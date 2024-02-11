/*Develop a recursive function named hasSubsetSum that accepts an integer array,
the array’s size, and a target sum as input and returns a boolean indicating whether a
subset with the specified sum exists. • The function should have the following signature:
bool hasSubsetSum(int arr[], int size, int targetSum).*/
#include<iostream>
using namespace std;
bool hasSubsetSum(int arr[], int size, int targetSum ) {

    if (targetSum == 0) 
    { 
        return true;
    }
    if (size == 0 || targetSum < 0) {
        return false;
    }
    
    //first function is including the current element while the other is excluding it.
    return hasSubsetSum(arr, size - 1, targetSum - arr[size - 1]) || 
           hasSubsetSum(arr, size - 1, targetSum);
}

int main() {
 int arr[]={2,4,6,8,10};
 int targetSum = 14;
 int s = sizeof(arr) / sizeof(arr[0]);

    bool subset = hasSubsetSum(arr, s, targetSum);

    if (subset) {
        cout << "Subset exists.";
    } else {
       cout << "Subset does'nt exists.";
    }
 return 0;
}
