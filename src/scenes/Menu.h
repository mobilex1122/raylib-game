#ifndef MENU_SCENE_H
#define MENU_SCENE_H
#include "../Scene.h"
#include "raylib.h"

class Menu : public Scene
{
    public:
        Menu();
        void create();
        void update();
};

#endif