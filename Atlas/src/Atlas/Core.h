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

#ifdef ATL_ENABLE_ASSERTS
	#define ATL_ASSERTS(x, ...) {if(!(x)) { ATL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define ATL_CORE_ASSERTS(x, ...) {if(!(x)) { ATL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define ATL_ASSERTS(x, ...)
	#define ATL_CORE_ASSERTS(x, ...)
#endif // ATL_ENABLE_ASSERTS


#define BIT(x)	(1 << x)
