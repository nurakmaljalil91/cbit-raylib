#include "Player.h"

Player::Player() {}

Player::~Player() {}

void Player::Start()
{
    this->transform.position.x = GetScreenWidth() / 2;
    this->transform.position.y = GetScreenHeight() / 2;

    this->Add_Component<SpriteRenderer>(Asset->Get_Texture("sokoban"), 1024, 108, 92, 108);
    this->Add_Component<CharacterController>();
}

void Player::Update() {}

void Player::Render()
{
}

void Player::Clear() {}
