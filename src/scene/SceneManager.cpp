#include "SceneManager.h"

SceneManagerBase::SceneManagerBase()
{
    scene_number = 0;
}

SceneManagerBase::~SceneManagerBase() {}

void SceneManagerBase::Set_Scene_Number(int _scene_number)
{
    scene_number = _scene_number;
}

int SceneManagerBase::Get_Scene_Number()
{
    return scene_number;
}

void SceneManagerBase::Start(){}
void SceneManagerBase::Update(){}
void SceneManagerBase::Render(){}

void SceneManagerBase::Load_Scene(int mScene){
    
}