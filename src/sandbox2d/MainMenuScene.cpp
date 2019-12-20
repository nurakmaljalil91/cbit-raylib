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
    start_text.transform.position.x = 590;
    start_text.transform.position.y = 340;
    start_button.Get_Component<Button>().Set_Hover_Image(Resources_Directory->Get_SpriteSheet() + "blueSheet.png", 190, 49, 190, 45);
    start_text.Add_Component<Text>(Resources_Directory->Get_Font() + "kenvector_future.ttf");
    start_text.Get_Component<Text>().text = "START";
}

void MainMenuScene::Update()
{
    //std::cout << GetFrameTime() << std::endl;
    //std::cout << "Main Menu Scene" << std::endl;
    //std::cout << start_button.Get_Component<Button>().state << std::endl;
    if (start_button.Get_Component<Button>().State_Click())
    {
        SceneManager->Load_Scene(2);
    }
    start_button.Update();
    start_text.Update();
}

void MainMenuScene::Render()
{
    start_button.Render();
    start_text.Render();
}

void MainMenuScene::Clear()
{
    start_button.Clear();
    start_text.Clear();
}