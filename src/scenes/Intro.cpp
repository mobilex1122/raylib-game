#include "Intro.hpp"
#include "../SceneManager.hpp"
#include "Menu.hpp"
#include <iostream>
#include "minmax.h"

Intro::Intro():Scene("Intro") {
    atlman = AtlasManager::getInstance();
}

void Intro::update() {
    if (introFrame < 8) {
        introFrame += 20 * GetFrameTime();
    } else {
        timeOut -= 15 * GetFrameTime();
        if (timeOut < 0) {
            SceneManager* sman = SceneManager::getInstance();
            sman->loadScene(new Menu());
        }
    }
}

void Intro::draw() {
    float h = GetScreenHeight();
    float w = GetScreenWidth();
    atlman->drawPro("logo",max(floor(introFrame),0),w/2,h/2,0.5,0.5);
}