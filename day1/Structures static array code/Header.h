#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#define NS	100
#define	MAX_CHARAC	60
typedef struct
{
	char name[MAX_CHARAC];
	float mark;
}tcard;

void ReadCard (tcard *);