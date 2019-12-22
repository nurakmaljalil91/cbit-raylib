#include "PlayScene.h"

PlayScene::PlayScene() {}

PlayScene::~PlayScene() {}

void PlayScene::On_Create() {}

void PlayScene::On_Destroy() {}

void PlayScene::On_Activate()
{
    player = std::make_shared<Entity>();
}

void PlayScene::On_Deactivate() {}

void PlayScene::Start()
{
    player->transform.position.x = GetScreenWidth() / 2;
    player->transform.position.y = GetScreenHeight() / 2;

    player->Add_Component<SpriteRenderer>(Resources_Directory->Get_SpriteSheet() + "sokoban_spritesheet@2.png", 1024, 108, 92, 108);
    player->Add_Component<CharacterController>();
    entities_manager.Add(player);
}

void PlayScene::Update()
{
    // if (entities_manager.Inside(player))
    // {
    //     player->Update();
    // }
    //player->Update();
    entities_manager.Init_New_Entities();
    entities_manager.Queue_For_Removal();
    entities_manager.Update();
}

void PlayScene::Render()
{
    ClearBackground(GRAY);
    // if (entities_manager.Inside(player))
    // {
    //     player->Render();
    // }
    // player->Render();
    entities_manager.Render();
}

void PlayScene::Clear()
{
    // if (entities_manager.Inside(player))
    // {
    //     player->Clear();
    // }
    // player->Clear();
    entities_manager.Clear();
}