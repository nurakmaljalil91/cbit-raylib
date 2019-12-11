#include "CharacterController.h"

CharacterController::CharacterController(/* args */) {}
CharacterController::~CharacterController() {}
void CharacterController::Start() {}
void CharacterController::Update()
{

    if (IsKeyDown(KEY_RIGHT))
        entity->transform.position.x += 2.0f;
    if (IsKeyDown(KEY_LEFT))
        entity->transform.position.x -= 2.0f;
    if (IsKeyDown(KEY_UP))
        entity->transform.position.y -= 2.0f;
    if (IsKeyDown(KEY_DOWN))
        entity->transform.position.y += 2.0f;
}

void CharacterController::Render() {}
void CharacterController::Clear() {}