#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "raylib.h"
#include "ecs/Entity.h"
#include "ecs/Component.h"
#include "ecs/SpriteRenderer.h"
#include "ecs/CharacterController.h"

class Game
{
public:
    Entity player;
    Game();
    virtual ~Game();
    void Start();
    void Update();
    void Render();
    void Clear();
};

#endif // GAME_H