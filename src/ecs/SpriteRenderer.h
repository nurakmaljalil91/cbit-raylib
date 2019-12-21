#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

#include <iostream>
#include <string>
#include "Component.h"

class SpriteRenderer : public Component
{
private:
    Texture2D texture;

public:
    float width;
    float height;
    Rectangle source_rect;
    Rectangle destination_rect;
    Color color;
    Vector2 anchor;
    float rotation;

    bool show_rect;

    SpriteRenderer(const char *file_location);
    SpriteRenderer(std::string file_location);
    SpriteRenderer(Texture2D _texture);
    SpriteRenderer(std::string file_location, float x, float y, float w, float h);
    SpriteRenderer(Texture2D _texture, float x, float y, float w, float h);

    ~SpriteRenderer();

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
};
#endif // SPRITERENDERER_H
