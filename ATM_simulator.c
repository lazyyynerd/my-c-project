#include <stdio.h>
#include <stdlib.h>
int main()
{
    int pin = 1234; // Default PIN
    int enteredPin;
    int attempts = 0;
    int choice;
    int balance = 1000; // Default balance
    const int maxAttempts = 3;

    printf("Welcome to the ATM Simulator!\n");
    if (attempts == maxAttempts) {
        printf("Too many incorrect attempts. Your account is locked.\n");
    return 1;}
 while (attempts < maxAttempts) {
        printf("Please enter your PIN: ");
        scanf("%d", &enteredPin);

        if (enteredPin == pin) {
            printf("Access granted. Welcome!\n");
           printf("chose your option\n"
                  "1. Check Balance\n"
                  "2. Withdraw Money\n"
                  "3. Deposit Money\n"
                  "4. Exit\n");
            scanf("%d", &choice);
            switch (choice) {
                case 1:
                    printf("Your current balance is: $%d\n", balance);
                    break;
                case 2: {
                    int withdrawAmount;
                    printf("Enter amount to withdraw: ");
                    scanf("%d", &withdrawAmount);
                    if (withdrawAmount == 0) {
                        printf("Withdrawal amount must be greater than zero.\n");
                    } else if (withdrawAmount < 0) {
                        printf("Withdrawal amount cannot be negative.\n");
                    } else if (withdrawAmount > balance) {
                        printf("Insufficient funds. Your current balance is: $%d\n", balance);
                    } else {
                        balance -= withdrawAmount;
                        printf("You have withdrawn $%d. Your new balance is: $%d\n", withdrawAmount, balance);
                    }
                    break;
                }
                case 3: {
                    int depositAmount;
                    printf("Enter amount to deposit: ");
                    scanf("%d", &depositAmount);
                    if (depositAmount == 0) {
                        printf("Deposit amount must be greater than zero.\n");
                    } else if (depositAmount < 0) {
                        printf("Deposit amount cannot be negative.\n");
                    } else {
                        balance += depositAmount;
                        printf("You have deposited $%d. Your new balance is: $%d\n", depositAmount, balance);
                    }
                    break;
                }
                case 4:
                    printf("Thank you for using the ATM Simulator. Goodbye!\n");
                    return 0;
                default:
                    printf("Invalid option. Please try again.\n");
            }
            break;
        } else {
            attempts++;
            printf("Incorrect PIN. You have %d attempt(s) left.\n", maxAttempts - attempts);
        }
    }

 return 0; }