/*
Q1 (a)
Define Class:

A class is a blueprint/template used to create objects.

It defines attributes (data members) and methods (functions).

Difference between Class and Object:

Class → Blueprint (definition, no memory until object is created).

Object → Real entity created from the class (has memory).

Example:

class Car {
public:
    string brand;
    void show() {
        cout << "Car brand: " << brand << endl;
    }
};

int main() {
    Car c1;          // object
    c1.brand = "BMW";
    c1.show();
}


Here:

Car → class.

c1 → object created from the class.

*/