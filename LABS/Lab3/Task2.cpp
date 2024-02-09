#include <iostream>
#include <string>
using namespace std;

class WBottle {
private:
    string b;
    string c;
    double l;
    double ml;

public:
    // Constructor
    WBottle(string b, string c, double l, double ml)
        : b(b), c(c), l(l), ml(ml) {}

    // Getter methods
    string getB() {
        return b;
    }

    string getC() {
        return c;
    }

    double getL() {
        return l;
    }

    double getML() {
        return ml;
    }

    // Setter methods
    void setB(string newB) {
        b = newB;
    }

    void setC(string newC) {
        c = newC;
    }

    void setL(double newL) {
        l = newL;
    }

    void setML(double newML) {
        ml = newML;
    }

    void consumeW(double amtML) {
        if (amtML <= ml) {
            ml -= amtML;
            // Update water capacity in liters
            l = ml / 1000.0;
            cout << "Water is consumed. Remaining capacity is : " << l << " liters." << endl;
        } else {
            cout << "There's not enough water in bottle." << endl;
        }
    }
};

int main() {
    // Example usage
    WBottle b("Aquafina", "Blue", 1.5, 1500);

    cout << "Brand: " << b.getB() << ", Color: " << b.getC()
        << ", Water Capacity: " << b.getL() << " liters" << endl;

    b.consumeW(500);  

    b.setML(1000);  
    cout << "Updated Water Capacity: " << b.getL() << " liters" << endl;

    b.consumeW(1200); 
    return 0;
}
