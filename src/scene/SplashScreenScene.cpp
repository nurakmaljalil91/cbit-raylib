#include "SplashScreenScene.h"

SplashScreenScene::SplashScreenScene() {}

SplashScreenScene::~SplashScreenScene() {}

void SplashScreenScene::On_Create()
{
    splash_screen.Add_Component<SpriteRenderer>(Resources_Directory->Get() + "logo.png");
    splash_screen.transform.position.x = 640;
    splash_screen.transform.position.y = 360;
}

void SplashScreenScene::On_Destroy() {}

void SplashScreenScene::On_Activate() {}

void SplashScreenScene::On_Deactivate() {}

void SplashScreenScene::Start() {}

void SplashScreenScene::Update()
{
    splash_screen.Update();
}

void SplashScreenScene::Render()
{
    splash_screen.Render();
}

void SplashScreenScene::Clear()
{
    splash_screen.Clear();
}