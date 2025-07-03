/*
1. As you have seen, when a member function refers to another member of a class, it does
so directly without qualifying the member with either a class or an object specifcation.
For example, examine this short program, which creates a simple inventory class:
*/
// Demonstrate the this pointer .
#include <iostream>
#include <cstring>
using namespace std;

class inventory
{
    char item[20];
    double cost;
    int on_hand;

public:
    inventory(const char *i, double c, int o)
    {
        strcpy(item, i);
        cost = c;
        on_hand = o;
    }
/*

The constructor uses the implicit this pointer to assign values to the object’s data members:

strcpy(this->item, i);     // this->item = i
this->cost = c;
this->on_hand = o;
Note: Although this isn’t written explicitly, it is always there behind the scenes in non-static member functions.

*/
    void show()
    {
    cout << item;
    cout << ": $" << cost;
    cout << " On hand : " << on_hand << "\n";
    }
/*
Again, the function uses class members directly (item, cost, on_hand), but the compiler interprets this as:

cout << this->item;
cout << ": $" << this->cost;
cout << " On hand : " << this->on_hand << "\n";
*/
};

int main()
{
    inventory ob("wrench", 4.95, 4);

    ob.show();

    return 0;
}