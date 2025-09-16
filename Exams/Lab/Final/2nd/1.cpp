#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
        string name;
        int ID;
public:
        Person(string n, int id) : name(n), ID(id) {}

    virtual ~Person() {}

    virtual void showDetails() = 0;
    
};
class Student : public Person
{
    int year;
public:
    Student(string n, int id, int y) : Person(n, id) , year(y){}

    ~Student() {}

    void showDetails() override
    {
        cout << "Name: " << name << ", ID: " << ID << ", Year: " << year << endl;
    }
};
class Staff : public Person
{
protected:
    string dept;
public:
    Staff(string n, int id, string d) : Person(n, id), dept(d)
    {

    }
    ~Staff() {}

    void showDetails() override
    {
        cout << "Name: " << name << ", ID: " << ID << ", Department: " << dept << endl;
    }

};
class Professor : public Staff
{
protected:
    string subject;
public:
    Professor(string n, int id, string d, string s) : Staff(n, id, d), subject(s) {}
    ~Professor() {}

    void showDetails() override
    {
        cout << "Name: " << name << ", ID: " << ID << ", Department: " << dept << ", Subject: " << subject << endl;
    }
};
class Admin : public Staff
{
protected:
    string role;
public:
    Admin(string n, int id, string d, string r) : Staff(n, id, d), role(r) {}
    ~Admin() {}

    void showDetails() override
    {
        cout << "Name: " << name << ", ID: " << ID << ", Department: " << dept << ", Role: " << role << endl;
    }
};
int main()
{
    Person *p1 = new Student("Alice", 101, 2);
    Person *p2 = new Professor("Dr. Smith", 201, "Computer Science", "Data Structures");
    Person *p3 = new Admin("Mr. Brown", 301, "Administration", "Registrar");
    p1->showDetails();
    p2->showDetails();
    p3->showDetails();
    delete p1;
    delete p2;
    delete p3;
    return 0;
}