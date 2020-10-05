#include "FilterThreshold.h"


void FilterThreshold::MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool)
{

	FilterBlackWhite FilterBW;
	FilterBW.MakeAction(Ut, Lt, Dt, Rt, studTool);

	InputDataProcess(Ut, Lt, Dt, Rt, studTool);

	image_data Copy;
	ImageCopy(&Image, &Copy);

	int intense, cur_pos;


	for (int i = U; i < D; i++)
	{
		for (int j = L; j < R; j += 1)
		{
			cur_pos = 0;
			for (int y = i - 2; y < i + 2; y++)
			{
				for (int x = j - 2; x < j + 2; x++)
				{
					if (PixelExist(x, y))
					{
						intense = Copy.pixels[(y*Image.w + x) * Copy.compPerPixel] * 3 +
							Copy.pixels[(y*Image.w + x) * Copy.compPerPixel + 1] * 6 +
							Copy.pixels[(y*Image.w + x) * Copy.compPerPixel + 2];

						intense /= 10;

						Mass[cur_pos] = intense;
						cur_pos++;
					}

				}
			}
			cur_pos++;

			Sort(Mass, cur_pos);

			if((Image.pixels[(i*Image.w + j) * Image.compPerPixel] * 3 +
				Image.pixels[(i*Image.w + j) * Image.compPerPixel + 1] * 6 +
				Image.pixels[(i*Image.w + j) * Image.compPerPixel + 2]) / 10 < Mass[(cur_pos / 2)])
			{
				Image.pixels[(i*Image.w + j) * Image.compPerPixel] = 0;
					Image.pixels[(i*Image.w + j) * Image.compPerPixel + 1] = 0;
					Image.pixels[(i*Image.w + j) * Image.compPerPixel + 2] = 0;
			}
						
		}
	}

}

void FilterThreshold::Sort(int* Mass, int len)
{
	int a;
	for(int i = 0; i<len-1;i++)
		for(int j = i+1; j<len; j++)
			if (Mass[i] < Mass[j])
			{
				a = Mass[i];
				Mass[i] = Mass[j];
				Mass[j] = a;
			}
}