#include "FilterBlackWhite.h"
#include "FilterConvolutional.h"
#include "FilterEdge.h"


FilterEdge::FilterEdge()
{
	Kernel = MyKernel;
	KernelSize = MyKernelSize;
}


void FilterEdge::MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool)
{
	FilterBlackWhite FilterBW;
	FilterBW.MakeAction(Ut, Lt, Dt, Rt, studTool);

	InputDataProcess(Ut, Lt, Dt, Rt, studTool);
	   
	PixelMass = new Pixel_t[(D - U) * (R - L)];

	for (int i = U; i < D; i++)
	{
		for (int j = L; j < R; j++)
		{
			PixelMass[i*(R - L) + j - L] = KernelProcess(&Image, j, i);
		}

	}

	for (int i = U; i < D; i++)
	{
		for (int j = L; j < R; j++)
		{
			SetPixel(Image, j, i, PixelMass[i*(R-L) + j-L]);
		}
	}

	delete [] PixelMass;
}

