#pragma once
#include "vector"
#include "Filter.h"
#include "png_toolkit.h"


class FilterConvolutional : public Filter
{


public:

	int KernelSize;
	std::vector<std::vector<int>> Kernel;

	void KernelProcess(image_data* Copy, image_data* Image, int i, int j);

	

};
