include(FetchContent)

FetchContent_Declare(
    raylib_external
    GIT_REPOSITORY https://github.com/raysan5/raylib.git
    CMAKE_ARGS -DCMAKE_INSTALL_PREFIX=${CMAKE_SOURCE_DIR}/external/raylib
)

FetchContent_MakeAvailable(raylib_external)
