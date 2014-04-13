#include "../../Headers/Shaders/Shaders.h"

Shaders::Shaders(){
	nls = new NonLightShader;
	ls = new LightShader;
}
Shaders::~Shaders(){
	delete nls;
	delete ls;
}