#include "MainMenuScene.h"

MainMenuScene::MainMenuScene() {}

MainMenuScene::~MainMenuScene() {}

void MainMenuScene::On_Create() {}

void MainMenuScene::On_Destroy() {}

void MainMenuScene::On_Activate()
{
    start_button = std::make_shared<Entity>(); // create start button
    start_text = std::make_shared<Entity>();   // create start text
}

void MainMenuScene::On_Deactivate() {}

void MainMenuScene::Start()
{

    // start_button->Add_Component<Button>(Resources_Directory->Get_SpriteSheet() + "blueSheet.png", 0, 94, 190, 49);
    start_button->Add_Component<Button>(Asset->Get_Texture("blue_sheet"), 0, 94, 190, 49);
    start_button->transform.position.x = GetScreenWidth() / 2;  // put the button on the middle of the screen
    start_button->transform.position.y = GetScreenHeight() / 2; // put the button on the middle of the screen

    start_text->transform.position.x = 590; // text position a bit lower than button
    start_text->transform.position.y = 340; // text position a bit lower than button

    start_button->Get_Component<Button>().Set_Hover_Image(190, 49, 190, 45);

    start_text->Add_Component<Text>(Resources_Directory->Get_Font() + "kenvector_future.ttf");
    start_text->Get_Component<Text>().text = "START";

    entities_manager.Add(start_button);
    entities_manager.Add(start_text);
}

void MainMenuScene::Update()
{
    if (start_button->Get_Component<Button>().State_Click())
    {
        SceneManager->Load_Scene(2); // load play scene
        PlaySound(Asset->Get_Audio("click_1"));
    }

    entities_manager.Init_New_Entities();
    entities_manager.Queue_For_Removal();
    entities_manager.Update();
}

void MainMenuScene::Render()
{

    entities_manager.Render();
}

void MainMenuScene::Clear()
{

    entities_manager.Clear();
}