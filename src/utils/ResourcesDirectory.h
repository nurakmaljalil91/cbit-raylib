#ifndef RESOURCESDIRECTORY_H
#define RESOURCESDIRECTORY_H

#include <string>

// Class Resources Directory will be singleton
class ResourcesDirectoryBase
{
private:
    static ResourcesDirectoryBase *instance;
    ResourcesDirectoryBase();
    std::string path;
    std::string image_folder;
    std::string sprite_sheets_folder;
    std::string font_folder;
    std::string audio_folder;

public:
    virtual ~ResourcesDirectoryBase();

    static ResourcesDirectoryBase *Get_Instance()
    {
        if (!instance)
        {
            instance = new ResourcesDirectoryBase;
        }
        return instance;
    }

    inline const std::string &Get()
    {
        return path;
    }

    inline const std::string &Get_Image()
    {
        return image_folder;
    }

    inline const std::string &Get_SpriteSheet(){
        return sprite_sheets_folder;
    }
}; // class ResourcesDirectoryBase

#endif // RESOURCESDIRECTORY_H