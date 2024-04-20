#include <iostream>
#include "Player.h"
#include "globals.h"
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
    //DrawRectangle(pos.x,pos.y,20,20, RED)
    Vector2 textureCenter {(float)texture.height,(float)texture.width};
    textureCenter = Vector2Scale(textureCenter,2);
    textureCenter = Vector2Divide(textureCenter,{2,2});
    DrawTextureEx(texture,Vector2Subtract(pos,textureCenter),0,2,WHITE);
    DrawCircle(pos.x,pos.y, 3, RED);
};

void Player::unload() {
    UnloadTexture(texture);
}
