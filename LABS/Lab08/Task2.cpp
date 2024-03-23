/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;
class Character{
public:
int health, damage;
Character(int health, int damage): health(health), damage(damage){}
void Display(){
    cout<<"Health:"<<health<<endl;
    cout<<"Damage: "<<damage<<endl;
}
};
class Enemy: public Character{
public:
Enemy(int health, int damage):Character(health, damage){}
void Display(){
    cout<<"Health:"<<health<<endl;
    cout<<"Damage: "<<damage<<endl;
}
};
class Player: public Character{
public:
Player(int health, int damage):Character(health, damage){}
void Display(){
    cout<<"Health:"<<health<<endl;
    cout<<"Damage: "<<damage<<endl;
}
};
class Wizard: public Player{
public:
int magic_power; string spells;
Wizard(int health, int damage, int magic_power, string spells):Player(health, damage), magic_power(magic_power), spells(spells){}
void Display(){
    cout<<"Health:"<<health<<endl;
    cout<<"Damage: "<<damage<<endl;
    cout<<"Magic Power: "<<magic_power<<endl;
    cout<<"Spells: "<<spells<<endl;
}
};
int main(){
    Wizard obj(100, 0, 25, "Expecto Patronum !");
    obj.Display();
}
