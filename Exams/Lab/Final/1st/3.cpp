/*
Pr.3 [15 Marks]

Write a program to implement the campervan (represents a large motor vehicle with living accommodation) 
class from two base classes house and van. Each of the classes will hold the minimum properties by their associated member functions described by their name. Any inclusion in this program is acceptable.
*/
// Pr3_Campervan.cpp
#include <iostream>
using namespace std;

class House {
public:
    int numRooms;
    House(int rooms=1) : numRooms(rooms) {}
    void showHouse() const { cout << "House part: rooms=" << numRooms << "\n"; }
};

class Van {
public:
    double engineCC;
    Van(double cc=1000) : engineCC(cc) {}
    void showVan() const { cout << "Van part: engine=" << engineCC << " cc\n"; }
};

// campervan inherits both
class Campervan : public House, public Van {
public:
    Campervan(int rooms, double cc) : House(rooms), Van(cc) {}
    void show() const {
        cout << "Campervan details:\n";
        showHouse();
        showVan();
    }
};

int main() {
    Campervan c(2, 2000.0);
    c.show();
    return 0;
}
