#ifndef SCENE_H
#define SCENE_H
enum SceneState {SCENE_LOADING,SCENE_RUNNING,SCENE_UNLOADING,SCENE_UNLOADED};

class Scene
{
public:
    Scene();
    Scene(const char * name);
    const char * name;
    virtual void create();
    virtual void update();
    virtual void draw();
    virtual void unload();
};

#endif
