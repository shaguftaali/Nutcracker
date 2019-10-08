workspace "Nutcracker"

	architecture "x64"

	startproject "Sandbox"


	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

	flags
	{
		"MultiProcessorCompile"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Included directories relative to root folder (solution directory)
 IncludeDir = {}
 IncludeDir["GLFW"] = "Nutcracker/vendor/GLFW/include"

 
group "Dependencies"
	include "Nutcracker/vendor/GLFW"

group ""

project "Nutcracker"
	location "Nutcracker"
	kind "SharedLib"
	language "C++"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "ncpch.h"
	pchsource "Nutcracker/src/ncpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW",
		"opengl32.lib"
	}


	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		
			"NC_PLATFORM_WINDOWS",
			"NC_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

		filter "configurations:Debug"
			defines "NC_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "NC_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "NC_DIST"
			optimize "On"


project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Nutcracker/vendor/spdlog/include",
		"Nutcracker/src",
		"Hazel/vendor",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Nutcracker"
	}

	filter "system:windows"
		cppdialect "c++17"
		staticruntime "On"
		systemversion "latest"

		defines
		{
		
			"NC_PLATFORM_WINDOWS"
		}

		

		filter "configurations:Debug"
			defines "NC_DEBUG"
			symbols "On"

		filter "configurations:Release"
			defines "NC_RELEASE"
			optimize "On"

		filter "configurations:Dist"
			defines "NC_DIST"
			optimize "On"
