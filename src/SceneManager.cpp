#include "SceneManager.h"

SceneManager* SceneManager::getInstance()
{
    if (!instance) {
        instance = new SceneManager();
        instance->loadedScene = new Scene();
    }
    return instance;
}

void SceneManager::loadScene(Scene* scene) {
    loadedScene->unload();
    loadedScene = scene;
}

Scene* SceneManager::getScene() {
    return loadedScene;
}

SceneManager::SceneManager() {

}
SceneManager::~SceneManager()
{
}
