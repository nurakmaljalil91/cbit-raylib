#ifndef CUBE_H
#define CUBE_H

#include <iostream>
#include "Component.h"
#include "raylib.h"

class Cube : public Component
{
public:
    Cube();
    ~Cube();

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
};
#endif // CUBE_H