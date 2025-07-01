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
    ~Test() // Destructor
    {
        cout << "Destructor called!" << endl;
    }
};

void objCreate()
    {
        Test T1,T2;
    }

 int main()
 {
    objCreate();
    cout << "Back in main...." << endl;
    Test T3;
    return 0;
 }
