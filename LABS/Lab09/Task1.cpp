/*
  Name: Hafsa Rashid
  Student ID: 23K-0064
  */
#include<iostream>
#include<cmath>
using namespace std;

const double PI = 3.142; 

class Shape {
public:
    double areaCircle(double radius) {
        return PI * pow(radius, 2); 
    }

    double areaRectangle(double length, double width) {
        return length * width; 
    }

    double areaTriangle(double base, double height) {
        return 0.5 * base * height;
    }

    double perimeterCircle(double radius) {
        return 2 * PI * radius; // Perimeter of a circle = 2 * pi * radius
    }

    double perimeterRectangle(double length, double width) {
        return 2 * (length + width); 
    }

    double perimeterTriangle(double side1, double side2, double side3) {
        return side1 + side2 + side3; 
    }
};

int main() {
    Shape shape;    
    double radiusCircle = 6.5; 
    double lengthRectangle = 7.3; 
    double widthRectangle = 4.8; 
    double baseTriangle = 5.7; 
    double heightTriangle = 8.2; 
    double side1Triangle = 7.4, side2Triangle = 9.1, side3Triangle = 6.3; 

    cout << "Area of Circle: " << shape.areaCircle(radiusCircle) << endl;
    cout << "Perimeter of Circle: " << shape.perimeterCircle(radiusCircle) << endl;

    cout << "Area of Rectangle: " << shape.areaRectangle(lengthRectangle, widthRectangle) << endl;
    cout << "Perimeter of Rectangle: " << shape.perimeterRectangle(lengthRectangle, widthRectangle) << endl;

    cout << "Area of Triangle: " << shape.areaTriangle(baseTriangle, heightTriangle) << endl;
    cout << "Perimeter of Triangle: " << shape.perimeterTriangle(side1Triangle, side2Triangle, side3Triangle) << endl;

    return 0;
}
