#ifndef SCENE_H
#define SCENE_H

#include "../utils/ResourcesDirectory.h"

// class scene act as base for all the scene that will
// be created in the game
class Scene
{
public:
    // SceneManagerBase *SceneManager = SceneManager->Get_Instance();
    //ResourcesDirectoryBase *Resources_Directory = Resources_Directory->Get_Instance();

    Scene();
    ~Scene();

    virtual void On_Create() = 0;  // Called when scene initially created. Called once per scene.
    virtual void On_Destroy() = 0; // Called when scene destroyed. Called once per scene.

    virtual void On_Activate(){};   // Called whenever a scene is activated.
    virtual void On_Deactivate(){}; // Called whenever a scene is deactivated.

    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Clear() = 0;
}; // class Scene

#endif // SCENE_H