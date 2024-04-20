#ifndef GAME_SCENE_H
#define GAME_SCENE_H
#include "../Scene.h"
#include "raylib.h"

class GameScene : public Scene
{
    public:
        GameScene();
        void create();
        void update();
};

#endif