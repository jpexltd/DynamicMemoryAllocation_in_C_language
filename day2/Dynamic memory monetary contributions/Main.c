#include "Header.h"
int main()
{
	int nelem, i, position;
	float *p, *paux;
	printf("Number of elements ? \n");
	scanf("%d", &nelem);
	p = CreateArray(nelem);

	printf("Please, enter the amounts of money:\n\n");
	for (i = 0; i<nelem; i++)
		scanf("%f", &p[i]);

	DisplayInfo(p, nelem);

	printf("Please, enter the two new amounts of money\n\n");
	for (i = 0; i <= 1; i++)
	{
		paux = AddElement(p, &nelem);
		if (paux == NULL)
		{
			printf("Error adding the new element\n");
			return -1;
		}
		else
			p = paux;
	}

	DisplayInfo(p, nelem);

	do
	{
		printf("\n\nPlease enter the position of the element to be deleted (0 to %d)\n\n", nelem - 1);
		scanf("%d", &position);
	} while ((position < 0) || (position>nelem-1));

	DeleteElement(p, &nelem, position);

	DisplayInfo(p, nelem);

	free(p);
	MemoryManager_DumpMemoryLeaks();
	system("pause");
	return 0;
}
