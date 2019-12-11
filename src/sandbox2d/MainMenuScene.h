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

    void On_Create() override;  // Called when scene initially created. Called once per scene.
    void On_Destroy() override; // Called when scene destroyed. Called once per scene.

    void On_Activate() override;   // Called whenever a scene is activated.
    void On_Deactivate() override; // Called whenever a scene is deactivated. 

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
};

#endif // MAINMENUSCENE_H