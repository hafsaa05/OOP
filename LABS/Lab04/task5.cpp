/*
Programmer: Hafsa Rashid
Student ID: 23K-0064

Instantiate a class named Office to represent attributes of an office space, including Location
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
    string* Furniture;

public:

    Office(string l = " ", int seat = 0, int furnitureSize = 3, string fur1 = "", string fur2 = "", string fur3 = "")
        : Location(l), SeatingCapacity(seat), Furniture(new string[furnitureSize]) {
        Furniture[0] = fur1;
        Furniture[1] = fur2;
        Furniture[2] = fur3;
    }

    ~Office() {
        delete[] Furniture;
    }

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
    Office* office1 = new Office("Karachi", 50, 3, "Table", "Chairs", "Fans");
    Office* office2 = new Office("Islamabad", 25, 3, "Cupboard", "Chairs", "Sofas");
    Office* office3 = new Office("Lahore", 25, 3, "Clock", "Bookshelf");

    cout << "Office 1 Info:\n";
    office1->DisplayInfo();
    cout << "\nOffice 2 Info:\n";
    office2->DisplayInfo();
    cout << "\nOffice 3 Info:\n";
    office3->DisplayInfo();

    delete office1;
    delete office2;
    delete office3;

    return 0;
}
