# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.14)  # Minimum CMake version
project(MyProject LANGUAGES C)      # Project name and language (C++)

# Set C++ standard (e.g., C++17)
set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

# Set options for static
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(SDL_STATIC ON)
set(BUILD_SHARED_LIBS OFF)
set(BUILD_STATIC_LIBS ON)

option(LIBRESSL_APPS "Build apps" OFF)
option(LIBRESSL_TESTS "Build tests" OFF)
option(ENABLE_ASM "Enable assembly" ON)
option(ENABLE_EXTRATESTS "Enable extra tests that may be unreliable on some platforms" OFF)
option(ENABLE_NC "Enable installing TLS-enabled nc(1)" OFF)

# Add the lib directory as a subdirectory
add_subdirectory(third_party/SDL3)
add_subdirectory(third_party/moonlight-common-c)
add_subdirectory(third_party/curl-8.15.0)
add_subdirectory(lib)
add_subdirectory(example)
