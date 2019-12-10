#include "MainMenuScene.h"

MainMenuScene::MainMenuScene()
{
}

MainMenuScene::~MainMenuScene()
{
}

void MainMenuScene::Start()
{

    start_button.Add_Component<Button>("../resources/blue_button00.png");
    start_button.transform.position.x = 640;
    start_button.transform.position.y = 360;
}

void MainMenuScene::Update()
{
    //std::cout << GetFrameTime() << std::endl;
    //std::cout << "Main Menu Scene" << std::endl;
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