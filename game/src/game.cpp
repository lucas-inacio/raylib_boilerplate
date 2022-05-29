#define RAYGUI_IMPLEMENTATION
#include <extras/raygui.h>
#include <box2d/box2d.h>

#include <chrono>

int main(int argc, char **argv)
{
    b2Vec2 gravity(0, -9.8f);
    b2World world(gravity);

    // Ground
    b2BodyDef groundBodyDef;
    groundBodyDef.position.Set(0, -10.0f);
    b2Body *groundBody = world.CreateBody(&groundBodyDef);
    b2PolygonShape groundBox;
    groundBox.SetAsBox(50.0f, 10.0f);
    groundBody->CreateFixture(&groundBox, 0.0f);

    // Actor
    b2BodyDef bodyDef;
    bodyDef.type = b2_dynamicBody;
    bodyDef.position.Set(0.0f, 4.0f);
    b2Body* body = world.CreateBody(&bodyDef);
    b2PolygonShape dynamicBox;
    dynamicBox.SetAsBox(1.0f, 1.0f);
    b2FixtureDef fixtureDef;
    fixtureDef.shape = &dynamicBox;
    fixtureDef.density = 1.0f;
    fixtureDef.friction = 0.3f;
    body->CreateFixture(&fixtureDef);


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