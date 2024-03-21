/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
#include<vector>
using namespace std;

class Course {
private:
    string code;
    string name;
    int credit_hours;
public:
    Course(string code, string name, int credit_hours) : code(code), name(name), credit_hours(credit_hours) {}
    int getCreditHours() const { return credit_hours; }
    string getCode() const { return code; }
    string getName() const { return name; }
};

class Student {
private:
    string ID, name;
    vector<Course> courses;
public:
    Student(string ID, string name) : ID(ID), name(name) {}

    void enroll(Course course) {
        courses.push_back(course);
        cout << course.getCode() << " is enrolled successfully" << endl;
    }

    void drop(Course course) {
        for (int i = 0; i < courses.size(); i++) {
            if (courses[i].getCode() == course.getCode()) {
                courses.erase(courses.begin() + i);
                cout << course.getCode() << " is dropped successfully" << endl;
                break;
            }
        }
    }

    int getTotalCreditHours() {
        int totalCreditHours = 0;
        for (int i = 0; i < courses.size(); i++)
            totalCreditHours += courses[i].getCreditHours();
        return totalCreditHours;
    }

    void printEnrolledCourses() {
        cout << "\nEnrolled Courses:" << endl;
        for (int i = 0; i < courses.size(); i++)
            cout << "Course: " << courses[i].getCode() << ", Name: " << courses[i].getName() << ", Credit Hours: " << courses[i].getCreditHours() << endl;
    }
};

int main() {
    Student student("23K-0064", "Hafsa");
    Course course1("CS-1001", "Object Oriented Programming", 3);
    Course course2("MT-2001", "Multivariable Calculus", 3);

    student.enroll(course1);
    student.enroll(course2);

    cout << "\nTotal Credit Hours: " << student.getTotalCreditHours() << endl;

    student.printEnrolledCourses();

    student.drop(course1);

    cout << "\nTotal Credit Hours after dropping a course: " << student.getTotalCreditHours() << endl;

    student.printEnrolledCourses();

    return 0;
}
