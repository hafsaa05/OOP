#include <iostream>

using namespace std;

class Calendar {
private:
    int currentYear;
    string jan[30];
    string feb[30];
    string march[30];
    string april[30];
    string may[30];
    string jun[30];
    string jul[30];
    string aug[30];
    string sep[30];
    string nov[30];
    string oct[30];
    string dec[30];

    void showOneMonth(string month[30]) {
        for (int i = 0; i < 30; i++) {
            if (month[i].size() > 0) {
                cout << month[i] << "  ";
            }
        }
        cout << endl;
    }

public:
    Calendar(int year) : currentYear(year) {}

    void addTask(int day, int month, const string& task) {
        switch(month) {
            case 1:
                jan[day - 1] = task;
                break;
            case 2:
                feb[day - 1] = task;
                break;
            case 3:
                march[day - 1] = task;
                break;
            case 4:
                april[day - 1] = task;
                break;
            case 5:
                may[day - 1] = task;
                break;
            case 6:
                jun[day - 1] = task;
                break;
            case 7:
                jul[day - 1] = task;
                break;
            case 8:
                aug[day - 1] = task;
                break;
            case 9:
                sep[day - 1] = task;
                break;
            case 10:
                nov[day - 1] = task;
                break;
            case 11:
                oct[day - 1] = task;
                break;
            case 12:
                dec[day - 1] = task;
                break;
        }
    }

    void removeTask(int day, int month) {
        switch(month) {
            case 1:
                jan[day - 1] = "";
                break;
            case 2:
                feb[day - 1] = "";
                break;
            case 3:
                march[day - 1] = "";
                break;
            case 4:
                april[day - 1] = "";
                break;
            case 5:
                may[day - 1] = "";
                break;
            case 6:
                jun[day - 1] = "";
                break;
            case 7:
                jul[day - 1] = "";
                break;
            case 8:
                aug[day - 1] = "";
                break;
            case 9:
                sep[day - 1] = "";
                break;
            case 10:
                nov[day - 1] = "";
                break;
            case 11:
                oct[day - 1] = "";
                break;
            case 12:
                dec[day - 1] = "";
                break;
        }
    }

    void displayTasks() {
        showOneMonth(jan);
        showOneMonth(feb);
        showOneMonth(march);
        showOneMonth(april);
        showOneMonth(may);
        showOneMonth(jun);
        showOneMonth(jul);
        showOneMonth(aug);
        showOneMonth(sep);
        showOneMonth(oct);
        showOneMonth(nov);
        showOneMonth(dec);
    }
};

int main() {
    Calendar myCalendar(2024);

    myCalendar.addTask(6, 7, "celebrate my birthday");
    myCalendar.addTask(15, 2, "important tasks");
    myCalendar.addTask(10, 3, "study");
    myCalendar.addTask(11, 3, "eat food");
    myCalendar.removeTask(11, 3);
    myCalendar.addTask(11, 3, "go out to eat food");

    myCalendar.displayTasks();

    return 0;
}
