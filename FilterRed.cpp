#include "Filter.h"
#include "FilterRed.h"
#include "png_toolkit.h"

void FilterRed :: MakeAction()
{
	
	int i, j;
	
	i = (U == 0) ? 0 : Image.h / U;

	for (; i < Image.h / D; i++)
	{
		j = (L == 0) ? 0 : Image.w / L;
		for (; j < Image.w / R; j+=1)
		{
			Image.pixels[(i*Image.w + j) * Image.compPerPixel] = 0xFF;
			Image.pixels[(i*Image.w + j) * Image.compPerPixel + 1] = 0x00;
			Image.pixels[(i*Image.w + j) * Image.compPerPixel + 2] = 0x00;
		}
	}

}