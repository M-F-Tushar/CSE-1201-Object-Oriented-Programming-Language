#include<iostream>
using namespace std;

class Test
{
    int n;
public:
    Test()
    {
        cout << "Constructor called!" << endl;
    }
    Test(int x)
    {
        n = x;
        cout << "Parameterized constructor called with value: " << n << endl;
    }
    void display()
    {
        cout << "Value of n: " << n << endl;
    }
};
 int main()
 {
    Test T(10);
    
    T.display();

    return 0;
 }