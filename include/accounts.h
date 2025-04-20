//
// Created by Jack Kennedy on 19/04/2025.
//

#ifndef ACCOUNTS_H
#define ACCOUNTS_H

typedef struct {
	int account_number;
	char account_name[50];
	double savings_balance;
	double current_balance;
} Account;

void print_accounts(const char *filename);

#endif //ACCOUNTS_H
