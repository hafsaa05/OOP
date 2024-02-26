#include<iostream>
using namespace std;

class RollerCoaster {
private:
    string name;
    int height;
    int length;
    int speed;
    int capacity;
    int currentNumRiders;
    bool rideInProgress;

public:
    RollerCoaster() : name("Roller Coaster"), height(500), length(2000), speed(0), capacity(20), currentNumRiders(0), rideInProgress(false) {}

    RollerCoaster(string name, int height, int length, int capacity, int speed, bool rideInProgress, int currentNumRiders)
        : name(name), height(height), length(length), capacity(0), speed(0), rideInProgress(false), currentNumRiders(0) {
        setCapacity(capacity);
    }

    // Getters and Setters
    string getName() { return name; }
    void setName(string name) { this->name = name; }

    int getHeight() { return height; }
    void setHeight(int height) { this->height = height; }

    int getLength() { return length; }
    void setLength(int length) { this->length = length; }

    int getSpeed() { return speed; }
    void setSpeed(int speed) { this->speed = speed; }

    int getCapacity() { return capacity; }
    void setCapacity(int capacity) {
        this->capacity = (capacity % 3 == 0 || capacity % 2 == 0) ? capacity : capacity - 1;
        if (this->capacity < 3) {
            this->capacity = 3;
        }
    }

    int getCurrentNumRiders() { return currentNumRiders; }
    void setCurrentNumRiders(int currentNumRiders) { this->currentNumRiders = currentNumRiders; }

    bool isRideInProgress() { return rideInProgress; }
    void setRideInProgress(bool rideInProgress) { this->rideInProgress = rideInProgress; }

    // Member Functions
    int Load(int riders) {
        if (rideInProgress) {
            return -1;
        }

        if (riders > capacity) {
            int unseated = riders - capacity;
            setCurrentNumRiders(capacity);
            return unseated;
        } else {
            setCurrentNumRiders(riders);
            return 0; 
        }
    }

    int start() {
        if (rideInProgress) {
            return -1; 
        }

        if (currentNumRiders == capacity) {
            setRideInProgress(true);
            cout << "Ride is in progress!" << endl;
            return 0; 
        } else {
            int emptySeats = capacity - currentNumRiders;
            return emptySeats; 
        }
    }

    void stop() {
        if (rideInProgress) {
            setRideInProgress(false);
            cout << "Ride is not in progress!" << endl;
        }
    }

    void unloadRiders() {
        if (!rideInProgress) {
            setCurrentNumRiders(0);
            cout << "Passengers are unloaded!" << endl;
        }
    }

    void accelerate(int roll) {
        speed += (roll % 10);
        cout << "After accelerating, new speed: " << speed << "!" << endl;
    }
void decelerate(int roll) {
    int last_nonzero_num = roll/10;
    speed -= last_nonzero_num;
    if (speed < 0) {
        speed = 0;
    }
 cout << "Speed has been decreased!"<< endl; 
}
 void displayDetails() {
        cout << "Name: " << name << endl;
        cout << "Height: " << height << endl;
        cout << "Length: " << length << endl;
        cout << "Speed: " << speed << endl;
        cout << "Capacity: " << capacity << endl;
        cout << "Current riders: " << currentNumRiders << endl;
        cout << "Ride in progress: " << rideInProgress << endl;
        cout << "\n" << endl;
    }
};
int main() {

    cout << "Programmer: Hafsa Rashid" << endl << "Student ID: 23K-0064" << endl << endl;
    RollerCoaster obj1; 
    cout<<"Obj1 is being called by default constructor!"<<endl;
	obj1.displayDetails();
    cout<<"Obj2 is being called by parameterized constructor!"<<endl; 
    RollerCoaster obj2("SUPER ROLLER COASTER", 700, 2500, 25, 0, false, 0);
    obj2.displayDetails();
    obj2.Load(20);
	obj2.start();
    //using 64 in place of 0064 as it's giving octal number error.
	obj2.accelerate(64);
	obj2.decelerate(64);
    obj2.getCurrentNumRiders();
    obj2.stop();
    obj2.unloadRiders();
}

