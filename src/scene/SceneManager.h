#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

class SceneManager
{
private:
    static SceneManager *instance;

    SceneManager(); // Private constructor so that no objects can be created.

public:
    int scene_number;

    virtual ~SceneManager();

    static SceneManager *Get_Instance()
    {
        if (!instance)
            instance = new SceneManager;
        return instance;
    }
    void Set_Scene_Number(int _scene_number);
    int Get_Scene_Number();
};

#endif // SCENEMANAGER_H