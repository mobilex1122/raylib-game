#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "../Scene.hpp"
#include "raylib.h"
#include "../Player.hpp"

class GameScene : public Scene
{
    public:
        GameScene();
        void update();
        void draw();
        void unload();

    private:
        Player player;
};

#endif