// A simple example of inheritance .
#include <iostream>
using namespace std;
// Define base class .
class B
{
    int i;

public:
    void set_i(int n)
    {
        i = n;
    };
    int get_i()
    {
        return i;
    };
};
// Define derived class .
class D : public B
{
    int j;

public:
    void set_j(int n)
    {
        j = n;
    };
    int mul()
    {
        // derived class can call base class public member functions
        return j * get_i();
    };
};

int main()
{
    D ob;

    ob.set_i(10);     // load i in base
    ob.set_j(4);     // load j in derived
    
    cout << ob.mul(); // displays 40
    return 0;
}