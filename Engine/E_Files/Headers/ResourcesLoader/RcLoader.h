#pragma once

#include <Windows.h>

struct Data{
	LPVOID res;
	HRSRC res_size;
};
Data RcLoad(int RESOURCE_ID);