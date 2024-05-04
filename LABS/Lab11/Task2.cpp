/*
Name: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;

class Account {
protected:
    int accountNumber;
    double balance;

public:
    Account(int accountNumber, double balance) : accountNumber(accountNumber), balance(balance) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    virtual void calculateInterest() const = 0;

    int getAccountNumber() const { return accountNumber; }
    double getBalance() const { return balance; }
};

class SavingsAccount : public Account {
protected:
    double interestRate;

public:
    SavingsAccount(int accountNumber, double balance, double interestRate) : Account(accountNumber, balance), interestRate(interestRate) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient Balance!" << endl;
        }
    }

    void calculateInterest() const override {
        cout << "Savings Account Number: " << getAccountNumber() << endl;
        cout << "Balance: " << getBalance() << endl;
        int years;
        cout << "Number of years of interest: ";
        cin >> years;
        cout << "Interest Amount: " << getBalance() * years * interestRate << endl;
        cout << "============================" << endl;
    }
};

class CurrentAccount : public Account {
protected:
    double overdraftLimit;

public:
    CurrentAccount(int accountNumber, double balance, double overdraftLimit) : Account(accountNumber, balance), overdraftLimit(overdraftLimit) {}

    void deposit(double amount) override {
        balance += amount;
    }

    void withdraw(double amount) override {
        if (balance - amount >= overdraftLimit) {
            balance -= amount;
        } else {
            cout << "Cannot withdraw! Exceeds overdraft limit." << endl;
        }
    }

    void calculateInterest() const override {
        cout << "Current Account Number: " << getAccountNumber() << endl;
        cout << "Balance: " << getBalance() << endl;
        cout << "Current accounts do not earn interest." << endl;
        cout << "============================" << endl;
    }
};

int main() {
    
    Account *savingsAcc = new SavingsAccount(12345, 1000, 0.05);
    savingsAcc->deposit(500);
    savingsAcc->withdraw(200);
    savingsAcc->calculateInterest();
    delete savingsAcc;

    Account *currentAcc = new CurrentAccount(54321, 2000, -1000);
    currentAcc->deposit(1000);
    currentAcc->withdraw(3000);
    currentAcc->calculateInterest();
    delete currentAcc;

    return 0;
}
