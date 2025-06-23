/*
1. Here is a program that defnes a generic base class called fruit that describes certain
characteristics of fruit. This class is inherited by two derived classes Apple and Orange.
These classes supply specifc information to fruit that are related to these type of fruit.
*/
#include <iostream>
#include <cstring>

using namespace std;
enum yn
{
    no,
    yes
};
enum color
{
    red,
    yellow,
    green,
    orange
};
void out(enum yn x);
char *c[] = {"red ", " yellow ", " green ", " orange "};
// Generic fruit class .
class fruit
{
    // in this base , all elements are public
public:
    enum yn annual;
    enum yn perennial;
    enum yn tree;
    enum yn tropical;
    enum color clr;
    char name[40];
};
// Derive Apple class .
class Apple : public fruit
{
    enum yn cooking;
    enum yn crunchy;
    enum yn eating;

public:
    void seta(char *n, enum color c, enum yn ck, enum yn crchy, enum yn e);
    void show();
};

// Derive orange class .
class Orange : public fruit
{
    enum yn juice;
    enum yn sour;
    enum yn eating;

public:
    void seto(char *n, enum color c, enum yn j, enum yn sr, enum yn e);
    void show();
};
void Apple ::seta(char *n, enum color c, enum yn ck, enum yn crchy, enum yn e)
{
    strcpy(name, n);
    annual = no;
    perennial = yes;
    tree = yes;
    tropical = no;
    clr = c;
    cooking = ck;
    crunchy = crchy;
    eating = e;
}
void Orange ::seto(char *n, enum color c, enum yn j, enum yn sr, enum yn e)
{
    strcpy(name, n);
    annual = no;
    perennial = yes;
    tree = yes;
    tropical = yes;
    clr = c;
    juice = j;
    sour = sr;
    eating = e;
}
void Apple ::show()
{
    cout << name << " apple is: " << "\n";
    cout << " Annual : ";
    out(annual);
    cout << " Perennial : ";
    out(perennial);
    cout << " Tree : ";
    out(tree);
    cout << " Tropical : ";
    out(tropical);
    cout << " Color : " << c[clr] << "\n";
    cout << " Good for cooking : ";
    out(cooking);
    cout << " Crunchy : ";
    out(crunchy);
    cout << " Good for eating : ";
    out(eating);
    cout << "\n";
}
void Orange ::show()
{
    cout << name << " orange is: " << "\n";
    cout << " Annual : ";
    out(annual);
    cout << " Perennial : ";
    out(perennial);
    cout << " Tree : ";
    out(tree);

    cout << " Tropical : ";
    out(tropical);
    cout << " Color : " << c[clr] << "\n";
    cout << " Good for juice : ";
    out(juice);
    cout << " Sour : ";
    out(juice);
    cout << " Good for eating : ";
    out(eating);
    cout << " Good for eating : ";
    out(eating);
    cout << "\n";
}

// Output function for enum yn
void out(enum yn x)
{
    if (x == no)
        cout << "no\n";
    else
        cout << "yes\n";
}

int main()
{
    Apple a1, a2;
    Orange o1, o2;
    a1.seta("Red Delicious", red, no, yes, yes);
    a2.seta("Jonathan", red, yes, no, yes);
    o1.seto("Navel", orange, no, no, yes);
    o2.seto("Valencia", orange, yes, yes, no);
    a1.show();
    a2.show();
    o1.show();
    o2.show();
    return 0;
}