/*
Member functions are the funtions that operate on the data encapsulated in the class
Public member funcitons are the interface to the class
*/

#include<iostream>
using namespace std;

class student
{
    private:
        int roll = 10;
    public:
        void dispaly();
};

void student :: dispaly()
{
    cout << "The roll number is : " << roll << endl;
}

int main()
{
    student s;

    s.dispaly();

    return 0;
}

