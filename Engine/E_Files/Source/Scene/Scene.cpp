#include "../../Headers/Scene/Scene.h"

void Scene::AddObject(
	const char* link,
	glm::vec3 poz,
	glm::vec3 size,
	MODEL_TYPE modelType){
	model = new Model(link, poz, size, NON_LIGHTED);
}
Model* Scene::GetModel(){
	return model;
}

Scene::Scene(){
}
Scene::~Scene(){
	delete model;
}