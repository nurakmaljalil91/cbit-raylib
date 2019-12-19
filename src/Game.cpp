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

}
