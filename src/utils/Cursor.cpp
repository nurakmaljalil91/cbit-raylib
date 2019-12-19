#include "Cursor.h"

Cursor::Cursor(std::string image_path) 
{
    cursor_image = LoadTexture(image_path.c_str());
    position = {0,0};
    color = WHITE;

}

Cursor::~Cursor() {}

void Cursor::Update()
{
    // Update position of the cursor based on the mouse position
    position = GetMousePosition();
}

void Cursor::Render()
{
    DrawTexture(cursor_image, position.x, position.y, color);
}

void Cursor::Clear()
{
    UnloadTexture(cursor_image);
}

void Cursor::Set_Image(std::string image)
{
    cursor_image = LoadTexture(image.c_str());
}