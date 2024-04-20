#ifndef GLOBALS_H
#define GLOBALS_H
#include "Scene.h"
enum GameState {GAME_LOADING,GAME_SCENE};
namespace Global {
    //NOTE: Game Scene State. Might change to some kind of scene loader system.
    extern GameState state;

    extern Scene* scene;

    // Might not need this?
    extern float delta;
}
#endif