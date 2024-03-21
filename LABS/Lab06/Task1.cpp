/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
#include<cstring>

using namespace std;

class BankAccount {
private:
    int accountId;
    double balance;
    int* transactionHistory;
    int numTransactions;

public:
    BankAccount(int id, double initialBalance, int* transactions, int numTrans)
        : accountId(id), balance(initialBalance), numTransactions(numTrans) {

        transactionHistory = new int[numTrans];
        memcpy(transactionHistory, transactions, numTrans * sizeof(int));
    }

    // Copy constructor
    BankAccount(const BankAccount& other)
        : accountId(other.accountId), balance(other.balance), numTransactions(other.numTransactions) {

        transactionHistory = new int[numTransactions];
        memcpy(transactionHistory, other.transactionHistory, numTransactions * sizeof(int));
    }

    ~BankAccount() {
        delete[] transactionHistory;
    }

    void display() {
        cout << "Account ID: " << accountId << endl;
        cout << "Balance: " << balance << endl;
        cout << "Transaction History: ";
        for (int i = 0; i < numTransactions; ++i) {
            cout << transactionHistory[i] << " ,";
        }
        cout << endl;
    }

    void updateTransactionHistory(int* newTransactions, int newNumber) {
        delete[] transactionHistory;

        numTransactions = newNumber;
        transactionHistory = new int[numTransactions];
        memcpy(transactionHistory, newTransactions, numTransactions * sizeof(int));
    }
};

int main() {
    int initialTransactions[3] = {1000, -25000, 1200};

    BankAccount acc1(12345, 500.0, initialTransactions, 3);

    // Creating a copy of the original account
    BankAccount acc2 = acc1;

    cout << "Original Account:" << endl;
    acc1.display();

    cout << "\nCopied Account:" << endl;
    acc2.display();

    // Updating transaction history of the original account
    int newTransactions[4] = {-500, 1250, -2100, 3000};
    acc1.updateTransactionHistory(newTransactions, 4);

    cout << "\nOriginal Account after updating transaction history:" << endl;
    acc1.display();

    return 0;
}
