#include <iostream>
#include <stdio.h>
#include "raylib.h"
#include "Game.h"
#include "scene/SceneManager.h"
#include "ecs/Entity.h"
#include "ecs/Cube.h"
#include "ecs/Component.h"

//Initialize pointer to zero so that it can be initialized in first call to getInstance
//SceneManagerBase *SceneManagerBase::instance = 0;
//Entity entity;
SceneManagerBase *SceneManagerBase::instance = 0;
int main(int argc, char const *argv[])
{

    InitWindow(1280, 720, "Game"); // Initialize the window
    SetTargetFPS(60);              // Set the frame for 60 frame per seconds
    Game game;                     // Game initialize
    game.Start();                  // Start will initialize all the game process

    // Define the camera to look into our 3d world
    // Camera3D camera = {0};
    // camera.position = Vector3{0.0f, 10.0f, 10.0f}; // Camera position
    // camera.target = Vector3{0.0f, 0.0f, 0.0f};     // Camera looking at point
    // camera.up = Vector3{0.0f, 1.0f, 0.0f};         // Camera up vector (rotation towards target)
    // camera.fovy = 45.0f;                           // Camera field-of-view Y
    // camera.type = CAMERA_PERSPECTIVE;              // Camera mode type
    // SceneManagerBase *SceneManager = SceneManager->Get_Instance();
    // entity.Add_Component<Cube>();
    // std::cout << entity.gameObject.is_active << std::endl;
    // entity.transform.position = Vector3{1, 1, 1};
    // entity.transform.scale = Vector3{3, 3, 3};
    // entity.transform.position.x += 10.0;
    // Vector3 cubePosition = {0, 0, 0};
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        // entity.Update();
        // entity.transform.position.x += 0.01f;

        game.Update();  // Update the game
        BeginDrawing(); // Start render here
        ClearBackground(RAYWHITE);
        // BeginMode3D(camera);
        // entity.Render();
        // // DrawCube(cubePosition, 2.0f, 2.0f, 2.0f, RED);
        // // DrawCubeWires(cubePosition, 2.0f, 2.0f, 2.0f, MAROON);
        // // std::cout << entity.Get_Component<
        // // DrawGrid(10, 1.0f);
        // EndMode3D();

        game.Render();   // Render all the objects in the game
        DrawFPS(10, 10); // Show FPS
        EndDrawing();
    }
    game.Clear();  // Clear all the objects load in the game
    CloseWindow(); // Close window and OpenGL context
    return 0;
}
