#include "SceneManager.h"

SceneManagerBase::SceneManagerBase() : scenes(0),
                                       current_scene(0),
                                       scene_id(0) {}

SceneManagerBase::~SceneManagerBase() {}

void SceneManagerBase::Start() {}

void SceneManagerBase::Update()
{
    if (current_scene)
    {
        current_scene->Update(); // Update the current scene
    }
}

void SceneManagerBase::Render()
{
    if (current_scene)
    {
        current_scene->Render(); // Render the current scene
    }
}

void SceneManagerBase::Clear()
{
    if (current_scene)
    {
        current_scene->Clear(); // Clear the current scene
    }
}

unsigned int SceneManagerBase::Add_Scene(std::shared_ptr<Scene> scene)
{
    auto inserted = scenes.insert(std::make_pair(scene_id, scene));
    inserted.first->second->On_Create();
    return scene_id++;
}

void SceneManagerBase::Load_Scene(unsigned int id)
{
    auto iter = scenes.find(id);
    if (iter != scenes.end())
    {
        if (current_scene)
        {
            current_scene->On_Deactivate(); // FIXME:Maybe change to On Deactivate
        }
        current_scene = iter->second;
        current_scene->On_Activate(); // FIXME: Maybe Change to On Active
        current_scene->Start(); 
    }
    else
    {
        std::cout << "Scene id not found" << std::endl;
    }
}

void SceneManagerBase::Remove_Scene(unsigned int id)
{
    auto iter = scenes.find(id);
    if (iter != scenes.end())
    {
        if (current_scene == iter->second)
        {
            current_scene = nullptr;
        }

        iter->second->On_Destroy(); // FIXME: Change to On destroy
        scenes.erase(iter);
    }
}
