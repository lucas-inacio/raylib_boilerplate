#define RAYGUI_IMPLEMENTATION
#include <extras/raygui.h>

int main(int argc, char **argv)
{
    InitWindow(800, 450, "raylib [core] example - basic window");

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            GuiButton(Rectangle{30, 30, 200, 200}, "Teste");
        EndDrawing();
    }

    CloseWindow();

    return 0;
}