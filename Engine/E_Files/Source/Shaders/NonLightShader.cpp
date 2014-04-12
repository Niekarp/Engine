#include "../../Headers/Shaders/NonLightShader.h"

void NonLightShader::Load(){
	Data vertex_shader   = RcLoad(RE_NON_LIGHT_VERTEX_SHADER);
	Data fragment_shader = RcLoad(RE_NON_LIGHT_FRAGMENT_SHADER);
	GLuint ivs = glCreateShader(GL_VERTEX_SHADER);
	GLuint ifs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(ivs, 1, (const char**)vertex_shader.res, 0);
	glShaderSource(ifs, 1, (const char**)fragment_shader.res, 0);

	glAttachShader(program, ivs);
	glAttachShader(program, ifs);
	glLinkProgram(program);
}
void NonLightShader::PassAtrib(GLuint argument, GLuint data_pointer){
	switch (argument){
	case 0:
		glBindBuffer(GL_ARRAY_BUFFER, data_pointer);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		break;
	case 1:
		glBindBuffer(GL_ARRAY_BUFFER, data_pointer);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		break;
	case 2:
		glBindBuffer(GL_ARRAY_BUFFER, data_pointer);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
		break;
	default:
		throw "Blad podczas przekazywania atrybutu do NonLightShader'a";
	};
}
void NonLightShader::PassUnif(GLuint argument, GLuint data_pointer){
	switch (argument){
	case 0:
		glUniformMatrix4fv(0, 1, GL_FALSE, (const GLfloat*)data_pointer);
		break;
	case 1:
		glUniform3fv(1, 1, (const GLfloat*)data_pointer);
		break;
	default:
		throw "Blad podczas przekazywania uniformu do NonLightShader'a";
	};
}
void NonLightShader::Draw(GLuint index, GLuint vertices){
	glBindBuffer(GL_ARRAY_BUFFER, index);
	glDrawElements(GL_TRIANGLES, vertices, GL_UNSIGNED_INT, 0);
}
void NonLightShader::Use(){
	glUseProgram(program);
}

NonLightShader::NonLightShader(){
}
NonLightShader::~NonLightShader(){
	glDeleteProgram(program);
}