#include "FilterConvolutional.h"

void FilterConvolutional::KernelProcess(image_data* Copy, image_data* Image, int j, int i)
{
	int CernSumR = 0, CernSumG = 0, CernSumB = 0, KernelMassSum = 0;
	int R, G, B;
	int FLy = i - KernelSize / 2, FLx = j - KernelSize / 2;

	for (int y = 0; y < KernelSize; y++)
	{
		for (int x = 0; x < KernelSize; x++)
		{
			if (PixelExist(FLx + x, FLy + y))
			{
				//printf(" %i_%i ", FLx + x, FLy + y);
				GetPixeRGB(*Copy, FLx + x, FLy + y, &R, &G, &B);

				CernSumR += Kernel[y][x] * R;
				CernSumG += Kernel[y][x] * G;
				CernSumB += Kernel[y][x] * B;

				KernelMassSum += Kernel[y][x];
			}
		}
	}
	//printf("\n");

	KernelMassSum = KernelMassSum == 0 ? 1 : KernelMassSum;

	CernSumR /= KernelMassSum;
	CernSumR = CernSumR > 255 ? 255 : CernSumR;
	CernSumR = CernSumR < 0 ? 0 : CernSumR;

	CernSumG /= KernelMassSum;
	CernSumG = CernSumG > 255 ? 255 : CernSumG;
	CernSumG = CernSumG < 0 ? 0 : CernSumG;

	CernSumB /= KernelMassSum;
	CernSumB = CernSumB > 255 ? 255 : CernSumB;
	CernSumB = CernSumB < 0 ? 0 : CernSumB;

	SetPixel(*Image, j, i, CernSumR, CernSumG, CernSumB);

}