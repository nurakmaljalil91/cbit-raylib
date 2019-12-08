#ifndef CHARACTERCONTROLLER_H
#define CHARACTERCONTROLLER_H

#include "Component.h"
#include <iostream>

class CharacterController : public Component
{
private:
    /* data */
public:
    CharacterController(/* args */);
    ~CharacterController();
    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;    
};

#endif // CHARACTERCONTROLLER