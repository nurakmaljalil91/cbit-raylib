#include "Button.h"

Button::Button(const char *file_location) : state(0), action(false), show_box(false)
{
    can_hover = false;                    // mean that hover texture is set
    texture = LoadTexture(file_location); // load the texture
    width = texture.width;                // texture width follow original width
    height = texture.height;              // component height follow texture height

    normal_source_rect = {0.0f, 0.0f, width, height}; // set the normal source rect

    bounds = {position.x - width / 2, position.y - height / 2, width, height}; // bounds of the button

    origin = {width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2}; // center or anchor of the texture
    rotation = 0;
    color = WHITE; // set color as white
}

Button::Button(std::string file_location) : state(0), action(false), show_box(false)
{
    can_hover = false;                            // mean that hover texture is set
    texture = LoadTexture(file_location.c_str()); // load the texture
    width = texture.width;                        // texture width follow original width
    height = texture.height;                      // component height follow texture height

    normal_source_rect = {0.0f, 0.0f, width, height}; // set the normal source rect

    bounds = {position.x - width / 2, position.y - height / 2, width, height}; // bounds of the button

    origin = {width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2}; // center or anchor of the texture
    rotation = 0;
    color = WHITE; // set color as white
}

Button::Button(Texture2D _texture) : state(0), action(false), show_box(false)
{
    can_hover = false;       // mean that hover texture is set
    texture = _texture;      // set texture
    width = texture.width;   // texture width follow original width
    height = texture.height; // component height follow texture height

    normal_source_rect = {0.0f, 0.0f, width, height}; // set the normal source rect

    bounds = {position.x - width / 2, position.y - height / 2, width, height}; // bounds of the button

    origin = {width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2}; // center or anchor of the texture
    rotation = 0;
    color = WHITE; // set color as white
}

Button::Button(std::string file_location, float x, float y, float w, float h) : state(0), action(false), show_box(false)
{
    can_hover = false;                            // mean that hover texture is set
    texture = LoadTexture(file_location.c_str()); // load the texture
    width = w;                                    // texture width follow set width
    height = h;                                   // component height follow texture height

    normal_source_rect = {x, y, width, height}; // set the normal source rect

    bounds = {position.x - width / 2, position.y - height / 2, width, height}; // bounds of the button

    origin = {width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2}; // center or anchor of the texture
    rotation = 0;
    color = WHITE; // set color as white
}

Button::Button(Texture2D _texture, float x, float y, float w, float h) : state(0), action(false), show_box(false)
{
    can_hover = false;  // mean that hover texture is set
    texture = _texture; // set texture
    width = w;          // texture width follow set width
    height = h;         // component height follow texture height

    normal_source_rect = {x, y, width, height}; // set the normal source rect

    bounds = {position.x - width / 2, position.y - height / 2, width, height}; // bounds of the button

    origin = {width, height};
    center = {(width - position.x) / 2, (height - position.y) / 2}; // center or anchor of the texture
    rotation = 0;
    color = WHITE; // set color as white
}

Button::~Button() {}

void Button::Start() {}

void Button::Update()
{
    mouse_position = GetMousePosition(); // mouse position using raylib mouse position
    action = false;
    if (CheckCollisionPointRec(mouse_position, bounds))
    {
        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))
        {
            state = 2; // Clicked
        }
        else
        {
            state = 1; // Hover
        }
        if (IsMouseButtonReleased(MOUSE_LEFT_BUTTON))
        {
            action = true;
        }
    }
    else
    {
        state = 0; // Normal
    }

    // State_Normal();
    // State_Hover();
    // std::cout << state << std::endl;
}

void Button::Render()
{

    bounds = {position.x - width / 2, position.y - height / 2, width, height}; // always update bounds of button
    center = {(width - position.x) / 2, (height - position.y) / 2};            // always update center or anchor of the texture

    if (show_box) // show the rectangle
    {
        DrawRectangleLines(bounds.x, bounds.y, width, height, BLACK);
        DrawRectangleLines(position.x, position.y, width, height, RED);
        DrawRectangleLines(normal_source_rect.x, normal_source_rect.y, normal_source_rect.width, normal_source_rect.height, GREEN);
    }

    if (can_hover && state == 1) // hover state
    {
        DrawTextureRec(texture, hover_source_rect, Vector2{bounds.x, bounds.y}, color); // draw the hover texture
    }
    else // normal state
    {
        DrawTextureRec(texture, normal_source_rect, Vector2{bounds.x, bounds.y}, color); // draw normal texture
    }
}

void Button::Clear()
{
    UnloadTexture(texture); // unload the texture2d
}

bool Button::Is_Action()
{
    return action;
}

int Button::State()
{
    return state;
}

bool Button::State_Normal()
{

    if (state == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Button::State_Hover()
{

    if (state == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool Button::State_Click()
{
    //bool _state = false;
    if (state == 2)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Button::Set_Normal_Image(std::string file_location, float x, float y, float w, float h)
{
    normal_source_rect = {x, y, w, h};
}

void Button::Set_Hover_Image(std::string file_location, float x, float y, float w, float h)
{
    hover_source_rect = {x, y, w, h};
    can_hover = true;
}

void Button::Set_Click_Image(std::string file_location, float x, float y, float w, float h)
{
    click_source_rect = {x, y, w, h};
}
