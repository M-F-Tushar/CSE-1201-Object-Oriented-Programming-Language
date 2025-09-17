/*
Pr.4 [15 Marks]

Consider an example of a bookshop that sells regular books and audiobooks. These two classes are inherited from the base class media. The media class
has common data members such as title and publication. The book class has data members for storing a number of pages in a book, and the audio class 
has data members for storing the playing time. Each class will have member functions such as read() and show(). In the base class, these members have to be defined as virtual 
functions. Write a program that models the class hierarchy for the bookshop and processes objects of these classes using pointers to the base class.
*/
#include <iostream>
#include <string>
using namespace std;

class Media {
public:
    string title;
    string publication;
    Media(const string& t="", const string& p="") : title(t), publication(p) {}
    virtual void read() = 0;   // pure virtual
    virtual void show() = 0;   // pure virtual
    virtual ~Media() {}
};

class Book : public Media {
    int pages;
public:
    Book(const string& t, const string& p, int pg)
        : Media(t,p), pages(pg) {}
    
    void read() override {
        cout << "Reading book \"" << title << "\" (" << pages << " pages)\n";
    }
    
    void show() override {
        cout << "Book: " << title << ", pub: " << publication << ", pages: " << pages << "\n";
    }
};

class Audio : public Media {
    double playTime; // minutes
public:
    Audio(const string& t, const string& p, double tmin)
        : Media(t,p), playTime(tmin) {}
    
    void read() override {
        cout << "Loading audio \"" << title << "\" (" << playTime << " min)\n";
    }
    
    void show() override {
        cout << "Audio: " << title << ", pub: " << publication << ", playtime: " << playTime << " min\n";
    }
};

int main() {
    // Create objects
    Media* book1 = new Book("C++ Basics", "TechPub", 350);
    Media* audio1 = new Audio("Learn C++", "AudioPub", 45.5);

    // Process objects manually
    book1->show();
    book1->read();
    cout << "-----\n";

    audio1->show();
    audio1->read();
    cout << "-----\n";

    // Clean up memory
    delete book1;
    delete audio1;

    return 0;
}
