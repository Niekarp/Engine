#pragma once

#include <windows.h>

#include "../../Libs/glew/glew.h"
#include "../../Libs/glm/gtx/transform.hpp"
#include "../../Resources/shaders.h"
#include "../ResourcesLoader/RcLoader.h"

class IShader{
public:
	virtual void Load() = 0;
	virtual void PassAtrib(GLuint argument, GLuint bufferID) = 0;
	virtual void PassUnif(GLuint argument, const GLfloat* data_pointer) = 0;
	virtual void Draw(GLuint index, GLuint vertices) = 0;
	virtual void Use() = 0;

	virtual ~IShader();
};