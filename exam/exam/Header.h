#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MemoryManager.h"

#define MAX_CHARAC_NAME	20
#define MAX_CHARAC_TITLE 30

typedef struct
{
	char title[MAX_CHARAC_TITLE]; // Example: "THE ESSENTIAL"
	int year;
	char nameAuthor[MAX_CHARAC_NAME];
	int numSongs; // The songs number
	char ** ppSong; // The songs name
}tDisc;

int Menu();
tDisc *AddDisc(tDisc *pDisc, int *nDiscs);
tDisc ReadDisc();
char **AddSongs(char ** ppSong, int numSongs);
void ReadSong(char *song);
void AllDiscsDisplay(tDisc *p, int n);
void SingleDiscDisplay(tDisc *p, int pos);
void SongsDisplay(char **ppSong, int numSongs);
int LookForDiscByAuthor(tDisc * pDisc, int nDisc);
void PrintDiscsOfAuthor(tDisc *pDisc, int nDiscs);
int DeleteDisc(tDisc *pDisc, int *pnDiscs);
int LookForDisc(tDisc *pDisc, int nDiscs);
void FreeMemory(tDisc *pDisc, int nDiscs);