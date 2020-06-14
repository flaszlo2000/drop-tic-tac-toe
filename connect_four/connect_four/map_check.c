/**
	@author Levente Löffler
	@version 1.0.0 6/14/2020
*/

#include "map_check.h"
#include <stdio.h>

bool check_draw(map_data* sMap)
{
	for (char c = 0; c < sMap->x; c++)
		for (char d = 0; d < sMap->y; d++)
			if (sMap->pMap[c][d] == '0')
				return false;
	return true;
}

bool check_win(map_data* sMap, char nRound)
{
	for (char c = 0; c < sMap->x; c++)
		for (char d = 0; d < sMap->y; d++)
			if (sMap->pMap[c][d] == (nRound % 2 ? '1' : '0'))
			{
				if (d + 3 < sMap->y)
					if (sMap->pMap[c][d + 1] == sMap->pMap[c][d] && sMap->pMap[c][d + 2] == sMap->pMap[c][d] && sMap->pMap[c][d + 3] == sMap->pMap[c][d])
					{
						return true;
					}
				if (c + 3 < sMap->x && d + 3 < sMap->y)
					if (sMap->pMap[c + 1][d + 1] == sMap->pMap[c][d] && sMap->pMap[c + 2][d + 2] == sMap->pMap[c][d] && sMap->pMap[c + 3][d + 3] == sMap->pMap[c][d])
					{
						return true;
					}
				if (c + 3 < sMap->x)
					if (sMap->pMap[c + 1][d] == sMap->pMap[c][d] && sMap->pMap[c + 2][d] == sMap->pMap[c][d] && sMap->pMap[c + 3][d] == sMap->pMap[c][d])
					{
						return true;
					}
				if (c + 3 < sMap->x && d-3 > 0)
					if (sMap->pMap[c + 1][d - 1] == sMap->pMap[c][d] && sMap->pMap[c + 2][d - 2] == sMap->pMap[c][d] && sMap->pMap[c + 3][d + 3] == sMap->pMap[c][d])
					{
						return true;
					}
			}
	return false;
}