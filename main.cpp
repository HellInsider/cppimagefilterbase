#include <iostream>
#include "Filter.h"
#include "FilterRed.h"
#include "FilterWhiteBlack.h"
#include <string.h>
#include "png_toolkit.h"
#pragma warning(disable: 4996)

int main( int argc, char *argv[] )
{
    // toolkit filter_name base_pic_name sudent_tool student_pic_name limitPix limitMSE
    // toolkit near test images!



	//printf("args[1...3] = %s\n %s\n %s\n", argv[1], argv[2], argv[3]);

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

	FILE *config;	
	char filter_name[32];
	int U, D, L, R;
	
	config = fopen(argv[1], "r");
	   
	fscanf(config, "%s", filter_name);
	fscanf(config, "%i %i %i %i ", &U, &L, &D, &R);
	
	if (config != NULL) fclose(config);


	Filter *MyFilter;
	MyFilter = new FilterRed(U, L, D, R, &studTool);

//	MyFilter = new FilterWhiteBlack(U, L, D, R, &studTool);


	/*switch (std::stoi(filter_name))
	{
	case (std::stoi("Red")): {break; }
	case "ThresHold": {break; }
	case "Blur": {break; }
	case "Edge": {break; }
	}*/

	MyFilter->MakeAction();

	studTool.save(argv[3]);
	//studTool.save("Darya.jpg");
	
	delete MyFilter;
	printf("Complete!\n");
    return 0;
}
