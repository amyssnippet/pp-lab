#include <stdio.h>

struct Account {
    int accountNumber;
    char name[50];
    float balance;
};

void deposit(struct Account *acc, float amount) {
    if (amount > 0) {
        acc->balance += amount;
        printf("Deposit successful. New balance: %.2f\n", acc->balance);
    } else {
        printf("Invalid deposit amount.\n");
    }
}

void withdraw(struct Account *acc, float amount) {
    if (amount > 0) {
        if (acc->balance >= amount) {
            acc->balance -= amount;
            printf("Withdrawal successful. New balance: %.2f\n", acc->balance);
        } else {
            printf("Insufficient balance.\n");
        }
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

void displayBalance(struct Account acc) {
    printf("\n Account Details \n");
    printf("Account Number: %d\n", acc.accountNumber);
    printf("Name: %s\n", acc.name);
    printf("Current Balance: %.2f\n", acc.balance);
}

int main() {
    struct Account userAcc;
    int choice;
    float amount;

    printf("Enter Account Number: ");
    scanf("%d", &userAcc.accountNumber);
    
    printf("Enter Account Holder Name: ");
    scanf(" %[^\n]", userAcc.name);
    
    printf("Enter Initial Balance: ");
    scanf("%f", &userAcc.balance);

    do {
        printf("\n1. Deposit\n2. Withdraw\n3. Balance Inquiry\n4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1) {
            printf("Enter amount to deposit: ");
            scanf("%f", &amount);
            deposit(&userAcc, amount);
        } else if (choice == 2) {
            printf("Enter amount to withdraw: ");
            scanf("%f", &amount);
            withdraw(&userAcc, amount);
        } else if (choice == 3) {
            displayBalance(userAcc);
        } else if (choice == 4) {
            printf("Exiting system...\n");
        } else {
            printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 4);

    return 0;
}