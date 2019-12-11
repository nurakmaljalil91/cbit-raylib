#include "SplashScreenScene.h"

SplashScreenScene::SplashScreenScene() : time_to_fade(200) {}

SplashScreenScene::~SplashScreenScene() {}

void SplashScreenScene::On_Create()
{
}

void SplashScreenScene::On_Destroy() {}

void SplashScreenScene::On_Activate() {}

void SplashScreenScene::On_Deactivate() {}

void SplashScreenScene::Start()
{
    splash_screen.Add_Component<Button>(Resources_Directory->Get() + "logo.png");
    splash_screen.transform.position.x = GetScreenWidth() / 2;
    splash_screen.transform.position.y = GetScreenHeight() / 2;
    time_to_fade = 200;
}

void SplashScreenScene::Update()
{
    splash_screen.Update();
    // if (splash_screen.Get_Component<Button>().action && splash_screen.Get_Component<Button>().state == 1)
    // {
    //     SceneManager->Load_Scene(1);
    // }
    time_to_fade -= GetTime();
    if (time_to_fade <= 0)
    {
        SceneManager->Load_Scene(1);
    }
}

void SplashScreenScene::Render()
{
    ClearBackground(WHITE);
    splash_screen.Render();
}

void SplashScreenScene::Clear()
{
    splash_screen.Clear();
}