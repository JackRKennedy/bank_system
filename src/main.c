#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/accounts.h"

int main(void) {
	char *filename = "csv/accounts.csv";
	int num_accounts = count_rows(filename);
	// int size = count_rows(filename); // get number of rows in csv file

	//adding two boilerplate accounts
	/*
	const Account acc1 = {"John Doe", 001, 475.50, 534.0};
	const Account acc2 = {"Jane Doe", 002, 763.78, 234.98};
	accounts[0] = acc1;
	accounts[1] = acc2;
	*/

	bool quit = false;

	while (!quit){
		printf("\nWelcome to our banking system, we are a growing branch with %d accounts and counting!\n", num_accounts);

		char input[3]; // allow for an input buffer

		printf("How can we help you today?\n");
		printf("q:\tquit\na:\tadd account\nd:\tdelete account\nl:\tlogin\n\n");

		// check for errors with the input - should be one character in length with no newline
		if (fgets(input, sizeof(input), stdin) == NULL) {
			perror("Error reading input");
			exit(EXIT_FAILURE);
		}

		// Remove the newline character if present
		input[strcspn(input, "\n")] = 0;

		// cannot be larger than one character
		if (strlen(input) > 1) {
			printf("Invalid input: Please enter only one character.\n");
			continue; // Go to the next iteration of the loop
		}

		char option = input[0]; // Extract the first character


		switch (option) {
			case 'l': //login to selected account
				printf("Which account would you like to access?\n");

			print_accounts(filename);
			break;
			case 'q': //quit
				printf("Thank you for using the banking system\n");
			quit = true;
			break;
			case 'a': // add account
				add_account(filename);
			break;
			case 'd': // delete account
				delete_account(filename);
			break;
			case '?': // unrecognised input
				perror("That is an unrecognised value, please double check the valid options\n");
			default:
				printf("Invalid input: Please enter a valid option\n");
				break;
		}
		return 0;
	}
}