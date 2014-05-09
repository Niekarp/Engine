#include <windows.h>

#include "E_Files\Libs\glew\glew.h"
#include "E_Files\Libs\glfw\glfw3.h"
#include "E_Files\Resources\shaders.h"
#include "E_Files\Headers\Shaders\Shader.h"

#include "E_Files\Headers\Scene\Scene.h"

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
	glClearColor(0.005, 0.111, 0.2, 1);

	Shader* shader = new Shader;

	
	Scene* scene = new Scene(win);
	while (glfwGetKey(win, GLFW_KEY_ESCAPE) != GLFW_PRESS && !glfwWindowShouldClose(win)){
		try{
			glClear(GL_COLOR_BUFFER_BIT);
			glfwPollEvents();
			
			scene->ObjectAdd("test", "Models/Test/test.ply", "Models/Test/test.bmp", NON_LIGHTED, glm::vec3(0.f, 0.f, 0.f), glm::vec3(1.f, 1.f, 1.f));
			scene->ComputeMatricesFromInputs();
			
			shader->Draw(scene);
			glfwSwapBuffers(win);
		}
		catch (const char* error){
			MessageBox(0, error, 0, 0);
		}
	}
	glfwDestroyWindow(win);
	return 0;
}