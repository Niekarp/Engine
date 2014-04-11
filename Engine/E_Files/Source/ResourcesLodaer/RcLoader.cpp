#include "../../Headers/ResourcesLoader/RcLoader.h"

LPVOID RcLoad(int RESOURCE_ID){
	LPVOID res = LockResource(LoadResource(0, FindResource(0, MAKEINTRESOURCE(RESOURCE_ID), RT_RCDATA)));
	if (!res)throw;
	return res;
}