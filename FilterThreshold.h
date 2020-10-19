#pragma once
#include "Filter.h"
#include "FilterBlackWhite.h"

class FilterThreshold: public Filter
{

public:
	FilterThreshold() {};
	~FilterThreshold() {};

	virtual void MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool);
	void Sort(int* Mass, int len);


	int Mass[25];
};