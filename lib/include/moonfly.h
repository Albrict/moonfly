#pragma once

#if _WIN32
#define MOONFLY_API  __declspec(dllexport)
#else
#define MOONFLY_API 
#endif

MOONFLY_API void MoonflyInit();
MOONFLY_API void MoonflyClose();
