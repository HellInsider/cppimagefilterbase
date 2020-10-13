#include "Filter.h"

bool Filter::PixelExist(int x, int y)
{
	//if (x >= 0 && x < Image.w && y>=0 && y < Image.h)
	if (x >= L && x < R && y >= U && y < D)
		return true;

	return false;
}

void Filter::InputDataProcess(int Ut, int Lt, int Dt, int Rt, png_toolkit* tstudTool)
{
	studTool = tstudTool;
	Image = studTool->getPixelData();

	U = (Ut == 0) ? 0 : Image.h / Ut;
	D = Image.h / Dt;

	L = (Lt == 0) ? 0 : Image.w / Lt;
	R = Image.w / Rt;
}

void Filter::ImageCopy(image_data* from, image_data* to)
{
	to->compPerPixel = from->compPerPixel;
	to->h = from->h;
	to->w = from->w;
	to->pixels = new stbi_uc[to->h*to->w*to->compPerPixel];

	for(int i=0;i<to->h;i++)
		for (int j = 0; j < to->w; j++)
			for(int byte = 0; byte<to->compPerPixel; byte++)
				to->pixels[to->compPerPixel*(to->w*i + j) + byte] = from->pixels[from->compPerPixel*(from->w*i + j) + byte];
		
}

int Filter::GetPixelIntense(image_data Data, int x, int y)
{
	int intense = Data.pixels[(y*Image.w + x) * Data.compPerPixel] * 3 +
		Data.pixels[(y*Image.w + x) * Data.compPerPixel + 1] * 6 +
		Data.pixels[(y*Image.w + x) * Data.compPerPixel + 2];

	return ( intense / 10 );
}

void Filter::GetPixeRGB(image_data Data, int x, int y, Pixel_t* pixel)
{
	pixel->R = Data.pixels[(y*Image.w + x) * Data.compPerPixel];
	pixel->G = Data.pixels[(y*Image.w + x) * Data.compPerPixel + 1];
	pixel->B = Data.pixels[(y*Image.w + x) * Data.compPerPixel + 2];
}

void Filter::SetPixel(image_data Data, int x, int y, Pixel_t pixel)
{
	Data.pixels[(y*Data.w + x) * Data.compPerPixel] = pixel.R;
	Data.pixels[(y*Data.w + x) * Data.compPerPixel + 1] = pixel.G;
	Data.pixels[(y*Data.w + x) * Data.compPerPixel + 2] = pixel.B;
}