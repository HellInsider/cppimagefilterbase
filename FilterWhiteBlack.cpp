#include "FilterWhiteBlack.h"

void FilterWhiteBlack::MakeAction()
{
	int i, j;
	float x;

	i = (U == 0) ? 0 : Image.h / U;

	for (; i < Image.h / D; i++)
	{
		j = (L == 0) ? 0 : Image.w / L;
		for (; j < Image.w / R; j += 1)
		{
			x = Image.pixels[(i*Image.w + j) * Image.compPerPixel] * 0.3 +
				Image.pixels[(i*Image.w + j) * Image.compPerPixel + 1] * 0.6 +
				Image.pixels[(i*Image.w + j) * Image.compPerPixel + 2] * 0.1;

			Image.pixels[(i*Image.w + j) * Image.compPerPixel] = (unsigned char)(x);
			Image.pixels[(i*Image.w + j) * Image.compPerPixel + 1] = (unsigned char)(x);
			Image.pixels[(i*Image.w + j) * Image.compPerPixel + 2] = (unsigned char)(x);
		}
	}
}