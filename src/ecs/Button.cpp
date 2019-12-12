#include "Button.h"

Button::Button(const char *file_location) : state(0), action(false), show_box(false)
{
    texture = LoadTexture(file_location);
    width = texture.width;
    height = texture.height;

    source_rect = {0.0f, 0.0f, width, height};

    bounds = {position.x - width / 2, position.y - height / 2, width, height};

    origin = {width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2};
    rotation = 0;
    color = WHITE;
}

Button::Button(std::string file_location) : state(0), action(false), show_box(false)
{
    texture = LoadTexture(file_location.c_str());
    width = texture.width;
    height = texture.height;

    source_rect = {0.0f, 0.0f, width, height};

    bounds = {position.x - width / 2, position.y - height / 2, width, height};

    origin = {width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2};
    rotation = 0;
    color = WHITE;
}

Button::Button(std::string file_location, float x, float y,float w, float h) : state(0), action(false), show_box(false)
{
    texture = LoadTexture(file_location.c_str());
    width = w;
    height = h;

    source_rect = {x, y, width, height};

    bounds = {position.x - width / 2, position.y - height / 2, width, height};

    origin = {width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2};
    rotation = 0;
    color = WHITE;
}

Button::~Button() {}

void Button::Start() {}

void Button::Update()
{
    mouse_position = GetMousePosition();
    // std::cout << "x: " << mouse_position.x;
    // std::cout << ",y: " << mouse_position.y << std::endl;
    action = false;
    if (CheckCollisionPointRec(mouse_position, bounds))
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            state = 2;
        }
        else
        {
            state = 1;
        }
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            action = true;
        }
    }
    else
    {
        state = 0;
    }
}

void Button::Render()
{

    bounds = {position.x - width / 2, position.y - height / 2, width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2};
    // std::cout << center.x << "," << center.y << std::endl;
    //DrawTexturePro(texture, source_rect, destination_rect, origin, rotation, color);
    if (show_box)
    {
        DrawRectangleLines(bounds.x, bounds.y, width, height, BLACK);
        DrawRectangleLines(position.x, position.y, width, height, RED);
        DrawRectangleLines(source_rect.x, source_rect.y, source_rect.width, source_rect.height, GREEN);
    }

    DrawTextureRec(texture, source_rect, Vector2{bounds.x, bounds.y}, color);
}

void Button::Clear()
{
    UnloadTexture(texture);
}