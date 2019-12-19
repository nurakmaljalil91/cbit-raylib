#ifndef CURSOR_H
#define CURSOR_H

#include <string>
#include "raylib.h"

class Cursor
{
private:
    Texture2D cursor_image; // cursor image
    Vector2 position;     // position of cursor
    Color color;
public:
    Cursor(std::string image_path);          // Constructor
    virtual ~Cursor(); // Deconstructor

    void Update(); // Update the cursor position
    void Render(); // Render the cursor image
    void Clear();  // Clear the cursor texture

    void Set_Image(std::string image); // set the image of the 
}; // class Cursor

#endif // CURSOR_H