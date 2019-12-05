#ifndef COMPONENT_H
#define COMPONENT_H
#include "raylib.h"
class Component
{
public:
    Vector3 position;
    Component();
    ~Component();
};
#endif // COMPONENT_H