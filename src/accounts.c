//
// Created by Jack Kennedy on 19/04/2025.
//

#include <stdio.h>
#include "../include/accounts.h"

void print_accounts(int size, Account *accounts) {
	printf("List of available accounts: \n");

	for (int i = 0; i < size; i++) {
		printf("%s : %d\n", accounts[i].account_name, accounts[i].account_number);
	}
}