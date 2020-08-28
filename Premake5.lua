workspace "PaintTheCube"
    configurations
    {
        "Debug",
        "Release"
    }
    platforms
    {
        "Win64"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "PaintTheCube"
    kind "WindowedApp"
    language "C++"
    
    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.location}/src/**.cpp",
        "%{prj.location}/include/**.h",
        "%{prj.location}/include/**.hpp",
    }
    includedirs
    {
        "%{prj.location}/include",
        "%{prj.location}/vendor/Odin/Odin/include",
        "%{prj.location}/vendor/Odin/external/GameMath/include"
    }

    filter "system:windows"
        cppdialect "c++17"
        staticruntime "off"
        systemversion "latest"

        postbuildcommands
        {
            "copy /y %{cfg.architecture}\\*.dll bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\PaintTheCube\\*.dll",
            "Xcopy /E /I /y assets bin\\%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}\\PaintTheCube\\assets"
        }

        buildoptions { "/MP" }
        warnings "Extra"

    
    filter "platforms:Win64"
        architecture "x86_64"
        debugenvs 
        {
            "PATH=%PATH%;$(ProjectDir)/x86_64"
        }
        buildoptions { "/bigobj" }

    filter "configurations:Debug"
        symbols "On"
        runtime "Debug"
        libdirs 
        {
            "%{prj.location}/vendor/Odin/Odin/bin/Debug-windows-x86_64/Odin"
        }
        links
        {
            "Odin.lib"
        }

    filter "configurations:Release"
        optimize "Full"
        runtime "Release"
        libdirs
        {
            "%{prj.location}/vendor/Odin/Odin/bin/Release-windows-x86_64/Odin"
        }
        links 
        {
            "Odin.lib"
        }

