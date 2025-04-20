//
// Created by Jack Kennedy on 19/04/2025.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/accounts.h"

// calculates the number of accounts:
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

// reads from csv file and prints account information
void print_accounts(const char *filename) {
	printf("List of available accounts: \n");
	printf("Account Number | Account Name |\n");

	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		perror("Error opening file");
		fclose(file);
		return; // if any errors with opening file close the function
	}

	char line[1024]; // buffer for lines
	fgets(line, sizeof(line), file); // skip header file

	while (fgets(line, sizeof(line), file) != NULL) { // go through remaining lines
		if (ferror(file)) {
			perror("Error reading file");
			fclose(file);
			return; // if any errors with reading file close the function
		}
		char *token = strtok(line, ","); // split line into tokens
		int fieldCount = 0; // field count variable so i can iterate through cells in a row

		while (token != NULL && fieldCount < 2) { // only iterate through the first two cells to show infromation
			//remove leading/trailing whitespace
			char *start = token;
			while (*start == ' ' || *start == '\t') {
				start++;
			}

			char *end = start +strlen(start) -1;
			while (end >= start && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r')) {
				*end = '\0';end--;
			}

			printf("%s | ", start); // print current cell value
			token = strtok(NULL, ","); // get next token
			fieldCount++;
		}
		printf("\n"); // print new line at the end of the current line
		}
	if (fclose(file) != 0) {
		perror("Error closing file");
	}
}
void login(const char *filename, int account_number) {
}

void delete_account(const char *filename) {

}

void add_account(const char *filename) {

}