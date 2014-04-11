#pragma once

#include <windows.h>

#include "../../Resources/shaders.h"
#include "../ResourcesLoader/RcLoader.h"
#include "../../Libs/glew/glew.h"
#include "../../Libs/glm/gtx/transform.hpp"
#pragma comment ( lib, "opengl32.lib" )
#pragma comment ( lib, "E_Files/Libs/glew/glew32.lib" )

class IShader{
public:
	virtual void Load() = 0;
	virtual void PassAtrib(GLuint argument, GLuint data_pointer) = 0;
	virtual void PassUnif(GLuint argument, GLuint data_pointer) = 0;
	virtual void Draw(GLuint index, GLuint vertices) = 0;
	virtual void Use() = 0;

	IShader();
	virtual ~IShader();
};