#include <iostream>
#include <fstream>
#include <string>
#include "Cfg_Reader.h"

bool Cfg_Reader::Read(char* Cfg_path, int* U, int* L, int* D, int* R, FilterType *type)
{
	std::ifstream stream(Cfg_path);
	std::string temp_buf;
	   	
	if (!stream)
	{
		return false;
	}

	stream >> temp_buf;
	stream >> *U >> *L >> *D >> *R;

	stream.close();



	int i = 0;
	for (; i < Filters_Num; i++)
	{
		if (FindSubString(temp_buf, Filter_Names[i]))
			break;
	}

	if(i == Filters_Num)
	{
		return false;
	}

	*type = (FilterType) i;

	return true;
}

bool Cfg_Reader::FindSubString(std::string str1, std::string str2) // find str2 in str1
{
	int lenght_str1 = str1.length(), lenght_str2 = str2.length();

	int j;
	for (int i = 0; i <= lenght_str1 - lenght_str2; i++)
	{
		for (j=0; j < lenght_str2; j++)
		{
			if(str1[i+j] != str2[j])
			{
				break;
			}
		}
		if (j == lenght_str2)
			return true;
	}

	return false;
}