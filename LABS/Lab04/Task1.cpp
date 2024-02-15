/*Construct a class representing a Book, encompassing attributes like name, author, ISBN number,
and total page count, along with a variable tracking the number of pages read. Tasks include
defining constructors for the Book class - one default constructor and another parameterized
constructor initializing all attributes. Values can be hardcoded within the main function.
Additionally, implement a method to update the pages read, triggering a display of "You have
finished the book" when all pages are read. This method should be called from the main
function to monitor reading progress.*/
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
    // Default constructor
    Book() {
        name = "Unknown";
        author = "Unknown";
        ISBN = "Unknown";
        totalPages = 0;
        pagesRead = 0;
    }

    // Parameterized constructor
    Book(const string& bookName, const string& bookAuthor, const string& bookISBN, int totalPageCount) {
        name = bookName;
        author = bookAuthor;
        ISBN = bookISBN;
        totalPages = totalPageCount;
        pagesRead = 0;
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
    void display() {
        cout << "Name: " << name << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN Number: " << ISBN << endl;
        cout << "Current pages read: " << pagesRead << endl;
        cout << "Total pages: " << totalPages << endl;
    }
};

int main() {
    Book b1("Harry Potter", "J.K. Rowling", "978-3-16-148410-0", 850);
    b1.updatePagesRead(200);
    b1.display();

    return 0;
}
