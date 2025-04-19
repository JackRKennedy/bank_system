#include <stdio.h>
#include <stdlib.h>

#include "../include/accounts.h"

int main(void) {

	Account *accounts = NULL;
	int size = 2; // number of accounts currently active, includes boilerplate accounts
	const int capacity = 5; // number of accounts created, starting small but can change this in the future

	accounts = (Account *)malloc(capacity * sizeof(Account));

	//adding two boilerplate accounts

	const Account acc1 = {"Jack Kennedy", 001, 475.50, 534.0};
	const Account acc2 = {"Aine McGlinchey", 002, 763.78, 234.98};
	accounts[0] = acc1;
	accounts[1] = acc2;

	printf("Welcome to the banking system\n");

	printf("Which account would you like to access?\n");

	print_accounts(size, accounts);

	free (accounts); // free memory from accounts array implementation
	return 0;
}