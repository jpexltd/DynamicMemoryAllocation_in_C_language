#include "Header.h"
int main()
{
	int operation, nStudents=0, position;
	float average = 0.0;
	tStudent *pStudent=NULL, *pStud_aux;
	tSubject *pSubj_aux;

	while ((operation = Menu()) != 6)
	{
		switch (operation)
		{
		case 1:
			pStud_aux = AddStudent(pStudent, &nStudents);
			if (pStud_aux == NULL)
			{
				printf("Error allocating memory\n");
				system("pause");
				FreeMemory(pStudent, nStudents);
				return -1;
			}
			pStudent = pStud_aux;
			break;
		case 2:
			position = LookForStudentByID(pStudent, nStudents);
			if (position != -1)
			{
				pSubj_aux = AddSubject(pStudent, position);
				if (pSubj_aux == NULL)
				{
					printf("Error allocating memory\n");
					system("pause");
					FreeMemory(pStudent, nStudents);
					return -1;
				}
				else
					pStudent[position].pSubject = pSubj_aux;
			}
			break;
		case 3:
			position = LookForStudentByID(pStudent, nStudents);
			if (position != -1)
			{
				average = CalculateAverage1Stu(pStudent, position);
				printf("\n\n The mark average for the student: %s is %.2f\n", pStudent[position].name, average);
			}
			system("pause");
			break;
		case 4:
			average = CalculateAverageAllStu(pStudent, nStudents);
			printf("\n\n The mark average for all the student is: %.2f\n", average);
			system("pause");
			break;
		case 5:
			StudentsDisplay(pStudent, nStudents);
			system("pause");
			break;
		}
	}

	FreeMemory(pStudent, nStudents);
		
	MemoryManager_DumpMemoryLeaks();
	system("pause");
}

int Menu()
{
	int op;
	do
	{
		system("cls");
		printf("\t1. Add student\n");
		printf("\t2. Add subject by ID of the student\n");
		printf("\t3. Calculate the marks average of one student\n");
		printf("\t4. Calculate the marks average of the all students\n");
		printf("\t5. DataDisplay\n");
		printf("\t6. Exit\n");
		printf("\n Select one option\n\n");
		scanf("%d", &op);
	} while (op < 1 || op > 6);
	return op;
}