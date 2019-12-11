#include "Game.h"

Game::Game()
{
}

Game::~Game()
{
}

void Game::Start()
{
    //SceneManager->Add_Scene()
    std::shared_ptr<SplashScreenScene> splashScreen = std::make_shared<SplashScreenScene>();
    std::shared_ptr<MainMenuScene> main_menu = std::make_shared<MainMenuScene>();
    SceneManager->Add_Scene(splashScreen);
    SceneManager->Add_Scene(main_menu);
    //SceneManager->Add_Scene(new Scene());
    //SceneManager->Add_Scene(new PlayScene());
    //SceneManager->Add_Scene(new MainMenuScene());
    SceneManager->Load_Scene(0);
    // player.Add_Component<SpriteRenderer>("../resources/Player/player_05.png");
    // player.Add_Component<CharacterController>();
    SceneManager->Start();
}

void Game::Update()
{
    ///player.Update();
    SceneManager->Update();
    //std::cout << player.transform.position.x << std::endl;
}

void Game::Render()
{
    //player.Render();
    SceneManager->Render();
}

void Game::Clear()
{
    //player.Clear();
    SceneManager->Clear();
}
