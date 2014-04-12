#include <windows.h>

#include "E_Files\Resources\shaders.h"
#include "E_Files\Headers\Shaders\IShader.h"
#include "E_Files\Headers\Shaders\NonLightShader.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	try{
		IShader* shader;
		shader = new NonLightShader;
		shader->Load();
	}
	catch (const char* error){
		MessageBox(0, error, "Error", 0);
	}
	
	return 0;
}