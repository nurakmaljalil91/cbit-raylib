#include "Component.h"
//#include "Entity.h"

Component::Component() : enabled(true) {}
Component::~Component() {}

void Component::Update_Transform(Vector3 mPosition, Vector3 mRotation, Vector3 mScale)
{
    position = mPosition; // position of the component update with the entity
    rotation = mRotation; // rotation of the component update with the entity
    scale = mScale;       // scale of the component update with the entity
}
