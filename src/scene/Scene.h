#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
    Scene();  // Constructor scene parent
    ~Scene(); // Deconstructor scene parent

    virtual void On_Create() = 0;  // Called when scene initially created. Called once per scene.
    virtual void On_Destroy() = 0; // Called when scene destroyed. Called once per scene.

    virtual void On_Activate(){};   // Called whenever a scene is activated.
    virtual void On_Deactivate(){}; // Called whenever a scene is deactivated.

    virtual void Start() = 0;  // virtual Start function
    virtual void Update() = 0; // Virtual Update function
    virtual void Render() = 0; // Virtual Render function
    virtual void Clear() = 0;  // Virtual Clear function
};                             // class Scene

#endif // SCENE_H