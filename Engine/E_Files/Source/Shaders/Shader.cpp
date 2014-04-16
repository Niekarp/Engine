#include "../../Headers/Shaders/Shader.h"

void Shader::Draw(Scene* scene){
	shader = nls;
	shader->PassAtrib(0, scene->GetModel()->Bos(0));
	shader->PassAtrib(1, scene->GetModel()->Bos(1));
	shader->PassAtrib(2, scene->GetModel()->Bos(2));
	shader->PassUnif(0, scene->GetModel()->Matrix());

	shader->Draw(scene->GetModel()->Bos(3),
		scene->GetModel()->TriangleN());
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

	delete shader;
}