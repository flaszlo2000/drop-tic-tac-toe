//ez csak msvc-nek kell, de a gcc nem bánja
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>



//adatszerkezet a tornához
struct torna
{
	unsigned char nRounds;
	unsigned char nP1_wins;
};



//általános adatszerkezet
struct data
{
	unsigned char nPlayers;
	struct torna* torna;
};



//adatok beolvasása és tárolása
void init(struct data* game_data)
{
	//játékosszám
	printf("pls player numero\n");

	while (1)
	{
		scanf("%hhu", &game_data->nPlayers);

		if (game_data->nPlayers != 0 && game_data->nPlayers != 1 && game_data->nPlayers != 2)
		{
			printf("wtf\n");
			continue;
		};

		break;
	}


	//torna-e, és ha igen, hány menetes
	printf("pls torna numero\n");
	while (1)
	{
		unsigned char torna;
		scanf("%hhu", &torna);

		if (torna < 0)
		{
			printf("wtf2");
			continue;
		}

		if (!torna)
			game_data->torna = NULL;
		else
		{
			game_data->torna = malloc(sizeof(struct torna));
			game_data->torna->nRounds = torna;
			game_data->torna->nP1_wins = 0;
		}

		break;
	}
}



int main()
{
	struct data game_data;

	init(&game_data);

	//game_loop();

	//epilogue_function();

	free(game_data.torna);

	return 0;
}