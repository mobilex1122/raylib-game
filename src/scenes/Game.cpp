#include <iostream>
#include "Game.h"


GameScene::GameScene(): Scene(), player(50,50) {
    name = "Game";
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