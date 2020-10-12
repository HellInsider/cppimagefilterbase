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

	image_data Copy;
	ImageCopy(&Image, &Copy);

	for (int i = U; i < D; i++)
	{
		for (int j = L; j < R; j++)
		{
			KernelProcess(&Copy, &Image, j, i);			
		}
	}
}

