#pragma once
#include "FilterConvolutional.h"
#include "png_toolkit.h"


class FilterEdge : public FilterConvolutional
{

	int MyKernelSize = 3;
	std::vector<std::vector<int>> MyKernel = { { -1, -1, -1},
											   { -1, 9, -1},
											   { -1, -1, -1} };

public:
	
	FilterEdge();
	virtual void MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool);
};
