#pragma once
#include "png_toolkit.h"
 
enum FilterType
{
	Red,
	BlackWhite,
	Threshold,
	Blur,
	Edge
};

class Filter
{
public:
	Filter() {};
	
	virtual void MakeAction(int U, int L, int D, int R, png_toolkit* studTool) = 0;
	~Filter() {};

	void InputDataProcess(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool);
	bool PixelExist(int x, int y);
	void ImageCopy(image_data* from, image_data* to);

	int GetPixelIntense(image_data Data, int x, int y);
	void SetPixel(image_data Data, int x, int y, int r, int g, int b);


	int U, D, L, R;
	png_toolkit* studTool;
	image_data Image;
};