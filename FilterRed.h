#pragma once
#include "Filter.h"
#include "png_toolkit.h"

class FilterRed: public Filter
{
	//FilterRed() {};
public:
	FilterRed(int U, int L, int D, int R, png_toolkit* studTool) :Filter(U, L,  D, R,  studTool) {};
	virtual void MakeAction();
	~FilterRed() {};
};