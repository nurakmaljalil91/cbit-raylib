#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <bitset>
#include <array>
#include "raylib.h"
#include "Component.h"
#include "Cube.h"

using ComponentID = std::size_t;
using Group = std::size_t;

inline ComponentID Get_New_Component_Type_ID()
{
    static ComponentID last_ID = 0u;
    return last_ID;
}

template <typename T>
inline ComponentID Get_Component_Type_ID() noexcept
{
    static_assert(std::is_base_of<Component, T>::value, "");
    static ComponentID type_ID = Get_New_Component_Type_ID();
    return type_ID;
}

constexpr std::size_t max_components = 32;
constexpr std::size_t max_groups = 32;

using ComponentBitSet = std::bitset<max_components>;
using GroupBitSet = std::bitset<max_groups>;

using ComponentArray = std::array<Component *, max_components>;

// GameObject work as entity identifier
struct GameObject
{
    const char *name;      // name of the gameObject
    const char *tag;       // tag for gameObject to be found
    int layer = 0;         // check where the layer of the entity
    bool is_active = true; // only update and render when the entity is active
};

// Transform act physical attributes saver
struct ETransform
{
    Vector3 position = {0.0, 0.0, 0.0}; // position of the entity
    Vector3 rotation = {0.0, 0.0, 0.0}; // rotation of the entity
    Vector3 scale = {1.0, 1.0, 1.0};    // scale for the entity
};

// Class of entity
class Entity
{
public:
    ComponentArray component_array;
    ComponentBitSet component_bitset;
    GroupBitSet group_bitset;

    GameObject gameObject; // GameObject of the entity
    ETransform transform;  // Transform of the entity

    std::vector<std::unique_ptr<Component>> components; // all components attach to the entity

    Entity();          // Entity constructor
    virtual ~Entity(); // Entity deconstructor

    bool Has_Group(Group mGroup)
    {
        return group_bitset[mGroup];
    }
    void Add_Group(Group mGroup);
    void Delete_Group(Group mGroup)
    {
        group_bitset[mGroup] = false;
    }

    template <typename T>
    bool Has_Component() const
    {
        return component_bitset[Get_Component_Type_ID<T>()];
    }

    template <typename T, typename... TArgs>
    T &Add_Component(TArgs &&... mArgs)
    {
        T *c(new T(std::forward<TArgs>(mArgs)...)); // Create the component
        std::unique_ptr<Component> uPtr{c};
        components.emplace_back(std::move(uPtr));

        component_array[Get_Component_Type_ID<T>()] = c;
        component_bitset[Get_Component_Type_ID<T>()] = true;
        c->Start();
        return *c;
    }

    template <typename T>
    T &Get_Component() const
    {
        auto ptr(component_array[Get_Component_Type_ID<T>()]);
        return *static_cast<T *>(ptr);
    }

    void Update()
    {
        if (gameObject.is_active)
        {
            for (auto &c : components)
            {
                // update the transform for the component
                c->Update_Transform(transform.position, transform.rotation, transform.scale);
                c->Update();
            }
        }
    }

    void Render()
    {
        if (gameObject.is_active)
        {
            for (auto &c : components)
            {
                c->Render();
            }
        }
    }
};
#endif // ENTITY_H