workspace "PlottrWS"
    configurations { "Debug", "Release", "Jporta" }
    
project "Plottr"
    kind "ConsoleApp"
    language "C++"


    files {
        "lib/**.h",
        "lib/**.hpp",
        "src/**.c",
        "src/**.cpp"
    }
    includedirs "lib"

    entrypoint "huh"
   
    targetdir "bin/%{cfg.buildcfg}"
    targetname "Plottr"

    linkoptions {
        "-lncursesw"      -- Link ncurses (wide character) library
    }


-------------------------------- Config : Debug --------------------------------
    filter "configurations:Debug"
        defines { "DEBUG" }
        optimize "Off"
        symbols "On"

------------------------------- Config : Release -------------------------------
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Full"
        symbols "Off"

------------------------------- Config : Jporta --------------------------------
    filter "configurations:Jporta"
        defines { "DEBUG", "MEMTRACE" }
        optimize "Off"
        symbols "On"
        buildoptions {
	    	"-Wall", "-Wextra", "-Wpedantic"
	    }
        -- entrypoint "test"
        -- linkoptions { "/ENTRY:test" }

------------------------------- System : Windows -------------------------------
    filter "system:windows"
        defines { "WIN" }
-------------------------------- System : Linux --------------------------------
    filter "system:linux"
        defines { "UNIX" }




project "PlottrTest"
    kind "ConsoleApp"
    -- location "tests"
    targetname "PlottrTest"

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
