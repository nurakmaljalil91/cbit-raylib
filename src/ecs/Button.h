#ifndef BUTTON_H
#define BUTTON_H

#include <iostream>
#include "raylib.h"
#include "Component.h"

class Button : public Component
{
public:
    
    Texture2D texture;
    float width;
    float height;
    Rectangle source_rect;
    Rectangle destination_rect;
    Color color;
    Vector2 origin;
    float rotation;
    int number;
    Vector2 center;
    Vector2 mouse_position;

    Button(const char *file_location);
    virtual ~Button();

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;

}; // class Button

#endif // BUTTON_H