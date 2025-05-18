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
    filter "configurations:Jporta"
        defines {"MEMTRACE", "JPORTA", "CPORTA"}
        buildoptions {
	    	"-Wall", "-Werror", "-O0", "-Wextra", "-Wpedantic", "-fprofile-arcs -ftest-coverage"
	    }
        linkoptions {
            "--coverage"
        }
    
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
        "-lncursesw",      -- Link ncurses (wide character) library
        "-e,testMain"
    }

    includedirs {
        "src",
        "lib"
    }

project("Docs")
    kind "Makefile"
    location(buildDirectory)

    buildcommands {
        "plantuml ../docs/uml",
        "doxygen ../Doxyfile",
        "make -C ../"..buildDirectory.."/docs pdf"
    }
  
    cleancommands {
        "make -C "..buildDirectory.."/docs clean"
    }

project("Zip")
    kind "Makefile"
    location(buildDirectory)

    buildcommands {
        "mkdir -p zip",
        "cp ../src/* ./zip",
        "cp ../lib/* ./zip",
        "cp ../tests/* ./zip",
        "zip -jr zipped.zip ./zip/*"
    }