cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(dspack)
set(CMAKE_CXX_STANDARD 11)

set(EXECUTABLE_OUTPUT_PATH ${PROJECT_BINARY_DIR}/bin)

enable_testing()
add_subdirectory(third_party/gtest)
add_subdirectory(test)