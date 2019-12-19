#include "PlayScene.h"

PlayScene::PlayScene() {}

PlayScene::~PlayScene() {}

void PlayScene::On_Create() {}

void PlayScene::On_Destroy() {}

void PlayScene::On_Activate() {}

void PlayScene::On_Deactivate() {}

void PlayScene::Start() {}

void PlayScene::Update()
{
    // std::cout << Input->GetAxis("Horizontal") << std::endl;
    // std::cout << "Play Scene" << std::endl;
}

void PlayScene::Render() {
    ClearBackground(BLUE);

}

void PlayScene::Clear() {}