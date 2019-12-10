#ifndef RESOURCESDIRECTORY_H
#define RESOURCESDIRECTORY_H

#include <string>

class ResourcesDirectory
{
private:
   std::string path;

public:
    ResourcesDirectory();

    inline const std::string& Get()
    {
        return path;
    }
}; // class ResourcesDirectory

#endif // RESOURCESDIRECTORY_H