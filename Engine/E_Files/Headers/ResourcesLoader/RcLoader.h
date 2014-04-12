#pragma once

#include <Windows.h>

struct Data{
	LPVOID res;
	DWORD res_size;
};
Data RcLoad(int RESOURCE_ID);