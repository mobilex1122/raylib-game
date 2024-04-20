#include <iostream>
#include "Menu.h"
#include "Game.h"


Menu::Menu(): Scene() {
    name = "Menu";
}

void Menu::create()
{
    std::cout << "Created Menu\n";
}

void Menu::update()
{
    if (IsKeyPressed(KEY_SPACE)) {
        loadScene(new GameScene());
    };
}