#ifndef __DEFS_H_
#define __DEFS_H_

#include <hlp.h>

#define FORWARDED extern
#define INTERNAL_EXPORT FORWARDED
#define INTERNAL 

typedef unsigned char uchar;


#define DBG_LIBEXPORT extern "C" __declspec(dllexport)

#if _DEBUG
#define DBGPRINT(s,...) HlpDebugPrint("ApiBreak: " s "\n",##__VA_ARGS__)
#define DBGPRINT2(s,...) HlpDebugPrint("ApiBreak: %s\n",##__VA_ARGS__)
#define _DBGPRINT(s,...) HlpDebugPrint(s,##__VA_ARGS__)
#else
#define DBGPRINT(s,...) 
#define DBGPRINT2(s,...)
#define _DBGPRINT(s,...)

#endif

#define RAISEGLOBALERROR(errString) AbRaiseSystemError(errString, 0,__FUNCTION__,__LINE__)

#define BIGERROR(msg) DBGPRINT(msg); \
                     __debugbreak()


#define NOTIMPLEMENTED() HlpDebugPrint(__FUNCTION__ " not implemented yet")


#define ALLOCOBJECT(type) (type *)AbMemoryAlloc(sizeof(type))
#define FREEOBJECT(ob) AbMemoryFree((ob))

#define RESIZEOBJECTLIST(type, obj, newSize) (type *)AbMemoryRealloc((obj),sizeof(type) * (newSize))

#define ALLOCSTRINGW(size) (LPWSTR)AbMemoryAlloc(sizeof(WCHAR) * ((size)+1))
#define ALLOCSTRINGA(size) (LPSTR)AbMemoryAlloc(sizeof(CHAR) * ((size)+1))

#define FREESTRING(str) AbMemoryFree((void *)(str))

#if _DEBUG
#define DBGBREAK __debugbreak
#else
#define DBGBREAK
#endif

#define _stringfy(x) #x

#define AB_VERSION_MAJOR 0
#define AB_VERSION_MINOR 5
#define AB_VERSION_BUILD 39

#if _WIN64
#define AB_PLATFORM     "x64"
#define PLATFORM_SIZE	64
#else
#define AB_PLATFORM     "x86"
#define PLATFORM_SIZE	32
#endif

#define AB_PHASE        "BETA"

#define AB_APPNAME      "Api Break (" AB_PHASE ")"
#define AB_APPTITLE     AB_APPNAME " - " AB_PLATFORM



#define AB_VERSION_STRING(maj,min,build) _stringfy(maj) "." _stringfy(min) " Build: " _stringfy(build)

#define AB_VERSTR AB_VERSION_STRING(AB_VERSION_MAJOR,AB_VERSION_MINOR,AB_VERSION_BUILD)
#define AB_BUILD_TIME __DATE__ " " __TIME__


#endif // !__DEFS_H_
