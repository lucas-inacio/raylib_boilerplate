cmake_minimum_required(VERSION 3.1)


project(joguinho_cpp)

add_executable(${PROJECT_NAME} main.cpp)

# Copied from https://cliutils.gitlab.io/modern-cmake/chapters/projects/submodule.html
find_package(Git QUIET)
if(GIT_FOUND AND EXISTS "${PROJECT_SOURCE_DIR}/.git")
# Update submodules as needed
    option(GIT_SUBMODULE "Check submodules during build" ON)
    if(GIT_SUBMODULE)
        message(STATUS "Submodule update")
        execute_process(COMMAND ${GIT_EXECUTABLE} submodule update --init --recursive
                        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}
                        RESULT_VARIABLE GIT_SUBMOD_RESULT)
        if(NOT GIT_SUBMOD_RESULT EQUAL "0")
            message(FATAL_ERROR "git submodule update --init --recursive failed with ${GIT_SUBMOD_RESULT}, please checkout submodules")
        endif()
    endif()
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/raylib/CMakeLists.txt")
    message(FATAL_ERROR "raylib was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

if(NOT EXISTS "${PROJECT_SOURCE_DIR}/external/raygui/src/raygui.h")
    message(FATAL_ERROR "raygui was not downloaded! GIT_SUBMODULE was turned off or failed. Please update submodules and try again.")
endif()

# Raylib dependency
add_subdirectory(external/raylib)

# Windows specific configuration
if (WIN32)
    if (CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        target_link_options(${PROJECT_NAME}
            PUBLIC "/ENTRY:mainCRTStartup" 
            PUBLIC "/SUBSYSTEM:WINDOWS"
        )
    elseif(CMAKE_CXX_COMPILER_ID STREQUAL "Clang")
        target_link_options(${PROJECT_NAME}
            PUBLIC "-Wl,-entry:mainCRTStartup"
            PUBLIC "-Wl,-subsystem:windows"
        )
    else()
        target_link_options(${PROJECT_NAME}
            PUBLIC "-Wl,--subsystem,windows"
        )
    endif()
endif()

target_include_directories(${PROJECT_NAME} 
    PUBLIC external/raylib/src
    PUBLIC external/raygui/src
)

target_link_directories(${PROJECT_NAME} PUBLIC external/raylib/src)

target_link_libraries(${PROJECT_NAME} raylib)

set(CMAKE_INSTALL_PREFIX ${PROJECT_NAME})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)