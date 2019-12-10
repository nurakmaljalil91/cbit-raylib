#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <iostream>
#include "../scene/Scene.h"
#include "raylib.h"
#include "../ecs/Entity.h"
#include "../ecs/Button.h"

class MainMenuScene : public Scene
{
public:
    Entity start_button;

    MainMenuScene();
    ~MainMenuScene();

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
};

#endif // MAINMENUSCENE_H