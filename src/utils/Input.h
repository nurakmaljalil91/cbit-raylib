#ifndef INPUT_H
#define INPUT_H

#include <string>
#include "raylib.h"

class InputBase
{
private:
    static InputBase *instance;
    InputBase();

public:
    virtual ~InputBase();

    static InputBase *Get_Instance()
    {
        if (!instance)
        {
            instance = new InputBase;
        }
        return instance;
    }

    float GetAxis(std::string input_axis);

}; // InputBase class

#endif // INPUT_H