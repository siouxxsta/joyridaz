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

	defines { "LIBRW", "RW_GL3", "AUDIO_OAL", "_CRT_NONSTDC_NO_DEPRECATE" }

	filter "platforms:x64"
		system "windows"
		architecture "x86_64"

	filter "configurations:Debug"
		defines { "LCSR_DEBUG" }

	filter "configurations:Release"
		defines { "LCSR_MASTER" }
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
	targetdir "bin/%{cfg.platform}/%{cfg.buildcfg}"
	objdir "obj/%{cfg.platform}/%{cfg.buildcfg}"
	characterset "MBCS"
	dependson "librw"
	
	filter "configurations:Debug"
		targetname "dbg"
	
	filter "configurations:Release"
		targetname "lcsr"

	filter {}

	buildoptions { "/Zc:sizedDealloc-" }
	linkoptions { "/SAFESEH:NO" }

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

	files { "src/extras/GitSHA1.cpp" }

	includedirs {
		"vendor/mpg123/include",
		"vendor/libsndfile/include",
		"vendor/openal-soft/include",
		"vendor/glfw/include",
		aap_librw
	}

	libdirs {
		"vendor/mpg123/lib/Win64",
		"vendor/libsndfile/lib/Win64",
		"vendor/openal-soft/libs/Win64",
		"vendor/glfw/libs",
		path.join(aap_librw, "lib/win-amd64-librw_gl3_glfw-oal/%{cfg.buildcfg}")
	}

	prebuildcommands {
		'pwsh -File "%{wks.location}/../tools/Write-GitHashHeader.ps1" -OutputFile "%{wks.location}/../src/extras/GitSHA1.cpp"'
	}

	postbuildcommands {
		'{COPY} "%{cfg.targetdir}/%{cfg.targetname}.exe" "D:/Liberty City Stories Revamped/"',
		'{COPY} "%{cfg.targetdir}/%{cfg.targetname}.pdb" "D:/Liberty City Stories Revamped/"'
    }

	for _, directory in ipairs(source_directories) do
		files(add_source_files(directory))
	end

	for _, directory in ipairs(source_directories) do
		includedirs { directory }
	end

	ignoredefaultlibraries { "MSVCRT" }
	links { "rw", "OpenAL32", "libmpg123-0", "libsndfile-1", "opengl32", "glfw3", "winmm", "ws2_32" }
	
  filter {}