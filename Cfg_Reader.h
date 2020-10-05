#pragma once
#include <string>
#include "Filter.h"

class Cfg_Reader
{
	bool FindSubString(std::string str1, std::string str2);

	static const int Filters_Num = 5;

	std::string Filter_Names[Filters_Num] =
	{
		"Red",
		"BlackWhite",
		"Threshold",
		"Blur",
		"Edge"
	};


public:
	bool Read(char* Cfg_path, int* U, int* L, int* D, int* R, FilterType *type);


};