#include "Filter.h"
#include "FilterRed.h"
#include "png_toolkit.h"

void FilterRed :: MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool)
{
	InputDataProcess(Ut, Lt, Dt, Rt, studTool);

	int i, j;

	for (i = U; i < D; i++)
	{
		for (j = L; j < R; j += 1)
		{
			Image.pixels[(i*Image.w + j) * Image.compPerPixel] = 0xFF;
			Image.pixels[(i*Image.w + j) * Image.compPerPixel + 1] = 0x00;
			Image.pixels[(i*Image.w + j) * Image.compPerPixel + 2] = 0x00;
		}
	}
}