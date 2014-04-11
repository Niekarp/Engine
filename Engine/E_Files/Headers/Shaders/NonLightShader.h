#pragma once

#include "Shader.h"

class NonLightShader : public Shader{
public:
	void Load();
	void PassAtrib(GLuint argument, GLuint data_pointer);
	void PassUni(GLuint argument, GLuint data_pointer);
	void Draw(GLuint vertices);
	void Use();
	
	NonLightShader();
	~NonLightShader();
private:
	GLuint program;
};