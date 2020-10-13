#include "Filter.h"
#include "FilterRed.h"
#include "png_toolkit.h"

void FilterRed :: MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool)
{
	InputDataProcess(Ut, Lt, Dt, Rt, studTool);

	int i, j;
	Pixel_t pixel_red = { 0xFF,0,0 };
	
	for (i = U; i < D; i++)
	{
		for (j = L; j < R; j++)
		{
			SetPixel(Image, j, i, pixel_red);
		}
	}
}