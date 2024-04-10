/*
Name: Hafsa Rashid
Student ID: 23K-0064
*/
#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

class Shape {
public:
    virtual double area() const = 0;
    virtual double perimeter() const = 0;
    virtual void displayProperties() const = 0;
};

class Circle : public Shape {
private:
    double radius;

public:
    Circle(double r) : radius(r) {}

    double area() const override {
        return M_PI * radius * radius;
    }

    double perimeter() const override {
        return 2 * M_PI * radius;
    }

    void displayProperties() const override {
        cout << fixed << setprecision(4);
        cout << "- Area: " << area() << endl;
        cout << "- Perimeter: " << perimeter() << endl;
        cout << "- Diameter: " << 2 * radius << endl;
    }
};

class Rectangle : public Shape {
private:
    double length;
    double width;

public:
    Rectangle(double l, double w) : length(l), width(w) {}

    double area() const override {
        return length * width;
    }

    double perimeter() const override {
        return 2 * (length + width);
    }

    void displayProperties() const override {
        double diagonal = sqrt(length * length + width * width);
        cout << fixed << setprecision(4);
        cout << "- Area: " << area() << endl;
        cout << "- Perimeter: " << perimeter() << endl;
        cout << "- Diagonal: " << diagonal << endl;
    }
};

class Square : public Rectangle {
public:
    Square(double s) : Rectangle(s, s) {}
};

class Triangle : public Shape {
protected:
    double side1, side2, side3;

public:
    Triangle(double s1, double s2, double s3) : side1(s1), side2(s2), side3(s3) {}

    double area() const override {
        double s = (side1 + side2 + side3) / 2;
        return sqrt(s * (s - side1) * (s - side2) * (s - side3));
    }

    double perimeter() const override {
        return side1 + side2 + side3;
    }

    void displayProperties() const override {
        cout << fixed << setprecision(4);
        cout << "- Area: " << area() << endl;
        cout << "- Perimeter: " << perimeter() << endl;
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(double side) : Triangle(side, side, side) {}
};

int main() {
    cout << "Welcome to the Geometry Competition Calculator!" << endl;
    string choice;

    do {
        cout << "Please select a shape:" << endl;
        cout << "1. Circle" << endl;
        cout << "2. Rectangle" << endl;
        cout << "3. Square" << endl;
        cout << "4. Triangle" << endl;

        int option;
        cout << "Enter your choice: ";
        cin >> option;

        switch (option) {
            case 1: {
                double radius;
                cout << "Enter the radius of the circle: ";
                cin >> radius;
                Shape* shape = new Circle(radius);
                cout << "Properties of the Circle:" << endl;
                shape->displayProperties();
                delete shape;
                break;
            }
            case 2: {
                double length, width;
                cout << "Enter the length of the rectangle: ";
                cin >> length;
                cout << "Enter the width of the rectangle: ";
                cin >> width;
                Shape* shape = new Rectangle(length, width);
                cout << "Properties of the Rectangle:" << endl;
                shape->displayProperties();
                delete shape;
                break;
            }
            case 3: {
                double side;
                cout << "Enter the side length of the square: ";
                cin >> side;
                Shape* shape = new Square(side);
                cout << "Properties of the Square:" << endl;
                shape->displayProperties();
                delete shape;
                break;
            }
            case 4: {
                double side1, side2, side3;
                cout << "Enter the lengths of the three sides of the triangle: ";
                cin >> side1 >> side2 >> side3;
                Shape* shape = new Triangle(side1, side2, side3);
                cout << "Properties of the Triangle:" << endl;
                shape->displayProperties();
                delete shape;
                break;
            }
            default:
                cout << "Invalid choice!" << endl;
        }

        cout << "Do you want to calculate properties for another shape? (yes/no): ";
        cin >> choice;
    } while (choice == "yes");

    cout << "Thank you for using the Geometry Competition Calculator!" << endl;

    return 0;
}
