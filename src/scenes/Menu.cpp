#include <iostream>
#include "Menu.h"
#include "../SceneManager.h"
#include "Game.h"


Menu::Menu(): Scene("Menu") {
}

void Menu::update()
{
    if (IsKeyPressed(KEY_SPACE)) {
        SceneManager* sman = SceneManager::getInstance();
        sman->loadScene(new GameScene());
    };
}