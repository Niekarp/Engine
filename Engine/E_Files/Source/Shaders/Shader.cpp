#include "../../Headers/Shaders/Shader.h"

void Shader::Draw(Model* model){
	// working c:
}

Shader::Shader(){
	nls = new NonLightShader;
	nls->Load();
	ls = new LightShader;
	ls->Load();
}
Shader::~Shader(){
	delete nls;
	delete ls;
}