include(FetchContent)

FetchContent_Declare(
    box2d_external
    GIT_REPOSITORY https://github.com/erincatto/box2d.git
    GIT_TAG main
)

set(BOX2D_BUILD_UNIT_TEST OFF)
set(BOX2D_BUILD_TESTBED OFF)

FetchContent_MakeAvailable(box2d_external)