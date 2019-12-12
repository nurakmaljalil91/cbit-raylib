#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <iostream>
#include "../scene/Scene.h"

class PlayScene : public Scene
{
public:
    PlayScene();
    ~PlayScene();

    void On_Create() override;  // Called when scene initially created. Called once per scene.
    void On_Destroy() override; // Called when scene destroyed. Called once per scene.

    void On_Activate() override;   // Called whenever a scene is activated.
    void On_Deactivate() override; // Called whenever a scene is deactivated.

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
}; // class PlayScene

#endif // PLAYSCENE_H