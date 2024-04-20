#include <iostream>
#include "raylib.h"
#include "globals.h"
#include "Player.h"
#include "scenes/Menu.h"
#include "SceneManager.h"

SceneManager* SceneManager::instance = nullptr;

int main()
{
    InitWindow(800,450, "Game");

    SceneManager* sman = SceneManager::getInstance();
    
    sman->loadScene(new Menu());

    while (!WindowShouldClose())
    {
        // Might not needed? But not sure how raylib calculates it.
        Global::delta = GetFrameTime();
        Scene* scene = sman->getScene();
   
        if (IsKeyPressed(KEY_Q))
        {
            sman->loadScene(new Menu());
        }
        
        scene->update();
 
        BeginDrawing();
            ClearBackground(RAYWHITE);
            scene->draw();
            DrawText(scene->name, 7,7,20,GRAY);
            DrawText(scene->name, 5,5, 20, BLACK);

            DrawFPS(20,20);
        EndDrawing();
    }
    sman->getScene()->unload();

    CloseWindow();
    return 0;
}