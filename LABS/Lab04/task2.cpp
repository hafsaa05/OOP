/*Revise the previous Book class by eliminating the parameterized constructor and enhancing the
default constructor. The revised default constructor should initialize the page count to 1000
and the pages read to 0 using a member initialization list. Generate setter methods for the
remaining attributes and utilize them within the main function to update attribute values. Introduce
a method called "showBookInfo" to exhibit all book details. Invoke this method from the main
function for displaying book information.*/
#include<iostream>
using namespace std;

class Book {
private:
    string name;
    string author;
    string ISBN;
    int totalPages;
    int pagesRead;

public:
    // Default constructor with member initialization list
    Book() : name("Unknown"), author("Unknown"), ISBN("Unknown"), totalPages(1000), pagesRead(0) {}

    // Setter methods
    void setName(const string& bookName) {
        name = bookName;
    }

    void setAuthor(const string& bookAuthor) {
        author = bookAuthor;
    }

    void setISBN(const string& bookISBN) {
        ISBN = bookISBN;
    }

    void setTotalPages(int totalPageCount) {
        totalPages = totalPageCount;
    }

    // Function to update pages read
    void updatePagesRead(int pages) {
        pagesRead += pages;
        if (pagesRead >= totalPages) {
            cout << "You have finished the book!" << endl;
        } else {
            cout << "You have read " << pagesRead << " pages. Keep going!" << endl;
        }
    }

    // Function to display info
    void showBookInfo() {
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN Number: " << ISBN << endl;
        cout << "Current pages read: " << pagesRead << endl;
        cout << "Total pages: " << totalPages << endl;
    }
};

int main() {
    Book b1;
    b1.setName("Harry Potter");
    b1.setAuthor("J.K. Rowling");
    b1.setISBN("978-3-16-148410-0");
    b1.updatePagesRead(200);
    b1.showBookInfo();

    return 0;
}
