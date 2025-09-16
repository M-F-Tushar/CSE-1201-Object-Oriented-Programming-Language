/*
Q3. Create a class Distance with feet and inches. Overload constructors to allow 
initialization with no value and with two parameters. Overload the == operator 
to check if two distances are equal. Show results in main(). [10]

*/
#include <iostream>
using namespace std;

class Distance 
{
    int feet, inches;
public:
    Distance() 
    { 
        feet = 0; inches = 0;
    }
    Distance(int f, int i) 
    { 
        feet = f; inches = i;
    }

    int operator==(Distance d) 
    {
        return (feet == d.feet && inches == d.inches);
    }

    void display() 
    {
        cout << feet << " feet, " << inches << " inches" << endl;
    }
};

int main() 
{
    Distance d1(5, 8), d2(5, 8), d3(4, 11);
    if (d1 == d2)
        cout << "d1 and d2 are equal\n";
    else
        cout << "d1 and d2 are not equal\n";

    if (d1 == d3)
        cout << "d1 and d3 are equal\n";
    else
        cout << "d1 and d3 are not equal\n";

    return 0;
}
