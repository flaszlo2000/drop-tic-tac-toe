/**
	@author Levente Löffler
	@version 1.0.5 6/16/2020

	Implementation of the display module.
*/

#include "display.h"
#include <stdio.h>

void display(map_data* sMap)
{
	for (short s = 0; s < sMap->y * 2 - 1; s++)
		if (s % 2 == 0)
			printf("%c", s / 2 + 65);
		else
			printf(" ");

	printf("\n");

	for (short s = 0; s < sMap->y * 2 - 1; s++)
		printf(" ");

	printf("\n");

	for (unsigned char c = 0; c < sMap->x; c++)
	{
		for (short s = 0; s < sMap->y * 2 - 1; s++)
			if (s % 2 == 0)
				printf("%c", sMap->pMap[c][s / 2]);
			else
				printf(" ");
		printf("\n");
	}
		
	printf("\n");
}