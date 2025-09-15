/*
Pr.4 [15 Marks]

Consider an example of a bookshop that sells regular books and audiobooks. These two classes are inherited from the base class media. The media class
has common data members such as title and publication. The book class has data members for storing a number of pages in a book, and the audio class 
has data members for storing the playing time. Each class will have member functions such as read() and show(). In the base class, these members have to be defined as virtual 
functions. Write a program that models the class hierarchy for the bookshop and processes objects of these classes using pointers to the base class.
*/
// Pr4_Media.cpp
#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Media {
public:
    string title;
    string publication;
    Media(const string& t="", const string& p="") : title(t), publication(p) {}
    virtual void read() = 0; // pure virtual
    virtual void show() = 0; // pure virtual
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
    void read() override { // for audio, read = load/play info
        cout << "Loading audio \"" << title << "\" (" << playTime << " min)\n";
    }
    void show() override {
        cout << "Audio: " << title << ", pub: " << publication << ", playtime: " << playTime << " min\n";
    }
};

int main() {
    vector<unique_ptr<Media>> shop;
    shop.emplace_back(make_unique<Book>("C++ Basics", "TechPub", 350));
    shop.emplace_back(make_unique<Audio>("Learn C++", "AudioPub", 45.5));

    for (auto &item : shop) {
        item->show();
        item->read();
        cout << "-----\n";
    }
    return 0;
}
