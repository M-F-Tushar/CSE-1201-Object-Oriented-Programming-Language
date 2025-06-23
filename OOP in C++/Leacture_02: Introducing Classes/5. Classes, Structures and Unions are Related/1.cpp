// 1. Here is a short program that uses struct to create a class:
#include <iostream>
#include <cstring>

using namespace std;

struct st_type
{
private:
    double balance;
    char name[40];

public:
    st_type(double b, const char *n)
    {
        balance = b;
        strcpy(name, n);
    };
    void show()
    {
        cout << " Name : " << name;
        cout << ": $" << balance;
        if (balance < 0.0)
            cout << "**";
        cout << "\n";
    };
};

int main()
{
    st_type acc1(100.12, " Johnson ");
    st_type acc2(-12.34, " Hedricks ");
    acc1.show();
    acc2.show();
    return 0;
}