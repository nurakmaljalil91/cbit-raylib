#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <iostream>
#include <memory>
#include "../scene/Scene.h"
#include "raylib.h"
//#include "../ecs/EntitiesManager.h"
#include "../ecs/Entity.h"
#include "../ecs/Button.h"
#include "../ecs/Text.h"
#include "../scene/SceneManager.h"
#include "../utils/ResourcesDirectory.h"

class MainMenuScene : public Scene
{
private:
    // std::shared_ptr<Entity> start_button;              // button start
    Entity start_button;
    Entity start_text;                // text in front of button
    //EntitiesManager entities_manager; // the entities manager

public:
    SceneManagerBase *SceneManager = SceneManager->Get_Instance();
    ResourcesDirectoryBase *Resources_Directory = Resources_Directory->Get_Instance();

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
}; // class MainMenuScene

#endif // MAINMENUSCENE_H