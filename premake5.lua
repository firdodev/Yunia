-- premake5.lua
workspace "YuniaApp"
   architecture "x64"
   configurations { "Debug", "Release", "Dist" }
   startproject "YuniaApp"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

include "YuniaExternal.lua"
include "YuniaApp"