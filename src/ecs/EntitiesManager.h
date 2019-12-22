#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H

#include <memory>
#include <vector>
#include <algorithm>

#include "Entity.h"
// class Entity;

class EntitiesManager
{
private:
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Entity>> new_entities;

public:
    void Add(std::shared_ptr<Entity> entity); // Add the entity to entities

    void Start();  // Start all the entities initialization
    void Update(); // Update all the entities update
    void Render(); // Render all the entities render
    void Clear();  // Clear all teh entities clear

    bool Inside(std::shared_ptr<Entity> entity); // Check if entity inside the manager
    void Init_New_Entities();                    // Process new entities
    void Queue_For_Removal();                    // Process to remove entities
};                                               // class EntitiesManager

#endif // ENTITIESMANAGER_H