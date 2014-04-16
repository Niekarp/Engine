#pragma once

#include "../../Libs/glew/glew.h"
#include "../../Libs/glm/glm.hpp"
#include "../../Libs/glm/gtx/transform.hpp"


enum MODEL_TYPE{
	NON_LIGHTED,
	DIFFUSE_LIGHTED,
	AMBIENT_LIGHTED
};
class Model{
public:
	Model(const char* link,
		glm::vec3 poz,
		glm::vec3 size,
		MODEL_TYPE modelType);
	Model();
	~Model();

	void Load(const char* link);
	void Move(glm::vec3 position);
	void Size(glm::vec3 size);
	MODEL_TYPE Type();

	const GLfloat* Matrix();
	GLuint    Bos(GLuint index);
	GLuint    TriangleN();
	glm::vec3 Position();
	glm::vec3 Size();
private:
	MODEL_TYPE modelType;
	glm::mat4 modelMatrix;
	GLuint    bos[4];
	GLuint    triangleNumber;
	glm::vec3 position;
	glm::vec3 size;
};