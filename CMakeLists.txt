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
#
# Clang toolchain (pick one style):
#   CC=clang CXX=clang++ cmake -S . -B build-clang ...
#   cmake -S . -B build-clang -DCMAKE_C_COMPILER=clang -DCMAKE_CXX_COMPILER=clang++ ...
#
# include-what-you-use (IWYU): install a build that matches your Clang (same LLVM major).
# CMake runs IWYU, then the real compiler, on each C++ file when this is set at configure time:
# CC=clang CXX=clang++ cmake -S . -B build-iwyu \
#   -DBUILD_TESTING=ON \
#   "-DCMAKE_CXX_INCLUDE_WHAT_YOU_USE=include-what-you-use;-Xiwyu;--verbose=2"
# cmake --build build-iwyu


project(data-structures LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(alt_vector)
