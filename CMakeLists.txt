cmake_minimum_required(VERSION 3.19)

project(cpp_space VERSION 0.0.1)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)

include(cmake/raylib.cmake)
include(cmake/box2d.cmake)

add_subdirectory(game)