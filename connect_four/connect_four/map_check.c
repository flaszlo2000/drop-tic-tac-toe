/**
	@author Levente Löffler
	@author László Fazekas
	@version 1.0.0 6/14/2020

	Implementation of the map_check module.
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
	bool ret = false;
	for (char c = 0; c < sMap->x; c++)
		for (char d = 0; d < sMap->y; d++)
			if (sMap->pMap[c][d] == (nRound % 2 ? '1' : '0'))
			{
				if (d + 3 < sMap->y)
					if (sMap->pMap[c][d + 1] == sMap->pMap[c][d] && sMap->pMap[c][d + 2] == sMap->pMap[c][d] && sMap->pMap[c][d + 3] == sMap->pMap[c][d])
					{
						for (char e = d; e <= d + 3; e++)
							sMap->pMap[c][e] = '-';
						ret = true;
					}
				if (c + 3 < sMap->x && d + 3 < sMap->y)
					if (sMap->pMap[c + 1][d + 1] == sMap->pMap[c][d] && sMap->pMap[c + 2][d + 2] == sMap->pMap[c][d] && sMap->pMap[c + 3][d + 3] == sMap->pMap[c][d])
					{
						for (char e = c, f = d; e <= c + 3 && f <= d + 3; e++, f++)
							sMap->pMap[e][f] = '\\';
						ret = true;
					}
				if (c + 3 < sMap->x)
					if (sMap->pMap[c + 1][d] == sMap->pMap[c][d] && sMap->pMap[c + 2][d] == sMap->pMap[c][d] && sMap->pMap[c + 3][d] == sMap->pMap[c][d])
					{
						for (char e = c; e <= c + 3; e++)
							sMap->pMap[e][d] = '|';
						ret = true;
					}
				if (c + 3 < sMap->x && d - 3 > 0)
					if (sMap->pMap[c + 1][d - 1] == sMap->pMap[c][d] && sMap->pMap[c + 2][d - 2] == sMap->pMap[c][d] && sMap->pMap[c + 3][d + 3] == sMap->pMap[c][d])
					{
						for (char e = c, f = d; e <= c + 3 && f >= d - 3; e++, f--)
							sMap->pMap[e][f] = '/';
						ret = true;
					}
				if (ret)
					break;
			}
	return ret;
}