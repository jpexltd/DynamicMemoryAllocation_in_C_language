#include "Header.h"
int main()
{
	int operation, nBones = 0, nMuscles = 0, i,j, length, area;
	float density;
	tBone *pBone = NULL;
	tMuscle *pMuscle = NULL;
	
	IniGlobalStrings();
	while ((operation = Menu()) != 8)
	{
		switch (operation)
		{
		case 1:
			
			nBones = AddBone(&pBone, nBones, pMuscle);

			/* Read the data for the bone and allocate memory 
			   for the pointer to pointer to tMuscle */

			pBone[nBones-1].ppMusc = ReadBone(&pBone[nBones - 1]);

			if (pBone[nBones - 1].ppMusc == NULL)
			{
				printf("Error allocating memory in the array of pointers to tMuscle\n");
				system("pause");
				FreeMemory(pBone, nBones, pMuscle);
				return -1;
			}
			/*Link the pointers of the array of pointer with the corresponding
			  muscle in the array of muscles */
			  
			LinkBone(&pBone[nBones - 1], pMuscle, nMuscles);

			break;
		case 2:
			
			pMuscle = AddMuscle(pMuscle, &nMuscles, pBone, nBones);
			pMuscle[nMuscles - 1] = ReadMuscle();
			break;
		case 3:
			printf("\n\n Bone data:\n");
			printf("==============\n\n");
			for (i = 0; i < nBones; i++)
			{
				printf("Bone %d\n", i+1);
				PrintBone(pBone[i]);
			}
			system("pause");
			break;
		case 4:
			printf("\n\n Muscle data:\n");
			printf("==============\n\n");
			for (i = 0; i < nMuscles; i++)
			{
				printf("Muscle %d\n", i + 1);
				PrintMuscle(pMuscle[i]);
			}
			system("pause");
			break;
		case 5:
			for (i = 0; i < nBones; i++)
			{
				printf("Bone %d\n", i + 1);
				printf("==============\n\n");
				PrintBone(pBone[i]);
				printf("\nMuscles associated\n");
				for (j = 0; j < pBone[i].nMusc; j++)
				{
					/* In case the pointer to the muscle is not pointing 
					   to any muscle, his value will be NULL and it cannot
					   be passed the content of the pointer*/
					if (pBone[i].ppMusc[j] != NULL)
						PrintMuscle(*(pBone[i].ppMusc[j]));
				}
			}
			system("pause");
			break;
		case 6:
			printf("\nPlease, enter the lenght: ");
			scanf("%d", &length);

			printf("\nArea of the body (0: head, 1: trunk, 2: extremities): ");
			scanf("%d", &area); 
			MusclesLengthArea(pBone, nBones, length, area);
			system("pause");
			break;
		case 7:
			printf("\nArea of the body (0: head, 1: trunk, 2: extremities): ");
			scanf("%d", &area);
			density = CalculateBoneDensity(pBone, nBones, area);
			printf("\n\nThe density of this area is: %.2f\n", density);
			system("pause");
			break;
		}
	}

	FreeMemory(pBone, nBones, pMuscle);

	MemoryManager_DumpMemoryLeaks();
	system("pause");
}

int Menu()
{
	int op;
	do
	{
		system("cls");
		printf("\t1. Add bone\n");
		printf("\t2. Add muscle\n");
		printf("\t3. Print bones\n");
		printf("\t4. Print muscles\n");
		printf("\t5. Print both arrays connected\n");
		printf("\t6. Muscles of an area of the body, which length is less than a value\n");
		printf("\t7. Calculate bone density\n");
		printf("\t8. Exit\n");
		printf("\n Please select one option of one area of the body\n\n");
		scanf("%d", &op);
	} while (op < 1 || op > 8);
	return op;
}