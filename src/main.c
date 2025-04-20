#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/accounts.h"

int count_rows(const char *filename) {
	FILE *file = fopen(filename,"r"); // opening in write mode, nothing to update
	// handle errors with opening file
	if (file == NULL) {
		perror("Error opening file");
		fclose(file);
		return -1; // closes application with error
	}
	int count = 0;
	char line[1024];
	fgets(line, sizeof(line), file); // get header row and skip it

	// perform while loop search now to return true count
	while (fgets(line, sizeof(line), file) != NULL) { // while row is not empty
		// check if the line isn't empty or contains only whitespace:
		if (strlen(line) > 1 && !strspn(line, " \t\n\r\f\v")) {
			count++;
		}
	}
	fclose(file); // close file after reading
	return count;
}

int main(void) {
	char *filename = "csv/accounts.csv";
	// int size = count_rows(filename); // get number of rows in csv file

	//adding two boilerplate accounts
	/*
	const Account acc1 = {"John Doe", 001, 475.50, 534.0};
	const Account acc2 = {"Jane Doe", 002, 763.78, 234.98};
	accounts[0] = acc1;
	accounts[1] = acc2;
	*/

	printf("Welcome to the banking system\n");

	printf("Which account would you like to access?\n");

	print_accounts(filename);

	return 0;
}