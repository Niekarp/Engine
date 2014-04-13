#pragma once

#include "IShader.h"

class LightShader : public IShader{
public:
	void Load();
	void PassAtrib(GLuint argument, GLuint data_pointer);
	void PassUnif(GLuint argument, const GLfloat* data_pointer);
	void Draw(GLuint index, GLuint vertices);
	void Use();

	LightShader();
	~LightShader();
private:
	GLuint program;
};