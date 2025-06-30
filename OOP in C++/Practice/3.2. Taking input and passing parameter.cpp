/*
Member functions are the funtions that operate on the data encapsulated in the class
Public member funcitons are the interface to the class
*/

#include<iostream>
using namespace std;

class student
{

    public:
        void display(int roll, char name[]);
        
};

void student :: display(int roll, char name[])
{
    cout << "The roll number is : " << roll << endl;
    cout << "The name is : " << name << endl;
}

int main()
{
    student s;

    int roll;
    char name[50];

    cout <<  "Enter roll number: ";
    cin >> roll;

    cout << "Enter name: ";
    cin >> name;

    s.display(roll, name);

    return 0;
}

