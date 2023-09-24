@echo off

pushd ..
:: Create the premake5.lua file in vendor/imgui and write to it
echo project "ImGui"                                          > vendor\imgui\premake5.lua
echo     kind "StaticLib"                                     >> vendor\imgui\premake5.lua
echo     language "C++"                                       >> vendor\imgui\premake5.lua
echo     staticruntime "off"                                  >> vendor\imgui\premake5.lua
echo     targetdir ("bin/" .. outputdir .. "/%%{prj.name}")   >> vendor\imgui\premake5.lua
echo     objdir ("bin-int/" .. outputdir .. "/%%{prj.name}") >> vendor\imgui\premake5.lua
echo     files                                                >> vendor\imgui\premake5.lua
echo     {                                                    >> vendor\imgui\premake5.lua
echo         "imconfig.h",                                    >> vendor\imgui\premake5.lua
echo         "imgui.h",                                       >> vendor\imgui\premake5.lua
echo         "imgui.cpp",                                     >> vendor\imgui\premake5.lua
echo         "imgui_draw.cpp",                                >> vendor\imgui\premake5.lua
echo         "imgui_internal.h",                              >> vendor\imgui\premake5.lua
echo         "imgui_tables.cpp",                              >> vendor\imgui\premake5.lua
echo         "imgui_widgets.cpp",                             >> vendor\imgui\premake5.lua
echo         "imstb_rectpack.h",                              >> vendor\imgui\premake5.lua
echo         "imstb_textedit.h",                              >> vendor\imgui\premake5.lua
echo         "imstb_truetype.h",                              >> vendor\imgui\premake5.lua
echo         "imgui_demo.cpp"                                 >> vendor\imgui\premake5.lua
echo     }                                                    >> vendor\imgui\premake5.lua
echo     filter "system:windows"                              >> vendor\imgui\premake5.lua
echo         systemversion "latest"                           >> vendor\imgui\premake5.lua
echo         cppdialect "C++17"                               >> vendor\imgui\premake5.lua
echo     filter "system:linux"                                >> vendor\imgui\premake5.lua
echo         pic "On"                                         >> vendor\imgui\premake5.lua
echo         systemversion "latest"                           >> vendor\imgui\premake5.lua
echo         cppdialect "C++17"                               >> vendor\imgui\premake5.lua
echo     filter "configurations:Debug"                        >> vendor\imgui\premake5.lua
echo         runtime "Debug"                                  >> vendor\imgui\premake5.lua
echo         symbols "on"                                     >> vendor\imgui\premake5.lua
echo     filter "configurations:Release"                      >> vendor\imgui\premake5.lua
echo         runtime "Release"                                >> vendor\imgui\premake5.lua
echo         optimize "on"                                    >> vendor\imgui\premake5.lua
echo     filter "configurations:Dist"                         >> vendor\imgui\premake5.lua
echo         runtime "Release"                                >> vendor\imgui\premake5.lua
echo         optimize "on"                                    >> vendor\imgui\premake5.lua
echo         symbols "off"                                    >> vendor\imgui\premake5.lua


vendor\bin\premake5.exe vs2022
popd
pause
