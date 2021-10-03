# Boilerplate build configuration for raylib and raygui based projects
* Includes raylib and raygui as submodules
* On windows sets subsystem:windows (no need to defined WinMain entrypoint - tested with Visual studio and MinGW)

## Building
From the repository root:

### For Windows/Linux:
```
cmake <-DBUILD_SHARED_LIBS=ON> -S . -B build
```
This will set GRAPHICS to GRAPHICS_API_OPENGL_33 by default when building raylib

### On Raspberry Pi 4:
```
cmake -DPLATFORM=PLATFORM_DESKTOP -DGRAPHICS=GRAPHICS_API_OPENGL_21 -S . -B build
```
