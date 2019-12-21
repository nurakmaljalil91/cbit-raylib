#include "SpriteRenderer.h"

SpriteRenderer::SpriteRenderer(const char *file_location) : show_rect(false)
{
    texture = LoadTexture(file_location); // load the texture
    width = texture.width;                // the width of the image depend on the image size
    height = texture.height;              // the height of the sprite is depend of the texture height

    source_rect = {0.0f, 0.0f, width, height}; // original image rect

    destination_rect = {position.x, position.y, width, height}; // where to draw the texture

    anchor = {(width - position.x) / 2, (height - position.y) / 2}; // anchor is the origin of the image // on this case middle of texture
    rotation = 0;
    color = WHITE;
}

SpriteRenderer::SpriteRenderer(std::string file_location) : show_rect(false)
{
    texture = LoadTexture(file_location.c_str());
    width = texture.width;
    height = texture.height;

    source_rect = {0.0f, 0.0f, width, height};

    destination_rect = {position.x, position.y, width, height};

    anchor = {(width - position.x) / 2, (height - position.y) / 2};
    rotation = 0;
    color = WHITE;
}

SpriteRenderer::SpriteRenderer(Texture2D _texture) : show_rect(false)
{
    texture = _texture;
    width = texture.width;
    height = texture.height;

    source_rect = {0.0f, 0.0f, width, height};

    destination_rect = {position.x, position.y, width, height};

    anchor = {(width - position.x) / 2, (height - position.y) / 2};
    rotation = 0;
    color = WHITE;
}

SpriteRenderer::SpriteRenderer(std::string file_location, float x, float y, float w, float h) : show_rect(false)
{
    texture = LoadTexture(file_location.c_str());
    width = w;
    height = h;

    source_rect = {x, y, width, height};

    destination_rect = {position.x, position.y, width, height};

    anchor = {(width - position.x) / 2, (height - position.y) / 2};
    rotation = 0;
    color = WHITE;
}

SpriteRenderer::SpriteRenderer(Texture2D _texture, float x, float y, float w, float h) : show_rect(false)
{
    texture = _texture;
    width = w;
    height = h;

    source_rect = {x, y, width, height};

    destination_rect = {position.x, position.y, width, height};

    anchor = {(width - position.x) / 2, (height - position.y) / 2};
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
    if (show_rect)
    {
        DrawLine(destination_rect.x, destination_rect.y, destination_rect.x + 100, destination_rect.y, BLUE);
        DrawLine(destination_rect.x, destination_rect.y, destination_rect.x, destination_rect.y + 100, GREEN);
    }

    destination_rect = {position.x, position.y, width, height};

    DrawTexturePro(texture, source_rect, destination_rect, anchor, rotation, color);
}

void SpriteRenderer::Clear()
{
    UnloadTexture(texture);
}