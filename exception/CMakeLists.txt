add_library(exception INTERFACE)
add_library(exception::exception ALIAS exception)

target_include_directories(exception INTERFACE
  "$<BUILD_INTERFACE:${CMAKE_SOURCE_DIR}>"
)
