#include <iostream>
#include "Game.h"


GameScene::GameScene(): Scene() {
    name = "Game";
}

void GameScene::create()
{
    std::cout << "Created GAME SCENE\n";
}

void GameScene::update()
{
    
}