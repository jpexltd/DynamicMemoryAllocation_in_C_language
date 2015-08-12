#include "Header.h"
int main()
{
	int n_stud, i;
	tcard *p, *paux;

	printf("Please, enter the number of students\n");
	scanf("%d", &n_stud);

	if ((p = (tcard *)malloc(n_stud*sizeof(tcard))) == NULL)
	{
		printf("Error allocating memory\n");
		return -1;
	}

	for (i = 0; i<n_stud; i++)
	{
		printf("\nStudent %d\n", i + 1);
		ReadStudent(&p[i]);
	}

	DisplayStudents(p, n_stud);

	paux = AddStudent(p, &n_stud);
	if (paux == NULL)
	{
		printf("Error adding a new student\n");
		return -1;
	}
	else 
		p = paux;

	DisplayStudents(p, n_stud);

	free(p);
	MemoryManager_DumpMemoryLeaks();
	system("pause");
	return 0;
}