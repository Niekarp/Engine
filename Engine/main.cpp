#include <windows.h>

#include "E_Files\Resources\shaders.h"

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	HGLOBAL Ver_Shader = LoadResource(hInstance, FindResource(hInstance, MAKEINTRESOURCE(RE_NON_LIGHT_VERTEX_SHADER), RT_RCDATA));
	HGLOBAL Frag_Shader = LoadResource(hInstance, FindResource(hInstance, MAKEINTRESOURCE(RE_NON_LIGHT_FRAGMENT_SHADER), RT_RCDATA));
	MessageBox(0, "Czy Barrack Obama Przezyje ?"," dupa", 0);

	if (Ver_Shader == 0 || Frag_Shader == 0)
		MessageBox(0, "Barrack Obama Nie Zyje!", "Porazka", 0);
	else
		MessageBox(0, "Barrack Obama Zostal Uratowany!", "Zwyciestwo", 0);
	
	return 0;
}