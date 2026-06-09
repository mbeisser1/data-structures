cmake_minimum_required(VERSION 3.20)

# Build instructions: see README.md
#
# Quick start (tests + IDE compile database):
#   cmake -S . -B build -DBUILD_TESTING=ON
#   cmake --build build
#   ctest --test-dir build
#
# Library only (no Catch2, no compile_commands for test TU):
#   cmake -S . -B build
#   cmake --build build


project(data-structures LANGUAGES CXX)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
if(CMAKE_EXPORT_COMPILE_COMMANDS AND NOT CMAKE_SOURCE_DIR STREQUAL CMAKE_BINARY_DIR)
  set(_compile_commands_link "${CMAKE_SOURCE_DIR}/compile_commands.json")
  file(CREATE_LINK
    "${CMAKE_BINARY_DIR}/compile_commands.json"
    "${_compile_commands_link}"
    SYMBOLIC
  )
  unset(_compile_commands_link)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

include(CTest)

add_subdirectory(exception)
add_subdirectory(alt_vector)
add_subdirectory(mystruct)

add_executable(main main.cpp)
target_compile_features(main PRIVATE cxx_std_20)
