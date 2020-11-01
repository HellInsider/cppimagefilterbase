#pragma once
#include <string>
#include "Filter.h"

class Cfg_Reader
{
	

	bool FindSubString(std::string str1, std::string str2);
	   
	std::ifstream *stream;

	static const int Filters_Num = 6;

	std::string Filter_Names[Filters_Num] =
	{
		"Red",
		"BlackWhite",
		"Threshold",
		"Blur",
		"Edge",
		"Extazy"
	};


public:
	bool Read(int* U, int* L, int* D, int* R, FilterType *type);
	Cfg_Reader(char* Cfg_path);
	~Cfg_Reader();


};