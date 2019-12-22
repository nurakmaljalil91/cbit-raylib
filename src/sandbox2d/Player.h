#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include "../ecs/Entity.h"
#include "../ecs/Text.h"
#include "../ecs/SpriteRenderer.h"
#include "../ecs/CharacterController.h"
#include "../utils/Asset.h"

class Player : public Entity
{
private:
public:
    AssetBase *Asset = Asset->Get_Instance();

    Player();          // Constructor
    virtual ~Player(); // Deconstructor

    void Start();
    void Update();
    void Render();
    void Clear();

}; // class Player

#endif // PLAYER_H