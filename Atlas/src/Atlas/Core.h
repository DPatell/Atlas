#pragma once

#ifdef ATL_PLATFORM_WINDOWS
#if ATL_DYNAMIC_LINK
	#ifdef ATL_BUILD_DLL
		#define ATLAS_API __declspec(dllexport)
	#else
		#define ATLAS_API __declspec(dllimport)
	#endif // ATL_BUILD_DLL
#else
	#define ATLAS_API
#endif
#else
	#error Atlas is Windows Exclusive.
#endif // ATL_PLATFORM_WINDOWS

#ifdef ATL_DEBUG
	#define ATL_ENABLE_ASSERTS
#endif

#ifdef ATL_ENABLE_ASSERTS
	#define ATL_ASSERT(x, ...) {if(!(x)) { ATL_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
	#define ATL_CORE_ASSERT(x, ...) {if(!(x)) { ATL_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak();}}
#else
	#define ATL_ASSERT(x, ...)
	#define ATL_CORE_ASSERT(x, ...)
#endif // ATL_ENABLE_ASSERTS


#define BIT(x)	(1 << x)

#define ATL_BIND_EVENT_FN(fn) std::bind(&fn, this, std::placeholders::_1)