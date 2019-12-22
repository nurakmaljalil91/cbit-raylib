#include "Text.h"

Text::Text(std::string font_location)
{
    font = LoadFont(font_location.c_str());
    text = "Write here";
    size = 1;
    spacing = 0.5;
    color = BLACK;
}

Text::Text(Font _font)
{
    font = _font;
    text = "Write here";
    size = 1;
    spacing = 0.5;
    color = BLACK;
}

Text::~Text() {}

void Text::Start() {}
void Text::Update() {}
void Text::Render()
{
    DrawTextEx(font, text, {position.x, position.y}, font.baseSize * size, spacing, color);
}
void Text::Clear()
{
    UnloadFont(font);
}