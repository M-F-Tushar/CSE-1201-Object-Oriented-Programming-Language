#include<iostream>
using namespace std;

class date
{
    int day, month, year;
public:
    date(char *str)
    {
        sscanf(str, "%d%*c%d%*c%d", &month, &day, &year);
    }
    date(int d, int m, int y)
    {
        day = d;
        month = m;
        year = y;
    }

    void show()
    {
        cout << "Date: " << day << "/" << month << "/" << year << endl;
    }

};

int main()
{
    date s1("12/05/2020");
    date s2(15, 8, 2021);

    s1.show();
    s2.show();

    return 0;

}
