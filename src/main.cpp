#include <iostream>
#include "raylib.h"
#include "AtlasManager.hpp"
#include "SceneManager.hpp"
#include "globals.hpp"
#include "Player.hpp"
#include "scenes/Menu.hpp"
#define RAYGUI_IMPLEMENTATION
#include "raygui.h"
#undef RAYGUI_IMPLEMENTATION
#define GUI_DEBUG_IMPLEMENTATION
#include "gui_Debug.hpp"
SceneManager* SceneManager::instance = nullptr;
AtlasManager* AtlasManager::instance = nullptr;

int main()
{
    InitWindow(800,450, "Game");

    SceneManager* sman = SceneManager::getInstance();

    sman->loadScene(new Menu());

    SetTargetFPS(60);

    bool showDebug = false;
    GuiDebugState debugState = InitGuiDebug();

    AtlasManager* atlman = AtlasManager::getInstance();

    atlman->loadAtlas("res/atlas.png","res/atlas.json");

    while (!WindowShouldClose())
    {
        // Might not needed? But not sure how raylib calculates it.
        Global::delta = GetFrameTime();
        Scene* scene = sman->getScene();
   
        if (IsKeyPressed(KEY_Q))
        {
            sman->loadScene(new Menu());
        }

        if (IsKeyPressed(KEY_F1)) {
            showDebug = !showDebug;
        }
        
        if (showDebug) {
            strcpy(debugState.FpsText, std::to_string(GetFPS()).c_str());
            strcpy(debugState.Scene_NameText, scene->name);
        }

        scene->update();
 
        BeginDrawing();
            ClearBackground(RAYWHITE);
            scene->draw();
            
            // Debug view
            if (showDebug) {
                GuiDebug(&debugState);
            }
        EndDrawing();
    }
    sman->getScene()->unload();

    CloseWindow();
    return 0;
}