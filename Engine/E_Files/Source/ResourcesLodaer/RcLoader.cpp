#include "../../Headers/ResourcesLoader/RcLoader.h"
#include <Windows.h>

Data RcLoad(int RESOURCE_ID){
	Data data;
	HRSRC res_location = FindResource(0, MAKEINTRESOURCE(RESOURCE_ID), RT_RCDATA);
	data.res = LockResource(LoadResource(0, res_location));
	data.res_size = SizeofResource(0, res_location);
	char* tab = (char*)data.res;
	tab[data.res_size - 1] = 0;
	MessageBox(0, (LPCSTR)tab, 0, 0);
	if (!data.res || !data.res_size)throw "Wystapil problem przy uzyskiwaniu dostepu do zasobow NonLightShader'a";
	return data;
}