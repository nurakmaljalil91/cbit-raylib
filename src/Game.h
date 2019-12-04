#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "raylib.h"

class Game
{
public:
    Game();
    virtual ~Game();
    void Start();
    void Update();
    void Render();
};

#endif // GAME_H