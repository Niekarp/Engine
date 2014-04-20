#include "../../Headers/Scene/Scene.h"

void Scene::ObjectAdd(
	std::string objectName,
	const char* ply_filepath,
	const char* texturepath,
	MODEL_TYPE modelType,
	glm::vec3 poz,
	glm::vec3 size)
{
	models.push_back(Model(objectName, ply_filepath, texturepath, modelType, poz, size));
}
void Scene::ObjectDelete(std::string objectName){

}

Scene::Scene(){
}
Scene::~Scene(){
	models.clear();
}