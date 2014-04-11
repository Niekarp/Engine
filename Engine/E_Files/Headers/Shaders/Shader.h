#pragma once

#include <windows.h>

#include "../../Resources/shaders.h"
#include "../../Libs/glew/glew.h"
#pragma comment ( lib, "opengl32.lib" )
#pragma comment ( lib, "E_Files/Libs/glew/glew32.lib" )

class Shader{
public:
	virtual void Load() = 0;
	virtual void PassAtrib(GLuint argument, GLuint data_pointer) = 0;
	virtual void PassUni(GLuint argument, GLuint data_pointer) = 0;
	virtual void Draw(GLuint vertices) = 0;
	virtual void Use() = 0;

	Shader();
	virtual ~Shader() = 0;
};