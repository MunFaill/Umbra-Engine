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
    --TODO
}

links
{
    "SDL3"
}

filter "configurations:Debug"
symbols "On"
defines {"Debug"}
filter "configurations:Release"
optimize "On"
defines {"NDEBUG"}

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
defines {"Debug"}
filter "configurations:Release"
optimize "On"
defines {"NDEBUG"}

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
defines {"Debug"}
filter "configurations:Release"
optimize "On"
defines {"NDEBUG"}

--=================================================================
