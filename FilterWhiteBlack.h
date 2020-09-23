#pragma once
#include "Filter.h"
#include "png_toolkit.h"

class FilterWhiteBlack : public Filter
{
	//FilterRed() {};
public:
	FilterWhiteBlack(int U, int L, int D, int R, png_toolkit* studTool) :Filter(U, L, D, R, studTool) {};
	virtual void MakeAction();
	~FilterWhiteBlack() {};
};