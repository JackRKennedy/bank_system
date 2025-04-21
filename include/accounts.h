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

int count_rows(const char *filename); // used to display the welcome message and possible other used

void print_accounts(const char *filename); // prints the account list available when logging in

/*Account balances is used after withdraw, deposit and login to show updated account balances*/
void print_account_balances(const char *filename, int account_number);

void login(const char *filename);

void add_account(const char *filename);

void delete_account(const char *filename);

void withdraw(const char *filename, int account_number);

void deposit(const char *filename, int account_number);

#endif //ACCOUNTS_H
