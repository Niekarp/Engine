#include "../../Headers/Model/Model.h"

Model::Model(std::string modelName,
	const char* file_ply,
	const char* texturePath,
	MODEL_TYPE type,
	glm::vec3 poz,
	glm::vec3 size)
	: name(modelName), modelType(type)
{
	LoadPLY(file_ply);
	LoadTexture(texturePath);
	Move(poz);
	Size(size);
}
Model::Model(){
	throw "Nie podano parametrow tworzonego modelu";
}
Model::~Model(){
	glDeleteBuffers(4, bos);
	glDeleteTextures(1, &textureID);
}

void Model::LoadPLY(const char* filename){
	FILE* file;
	if (fopen_s(&file, filename, "r") != 0){
		perror("Wystapil blad");
		throw "Blad Podczas Ladowania Modelu";
	}
	fseek(file, 0, SEEK_END);
	int pos = ftell(file);
	fseek(file, 0, SEEK_SET);
	char* text = new char[pos];
	char* text_p = text;
	fread(text, 1, pos, file);
	fclose(file);


	//Sprawdzanie Formatu
	if (text[0] != 'p'
		||
		text[1] != 'l'
		||
		text[2] != 'y'){
		printf("Bledny format pliku\n");
		delete[] text;
		throw "Bledny Format Pliku Z Modelem";
	}
	//Tworzenie tablic
	float* vertex;
	float* normal;
	float* uv;
	std::vector<int> indyk;

	int face;
	int array_elements;
	//
	text = strstr(text, "element vertex") + strlen("element vertex ");
	array_elements = atoi(text);
	vertex = new float[array_elements * 3];
	normal = new float[array_elements * 3];
	uv = new float[array_elements * 2];

	text = strstr(text, "element face") + strlen("element face ");
	face = atoi(text);
	indyk.reserve(face * 3);
	//Definiowanie tablic
	text = strstr(text, "end_header") + strlen("end_header\n");
	float value;
	for (int i = 0; i < array_elements; i++){
		for (int j = 0; j < 8; j++){
			value = (float)atof(text);
			switch (j){
			case 0:
			case 1:
			case 2:
				vertex[(i * 3) + j] = value;
				break;
			case 3:
			case 4:
			case 5:
				normal[(i * 3) + (j - 3)] = value;
				break;
			case 6:
			case 7:
				uv[(i * 2) + (j - 6)] = value;
				break;
			};
			if (*text == '-')text += 10;
			else if (*text != '-')text += 9;
		}
	}
	//Indyk
	int v[4];
	for (int i = 0; i < face; i++){
		value = (float)atof(text);
		text += 2;
		if ((int)value == 3){
			for (int j = 0; j < 3; j++){
				indyk.push_back(atoi(text));
				if (j != 2) text = strstr(text, " ") + 1;
				else text = strstr(text, "\n") + 1;
			}
		}
		else if ((int)value == 4){
			for (int j = 0; j < 4; j++){
				v[j] = atoi(text);
				if (j != 3) text = strstr(text, " ") + 1;
				else text = strstr(text, "\n") + 1;
			}
			indyk.push_back(v[0]);
			indyk.push_back(v[1]);
			indyk.push_back(v[2]);
			indyk.push_back(v[0]);
			indyk.push_back(v[2]);
			indyk.push_back(v[3]);
		}
	}
	verticesN = indyk.size();

	glGenBuffers(4, bos);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bos[0]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (array_elements * 3) * 4, vertex, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bos[1]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (array_elements * 3) * 4, normal, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bos[2]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, (array_elements * 2) * 4, uv, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, bos[3]);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, indyk.size() * 4, &indyk[0], GL_STATIC_DRAW);
	//~~~~~
	delete[] text_p;

	delete[] vertex;
	delete[] normal;
	delete[] uv;
	indyk.clear();
}
void Model::LoadTexture(const char* imagepath){
	unsigned char header[54];
	unsigned int dataPos;
	unsigned int width, height;
	unsigned int imageSize;

	unsigned char* data;

	FILE* file;
	if (fopen_s(&file, imagepath, "r") != 0){
		perror("Wystapil blad");
		throw "Problem z otwarciem pliku z textura";
	}
	if (fread(header, 1, 54, file) != 54)
		throw "Problem z wczytywaniem tekstury";
	if (header[0] != 'B' || header[1] != 'M')
		throw "Niepoprawny format pliku z textura";
	
	dataPos   = *(int*)&(header[0x0A]);
	imageSize = *(int*)&(header[0x22]);
	width     = *(int*)&(header[0x12]);
	height    = *(int*)&(header[0x16]);

	if (imageSize == 0) imageSize = width * height * 3;
	if (dataPos == 0) dataPos = 54;

	data = new unsigned char[imageSize];

	fread(data, 1, imageSize, file);

	fclose(file);


	GLuint makedTexture;
	glGenBuffers(1, &makedTexture);
	glBindTexture(GL_TEXTURE_2D, makedTexture);
	glTexImage2D(GL_TRIANGLES, 0, GL_RGB, width, height, 0, GL_BGR, GL_UNSIGNED_BYTE, data);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

	textureID = makedTexture;
	
	glDeleteTextures(1, &makedTexture);
}
void Model::Move(glm::vec3 position){
	modelMatrix *= glm::translate(position);
}
void Model::Size(glm::vec3 size){
	modelMatrix *= glm::scale(size);
}

std::string Model::Name(){
	return name;
}
MODEL_TYPE Model::Type(){
	return modelType;
}
const GLfloat* Model::Matrix(){
	return (const GLfloat*)&modelMatrix;
}
GLuint    Model::Texture(){
	return textureID;
}
GLuint    Model::Bos(GLuint index){
	if (index > 4 || index < 0)
		throw "Wyjscie poaza zasieg tablicy bos";
	else
	    return bos[index];
}
GLuint    Model::VerticesN(){
	return verticesN;
}
glm::vec3 Model::Position(){
	return position;
}
glm::vec3 Model::Size(){
	return size;
}