#include "SplashScreenScene.h"

SplashScreenScene::SplashScreenScene() : time_to_fade(200) {}

SplashScreenScene::~SplashScreenScene() {}

void SplashScreenScene::On_Create() {}

void SplashScreenScene::On_Destroy() {}

void SplashScreenScene::On_Activate() {}

void SplashScreenScene::On_Deactivate() {}

void SplashScreenScene::Start()
{
    splash_screen.Add_Component<SpriteRenderer>(Asset->Get_Texture("logo"));
    splash_screen.transform.position.x = GetScreenWidth() / 2;  // make logo in the middle of the screen
    splash_screen.transform.position.y = GetScreenHeight() / 2; // make logo in the middle of the screen

    time_to_fade = 200; // start the timers
}

void SplashScreenScene::Update()
{
    splash_screen.Update();
    time_to_fade -= GetTime(); // reduce the timer
    if (time_to_fade <= 0)     // when timer reach zero
    {
        SceneManager->Load_Scene(1); // Change the scene to the first scene
    }
}

void SplashScreenScene::Render()
{
    ClearBackground(WHITE); // Background color
    splash_screen.Render();
}

void SplashScreenScene::Clear()
{
    splash_screen.Clear();
}