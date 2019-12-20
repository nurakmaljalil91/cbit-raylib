#include "Cursor.h"

Cursor::Cursor(const char *image_path)
{
    cursor_image = LoadTexture(image_path); // here we load the image texture
    width = cursor_image.width;             // width and height is the width & height from the original image
    height = cursor_image.height;
    position = {0, 0};                                                                   // initial position
    source_rect = {position.x, position.y, width, height};                               // as not spritesheet original image is the same size as image
    destination_rect = {position.x - width / 2, position.y - height / 2, width, height}; // destination rectangle where should draw
    origin = {width, height};
    anchor = {(width - position.x) / 2, (height - position.y) / 2}; // make the anchor at the center of the image
    color = WHITE;                                                  // color is white
}

Cursor::Cursor(std::string image_path)
{
    cursor_image = LoadTexture(image_path.c_str()); // here we load the image texture
    width = cursor_image.width;                     // width and height is the width & height from the original image
    height = cursor_image.height;
    position = {0, 0};                                                                   // initial position
    source_rect = {position.x, position.y, width, height};                               // as not spritesheet original image is the same size as image
    destination_rect = {position.x - width / 2, position.y - height / 2, width, height}; // destination rectangle where should draw
    origin = {width, height};
    anchor = {(width - position.x) / 2, (height - position.y) / 2}; // make the anchor at the center of the image
    color = WHITE;                                                  // color is white
}

Cursor::Cursor(std::string image_path, float x, float y, float w, float h)
{
    cursor_image = LoadTexture(image_path.c_str());                                      // here we load the image texture
    width = w;                                                                           // width and height is the width & height from the original image
    height = h;                                                                          // height follow spritesheet
    position = {0, 0};                                                                   // initial position
    source_rect = {x, y, width, height};                                                 // as not spritesheet original image is the same size as image
    destination_rect = {position.x - width / 2, position.y - height / 2, width, height}; // destination rectangle where should draw
    origin = {width, height};                                                            // origin of image
    anchor = {(width - position.x) / 2, (height - position.y) / 2};                      // make the anchor at the center of the image
    color = BLACK;                                                                       // color is white
}

Cursor::~Cursor() {}

void Cursor::Update()
{
    position = GetMousePosition();                                                       // Update position of the cursor based on the mouse position
    destination_rect = {position.x - width / 2, position.y - height / 2, width, height}; // Update destination rectangle where should draw
    anchor = {(width - position.x) / 2, (height - position.y) / 2};                      // Update the anchor at the center of the image
}

void Cursor::Render()
{
    DrawTextureRec(cursor_image, source_rect, Vector2{destination_rect.x, destination_rect.y}, color); // Draw the part of the original rectangle (using spritesheet)
}

void Cursor::Clear()
{
    UnloadTexture(cursor_image); // Unload the texture2d
}

void Cursor::Set_Image(std::string image)
{
    cursor_image = LoadTexture(image.c_str()); // Set the image of cursor
}