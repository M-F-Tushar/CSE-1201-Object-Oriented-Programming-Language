//Q5 (c)
//Library Class with Overloaded searchBook()
#include <iostream>
#include <string>
using namespace std;

class Library {
public:
    void searchBook(string title) {
        cout << "Searching book by title: " << title << endl;
    }
    void searchBook(string author, bool byAuthor) {
        if(byAuthor)
            cout << "Searching book by author: " << author << endl;
    }
    void searchBook(int ISBN) {
        cout << "Searching book by ISBN: " << ISBN << endl;
    }
};

int main() {
    Library lib;
    lib.searchBook("C++ Basics");
    lib.searchBook("Bjarne Stroustrup", true);
    lib.searchBook(12345);
}