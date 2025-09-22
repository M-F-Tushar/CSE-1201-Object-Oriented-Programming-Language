//Q2 (c)
//Student with Parameterized Constructor
#include <iostream>
#include <string>
using namespace std;

class Student {
private:
    string name;
    int age;
    float cgpa;
public:
    Student(string n, int a, float c) {  // parameterized constructor
        name = n;
        age = a;
        cgpa = c;
    }
    void display() {
        cout << "Name: " << name << ", Age: " << age << ", CGPA: " << cgpa << endl;
    }
};

int main() {
    Student s1("John", 20, 3.8);
    s1.display();
}