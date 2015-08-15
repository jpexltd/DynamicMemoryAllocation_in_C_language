#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MemoryManager.h"

#define	MAX_CHARAC_NAME	20
#define MAX_CHARAC_TITLE	30

typedef struct
{
	char title[MAX_CHARAC_TITLE];    // Example: "THE ESSENTIAL"
	int year;
	char nameAuthor[MAX_CHARAC_NAME];        
	int numSongs;     // The songs number
	char ** ppSong;    // The songs name
}tDisc;


void ReadSongs(tDisc disc);
char ** ReadDisc(tDisc *pDisc);
int AddDisc(tDisc **ppDisc, int n);
void PrintSongs(tDisc disc);
void PrintDisc(tDisc disc);
void PrintDiscsOfAuthor(tDisc *pDisc, int nDiscs);
int DeleteDisc(tDisc *pDisc, int *pnDiscs);
void FreeMemory(tDisc *pDisc, int nDiscs);
int Menu();