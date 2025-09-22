
//Q1 (b)
#include <iostream>
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int id;
    float salary;
public:
    void setDetails(string n, int i, float s) {
        name = n;
        id = i;
        salary = s;
    }
    void display() {
        cout << "Name: " << name << ", ID: " << id << ", Salary: " << salary << endl;
    }
};