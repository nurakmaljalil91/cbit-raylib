#ifndef ENTITIESMANAGER_H
#define ENTITIESMANAGER_H

#include <memory>
#include <vector>

#include "Entity.h"

class EntitiesManager
{
private:
    std::vector<std::shared_ptr<Entity>> entities;
    std::vector<std::shared_ptr<Entity>> new_entities;

public:
    EntitiesManager();          // Constructor
    virtual ~EntitiesManager(); // Deconstructor

    void Add(std::shared_ptr<Entity> entity); // Add the entity to entities

    void Start();  // Start all the entities initialization
    void Update(); // Update all the entities update
    void Render(); // Render all the entities render
    void Clear();  // Clear all teh entities clear

    void Init_New_Entities(); // Process new entities
};                            // class EntitiesManager

#endif // ENTITIESMANAGER_H