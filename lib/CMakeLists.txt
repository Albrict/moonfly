add_library(moonfly STATIC
            src/moonfly.cpp
)

# Include the library's public headers
target_include_directories(moonfly PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
)

# Set properties for the library
target_compile_features(moonfly PUBLIC cxx_std_17)  # Require C++17

# Add compiler warnings
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # GCC/Clang warnings
    target_compile_options(moonfly PRIVATE
        -Wall
        -Wextra
        -Wpedantic
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC warnings
    target_compile_options(moonfly PRIVATE
        /W4  # Enable all warnings
        /WX  # Treat warnings as errors
    )
endif()

# Debug flags
if(CMAKE_CXX_COMPILER_ID STREQUAL "GNU" OR CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
    # GCC/Clang debug flags
    target_compile_options(moonfly PRIVATE
        $<$<CONFIG:Debug>:-g3>  # Debug symbols
        $<$<CONFIG:Debug>:-O0>  # Disable optimizations in Debug mode
    )
elseif(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
    # MSVC debug flags
    target_compile_options(moonfly PRIVATE
        $<$<CONFIG:Debug>:/Zi>  # Debug symbols
        $<$<CONFIG:Debug>:/Od>  # Disable optimizations in Debug mode
    )
endif()

# Sanitizer flags
option(ENABLE_SANITIZERS "Enable sanitizers (AddressSanitizer, UndefinedBehaviorSanitizer)" OFF)
if(ENABLE_SANITIZERS)
    target_compile_options(moonfly PRIVATE
        -fsanitize=address
        -fsanitize=undefined
        -fno-omit-frame-pointer
    )
    target_link_options(moonfly PRIVATE
        -fsanitize=address
        -fsanitize=undefined
    )
endif()
