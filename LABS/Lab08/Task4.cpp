/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;

class Person {
public:
    string name;
    int age;
    Person(string name, int age) : name(name), age(age) {}
    void Display() {
        cout << "Name: " << name << endl;
        cout << "Age: " << age << endl;
    }
};

class Student : virtual public Person {
public:
    int ID;
    string grade;
    Student(string name, int age, int ID, string grade) : Person(name, age), ID(ID), grade(grade) {}
    void Display() {
        cout << "Student ID: " << ID << endl;
        cout << "Grade: " << grade << endl;
    }
};

class Teacher :virtual public Person {
public:
    string subject;
    int roomNo;
    Teacher(string name, int age, string subject, int roomNo) : Person(name, age), subject(subject), roomNo(roomNo) {}
    void Display() {
        cout << "Subject: " << subject << endl;
        cout << "Room Number: " << roomNo << endl;
    }
};

class GraduateStudent : public Student, public Teacher {
public:
    GraduateStudent(string name, int age, int ID, string grade, string subject, int roomNo) :Person(name, age), Student(name, age, ID, grade), Teacher(name, age, subject, roomNo) {}
    void Display() {
        Person::Display(); // Accessing the Display() function from the Person class
        Student::Display();
        Teacher::Display();
    }
};


int main() {
    GraduateStudent s1("Hafsa", 18, 64, "A+", "OOP", 4);
    s1.Display();
    return 0;
}
