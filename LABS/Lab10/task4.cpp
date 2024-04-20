/*
Name: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;

class perimeter{
int length = 3, breadth = 4;
public:
friend class printClass;
};

class printClass{
public:
void display(perimeter& other){
    cout<<"Length: "<<other.length<<endl;
    cout<<"breadth: "<<other.breadth<<endl;
}
};

int main(){

    printClass obj1;
    perimeter obj2;
    obj1.display(obj2);
    return 0;
}
