#pragma once
#include "png_toolkit.h"
 
class Filter
{
public:
	Filter() {};
	Filter(int U, int L, int D, int R, png_toolkit* studTool) : U(U), L(L), D(D), R(R), studTool(studTool) 
		{ Image = studTool->getPixelData(); };
	
	virtual void MakeAction() = 0;
	~Filter() {};

	int U, D, L, R;
	png_toolkit* studTool;
	image_data Image;
};