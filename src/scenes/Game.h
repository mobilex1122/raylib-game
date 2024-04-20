#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "../Scene.h"
#include "raylib.h"
#include "../Player.h"

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