#pragma once

#include <vector>

#include "../Model/Model.h"

enum LightType {DIFFUSE, AMBIENT, DIFFUSE_AND_AMBIENT};
class Scene{
public:
	void ObjectAdd(
		std::string objectName,
		const char* ply_filepath,
		const char* texturepath,
		MODEL_TYPE modelType,
		glm::vec3 poz,
		glm::vec3 size);
	void ObjectDelete(std::string objectName);
	void LightAdd(LightType lightType, glm::vec3 light);
	void LightDelete(LightType lightType);

	Scene();
	~Scene();
private:
	std::vector<Model> models;
	glm::vec3 spotlight;
	glm::vec3 ambientLight;
};