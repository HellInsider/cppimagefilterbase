#include "FilterBlackWhite.h"

void FilterBlackWhite::MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool)
{
	InputDataProcess(Ut, Lt, Dt, Rt, studTool);

	int i, j;
	unsigned char x;
	Pixel_t pixel;

	for (i = U; i < D; i++)
	{
		for (j = L; j < R; j++)
		{
			x = (unsigned char)GetPixelIntense(Image, j, i);
			pixel = { x,x,x };
			SetPixel(Image, j, i, pixel);
		}
	}
}