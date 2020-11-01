#include "FilterBlackWhite.h"
#include "FilterConvolutional.h"
#include "FilterExtazy.h"
#include <vector>

void FilterExtazy::MakeAction(int Ut, int Lt, int Dt, int Rt, png_toolkit* studTool)
{

	//FilterBlackWhite FilterBW;
	//FilterBW.MakeAction(Ut, Lt, Dt, Rt, studTool);

	InputDataProcess(Ut, Lt, Dt, Rt, studTool);

	std::vector<int> ChangeList;

	int intense, cur_pos;
	Pixel_t pixel_new = { 42,127, 213 };


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
						intense = GetPixelIntense(Image, x, y);

						Mass[cur_pos] = intense;
						cur_pos++;
					}
				}
			}

			Sort(Mass, cur_pos);

			if (GetPixelIntense(Image, j, i) < Mass[(cur_pos) / 2])
			{
				ChangeList.push_back(i);
				ChangeList.push_back(j);
			}

		}
	}

	int i = 0, j = 0;

	for (int t = 0; t < ChangeList.size(); t += 2)
	{
		i = ChangeList[t];
		j = ChangeList[t + 1];
		SetPixel(Image, j, i, pixel_new);
		pixel_new.R += 21 * (t % 3);
		pixel_new.G += 21 * (t % 3);
		pixel_new.B += 21 * (t % 3);
		//printf("%u\n", pixel_new.R);
	}

}

void FilterExtazy::Sort(int* Mass, int len)
{
	int a;
	for (int i = 0; i < len - 1; i++)
		for (int j = i + 1; j < len; j++)
			if (Mass[i] > Mass[j])
			{
				a = Mass[i];
				Mass[i] = Mass[j];
				Mass[j] = a;
			}
}