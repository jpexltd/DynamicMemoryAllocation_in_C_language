#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MemoryManager.h"
#define MAX_NUM_CHARAC	50
typedef struct
{
	char name[50];
	float mark;
}tcard;

void ReadStudent(tcard *p_alum);
void DisplayStudents(tcard *pcard, int n);
tcard * AddStudent(tcard *p, int *pn);