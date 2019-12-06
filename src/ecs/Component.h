#ifndef COMPONENT_H
#define COMPONENT_H
#include "raylib.h"
class Component
{
private:
    Vector3 position;

public:
    Component();
    ~Component();

    void Set_Position(Vector3 mPosition);
    Vector3 Get_Position();

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};
#endif // COMPONENT_H