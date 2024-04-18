/*
Name: Hafsa Rashid
Student ID: 23K-0064
*/
#include <iostream>
using namespace std;

class Shape {
public:
    int rad;
    double area; 
    Shape() : rad(0), area(0) {}
    Shape(int r) : rad(r), area(0) {}

    void calculateArea() {
        area = 3.142 * rad * rad;
    }

    Shape operator+(const Shape& obj) const {
        Shape temp;
        temp.area = this->area + obj.area;
        return temp;
    }

    void display() const {
        cout << "The combined Areas are: " << area << endl;
    }
};

int main() {
    Shape shape1(23), shape2(34), combinedArea;
    shape1.calculateArea();
    shape2.calculateArea();
    combinedArea = shape1 + shape2;
    combinedArea.display();

    return 0;
}
