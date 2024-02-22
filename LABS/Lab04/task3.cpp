/*
Programmer: Hafsa Rashid
Student ID: 23K-0064

Develop a class called WeekDays containing private data members - a string array named Days
for the days of the week and an integer variable named CurrentDay for the current day. Create
the following constructors and member functions for the class: a Default Constructor initializing
the Days array from Sunday to Saturday, a Parameterized Constructor accepting an integer value
for CurrentDay, performing a modulus operation to adjust if the value exceeds 6, and initializing
the Days array accordingly. Additional member functions include getCurrentDay, getNextDay,
getPreviousDay, and getNthDayFromToday.*/
#include <iostream>
#include <cstdlib>  
using namespace std;

class WeekDays {
private:
    string Days[7];
    int CurrentDay;

public:
    // Default Constructor
    WeekDays() {
        Days[0] = "Sunday";
        Days[1] = "Monday";
        Days[2] = "Tuesday";
        Days[3] = "Wednesday";
        Days[4] = "Thursday";
        Days[5] = "Friday";
        Days[6] = "Saturday";
        CurrentDay = 0;  // initializing CurrentDay to Sunday by default
    }

    // Parameterized Constructor
    WeekDays(int day) {
        if (day > 6 || day < 0) {
            cout << "Invalid input.";
            exit(EXIT_FAILURE);
        } else {
            Days[0] = "Sunday";
            Days[1] = "Monday";
            Days[2] = "Tuesday";
            Days[3] = "Wednesday";
            Days[4] = "Thursday";
            Days[5] = "Friday";
            Days[6] = "Saturday";
            CurrentDay = day;
        }
    }

    void GetCurrentDay() {
        cout << "Current Day: " << Days[CurrentDay] << endl;
    }

    void GetNextDay() {
        int nextDay = (CurrentDay + 1) % 7;
        cout << "Next Day: " << Days[nextDay] << endl;
    }

    void getPreviousDay() {
        int previousDay = (CurrentDay - 1 + 7) % 7;  
        cout << "The previous day is " << Days[previousDay] << endl;
    }

    void getNthDay(int addDays) {
        cout << "The Nth day from " << Days[CurrentDay] << " is " << Days[(CurrentDay + addDays) % 7] << endl;
    }

    void GetNthDay() {
        int n;
        cout << "Enter the number of days from today: ";
        cin >> n;
        int nthDay = (CurrentDay + n) % 7;
        cout << "Day after " << n << " days is: " << Days[nthDay] << endl;
    }
};

int main() {
    WeekDays d1(4);
    d1.GetCurrentDay();
    d1.GetNextDay();
    d1.getPreviousDay();
    d1.getNthDay(3);  
    d1.GetNthDay();  

    return 0;
}
