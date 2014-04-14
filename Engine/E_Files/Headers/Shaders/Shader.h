#pragma once

#include "IShader.h"
#include "LightShader.h"
#include "NonLightShader.h"

#include "../Model/Model.h"

class Shader{
public:
	void Draw(Model* tap_madl);

	Shader();
	~Shader();
private:
	IShader* shader;

	IShader* nls;
	IShader* ls;
};