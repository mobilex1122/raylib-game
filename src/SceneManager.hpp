#ifndef SCENEMANAGER_H
#define SCENEMANAGER_H
#include "Scene.hpp"
class SceneManager
{
public:
    static SceneManager* getInstance();

    void loadScene(Scene* scene);

    Scene* getScene();

    SceneManager(const SceneManager&) = delete;
    SceneManager* operator=(const SceneManager&) = delete;
private:
    SceneManager();
    ~SceneManager();
    Scene* loadedScene;

    static SceneManager* instance;
};
#endif
