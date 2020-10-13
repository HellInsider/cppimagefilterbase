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

	image_data Copy;
	ImageCopy(&Image, &Copy);

	for (int i = U; i < D; i++)
	{
		for (int j = L; j < R; j++)
		{
			KernelProcess(&Copy, &Image, j, i);			
		}
		//printf("%f\n", (float)(i) / (D - U));
	}
}

