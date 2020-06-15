/**
	@author Levente Löffler
	@version 1.0.0 6/12/2020

	Implementation of the display module.
*/

#include "display.h"
#include <stdio.h>

void display(map_data* sMap)
{
	for (short s = 0; s < sMap->y * 2 - 1; s++) //this column naming part needs to be rethought.
		if (s % 2 == 0)
			printf("%d", s / 2 + 1); //when going above single digit numbers, the headers dont line up with the columns
		else
			printf(" ");

	printf("\n");

	for (short s = 0; s < sMap->y * 2 - 1; s++)
		printf(" ");

	printf("\n");

	for (char c = 0; c < sMap->x; c++)
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