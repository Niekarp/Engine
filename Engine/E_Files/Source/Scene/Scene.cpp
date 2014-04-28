#include "../../Headers/Scene/Scene.h"


Scene::Scene(GLFWwindow* window) : win(window){
}
Scene::~Scene(){
	models.clear();
}

bool Scene::ObjectAdd(
	std::string objectName,
	const char* ply_filepath,
	const char* texturepath,
	MODEL_TYPE modelType,
	glm::vec3 poz,
	glm::vec3 size)
{
	for (unsigned int i = 0; i < models.size(); i++){
		if (models.at(i).Name() == objectName)
			return false;
	}
	models.push_back(Model(objectName, ply_filepath, texturepath, modelType, poz, size));
	return true;
}
bool Scene::ObjectDelete(std::string objectName){
	for (unsigned int i = 0; i < models.size(); i++){
		if (models.at(i).Name() == objectName){
			models.erase(models.begin() + i);
			return true;
		}
	}
	return false;
}
void Scene::LightAdd(LightType lightType, glm::vec3 light){
	if (lightType == DIFFUSE) spotlight = light;
	else if (lightType == AMBIENT) ambientLight = light;
	else if (lightType == DIFFUSE_AND_AMBIENT){
		spotlight = light;
		ambientLight = light;
	}
	else
		throw "Porblem podczas modyfikacji oswietlenia sceny";
}
void Scene::LightDelete(LightType lightType){
	if (lightType == DIFFUSE) spotlight = glm::vec3(0, 0, 0);
	else if (lightType == AMBIENT) ambientLight = glm::vec3(0, 0, 0);
	else if (lightType == DIFFUSE_AND_AMBIENT){
		spotlight = glm::vec3(0, 0, 0);
		ambientLight = glm::vec3(0, 0, 0);
	}
	else
		throw "Problem podczas usuwania swiatla ze sceny";
}
void Scene::ComputeMatricesFromInputs(){
	static float c_angleX = 0;
	static float c_angleY = 0;
	static float c_FoV = 45.f;
	static glm::vec3 c_position = glm::vec3(0.5, 0.5, -0.5);
	const float speed = 3.f;
	const float c_mouseSpeed = 0.005f;

	static double lastTime = glfwGetTime();
	double currentTime = glfwGetTime();
	float deltaTime = float(currentTime - lastTime);

	double xpos, ypos;
	glfwGetCursorPos(win, &xpos, &ypos);
	glfwSetCursorPos(win, 1500 / 2, 800 / 2);

	c_angleX += c_mouseSpeed * float(1500 / 2 - xpos);
	c_angleY += c_mouseSpeed * float(800 / 2 - ypos);

	if (c_angleY > PI / 2 || c_angleY < -PI / 2){
		if (c_angleY > PI / 2) c_angleY = (PI / 2) - 0.001;
		else if (c_angleY < -PI / 2) c_angleY = (-PI / 2) + 0.001;
	}

	glm::vec3 direction(
		sin(c_angleX),
		sin(c_angleY),
		cos(c_angleX)
		);
	glm::vec3 right = glm::vec3(
		sin(c_angleX - 3.14f / 2.f),
		0,
		cos(c_angleX - 3.14f / 2.f)
		);
	glm::vec3 up = glm::cross(right, direction);

	if (glfwGetKey(win, GLFW_KEY_W) == GLFW_PRESS){
		c_position += direction * deltaTime * speed;
	}
	if (glfwGetKey(win, GLFW_KEY_S) == GLFW_PRESS){
		c_position -= direction * deltaTime * speed;
	}
	if (glfwGetKey(win, GLFW_KEY_D) == GLFW_PRESS){
		c_position += right * deltaTime * speed;
	}
	if (glfwGetKey(win, GLFW_KEY_A) == GLFW_PRESS){
		c_position -= right * deltaTime * speed;
	}


	float FoV = c_FoV;
	glm::mat4 c_ProjectMatrix = glm::perspective(FoV, 1500.f / 800.f, 0.1f, 100.f);
	glm::mat4 c_ViewMatrix = glm::lookAt(
		c_position,
		c_position + direction,
		up
		);

	lastTime = currentTime;

	//~~~~~
	vp = c_ProjectMatrix * c_ViewMatrix;
}

std::vector<Model>* Scene::Models(){
	return &models;
}
glm::vec3* Scene::Spotlight(){
	return &spotlight;
}
glm::vec3* Scene::AmbientLight(){
	return &ambientLight;
}
glm::mat4* Scene::VP(){
	return &vp;
}