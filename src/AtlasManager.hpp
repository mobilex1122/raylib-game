/*

    AtlMan 0.0.1 - Atlas Manager for RayLib

    Author: Jan Palma

    License: MIT


*/
#ifndef ATLASMANAGER_H
#define ATLASMANAGER_H
#include "raylib.h"
#include <json.hpp>
#include <iostream>
using json = nlohmann::json;
/*typedef struct AtlasTextureData {
    int x;
    int y;
    int w;
    int h;
};*/
class AtlasManager
{
public:
    static AtlasManager* getInstance();

    void loadAtlas(const char * atlasFile ,const char * dataFile);

    void draw(const char * texture, int frame, float x, float y);

    void drawPro(const char * texture, int frame, float x, float y,float offsetX,float offsetY);
    
    Rectangle getTextureRect(const char * texture,int frame);

    AtlasManager(const AtlasManager*) = delete;
    AtlasManager* operator=(const AtlasManager&) = delete;
private:
    bool textureExists(const char * texture,int frame);
    void NoTexture(float x,float y);
    static AtlasManager* instance;
    Texture2D atlas;
    json data;
    AtlasManager() {};
    ~AtlasManager() {};
};

#endif