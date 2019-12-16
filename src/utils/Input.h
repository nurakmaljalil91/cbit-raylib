#ifndef INPUT_H
#define INPUT_H

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
}; // InputBase class

#endif // INPUT_H