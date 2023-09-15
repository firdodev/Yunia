project "Yunia"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"
    targetdir "bin/%{cfg.buildcfg}"
    staticruntime "off"

    files { "src/**.h", "src/**.cpp" }

    includedirs
    {
      "src",
      "../vendor/imgui"
    }

    links
    {
      "ImGui"
    }

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")


    filter "system:windows"
      systemversion "latest"
      defines { "YU_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
      defines { "YU_DEBUG" }
      runtime "Debug"
      symbols "On"

    filter "configurations:Release"
      defines { "YU_RELEASE" }
      runtime "Release"
      optimize "On"
      symbols "On"

    filter "configurations:Dist"
      defines { "YU_DIST" }
      runtime "Release"
      optimize "On"
      symbols "Off"