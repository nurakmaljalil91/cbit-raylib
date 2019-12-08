#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include <iostream>
#include <stack>
#include "Scene.h"
class SceneManagerBase
{
private:
    static SceneManagerBase *instance;

    SceneManagerBase(); // Private constructor so that no objects can be created.

    std::stack<Scene*> scenes;

public:
    int scene_number;

    virtual ~SceneManagerBase();

    static SceneManagerBase *Get_Instance()
    {
        if (!instance)
            instance = new SceneManagerBase;
        return instance;
    }
    void Set_Scene_Number(int _scene_number);
    int Get_Scene_Number();

    void Start();
    void Update();
    void Render();

    void Load_Scene(int mScene);
};

#endif // SCENEMANAGER_H