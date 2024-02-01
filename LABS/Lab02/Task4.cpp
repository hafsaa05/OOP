//Your task is to implement a basic Student Registration System in C++. Define two
structures, Register and Student, where Register includes attributes courseId and
courseName, and Student inherits from Register while having additional attributes
such as studentId, firstName, lastName, cellNo, and email. Your objective is to
create an array of Student structures to store data for five students. Write a C++
program that accomplishes the following tasks:
1. Implement the Register and Student structures.
2. Inherit the Register structure in the Student structure.
3. Create an array of Student structures to store data for 5 students.
4. Take input for each student, including their courseId, courseName,
studentId, firstName, lastName, cellNo, and email.
5. Display the information for all 5 students.

#include <iostream>
using namespace std;

// Define the Register structure
struct Register {
    string courseId;
    string courseName;
};

// Define the Student structure inheriting from Register
struct Student : Register {
    string studentId;
    string firstName;
    string lastName;
    long cellNo;  // Changed data type to long
    string email;
};

int main() {
    // Create an array of Student structures to store data for 5 students
    Student students[5];

    // Take input for each student
    for (int i = 0; i < 5; i++) {
        cout << "Enter data for Student " << i + 1 << ":" << endl;

        cout << "Course ID: ";
        getline(cin, students[i].courseId);

        cout << "Course Name: ";
        getline(cin, students[i].courseName);

        cout << "Student ID: ";
        getline(cin, students[i].studentId);

        cout << "First Name: ";
        getline(cin, students[i].firstName);

        cout << "Last Name: ";
        getline(cin, students[i].lastName);

        cout << "Cell no: ";
        cin >> students[i].cellNo;

        cout << "Email: ";
        cin.ignore(); // Clear the newline character left in the buffer
        getline(cin, students[i].email);
    }

    // Display the information for all 5 students
    cout << "\nStudent Information:\n";
    for (int i = 0; i < 5; i++) {
        cout << "Student " << i + 1 << ":\n";
        cout << "Course ID: " << students[i].courseId << endl;
        cout << "Course Name: " << students[i].courseName << endl;
        cout << "Student ID: " << students[i].studentId << endl;
        cout << "First Name: " << students[i].firstName << endl;
        cout << "Last Name: " << students[i].lastName << endl;
        cout << "Cell no: " << students[i].cellNo << endl;
        cout << "Email: " << students[i].email << endl;
        cout << "-------------------------\n";
    }

    return 0;
}
