#include "SceneLoader.h"

void loadScene(Scene* scene)
{
    Global::state = GAME_LOADING;
    Global::scene->unload();
    Global::scene = scene;
    Global::scene->create();
    Global::state = GAME_SCENE;
}