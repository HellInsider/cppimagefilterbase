#include "FilterBlackWhite.h"
#include "FilterConvolutional.h"
#include "FilterBlur.h"


FilterBlur::FilterBlur()
{
	Kernel = MyKernel;
	KernelSize = MyKernelSize;
}


void FilterBlur::MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool)
{
	InputDataProcess(Ut, Lt, Dt, Rt, studTool);

	PixelMass = new Pixel_t [(D - U) * (R - L)];

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
			SetPixel(Image, j, i, PixelMass[i*(R - L) + j - L]);
			//printf("%i: \n", i*(R - L) + j - L);
		}
	}

	delete[] PixelMass;
}

