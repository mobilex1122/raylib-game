#include <iostream>
#include "raylib.h"
#include "Player.h"

int main()
{
    InitWindow(800,450, "Game");

    Player player {20,20};

    while (!WindowShouldClose())
    { 
        player.update();
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawText("HELLO", 20,20,20, LIGHTGRAY);
            player.draw();
        EndDrawing();
    }
    
    CloseWindow();
    return 0;
}