#include <iostream>
#include "Game.hpp"


GameScene::GameScene(): Scene("Game"), player(50,50) {
}
void GameScene::update()
{
    player.update();
}

void GameScene::draw()
{
    player.draw();
}

void GameScene::unload()
{
    player.unload();
}