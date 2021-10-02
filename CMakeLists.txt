cmake_minimum_required(VERSION 3.0)

project(joguinho_cpp)

add_executable(${PROJECT_NAME} main.cpp)

add_subdirectory(external/raylib)

target_include_directories(${PROJECT_NAME} PUBLIC external/raylib/src)

target_link_directories(${PROJECT_NAME} PUBLIC external/raylib/src)

target_link_libraries(${PROJECT_NAME} raylib)