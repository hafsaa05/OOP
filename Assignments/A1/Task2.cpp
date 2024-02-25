#include <iostream>
using namespace std;

class Table {
private:
    const int seatsCapacity;
    int occupiedSeats;
    int freeSeats;
    bool clean;

public:
    Table() : seatsCapacity(4), occupiedSeats(0), freeSeats(4), clean(true) {}

    Table(int capacity) : seatsCapacity((capacity == 8) ? 8 : 4), occupiedSeats(0), freeSeats(seatsCapacity), clean(true) {}

    int getSeatsCapacity() const { return seatsCapacity; }
    int getOccupiedSeats() const { return occupiedSeats; }
    int getFreeSeats() const { return freeSeats; }
    bool isClean() const { return clean; }

    void useTable(int people) {
        if (clean && freeSeats >= people) {
            occupiedSeats = people;
            freeSeats -= people;
            cout << "Table is available! Group of " << people << " is using the table." << endl;
        } else {
            cout << "Table is not available for the group." << endl;
        }
    }

    void haveLunch() {
        if (clean && occupiedSeats > 0) {
            cout << "HAVING LUNCH!" << endl;
            clean = false;
        } else {
            cout << "Table is not available for lunch." << endl;
        }
    }

    void leaveTable() {
        freeSeats += occupiedSeats;
        occupiedSeats = 0;
        cout << "Leaving the table." << endl;
    }

    void cleanTable() {
        if (occupiedSeats == 0) {
            clean = true;
            cout << "Table cleaned." << endl;
        } else {
            cout << "Cannot clean the table while someone is seated." << endl;
        }
    }
};

void OccupyTable(Table tables[5], int people) {
    for (int i = 0; i < 5; i++) {
        if (tables[i].isClean() && tables[i].getSeatsCapacity() >= people) {
            tables[i].useTable(people);
            cout << "Table with seat capacity of " << tables[i].getSeatsCapacity() << " has been occupied by " << people << "." << endl;
            return;
        }
    }
    cout << "No available table for the group." << endl;
}
void EmptyTable(Table tables[5], int index) {
    tables[index].leaveTable();
    tables[index].cleanTable();
}

int main() {
    cout << "Programmer: Hafsa Rashid" << endl << "Student ID: 23K-0064" << endl;
    cout << "\n";

    Table tables[5] = { Table(8), Table(8), Table(4), Table(4), Table(4) };

    OccupyTable(tables, 4);
    OccupyTable(tables, 6);

    tables[0].useTable(4);
    tables[0].haveLunch();
    tables[0].leaveTable();
    tables[0].cleanTable();

    EmptyTable(tables, 1);

    return 0;
}
