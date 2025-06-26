// 1. Here is an example of a function that returns an object:
#include <iostream>
#include <string>
using namespace std;

class samp
{
    char s[80];
public:
    void show()
    {
        cout << s << endl;
    }
    void set(char *str)
    {
        strcpy(s, str);
    }
};

samp input()
{
    char s[80];
    samp str;

    cout << "Enter a string:";
    cin >> s;

    str.set(s);// Copies the contents of the local buffer into the object's internal string.

    return str;
}

int main()
{
    samp ob;

    ob = input();
    ob.show();

    return 0;
}  