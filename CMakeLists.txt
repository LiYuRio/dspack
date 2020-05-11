cmake_minimum_required(VERSION 3.11 FATAL_ERROR)
project(dspack)

add_executable(test_array_list
  test/test_array_list.cpp
)

target_include_directories(test_array_list 
  PRIVATE
    ${PROJECT_SOURCE_DIR}/dspack
)