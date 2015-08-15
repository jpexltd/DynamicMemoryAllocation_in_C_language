#include "Header.h"
int main()
{
	int operation, nDiscs = 0;
	tDisc *pDisc = NULL, *pDisc_aux;

	while ((operation = Menu()) != 5)
	{
		switch (operation)
		{
		case 1:
			pDisc_aux = AddDisc(pDisc, &nDiscs);
			if (pDisc_aux == NULL)
			{
				printf("Error allocating memory\n");
				system("pause");
				FreeMemory(pDisc, nDiscs);
				return -1;
			}
			pDisc = pDisc_aux;
			break;
		case 2:
			// Display information of the discs
			AllDiscsDisplay(pDisc, nDiscs);
			system("pause");
			break;
		case 3:
			// 3. Display the discs of an author using his name
			PrintDiscsOfAuthor(pDisc, nDiscs);
			break;
		case 4:
			// 4. Delete disc
			DeleteDisc(pDisc, &nDiscs);
			break;
		}
	}

	FreeMemory(pDisc, nDiscs);
	MemoryManager_DumpMemoryLeaks();
	system("pause");
	return 0;
}

int Menu()
{
	int op;
	do
	{
		system("cls");
		printf("\t1. Add disc\n");
		printf("\t2. Display information of the discs\n");
		printf("\t3. Display the discs of an author using his name\n");
		printf("\t4. Delete disc\n");
		printf("\t5. Exit\n");
		printf("\n Select one option\n\n");
		scanf("%d", &op);
	} while (op < 1 || op > 5);
	return op;
}