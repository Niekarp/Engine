#include "../../Headers/Shaders/LightShader.h"

void LightShader::Load(){
	Data vertex_shader   = RcLoad(RE_LIGHT_VERTEX_SHADER);
	Data fragment_shader = RcLoad(RE_LIGHT_FRAGMENT_SHADER);
	GLuint ivs = glCreateShader(GL_VERTEX_SHADER);
	GLuint ifs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(ivs, 1, (const GLchar**)&vertex_shader.res, (GLint*)&vertex_shader.res_size);
	glShaderSource(ifs, 1, (const GLchar**)&fragment_shader.res, (GLint*)&fragment_shader.res_size);

	glAttachShader(program, ivs);
	glAttachShader(program, ifs);
	glLinkProgram(program);
}
void LightShader::PassAtrib(GLuint argument, GLuint bufferID){
	switch (argument){
	case 0:
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
		break;
	case 1:
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);
		break;
	case 2:
		glBindBuffer(GL_ARRAY_BUFFER, bufferID);
		glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, 0);
		break;
	default:
		throw "Blad podczas przekazywania atrybutu do NonLightShader'a";
	};
}
void LightShader::PassUnif(GLuint argument, const GLfloat* data_pointer){
	switch (argument){
	case 0:
		glUniformMatrix4fv(0, 1, GL_FALSE, data_pointer);
		break;
	case 1:
		glUniform3fv(1, 1, data_pointer);
		break;
	case 2:
		glUniform3fv(2, 1, data_pointer);
		break;
	default:
		throw "Blad podczas przekazywania uniformu do NonLightShader'a";
	};
}
void LightShader::Draw(GLuint index, GLuint vertices){
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, index);
	glDrawElements(GL_TRIANGLES, vertices, GL_UNSIGNED_INT, 0);
}
void LightShader::Use(){
	glUseProgram(program);
}

LightShader::LightShader(){
}
LightShader::~LightShader(){
	glDeleteProgram(program);
}