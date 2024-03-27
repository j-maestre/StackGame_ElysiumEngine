local lang = "C++"
local version = "C++20"


conan = {}
configs = {'Debug','Release','RelWithDebInfo'}
function conan_config_exec()
	configs = {'Debug','Release','RelWithDebInfo'}
	for i = 1,3 do
		include("build/deps/"..configs[i].."/conanbuildinfo.premake.lua")
		filter("configurations:"..configs[i])
			linkoptions { conan_exelinkflags }
			includedirs{ conan_includedirs }
			libdirs{ conan_libdirs }
			links{ conan_libs }
			links{ conan_system_libs }
			links{ conan_frameworks }
      links{"deps/Elysium/lib/"..configs[i].."/Elysium"}
			defines{ conan_defines }
		filter{}
	end
end

function conan_config_lib()
	configs = {'Debug','Release','RelWithDebInfo'}
	for i = 1,3 do
		include("build/deps/"..configs[i].."/conanbuildinfo.premake.lua")
		filter("configurations:"..configs[i])
			linkoptions { conan_sharedlinkflags }
			includedirs{ conan_includedirs }
			defines{ conan_defines }
		filter{}
	end
end

workspace "Project-Name"
  configurations { "Debug", "Release", "RelWithDebInfo" }
  architecture "x64"
  location "build/"
  cppdialect (version)
  
  startproject "Project-Name"
  
 project "Project-Name"
  kind "ConsoleApp"
  language (lang)
  conan_config_exec()
  
  -- Archivos del proyecto de visual
  location "build/"

  -- Carpeta donde va a ir lo que compile
  targetdir ("build/%{prj.name}/%{cfg.buildcfg}")
  
  includedirs
  {
    "include",
    "src",
    "deps/Elysium/include",
  }
  
  files
  {
    "include/**.*",
    "src/**.*",
    "premake5.lua",
  }
  
  filter "configurations:Debug"
    defines { "DEBUG" }
    runtime "Debug"
    optimize "Debug"
    symbols "on"
  
  filter "configurations:Release"
    defines { "NDEBUG" }
    runtime "Release"
    optimize "Speed"
    symbols "off"

  
  filter "configurations:RelWithDebInfo"
    defines { "DEBUG" }
    runtime "Release"
    optimize "on"
    symbols "on"
 