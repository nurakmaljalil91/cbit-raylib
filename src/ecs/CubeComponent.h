#ifndef CUBECOMPONENT_H
#define CUBECOMPONENT_H

#include "Component.h"
#include "raylib.h"

class CubeComponent : public Component
{
public:
 
    CubeComponent();
    ~CubeComponent();

    void Start() override;
    void Update() override;
    void Render() override;
};
#endif // CUBECOMPONENT_H