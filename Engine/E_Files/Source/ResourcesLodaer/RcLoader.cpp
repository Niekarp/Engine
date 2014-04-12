#include "../../Headers/ResourcesLoader/RcLoader.h"

Data RcLoad(int RESOURCE_ID){
	Data data;
	HRSRC res_location = FindResource(0, MAKEINTRESOURCE(RESOURCE_ID), RT_RCDATA);
	data.res = LockResource(LoadResource(0, res_location));
	data.res_size = SizeofResource(0, res_location);
	if (!data.res || !data.res_size)throw "Wystapil problem przy uzyskiwaniu dostepu do zasobow NonLightShader'a";
	return data;
}