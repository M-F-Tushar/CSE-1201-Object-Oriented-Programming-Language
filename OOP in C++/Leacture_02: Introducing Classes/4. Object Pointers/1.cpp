#include<iostream>
using namespace std;

class myclass
{
    int a;
public:
    myclass(int x)
    {
        a = x;
    };

    int get()
    {
        return a;
    };

};

int main()
{
    myclass ob(120);
    myclass *p; // Create a pointer that will point at the object

    p = &ob; // Putting the adress of the object

    cout << "Value using object:" << ob.get();
    cout << "\n";

    cout << "Value usign pointer:" << p->get();

    return 0;
}
