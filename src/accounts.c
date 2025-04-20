//
// Created by Jack Kennedy on 19/04/2025.
//
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "../include/accounts.h"

// reads from csv file and prints account information
void print_accounts(const char *filename) {
	printf("List of available accounts: \n");
	printf("Account Number | Account Name | Savings Balance $ | Current Balance $\n");

	FILE *file = fopen(filename, "r");
	if (file == NULL) {
		perror("Error opening file");
		fclose(file);
		return; // if any errors with opening file close the function
	}

	char line[1024]; // buffer for lines
	fgets(line, sizeof(line), file); // skip header file

	while (fgets(line, sizeof(line), file) != NULL) { // go through remaining lines
		char *token = strtok(line, ","); // split line into tokens

		while (token != NULL) {
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
		}
		printf("\n"); // print new line at the end of the current line
		}
	if (fclose(file) != 0) {
		perror("Error closing file");
	}
}