#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "raylib.h"
#include "scene/SceneManager.h"
#include "scene/SplashScreenScene.h"
#include "sandbox2d/PlayScene.h"
#include "sandbox2d/MainMenuScene.h"
#include "utils/ResourcesAllocator.h"
#include "utils/ResourcesDirectory.h"
#include "utils/Asset.h"

// Main game class where all the objects will be inside
class Game
{
private:
    Texture2D logo;                 // logo image
    Texture2D blue_sheets;          // blue ui sprite sheet
    Texture2D sokoban_sprite_sheet; // sokoban sprite sheet
    Font kenvector;                 // kenvector font
    Sound click_1;                  // click sound ogg

public:
    // Game objects will declare here
    SceneManagerBase *SceneManager = SceneManager->Get_Instance();                     // Get the SceneManager instance here
    ResourcesDirectoryBase *Resources_Directory = Resources_Directory->Get_Instance(); // Get Resource Directory instance here
    AssetBase *Asset = Asset->Get_Instance();                                          // Get the Asset instance here

    Game();          // Game class Constructor
    virtual ~Game(); // Game class deconstructor
    void Start();    // Game Initialize function
    void Update();   // Game class update function
    void Render();   // Game class draw function
    void Clear();    // Game class clean function

    void Load_Data();   // load the data of the game one time
    void Unload_Data(); // unload the data of the game one time
};                      // class Game

#endif // GAME_H