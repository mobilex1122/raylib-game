#ifndef GLOBALS_H
#define GLOBALS_H
enum GameState {TITLE,GAMEPLAY};
namespace Global {
    //NOTE: Game Scene State. Might change to some kind of scene loader system.
    extern GameState state;

    // Might not need this?
    extern float delta;
}
#endif