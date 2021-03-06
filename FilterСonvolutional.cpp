#include "FilterConvolutional.h"

Pixel_t FilterConvolutional::KernelProcess( image_data* Image, int j, int i)
{
	int CernSumR = 0, CernSumG = 0, CernSumB = 0, KernelMassSum = 0;
	Pixel_t pixel;
	int FLy = i - KernelSize / 2, FLx = j - KernelSize / 2;
	int KernelVal;

	for (int y = 0; y < KernelSize; y++)
	{
		for (int x = 0; x < KernelSize; x++)
		{
			if (PixelExist(FLx + x, FLy + y))
			{
				GetPixeRGB(*Image, FLx + x, FLy + y, &pixel);

				KernelVal = Kernel[y][x];

				CernSumR += KernelVal * pixel.R;
				CernSumG += KernelVal * pixel.G;
				CernSumB += KernelVal * pixel.B;

				KernelMassSum += KernelVal;
			}
		}
	}

	if (KernelMassSum != 0 && KernelMassSum != 1)
	{
		CernSumR /= KernelMassSum;
		CernSumG /= KernelMassSum;
		CernSumB /= KernelMassSum;
	}


	if (CernSumR > 255) CernSumR = 255;
	if (CernSumR < 0) CernSumR = 0;

	if (CernSumG > 255) CernSumG = 255;
	if (CernSumG < 0) CernSumG = 0;

	if (CernSumB > 255) CernSumB = 255;
	if (CernSumB < 0) CernSumB = 0;
	
	pixel.R = CernSumR;
	pixel.G = CernSumG;
	pixel.B = CernSumB;

	return pixel;
}