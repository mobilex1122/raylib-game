#include <iostream>
#include "Menu.h"


Menu::Menu(): Scene() {
    name = "Menu";
}

void Menu::create()
{
    std::cout << "Created Menu";
}

void Menu::update()
{
    if (IsKeyPressed(KEY_SPACE)) {
        std::cout << "Test \n";
    };
}