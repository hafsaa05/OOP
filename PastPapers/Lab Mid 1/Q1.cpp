/*
 You are developing a C++ program to manage employee information. Create a class named Employee that 
 incorporates static variables, constant variables, and functions to ensure proper organization and data 
 integrity. 
 a) Implement a static variable named nextEmployeeID within the Employee class to assign unique IDs 
 to each employee. This ID should be incremented for every new employee added. 
 b) Create a static function 
 called generate EmployeelD that returns the next available employee ID. Demonstrate its usage in the main 
 function by creating two instances of the Employee class and printing their generated IDs. 
 c) Introduce a 
 constant float variable named MAX_SALARY to represent the maximum allowed salary for an employee. 
 d) Modify the member function setSalary to check whether the provided salary exceeds MAX_SALARY. If it does, 
 set the salary to MAX_SALARY. Otherwise, set it to the provided value. 
 e) Implement a non-static member function named displayEmployeelnfo that prints the employee's ID, name, 
 and salary. 
 f) Demonstrate the functionality by creating an instance of the Employee class, setting its 
 information, and then displaying the information using the display EmployeeInfo function. */
#include<iostream>
using namespace std;
class Employee{
    static int nextEmployeeID;
    const float MAX_SALARY = 12000;
    string name;
    float salary;
    public:
    Employee(string name, float salary ): name(name), salary(salary) {}
    static int generateEmployeeID() {
        return nextEmployeeID++;
    }

    void setSalary(float salary) {
        if (salary>MAX_SALARY){ 
            salary = MAX_SALARY;
        } else {
            salary=salary;
        }
    }
    void displayEmployeelnfo(){
        cout<<"Employee's ID: "<<nextEmployeeID<<endl;
        cout<<"Name: "<<name<<endl;
        cout<<"Salary: "<<salary<<"$"<<endl;
    }
};
int Employee::nextEmployeeID = 1;

int main(){
    Employee e1("Hafsa", 999.567);
    Employee emp1("John Doe", 75000.0f);
    e1.displayEmployeelnfo();
    return 0;
}
