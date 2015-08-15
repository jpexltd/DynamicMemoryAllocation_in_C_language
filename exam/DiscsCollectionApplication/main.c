#include "Header.h"
int main()
{
	int nDiscs=0, operation, i, result;
	tDisc *pDisc=NULL;

    while ((operation = Menu()) != 5)
    {
	  switch (operation)
	  {
	    case 1:
		// ADD DISC
		/*Allocate memory for the structures type tDisc*/

		nDiscs = AddDisc(&pDisc, nDiscs);

		/* Read the data for the disc and allocate memory
		for the pointer to pointer to char * (ppSong) */

		pDisc[nDiscs - 1].ppSong = ReadDisc(&pDisc[nDiscs - 1]);

		if (pDisc[nDiscs - 1].ppSong == NULL)
		{
			printf("Error allocating memory in the array of pointers of the songs\n");
			system("pause");
			FreeMemory(pDisc, nDiscs);
			return -1;
		}

		/*Allocate memory for the names of the songs
		  that is for the pointers contained in the array of pointers to char,
		  and read the names*/

		ReadSongs(pDisc[nDiscs - 1]);

		break;
	case 2:
		//DISPLAY INFORMATION OF THE DISCS
		for (i = 0; i < nDiscs; i++)
		{
			printf("\n\nDisc %d\n", i + 1);
			PrintDisc(pDisc[i]);
			PrintSongs(pDisc[i]);
		}
		system("pause");
		break;
	case 3:
		//DISPLAY THE DISC OF AN AUTHOR USING HIS NAME
		PrintDiscsOfAuthor(pDisc, nDiscs);
		system("pause");
		break;
	case 4:
		//DELETE DISC
		result = DeleteDisc(pDisc, &nDiscs);
		if (result == 0)
		{
			printf("\nThe disc has been deleted\n");
			system("pause");
			if (nDiscs == 0)
				pDisc = NULL;
		}
		else
		{
			printf("\nThe disc does not exist, cannot be deleted\n");
			system("pause");
		}
		break;
	}
}

FreeMemory(pDisc, nDiscs);

MemoryManager_DumpMemoryLeaks();
system("pause");
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
		printf("\n Please select one option\n");
		scanf("%d", &op);
	} while (op < 1 || op > 5);
	return op;
}