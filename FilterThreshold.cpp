#include "FilterThreshold.h"
//#include <iostream>


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
		for (int j = L; j < R; j++)
		{
			cur_pos = 0;
			for (int y = i - 2; y <= i + 2; y++)
			{
				for (int x = j - 2; x <= j + 2; x++)
				{
					if (PixelExist(x, y))
					{
						intense = GetPixelIntense(Copy, x, y);
						
						Mass[cur_pos] = intense;
						cur_pos++;
					}
				}
			}

			Sort(Mass, cur_pos);		

			if(GetPixelIntense(Copy, j, i) < Mass[(cur_pos)/ 2])
			{
				SetPixel(Image, j, i, 0, 0, 0);
			}
						
		}
	}
}

void FilterThreshold::Sort(int* Mass, int len)
{
	int a;
	for(int i = 0; i<len-1;i++)
		for(int j = i+1; j<len; j++)
			if (Mass[i] > Mass[j])
			{
				a = Mass[i];
				Mass[i] = Mass[j];
				Mass[j] = a;
			}
}