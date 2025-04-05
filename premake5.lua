workspace "Nagyhf"
    configurations { "Debug", "Release" }
    
project "Main"
    kind "ConsoleApp"
    language "C++"


    files {
        "lib/**.h",
        "lib/**.hpp",
        "src/**.c",
        "src/**.cpp"
    }
    includedirs "lib"
   
    targetdir "bin/%{cfg.buildcfg}"
    targetname "plottr"

    linkoptions {
        "-lncursesw"      -- Link ncurses (wide character) library
    }

    filter "configurations:Debug"
        defines { "DEBUG" }
        optimize "Off"
        symbols "On"
    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "Full"
    
    filter "system:windows"
        defines { "WIN" }
    filter "system:linux"
        defines { "UNIX" }


        