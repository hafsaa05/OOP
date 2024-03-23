/*
Programmer: Hafsa Rashid
Student ID: 23K-0064
*/
#include<iostream>
using namespace std;
class Book{
public:
string title, author, publisher;
Book(string title, string author, string publisher): title(title), author(author), publisher(publisher) {}
void display(){
    cout<<"Title: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"Publisher: "<<publisher<<endl;
    }
};
class FictionBook: public Book{
public:
string genre, protagonist;
FictionBook (string title, string author, string publisher, string genre, string protagonist): Book(title, author, publisher), genre(genre), protagonist(protagonist) {}
void display(){
    cout<<"Title: "<<title<<endl;
    cout<<"Author: "<<author<<endl;
    cout<<"Publisher: "<<publisher<<endl;
    cout<<"Genre: "<<genre<<endl;
    cout<<"Protagonist: "<<protagonist<<endl;
}
};
int main() {
    FictionBook obj("Harry Potter", "J.K Rowling", "mystery", "Fantasy", "Hermione");
    obj.display();
}
