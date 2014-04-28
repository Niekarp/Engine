#include "../../Headers/Shaders/Shader.h"

void Shader::Draw(Scene* scene){
    std::vector<Model>& models = *(scene->Models());
	
	for (unsigned int i = 0; i < models.size(); i++){
	    glm::mat4 mvp = ((*(models.at(i).Matrix()) * (*(scene->VP()))));
	    
		switch(models.at(i).Type()){
			case NON_LIGHTED:
				shader = nls;
				shader->Use();
				shader->PassUnif(0, (const GLfloat*)&mvp);
				break;
			case DIFFUSE_LIGHTED:
				shader = ls;
				shader->Use();
				shader->PassUnif(0, (const GLfloat*)&mvp);
				shader->PassUnif(1, (const GLfloat*)scene->Spotlight());
				shader->PassUnif(3, (const GLfloat*)&glm::vec3(1, 0, 0));
				break;
			case AMBIENT_LIGHTED:
				shader = ls;
				shader->Use();
				shader->PassUnif(0, (const GLfloat*)&mvp);
				shader->PassUnif(2, (const GLfloat*)scene->AmbientLight());
				shader->PassUnif(3, (const GLfloat*)&glm::vec3(0, 1, 0));
				break;
			case DIFFUSE_AND_AMBIENT_LIGHTED:
				shader = ls;
				shader->Use();
				shader->PassUnif(0, (const GLfloat*)&mvp);
				shader->PassUnif(1, (const GLfloat*)scene->Spotlight());
				shader->PassUnif(2, (const GLfloat*)scene->AmbientLight());
				shader->PassUnif(3, (const GLfloat*)&glm::vec3(0, 0, 1));
				break;
			default:
				throw "Problem podczas przekazywania uniformow do shadera";
				break;
		};
		
		shader->PassAtrib(0, models.at(i).Bos(0));
		shader->PassAtrib(1, models.at(i).Bos(1));
		shader->PassAtrib(2, models.at(i).Bos(2));
		
		shader->Draw(models.at(i).Bos(3), models.at(i).VerticesN());
	}
}

Shader::Shader(){
	nls = new NonLightShader;
	nls->Load();
	ls = new LightShader;
	ls->Load();
}
Shader::~Shader(){
	delete nls;
	delete ls;

	delete shader;
}