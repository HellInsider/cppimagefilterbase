#pragma once
#include "Filter.h"
#include "png_toolkit.h"

class FilterBlackWhite : public Filter
{
public:
	FilterBlackWhite() {};
	virtual void MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool);
	~FilterBlackWhite() {};
};