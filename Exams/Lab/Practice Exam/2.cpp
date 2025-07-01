// Q.2 - Defines a Book class with private title, author, and price members. It has a parameterized constructor to initialize all values, 
// a destructor that prints a message when the object is destroyed, and a display() function to show book details.
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    float price;
    
public:
    // Parameterized constructor to initialize all data members
    Book(string t, string a, float p) 
    {
        title = t;
        author = a;
        price = p;
    }
    
    // Destructor that prints a message when object is destroyed
    ~Book() 
    {
        cout << "Book object destroyed" << endl;
    }
    
    // display() function to print all details of a book
    void display() 
    {
        cout << "Title: " << title << ", Author: " << author << ", Price: $" << price << endl;
    }
};
int main()
{
    Book b1("C++ Programming", "Mahir", 5000);
    Book b2("Data Structures", "Tusher", 6000);

    b1.display();
    b2.display();

    return 0;
}
