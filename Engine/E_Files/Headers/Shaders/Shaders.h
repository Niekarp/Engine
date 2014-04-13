#pragma once

#include "IShader.h"
#include "LightShader.h"
#include "NonLightShader.h"

class Shaders{
public:
	IShader* nls;
	IShader* ls;
	Shaders();
	~Shaders();
};