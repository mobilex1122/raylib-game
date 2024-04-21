#include "AtlasManager.hpp"

AtlasManager* AtlasManager::getInstance() {
    if (!instance) {
        instance = new AtlasManager();
    }
    return instance;
}

void AtlasManager::draw(const char * texture, int frame, float x, float y) {
    if (textureExists(texture,frame)) {
        Rectangle rect = getTextureRect(texture,frame);
        DrawTextureRec(atlas,rect,(Vector2) {x,y},WHITE);
    } else {
       NoTexture(x,y);
    }
}

void AtlasManager::drawPro(const char * texture, int frame, float x, float y,float offsetX,float offsetY) {
    if (textureExists(texture,frame)) {
        Rectangle rect = getTextureRect(texture,frame);
        Rectangle rectDest {x,y,rect.width,rect.height};
        DrawTexturePro(atlas,rect,rectDest,(Vector2){rect.width*offsetX,rect.height*offsetY},0,WHITE);
    } else {
        NoTexture(x,y);
    }
}
void AtlasManager::NoTexture(float x,float y) {
    DrawRectangleLines(x-20,y-20,40,40,RED);
    DrawLine(x-20,y-20,x+20,y+20,RED);
    DrawLine(x+20,y-20,x-20,y+20,RED);
}

bool AtlasManager::textureExists(const char * texture,int frame) {
    std::string key = std::string(texture) + "-" + std::to_string(frame) ;
    return (data.find(key) != data.end());
}

Rectangle AtlasManager::getTextureRect(const char * texture,int frame) {
    std::string key = std::string(texture) + "-" + std::to_string(frame) ;
    if (textureExists(texture,frame)) {
        json sprite = data[key];
        json frame = sprite["frame"];
        float tx,ty,tw,th = 0;
        if (frame["x"].is_number() && frame["x"].is_number() && frame["x"].is_number() &&frame["x"].is_number()) {
            tx = (int)frame["x"];
            ty = (int)frame["y"];
            tw = (int)frame["w"];
            th = (int)frame["h"];
        }
        return (Rectangle){tx,ty,tw,tw};
    } else {
        return (Rectangle){0,0,0,0};
    }
}

void AtlasManager::loadAtlas(const char * atlasFile ,const char * dataFile)
{
    this->atlas = LoadTexture(atlasFile);
    json rawData = json::parse(LoadFileText(dataFile));
    if (rawData["frames"].is_object()) {
        this->data = rawData["frames"];
    }
}