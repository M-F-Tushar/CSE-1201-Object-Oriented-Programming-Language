Constructors and Destructors in C++

In C++, constructors and destructors are special member functions of a class that help manage the lifecycle of objects. They automatically handle initialization and cleanup without the programmer having to call them explicitly.

1. Constructor

Purpose:
A constructor is used to initialize an object when it is created. It sets up the initial state of the object, allocates resources if necessary, and can take arguments to customize the initialization.

Key Points:

Name of the constructor matches the class name.

No return type (not even void).

Automatically called when an object is created.

Can be overloaded (multiple constructors with different parameters).

Example Use Case:
Imagine you have a BankAccount class. When a new account is created, you might want to initialize the balance and account holder’s name.

#include <iostream>
using namespace std;

class BankAccount {
    string name;
    double balance;
public:
    // Constructor
    BankAccount(string n, double b) {
        name = n;
        balance = b;
        cout << "Account for " << name << " created with balance $" << balance << endl;
    }
};

int main() {
    BankAccount acc1("Alice", 1000.0);  // Constructor is called here
    return 0;
}


Output:

Account for Alice created with balance $1000

2. Destructor

Purpose:
A destructor is used to clean up when an object is destroyed. This includes:

Releasing dynamically allocated memory (new / delete)

Closing files

Releasing other system resources

Key Points:

Name of destructor is class name prefixed with ~ (tilde symbol).

No return type, takes no parameters.

Automatically called when an object goes out of scope or is explicitly deleted.

Only one destructor per class (cannot be overloaded).

Example Use Case:
If a class allocates dynamic memory for some reason, failing to release it will cause memory leaks. A destructor ensures cleanup.

#include <iostream>
using namespace std;

class Demo {
    int* data;
public:
    // Constructor
    Demo(int size) {
        data = new int[size]; // allocate memory
        cout << "Memory allocated for " << size << " integers." << endl;
    }

    // Destructor
    ~Demo() {
        delete[] data;  // free memory
        cout << "Memory freed." << endl;
    }
};

int main() {
    Demo obj(5);  // Constructor called
    // do some operations
}  // Destructor called automatically here


Output:

Memory allocated for 5 integers.
Memory freed.

3. Differences Between Constructor and Destructor
Feature	Constructor	Destructor
Purpose	Initialize object	Clean up object
Name	Same as class name	Same as class name with ~
Return Type	None	None
Parameters	Can have parameters (overloaded)	Cannot have parameters
Called	When object is created	When object goes out of scope or is deleted
Number per class	Can have multiple (overloaded)	Only one
4. Example Scenario Where Destructor is Essential

Suppose a class opens a file for writing. You must close the file when the object is destroyed. If you forget, you might lose data or lock the file.

#include <iostream>
#include <fstream>
using namespace std;

class FileWriter {
    ofstream file;
public:
    FileWriter(string filename) {
        file.open(filename);
        cout << "File opened for writing.\n";
    }

    void writeData(string data) {
        file << data << endl;
    }

    ~FileWriter() {
        file.close();  // ensures the file is closed when object goes out of scope
        cout << "File closed.\n";
    }
};

int main() {
    {
        FileWriter fw("output.txt");
        fw.writeData("Hello, World!");
    }  // Destructor called here, file is safely closed
}

✅ Summary

Constructor: Sets up the object → called when object is created.

Destructor: Cleans up resources → called when object is destroyed.

Destructors are essential whenever a class manages dynamic memory, files, or other resources, ensuring no leaks or dangling handles.
