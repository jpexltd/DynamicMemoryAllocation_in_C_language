#include "Header Menu.h"
int main()
{
	int datum1, datum2, result, operation;
	while ((operation = Menu()) != 5)
	{
		printf("\nEnter datum1: ");
		scanf("%d", &datum1);
		printf("\nEnter datum2: ");
		scanf("%d", &datum2);
		switch (operation)
		{
		case 1:
			result = Remainer_of_division(datum1, datum2);
			break;
		case 2:
			result = Largest(datum1, datum2);
			break;
		case 3:
			result = Smallest(datum1, datum2);
			break;
		case 4:
			Display(datum1, datum2);
			break;
		}
		if (operation != 4)
			printf("\nResul: %d\n", result);
		system("pause");
	}
	return 0;
}

int Menu()
{
	int op;
	do
	{
		system("cls");
		printf("\t1. Remainer of the division\n");
		printf("\t2. Largest\n");
		printf("\t3. Smallest\n");
		printf("\t4. Display\n");
		printf("\t5. Quit\n");
		printf("\n Please select one option\n\n");
		scanf("%d", &op);
	} while (op < 1 || op > 5);
	return op;
}