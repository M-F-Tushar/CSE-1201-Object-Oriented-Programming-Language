#include<iostream>
using namespace std;

class student
{
    private:
        int roll;
        char name[];
    public:
        void inputData()
        {
            cout << "Enter roll number: ";
            cin >> roll;
            cout << "Enter name: ";
            cin >> name;
        }
        void outputData()
        {
            cout << "The roll number is: " << roll << endl;
            cout << "The name is: " << name << endl;
        }
};

int main()
{
    student s;

    s.inputData();
    s.outputData();

    return 0;
}