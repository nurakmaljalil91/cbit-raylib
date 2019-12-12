#include <iostream>

#include "raylib.h"
#include "Game.h"
#include "scene/SceneManager.h"
#include "utils/ResourcesDirectory.h"

// Initialize pointer to zero so that it can be initialized in first call to getInstance
// Because main is the first cpp file to compile and read we instantiate SceneManager here
SceneManagerBase *SceneManagerBase::instance = 0;             // Scene Manager
ResourcesDirectoryBase *ResourcesDirectoryBase::instance = 0; // Resources Directory

int main(int argc, char const *argv[])
{

    InitWindow(1280, 720, "Game"); // Initialize the window
    SetTargetFPS(60);              // Set the frame for 60 frame per seconds

    Game game;    // Game initialize
    game.Start(); // Start will initialize all the game process

    while (!WindowShouldClose()) // Detect window close button or ESC key
    {
        game.Update(); // Update the game

        BeginDrawing();            // Start render here
        ClearBackground(RAYWHITE); // Make the background color white
        game.Render();             // Render all the objects in the game
        DrawFPS(10, 10);           // Show FPS
        EndDrawing();              // End render here
    }

    game.Clear();  // Clear all the objects load in the game
    CloseWindow(); // Close window and OpenGL context
    return 0;
}
