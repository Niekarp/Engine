#pragma once

#include <stdio.h>
#include <vector>

#include "../../Libs/glew/glew.h"
#include "../../Libs/glm/glm.hpp"
#include "../../Libs/glm/gtx/transform.hpp"
#include "../../Libs/glfw/glfw3.h"


enum MODEL_TYPE{
	NON_LIGHTED,
	DIFFUSE_AND_AMBIENT_LIGHTED,
	DIFFUSE_LIGHTED,
	AMBIENT_LIGHTED
};
class Model{
public:
	Model(std::string modelName,
		const char* file_ply,
		const char* texturePath,
		MODEL_TYPE type,
		glm::vec3 poz,
		glm::vec3 size);
	Model();
	~Model();

	void LoadPLY(const char* ply);
	void LoadTexture(const char* imagepath);
	void Move(glm::vec3 position);
	void Size(glm::vec3 size);

	std::string    Name();
	MODEL_TYPE     Type();
	const GLfloat* Matrix();
	GLuint    Bos(GLuint index);
	GLuint    Texture();
	GLuint    TriangleN();
	glm::vec3 Position();
	glm::vec3 Size();
private:
	std::string name;

	MODEL_TYPE modelType;
	glm::mat4  modelMatrix;
	GLuint     textureID;
	GLuint     bos[4];
	GLuint     triangleNumber;

	glm::vec3 position;
	glm::vec3 size;
};