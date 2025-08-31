#include<iostream>
using namespace std;

class myclass
{
    int x;
public:
    myclass()
    {
        x = 0;
    }
    myclass(int n)
    {
        x = n;
    }
    int get_x()
    {
        return x;
    }
};

int main()
{
    myclass ob1[10];
    myclass ob2[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    for(int i=0; i<10; i++)
    {
        cout << "ob1["<< i << "]: " << ob1[i].get_x() << endl;
        cout << "ob2["<< i << "]: " << ob2[i].get_x() << endl;
    }
}
