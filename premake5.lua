workspace "Umbra"
architecture "x64"
configurations
{
    "Debug",
    "Release",
}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

--UmbraCore========================================================

project "UmbraCore"
location "%{prj.name}"
kind "SharedLib"
language "C++"

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files
{
    "%{prj.name}/**.hpp",
    "%{prj.name}/**.cpp",
}

includedirs
{
    "Vendor/Bgfx/bgfx/include"
}

libdirs
{
    "Vendor/Bgfx/bgfx/.build/linux64_gcc/bin"
}

links
{
    "SDL3",
    "bgfxRelease",
    "bimgRelease",
    "bxRelease"
}

filter "configurations:Debug"
symbols "On"
filter "configurations:Release"
optimize "On"

--=================================================================
--UmbraEditor======================================================

project "UmbraEditor"
location "%{prj.name}"
kind "SharedLib"
language "C++"

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files
{
    "%{prj.name}/**.hpp",
    "%{prj.name}/**.cpp",
}

includedirs
{
    --TODO
}

links
{
    --TODO
}

filter "configurations:Debug"
symbols "On"
filter "configurations:Release"
optimize "On"

--=================================================================
--UmbraSandbox=====================================================

project "UmbraSandbox"
location "%{prj.name}"
kind "ConsoleApp"
language "C++"

targetdir("bin/" .. outputdir .. "/%{prj.name}")
objdir("bin-int/" .. outputdir .. "/%{prj.name}")

files
{
    "%{prj.name}/**.hpp",
    "%{prj.name}/**.cpp",
}

includedirs
{
    "UmbraCore/"
}

links
{
    "UmbraCore"
}

filter "configurations:Debug"
symbols "On"
filter "configurations:Release"
optimize "On"

--=================================================================
