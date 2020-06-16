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
	for (unsigned char c = 0; c < sMap->x; c++)
		for (unsigned char d = 0; d < sMap->y; d++)
			if (sMap->pMap[c][d] == '0')
				return false;
	return true;
}

bool check_win(game_data* sGame, char nTurn)
{
	bool ret = false;

	for (unsigned char c = 0; c < sGame->map.x; c++)
		for (unsigned char d = 0; d < sGame->map.y; d++)
			if (sGame->map.pMap[c][d] == (nTurn % 2 ? '1' : '2'))
			{
				bool lWin = true;
				if (d + sGame->lLength - 1 < sGame->map.y)
				{
					for (unsigned char e = d + 1; e < d + sGame->lLength; e++)
						if (sGame->map.pMap[c][e] != sGame->map.pMap[c][d])
						{
							lWin = false;
							break;
						}

					if (lWin)
						for (unsigned char e = d; e < d + sGame->lLength; e++)
						{
							sGame->map.pMap[c][e] = '-';
							ret = true;
						}
				}

				lWin = true;
				if (c + sGame->lLength - 1 < sGame->map.x && d + sGame->lLength - 1 < sGame->map.y)
				{
					for (unsigned char e = c + 1, f = d + 1; e < c + sGame->lLength && f < d + sGame->lLength; e++, f++)
						if (sGame->map.pMap[e][f] != sGame->map.pMap[c][d])
						{
							lWin = false;
							break;
						}

					if (lWin)
						for (unsigned char e = c, f = d; e < c + sGame->lLength && f < d + sGame->lLength; e++, f++)
						{
							sGame->map.pMap[e][f] = '\\';
							ret = true;
						}
				}

				lWin = true;
				if (c + sGame->lLength - 1 < sGame->map.x)
				{
					for (unsigned char e = c + 1; e < c + sGame->lLength; e++)
						if (sGame->map.pMap[e][d] != sGame->map.pMap[c][d])
						{
							lWin = false;
							break;
						}

					if (lWin)
						for (unsigned char e = c; e < c + sGame->lLength; e++)
						{
							sGame->map.pMap[e][d] = '|';
							ret = true;
						}
				}

				lWin = true;
				if (c + sGame->lLength - 1 < sGame->map.x && d - sGame->lLength + 1 > 0)
				{
					for (unsigned char e = c + 1, f = d - 1; e < c + sGame->lLength && f > d - sGame->lLength; e++, f--)
						if (sGame->map.pMap[e][f] != sGame->map.pMap[c][d])
						{
							lWin = false;
							break;
						}

					if (lWin)
						for (unsigned char e = c, f = d; e < c + sGame->lLength && f > d - sGame->lLength; e++, f--)
						{
							sGame->map.pMap[e][f] = '/';
							ret = true;
						}
				}

				if (ret)
					break;
			}

	return ret;
}