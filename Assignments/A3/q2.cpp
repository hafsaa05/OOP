#include<iostream>
using namespace std;
template <class T> class Pet{

private:
string name;
T age;

public:
Pet(string name,T age): name(name), age(age) {}

virtual void makeSound() = 0;

virtual void displayInfo() {
    cout << "Name: " << name << endl
         << "Age: " << age << endl;
    }
};

template <class T> class Cat: public Pet<T> {

public:
Cat(string name,T age): Pet<T>(name , age){}

void makeSound() override{
    cout<<"Meow!"<<endl;
}

void displayInfo() override {
    Pet<T>::displayInfo();
}
};

template <class T> class Dog: public Pet<T> {

public:
Dog(string name,T age): Pet<T>(name , age){}

void makeSound() override{
    cout<<"Woof!"<<endl;
}

void displayInfo() override {
    Pet<T>::displayInfo();
}

};

template <class T> class Bird: public Pet<T> {

public:
Bird(string name,T age): Pet<T>(name , age){}

void makeSound() override{
    cout<<"Chirp!"<<endl;
}

void displayInfo() override {
    Pet<T>::displayInfo();
}
};

int main(){
    cout << "Name: Hafsa Rashid" << endl << "Student ID: 23K-0064" << endl;
    cout<<"\n";
    Cat<int> c1("Kitty", 2);
    c1.displayInfo();
    c1.makeSound();

    Dog<double> d1("Puppy", 3.6);
    d1.displayInfo();
    d1.makeSound();
    
    Bird<float> b1("Robin", 1.5);
    b1.displayInfo();
    b1.makeSound();

}




