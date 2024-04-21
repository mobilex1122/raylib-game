#include <iostream>
#include "Player.hpp"
#include "globals.hpp"
#include "AtlasManager.hpp"
Player::Player(float x, float y): pos({x, y}) {
    texture = LoadTexture("res/box.png");
};
void Player::update() {
    float delta = Global::delta;

    //NOTE: Change to one SPEED variable
    if (IsKeyDown(KEY_LEFT)) {
        pos.x -= 100 * delta;
    } else if (IsKeyDown(KEY_RIGHT)) {
        pos.x += 100 * delta;
    }

    if (IsKeyDown(KEY_UP)) {
        pos.y -= 100 * delta;
    } else if (IsKeyDown(KEY_DOWN)) {
        pos.y += 100 * delta;
    }
}
void Player::draw() {
    frame += 0.2;
    if (frame >= 6) {
        frame = 0;
    }
    AtlasManager* atlm = AtlasManager::getInstance();
    atlm->drawPro("diamond",floor(frame),pos.x,pos.y,0.5,0.5);
    DrawCircle(pos.x,pos.y, 3, RED);
};

void Player::unload() {
    UnloadTexture(texture);
}
