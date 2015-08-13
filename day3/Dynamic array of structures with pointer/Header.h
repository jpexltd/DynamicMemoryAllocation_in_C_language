#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MemoryManager.h"
#define MAX_NUM_CHARAC	20

typedef struct
{
	char  name[20];
	int   year;
	float mark;
}tSubject;

typedef struct
{
	char  name[20];
	int   ID;
	int   nSubjects;
	tSubject *pSubject;
}tStudent;

int Menu();
tStudent *AddStudent(tStudent *p, int *pn);
tStudent ReadStudent();
int LookForStudentByID(tStudent *p, int n);
tSubject *AddSubject(tStudent *p, int pos);
void ReadSubject(tSubject *pSubject);
void SubjectsDisplay(tSubject *p, int n);
void StudentsDisplay(tStudent *p, int n);
float CalculateAverage1Stu(tStudent *p, int pos);
float CalculateAverageAllStu(tStudent *p, int n);
void FreeMemory(tStudent *p, int n);