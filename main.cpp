#include <iostream>
#include "Cfg_Reader.h"
#include "Filter.h"
#include "FilterRed.h"
#include "FilterBlackWhite.h"
#include "FilterThreshold.h"
#include "FilterBlur.h"
#include "FilterEdge.h"
#include "FilterExtazy.h"
#include "png_toolkit.h"
#pragma warning(disable: 4996)


int main( int argc, char *argv[] )
{
	if (argc != 4)
	{
		printf("Err: Not enought args\n");
		return 0;
	}
		
	png_toolkit studTool;

	if (!studTool.load(argv[2]))
	{
		printf("Err: Not found pic\n");
		return 0;
	}

		
	FilterType Type;
	int U, D, L, R;

	Cfg_Reader Reader(argv[1]);

	Filter *MyFilter = NULL;

	while (Reader.Read(&U, &L, &D, &R, &Type))
	{
		switch (Type)
		{
		case Red: { MyFilter = new FilterRed(); break; }
		case BlackWhite: { MyFilter = new FilterBlackWhite(); break; }
		case Threshold: { MyFilter = new FilterThreshold(); break; }
		case Blur: { MyFilter = new FilterBlur(); break; }
		case Edge: { MyFilter = new FilterEdge(); break; }
		case Extazy: { MyFilter = new FilterExtazy(); break; }
		default: { }
		}

		if (MyFilter == NULL)
		{
			std::cout << "Unknown Filter." << std::endl;
			return 0;
		}

		MyFilter->MakeAction(U, L, D, R, &studTool);
	}

	studTool.save(argv[3]);
	
	delete MyFilter;
	printf("Complete!\n");

    return 0;
}
