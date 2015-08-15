#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MemoryManager.h"


// CONSTANT DEFINITION

#define MAX_CHARAC_NAME	20
#define MAX_CHARAC_DESCR	100
#define MAX_CHARAC_FUNC	100

// GLOBAL VARIABLES = EXCEPCIONAL CASE
// strings to show the names of the enumerate types
// in order to make easier the entrance of data

char BodyParts[3][15];
char MuscleTypes[3][15];

// DATA TYPE DEFINITION

typedef enum
{
	head, trunk, extremities
}tBodyParts;

typedef enum
{
	estriated, smooth, cardiac
}tMuscleType;

typedef struct
{
	char name[MAX_CHARAC_NAME];
	char description[MAX_CHARAC_DESCR];
	tBodyParts location;
	int length;
}tCommonInfo;


typedef struct
{
	tCommonInfo commonInfo;
	tMuscleType type;
	char function[MAX_CHARAC_FUNC];
}tMuscle;


typedef struct
{
	tCommonInfo commonInfo;
	float density;
	int nMusc;
	tMuscle **ppMusc;
}tBone;

int Menu();
IniGlobalStrings();
int AddBone(tBone **, int, tMuscle *);
tMuscle *AddMuscle(tMuscle *, int *, tBone *, int);
void LinkBone(tBone *, tMuscle *, int);
tCommonInfo ReadCommomnInfo();
tMuscle ReadMuscle();
tMuscle **ReadBone(tBone *);
void PrintCommonInfo(tCommonInfo);
void PrintBone(tBone);
void PrintMuscle(tMuscle );
void MusclesLengthArea(tBone *, int, int, int);
float CalculateBoneDensity(tBone *, int, int);
void FreeMemory(tBone *, int, tMuscle *);

