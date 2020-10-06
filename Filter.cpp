#include "Filter.h"

bool Filter::PixelExist(int x, int y)
{
	if (x >= 0 && x < Image.w && y>=0 && y < Image.h)
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
		{
			to->pixels[to->compPerPixel*(to->w*i + j)] = from->pixels[from->compPerPixel*(from->w*i + j)];
			to->pixels[to->compPerPixel*(to->w*i + j)+1] = from->pixels[from->compPerPixel*(from->w*i + j)+1];
			to->pixels[to->compPerPixel*(to->w*i + j)+2] = from->pixels[from->compPerPixel*(from->w*i + j)+2];
		}
}

int Filter::GetPixelIntense(image_data Data, int x, int y)
{
	int intense = Data.pixels[(y*Image.w + x) * Data.compPerPixel] * 3 +
		Data.pixels[(y*Image.w + x) * Data.compPerPixel + 1] * 6 +
		Data.pixels[(y*Image.w + x) * Data.compPerPixel + 2];

	return intense / 10;
}

void Filter::SetPixel(image_data Data, int x, int y, int r, int g, int b)
{
	Data.pixels[(y*Data.w + x) * Data.compPerPixel] = r;
	Data.pixels[(y*Data.w + x) * Data.compPerPixel + 1] = g;
	Data.pixels[(y*Data.w + x) * Data.compPerPixel + 2] = b;
}