#include <windows.h>

#include "E_Files\Libs\glew\glew.h"
#include "E_Files\Libs\glfw\glfw3.h"
#include "E_Files\Resources\shaders.h"
#include "E_Files\Headers\Shaders\Shaders.h"

#pragma comment ( lib, "opengl32.lib" )
#pragma comment ( lib, "E_Files/Libs/glew/glew32.lib" )
#pragma comment ( lib, "E_Files/libs/glfw/glfw3.lib")

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	glfwInit();
	GLFWwindow* win = glfwCreateWindow(1500, 800, "The Lorem", NULL, NULL);
	glfwMakeContextCurrent(win);
	glewInit();

	glViewport(0, 0, 1500, 800);

	glm::mat4 mvp;
	Shaders* shaders = new Shaders;
	try{
		shaders->ls->PassUnif(0, (const GLfloat*)&mvp);
	}
	catch (const char* error){
		MessageBox(0, error, "Error", 0);
	}
	
	glfwDestroyWindow(win);
	return 0;
}