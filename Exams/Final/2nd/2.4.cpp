//Q2 (d)
//Complete Book Class (with Copy Constructor)
#include <iostream>
#include <string>
using namespace std;

class Book {
private:
    string title;
    string author;
    float price;
public:
    Book(string t, string a, float p) {   // parameterized constructor
        title = t; author = a; price = p;
    }
    Book(const Book &b) {   // copy constructor
        title = b.title;
        author = b.author;
        price = b.price;
    }
    void display() {
        cout << "Title: " << title << ", Author: " << author << ", Price: " << price << endl;
    }
};