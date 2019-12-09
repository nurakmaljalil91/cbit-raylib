#ifndef MAINMENUSCENE_H
#define MAINMENUSCENE_H

#include <iostream>
#include "../scene/Scene.h"

class MainMenuScene : public Scene
{
public:
    MainMenuScene();
    ~MainMenuScene();

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
};

#endif // MAINMENUSCENE_H