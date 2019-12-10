#include "Button.h"

Button::Button(const char *file_location)
{
    texture = LoadTexture(file_location);
    width = texture.width;
    height = texture.height;

    source_rect = {0.0f, 0.0f, width, height};

    destination_rect = {position.x - width / 2, position.y - height / 2, width, height};

    origin = {width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2};
    rotation = 0;
    color = WHITE;

    std::cout << "width: " << width << ",height: " << height;
}

Button::~Button() {}

void Button::Start() {}

void Button::Update()
{
    mouse_position = GetMousePosition();
    // std::cout << "x: " << mouse_position.x;
    // std::cout << ",y: " << mouse_position.y << std::endl;

    if (CheckCollisionPointRec(mouse_position, destination_rect))
    {
        if(IsMouseButtonDown(MOUSE_LEFT_BUTTON)){
            std::cout << "You should change scene here" << std::endl;
        }
    }
}

void Button::Render()
{
    destination_rect = {position.x - width / 2, position.y - height / 2, width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2};
    // std::cout << center.x << "," << center.y << std::endl;
    //DrawTexturePro(texture, source_rect, destination_rect, origin, rotation, color);
    DrawTextureRec(texture, source_rect, Vector2{destination_rect.x, destination_rect.y}, color);
}

void Button::Clear()
{
    UnloadTexture(texture);
}