#include <iostream>
#include "Menu.hpp"
#include "../SceneManager.hpp"
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
    float scy = GetScreenHeight() / 2;
    float scx = GetScreenWidth() / 2;
    DrawText("Press SPACE to start.", scx - 110,scy - 10,20, BLACK);
}