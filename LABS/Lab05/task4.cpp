/*
Programmer: Hafsa Rashid
STudent ID: 23K-0064
*/
#include<iostream>
using namespace std;

class BankAccount {
private:
    long accountNumber;
    string accountHolderName;
    double balance;

public:
    BankAccount(long accountNumber, string accountHolderName, double balance) {
        this->accountNumber = accountNumber;
        this->accountHolderName = accountHolderName;
        this->balance = balance;
    }

    // Function to deposit money
    void deposit(double amount) {
        balance += amount;
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            cout << "Successfully withdrawn " << amount << " rupees" << endl;
        } else {
            cout << "Insufficient funds!" << endl;
        }
    }

    // Function to display account details
    void display() {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolderName << endl;
        cout << "Balance: " << balance << " rupees" << endl;
    }
};

int main() {
    // Create an array of BankAccount objects
    BankAccount accounts[3] = {
        BankAccount(1, "Hafsa", 0.0),
        BankAccount(2, "Anusha", 1500.0),
        BankAccount(3, "Amna", 2000.0)
    };

    cout << "Initial Account details for the first account:" << endl;
    accounts[0].display();
    cout << endl;

    accounts[0].deposit(0.0);
    accounts[0].withdraw(200.0);

    cout << "Updated Account details for the first account after transactions:" << endl;
    accounts[0].display();
    cout << endl;

    return 0;
}
