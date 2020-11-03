#pragma once

#ifdef ATL_PLATFORM_WINDOWS
	#ifdef ATL_BUILD_DLL
		#define ATLAS_API __declspec(dllexport)
	#else
		#define ATLAS_API __declspec(dllimport)
	#endif // ATL_BUILD_DLL
#else
	#error Atlas is Windows Exclusive.
#endif // ATL_PLATFORM_WINDOWS

#define BIT(x)	(1 << x)
