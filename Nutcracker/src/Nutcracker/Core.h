#pragma once
#include <string>
#include <functional>

#ifdef NC_PLATFORM_WINDOWS
	#ifdef NC_BUILD_DLL
		#define NUTCRACKER_API _declspec(dllexport) 
	#else
		#define NUTCRACKER_API _declspec(dllimport)
	#endif
#else
	#error Nutcracker only support Windows !
#endif

#define BIT(x) (1<<x)