/*
3. You must exercise some care when assigning one object to another. For example, here is
the strtype class developed in Chapter 2, along with a short main(). See if you can fnd
an error in this program.
*/
#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
class strtype
{
    char *p;
    int len;

public:
    strtype(char *ptr);
    ~strtype();
    void show();
};
strtype ::strtype(char *ptr)
{
    len = strlen(ptr);
    p = (char *)malloc(len + 1);
    if (!p)
    {
        cout << " Allocation error \n";
        exit(1);
    }
    strcpy(p, ptr);
}
strtype ::~strtype()
{
    cout << " Freeing p\n";
    free(p);
}
void strtype ::show()
{
    cout << p << " - length : " << len;
    cout << "\n";
}
int main()
{
    strtype s1(" This is a test ."), s2("I like C++. ");

    s1.show();
    s2.show();
    // assign s1 to s2 - - this generates an error
    s2 = s1;
    s1.show();
    s2.show();
    return 0;
}