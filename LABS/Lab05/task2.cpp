/*
Programmer: Hafsa Rashid
Student ID: 23k-0064
*/
#include<iostream>
using namespace std;

class FinancialAssistant{
    const float interestRate;
    float loanAmount;     
    int repaymentMonths; 
    
public:
    FinancialAssistant(float userRate, float principalAmount, int repaymentPeriod):interestRate(userRate), loanAmount(principalAmount), repaymentMonths(repaymentPeriod)
    {
        if(userRate <= 0 || userRate >= 0.005)
        {
            cout << "Invalid interest rate" << endl;
            return;
        }
    }
    
    void calculatePayment()
    {
        float monthlyPayment;
        float interest;
        float totalPayment;
        
        monthlyPayment = loanAmount / repaymentMonths;
        interest = monthlyPayment * interestRate;
        totalPayment = monthlyPayment + interest;
        
        cout << "You are required to make monthly payments of " << totalPayment << " for " << repaymentMonths << " months to settle your financial commitment." << endl;
    }
};

int main(){
    FinancialAssistant Assistant1(0.003, 13000, 6);
    Assistant1.calculatePayment();
    return 0;
}
