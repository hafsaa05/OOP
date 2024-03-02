/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;

class Engine {
private:
    string type;

public:
    Engine(string engineType) : type(engineType) {
        cout << "Vroom! Engine started." << endl;
    }

    void startEngine() {
        cout << "Vroom! Engine started." << endl;
    }
};

class Wheels {
private:
    int count;

public:
    Wheels(int wheelCount) : count(wheelCount) {}

    void move() {
        cout << "Wheels rolling!" << endl;
    }
};

class Headlights {
private:
    int count;

public:
    Headlights(int headlightCount) : count(headlightCount) {}

    void turnOn() {
        cout << "Headlights on !" << endl;
    }

    void turnOff() {
        cout << "Headlights off !" << endl;
    }
};

class Steering {
private:
    string type;

public:
    Steering(string steeringType) : type(steeringType) {
        cout << "Steering type: " << type << endl;
    }

    void steer() {
        cout << "Steering the car" << endl;
    }
};

class Car {
private:
    Engine* engine;
    Steering* steering;
    Wheels* wheels;
    Headlights* headlights;

public:
    Car(Engine* carEngine, Steering* carSteering, Wheels* carWheels, Headlights* carHeadlights)
        : engine(carEngine), steering(carSteering), wheels(carWheels), headlights(carHeadlights) {}

    void start() {
        if (engine) {
            engine->startEngine();
        }
    }

    void drive() {
        if (wheels) {
            wheels->move();
        }
        if (headlights) {
            headlights->turnOn();
        }
        if (steering) {
            steering->steer();
        }
    }
};

int main() {
    Engine carEngine("Powerful Engine");
    Steering carSteering("Responsive Steering");
    Wheels carWheels(4);
    Headlights carHeadlights(2);

    Car myCar(&carEngine, &carSteering, &carWheels, &carHeadlights);
    myCar.start();
    myCar.drive();

    return 0;
}
