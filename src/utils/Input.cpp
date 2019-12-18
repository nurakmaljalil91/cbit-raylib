#include "Input.h"

InputBase::InputBase() {}

InputBase::~InputBase() {}

float InputBase::GetAxis(std::string input_axis)
{
    float axis;
    if (input_axis == "Horizontal")
    {
        if (IsKeyDown(KEY_D))
        {
            axis = 1;
        }
        if (IsKeyDown(KEY_A))
        {
            axis = -1;
        }
    }
    if (input_axis == "Vertical")
    {
        if (IsKeyDown(KEY_W))
        {
            axis = 1;
        }
        if (IsKeyDown(KEY_S))
        {
            axis = -1;
        }
    }
    else
    {
        axis = 0;
    }

    return axis;
}
