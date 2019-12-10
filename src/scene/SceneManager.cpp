#include "SceneManager.h"

SceneManagerBase::SceneManagerBase()
{
    current_scene = 0;
}

SceneManagerBase::~SceneManagerBase() {}

void SceneManagerBase::Set_Scene_Number(int _scene_number)
{
    current_scene = _scene_number;
}

int SceneManagerBase::Get_Scene_Number()
{
    return current_scene;
}

void SceneManagerBase::Start()
{
    if (!scenes.empty())
    {
        scenes.top()->Start();
    }
}

void SceneManagerBase::Update()
{
    if (!scenes.empty())
    {
        scenes.top()->Update();
    }
}

void SceneManagerBase::Render()
{
    if (!scenes.empty())
    {
        scenes.top()->Render();
    }
}

void SceneManagerBase::Clear()
{
    if (!scenes.empty())
    {
        scenes.top()->Clear();
    }
}

void SceneManagerBase::Add_Scene(Scene *mScene)
{
    scenes.push(mScene);
}

void SceneManagerBase::Load_Scene(int mScene)
{
}