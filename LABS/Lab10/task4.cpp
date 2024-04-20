/*
Name: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;

class perimeter{
int length, breadth;
public:
perimeter(int l, int b): length(l), breadth(b){};
friend class printClass;
};

class printClass{
public:
void display(perimeter& other){
    cout<<"Length: "<<other.length<<endl<<"breadth: "<<other.breadth<<endl;
}
};

int main(){

    printClass obj1;
    perimeter obj2(3, 4);
    obj1.display(obj2);
    return 0;
}
