#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include <string>

#include "raylib.h"
#include "Component.h"

class Button : public Component
{
public:
    // Texture or image members
    Texture2D texture;
    float width;
    float height;
    Rectangle source_rect;
    Rectangle destination_rect;
    Color color;
    Vector2 origin;
    float rotation;
    int number; // for testing
    Vector2 center;
    Vector2 mouse_position;

    // Button function members
    int state; // 0 - Normal 1 - Hover 2 - Pressed 
    bool action;
    
    Button(const char *file_location);
    Button(std::string file_location);
    virtual ~Button();

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;

}; // class Button

#endif // BUTTON_H