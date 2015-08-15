#include "Header.h"

tDisc *AddDisc(tDisc *pDisc, int *nDiscs)
{
	tDisc *paux;
	paux = (tDisc *)realloc(pDisc, (*nDiscs + 1)*sizeof(tDisc));
	if (paux != NULL)
	{
		paux[*nDiscs] = ReadDisc();
		(*nDiscs)++;
	}
	return paux;
}

tDisc ReadDisc()
{
	tDisc disc;

	printf("\n\tEnter the disc title: ");
	fflush(stdin);
	fgets(disc.title, MAX_CHARAC_TITLE, stdin);
	printf("\n\tEnter the author name: ");
	fflush(stdin);
	fgets(disc.nameAuthor, MAX_CHARAC_NAME, stdin);
	//Get number of songs from user
	printf("\n\tEnter the year of release: ");
	fflush(stdin);
	scanf("%d", &disc.year);
	printf("\n\tEnter the total number of songs in the disc: ");
	fflush(stdin);
	scanf("%d", &disc.numSongs);
	disc.ppSong = AddSongs(*disc.ppSong, disc.numSongs);

	return disc;
}

char ** AddSongs(char * ppSong, int numSongs)
{
	char *paux[MAX_CHARAC_NAME], song[MAX_CHARAC_NAME];
	int i, j;
	for (i = 0; i < numSongs; i++){
		printf("\n\tName of the song: "); 
		fflush(stdin);
		fgets(song, MAX_CHARAC_NAME, stdin);
		paux[i] = (char *)malloc(strlen(song) + 1);
		if (paux[i] == NULL)
		{
			printf("Error allocating memory\n");
			for (j = 0; j < i; j++)
				free(paux[j]);
			system("pause");
			return -1;
		}
		strcpy(paux[i], song);
	}
	return paux;
}

void ReadSong(char *song)
{
	printf("\n\tName of the song: ");
	fflush(stdin);
	fgets(song, MAX_CHARAC_NAME, stdin);
}

void AllDiscsDisplay(tDisc *p, int n)
{
	int i;

	printf("\n\nDisplay of the information of the discs\n");
	printf("===================================\n\n");
	for (i = 0; i < n; i++)
	{
		SingleDiscDisplay(p,i);
	}
}

void SingleDiscDisplay(tDisc *p, int pos)
{
	printf("\nDisc num %d\n", pos + 1);
	printf("\n\tTitle: %s", p[pos].title);
	printf("\n\tYear: %d", p[pos].year);
	printf("\n\tAuthor name: %s", p[pos].nameAuthor);
	SongsDisplay(p[pos].ppSong, p[pos].numSongs);
}

void SongsDisplay(char **ppSong, int numSongs)
{
	int i;

	printf("\n\tSongs\n");
	printf("===================================\n\n");

	for (i = 0; i < numSongs; i++)
	{
		printf("\n\tSong %d\n", i + 1);
		printf("\n\t\tName: %s", *ppSong[i]);
		printf("__________________________\n");
	}
}

int LookForDiscByAuthor(tDisc * pDisc, int nDisc)
{
	int i;
	char name[MAX_CHARAC_NAME];

	printf("Please enter the name of the author whose albums you are looking for: ");
	fflush(stdin);
	fgets(name, MAX_CHARAC_NAME, stdin);

	for (i = 0; i < nDisc; i++)
	{
		if (strcmp(pDisc[i].nameAuthor, name) == 0)
			return i;
	}
	printf("This author does not exist\n");
	system("pause");
	return -1;
}

void PrintDiscsOfAuthor(tDisc *pDisc, int nDiscs)
{
	int pos;
	pos = LookForDiscByAuthor(pDisc, nDiscs);
	if (pos != -1) {
		SingleDiscDisplay(pDisc, pos);
	}
}

int DeleteDisc(tDisc *pDisc, int *pnDiscs)
{
	int pos, i;
	pos = LookForDisc(pDisc, *pnDiscs);
	if (pos != -1) {
		for (i = pos; i < *pnDiscs - 1; i++) {
			pDisc[i] = pDisc[i + 1];
		}
		free(pDisc[(*pnDiscs) - 1].ppSong);
		pDisc = (tDisc *)realloc(pDisc, (*pnDiscs - 1) * sizeof(tDisc));
		(*pnDiscs)--;
	}
}

int LookForDisc(tDisc *pDisc, int nDiscs)
{
	int i;
	char title[MAX_CHARAC_TITLE];

	printf("Please enter the title of the album you want to delete: ");
	fflush(stdin);
	fgets(title, MAX_CHARAC_TITLE, stdin);

	for (i = 0; i < nDiscs; i++)
	{
		if (strcmp(pDisc[i].title, title) == 0)
			return i;
	}
	printf("This title does not exist\n");
	system("pause");
	return -1;
}

void FreeMemory(tDisc *pDisc, int nDiscs)
{
	int i;
	if (pDisc != NULL)
	{
		for (i = 0; i < nDiscs; i++)
			if (pDisc[i].ppSong != NULL)
				free(pDisc[i].ppSong);
		free(pDisc);
	}
}


