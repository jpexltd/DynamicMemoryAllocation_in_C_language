#include "Header.h"

int main()
{
	tcard students[NS];
	int j = 0, i = 0, pass = 0, fail = 0;
	char car = 'y';
	
	printf("Enter data.\n\n");
	

	for (i = 0; i < NS && car=='y'; i++)
	{ 

		ReadCard(&students[i]);  //ReadCard(students+i);
		do
		{
			printf("Would you like to enter another student card? (y/n)\n");
			car = tolower (getchar());
			fflush(stdin);
		} while (car != 'y' && car != 'n');
	}

	for (j = 0; j<i; j++)
		if (students[j].mark >= 5)
			pass++;
		else
			fail++;
	printf("Pass %.3f%%\n", (float)pass / i * 100);
	printf("Fail %.3f%%\n", (float)fail / i * 100);
	system("pause");
	return 0;
}
