#ifndef ASSET_H
#define ASSET_H

#include <map>
#include <string>

#include "raylib.h"

class AssetBase
{
private:
    std::map<std::string, Texture2D *> textures;
    std::map<std::string, Font *> fonts;
    static AssetBase *instance;
    AssetBase();

public:
    virtual ~AssetBase();

    static AssetBase *Get_Instance()
    {
        if (!instance)
        {
            instance = new AssetBase;
        }
        return instance;
    }

    // Texture management
    void Add_Texture(std::string id, Texture2D* texture)
    {

        textures.emplace(id, texture);
    }

    Texture *Get_Texture(std::string id)
    {
        return textures.find(id)->second;
    }

    // Font management
    void Add_Font(std::string id, Font* font)
    {

        fonts.emplace(id, font);
    }

    Font *Get_Font(std::string id)
    {
        return fonts.find(id)->second;
    }

}; // class AssetBase

#endif // ASSET_H