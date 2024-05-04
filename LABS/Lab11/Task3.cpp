/*
Name: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;

class Vehicle {
protected:
    string make, model;
    int speed;

public:
    Vehicle(string make, string model, int speed) : make(make), model(model), speed(speed) {}

    string getMake() const {
        return make;
    }
    string getModel() const {
        return model;
    }
    int getSpeed() const {
        return speed;
    }

    virtual void accelerate() const = 0;
    virtual void brake() const = 0;
    virtual void calculateFuelEfficiency() const = 0;
};

class Car : public Vehicle {
private:
    double fuelCapacity;

public:
    Car(double fuelCapacity, string make, string model, int speed) :
        Vehicle(make, model, speed), fuelCapacity(fuelCapacity) {}

    void accelerate() const override {
        cout << "Accelerating the car!" << endl;
    }
    void brake() const override {
        cout << "Applying Brakes on car!" << endl;
    }
    void calculateFuelEfficiency() const override {
        cout << "Calculating fuel efficiency of car!" << endl;
    }
};

class Truck : public Vehicle {
private:
    int cargoCapacity;

public:
    Truck(int cargoCapacity, string make, string model, int speed) :
        Vehicle(make, model, speed), cargoCapacity(cargoCapacity) {}

    void accelerate() const override {
        cout << "Accelerating the truck!" << endl;
    }
    void brake() const override {
        cout << "Applying Brakes on truck!" << endl;
    }
    void calculateFuelEfficiency() const override {
        cout << "Calculating fuel efficiency of truck!" << endl;
    }
};

int main() {
    Car car(50.5, "Toyota", "Corolla", 1600);
    car.accelerate();
    car.brake();
    car.calculateFuelEfficiency();

    Truck truck(5000, "Ford", "F150", 100);
    truck.accelerate();
    truck.brake();
    truck.calculateFuelEfficiency();

    return 0;
}
