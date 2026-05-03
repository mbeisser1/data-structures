# Header-only alt_vector (sources under src/include/).
# Consumers: target_link_libraries(your_target PRIVATE alt_vector)

add_library(alt_vector INTERFACE)
add_library(alt_vector::alt_vector ALIAS alt_vector)

target_include_directories(alt_vector INTERFACE
  "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>"
  "$<INSTALL_INTERFACE:include>"
)

if(BUILD_TESTING)
  find_package(Catch2 3 REQUIRED CONFIG)

  add_executable(alt_vector_test src/tests/alt_vector_test.cpp)
  target_include_directories(alt_vector_test PRIVATE
    "$<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/src/include>"
  )
  target_link_libraries(alt_vector_test PRIVATE alt_vector Catch2::Catch2WithMain)

  # Register with CTest so `ctest` runs this executable (all Catch cases in one process).
  add_test(NAME alt_vector_test COMMAND $<TARGET_FILE:alt_vector_test>)
endif()
