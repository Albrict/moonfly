# Root CMakeLists.txt
cmake_minimum_required(VERSION 3.14)  # Minimum CMake version
project(MyProject LANGUAGES CXX)      # Project name and language (C++)

# Set C++ standard (e.g., C++17)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Add the lib directory as a subdirectory
add_subdirectory(lib)
add_subdirectory(example)
