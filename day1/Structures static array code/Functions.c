#include "Header.h"

void ReadCard(tcard *pCard)
{
	printf("Name:\t");
	fgets(pCard->name,60,stdin);
	printf("Mark\t");
	scanf("%f", &pCard->mark);
	fflush(stdin); 
}