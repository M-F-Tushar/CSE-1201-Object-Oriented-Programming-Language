/*
1. It is possible-in fact, quite common-to pass a constructor more than one argument. Here
myclass() is passed two arguments:
*/
#include <iostream>
using namespace std;
class myclass
{
    int a, b;

public:
    myclass(int x, int y)
    {
        cout << "In constructor \n";
        a = x;
        b = y;
    }; // constructor
    void show()
    {
        cout << a << " " << b << "\n";
    };
};
int main()
{
    myclass ob(4, 7);

    ob.show();

    return 0;
}