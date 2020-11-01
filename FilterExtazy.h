#pragma once
#include "FilterConvolutional.h"
#include "png_toolkit.h"


class FilterExtazy : public FilterConvolutional
{

	void Sort(int* Mass, int len);


	int Mass[25];
public:

	virtual void MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool);
};
