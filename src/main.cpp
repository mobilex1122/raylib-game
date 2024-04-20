#include <iostream>
#include "raylib.h"
#include "globals.h"
#include "Player.h"
#include "scenes/Menu.h"
#include "SceneLoader.h"

int main()
{
    InitWindow(800,450, "Game");

    Player player {20,20};

    loadScene(new Menu());
    while (!WindowShouldClose())
    {
        // Might not needed? But not sure how raylib calculates it.
        Global::delta = GetFrameTime();
        switch (Global::state)
        {
        case GAME_SCENE:
            Global::scene->update();
            break;
        default:
            break;
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            switch (Global::state)
            {
            case GAME_LOADING:
                DrawText("LOADING...", 20,20,20, LIGHTGRAY);
                break;
            case GAME_SCENE:
                Global::scene->draw();
                break;
            default:
                DrawText("INCORRECT STATE", 20,20,20, RED);
                break;
            }
            DrawText(Global::scene->name, 20,41, 20, LIGHTGRAY);
        EndDrawing();
    }
    Global::scene->unload();

    CloseWindow();
    return 0;
}