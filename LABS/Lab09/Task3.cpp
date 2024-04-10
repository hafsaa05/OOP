/*
Name: Hafsa Rashid
Student ID: 23K-0064
*/
#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    int employeeID;
    string employeeName;

public:
    Employee(int id, const string& name) : employeeID(id), employeeName(name) {}

    virtual double calculatePay() const {
        return 0.0;
    }

    virtual void displayDetails() const {
        cout << "Employee ID: " << employeeID << ", Name: " << employeeName;
    }
};

class FullTimeEmployee : public Employee {
private:
    double monthlySalary;

public:
    FullTimeEmployee(int id, const string& name, double salary) : Employee(id, name), monthlySalary(salary) {}

    double calculatePay() const override {
        return monthlySalary;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "\nType: Full-time, Monthly Salary: $" << monthlySalary << endl;
    }
};

class PartTimeEmployee : public Employee {
private:
    double hourlyWage;
    double hoursWorked;

public:
    PartTimeEmployee(int id, const string& name, double wage, double hours) : Employee(id, name), hourlyWage(wage), hoursWorked(hours) {}

    double calculatePay() const override {
        return hourlyWage * hoursWorked;
    }

    void displayDetails() const override {
        Employee::displayDetails();
        cout << "\nType: Part-time, Hourly Wage: $" << hourlyWage << ", Hours Worked: " << hoursWorked << endl;
    }
};

int main() {
    FullTimeEmployee fullTimeEmp(1, "Harry", 7500);
    PartTimeEmployee partTimeEmp(2, "James", 12, 30);

    fullTimeEmp.displayDetails();
    partTimeEmp.displayDetails();
    cout<<"\n";
    cout<<"Calculating Pay: "<<endl;
    cout << "Full-time Employee Pay: $" << fullTimeEmp.calculatePay() << endl;
    cout << "Part-time Employee Pay: $" << partTimeEmp.calculatePay() << endl;
    cout<<"\n";
    Employee* empPtr = &fullTimeEmp;
    cout << "Using base class pointer to calculate Full-time Employee Pay: $" << empPtr->calculatePay() << endl;

    return 0;
}
