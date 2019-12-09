#ifndef GAME_H
#define GAME_H
#include <iostream>
#include "raylib.h"
#include "ecs/Entity.h"
#include "ecs/Component.h"
#include "ecs/SpriteRenderer.h"
#include "ecs/CharacterController.h"
#include "scene/SceneManager.h"
#include "sandbox2d/PlayScene.h"
#include "sandbox2d/MainMenuScene.h"
// #include "scene/Scene.h"


// Main game class where all the objects will be inside
class Game
{
public:
    // Game objects will declare here
    //Entity player;
    SceneManagerBase *SceneManager = SceneManager->Get_Instance();

    Game();          // Game class Constructor
    virtual ~Game(); // Game class deconstructor
    void Start();    // Game Initialize function
    void Update();   // Game class update function
    void Render();   // Game class draw function
    void Clear();    // Game class clean function
};                   // class Game

#endif // GAME_H