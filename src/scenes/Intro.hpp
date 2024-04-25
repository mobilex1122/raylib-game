#ifndef INTROSCENE_H
#define INTROSCENE_H
#include "../Scene.hpp"
#include "../AtlasManager.hpp"
class Intro: public Scene
{
private:
    AtlasManager* atlman;
    float introFrame = -20;
    float timeOut = 40;
public:
    Intro(/* args */);
    void update();
    void draw();
};

#endif