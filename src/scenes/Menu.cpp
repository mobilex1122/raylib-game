#include <iostream>
#include "Menu.hpp"
#include "../SceneManager.hpp"
#include "../AtlasManager.hpp"
#include "Game.hpp"


Menu::Menu(): Scene("Menu") {
}

void Menu::update()
{
    if (IsKeyPressed(KEY_SPACE)) {
        SceneManager* sman = SceneManager::getInstance();
        sman->loadScene(new GameScene());
    };
}

void Menu::draw() {
    GetMousePosition();
    float scy = GetScreenHeight() / 2;
    float scx = GetScreenWidth() / 2;
    int btnState = 0;
    if (CheckCollisionPointRec(GetMousePosition(),(Rectangle){scx-44,scy-27,94,53})) {
        btnState = 1;
        if (IsMouseButtonDown(MOUSE_BUTTON_LEFT)) {
            btnState = 2;
        }
        if (IsMouseButtonReleased(MOUSE_BUTTON_LEFT)) {
            SceneManager* sman = SceneManager::getInstance();
            sman->loadScene(new GameScene());       
        }
    }
    AtlasManager* atlman = AtlasManager::getInstance();
    atlman->drawN("button",btnState,scx-44,scy-27,94,53,16,16,16,16,NPATCH_NINE_PATCH);
    DrawText("Start", scx - 25,scy - 10,20, BLACK);
}