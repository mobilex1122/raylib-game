#include <iostream>
#include "raylib.h"
#include "globals.h"
#include "Player.h"


int main()
{
    InitWindow(800,450, "Game");

    Player player {20,20};

    while (!WindowShouldClose())
    {
        // Might not needed? But not sure how raylib calculates it.
        Global::delta = GetFrameTime();
        switch (Global::state)
        {
        case TITLE:
            if (IsKeyPressed(KEY_SPACE)) {
                Global::state = GAMEPLAY;
            }
            break;
        case GAMEPLAY:
            player.update();
            break;
        default:
            break;
        }
        BeginDrawing();
            ClearBackground(RAYWHITE);
            switch (Global::state)
            {
            case TITLE:
                DrawText("Press SPACE", 20,20,20, LIGHTGRAY);
                break;
            case GAMEPLAY:
                player.draw();
                break;
            default:
                DrawText("INCORRECT STATE", 20,20,20, RED);
                break;
            }
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}