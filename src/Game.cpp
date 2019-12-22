#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Start()
{
    std::shared_ptr<SplashScreenScene> splashScreen = std::make_shared<SplashScreenScene>(); // Create the splash screen scene
    std::shared_ptr<MainMenuScene> main_menu = std::make_shared<MainMenuScene>();            // Create the main menu scene
    std::shared_ptr<PlayScene> play_scene = std::make_shared<PlayScene>();                   // Create the play scene

    SceneManager->Add_Scene(splashScreen); // scene - 0
    SceneManager->Add_Scene(main_menu);    // scene - 1
    SceneManager->Add_Scene(play_scene);   // scene - 2

    SceneManager->Load_Scene(0); // Start the first scene
    SceneManager->Start();       // Start all the scene manager scenes
}

void Game::Update()
{
    SceneManager->Update(); // Update all the scenes in scene manager
}

void Game::Render()
{
    SceneManager->Render(); // Render all the scenes in scene manager
}

void Game::Clear()
{
    SceneManager->Clear(); // Clear all the scenes in scene manager
}

void Game::Load_Data()
{
    logo = LoadTexture("../resources/Images/logo.png");                                        // load logo texture
    blue_sheets = LoadTexture("../resources/SpriteSheets/blueSheet.png");                      // load blue ui sprite sheet
    sokoban_sprite_sheet = LoadTexture("../resources/SpriteSheets/sokoban_spritesheet@2.png"); // load sokoban sprite sheet
    kenvector = LoadFont("../resources/Fonts/kenvector_future.ttf");                           // load kenvector font
    click_1 = LoadSound("../resources/Audio/click1.ogg");                                      // load click sound

    Asset->Add_Texture("logo", logo);                    // insert logo inside Asset
    Asset->Add_Texture("blue_sheet", blue_sheets);       // insert blue ui sprite sheet inside Asset
    Asset->Add_Texture("sokoban", sokoban_sprite_sheet); // insert sokoban sprite sheet inside Asset
    Asset->Add_Font("kenvector", kenvector);             // insert kenvector font inside Asset
    Asset->Add_Audio("click_1", click_1);                // insert click sound inside Asset
}

void Game::Unload_Data()
{
    UnloadTexture(logo);                 // Unload logo texture
    UnloadTexture(blue_sheets);          // unload blue ui sprite sheet
    UnloadTexture(sokoban_sprite_sheet); // unload sokoban sprite sheet
    UnloadFont(kenvector);               // Unload kenvector font
    UnloadSound(click_1);                // unload click sound
}