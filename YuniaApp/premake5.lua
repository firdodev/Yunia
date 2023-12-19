project "YuniaApp"
   kind "ConsoleApp"
   language "C++"
   cppdialect "C++17"
   targetdir "bin/%{cfg.buildcfg}"
   staticruntime "off"

   files { "src/**.h", "src/**.cpp" }

   includedirs
   {
      "../vendor/imgui",
      "../vendor/glfw/include",

      "../Yunia/src",

      "%{IncludeDir.VulkanSDK}",
      "%{IncludeDir.glm}",
   }

    links
    {
        "Yunia"
    }

   targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
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
      kind "WindowedApp"
      defines { "YU_DIST" }
      runtime "Release"
      optimize "On"
      symbols "Off"