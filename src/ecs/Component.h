#ifndef COMPONENT_H
#define COMPONENT_H

#include "raylib.h"
//#include "Entity.h" // this will cause compiler error

class Entity; // forward declaration of the Entity

class Component
{
protected:
public:
    Entity *entity;   // entity where the this component is gonna attach
    Vector3 position; // position of entity
    Vector3 rotation; // rotation of entity
    Vector3 scale;    // scale of entity
    bool enabled;     // only update and render when enable
    Component();      // Base constructor
    ~Component();     // Base deconstructor

    void Update_Transform(Vector3 mPosition, Vector3 mRotation, Vector3 mScale); // update the current transform of the entity

    virtual void Start() = 0;  // virtual function of start // = 0 no need to declare
    virtual void Update() = 0; // virtual function of update
    virtual void Render() = 0; // virtual function of render
    virtual void Clear() = 0;  // virtual function of  clear
};                             // class component
#endif                         // COMPONENT_H