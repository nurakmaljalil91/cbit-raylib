#include <iostream>

#include "raylib.h"
#include "Game.h"
#include "scene/SceneManager.h"
#include "utils/ResourcesDirectory.h"
#include "utils/Input.h"
#include "utils/Asset.h"
#include "utils/Cursor.h"

// Initialize pointer to zero so that it can be initialized in first call to getInstance
// Because main is the first cpp file to compile and read we instantiate SceneManager here
SceneManagerBase *SceneManagerBase::instance = 0;             // Scene Manager singleton initialization
ResourcesDirectoryBase *ResourcesDirectoryBase::instance = 0; // Resources Directory singleton initialization
InputBase *InputBase::instance = 0;                           // Input singleton initialization
AssetBase *AssetBase::instance = 0;                           // Asset singleton initialization

int main(int argc, char const *argv[])
{

    InitWindow(1280, 720, "Game"); // Initialize the window
    InitAudioDevice();             // Initialize the audio device
    SetTargetFPS(60);              // Set the frame for 60 frame per seconds

    Game game;        // Game initialize
    game.Load_Data(); // Load the game data here
    game.Start();     // Start will initialize all the game process

    HideCursor();                                                                   // Hide the cursor
    Cursor cursor("../resources/SpriteSheets/sheet_white1x.png", 350, 450, 50, 50); // create cursor
    while (!WindowShouldClose())                                                    // Detect window close button or ESC key
    {
        game.Update();   // Update the game
        cursor.Update(); // Update the cursor

        BeginDrawing();            // Start render here
        ClearBackground(RAYWHITE); // Make the background color white
        game.Render();             // Render all the objects in the game
        cursor.Render();           // Render the cursor
        DrawFPS(10, 10);           // Show FPS
        EndDrawing();              // End render here
    }

    game.Clear();       // Clear all the objects load in the game
    game.Unload_Data(); // Unload all the data in the game
    cursor.Clear();     // Clear the cursor texture
    CloseAudioDevice(); // Close audio device
    CloseWindow();      // Close window and OpenGL context
    return 0;
}
