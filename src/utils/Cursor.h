#ifndef CURSOR_H
#define CURSOR_H

#include <string>
#include "raylib.h"

class Cursor
{
private:
    Texture2D cursor_image;     // cursor image
    float width;                // width of the cursor
    float height;               // height of cursor
    Rectangle source_rect;      // source rectangle of the image from the spritesheet
    Rectangle destination_rect; // this is where the image should render
    Vector2 origin;             // this is the origin of image
    Vector2 anchor;             // center of the image
    Vector2 position;           // position of cursor
    Color color;                // color of the cursor
public:
    Cursor(const char *image_path); // Constructor : const* char
    Cursor(std::string image_path); // Constructor : string
    Cursor(std::string Image_path, float x, float y, float w, float h); // Constructor : x,y,w,h
    virtual ~Cursor(); // Deconstructor

    void Update(); // Update the cursor position
    void Render(); // Render the cursor image
    void Clear();  // Clear the cursor texture

    void Set_Image(std::string image); // set the image of the
};                                     // class Cursor

#endif // CURSOR_H