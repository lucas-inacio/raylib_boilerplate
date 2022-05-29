find_package(Threads REQUIRED)
add_executable(game src/game.cpp)
target_link_libraries(game raylib Threads::Threads)

# Windows specific configuration
if(WIN32)
    if(CMAKE_CXX_COMPILER_ID STREQUAL "MSVC")
        set(WIN32_RELEASE_FLAGS_1 "/ENTRY:mainCRTStartup")
        set(WIN32_RELEASE_FLAGS_2 "/SUBSYSTEM:WINDOWS")
    else()
        set(WIN32_RELEASE_FLAGS_1 "-Wl,--entry,mainCRTStartup")
        set(WIN32_RELEASE_FLAGS_2 "-Wl,--subsystem,windows")
    endif()
    
    target_link_options(
        game
        PUBLIC $<$<CONFIG:Release>:${WIN32_RELEASE_FLAGS_1}>
        PUBLIC $<$<CONFIG:Release>:${WIN32_RELEASE_FLAGS_2}>
    )
endif()



