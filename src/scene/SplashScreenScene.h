#ifndef SPLASHSCREENSCENE_H
#define SPLASHSCREENSCENE_H

#include "raylib.h"
#include "Scene.h"
#include "SceneManager.h"
#include "../utils/ResourcesDirectory.h"
#include "../ecs/Entity.h"
#include "../ecs/SpriteRenderer.h"
#include "../ecs/CharacterController.h"
#include "../ecs/Button.h"

class SplashScreenScene : public Scene
{
private:
    Entity splash_screen;
    double time_to_fade;
public:
    SceneManagerBase *SceneManager = SceneManager->Get_Instance();
    ResourcesDirectoryBase *Resources_Directory = Resources_Directory->Get_Instance();

    SplashScreenScene();
    virtual ~SplashScreenScene();

    void On_Create() override;  // Called when scene initially created. Called once per scene.
    void On_Destroy() override; // Called when scene destroyed. Called once per scene.

    void On_Activate() override;   // Called whenever a scene is activated.
    void On_Deactivate() override; // Called whenever a scene is deactivated.

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
};

#endif // SPLASHSCREENSCENE_H