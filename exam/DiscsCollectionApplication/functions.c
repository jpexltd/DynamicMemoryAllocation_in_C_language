#include "Header.h"

void ReadSongs(tDisc disc)
{
	int i,j;
	char name[MAX_CHARAC_NAME];
	printf("\nThere are %d songs\n", disc.numSongs);
	for (i = 0; i < disc.numSongs; i++)
	{
		printf("\nPlease enter a name for the song %d: \n", i+1);
		fflush(stdin);
		fgets(name, MAX_CHARAC_NAME, stdin);
		disc.ppSong[i] = (char *)malloc(strlen(name) + 1);
		if (disc.ppSong[i] == NULL)
		{
			printf("Error allocating memory\n");
			for (j = 0; j < i; j++)
				free(disc.ppSong[j]);
			system("pause");
			exit (-1);
		}
		strcpy(disc.ppSong[i], name);
	}
}

char ** ReadDisc(tDisc *pDisc)
{
	
	printf("\nTitle of the disc?: ");
	fflush(stdin);
	fgets(pDisc->title,MAX_CHARAC_TITLE,stdin);
	printf("\nYear?: ");
	scanf("%d", &pDisc->year);
	printf("\nName of the author?: ");
	fflush(stdin);
	fgets(pDisc->nameAuthor, MAX_CHARAC_NAME, stdin);
	printf("\nNumber of songs?: ");
	scanf("%d", &pDisc->numSongs);

	/*Allocating memory for the songs. We don't use
	an auxiliar pointer in this case because in this moment
	pDisc->ppSongs is not pointing to a valid address*/

	pDisc->ppSong = (char **)malloc(pDisc->numSongs*sizeof(char *));
	return pDisc->ppSong;
}

int AddDisc(tDisc **ppDisc, int n)
{
	tDisc *paux = *ppDisc;
	paux = (tDisc *)realloc(paux, (n + 1)*sizeof(tDisc));
	if (paux == NULL)
	{
		printf("\nError allocating memory\n");
		system("pause");
		FreeMemory(*ppDisc, n);
		exit(-1);
	}
	*ppDisc = paux;
	return (n + 1);
}

void PrintSongs(tDisc disc)
{
	int i;
	printf("\nSONGS");
	printf("\n_____\n");
	for (i = 0; i < disc.numSongs; i++)
		printf("\t Song %d: %s\n", i + 1, disc.ppSong[i]);
}

void PrintDisc(tDisc disc)
{
	printf("==================");
	printf("\n\tTitle: %s", disc.title);
	printf("\n\tYear: %d ", disc.year);
	printf("\n\tAuthor name: %s", disc.nameAuthor);
	printf("\n\tNumber of songs: %d \n", disc.numSongs);
}

void PrintDiscsOfAuthor(tDisc *pDisc, int nDiscs)
{
	int i, found=0;
	char name[MAX_CHARAC_NAME];
	printf("\nplease, enter the name of the author\n");
	fflush(stdin);
	fgets(name, MAX_CHARAC_NAME, stdin);
	for (i = 0; i < nDiscs; i++)
		if (!strcmp(name, pDisc[i].nameAuthor))
		{
			PrintDisc(pDisc[i]);
			found = 1;
		}
	if (found == 0)
		printf("\n\nThis author has not discs\n");
}

int LookForDisc(tDisc *pDisc, int nDiscs)
{
	int i;
	char title[MAX_CHARAC_TITLE];
	printf("\nTitle of the disc\n");
	fflush(stdin);
	fgets(title, MAX_CHARAC_TITLE, stdin);
	for (i = 0; i < nDiscs; i++)
		if (!strcmp(title, pDisc[i].title))
			return i;
	return -1;
}

int DeleteDisc(tDisc *pDisc, int *pnDiscs)
{
	int position, i;
	position = LookForDisc(pDisc, *pnDiscs);
	if (position != -1)
	{
		// freeing the allocated memory to the disc
		for (i = 0; i < pDisc[position].numSongs; i++)
			if (pDisc[position].ppSong[i] != NULL)
				free(pDisc[position].ppSong[i]);
		if (pDisc[position].ppSong != NULL)
			free(pDisc[position].ppSong);

		// moving the elements to the left side
		for (i = position; i < *pnDiscs - 1; i++)
			pDisc[i] = pDisc[i + 1];

		//Deleting the last pelement of the array
		pDisc = (tDisc *)realloc(pDisc, (*pnDiscs - 1)*sizeof(tDisc));
		(*pnDiscs)--;
		return 0;
	}
	else
		return -1;
}


void FreeMemory(tDisc *pDisc, int nDiscs)
{
	int i,j;
	if (pDisc != NULL)
	{
		for (i = 0; i < nDiscs; i++)
		{
			if (pDisc[i].ppSong != NULL)
			{
				for (j = 0; j < pDisc[i].numSongs; j++)
					if (pDisc[i].ppSong[j] != NULL)
						free(pDisc[i].ppSong[j]);
				free(pDisc[i].ppSong);
			}
		}
		free(pDisc);
	}
}