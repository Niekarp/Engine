#pragma once

#include "IShader.h"
#include "LightShader.h"
#include "NonLightShader.h"

#include "../Model/Model.h"
#include "../Scene/Scene.h"

class Shader{
public:
	void Draw(Scene* scene);

	Shader();
	~Shader();
private:
	IShader* shader;

	IShader* nls;
	IShader* ls;
};