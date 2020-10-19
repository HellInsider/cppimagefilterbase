#pragma once
#include "vector"
#include "Filter.h"
#include "png_toolkit.h"


class FilterConvolutional : public Filter
{
	

public:

	int KernelSize;
	std::vector<std::vector<int>> Kernel;

	Pixel_t KernelProcess(image_data* Image, int i, int j);

	Pixel_t *PixelMass;

};
