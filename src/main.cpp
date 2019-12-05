#include <iostream>
#include <stdio.h>
#include "raylib.h"
#include "Game.h"
#include "scene/SceneManager.h"
#include "ecs/Entity.h"
#include "ecs/CubeComponent.h"
#include "ecs/Component.h"

//Initialize pointer to zero so that it can be initialized in first call to getInstance
SceneManager *SceneManager::instance = 0;
Entity entity;
CubeComponent cube;
int main(int argc, char const *argv[])
{

    InitWindow(1280, 720, "Game"); // Initialize the window
    SetTargetFPS(60);              // Set the frame for 60 frame per seconds
    Game game;                     // Game initialize
    game.Start();                  // Start will initialize all the game process

    SceneManager *sceneManager = sceneManager->Get_Instance();
    entity.Add_Component<CubeComponent>();    
    
    while (!WindowShouldClose()) // Detect window close button or ESC key
    {

        game.Update(); // Update the game
        BeginDrawing();
        ClearBackground(BLACK);
        game.Render();   // Render all the objects in the game
        DrawFPS(10, 10); // Show FPS
        EndDrawing();
    }

    CloseWindow(); // Close window and OpenGL context
    return 0;
}
