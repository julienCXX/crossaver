#ifndef _CROSSAVER_H_CONSTANTS
#define _CROSSAVER_H_CONSTANTS

// OS-dependant constants

// Whether the OS gives a window with a handle for the full screen mode
#ifdef _WIN32
#define IS_FULL_SCREEN_VIA_HANDLE false
#else // _WIN32
#define IS_FULL_SCREEN_VIA_HANDLE true
#endif // _WIN32

#endif // _CROSSAVER_H_CONSTANTS
