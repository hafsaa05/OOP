/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;
class Position{
    public:
    int x, y, z;
    Position(int x, int y, int z): x(x), y(y), z(z){}
};
class Health{
    public:
    int health;
    Health(int health): health(health){}

};
class Character:public Position, public Health{
public:
string name;
int power, speed;
Character(string name, int x, int y, int z,int health,int power, int speed): Position(x, y, z), Health(health), name(name), power(power), speed(speed){}
void Display(){
    cout<<"Name: "<<name<<endl;
    cout<<"Position: "<<x<<", "<<y<<", "<<z<<"."<<endl;
    cout<<"Health: "<<health<<endl;
    cout<<"Power: "<<power<<endl;
    cout<<"Speed: "<<speed<<endl;
}
};
int main(){
Character obj("Arisu", 12, 14, 16, 80, 50, 99);
obj.Display();
}
