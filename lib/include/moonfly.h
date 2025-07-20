#pragma once

#if _WIN32
#define MOONFLY_API  __declspec(dllexport)
#else
#define MOONFLY_API 
#endif

// Boolean type
#if (defined(__STDC__) && __STDC_VERSION__ >= 199901L) || (defined(_MSC_VER) && _MSC_VER >= 1800)
    #include <stdbool.h>
#elif !defined(__cplusplus) && !defined(bool)
    typedef enum bool { false = 0, true = !false } bool;
    #define MOONFLY_BOOL_TYPE
#endif

MOONFLY_API bool MoonflyInit();
MOONFLY_API void MoonflyClose();
