#include "Scene.hpp"
#include <iostream>
Scene::Scene()
{
  name = "Untitled";
}
Scene::Scene(const char * name) {
  this->name = name;
}

//NOTE: Left create,draw,update,unload blank for now

void Scene::create()
{
  std::cout << "created Scene\n";
}

void Scene::draw() 
{
    
}

void Scene::update()
{
}

void Scene::unload()
{

}

