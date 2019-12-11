#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H

#include <iostream>
#include <stack>
#include <memory>
#include <unordered_map>

#include "Scene.h"

// Note class Scene Manager use singleton pattern. Before using stack and
// now using unorder map to saves the all the scenes
class SceneManagerBase
{
private:
    static SceneManagerBase *instance; // Allow only one Scene Manager instance in the game

    SceneManagerBase(); // Private constructor so that no objects can be created.

    std::unordered_map<unsigned int, std::shared_ptr<Scene>> scenes; // collection of scenes
    std::shared_ptr<Scene> current_scene;                            // current scene object
    unsigned int scene_id;                                           // scene id

public:
    virtual ~SceneManagerBase(); // Deconstructor of Scene Manager class

    // This is function to get the instance of Scene Manager class
    static SceneManagerBase *Get_Instance()
    {
        if (!instance)
            instance = new SceneManagerBase;
        return instance;
    }

    void Start();  // Start the scene note:may not need for this function
    void Update(); // Update the current scene
    void Render(); // Render the current scene
    void Clear();  // Clear the current scene

    unsigned int Add_Scene(std::shared_ptr<Scene> scene); // Add new scene
    void Load_Scene(unsigned int id);                     // Load scene
    void Remove_Scene(unsigned int id);                   // remove the scene

}; // class SceneManagerBase

#endif // SCENEMANAGER_H