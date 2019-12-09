#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
    Scene();
    ~Scene();
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
    virtual void Clear() = 0;
};

#endif // SCENE_H