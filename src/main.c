#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../include/accounts.h"

int main(void) {
    char *filename = "csv/accounts.csv";
    int num_accounts = count_rows(filename);


    bool quit = false;

    while (!quit) {
        printf("\nWelcome to our banking system, we are a growing branch with %d active accounts and counting!\n", num_accounts);

        char input[3];

        printf("How can we help you today?\n");
        printf("q:\tquit\na:\tadd account\nd:\tdelete account\nl:\tlogin\n\n");

        if (fgets(input, sizeof(input), stdin) == NULL) {
            perror("Error reading input");
            exit(EXIT_FAILURE);
        }

        input[strcspn(input, "\n")] = 0;

        if (strlen(input) > 1) {
            printf("Invalid input: Please enter only one character.\n");
            continue;
        }

        char option = input[0];

        switch (option) {
            case 'l':
                login(filename); // Call login() *after* displaying accounts
                break;
            case 'q':
                printf("Thank you for using the banking system\n");
                quit = true;
                break;
            case 'a':
                add_account(filename);
                num_accounts = count_rows(filename); // Update after account added
                break;
            case 'd':
                delete_account(filename);
                num_accounts = count_rows(filename); // Update after account deletion
                break;
            default:  // Simplified default case
                printf("Invalid input: Please enter a valid option\n");
                break;
        }
    } // while loop ends here now

    return 0;  // Return 0 *after* the loop finishes
}