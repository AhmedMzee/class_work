#include <stdio.h>

float deposit(float balance, float amount) {
    return balance + amount;
}

float withdraw(float balance, float amount) {
    if (amount > balance) {
        printf("Insufficient funds!\n");
        return balance;
    }
    return balance - amount;
}

int main() {
    float balance = 0.0;
    int choice;
    float amount;

    while (1) {
        printf("\nBank Account Operations:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter amount to deposit: ");
                scanf("%f", &amount);
                balance = deposit(balance, amount);
                printf("New balance: %.2f\n", balance);
                break;
            case 2:
                printf("Enter amount to withdraw: ");
                scanf("%f", &amount);
                balance = withdraw(balance, amount);
                printf("New balance: %.2f\n", balance);
                break;
            case 3:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}