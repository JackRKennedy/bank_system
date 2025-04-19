//
// Created by Jack Kennedy on 19/04/2025.
//

#ifndef ACCOUNTS_H
#define ACCOUNTS_H

typedef struct {
	char account_name[50];
	int account_number;
	double savings_balance;
	double current_balance;
} Account;

void print_accounts(int size, Account *accounts);

#endif //ACCOUNTS_H
