/*Instantiate a class named Office to represent attributes of an office space, including Location
(default value: " "), SeatingCapacity (default value: 0), and Furniture (a string array with a
size of 3, default: {"", "", ""}). Implement a parameterized constructor assigning default values to
all attributes using a member initialization list. Create multiple instances of the Office class using
different numbers of constructor arguments.*/
#include<iostream>
using namespace std;

class Office {
private:
    string Location;
    int SeatingCapacity;
    string Furniture[3];

public:
    // Parameterized constructor with default values
    Office(string l = " ", int seat = 0, string fur1 = "", string fur2 = "", string fur3 = "")
        : Location(l), SeatingCapacity(seat), Furniture{fur1, fur2, fur3} {};

    void DisplayInfo() {
 
        cout << "Location: " << Location << endl;
        cout << "Seating Capacity: " << SeatingCapacity << endl;
        cout << "Furniture: \n";
        for (int i = 0; i < 3; i++) {
            if (!Furniture[i].empty()) {
                cout << Furniture[i] << endl;
            }
        }
    }
};

int main() {
    Office office1("Karachi", 50, "Table", "Chairs", "Fans");  
    Office office2("Islamabad", 25, "Cupboard", "Chairs", "Sofas");  
    Office office3("Lahore", 25, "Clock", "Bookshelf");
    cout << "Office 1 Info:\n";
    office1.DisplayInfo();

    cout << "\nOffice 2 Info:\n";
    office2.DisplayInfo();

    cout << "\nOffice 3 Info:\n";
    office3.DisplayInfo();

    return 0;
}
