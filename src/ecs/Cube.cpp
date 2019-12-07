#include "Cube.h"

Cube::Cube() {}
Cube::~Cube() {}

void Cube::Start()
{
}

void Cube::Update()
{
}

void Cube::Render()
{
    DrawCube(position, scale.x, scale.y, scale.z, GRAY);
    DrawCubeWires(position, scale.x, scale.y, scale.z, DARKGRAY);
}