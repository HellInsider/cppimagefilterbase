#include "FilterBlackWhite.h"

void FilterBlackWhite::MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool)
{
	InputDataProcess(Ut, Lt, Dt, Rt, studTool);

	int i, j;
	float x;

	for (i = U; i < D; i++)
	{
		for (j = L; j < R; j += 1)
		{
			x = Image.pixels[(i*Image.w + j) * Image.compPerPixel] * 0.3 +
				Image.pixels[(i*Image.w + j) * Image.compPerPixel + 1] * 0.6 +
				Image.pixels[(i*Image.w + j) * Image.compPerPixel + 2] * 0.1;

			SetPixel(Image, j, i, x, x, x);
		}
	}
}