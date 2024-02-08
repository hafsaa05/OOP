#include<iostream>
using namespace std;
//function to calculate of GCD recursively
int GCD(int n1, int n2) {
    if (n2 == 0) {
        return n1;  // GCD is found when the second number becomes zero
    } else {
        return GCD(n2, n1 % n2);  // Recursive call with swapped values and remainder
    }
}
//function to calculate of LCM recursively
int LCM(int n1, int n2) {
    static int m = 1;  // Static variable to keep track of the current multiple

    if (m % n1 == 0 && m % n2 == 0) {
        int result = m;
        m = 1;  // Reset static variable for future calls
        return result;  // LCM is found when it's divisible by both numbers
    } else {
        m++;  // Increment the current multiple
        return LCM(n1, n2);  // Recursive call with the next multiple
    }
}

int main(){
	int a, b;
	cout<<"Enter your first number: "<<endl;
	cin>>a;
	cout<<"Enter your second number: "<<endl;
	cin>>b;
	
    int gcd = GCD(a, b);
	cout<<"GCD of "<<a<<" and "<<b<<" is: "<<gcd<<endl;
    int lcm = LCM(a, b);
	cout<<"LCM of "<<a<<" and "<<b<<" is: "<<lcm<<endl;

}//end main
