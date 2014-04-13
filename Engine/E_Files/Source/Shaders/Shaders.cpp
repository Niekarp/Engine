#include "../../Headers/Shaders/Shaders.h"

Shaders::Shaders(){
	nls = new NonLightShader;
	nls->Load();
	ls = new LightShader;
	ls->Load();
}
Shaders::~Shaders(){
	delete nls;
	delete ls;
}