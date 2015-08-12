#include "Header.h"

float * CreateArray(int nelem)
{
	float *p;
	p = (float *)malloc(nelem*sizeof(float));
	if (p == NULL)
	{
		printf("Error allocating memory");
		exit(-1);
	}
	else
		return p;
}

float *AddElement(float *p, int *pnelem)
{
	float *paux=NULL;
	paux = (float *)realloc(p, (*pnelem + 1) * sizeof(float));
	if (paux != NULL)
	{
		scanf("%f", &paux[*pnelem]);
		(*pnelem)++;
	}
	return paux;
}

void DeleteElement(float *p, int *pnelem, int pos)
{
	int i;
	for (i = pos; i < *pnelem - 1; i++)
		p[i] = p[i + 1];

	p = (float *)realloc(p, (*pnelem - 1) * sizeof(float));
	(*pnelem)--;
}



void DisplayInfo(float * paux, int nelem)
{
	int i;
	float total = 0;
	printf("The elements of the array are:\n\n");
	for (i = 0; i < nelem; i++)
	{
		printf("\n\t%.2f  ", paux[i]);
		total += paux[i];
	}
	printf("\n\nThe total amount collected is: %.2f", total);
	printf("\n\n");
}