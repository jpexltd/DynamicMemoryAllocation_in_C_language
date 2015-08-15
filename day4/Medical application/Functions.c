#include "Header.h"

IniGlobalStrings()
{
	/* The names of the enumerates types
	   must have the same position on the enumerate type
	   than in the global array of string. This allows to
	   use the enumerate type as the index of the array 
	   to display the name*/
	strcpy(BodyParts[0], "head");
	strcpy(BodyParts[1], "trunk");
	strcpy(BodyParts[2], "extremities");
	strcpy(MuscleTypes[0], "estriated");
	strcpy(MuscleTypes[1], "smooth");
	strcpy(MuscleTypes[2], "cardiac");
}

tCommonInfo ReadCommonInfo()
{
	tCommonInfo common;
	printf("\nName: ");
	fflush(stdin);
	fgets(common.name, MAX_CHARAC_NAME, stdin);

	printf("\nLenght: ");
	scanf("%d", &common.length);

	printf("\nLocation on the body (0: head, 1: trunk, 2: extremities): ");
	scanf("%d", &common.location);
	fflush(stdin);

	printf("\nDescription (max. 100 characters): ");
	fflush(stdin);
	fgets(common.description, MAX_CHARAC_DESCR, stdin);

	return common;
}

tMuscle ReadMuscle()
{
	tMuscle muscle;

	muscle.commonInfo = ReadCommonInfo();

	printf("\nMuscle type(0: estriated, 1: smooth, 2: cardiac): ");
	scanf("%d", &muscle.type);
	fflush(stdin);

	printf("\nDescribe the function of the muscle (max. 100 characters): ");
	fgets(muscle.function, MAX_CHARAC_FUNC, stdin);

	return muscle;
}

tMuscle ** ReadBone(tBone *pBone)
{
	pBone->commonInfo = ReadCommonInfo();
	printf("\nDensity (value between 0 and 1): ");
	scanf("%f", &pBone->density);
	printf("\nHow many muscles associated?: ");
	scanf("%d", &pBone->nMusc);

	/*Allocating memory for the pointers to tMuscle array. We don't use 
	  an auxiliar pointer in this case because in this moment 
	  pBone->ppMusc is not pointing to a valid address*/ 

	pBone->ppMusc = (tMuscle **)malloc(pBone->nMusc*sizeof(tMuscle *));
	return pBone->ppMusc;
}


tMuscle *AddMuscle(tMuscle *pMuscle, int *pNumMuscles, tBone *pBone, int nBones)
{
	tMuscle *paux;
	paux = (tMuscle *)realloc(pMuscle, (*pNumMuscles + 1)*sizeof(tMuscle));
	if (paux == NULL)
	{
		printf("\nError allocating memory\n");
		system("pause");
		FreeMemory(pBone, nBones, pMuscle);
		exit(-1);
	}
	else
		(*pNumMuscles)++;
	return paux;
}

int AddBone(tBone **ppBone, int n, tMuscle *pMuscle)
{
	tBone *paux = *ppBone;
	paux = (tBone *)realloc(paux, (n + 1)*sizeof(tBone));
	if (paux == NULL)
	{
		printf("\nError allocating memory\n");
		system("pause");
		FreeMemory(*ppBone, n, pMuscle);
		exit(-1);
	}
	*ppBone = paux;
	return (n + 1);
}

void LinkBone(tBone *pBone, tMuscle *pMuscle, int nMuscles)
{
	int i, j;
	char nameMuscle[MAX_CHARAC_NAME];
	printf("\n This bone has %d muscles associated\n", pBone->nMusc);

	/* for each of the muscles associates with the bone we should
	   read from keyboard the name of the muscle and look for this name
	   in the array of muscles. 
	   If we find the name we have to point the pointer to this muscle.
	   If we don't find the name we have to point the pointer to NULL */

	for (i = 0; i < pBone->nMusc; i++)
	{
		printf("\n\nPlease enter the name of the muscle number %d\n", i + 1);
		fflush(stdin);
		fgets(nameMuscle, MAX_CHARAC_NAME, stdin);

		for (j = 0; j < nMuscles; j++)
		{
			if (!strcmp(nameMuscle, pMuscle[j].commonInfo.name))
			{
				pBone->ppMusc[i] = &pMuscle[j];
				break;
			}
		}
		if (j == nMuscles)
			pBone->ppMusc[i] = NULL;
	}
}

void PrintCommonInfo(tCommonInfo common)
{
	printf("\n\tName: %s",common.name);
	printf("\n\tDescription: %s", common.description);
	printf("\n\tLocation: %s ", BodyParts[common.location]);
	printf("\n\tLength: %d ", common.length);
}

void PrintBone(tBone bone)
{
	PrintCommonInfo(bone.commonInfo);
	printf("\n\tDensity: %.2f ", bone.density);
	printf("\n\tNumber of associated muscles: %d ", bone.nMusc);
	printf("\n*******************************\n\n");
}

void PrintMuscle(tMuscle muscle)
{
	PrintCommonInfo(muscle.commonInfo);
	printf("\n\tType: %s ", MuscleTypes[muscle.type]);
	printf("\n\tFunction: %s ", muscle.function);
	printf("\n*******************************\n\n");
}

void MusclesLengthArea(tBone *pBone, int nBones, int length, int area)
{
	int i, j;

	printf("\n\nMuscle name\t\tName of the bone to which it belongs\n");
	printf("______________________________________________________\n");
	for (i = 0; i<nBones; i++)
		for (j = 0; j<pBone[i].nMusc; j++)
			if ((pBone[i].ppMusc[j]->commonInfo.length < length) &&
				(pBone[i].ppMusc[j]->commonInfo.location == area))
				printf("%-20s\t\t%-s\n", pBone[i].ppMusc[j]->commonInfo.name,
				pBone[i].commonInfo.name);

}

float CalculateBoneDensity(tBone *pBone, int nBones, int area)
{
	int i, numBonesArea=0;
	float boneDensity = 0;
	for (i = 0; i < nBones; i++)
		if (pBone[i].commonInfo.location == area)
		{
			boneDensity += pBone[i].density / pBone[i].commonInfo.length;
			numBonesArea++;
		}
	return (boneDensity * 100) / nBones;
}

void FreeMemory(tBone *pBone, int nBones, tMuscle *pMuscle)
{
	int i;
	if (pBone != NULL)
	{
		for (i = 0; i < nBones; i++)
		{
			if (pBone[i].ppMusc != NULL)
				free(pBone[i].ppMusc);
		}
		free(pBone);
	}
	if (pMuscle != NULL)
	{
		free(pMuscle);
	}
}