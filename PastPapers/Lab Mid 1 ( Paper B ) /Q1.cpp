/*
You have to develop a statistical calculation module for a scientific research application. The requirements for this 
module are outlined below: a. Implement a C++ class named 'Statistical Analyzer' with a function compute Average that 
calculates the average of an array of numerical data. The function should be designed to be accessible without creating 
an instance of the class and should be optimized for efficiency. Describe the approach you would take to ensure 
flexibility for different data sets, considering the dynamic nature of scientific research data. b. Extend member 
function the Statistical Analyzer class by implementing a calculateStandardDeviation that computes the standard deviation of a given array of numerical data. Optimize this function for efficiency and ensure it is resistant to unintentional modifications of the object's data.
*/  
#include<iostream>
#include<cmath>
using namespace std;
class StatisticalAnalyzer{
public:
static float computeAvg(int arr[], int n)//avg of an array 
{ 
 int avg = 0;
 for (int i =0; i<n; i++) {
    avg += arr[i];
 }
 return avg/n;
}
static float standardDeviation(int arr[], int n) {
   
    float mean = StatisticalAnalyzer::computeAvg(arr, n);

    int num=0;//numerator

    for(int i=0; i<n; i++){
    num += (arr[i]-mean) * (arr[i]-mean);
    }
     return sqrt( num / ( n-1 ));;
}
};
 


int main(){
    int arr[3]={2,3,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    cout<<StatisticalAnalyzer::computeAvg(arr, n) << endl; 
    cout<<StatisticalAnalyzer::standardDeviation(arr, n)<<endl;

}
