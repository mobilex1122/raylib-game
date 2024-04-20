#include "raylib.h"
#include "raymath.h"
#ifndef PLAYER_H
#define PLAYER_H
class Player
{
public:
    Player(float x, float y);
    void update();
    void draw();
    void unload();
private:
    Vector2 pos;
    Texture2D texture;
};

#endif
