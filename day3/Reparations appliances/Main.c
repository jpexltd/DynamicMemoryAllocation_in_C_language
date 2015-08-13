#include "Header.h"
int main()
{
	
	int nCustomers=0, operation,posCust, posCont, appliancePrice, nCon_aux;	tCustomer * pCustomer = NULL, *pCust_aux;	tCon *pCon_aux;	char serialNumber[15];	while ((operation = Menu()) != 8)
	{
		switch (operation)
		{
		case 1:
			pCust_aux = AddNewCust(pCustomer, &nCustomers);
			if (pCust_aux == NULL)
			{
				printf("Error allocating memory\n");
				system("pause");
				FreeMemory(pCustomer, nCustomers);
				return -1;
			}
			pCustomer = pCust_aux;
			break;
		case 2:
			posCust = LookForCustomerByCode(pCustomer, nCustomers);
			if (posCust != -1)
			{
				pCon_aux = AddContract(pCustomer, posCust);
				if (pCon_aux == NULL)
				{
					printf("Error allocating memory\n");
					system("pause");
					FreeMemory(pCustomer, nCustomers);
					return -1;
				}
				else
					pCustomer[posCust].custContract.pContract = pCon_aux;
			}
			break;
		case 3:
			printf("\n\tPlease enter serial number of the appliance: ");
			fflush(stdin);
			fgets(serialNumber, MAX_CHARAC_SERIALNUMBER, stdin);
			printf("\n\tPlease enter the cost of the repair: ");
			scanf("%d", &appliancePrice);
			switch (AllowReparation(pCustomer, nCustomers, serialNumber, appliancePrice))
			{
			case 0:
				printf("\nThe repair has not been allowed, the cost is very high\n");
				break;
			case 1:
				printf("\nThe repair has been allowed\n");
				break;
			case 2:
				printf("\nThis serial number doesn't exist\n");
				break;
			}
			system("pause");
			break;
		case 4:
			posCust = LookForCustomerByCode(pCustomer, nCustomers);
			if (posCust != -1)
				CustomerDisplay(pCustomer[posCust]);
			system ("pause");
			break;
		case 5:
			posCust = LookForCustomerByCode(pCustomer, nCustomers);
			if (posCust != -1)
			{
				DeleteCustomer(pCustomer, nCustomers, posCust);
				nCustomers--;
				if (nCustomers == 0)
					pCustomer = NULL;
			}
			system("pause");
			break;
		case 6:
			posCust = LookForCustomerByCode(pCustomer, nCustomers);
			if (posCust != -1)
			{
				pCon_aux = pCustomer[posCust].custContract.pContract;
				nCon_aux = pCustomer[posCust].custContract.nCurrentContract;
				posCont = LookForContByContNumber(&pCustomer[posCust], nCon_aux);
				if (posCont != -1)
				{
					DeleteContract(pCon_aux, nCon_aux, posCont);
					pCustomer[posCust].custContract.nCurrentContract--;
					if (pCustomer[posCust].custContract.nCurrentContract == 0)
						pCustomer[posCust].custContract.pContract = NULL;
				}
			}
			system("pause");
			break;
		case 7:
			PrintData(pCustomer, nCustomers);
			system("pause");
			break;
		}
	}	FreeMemory(pCustomer, nCustomers);
	MemoryManager_DumpMemoryLeaks();
	system("pause");
}

int Menu()
{
	int op;
	do
	{
		system("cls");
		printf("\t1. Add a new customer\n");
		printf("\t2. Add a contract\n");
		printf("\t3. Allow a repair\n");
		printf("\t4. Print customer data using its code\n");
		printf("\t5. Delete a customer using its code\n");
		printf("\t6. Delete a contract of a customer using its contract number\n");
		printf("\t7. Print data\n");
		printf("\t8. Exit\n");
		printf("\n Select one option\n\n");
		scanf("%d", &op);
	} while (op < 1 || op > 8);
	return op;
}