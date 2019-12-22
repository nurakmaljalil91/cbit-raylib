#include "EntitiesManager.h"

void EntitiesManager::Add(std::shared_ptr<Entity> entity)
{
    new_entities.push_back(entity); // add entity to the entities
}

void EntitiesManager::Start() {}

void EntitiesManager::Update()
{
    for (const auto &e : entities)
    {
        e->Update(); // update all the entities
    }
}

void EntitiesManager::Render()
{
    for (const auto &e : entities)
    {
        e->Render(); // Render all the entities
    }
}

void EntitiesManager::Clear()
{
    for (const auto &e : entities)
    {
        e->Clear(); // Clear all the entities
    }
}

bool EntitiesManager::Inside(std::shared_ptr<Entity> entity)
{
    if (std::find(entities.begin(), entities.end(), entity) != entities.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

void EntitiesManager::Init_New_Entities()
{
    entities.insert(entities.end(), new_entities.begin(), new_entities.end()); // combine the new entities with the original entities

    new_entities.clear(); // clear the oject inside the new entities
}

void EntitiesManager::Queue_For_Removal()
{
    auto entity_iter = entities.begin(); // create iterator for the entity

    while (entity_iter != entities.end())
    {

        auto ent = *entity_iter;

        if (ent->Is_Ready_To_Remove())
        {
            entity_iter = entities.erase(entity_iter);
        }
        else
        {
            ++entity_iter;
        }
    }
}