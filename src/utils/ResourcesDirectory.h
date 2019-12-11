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

public:
    virtual ~ResourcesDirectoryBase();

    static ResourcesDirectoryBase *Get_Instance(){
        if(!instance){
            instance = new ResourcesDirectoryBase;
        }
        return instance;
    }

    inline const std::string &Get()
    {
        return path;
    }
}; // class ResourcesDirectoryBase

#endif // RESOURCESDIRECTORY_H