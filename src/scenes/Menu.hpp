#ifndef MENU_SCENE_H
#define MENU_SCENE_H
#include "../Scene.hpp"
#include "raylib.h"

class Menu : public Scene
{
    public:
        Menu();
        void update();
        void draw();
};

#endif