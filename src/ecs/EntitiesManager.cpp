#include "EntitiesManager.h"

EntitiesManager::EntitiesManager() {}

EntitiesManager::~EntitiesManager() {}

void EntitiesManager::Add(std::shared_ptr<Entity> entity)
{
    new_entities.push_back(entity);
}

void EntitiesManager::Start() {}

void EntitiesManager::Update()
{
    for (auto &e : entities)
    {
        e->Update();
    }
}

void EntitiesManager::Render()
{
    for (auto &e : entities)
    {
        e->Render();
    }
}

void EntitiesManager::Clear()
{
    for (auto &e : entities)
    {
        e->Clear();
    }
}

void EntitiesManager::Init_New_Entities() {
    if(new_entities.size() > 0){
        for(const auto& e:entities){
        
        }
    }
}