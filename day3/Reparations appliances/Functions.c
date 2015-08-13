#include "Header.h"

tCustomer *AddNewCust(tCustomer *p, int *pn)
{
	tCustomer *paux;
	paux = (tCustomer *)realloc(p, (*pn + 1)*sizeof(tCustomer));
	if (paux != NULL)
	{
		paux[*pn] = ReadCustomer();
		(*pn)++;
	}
	return paux;
}

tCustomer ReadCustomer()
{
	tCustomer customer;

	printf("\n\tName: ");
	fflush(stdin);
	fgets(customer.name, MAX_CHARAC_NAME_ADDRESS,stdin);
	printf("\n\tLast name: ");
	fflush(stdin);
	fgets(customer.lastName, MAX_CHARAC_NAME_ADDRESS, stdin);
	printf("\n\tAddress: ");
	fflush(stdin);
	fgets(customer.address, MAX_CHARAC_NAME_ADDRESS, stdin);
	printf("\n\tCode: ");
	fflush(stdin);
	fgets(customer.code, MAX_CHARAC_CODE, stdin);
	
	//Initially the number of contracts is 0
	customer.custContract.nCurrentContract = 0;
	customer.custContract.pContract = NULL;

	return customer;
}

int LookForCustomerByCode(tCustomer *p, int n)
{
	int i;
	char code[15];

	printf("Please enter the code of the customer: ");
	fflush(stdin);
	fgets(code, MAX_CHARAC_CODE, stdin);

	for (i = 0; i < n; i++)
	{
		if (!strcmp(code, p[i].code))
			return i;
	}
	printf("This customer does not exist\n");
	system("pause");
	return -1;
}

int LookForContByContNumber(tCustomer *p, int nContr)
{
	// p: pointer to the customer whose contract will be searched
	// nContr: Num of contracts of this customer
	int i;
	char contractNumber[15];

	printf("Please enter the contract number of the customer: ");
	fflush(stdin);
	fgets(contractNumber, MAX_CHARAC_CONTRACTNUMBER, stdin);

	for (i = 0; i < nContr; i++)
	{
		if (!strcmp(contractNumber, p->custContract.pContract[i].contractNumber))
			return i;
	}
	printf("This customer does not have this contract\n");
	system("pause");
	return -1;
}

tCon *AddContract(tCustomer *p, int pos)
{
	int nContracts;
	tCon *paux;

	paux = p[pos].custContract.pContract;
	nContracts = p[pos].custContract.nCurrentContract;
	paux = (tCon *)realloc(paux, (nContracts + 1)*sizeof(tCon));
	if (paux != NULL)
	{
		ReadContract(&paux[nContracts]);
		p[pos].custContract.nCurrentContract++;
	}
	return paux;
}

void ReadContract(tCon *pCon)
{
	printf("\n\tDescription: ");
	fflush(stdin);
	fgets(pCon->description, MAX_CHARAC_DESC, stdin);
	printf("\n\tAppliance price: ");
	scanf("%d", &pCon->appliancePrice);
	printf("\n\tInsurance policy: ");
	scanf("%d", &pCon->insurancePolicy);
	printf("\n\tSerial number: ");
	fflush(stdin);
	fgets(pCon->serialNumber, MAX_CHARAC_SERIALNUMBER, stdin);
	printf("\n\tContract number: ");
	fflush(stdin);
	fgets(pCon->contractNumber, MAX_CHARAC_CONTRACTNUMBER, stdin);
}

int AllowReparation(tCustomer *pCust, int nCust, char serialNum[15], int Rep)
{
	int i, j;

	for (i = 0; i<nCust; i++)
	{
	  if (pCust[i].custContract.nCurrentContract)
		for (j = 0; j<pCust[i].custContract.nCurrentContract; j++)
		 {
			if (!strcmp(pCust[i].custContract.pContract[j].serialNumber, serialNum))
			{
			  if (Rep <= (int)(0.25 * (pCust[i].custContract.pContract[j].appliancePrice)))
			    return 1;
			  return 0;
			}
		}
	}
	return 2;
}

void CustomerDisplay(tCustomer customer)
{
	printf("\n\tName: %s\n", customer.name);
	printf("\n\tLast name: %s\n", customer.lastName);
	printf("\n\tAddress: %s\n", customer.address);
	printf("\n\tCode: %s\n", customer.code);
}

void ContractsDisplay(tCon *p, int n)
{
	int i;

	printf("\n\tContracts\n");
	printf("===================================\n\n");

	for (i = 0; i < n; i++)
	{
		printf("\n\tContract %d\n", i + 1);
		printf("\n\t\tDescription: %s", p[i].description);
		printf("\n\t\tAppliance price: %d", p[i].appliancePrice);
		printf("\n\t\tInsurance Policy: %d", p[i].insurancePolicy);
		printf("\n\t\tSerial number: %s", p[i].serialNumber);
		printf("\n\t\tContract number: %s", p[i].contractNumber);
		printf("\n");
		printf("__________________________\n");
	}
}

void PrintData(tCustomer *pCust, int nCust)
{
	int i;
	printf("\n\nDisplay of the data\n");
	printf("===================================\n\n");

	for (i = 0; i < nCust; i++)
	{
		printf("\n\tCustomer %d\n", i + 1);
		CustomerDisplay(pCust[i]);
		ContractsDisplay(pCust[i].custContract.pContract, pCust[i].custContract.nCurrentContract);
	}
}



void DeleteCustomer(tCustomer *pCust, int nCust, int pos)
{
	int i;

	if (pCust[pos].custContract.pContract!=NULL)
		free(pCust[pos].custContract.pContract);

	for (i = pos; i < nCust-1; i++)
		pCust[i] = pCust[i + 1];

	pCust = (tCustomer *)realloc(pCust, (nCust - 1)*sizeof(tCustomer));
}

void DeleteContract(tCon *pCon, int nCon, int pos)
{
	int i;
	for (i = pos; i < nCon - 1; i++)
		pCon[i] = pCon[i + 1];
	pCon = (tCon *)realloc(pCon, (nCon - 1)*sizeof(tCon));
}

void FreeMemory(tCustomer *pCust, int nCust)
{
	int i;
	if (pCust != NULL)
	{
		for (i = 0; i < nCust; i++)
			if (pCust[i].custContract.pContract != NULL)
				free(pCust[i].custContract.pContract);
		free(pCust);
	}
}