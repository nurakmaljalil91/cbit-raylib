#include "ResourcesDirectory.h"

ResourcesDirectoryBase::ResourcesDirectoryBase()
{
    path = "../resources/";
    image_folder = "../resources/Images/";
    sprite_sheets_folder = "../resources/SpriteSheets/";
    font_folder = "../resources/Fonts/";
    audio_folder = "../resources/Audio/";
}

ResourcesDirectoryBase::~ResourcesDirectoryBase()
{
}