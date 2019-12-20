#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <string>

#include "raylib.h"
#include "Component.h"

class Button : public Component
{
private:
    bool can_hover; // Check if the button can hover

public:
    // Texture or image members
    Texture2D texture;            // texture2d image or spritesheet
    float width;                  // width of the texture
    float height;                 // height of the texture
    Rectangle normal_source_rect; // rectangle of original image or source image
    Rectangle hover_source_rect;  // Rectangle of hover image
    Rectangle click_source_rect;  // Rectangle of click image
    Rectangle bounds;             // same as destination rectangle in sprite renderer component
    Color color;                  // Color of the button
    Vector2 origin;               // origin of image // NOTE: not sure about this
    float rotation;               // rotate the image
    int number;                   // for testing
    Vector2 center;               // center or anchor of the image
    Vector2 mouse_position;       // the position of the mouses

    // Button function members
    int state;   // 0 - Normal 1 - Hover 2 - Pressed
    bool action; // check if the button is in action

    bool show_box; // show the rectangle or bounds of the image

    Button(const char *file_location);                                     // Constructor if the image is single image using const* char
    Button(std::string file_location);                                     // Constructor if the image is single image using string
    Button(std::string file_location, float x, float y, float w, float h); // Constructor if using strings
    virtual ~Button();                                                     // Deconstructor

    void Start() override;  // Start or initialization of the button
    void Update() override; // Update the button
    void Render() override; // Render button
    void Clear() override;  // Clear the button

    // mouse function
    bool Is_Action(); // return mouse action
    int State();      // return mouse state;
    bool State_Normal();
    bool State_Hover();
    bool State_Click();

    void Set_Normal_Image(std::string file_location, float x, float y, float w, float h);
    void Set_Hover_Image(std::string file_location, float x, float y, float w, float h);
    void Set_Click_Image(std::string file_location, float x, float y, float w, float h);

}; // class Button

#endif // BUTTON_H