# Header-only MyStruct (mystruct.h at repo root).
# Consumers: target_link_libraries(your_target PRIVATE mystruct)

add_library(mystruct INTERFACE)
add_library(mystruct::mystruct ALIAS mystruct)

target_include_directories(mystruct INTERFACE
  "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
)

if(BUILD_TESTING)
  find_package(Catch2 3 QUIET CONFIG)
  if(NOT Catch2_FOUND)
    include(FetchContent)
    FetchContent_Declare(
      Catch2
      GIT_REPOSITORY https://github.com/catchorg/Catch2.git
      GIT_TAG        v3.7.1
    )
    FetchContent_MakeAvailable(Catch2)
  endif()

  add_executable(mystruct_test mystruct_test.cpp)
  target_link_libraries(mystruct_test PRIVATE mystruct Catch2::Catch2WithMain)
  add_test(NAME mystruct_test COMMAND $<TARGET_FILE:mystruct_test>)
endif()
