local aap_librw = "vendor/librw"

local function add_source_files(prefix)
	return {
		prefix .. "/*.cpp",
		prefix .. "/*.h",
		prefix .. "/*.c",
		prefix .. "/*.ico",
		prefix .. "/*.rc"
	}
end

workspace "gta-lcs-revamped"
	language "C++"
	configurations { "Debug", "Release" }
	platforms { "x64" }
	startproject "gta-lcs-revamped"
	location "generated"
	staticruntime "off"
	symbols "Full"

	defines { "LIBRW", "RW_GL3", "AUDIO_OAL", "_CRT_SECURE_NO_WARNINGS", "_CRT_NONSTDC_NO_DEPRECATE"}

	filter "platforms:x64"
		system "windows"
		architecture "x86_64"

	filter "configurations:Debug"
		defines { "DEBUG" }

	filter "configurations:Release"
		defines { "MASTER" }
		optimize "Speed"
		linktimeoptimization "On"

  filter {}

project "librw"
	kind "StaticLib"
	language "C++"
	targetname "rw"
	targetdir(path.join(aap_librw, "lib/win-amd64-librw_gl3_glfw-oal/%{cfg.buildcfg}"))
	objdir(path.join(aap_librw, "obj/win-amd64-librw_gl3_glfw-oal/%{cfg.buildcfg}"))

	files {
		path.join(aap_librw, "src/**.h"),
		path.join(aap_librw, "src/**.cpp"),
		path.join(aap_librw, "src/**.c"),
	}

	includedirs { "vendor/glfw/include" }
	buildoptions { "/Zc:sizedDealloc-" }

	filter {}

project "gta-lcs-revamped"
	kind "WindowedApp"
	language "C++"
	cppdialect "C++17"
	targetname "lcsr"
	targetdir "bin/%{cfg.platform}/%{cfg.buildcfg}"
	objdir "obj/%{cfg.platform}/%{cfg.buildcfg}"
	characterset "MBCS"
	dependson "librw"

	files { "src/extras/GitSHA1.cpp" }

	prebuildcommands {
		'pwsh -File "%{wks.location}..\\tools\\Write-GitHashHeader.ps1" -OutputFile "%{wks.location}..\\src\\extras\\GitSHA1.cpp"'
	}

	local source_directories = {
		"src", "src/fakerw", "src/animation",
		"src/audio", "src/audio/eax", "src/audio/oal",
		"src/buildings", "src/collision", "src/control",
		"src/core", "src/entities", "src/leeds",
		"src/leeds/base", "src/math", "src/modelinfo",
		"src/objects", "src/peds", "src/renderer",
		"src/rw", "src/save", "src/skel",
		"src/skel/win", "src/skel/glfw", "src/text",
		"src/vehicles", "src/weapons", "src/extras"
	}

	for _, directory in ipairs(source_directories) do
		files(add_source_files(directory))
	end

	includedirs { aap_librw }
	for _, directory in ipairs(source_directories) do
		includedirs { directory }
	end

	includedirs {
		"vendor/openal-soft/include",
		"vendor/libsndfile/include",
		"vendor/mpg123/include",
		"vendor/glfw/include"
	}

	libdirs {
		"vendor/mpg123/lib/Win64",
		"vendor/libsndfile/lib/Win64",
		"vendor/openal-soft/libs/Win64",
		"vendor/glfw/libs",
		path.join(aap_librw, "lib/win-amd64-librw_gl3_glfw-oal/%{cfg.buildcfg}")
	}

	buildoptions { "/Zc:sizedDealloc-" }
	linkoptions { "/SAFESEH:NO" }
	ignoredefaultlibraries { "MSVCRT" }
	targetextension ".exe"

	links { "rw", "OpenAL32", "libmpg123-0", "libsndfile-1", "opengl32", "glfw3", "winmm", "ws2_32" }
	
  filter {}