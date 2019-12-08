#ifndef COMPONENT_H
#define COMPONENT_H
#include "raylib.h"
class Component
{
protected:
public:
    Vector3 position;
    Vector3 rotation;
    Vector3 scale;
    // bool enabled;
    Component();
    ~Component();

    void Update_Transform(Vector3 mPosition, Vector3 mRotation, Vector3 mScale);

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Clear() = 0;
};
#endif // COMPONENT_H