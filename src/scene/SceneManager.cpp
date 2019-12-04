#include "SceneManager.h"

SceneManager::SceneManager()
{
    scene_number = 0;
}
SceneManager::~SceneManager() {}


void SceneManager::Set_Scene_Number(int _scene_number) {
    scene_number = _scene_number;
}
int SceneManager::Get_Scene_Number() {
    return scene_number;
}