#ifndef PLAYSCENE_H
#define PLAYSCENE_H

#include <iostream>
#include "../scene/Scene.h"

class PlayScene : public Scene
{
public:
    PlayScene();
    ~PlayScene();

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
}; // class PlayScene

#endif // PLAYSCENE_H