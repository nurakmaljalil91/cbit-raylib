#ifndef ASSET_H
#define ASSET_H

#include <map>
#include <string>

#include "raylib.h"

class AssetBase
{
private:
    std::map<std::string, Texture2D> textures; // list of textures
    std::map<std::string, Font> fonts;         // list of fonts
    std::map<std::string, Sound> audio;        // list of audio
    static AssetBase *instance;                // instance of Asset
    AssetBase();                               // Construcor private because of singleton

public:
    virtual ~AssetBase(); // Deconstructor

    static AssetBase *Get_Instance() // Get the instance of the Asset
    {
        if (!instance)
        {
            instance = new AssetBase;
        }
        return instance;
    }

    // Texture management
    void Add_Texture(std::string id, Texture2D texture)
    {
        textures.emplace(id, texture); // add new texture
    }

    Texture Get_Texture(std::string id)
    {
        return textures.find(id)->second; // get texture
    }

    // Font management
    void Add_Font(std::string id, Font font)
    {
        fonts.emplace(id, font); // add new font
    }

    Font Get_Font(std::string id)
    {
        return fonts.find(id)->second; // get font
    }

    // Audio management
    void Add_Audio(std::string id, Sound _audio)
    {
        audio.emplace(id, _audio);
    }

    Sound Get_Audio(std::string id)
    {
        return audio.find(id)->second;
    }

}; // class AssetBase

#endif // ASSET_H