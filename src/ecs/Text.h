#ifndef TEXT_H
#define TEXT_H

#include <string>
#include "raylib.h"
#include "Component.h"

class Text : public Component
{
public:
    Font font;
    const char *text;
    int size;
    int spacing;
    Color color;
    
    Text(std::string font_location);
    ~Text();

    void Start() override;
    void Update() override;
    void Render() override;
    void Clear() override;
}; // class Text

#endif // TEXT_H