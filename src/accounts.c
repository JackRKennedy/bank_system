#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>
// Include any other necessary headers (e.g., for your accounts.h)
#include "../include/accounts.h"  //

// Function to count rows (excluding header and blank lines) in CSV file.
int count_rows(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return -1;
    }

    int count = 0;
    char line[1024];
    if (fgets(line, sizeof(line), file) == NULL) { // Check for empty or error conditions
        fclose(file);
        return 0; // Or handle the error as needed
    } //Skip header
    while (fgets(line, sizeof(line), file) != NULL) {

        if (strlen(line) > 1 && !strspn(line, " \t\n\r\f\v")) {
            count++;
        }
    }

    fclose(file);
    return count;
}


void print_accounts(const char *filename) {
    printf("List of available accounts: \n");
    printf("Account Number | Account Name |\n");

    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[1024];
    fgets(line, sizeof(line), file); // Skip header

    while (fgets(line, sizeof(line), file) != NULL) {
        // Error checking for fgets
        if (ferror(file)) {
            perror("Error reading file");
            fclose(file);
            return;
        }


        char *token = strtok(line, ",");
        int field_count = 0;

        while (token != NULL && field_count < 2) {
            // Trim whitespace
            char *start = token;
            while (isspace(*start)) {
                start++;
            }
            char *end = start + strlen(start) - 1;
            while (end >= start && isspace(*end)) {
                *end = '\0';
                end--;
            }

            printf("%s | ", start);
            token = strtok(NULL, ",");
            field_count++;
        }
        printf("\n");
    }

    if (fclose(file) != 0) {
        perror("Error closing file");
    }
}

void login(const char *filename) {
    print_accounts(filename); // Display available accounts

    printf("Which account do you need to log into?\n");

    int user_account;
    if (scanf("%d", &user_account) == 1) {  // Check for valid integer input
        // Clear the input buffer (important to prevent issues if the user enters non-numeric data)
        while (getchar() != '\n');


        FILE *file = fopen(filename, "r");
        if (file == NULL) {
            perror("Unable to open file");
            return;
        }

        char line[1024];
        fgets(line, sizeof(line), file); // Skip header
        bool account_found = false;

        while (fgets(line, sizeof(line), file) != NULL) {
            if (ferror(file)) { //check if there was an error during file reading
                perror("Error reading file");
                fclose(file);
                return;
            }

            line[strcspn(line, "\r\n")] = '\0'; // Remove newlines

            char target_string[20];
            snprintf(target_string, sizeof(target_string), "%d", user_account);

            char *comma_pos = strchr(line, ',');
            if (comma_pos == NULL) {
                printf("Error: Invalid CSV format.\n");
                fclose(file);
                return;
            }
            char first_field[256];
            strncpy(first_field, line, comma_pos - line);
            first_field[comma_pos - line] = '\0';

            if (strcmp(first_field, target_string) == 0) {
                account_found = true;
                int pin_attempts = 0;
                bool correct_pin = false;

                while (pin_attempts < 3 && !correct_pin) {
                    int user_pin, stored_pin;
                    printf("Please enter your PIN (attempt %d/3): ", pin_attempts + 1);


                    if (scanf("%d", &user_pin) != 1) {
                        printf("Invalid input: please enter a valid integer PIN\n");
                        while (getchar() != '\n'); // Clear the input buffer
                        continue; // Go to next attempt if the input is invalid
                    }

                    char *last_comma = strrchr(line, ',');
                    if (last_comma != NULL) {
                        char pin_str[256];  // Temporary string to hold extracted PIN
                        strcpy(pin_str, last_comma + 1);    // Extract PIN
                        stored_pin = atoi(pin_str);           // Convert PIN to integer

                    } else {
                        printf("Error: PIN not found in CSV.\n");
                        break; // Exit the inner loop if no PIN is found
                    }


                    if (user_pin == stored_pin) {
                        correct_pin = true;

                        // Remove the PIN from the output if needed (security best practice):
                        *comma_pos = '\0';

                        printf("Your account information (Account %s):\n%s\n", target_string, line);
                    } else {
                        printf("Incorrect PIN.\n");
                    }

                    pin_attempts++;
                } // End of PIN attempts loop

                if (!correct_pin) {
                    printf("Too many incorrect attempts. Login aborted.\n");
                }

                break; // Exit the account search loop after the account is found (successful or not)
            }
        } // End of account search loop

        if (!account_found) {
            printf("Account number not found.\n");
        }

        fclose(file);

    } else {
        printf("Invalid account number input.\n"); // Handle invalid input (non-integer)
        while (getchar() != '\n'); // Clear the input buffer to prevent infinite loop
    }
}




void delete_account(const char *filename) {
    // Implementation for deleting an account
}

void add_account(const char *filename) {
    // Implementation for adding an account
}