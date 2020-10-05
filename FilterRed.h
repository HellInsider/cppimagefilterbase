#pragma once
#include "Filter.h"
#include "png_toolkit.h"

class FilterRed: public Filter
{
	//FilterRed() {};
public:
	FilterRed() {};
	virtual void MakeAction(int U, int L, int D, int R, png_toolkit* studTool);
	~FilterRed() {};
};