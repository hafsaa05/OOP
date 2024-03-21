/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
#include<string>
using namespace std;

class Appointment {
private:
    string customerName; 
    double cost;
    static int totalAppointments;
    static double totalEarnings;

public:
    Appointment(string name, double cost) : customerName(name), cost(cost) {
        totalAppointments++;
        totalEarnings += cost;
    }

    static double averageCost() {
        if (totalAppointments == 0) {
            return 0.0;
        } else {
            return totalEarnings / totalAppointments;
        }
    }

    string getCustomerName() const {
        return customerName;
    }

    double getCost() const {
        return cost;
    }
};

int Appointment::totalAppointments = 0;
double Appointment::totalEarnings = 0.0;

int main() {
    Appointment a1("Hafsa", 50.0);
    Appointment a2("Amna", 40.0);

    double avgCost = Appointment::averageCost();

    cout << "Appointments:" << endl;
    cout << "Customer Name\tCost" << endl;
    cout << a1.getCustomerName() << "\t\t" << a1.getCost() << endl;
    cout << a2.getCustomerName() << "\t\t" << a2.getCost() << endl;

    cout << "\nAverage Cost per Appointment: $" << avgCost;

    return 0;
}
