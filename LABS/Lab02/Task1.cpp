/*Your assignment is to develop a C++ function that interchanges the values of two
variables. Construct a recursive function called recursiveSwap that accepts two
variables as arguments and swaps their values recursively.*/

#include<iostream>
using namespace std;

void recursiveSwap(int &a, int &b, int swaps) 
{ 
    // Base case: stop swapping when swaps reach 0
    if (swaps == 0) 
        return; 

    // Swap the values
    int temp = a;
    a = b;
    b = temp;

    // Recursive call with one less swap
    recursiveSwap(a, b, swaps - 1);
}

int main() {
    int n1, n2;
    cout << "Enter first number: ";
    cin >> n1;
    cout << "Enter second number: ";
    cin >> n2;

    recursiveSwap(n1, n2, 1); // Swap only once

    cout << "After swapping:" << endl;
    cout << "First number: " << n1 << endl;
    cout << "Second number: " << n2 << endl;

    return 0;
}
