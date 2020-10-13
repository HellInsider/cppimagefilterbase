#pragma once
#include "PixelRGB.h"
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
	
	virtual void MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool) = 0;
	~Filter() {};

	void InputDataProcess(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool);
	bool PixelExist(int x, int y);
	void ImageCopy(image_data* from, image_data* to);

	int GetPixelIntense(image_data Data, int x, int y);
	void SetPixel(image_data Data, int x, int y, Pixel_t pixel);
	void GetPixeRGB(image_data Data, int x, int y, Pixel_t* pixel);


	int U, D, L, R;
	png_toolkit* studTool;
	image_data Image;
};