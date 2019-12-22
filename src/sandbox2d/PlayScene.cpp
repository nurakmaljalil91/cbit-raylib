#include "PlayScene.h"

PlayScene::PlayScene() {}

PlayScene::~PlayScene() {}

void PlayScene::On_Create() {}

void PlayScene::On_Destroy() {}

void PlayScene::On_Activate()
{
    player = std::make_shared<Player>();
}

void PlayScene::On_Deactivate() {}

void PlayScene::Start()
{
    player->Start();
    entities_manager.Add(player);
}

void PlayScene::Update()
{
    player->Update();
    entities_manager.Init_New_Entities();
    entities_manager.Queue_For_Removal();
    entities_manager.Update();
}

void PlayScene::Render()
{
    ClearBackground(BLUE);
    player->Render();
    entities_manager.Render();
}

void PlayScene::Clear()
{
    player->Clear();
    entities_manager.Clear();
}