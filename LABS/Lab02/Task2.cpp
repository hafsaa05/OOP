#include<iostream>
using namespace std;
struct book{
	string title;
	string author;
	int year;
    string genre;
};
//a function to find a book by its title or author.
void find(book books[], int n) {
	string title;
	string author;
	cout<<"Enter book's name and author:"<<endl;
	cin>>title;
	cin>>author;
	
	int i;
	for (int i=0; i<n; i++) {
		if(books[i].title == title && books[i].author == author) {
			cout<<"TITLE: "<<books[i].title<<endl;
			cout<<"AUTHOR: "<<books[i].author<<endl;
			cout<<"GENRE: "<<books[i].genre<<endl;
			cout<<"YEAR: "<<books[i].year<<endl;
			break;
		} else {
			cout<<"Invalid Input. No book found."<<endl;
		}
	}
	
		}
	

//function to input new books.

void Add(book books[], int n) {
	int num;
	cout<<"Enter the number of books to be added: "<<endl;
	cin>>num;
	int i;
	for ( i=0; i<(n+num); i++) {
		cout<<"Enter book's title: "<<endl;
		cin>>books[i].title;
		cout<<"Enter book's author: "<<endl;
		cin>>books[i].author;
		cout<<"Enter book's year of publication: "<<endl;
		cin>>books[i].year;
		cout<<"Enter book's genre: "<<endl;
		cin>>books[i].genre;
	}
}
//funtion to update existing book data.

void Update(book books[], int n){
	string title;
	string author;
	cout<<"-------------------Starting To Update-------------------"<<endl;
	cout<<"Enter book's name and author:"<<endl;
	cin>>title;
	cin>>author;
	
	int i;
	for (i=0; i<n; i++) {
		if ( books[i].title==title && books[i].author==author) {
			cout<<"Now enter info to update existing book data:"<<endl;
			cout<<"--------------------------------------------"<<endl;
			cout<<"Enter book's title: "<<endl;
		    cin>>books[i].title;
	    	cout<<"Enter book's author: "<<endl;
	    	cin>>books[i].author;
		    cout<<"Enter book's year of publication: "<<endl;
		    cin>>books[i].year;
		    cout<<"Enter book's genre: "<<endl;
		    cin>>books[i].genre;
		    break;
		}
		
	}
}
//creating a function to display information about an array of book objects.
void Display(book books[], int num) {
    int i;
	for (i = 0; i<num; i++) {
        cout<<"TITLE: "<<books[i].title<<endl;
		cout<<"AUTHOR: "<<books[i].author<<endl;
		cout<<"GENRE: "<<books[i].genre<<endl;
		cout<<"YEAR: "<<books[i].year<<endl;
    }
}

int main() {
	int n;
	cout<<"Enter the number of books to be registered: "<<endl;
	cin>>n;
	
	book books[n];
	int i;
	for (i=0; i<n; i++) {
		cout<<"Enter book's title: "<<endl;
	    cin>>books[i].title;
	   	cout<<"Enter book's author: "<<endl;
	  	cin>>books[i].author;
        cout<<"Enter book's year of publication: "<<endl;
	    cin>>books[i].year;
	    cout<<"Enter book's genre: "<<endl;
	    cin>>books[i].genre;
	}
	int value;
    while (1) {
        cout << "1. Find\n2. Add\n3. Update\n4. Exit\n";
        cin >> value;

        switch (value) {
            case 1:
                find(books, n);
                break;

            case 2:
                Add(books, n);
                break;

            case 3:
                Update(books, n);
                break;

            case 4:
                return 0;

            default:
                cout << "Invalid Input." << endl;
                break;
        }
    }

    return 0;
}//end main
