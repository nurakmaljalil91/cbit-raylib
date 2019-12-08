#include "Game.h"

Game::Game() {}
Game::~Game() {}
void Game::Start()
{
    player.Add_Component<SpriteRenderer>("../resources/Player/player_05.png");
    player.Add_Component<CharacterController>();
}

void Game::Update()
{
    player.Update();
        if (IsKeyDown(KEY_D))
        player.transform.position.x += 2.0f;
    if (IsKeyDown(KEY_A))
        player.transform.position.x -= 2.0f;
    if (IsKeyDown(KEY_W))
        player.transform.position.y -= 2.0f;
    if (IsKeyDown(KEY_S))
        player.transform.position.y += 2.0f;

    //std::cout << player.transform.position.x << std::endl;
}
void Game::Render()
{
    player.Render();
}

void Game::Clear(){
    player.Clear();
}
