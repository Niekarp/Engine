#pragma once

#include "IShader.h"

class NonLightShader : public IShader{
public:
	void Load();
	void PassAtrib(GLuint argument, GLuint bufferID);
	void PassUnif(GLuint argument, const GLfloat* data_pointer);
	void Draw(GLuint index, GLuint vertices);
	void Use();
	
	NonLightShader();
	~NonLightShader();
private:
	GLuint program;
};