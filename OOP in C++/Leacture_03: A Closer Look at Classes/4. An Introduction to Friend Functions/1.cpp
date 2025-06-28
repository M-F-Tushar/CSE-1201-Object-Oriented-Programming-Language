#include<iostream>
using namespace std;

class myclass 
{
    int n, d;

public:
    myclass(int i, int j)
    {
        n = i;
        d = j;
    }
    friend int isfactor(myclass ob);
};

int isfactor(myclass ob)
{
    if (!(ob.n % ob.d))
        return 1; // d is a factor of n
    else
        return 0; // d is not a factor of n
}

int main()
{
    myclass ob1(10, 2);
    myclass ob2(13, 3);

    if (isfactor(ob1))
        cout << " 2 is a factor of 10"<< endl;
    else
        cout << " 2 is not a factor of 10" << endl;
    if (isfactor(ob2))
        cout << " 3 is a factor of 13" << endl;
    else
        cout << " 3 is not a factor of 13" << endl;
    return 0;
}