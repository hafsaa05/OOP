/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;

class Vehicle {
public:
    string make, model;
    int year;
    
    Vehicle(string make, string model, int year) : make(make), model(model), year(year) {}
    
    void display() {
        cout << "Company: " << make << endl;
        cout << "Model: " << model << endl;
        cout << "Year: " << year << endl;
    }
};

class Car : virtual public Vehicle {
public:
    int door;
    float fuel, efficiency;
    
    Car(string make, string model, int year, int door, float fuel, float efficiency)
        : Vehicle(make, model, year), door(door), fuel(fuel), efficiency(efficiency) {}
    
    void displayCar() {
        cout << "Doors: " << door << endl;
        cout << "Fuel: " << fuel << endl;
        cout << "Efficiency: " << efficiency << endl;
    }
};

class ElectricCar : virtual public Car {
public:
    int battery;
    
    ElectricCar(string make, string model, int year, int door, float fuel, float efficiency, int battery)
        : Vehicle(make, model, year), Car(make, model, year, door, fuel, efficiency), battery(battery) {}
    
    void displayElectricCar() {
        Vehicle::display(); 
        Car::displayCar();      
        cout << "Battery Life: " << battery << endl;
    }
};

int main() {
    ElectricCar obj("Tesla", "Model S", 2023, 4, 76.5, 88, 68);
    obj.displayElectricCar();
    return 0;
}
