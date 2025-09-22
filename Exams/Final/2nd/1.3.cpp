//Q1 (c)
//Array of Employee Objects
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
int main() {
    Employee emp[3];   // array of 3 employees

    emp[0].setDetails("Alice", 101, 50000);
    emp[1].setDetails("Bob", 102, 60000);
    emp[2].setDetails("Charlie", 103, 55000);

    for(int i=0; i<3; i++) {
        emp[i].display();
    }
}