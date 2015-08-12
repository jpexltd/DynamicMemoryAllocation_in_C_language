#include "Header Menu.h"

int Remainer_of_division(int datum1, int datum2)
{
	int c;
	c = datum1 % datum2;
	return c;
}

int Largest(int datum1, int datum2)
{
	int c;
	if (datum1 > datum2)
		c = datum1;
	else
		c = datum2;
	return c;
}

int Smallest(int datum1, int datum2)
{
	int c;
	if (datum1 < datum2)
		c = datum1;
	else
		c = datum2;
	return c;
}

void Display(int datum1, int datum2)
{
	printf("\n Los read numbers are: %d y %d\n\n", datum1, datum2);
}
