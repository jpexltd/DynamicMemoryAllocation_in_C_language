#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "MemoryManager.h"

float * CreateArray(int nelem);
float *AddElement(float *p, int *pnelem);
void DeleteElement(float *p, int *pnelem, int pos);
void DisplayInfo(float * paux, int nelem);
