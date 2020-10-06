#include "FilterBlackWhite.h"

void FilterBlackWhite::MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool)
{
	InputDataProcess(Ut, Lt, Dt, Rt, studTool);

	int i, j;
	int x;

	for (i = U; i < D; i++)
	{
		for (j = L; j < R; j += 1)
		{
			x =  GetPixelIntense(Image, j, i);
			SetPixel(Image, j, i, x, x, x);
		}
	}
}