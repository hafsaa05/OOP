/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;

class Square {
private:
    float sideLength;
    float area;
    static float allareas;

public:
    Square() : sideLength(0), area(0) {}
    Square(float sideLength) : sideLength(sideLength) {
        calculateArea();
        allareas += area;
    }
    void calculateArea() {
        area = sideLength * sideLength;
    }
    float getLength() {
        return sideLength;
    }
    float getArea() {
        return area;
    }
    static float getAllAreas() {
        return allareas;
    }
    void setLength(float length) {
        sideLength = length;
        calculateArea();
        allareas += area;
    }
    void setArea(float newArea) {
        area = newArea;
        allareas += area;
    }
  static void setAllAreas(float newAllAreas) {
        allareas = newAllAreas;
    }
};
float Square::allareas = 0;

int main() {
    cout << "-------------FIRST SQUARE INFORMATION----------" << endl;
    Square s1(12);
    cout << "Side length: " << s1.getLength() << endl;
    cout << "Area: " << s1.getArea() << endl;
    cout << "All areas value: " << s1.getAllAreas() << endl;

    cout << "-------------SECOND SQUARE INFORMATION----------" << endl;
    Square s2(15);
    cout << "Side length: " << s2.getLength() << endl;
    cout << "Area: " << s2.getArea() << endl;
    cout << "All areas value: " << s2.getAllAreas() << endl;

    cout << "-------------THIRD SQUARE INFORMATION----------" << endl;
    Square s3(18);
    cout << "Side length: " << s3.getLength() << endl;
    cout << "Area: " << s3.getArea() << endl;
    cout << "All areas value: " << s3.getAllAreas() << endl;

    return 0;
}
