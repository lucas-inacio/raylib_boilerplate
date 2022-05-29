cmake_minimum_required(VERSION 3.19)

project(cpp_space VERSION 0.0.1)

include(cmake/raylib.cmake)
include(cmake/box2d.cmake)

add_subdirectory(game)