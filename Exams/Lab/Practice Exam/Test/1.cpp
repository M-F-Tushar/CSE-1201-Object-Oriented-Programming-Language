/*
Q1. Create a class Calculator with three overloaded add() functions to perform (i) addition of two integers, (ii) addition of two floats, and 
(iii) concatenation of two strings. Call all versions of add() in main(). [10]

*/
#include <iostream>
#include <string>
using namespace std;

class Calculator 
{
public:
    int add(int a, int b) 
    {
        return a + b;
    }
    double add(double a, double b) 
    {
        return a + b;
    }

    string add(string a, string b) 
    {
        return a + b;
    }
};

int main() 
{
    Calculator ob;

    cout << "Integer addition: 10 + 20 = " << ob.add(10, 20) << endl;

    cout << "Float addition: 3.5 + 2.5 = " << ob.add(3.5, 2.5) << endl;

    cout << "String concatenation: " << ob.add("Hello, ", "World!") << endl;

    return 0;
}
