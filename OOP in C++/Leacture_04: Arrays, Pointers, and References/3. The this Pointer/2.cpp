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
        strcpy(this->item, i); // access members
        this->cost = c;        // through the this
        this->on_hand = o;     // pointer
    }
    void show();
};
void inventory ::show()
{
    cout << item;
    cout << ": $" << cost;
    cout << " On hand : " << on_hand << "\n";         
}
int main()
{
    inventory ob("wrench", 4.95, 4);

    ob.show();
    
    return 0;
}