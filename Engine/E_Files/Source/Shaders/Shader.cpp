#include "../../Headers/Shaders/Shader.h"



Shader::Shader(){
	nls = new NonLightShader;
	nls->Load();
	ls = new LightShader;
	ls->Load();
}
Shader::~Shader(){
	delete nls;
	delete ls;

	delete shader;
}