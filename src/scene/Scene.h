#ifndef SCENE_H
#define SCENE_H

class Scene
{
public:
    Scene();
    virtual ~Scene();
    virtual void Start() = 0;
    virtual void Update() = 0;
    virtual void Render() = 0;
};

#endif // SCENE_H