#include "../../Headers/ResourcesLoader/RcLoader.h"

HGLOBAL RcLoad(int RESOURCE_ID){
	HGLOBAL Res = LoadResource(0, FindResource(0, MAKEINTRESOURCE(RESOURCE_ID), RT_RCDATA));
	if (!Res)throw;
	return Res;
}