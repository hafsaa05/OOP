/*
Name: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;

class Logo{
    string logo;
    public:
    Logo() {  
           logo="Blue Bird";
    }
    friend class Platform;
    void display() {
        cout << "Logo: " << logo << endl;
    }
};

class Platform{
    string platform;
    public:
    Platform(string p): platform(p){}
    void change(Logo& other){
        other.logo = "Doge Coin";
    }
    void display() {
        cout << "Platform: " << platform << endl;
    }
};

class Server{
    string server;
    public:
    Server(string s): server(s){};
    void display() {
        cout << "Server: " << server << endl;
    }
};


int main(){
    Platform p1("Twitter");
    Logo l1;
    Server s1("123.456.789.0");

    cout<<"\t\tBEFORE"<<endl;
    p1.display();
    l1.display();
    s1.display();

    //changing the logo
    p1.change(l1);

    cout << "\t\tAFTER" << endl;
    p1.display();
    l1.display(); 
    s1.display();
}
