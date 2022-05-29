# raylib_boilerplate
Boilerplate build configuration for raylib and raygui based projects

# Required tools
* CMake

## Building
From the repository's root directory type:
```shell
mkdir build
cd build
cmake ..
cmake --build .
```

## Details
* The project downloads dependencies at configuration time using CMake's FetchContent.
* Release configuration on Windows sets appropriate flags so no console window is used.

The build configuration depends on wich generator you're using. For multi-configuration builds (like MSVC) specify the configuration at build time:
```shell
cmake --build . --config Release
```
On other generators like MinGW or GNU Makefiles set CMAKE_BUILD_TYPE at configuration time:
```shell
cmake .. -DCMAKE_BUILD_TYPE=Release
```