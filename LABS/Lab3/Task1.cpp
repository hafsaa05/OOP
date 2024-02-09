#include<iostream>
using namespace std;

class BoardMarker {
private:
    string brand;
    string color;
    bool refillable;
    bool inkStatus;

public:
    // Setters
    void setB(string newB) {
        brand = newB;
    }

    void setCol(string newCol) {
        color = newCol;
    }

    void setRefillable(bool isR) {
        refillable = isR;
    }

    void setInkStatus(bool newInk) {
        inkStatus = newInk;
    }

    // Getters
    string getB() {
        return brand;
    }

    string getCol() {
        return color;
    }

    bool isR() {
        return refillable;
    }

    bool isInkDepleted() {
        return !inkStatus;
    }

    // Writing method
    void write() {
        if (inkStatus) {
            cout << "This " << color << " board marker is writing." << endl;
        } else {
            cout << "The ink is depleted." << endl;
        }
    }

    // Refill method
    void refill() {
        if (refillable) {
            cout << "Refilling board marker." << endl;
            inkStatus = true;
        } else {
            cout << "The marker can't be refilled." << endl;
        }
    }
};

int main() {
    BoardMarker m1("Zoro", "black", true);
    cout << "brand: " << m1.getB() << " ,color: " << m1.getCol() << " ,refillable: " << m1.isR() << endl;

    m1.write();
    m1.setInkStatus(false);
    m1.write();
    m1.refill();

    BoardMarker m2("Dollar", "blue", false);
    m2.refill();

    return 0;
}
