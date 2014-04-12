#include "../../Headers/ResourcesLoader/RcLoader.h"

Data RcLoad(int RESOURCE_ID){
	Data data;
	data.res = LockResource(LoadResource(0, FindResource(0, MAKEINTRESOURCE(RESOURCE_ID), RT_RCDATA)));
	data.res_size = SizeofResource(0, FindResource(0, MAKEINTRESOURCE(RESOURCE_ID), RT_RCDATA));
	if (!data.res || !data.res_size)throw "Wystapil problem przy uzyskiwaniu dostepu do zasobow NonLightShader'a";
	return data;
}