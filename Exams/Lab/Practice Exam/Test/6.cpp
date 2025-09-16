/*
Q6. Create a class Time with hours and minutes as data members. Overload constructors to initialize (i) with 0 hours and 0 minutes, and 
(ii) with given hours and minutes. Overload the + operator to add two Time objects. Display the result in HH:MM format in main(). [10]
*/
/* 
Q6. Create a class Time with hours and minutes as data members. Overload constructors to initialize 
(i) with 0 hours and 0 minutes, and (ii) with given hours and minutes. Overload the + operator 
to add two Time objects. Display the result in HH:MM format in main(). [10]
*/

#include <iostream>
using namespace std;

class Time 
{
    int hours, minutes;
public:
    Time() 
    { 
        hours = 0; 
        minutes = 0; 
    }

    Time(int h, int m) 
    { 
        hours = h + m / 60;   // handle extra minutes
        minutes = m % 60; 
    }

    Time operator+(Time t2) 
    {
        Time temp;
        temp.minutes = minutes + t2.minutes;
        temp.hours = hours + t2.hours + (temp.minutes / 60);
        temp.minutes = temp.minutes % 60;
        return temp;
    }

    void display() 
    {
        if (hours < 10) cout << "0";
        cout << hours << ":";
        if (minutes < 10) cout << "0";
        cout << minutes << endl;
    }
};

int main() 
{
    Time t1(2, 45), t2(1, 30), t3;
    t3 = t1 + t2;
    cout << "Sum of times: ";
    t3.display();
    return 0;
}

