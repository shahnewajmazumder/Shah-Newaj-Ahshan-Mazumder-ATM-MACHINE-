#include <stdio.h>

#define MAX_ACCOUNTS 10  

int account_numbers[MAX_ACCOUNTS] = {101, 102, 103, 104, 105, 106, 107, 108, 109, 110};  
float balances[MAX_ACCOUNTS] = {1000.0, 2000.0, 1500.0, 800.0, 5000.0, 300.0, 1200.0, 3700.0, 2500.0, 4600.0}; 

void balance_inquiry(int account_index) {
    printf("Your total balance is: $%.2f\n", balances[account_index]);
}

void deposit(int account_index) {
    float amount;
    printf("Enter amount to deposit: ");
    scanf("%f", &amount);
    balances[account_index] += amount;
    printf("Deposit successful! Your new balance is: %.2f\n", balances[account_index]);
}

void withdrawal(int account_index) {
    float amount;
    printf("Enter amount to withdraw: ");
    scanf("%f", &amount);

    if (amount > balances[account_index]) {
        printf("Insufficient balance.\n");
    } else {
        balances[account_index] -= amount;
        printf("Withdrawal successful! Your new balance is: %.2f\n", balances[account_index]); 
    }
}

void atm_menu(int account_index) {
    int choice;
    
    while (1) {
        printf("\nATM Menu:\n");
        printf("1. Balance Inquiry\n");
        printf("2. Deposit\n");
        printf("3. Withdrawal\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                balance_inquiry(account_index);
                break;
            case 2:
                deposit(account_index);
                break;
            case 3:
                withdrawal(account_index);
                break;
            case 4:
                printf("Thank you for using the ATM. Goodbye!\n");
                return;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }
}

int main() {
    int selected_account;
    printf("Enter your account number (101-110): ");
    scanf("%d", &selected_account);

    int account_index = -1;
    for (int i = 0; i < MAX_ACCOUNTS; i++) {
        if (account_numbers[i] == selected_account) {
            account_index = i;
            break;
        }
    }

    if (account_index == -1) {
        printf("Invalid account number. Exiting...\n");
        return 1;
    }

    atm_menu(account_index);
    return 0;
}