cmake_minimum_required(VERSION 3.20)

# Build from this directory (repository root):
#
#   cmake -S . -B build -DBUILD_TESTING=ON
#   cmake --build build
#   ctest --test-dir build
#
#   rm -rf build
#   OR
#   cmake --build build --target clean
#
# Use -DBUILD_TESTING=OFF to skip the unit test executable (Catch2 is not required).

project(data-structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(alt_vector)
