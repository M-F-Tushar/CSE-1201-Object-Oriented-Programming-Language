#include<iostream>
using namespace std;

class Counter 
{
private:
    int count;
public:
    Counter(int c = 0)
    {
        count = c;
    }

    Counter operator+(const Counter &obj)
    {
        return Counter(count + obj.count);
    }

    Counter operator++()
    {
        ++count;
        return *this;
    }

    int getvalue() const
    {
        return count;
    }


};

int main()
{
    Counter c1(5);
    Counter c2(10);
    Counter c3 = c1 + c2;
    ++c1;
    cout << "c1: " << c1.getvalue() << endl;
    cout << "c2: " << c2.getvalue() << endl;
    cout << "c3: " << c3.getvalue() << endl;

    return 0;
}