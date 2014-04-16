#pragma once

#include "../Model/Model.h"

class Scene{
public:
	void AddObject(
		const char* link,
		glm::vec3 poz,
		glm::vec3 size,
		MODEL_TYPE modelType);
	Model* GetModel();

	Scene();
	~Scene();
private:
	Model* model;
};