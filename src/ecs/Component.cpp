#include "Component.h"
//#include "Entity.h"


Component::Component() {}
Component::~Component() {}

void Component::Update_Transform(Vector3 mPosition, Vector3 mRotation, Vector3 mScale)
{
    position = mPosition;
    rotation = mRotation;
    scale = mScale;
}
