#include "Header.h"

tStudent *AddStudent(tStudent *p, int *pn)
{
	tStudent *paux;
	paux = (tStudent *)realloc(p, (*pn + 1)*sizeof(tStudent));
	if (paux != NULL)
	{
		paux[*pn] = ReadStudent();
		(*pn)++;
	}
	return paux;
}
tStudent ReadStudent()
{
	tStudent student;

	printf("\n\tName: ");
	fflush(stdin);
	fgets(student.name, MAX_NUM_CHARAC, stdin); 
	printf("\n\tID: ");
	scanf("%d", &student.ID); 
	//Initially the number of subjects is 0
	student.nSubjects = 0;
	student.pSubject = NULL;

	return student;
}

int LookForStudentByID(tStudent *p, int n)
{
	int i, ID;

	printf("Please enter the ID of the student: ");
	scanf("%d", &ID);

	for (i = 0; i < n; i++)
	{
		if (p[i].ID == ID)
			return i;
	}
	printf("This student does not exist\n");
	system("pause");
	return -1;
}

tSubject *AddSubject(tStudent *p, int pos)
{
	int nsubjects;
	tSubject *paux;

	paux = p[pos].pSubject;
	nsubjects = p[pos].nSubjects;
	paux = (tSubject *)realloc(paux, (nsubjects+1)*sizeof(tSubject));
	if (paux != NULL)
	{
		ReadSubject(&paux[nsubjects]);
		p[pos].nSubjects++;
	}
	return paux;
}

void ReadSubject(tSubject *pSubject)
{
	printf("\n\tName: ");
	fflush(stdin);
	fgets(pSubject->name, MAX_NUM_CHARAC, stdin);
	printf("\n\tYear: ");
	scanf("%d", &pSubject->year);
	printf("\n\tMark: ");
	scanf("%f", &pSubject->mark);
}

void SubjectsDisplay(tSubject *p, int n)
{
	int i;

	printf("\n\tSubjects\n");
	printf("===================================\n\n");

	for (i = 0; i < n; i++)
	{
		printf("\n\tSubject %d\n", i + 1);
		printf("\n\t\tName: %s", p[i].name);
		printf("\n\t\tYear: %d", p[i].year);
		printf("\n\t\tMarka: %.2f", p[i].mark);
		printf("\n");
		printf("__________________________\n");
	}
}

void StudentsDisplay(tStudent *p, int n)
{
	int i;

	printf("\n\nDisplay of the data\n");
	printf("===================================\n\n");

	for (i = 0; i < n; i++)
	{
		printf("\nStudent %d\n", i + 1);
		printf("\n\tName: %s", p[i].name);
		printf("\n\tID: %d", p[i].ID);
		printf("\n\tNumber of subjects: %d", p[i].nSubjects);
		SubjectsDisplay(p[i].pSubject, p[i].nSubjects);
	}
}

float CalculateAverage1Stu(tStudent *p, int pos)
{
	int i;
	float total=0.0;
	for (i = 0; i < p[pos].nSubjects; i++)
	{
		total += p[pos].pSubject[i].mark;
	}
	return total / p[pos].nSubjects;
}

float CalculateAverageAllStu(tStudent *p, int n)
{
	int i, j, totalSub=0;
	float totalMark = 0.0;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < p[i].nSubjects; j++)
		{
			totalMark += p[i].pSubject[j].mark;
			totalSub++;
		}
	}
	return totalMark / totalSub;
}

void FreeMemory(tStudent *p, int n)
{
	int i;
	if (p != NULL)
	{
		for (i = 0; i < n; i++)
			if (p[i].pSubject != NULL)
				free(p[i].pSubject);
		free(p);
	}
}


