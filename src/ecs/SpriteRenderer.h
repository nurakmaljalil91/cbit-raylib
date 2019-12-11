#ifndef SPRITERENDERER_H
#define SPRITERENDERER_H

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
    Vector2 origin;
    float rotation;
    SpriteRenderer(const char* file_location);
    SpriteRenderer(std::string file_location);
    ~SpriteRenderer();

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
};
#endif // SPRITERENDERER_H
