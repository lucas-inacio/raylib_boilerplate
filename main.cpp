#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include <raylib.h>

int main()
{
    Vector2 windowSize{ 800, 600 };
    InitWindow(static_cast<int>(windowSize.x), static_cast<int>(windowSize.y), "Teste Raylib");

    // Câmera
    Camera camera = { 0 };
    camera.position = Vector3{ 50, 50, 50 };
    camera.target = Vector3{ 0, 10, 0 };
    camera.up = Vector3{ 0, 1, 0 };
    camera.fovy = 45;
    camera.projection = CAMERA_PERSPECTIVE;

    SetCameraMode(camera, CAMERA_FREE);
    SetTargetFPS(60);

    while (!WindowShouldClose())
    {
        UpdateCamera(&camera);

        BeginDrawing();
        ClearBackground(RAYWHITE);

        BeginMode3D(camera);
        DrawGrid(20, 10.0f);
        EndMode3D();

        EndDrawing();
    }

    CloseWindow();

    return 0;
}