#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "MemoryManager.h"
#define MAX_CHARAC_DESC	80
#define MAX_CHARAC_SERIALNUMBER	15
#define MAX_CHARAC_CONTRACTNUMBER	10
#define MAX_CHARAC_CODE	15
#define MAX_CHARAC_NAME_ADDRESS	50

typedef struct
{
	char description[80];
	int  appliancePrice;
	int  insurancePolicy;
	char serialNumber[15];
	char contractNumber[10];
} tCon;typedef struct
{
	tCon *pContract;
	int  nCurrentContract;
} tContract;typedef struct
{
	char name[50];
	char lastName[50];
	char address[50];
	char code[15]; // Customer personal code
	tContract custContract;
} tCustomer;int Menu();tCustomer *AddNewCust(tCustomer *p, int *pn);tCustomer ReadCustomer();int LookForCustomerByCode(tCustomer *p, int n);int LookForContByContNumber(tCustomer *p, int nContr);void ReadContract(tCon *pCon);tCon *AddContract(tCustomer *p, int pos);int AllowReparation(tCustomer *pCust, int nCust, char serialNum[15], int Rep);void CustomerDisplay(tCustomer customer);void ContractsDisplay(tCon *p, int n);void PrintData(tCustomer *pCust, int nCust);void DeleteCustomer(tCustomer *pCust, int nCust, int pos);void DeleteContract(tCon *pCon, int nCon, int pos);void FreeMemory(tCustomer *pCust, int nCust);