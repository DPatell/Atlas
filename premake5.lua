workspace "Atlas"
	architecture "x64"
	startproject "Sandbox"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Atlas/Libraries/GLFW/include"
IncludeDir["Glad"] = "Atlas/Libraries/Glad/include"
IncludeDir["ImGui"] = "Atlas/Libraries/imgui"
IncludeDir["glm"] = "Atlas/Libraries/glm"

group "Dependacies"
	include "Atlas/Libraries/GLFW"
	include "Atlas/Libraries/Glad"
	include "Atlas/Libraries/imgui"

group ""

project "Atlas"
	location "Atlas"
	kind "StaticLib"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "atlpch.h"
	pchsource "Atlas/src/atlpch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp",
		"%{prj.name}/Libraries/glm/glm/**.hpp",
		"%{prj.name}/Libraries/glm/glm/**.inl",
	}

	defines
	{
		"_CRT_SECURE_NO_WARNINGS"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/Libraries/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.glm}",
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter	"system:windows"
		systemversion "latest"

		defines
		{
			"ATL_PLATFORM_WINDOWS",
			"ATL_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

	filter "configurations:Debug"
		defines "ATL_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "ATL_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ATL_DIST"
		runtime "Release"
		optimize "on"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++17"
	staticruntime "on"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Atlas/Libraries/spdlog/include",
		"Atlas/src",
		"Atlas/Libraries",
		"%{IncludeDir.glm}"
	}

	links
	{
		"Atlas"
	}

	filter	"system:windows"
		systemversion "latest"

		defines
		{
			"ATL_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ATL_DEBUG"
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines "ATL_RELEASE"
		runtime "Release"
		optimize "on"

	filter "configurations:Dist"
		defines "ATL_DIST"
		runtime "Release"
		optimize "on"
