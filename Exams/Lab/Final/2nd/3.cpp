#include<iostream>
#include<string>
using namespace std;

class Person
{
protected:
        string name;
public:
    Person(string n) : name(n) {}
    virtual ~Person() {}
    virtual void showDetails() = 0;
};

class Student : public Person
{
protected:
    int grade;
public:
    Student(string n, int g) : Person(n), grade(g){}
    ~Student() {}
    void setgrade(int g)
    {
        grade = g;
    }
    int getgrade()
    {
        return grade;
    }
    void showDetails() override
    {
        cout << "Name: " << name << ", Grade: " << grade << endl;
    }
};

class Teacher : public Person
{
private:
    double salary;
public:
    Teacher(string n, double s) : Person(n), salary(s) {}
    ~Teacher() {}
    void setSalary(double s)
    {
        salary = s;
    }
    double getSalary()
    {
        return salary;
    }
    void showDetails() override
    {
        cout << "Name: " << name << ", Salary: " << salary << endl;
    }
};

class HighSchoolStudent : public Student
{
protected:
    string level;
public:
    HighSchoolStudent(string n, int g, string l) : Student(n, g), level(l) {}
    ~HighSchoolStudent() {}

    void showDetails() override
    {
        cout << "Name: " << name << ", Grade: " << getgrade() << ", Level: " << level << endl;
    }
};

class MathTeacher : public Teacher
{
protected:  
    string subject;
public:
    MathTeacher(string n, double s, string sub) : Teacher(n, s), subject(sub) {}
    ~MathTeacher() {}
    void showDetails() override
    {
        cout << "Name: " << name << ", Salary: " << getSalary() << ", Subject: " << subject << endl;
    }
};

class ScienceTeacher : public Teacher
{
protected:
    string subject;
public:
    ScienceTeacher(string n, double s, string sub) : Teacher(n, s), subject(sub) {}
    ~ScienceTeacher() {}
    void showDetails() override
    {
        cout << "Name: " << name << ", Salary: " << getSalary() << ", Subject: " << subject << endl;
    }
};

int main()
{
    Person *p1 = new Student("Alice", 10);
    Person *p2 = new Teacher("Bob", 50000);
    Person *p3 = new HighSchoolStudent("Charlie", 12, "Senior");
    Person *p4 = new MathTeacher("David", 60000, "Algebra");
    Person *p5 = new ScienceTeacher("Eve", 65000, "Physics");

    p1->showDetails();
    p2->showDetails();
    p3->showDetails();
    p4->showDetails();
    p5->showDetails();

    delete p1;
    delete p2;
    delete p3;
    delete p4;
    delete p5;

    return 0;
}