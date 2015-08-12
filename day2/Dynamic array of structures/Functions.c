#include "Header.h"

void ReadStudent(tcard *p)
{
	printf("\n\tName: ");
	fflush(stdin);
	fgets(p->name, MAX_NUM_CHARAC,stdin); // (*p).name
	printf("\n\tMark: ");
	scanf("%f", &(*p).mark); // &p->mark
}

void DisplayStudents(tcard *pcard, int n)
{
	int i;

	printf("\n\nDisplay of the data\n");
	printf("===================================\n\n");

	for (i = 0; i < n; i++)
	{
		printf("\nStudent %d\n", i + 1);      
		printf("\n\tName: %s", pcard[i].name);
		printf("\n\tMark: %.2f", pcard[i].mark);
	}
	printf("\n\n");
}

tcard * AddStudent(tcard *p, int *pn)
{
	int pos, i;
	tcard *paux=p;

	paux = (tcard *)realloc(p, (*pn + 1)*sizeof(tcard));
	if (paux != NULL)
	{
		do
		{
			printf("\nWhich position do you like to add the student? (0 to %d)", *pn);
			scanf("%d", &pos);
		} while ((pos<0) || (pos>*pn));
		for (i = *pn - 1; i >= pos; i--)
			paux[i + 1] = paux[i];
		ReadStudent(&paux[pos]);
		(*pn)++;
	}
	return paux;
}
