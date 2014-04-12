#include <windows.h>

#include "E_Files\Resources\shaders.h"
#include "E_Files\Headers\Shaders\IShader.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	try{
		RcLoad(RE_NON_LIGHT_VERTEX_SHADER);
		RcLoad(RE_NON_LIGHT_FRAGMENT_SHADER);
	}
	catch (const char* error){
		MessageBox(0, error, "Error", 0);
	}
	
	return 0;
}