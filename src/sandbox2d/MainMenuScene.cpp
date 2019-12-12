#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::On_Create()
{

    //splash_screen.Add_Component<SpriteRenderer>(Resources_Directory->Get() + "logo.png");
}
void MainMenuScene::On_Destroy() {}

void MainMenuScene::On_Activate() {}
void MainMenuScene::On_Deactivate() {}

void MainMenuScene::Start()
{
    start_button.Add_Component<Button>(Resources_Directory->Get_SpriteSheet() + "blueSheet.png", 0, 94, 190, 49);
    start_button.transform.position.x = 640;
    start_button.transform.position.y = 360;   
}

void MainMenuScene::Update()
{
    //std::cout << GetFrameTime() << std::endl;
    //std::cout << "Main Menu Scene" << std::endl;
    if (start_button.Get_Component<Button>().action && start_button.Get_Component<Button>().state == 1)
    {
        SceneManager->Load_Scene(2);
    }
    start_button.Update();
}
void MainMenuScene::Render()
{
    start_button.Render();
}
void MainMenuScene::Clear()
{
    start_button.Clear();
}