#include <stdio.h>

// Define a structure to represent a simple "class" for a bank account
struct BankAccount {
    // Private data (encapsulated)
    double balance;  // Account balance (private field)

    // Function to initialize account (simulating a constructor)
    //return_type (*pointer_name)(parameter_types);
    void (*init)(struct BankAccount *account, double initial_balance);
    
    // Function to deposit money (simulating a method)
    void (*deposit)(struct BankAccount *account, double amount);

    // Function to withdraw money (simulating a method)
    void (*withdraw)(struct BankAccount *account, double amount);

    // Function to get the balance (getter method)
    double (*get_balance)(struct BankAccount *account);
};

// Define methods outside the structure
void init(struct BankAccount *account, double initial_balance) {
    account->balance = initial_balance;
}

void deposit(struct BankAccount *account, double amount) {
    if (amount > 0) {
        account->balance += amount;
        printf("Deposited %.2f. New balance: %.2f\n", amount, account->balance);
    } else {
        printf("Deposit amount must be positive!\n");
    }
}

void withdraw(struct BankAccount *account, double amount) {
    if (amount > 0 && amount <= account->balance) {
        account->balance -= amount;
        printf("Withdrew %.2f. New balance: %.2f\n", amount, account->balance);
    } else {
        printf("Invalid withdrawal amount.\n");
    }
}

double get_balance(struct BankAccount *account) {
    return account->balance;
}

// Main function
int main() {
    // Create an instance of BankAccount
    struct BankAccount myAccount;

    // Assign the function pointers to simulate methods in object-oriented style
    myAccount.init = init;
    myAccount.deposit = deposit;
    myAccount.withdraw = withdraw;
    myAccount.get_balance = get_balance;

    // Initialize account
    myAccount.init(&myAccount, 1000.0);  // Simulate constructor
    
    // Perform operations on the account
    printf("Initial balance: %.2f\n", myAccount.get_balance(&myAccount));
    myAccount.deposit(&myAccount, 500.0);
    myAccount.withdraw(&myAccount, 200.0);
    
    // Final balance
    printf("Final balance: %.2f\n", myAccount.get_balance(&myAccount));

    return 0;
}
