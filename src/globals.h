#ifndef GLOBALS_H
#define GLOBALS_H
enum GameState {TITLE,GAMEPLAY};
namespace Global {

    extern GameState state;

    extern float delta;
}
#endif