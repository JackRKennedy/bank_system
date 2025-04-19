//
// Created by Jack Kennedy on 19/04/2025.
//

#include <stdio.h>
#include "../include/accounts.h"

typedef struct {
	char account_name[50];
	int account_number;
	double savings_balance;
	double current_balance;
} Account;

void print_accounts(int size, Account *accounts) {
	printf("List of available accounts: \n");

	for (int i = 0; i < size; i++) {
		printf("%s : \t%d\n", accounts[i].account_name, accounts[i].account_number);
	}
}