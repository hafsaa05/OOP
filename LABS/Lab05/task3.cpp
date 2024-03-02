/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include <iostream>
#include <cstring>
using namespace std;

class StringValidator {
private:
    char* str;

public:
    StringValidator(const char* input) {
        str = new char[strlen(input) + 1];
        strcpy(str, input);
    }

    ~StringValidator() {
        delete[] str;
    }

    bool isValid() const {
        const char* ptr = str;
        while (*ptr != '\0') {
            if (!(((*ptr) >= 'A' && (*ptr) <= 'Z') || ((*ptr) >= 'a' && (*ptr) <= 'z'))) {
                return false;
            }
            ptr++;
        }
        return true;
    }
};

int main() {
    StringValidator validator1("hey there");
    if (validator1.isValid()) {
        cout << "String 1 is valid." << endl;
    } else {
        cout << "String 1 is invalid." << endl;
    }

    StringValidator validator2("HELLOOO");
    if (validator2.isValid()) {
        cout << "String 2 is valid." << endl;
    } else {
        cout << "String 2 is invalid." << endl;
    }

    StringValidator validator3("h3ll00");
    if (validator3.isValid()) {
        cout << "String 3 is valid." << endl;
    } else {
        cout << "String 3 is invalid." << endl;
    }

    return 0;
}
