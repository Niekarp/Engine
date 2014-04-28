#pragma once

#include <vector>
#include "../Model/Model.h"
#include "../../Libs/glfw/glfw3.h"

#define PI 3,14
enum LightType {DIFFUSE, AMBIENT, DIFFUSE_AND_AMBIENT};
class Scene{
public:
	Scene(GLFWwindow* window);
	~Scene();
	
	bool ObjectAdd(
		std::string objectName,
		const char* ply_filepath,
		const char* texturepath,
		MODEL_TYPE modelType,
		glm::vec3 poz,
		glm::vec3 size);
	bool ObjectDelete(std::string objectName);
	void LightAdd(LightType lightType, glm::vec3 light);
	void LightDelete(LightType lightType);
	void ComputeMatricesFromInputs();

	std::vector<Model>* Models();
	glm::vec3* Spotlight();
	glm::vec3* AmbientLight();
	glm::mat4* VP();
private:
	GLFWwindow* win;
	
	std::vector<Model> models;
	glm::vec3 spotlight;
	glm::vec3 ambientLight;

	glm::mat4 vp;
};