cmake_minimum_required(VERSION 3.0 FATAL_ERROR)
project(matrix)

set(EXECUTABLE_NAME matrix)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)
add_executable(${EXECUTABLE_NAME} main.cpp)
set_property(TARGET ${EXECUTABLE_NAME} PROPERTY CXX_STANDARD 14)
