local Name = "PlottR"
local buildDirectory = "build"

workspace(Name.."_ws")
    configurations { "Debug", "Release", "Jporta" }
    cppdialect "C++17"

    --------------------------- System : Windows -------------------------------
    filter "system:windows"
        defines { "WIN" }
    ---------------------------- System : Linux --------------------------------
    filter "system:linux"
        defines { "UNIX" }
    ---------------------------- Config : Debug --------------------------------
    filter "configurations:Debug"
        defines { "DEBUG" }
        optimize "Off"
        symbols "On"
    --------------------------- Config : Release -------------------------------
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Full"
        symbols "Off"
    
project(Name)
    kind "ConsoleApp"
    language "C++"
    location(buildDirectory)


    files {
        "lib/**.h",
        "lib/**.hpp",
        "src/**.c",
        "src/**.cpp"
    }
    includedirs "lib"
   
    targetdir(buildDirectory.."/bin/%{cfg.buildcfg}")
    targetname "%{cfg.project.name}"

    linkoptions {
        "-lncursesw"      -- Link ncurses (wide character) library
    }

    --------------------------- Config : Jporta --------------------------------
    filter "configurations:Jporta"
        defines { "DEBUG", "MEMTRACE", "JPORTA", "CPORTA" }
        optimize "Off"
        symbols "On"
        buildoptions {
	    	"-Wall", "-Wextra", "-Wpedantic"
	    }
        linkoptions {} -- Remowe ncurses link




project(Name.."Test")
    kind "ConsoleApp"
    
    targetname("%{cfg.project.name}")
    targetdir(buildDirectory.."/bin/%{cfg.buildcfg}")
    location(buildDirectory)

    files {
        "tests/**.cpp",
        "src/**.cpp",
        "src/**.h",
        "lib/**.cpp",
        "lib/**.h"
    }
    removefiles {
        "src/main.cpp"
    }

    linkoptions {
        "-lncursesw"      -- Link ncurses (wide character) library
    }

    includedirs {
        "src",
        "lib"
    }
