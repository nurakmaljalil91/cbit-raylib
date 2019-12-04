#include "Game.h"

Game::Game() {}
Game::~Game() {}
void Game::Start()
{
}

void Game::Update()
{
    if (IsKeyDown(KEY_ENTER))
    {
        std::cout << "testing" << std::endl;
    }
}
void Game::Render() {}
