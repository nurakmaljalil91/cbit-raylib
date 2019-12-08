#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(const char *file_location)
{
    texture = LoadTexture(file_location);
    width = texture.width;
    height = texture.height;

    source_rect = {0.0f, 0.0f, width, height};

    destination_rect = {position.x, position.y, width , height };

    origin = {width, height};
    rotation = 0;
    color = WHITE;
}

SpriteRenderer::~SpriteRenderer()
{
}

void SpriteRenderer::Start()
{
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::Render()
{
    //DrawTexture(texture, position.x, position.y, color);
    destination_rect = {position.x, position.y, width , height };
    DrawTexturePro(texture, source_rect, destination_rect, origin, rotation, color);
}

void SpriteRenderer::Clear()
{
    UnloadTexture(texture);
}