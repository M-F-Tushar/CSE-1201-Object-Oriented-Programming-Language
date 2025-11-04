# Complete OOP Concepts Reference Guide

---

## Fundamental Structure and Lifetime

### 1. Object

**Definition:** An instance of a class that encapsulates data and behavior.

**Explanation:** An object is a concrete realization of a class with its own state (data members) and access to class behaviors (methods). Each object occupies memory and has a unique identity.

**C++ Code Example:**
```cpp
class Student {
public:
    string name;
    int age;
};

int main() {
    Student s1; // s1 is an object
    s1.name = "Alice";
    s1.age = 20;
    return 0;
}
```

**Java Code Example:**
```java
class Student {
    String name;
    int age;
}

public class Main {
    public static void main(String[] args) {
        Student s1 = new Student();
        s1.name = "Alice";
        s1.age = 20;
    }
}
```

**C++ vs Java Difference:** In C++, objects can be created on the stack (automatic storage) or heap (dynamic storage). In Java, all objects are created on the heap using `new`, and variables hold references to objects, not the objects themselves.

---

### 2. Class

**Definition:** A blueprint or template that defines the structure and behavior of objects.

**Explanation:** A class defines data members (attributes) and member functions (methods) that objects of that class will have. It serves as a user-defined data type that encapsulates data and functions operating on that data.

**C++ Code Example:**
```cpp
class Rectangle {
private:
    int width, height;
public:
    void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
    int getArea() {
        return width * height;
    }
};
```

**Java Code Example:**
```java
class Rectangle {
    private int width, height;
    
    public void setDimensions(int w, int h) {
        width = w;
        height = h;
    }
    
    public int getArea() {
        return width * height;
    }
}
```

**C++ vs Java Difference:** C++ classes use semicolon at the end of class definition. Java classes don't require semicolons. C++ has default private access for class members, while Java has package-private (default) access.

---

### 3. Member Function

**Definition:** A function defined inside a class that operates on class data members.

**Explanation:** Member functions (also called methods) define the behavior of a class. They can access and modify the object's data members and can be called using an object of the class.

**C++ Code Example:**
```cpp
class Circle {
private:
    double radius;
public:
    void setRadius(double r) { // Member function
        radius = r;
    }
    double getArea() { // Member function
        return 3.14 * radius * radius;
    }
};
```

**Java Code Example:**
```java
class Circle {
    private double radius;
    
    public void setRadius(double r) { // Member method
        radius = r;
    }
    
    public double getArea() { // Member method
        return 3.14 * radius * radius;
    }
}
```

**C++ vs Java Difference:** C++ member functions can be defined inside or outside the class using scope resolution operator (::). Java methods are always defined within the class body. C++ supports const member functions; Java doesn't have this feature.

---

### 4. Constructor

**Definition:** A special member function that is automatically called when an object is created.

**Explanation:** Constructors initialize objects. They have the same name as the class and no return type. Constructors can be overloaded to provide different ways to initialize objects.

**C++ Code Example:**
```cpp
class Book {
private:
    string title;
    int pages;
public:
    Book() { // Constructor
        title = "Unknown";
        pages = 0;
    }
    Book(string t, int p) { // Parameterized constructor
        title = t;
        pages = p;
    }
};
```

**Java Code Example:**
```java
class Book {
    private String title;
    private int pages;
    
    public Book() { // Constructor
        title = "Unknown";
        pages = 0;
    }
    
    public Book(String t, int p) { // Parameterized constructor
        title = t;
        pages = p;
    }
}
```

**C++ vs Java Difference:** C++ objects can be created without `new`, automatically calling constructor. Java requires explicit `new` keyword. C++ supports member initializer lists for efficiency; Java uses assignment in constructor body.

---

### 5. Destructor

**Definition:** A special member function that is automatically called when an object is destroyed.

**Explanation:** Destructors clean up resources (like memory, file handles) before an object is destroyed. In C++, the destructor name is the class name preceded by a tilde (~). Java uses finalizers (deprecated) or try-with-resources instead.

**C++ Code Example:**
```cpp
class FileHandler {
private:
    string filename;
public:
    FileHandler(string name) {
        filename = name;
        cout << "File opened: " << filename << endl;
    }
    ~FileHandler() { // Destructor
        cout << "File closed: " << filename << endl;
    }
};
```

**Java Code Example:**
```java
class FileHandler {
    private String filename;
    
    public FileHandler(String name) {
        filename = name;
        System.out.println("File opened: " + filename);
    }
    
    // Java doesn't have destructors
    // Use try-with-resources or close() method
    public void close() {
        System.out.println("File closed: " + filename);
    }
}
```

**C++ vs Java Difference:** C++ has explicit destructors called automatically when objects go out of scope. Java relies on garbage collection and doesn't have destructors. Java's `finalize()` method (deprecated) is unpredictable, so explicit cleanup methods are preferred.

---

### 6. Copy Constructor

**Definition:** A constructor that creates a new object as a copy of an existing object.

**Explanation:** A copy constructor takes a reference to an object of the same class and creates a new object with the same values. It's called during object initialization with another object, pass-by-value, and return-by-value.

**C++ Code Example:**
```cpp
class Point {
private:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    
    // Copy constructor
    Point(const Point& p) {
        x = p.x;
        y = p.y;
        cout << "Copy constructor called" << endl;
    }
};
```

**Java Code Example:**
```java
class Point {
    private int x, y;
    
    public Point(int a, int b) {
        x = a;
        y = b;
    }
    
    // Copy constructor (manual implementation)
    public Point(Point p) {
        x = p.x;
        y = p.y;
        System.out.println("Copy constructor called");
    }
}
```

**C++ vs Java Difference:** C++ automatically provides a default copy constructor and calls it implicitly. Java doesn't have automatic copy constructors; you must implement them manually. Java passes objects by reference, so copying happens less frequently.

---

### 7. Converting Constructor

**Definition:** A constructor that accepts a single argument of a different type, allowing implicit type conversion.

**Explanation:** Converting constructors enable automatic conversion from one type to another. This can lead to implicit conversions that may or may not be desired, which is why the `explicit` keyword exists.

**C++ Code Example:**
```cpp
class Distance {
private:
    int meters;
public:
    // Converting constructor
    Distance(int m) {
        meters = m;
    }
    void display() {
        cout << "Distance: " << meters << "m" << endl;
    }
};

int main() {
    Distance d = 100; // Implicit conversion from int
    d.display();
    return 0;
}
```

**Java Code Example:**
```java
class Distance {
    private int meters;
    
    // Converting constructor
    public Distance(int m) {
        meters = m;
    }
    
    public void display() {
        System.out.println("Distance: " + meters + "m");
    }
    
    public static void main(String[] args) {
        Distance d = new Distance(100); // Must be explicit in Java
        d.display();
    }
}
```

**C++ vs Java Difference:** C++ allows implicit conversion via converting constructors (can be prevented with `explicit`). Java doesn't support implicit object conversion; all constructor calls must be explicit with the `new` keyword.

---

### 8. explicit Keyword

**Definition:** A C++ keyword that prevents implicit type conversions through constructors.

**Explanation:** The `explicit` keyword prevents the compiler from using a constructor for implicit conversions. This helps avoid unintended conversions and makes code more readable and safer.

**C++ Code Example:**
```cpp
class Score {
private:
    int value;
public:
    explicit Score(int v) { // Prevents implicit conversion
        value = v;
    }
};

int main() {
    Score s1(95); // OK
    // Score s2 = 95; // Error: implicit conversion not allowed
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't have the explicit keyword
// All conversions are explicit by default

class Score {
    private int value;
    
    public Score(int v) {
        value = v;
    }
    
    public static void main(String[] args) {
        Score s1 = new Score(95); // Must be explicit
        // Score s2 = 95; // Not allowed in Java
    }
}
```

**C++ vs Java Difference:** C++ has the `explicit` keyword to prevent implicit conversions. Java doesn't need this keyword because it doesn't support implicit constructor conversions; all object creation must use the `new` keyword explicitly.

---

### 9. this Pointer

**Definition:** A pointer/reference to the current object instance within member functions.

**Explanation:** The `this` pointer (C++) or reference (Java) allows member functions to refer to the object that invoked them. It's useful for distinguishing between member variables and parameters with the same name, and for returning the current object.

**C++ Code Example:**
```cpp
class Account {
private:
    double balance;
public:
    Account(double balance) {
        this->balance = balance; // Disambiguate parameter
    }
    Account* deposit(double amount) {
        this->balance += amount;
        return this; // Return current object
    }
};
```

**Java Code Example:**
```java
class Account {
    private double balance;
    
    public Account(double balance) {
        this.balance = balance; // Disambiguate parameter
    }
    
    public Account deposit(double amount) {
        this.balance += amount;
        return this; // Return current object
    }
}
```

**C++ vs Java Difference:** In C++, `this` is a pointer (use `->` to access members). In Java, `this` is a reference (use `.` to access members). C++ `this` is a pointer constant; Java `this` is a final reference.

---

### 10. Scope Resolution Operator (::)

**Definition:** A C++ operator used to define members outside the class and access static members or resolve scope ambiguities.

**Explanation:** The scope resolution operator (::) allows defining member functions outside the class definition, accessing static members, and accessing global variables when local variables have the same name.

**C++ Code Example:**
```cpp
class Calculator {
public:
    int add(int a, int b);
    static int multiply(int a, int b);
};

// Define member function outside class
int Calculator::add(int a, int b) {
    return a + b;
}

int Calculator::multiply(int a, int b) {
    return a * b;
}
```

**Java Code Example:**
```java
// Java doesn't have scope resolution operator
// Methods must be defined inside the class

class Calculator {
    public int add(int a, int b) {
        return a + b;
    }
    
    public static int multiply(int a, int b) {
        return a * b;
    }
}
```

**C++ vs Java Difference:** C++ has the `::` operator for defining members outside the class and accessing nested scopes. Java requires all methods to be defined within the class body and uses dot notation for static member access.

---

### 11. Parameterized Constructor

**Definition:** A constructor that accepts arguments to initialize an object with specific values.

**Explanation:** Parameterized constructors allow objects to be created with initial values provided by the caller. This provides flexibility in object initialization and eliminates the need for separate setter methods.

**C++ Code Example:**
```cpp
class Employee {
private:
    string name;
    int id;
    double salary;
public:
    // Parameterized constructor
    Employee(string n, int i, double s) {
        name = n;
        id = i;
        salary = s;
    }
};

int main() {
    Employee emp("John", 101, 50000.0);
    return 0;
}
```

**Java Code Example:**
```java
class Employee {
    private String name;
    private int id;
    private double salary;
    
    // Parameterized constructor
    public Employee(String n, int i, double s) {
        name = n;
        id = i;
        salary = s;
    }
    
    public static void main(String[] args) {
        Employee emp = new Employee("John", 101, 50000.0);
    }
}
```

**C++ vs Java Difference:** Both languages support parameterized constructors similarly. C++ can use member initializer lists for efficiency. Java uses assignment in constructor body. C++ objects can be created on stack; Java requires heap allocation with `new`.

---

### 12. Default Constructor

**Definition:** A constructor that takes no arguments and provides default initialization.

**Explanation:** A default constructor is called when an object is created without arguments. If no constructor is defined, the compiler provides one automatically (but not if other constructors exist).

**C++ Code Example:**
```cpp
class Product {
private:
    string name;
    double price;
public:
    // Default constructor
    Product() {
        name = "Unknown";
        price = 0.0;
    }
};

int main() {
    Product p; // Calls default constructor
    return 0;
}
```

**Java Code Example:**
```java
class Product {
    private String name;
    private double price;
    
    // Default constructor
    public Product() {
        name = "Unknown";
        price = 0.0;
    }
    
    public static void main(String[] args) {
        Product p = new Product(); // Calls default constructor
    }
}
```

**C++ vs Java Difference:** Both languages auto-generate default constructors if none are defined. C++ default constructor leaves primitive types uninitialized for local objects; Java initializes all fields to default values (0, null, false). C++ syntax doesn't require `new`.

---

### 13. Constructor Chaining

**Definition:** The process of calling one constructor from another constructor within the same class or from a parent class.

**Explanation:** Constructor chaining reduces code duplication by allowing constructors to call other constructors. In Java, use `this()` for same-class constructors and `super()` for parent-class constructors. C++ uses member initializer lists.

**C++ Code Example:**
```cpp
class Vehicle {
private:
    string brand;
    int year;
public:
    Vehicle() : Vehicle("Unknown", 2000) { // Delegating constructor
    }
    
    Vehicle(string b, int y) : brand(b), year(y) {
        cout << "Vehicle created" << endl;
    }
};
```

**Java Code Example:**
```java
class Vehicle {
    private String brand;
    private int year;
    
    public Vehicle() {
        this("Unknown", 2000); // Constructor chaining
    }
    
    public Vehicle(String b, int y) {
        brand = b;
        year = y;
        System.out.println("Vehicle created");
    }
}
```

**C++ vs Java Difference:** C++11 introduced delegating constructors using initializer lists. Java uses `this()` which must be the first statement. Java's syntax is more explicit; C++'s uses initialization list syntax. Both achieve code reuse effectively.

---

### 14. Constructor/Destructor Order (Inheritance)

**Definition:** The sequence in which constructors and destructors are called in an inheritance hierarchy.

**Explanation:** Constructors are called from base to derived class (top-down), while destructors are called in reverse order (derived to base). This ensures proper initialization and cleanup of resources in the inheritance chain.

**C++ Code Example:**
```cpp
class Base {
public:
    Base() { cout << "Base constructor" << endl; }
    ~Base() { cout << "Base destructor" << endl; }
};

class Derived : public Base {
public:
    Derived() { cout << "Derived constructor" << endl; }
    ~Derived() { cout << "Derived destructor" << endl; }
};
```

**Java Code Example:**
```java
class Base {
    public Base() {
        System.out.println("Base constructor");
    }
    // No explicit destructor in Java
}

class Derived extends Base {
    public Derived() {
        System.out.println("Derived constructor");
    }
}
```

**C++ vs Java Difference:** C++ has explicit destructors called in reverse order of construction. Java relies on garbage collection without explicit destructors. C++ destructor order is deterministic and immediate; Java cleanup is non-deterministic.

---

### 15. Object Lifecycle

**Definition:** The stages an object goes through from creation to destruction.

**Explanation:** An object's lifecycle includes: creation (memory allocation and constructor call), usage (method calls and state changes), and destruction (cleanup and memory deallocation). Understanding lifecycle is crucial for resource management.

**C++ Code Example:**
```cpp
class Resource {
public:
    Resource() { 
        cout << "Created" << endl; 
    }
    void use() { 
        cout << "Using" << endl; 
    }
    ~Resource() { 
        cout << "Destroyed" << endl; 
    }
};

int main() {
    Resource r; // Created
    r.use();    // Using
    return 0;   // Destroyed automatically
}
```

**Java Code Example:**
```java
class Resource {
    public Resource() {
        System.out.println("Created");
    }
    
    public void use() {
        System.out.println("Using");
    }
    
    protected void finalize() { // Deprecated
        System.out.println("Being garbage collected");
    }
}
```

**C++ vs Java Difference:** C++ objects have deterministic lifecycles with explicit destruction when leaving scope. Java objects persist until garbage collected, making lifecycle timing unpredictable. C++ requires manual memory management for heap objects; Java handles this automatically.

---

### 16. Instantiation

**Definition:** The process of creating an object from a class.

**Explanation:** Instantiation allocates memory for an object and calls its constructor to initialize it. The new object becomes an instance of its class with its own state.

**C++ Code Example:**
```cpp
class Car {
public:
    string model;
    Car(string m) : model(m) {}
};

int main() {
    Car c1("Tesla");      // Stack instantiation
    Car* c2 = new Car("BMW"); // Heap instantiation
    delete c2;
    return 0;
}
```

**Java Code Example:**
```java
class Car {
    String model;
    
    public Car(String m) {
        model = m;
    }
    
    public static void main(String[] args) {
        Car c1 = new Car("Tesla"); // Heap instantiation
        // No manual deletion needed
    }
}
```

**C++ vs Java Difference:** C++ allows stack and heap instantiation; Java only heap with `new`. C++ stack objects are automatically destroyed; Java relies on garbage collection. C++ requires explicit `delete` for heap objects; Java automates this.

---

### 17. Main Class

**Definition:** The class containing the main method, serving as the entry point of a program.

**Explanation:** The main class contains the main method where program execution begins. In Java, the main class name should match the filename. C++ doesn't require a class for the main function.

**C++ Code Example:**
```cpp
// C++ doesn't require a main class
// main() can be a standalone function

#include <iostream>
using namespace std;

int main() {
    cout << "Program starts here" << endl;
    return 0;
}
```

**Java Code Example:**
```java
// Main class - filename should be Main.java
public class Main {
    public static void main(String[] args) {
        System.out.println("Program starts here");
    }
}
```

**C++ vs Java Difference:** Java requires a main class containing the main method. C++ has a standalone main function without requiring a class. Java's main must be public static void; C++ main returns int. Java enforces filename matching class name.

---

### 18. Main Method

**Definition:** The method where program execution begins.

**Explanation:** The main method is the entry point for standalone applications. It must have a specific signature. In Java, it's `public static void main(String[] args)`. In C++, it's typically `int main()` or `int main(int argc, char* argv[])`.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) {
    cout << "Hello World" << endl;
    cout << "Arguments: " << argc << endl;
    return 0; // Return status code
}
```

**Java Code Example:**
```java
public class HelloWorld {
    public static void main(String[] args) {
        System.out.println("Hello World");
        System.out.println("Arguments: " + args.length);
        // No return statement needed (void)
    }
}
```

**C++ vs Java Difference:** C++ main returns int (exit status); Java main returns void. C++ main can exist outside a class; Java main must be in a class. Java requires `public static void` signature; C++ just requires return type int.

---

### 19. Instance Variable/Method

**Definition:** Variables and methods that belong to an object instance rather than the class itself.

**Explanation:** Instance variables hold the state of individual objects. Instance methods operate on instance variables and can have different behavior for different objects. Each object has its own copy of instance variables.

**C++ Code Example:**
```cpp
class Counter {
private:
    int count; // Instance variable
public:
    Counter() : count(0) {}
    
    void increment() { // Instance method
        count++;
    }
    
    int getCount() { // Instance method
        return count;
    }
};
```

**Java Code Example:**
```java
class Counter {
    private int count; // Instance variable
    
    public Counter() {
        count = 0;
    }
    
    public void increment() { // Instance method
        count++;
    }
    
    public int getCount() { // Instance method
        return count;
    }
}
```

**C++ vs Java Difference:** Both languages support instance variables/methods similarly. C++ instance methods can be declared const. Java instance variables are automatically initialized to default values; C++ leaves them uninitialized unless explicitly set. Access syntax is identical in both.

---

### 20. Static Variable/Method

**Definition:** Variables and methods that belong to the class rather than any instance.

**Explanation:** Static members are shared among all instances of a class. Static variables maintain a single copy for the class. Static methods can be called without creating an object and can only access static members.

**C++ Code Example:**
```cpp
class Bank {
private:
    static int totalAccounts; // Static variable
public:
    Bank() {
        totalAccounts++;
    }
    
    static int getTotalAccounts() { // Static method
        return totalAccounts;
    }
};

int Bank::totalAccounts = 0; // Initialize static variable
```

**Java Code Example:**
```java
class Bank {
    private static int totalAccounts = 0; // Static variable
    
    public Bank() {
        totalAccounts++;
    }
    
    public static int getTotalAccounts() { // Static method
        return totalAccounts;
    }
}
```

**C++ vs Java Difference:** C++ requires static variables to be defined outside the class (except inline static). Java allows initialization in-place. Both use `ClassName::method()` (C++) or `ClassName.method()` (Java) for static method calls. C++ uses `::`, Java uses `.`.

---

### 21. Anonymous Object

**Definition:** An object that is created without a named variable reference.

**Explanation:** Anonymous objects are temporary objects used for single operations. They're created, used immediately, and destroyed. Useful for passing arguments or single method calls without storing the object.

**C++ Code Example:**
```cpp
class Message {
public:
    void display(string msg) {
        cout << msg << endl;
    }
};

int main() {
    Message().display("Hello"); // Anonymous object
    return 0;
}
```

**Java Code Example:**
```java
class Message {
    public void display(String msg) {
        System.out.println(msg);
    }
    
    public static void main(String[] args) {
        new Message().display("Hello"); // Anonymous object
    }
}
```

**C++ vs Java Difference:** C++ anonymous objects are destructed immediately after the statement. Java anonymous objects persist until garbage collected. C++ syntax allows `ClassName()` directly; Java requires `new ClassName()`. Both are useful for one-time operations.

---

### 22. Immutable Object/Class

**Definition:** An object whose state cannot be modified after creation.

**Explanation:** Immutable objects provide thread safety and predictable behavior. Once created, their data cannot change. This is achieved by making fields final/const, providing no setters, and ensuring defensive copying for mutable fields.

**C++ Code Example:**
```cpp
class Point {
private:
    const int x;
    const int y;
public:
    Point(int xVal, int yVal) : x(xVal), y(yVal) {}
    
    int getX() const { return x; }
    int getY() const { return y; }
    
    // No setters - immutable
};
```

**Java Code Example:**
```java
final class Point { // final class prevents extension
    private final int x;
    private final int y;
    
    public Point(int xVal, int yVal) {
        x = xVal;
        y = yVal;
    }
    
    public int getX() { return x; }
    public int getY() { return y; }
    // No setters - immutable
}
```

**C++ vs Java Difference:** C++ uses `const` for immutable fields; Java uses `final`. Java's String is immutable by design. C++ requires careful const-correctness. Java provides better immutability support with final classes. Both benefit from immutability for thread safety.

---

### 23. Garbage Collection

**Definition:** Automatic memory management that reclaims memory from objects no longer in use.

**Explanation:** Garbage collection (GC) automatically deallocates memory for unreferenced objects, preventing memory leaks. Java has built-in GC. C++ requires manual memory management with delete or smart pointers.

**C++ Code Example:**
```cpp
// C++ requires manual memory management
#include <memory> // For smart pointers

int main() {
    // Manual: requires delete
    int* ptr = new int(10);
    delete ptr;
    
    // Smart pointer: automatic cleanup
    unique_ptr<int> smart(new int(20));
    // Automatically deleted when out of scope
    return 0;
}
```

**Java Code Example:**
```java
public class Main {
    public static void main(String[] args) {
        String str = new String("Hello");
        str = null; // Object eligible for GC
        
        // Suggest GC (not guaranteed to run)
        System.gc();
        
        // Object automatically garbage collected
    }
}
```

**C++ vs Java Difference:** Java has automatic garbage collection; C++ doesn't (requires manual delete or smart pointers). Java GC timing is unpredictable; C++ destruction is deterministic. C++ offers more control over memory; Java provides safety and convenience.

---

## Access Control and Inheritance

### 24. Private Member

**Definition:** Class members accessible only within the class itself.

**Explanation:** Private members enforce encapsulation by hiding implementation details. They cannot be accessed from outside the class, including derived classes. This protects data integrity and allows internal changes without affecting external code.

**C++ Code Example:**
```cpp
class BankAccount {
private: // Private members
    double balance;
    string accountNumber;
    
public:
    BankAccount(double bal) : balance(bal) {}
    
    double getBalance() {
        return balance; // Can access private member
    }
};
```

**Java Code Example:**
```java
class BankAccount {
    private double balance; // Private member
    private String accountNumber;
    
    public BankAccount(double bal) {
        balance = bal;
    }
    
    public double getBalance() {
        return balance; // Can access private member
    }
}
```

**C++ vs Java Difference:** Both languages implement private members identically. C++ has class-level access (all instances of a class can access each other's private members). Java has the same behavior. C++ default access for class is private; Java's is package-private.

---

### 25. Public Member

**Definition:** Class members accessible from anywhere in the program.

**Explanation:** Public members form the interface of a class. They can be accessed by any code that has access to an object of the class. Public methods typically provide controlled access to private data.

**C++ Code Example:**
```cpp
class Calculator {
public: // Public members
    int add(int a, int b) {
        return a + b;
    }
    
    int multiply(int a, int b) {
        return a * b;
    }
};

int main() {
    Calculator calc;
    int sum = calc.add(5, 3); // Access public method
    return 0;
}
```

**Java Code Example:**
```java
class Calculator {
    public int add(int a, int b) { // Public method
        return a + b;
    }
    
    public int multiply(int a, int b) {
        return a * b;
    }
    
    public static void main(String[] args) {
        Calculator calc = new Calculator();
        int sum = calc.add(5, 3); // Access public method
    }
}
```

**C++ vs Java Difference:** Public members work identically in both languages. C++ struct has default public access; Java doesn't have struct. Both languages use public for class interface design. Access syntax is the same in both.

---

### 26. Protected Member

**Definition:** Class members accessible within the class and by derived classes.

**Explanation:** Protected members provide a middle ground between private and public. They're hidden from external code but accessible to subclasses, allowing inheritance while maintaining encapsulation from unrelated classes.

**C++ Code Example:**
```cpp
class Animal {
protected: // Protected members
    string species;
    int age;
    
public:
    Animal(string s, int a) : species(s), age(a) {}
};

class Dog : public Animal {
public:
    Dog(string s, int a) : Animal(s, a) {}
    
    void display() {
        cout << species << " " << age; // Can access protected
    }
};
```

**Java Code Example:**
```java
class Animal {
    protected String species; // Protected member
    protected int age;
    
    public Animal(String s, int a) {
        species = s;
        age = a;
    }
}

class Dog extends Animal {
    public Dog(String s, int a) {
        super(s, a);
    }
    
    public void display() {
        System.out.println(species + " " + age); // Can access
    }
}
```

**C++ vs Java Difference:** C++ protected members are accessible by friends and within the same package in derived classes. Java protected members are also package-accessible. C++ has more complex protected inheritance rules. Both allow derived class access.

---

### 27. Base Class (Superclass)

**Definition:** The class from which other classes inherit properties and behaviors.

**Explanation:** A base class (or parent/superclass) provides common attributes and methods that can be inherited by derived classes. It establishes an "is-a" relationship and promotes code reuse through inheritance.

**C++ Code Example:**
```cpp
class Shape { // Base class
protected:
    string color;
public:
    Shape(string c) : color(c) {}
    
    void setColor(string c) {
        color = c;
    }
    
    virtual double getArea() = 0;
};
```

**Java Code Example:**
```java
class Shape { // Base class (superclass)
    protected String color;
    
    public Shape(String c) {
        color = c;
    }
    
    public void setColor(String c) {
        color = c;
    }
    
    public double getArea() {
        return 0;
    }
}
```

**C++ vs Java Difference:** C++ uses `:` for inheritance syntax; Java uses `extends`. C++ supports multiple inheritance from multiple base classes; Java allows only single inheritance (but multiple interfaces). C++ has virtual inheritance; Java doesn't need it.

---

### 28. Derived Class (Subclass)

**Definition:** A class that inherits properties and behaviors from a base class.

**Explanation:** A derived class (or child/subclass) extends a base class by inheriting its members and can add new members or override existing ones. It represents a specialized version of the base class.

**C++ Code Example:**
```cpp
class Vehicle {
protected:
    int speed;
public:
    Vehicle(int s) : speed(s) {}
};

class Car : public Vehicle { // Derived class
private:
    int doors;
public:
    Car(int s, int d) : Vehicle(s), doors(d) {}
    
    void display() {
        cout << "Speed: " << speed << " Doors: " << doors;
    }
};
```

**Java Code Example:**
```java
class Vehicle {
    protected int speed;
    
    public Vehicle(int s) {
        speed = s;
    }
}

class Car extends Vehicle { // Derived class (subclass)
    private int doors;
    
    public Car(int s, int d) {
        super(s);
        doors = d;
    }
    
    public void display() {
        System.out.println("Speed: " + speed + " Doors: " + doors);
    }
}
```

**C++ vs Java Difference:** C++ uses `:` followed by access specifier (public/protected/private); Java uses `extends`. C++ can inherit from multiple classes; Java only one class. Java uses `super()` to call parent constructor; C++ uses initializer list.

---

### 29. Public Inheritance

**Definition:** Inheritance where public and protected members of the base class remain public and protected in the derived class.

**Explanation:** Public inheritance maintains the access levels of base class members. It represents an "is-a" relationship. Public members stay public, protected stay protected, and private remain inaccessible in the derived class.

**C++ Code Example:**
```cpp
class Animal {
public:
    void eat() { cout << "Eating" << endl; }
protected:
    int age;
};

class Dog : public Animal { // Public inheritance
public:
    void bark() {
        eat(); // public in Dog
        age = 5; // protected in Dog
    }
};

int main() {
    Dog d;
    d.eat(); // Accessible (still public)
    return 0;
}
```

**Java Code Example:**
```java
// Java only has public inheritance (via extends)
class Animal {
    public void eat() {
        System.out.println("Eating");
    }
    protected int age;
}

class Dog extends Animal {
    public void bark() {
        eat(); // public in Dog
        age = 5; // protected in Dog
    }
    
    public static void main(String[] args) {
        Dog d = new Dog();
        d.eat(); // Accessible (still public)
    }
}
```

**C++ vs Java Difference:** C++ has explicit public inheritance (`: public BaseClass`). Java's `extends` is always public inheritance by default. C++ offers private and protected inheritance options; Java doesn't. Both maintain the is-a relationship with public inheritance.

---

### 30. Private Inheritance

**Definition:** C++ inheritance where public and protected base class members become private in the derived class.

**Explanation:** Private inheritance implements an "implemented-in-terms-of" relationship rather than "is-a". Base class members are accessible within the derived class but not through derived class objects. Not available in Java.

**C++ Code Example:**
```cpp
class Engine {
public:
    void start() { cout << "Engine started" << endl; }
protected:
    int power;
};

class Car : private Engine { // Private inheritance
public:
    void startCar() {
        start(); // Accessible inside Car
        power = 100; // Accessible inside Car
    }
};

int main() {
    Car c;
    c.startCar(); // OK
    // c.start(); // Error: start() is private in Car
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't support private inheritance
// Use composition instead

class Engine {
    public void start() {
        System.out.println("Engine started");
    }
    protected int power;
}

class Car {
    private Engine engine = new Engine(); // Composition
    
    public void startCar() {
        engine.start(); // Delegation
    }
}
```

**C++ vs Java Difference:** C++ supports private inheritance with `: private BaseClass`. Java doesn't have private inheritance; composition is used instead. C++ private inheritance is rarely used; composition is preferred in both languages for has-a relationships.

---

### 31. Protected Inheritance

**Definition:** C++ inheritance where public and protected base class members become protected in the derived class.

**Explanation:** Protected inheritance makes all public and protected base members protected in the derived class. It's rarely used and represents implementation detail inheritance. Private members remain inaccessible. Not available in Java.

**C++ Code Example:**
```cpp
class Component {
public:
    void initialize() { cout << "Initialized" << endl; }
protected:
    int state;
};

class Module : protected Component { // Protected inheritance
public:
    void setup() {
        initialize(); // Now protected in Module
        state = 1; // Still protected
    }
};

class System : public Module {
public:
    void configure() {
        initialize(); // Accessible (protected in Module)
    }
};
```

**Java Code Example:**
```java
// Java doesn't support protected inheritance
// Only public inheritance via extends

class Component {
    public void initialize() {
        System.out.println("Initialized");
    }
    protected int state;
}

class Module extends Component {
    public void setup() {
        initialize(); // Remains public
        state = 1; // Remains protected
    }
}
```

**C++ vs Java Difference:** C++ has protected inheritance (`: protected BaseClass`). Java only supports public inheritance. Protected inheritance in C++ is very rare and generally avoided. Java's simpler inheritance model is easier to understand and use.

---

### 32. Multiple Inheritance

**Definition:** The ability of a class to inherit from more than one base class.

**Explanation:** Multiple inheritance allows a derived class to combine features from multiple parent classes. C++ supports this but it can lead to ambiguity (diamond problem). Java doesn't support it for classes but allows multiple interface implementation.

**C++ Code Example:**
```cpp
class Flyable {
public:
    void fly() { cout << "Flying" << endl; }
};

class Swimmable {
public:
    void swim() { cout << "Swimming" << endl; }
};

class Duck : public Flyable, public Swimmable { // Multiple inheritance
public:
    void quack() { cout << "Quack" << endl; }
};

int main() {
    Duck d;
    d.fly();
    d.swim();
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't support multiple inheritance for classes
// Use interfaces instead

interface Flyable {
    void fly();
}

interface Swimmable {
    void swim();
}

class Duck implements Flyable, Swimmable { // Multiple interfaces
    public void fly() {
        System.out.println("Flying");
    }
    
    public void swim() {
        System.out.println("Swimming");
    }
    
    public void quack() {
        System.out.println("Quack");
    }
}
```

**C++ vs Java Difference:** C++ supports multiple inheritance from multiple classes. Java only allows single class inheritance but multiple interface implementation. C++ has diamond problem requiring virtual inheritance; Java avoids this complexity. Java's approach is simpler and safer.

---

### 33. Virtual Base Class

**Definition:** A base class specified as virtual in C++ to solve the diamond problem in multiple inheritance.

**Explanation:** Virtual base classes ensure only one instance of a base class exists when inherited through multiple paths. This solves ambiguity in multiple inheritance hierarchies. Not needed in Java as it doesn't support multiple class inheritance.

**C++ Code Example:**
```cpp
class Animal {
public:
    int age;
};

class Mammal : virtual public Animal { // Virtual base
};

class Bird : virtual public Animal { // Virtual base
};

class Bat : public Mammal, public Bird {
public:
    void setAge(int a) {
        age = a; // No ambiguity - single Animal instance
    }
};
```

**Java Code Example:**
```java
// Java doesn't need virtual base classes
// No multiple inheritance of classes

class Animal {
    public int age;
}

class Mammal extends Animal {
}

// Cannot extend both Mammal and Bird in Java
class Bat extends Mammal {
    public void setAge(int a) {
        age = a;
    }
}
```

**C++ vs Java Difference:** C++ requires virtual base classes to solve diamond problem in multiple inheritance. Java doesn't have this issue due to single inheritance model. C++ virtual inheritance adds complexity; Java's simpler model avoids the problem entirely.

---

### 34. Single Inheritance

**Definition:** Inheritance where a class derives from only one base class.

**Explanation:** Single inheritance creates a linear hierarchy where each class has at most one direct parent. It's simpler and avoids ambiguity issues of multiple inheritance. Java enforces single inheritance for classes.

**C++ Code Example:**
```cpp
class Vehicle {
protected:
    int wheels;
public:
    Vehicle(int w) : wheels(w) {}
};

class Car : public Vehicle { // Single inheritance
private:
    string brand;
public:
    Car(int w, string b) : Vehicle(w), brand(b) {}
};
```

**Java Code Example:**
```java
class Vehicle {
    protected int wheels;
    
    public Vehicle(int w) {
        wheels = w;
    }
}

class Car extends Vehicle { // Single inheritance
    private String brand;
    
    public Car(int w, String b) {
        super(w);
        brand = b;
    }
}
```

**C++ vs Java Difference:** C++ allows both single and multiple inheritance. Java enforces single inheritance for classes (but multiple for interfaces). Both languages commonly use single inheritance. Single inheritance is simpler and more maintainable in both languages.

---

### 35. Interface Inheritance

**Definition:** Inheritance of method signatures without implementation, defining a contract that implementing classes must fulfill.

**Explanation:** Interfaces specify what methods a class must implement without defining how. Java has explicit interfaces; C++ achieves this with abstract classes containing only pure virtual functions.

**C++ Code Example:**
```cpp
// C++ uses abstract class with pure virtual functions
class Drawable { // Interface-like class
public:
    virtual void draw() = 0; // Pure virtual
    virtual void resize(int w, int h) = 0;
    virtual ~Drawable() {}
};

class Circle : public Drawable {
public:
    void draw() override {
        cout << "Drawing circle" << endl;
    }
    void resize(int w, int h) override {
        cout << "Resizing" << endl;
    }
};
```

**Java Code Example:**
```java
interface Drawable { // Interface
    void draw();
    void resize(int w, int h);
}

class Circle implements Drawable {
    public void draw() {
        System.out.println("Drawing circle");
    }
    
    public void resize(int w, int h) {
        System.out.println("Resizing");
    }
}
```

**C++ vs Java Difference:** Java has dedicated `interface` keyword; C++ uses abstract classes. Java interfaces can have default methods (Java 8+); C++ can have regular methods in abstract classes. Java uses `implements`; C++ uses inheritance syntax.

---

### 36. Access Modifiers

**Definition:** Keywords that control the visibility and accessibility of class members.

**Explanation:** Access modifiers enforce encapsulation by restricting access to class members. They include public (accessible everywhere), private (class only), protected (class and subclasses), and package-private/default (same package - Java).

**C++ Code Example:**
```cpp
class Example {
private:
    int privateVar; // Only within class
    
protected:
    int protectedVar; // Class and derived classes
    
public:
    int publicVar; // Accessible everywhere
    
    void accessMembers() {
        privateVar = 1;
        protectedVar = 2;
        publicVar = 3;
    }
};
```

**Java Code Example:**
```java
class Example {
    private int privateVar; // Only within class
    protected int protectedVar; // Class, subclasses, package
    public int publicVar; // Accessible everywhere
    int defaultVar; // Package-private (default)
    
    public void accessMembers() {
        privateVar = 1;
        protectedVar = 2;
        publicVar = 3;
        defaultVar = 4;
    }
}
```

**C++ vs Java Difference:** Java has four levels (private, protected, public, default/package-private). C++ has three (private, protected, public) plus friend. Java's default is package-private; C++ class default is private. Java has finer package-level control.

---

### 37. Data Field Encapsulation

**Definition:** The practice of making data fields private and providing public methods to access and modify them.

**Explanation:** Encapsulation hides internal data and exposes it through controlled interfaces (getters/setters). This protects data integrity, allows validation, and enables internal changes without affecting external code.

**C++ Code Example:**
```cpp
class Person {
private:
    string name; // Encapsulated field
    int age;
    
public:
    void setName(string n) { // Controlled access
        name = n;
    }
    
    string getName() {
        return name;
    }
    
    void setAge(int a) {
        if (a > 0 && a < 150) // Validation
            age = a;
    }
    
    int getAge() {
        return age;
    }
};
```

**Java Code Example:**
```java
class Person {
    private String name; // Encapsulated field
    private int age;
    
    public void setName(String n) { // Controlled access
        name = n;
    }
    
    public String getName() {
        return name;
    }
    
    public void setAge(int a) {
        if (a > 0 && a < 150) // Validation
            age = a;
    }
    
    public int getAge() {
        return age;
    }
}
```

**C++ vs Java Difference:** Both languages implement encapsulation identically using private fields and public methods. Naming conventions differ slightly (Java uses JavaBeans style strictly). Both benefit equally from encapsulation for maintainability and data integrity.

---

### 38. default (Package-private)

**Definition:** Java's default access level where members are accessible within the same package only.

**Explanation:** When no access modifier is specified in Java, members have package-private access. They're accessible to all classes in the same package but not outside. C++ doesn't have this concept; it has friend instead.

**C++ Code Example:**
```cpp
// C++ doesn't have package-private
// Use friend classes for similar functionality

class Helper; // Forward declaration

class MyClass {
private:
    int data;
    
    friend class Helper; // Helper can access private members
};

class Helper {
public:
    void accessData(MyClass& obj) {
        obj.data = 10; // Can access due to friend
    }
};
```

**Java Code Example:**
```java
// File: MyClass.java
package mypackage;

class MyClass { // Package-private class
    int data; // Package-private field (default)
    
    void display() { // Package-private method
        System.out.println(data);
    }
}

class Helper { // Same package - can access
    void useMyClass() {
        MyClass obj = new MyClass();
        obj.data = 10; // Accessible
        obj.display();
    }
}
```

**C++ vs Java Difference:** Java has package-private (default) access level. C++ doesn't have packages; uses namespaces which don't provide access control. C++ uses friend for selective access. Java's package system provides better modularity.

---

### 39. Getter (Accessor) Method

**Definition:** A public method that returns the value of a private field.

**Explanation:** Getters provide read access to private data members. They enable encapsulation by controlling how data is retrieved and can include logic like validation, logging, or computed values.

**C++ Code Example:**
```cpp
class Temperature {
private:
    double celsius;
    
public:
    double getCelsius() { // Getter
        return celsius;
    }
    
    double getFahrenheit() { // Computed getter
        return (celsius * 9.0/5.0) + 32;
    }
    
    void setCelsius(double c) {
        celsius = c;
    }
};
```

**Java Code Example:**
```java
class Temperature {
    private double celsius;
    
    public double getCelsius() { // Getter
        return celsius;
    }
    
    public double getFahrenheit() { // Computed getter
        return (celsius * 9.0/5.0) + 32;
    }
    
    public void setCelsius(double c) {
        celsius = c;
    }
}
```

**C++ vs Java Difference:** Both implement getters identically. Java follows strict JavaBeans naming convention (get + CapitalizedFieldName). C++ const getters (`double getCelsius() const`) prevent modification. Both languages benefit from getters for encapsulation and flexibility.

---

### 40. Setter (Mutator) Method

**Definition:** A public method that modifies the value of a private field.

**Explanation:** Setters provide controlled write access to private data members. They enable validation, maintain invariants, trigger side effects, and ensure data consistency before modification.

**C++ Code Example:**
```cpp
class Account {
private:
    double balance;
    
public:
    void setBalance(double b) { // Setter with validation
        if (b >= 0) {
            balance = b;
        } else {
            cout << "Invalid balance" << endl;
        }
    }
    
    double getBalance() {
        return balance;
    }
};
```

**Java Code Example:**
```java
class Account {
    private double balance;
    
    public void setBalance(double b) { // Setter with validation
        if (b >= 0) {
            balance = b;
        } else {
            System.out.println("Invalid balance");
        }
    }
    
    public double getBalance() {
        return balance;
    }
}
```

**C++ vs Java Difference:** Both implement setters identically. Java follows JavaBeans convention (set + CapitalizedFieldName). Both allow validation logic. Java has builder pattern for complex object creation; C++ has similar patterns. Both benefit from controlled mutation.

---

### 41. final Modifier

**Definition:** A keyword that prevents modification of variables, methods, or classes.

**Explanation:** In Java, `final` makes variables constant, prevents method overriding, and prevents class inheritance. C++ uses `const` for variables and `final` (C++11) for virtual function overriding prevention.

**C++ Code Example:**
```cpp
class Base {
public:
    virtual void display() final { // Cannot be overridden
        cout << "Base" << endl;
    }
};

class Constants {
public:
    static const int MAX_SIZE = 100; // Constant
};

void example() {
    const int value = 10; // Cannot be changed
    // value = 20; // Error
}
```

**Java Code Example:**
```java
final class FinalClass { // Cannot be extended
}

class Base {
    public final void display() { // Cannot be overridden
        System.out.println("Base");
    }
}

class Constants {
    public static final int MAX_SIZE = 100; // Constant
}

void example() {
    final int value = 10; // Cannot be changed
    // value = 20; // Error
}
```

**C++ vs Java Difference:** Java uses `final` for variables, methods, and classes. C++ uses `const` for variables and `final` for virtual methods only. C++ doesn't prevent class inheritance with `final` keyword on class. Java's `final` is more comprehensive.

---

## Polymorphism and Virtual Functions

### 42. Function Overloading (Method Overloading)

**Definition:** Defining multiple functions with the same name but different parameter lists.

**Explanation:** Function overloading allows multiple methods with the same name but different signatures (number, type, or order of parameters). It provides compile-time polymorphism and makes APIs more intuitive.

**C++ Code Example:**
```cpp
class Printer {
public:
    void print(int i) {
        cout << "Integer: " << i << endl;
    }
    
    void print(double d) {
        cout << "Double: " << d << endl;
    }
    
    void print(string s) {
        cout << "String: " << s << endl;
    }
};
```

**Java Code Example:**
```java
class Printer {
    public void print(int i) {
        System.out.println("Integer: " + i);
    }
    
    public void print(double d) {
        System.out.println("Double: " + d);
    }
    
    public void print(String s) {
        System.out.println("String: " + s);
    }
}
```

**C++ vs Java Difference:** Both support function overloading identically based on parameter types and count. C++ can overload by const-ness of parameters; Java cannot. Return type doesn't affect overloading in either language. Both resolve at compile-time.

---

### 43. Virtual Function

**Definition:** A member function that can be overridden in derived classes and is resolved at runtime.

**Explanation:** Virtual functions enable runtime polymorphism. When called through a base class pointer/reference, the correct derived class version is executed based on the actual object type, not the pointer type.

**C++ Code Example:**
```cpp
class Animal {
public:
    virtual void makeSound() { // Virtual function
        cout << "Some sound" << endl;
    }
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* ptr = new Dog();
    ptr->makeSound(); // Calls Dog::makeSound()
    delete ptr;
    return 0;
}
```

**Java Code Example:**
```java
class Animal {
    public void makeSound() { // Virtual by default
        System.out.println("Some sound");
    }
}

class Dog extends Animal {
    @Override
    public void makeSound() {
        System.out.println("Woof!");
    }
    
    public static void main(String[] args) {
        Animal ref = new Dog();
        ref.makeSound(); // Calls Dog.makeSound()
    }
}
```

**C++ vs Java Difference:** C++ requires explicit `virtual` keyword; Java methods are virtual by default (except final, static, private). C++ has vtable overhead only for virtual functions; Java has it for all methods. C++ needs virtual destructors; Java handles this automatically.

---

### 44. Pure Virtual Function

**Definition:** A virtual function with no implementation in the base class, declared with = 0.

**Explanation:** Pure virtual functions make a class abstract, requiring derived classes to provide implementations. They define an interface contract. A class with at least one pure virtual function cannot be instantiated.

**C++ Code Example:**
```cpp
class Shape {
public:
    virtual double getArea() = 0; // Pure virtual
    virtual void draw() = 0;
    virtual ~Shape() {} // Virtual destructor
};

class Circle : public Shape {
private:
    double radius;
public:
    Circle(double r) : radius(r) {}
    
    double getArea() override {
        return 3.14 * radius * radius;
    }
    
    void draw() override {
        cout << "Drawing circle" << endl;
    }
};
```

**Java Code Example:**
```java
abstract class Shape {
    public abstract double getArea(); // Abstract method
    public abstract void draw();
}

class Circle extends Shape {
    private double radius;
    
    public Circle(double r) {
        radius = r;
    }
    
    public double getArea() {
        return 3.14 * radius * radius;
    }
    
    public void draw() {
        System.out.println("Drawing circle");
    }
}
```

**C++ vs Java Difference:** C++ uses `= 0` for pure virtual functions; Java uses `abstract` keyword. C++ abstract classes can have constructors and data members; Java abstract classes too. Java has interfaces for pure abstraction; C++ uses abstract classes.

---

### 45. Abstract Class

**Definition:** A class that cannot be instantiated and may contain abstract methods that must be implemented by derived classes.

**Explanation:** Abstract classes serve as templates for derived classes. They can contain both abstract methods (no implementation) and concrete methods (with implementation). They enforce that certain methods must be implemented by subclasses.

**C++ Code Example:**
```cpp
class Vehicle { // Abstract class
private:
    string brand;
public:
    Vehicle(string b) : brand(b) {}
    
    virtual void start() = 0; // Pure virtual
    
    void displayBrand() { // Concrete method
        cout << "Brand: " << brand << endl;
    }
};

class Car : public Vehicle {
public:
    Car(string b) : Vehicle(b) {}
    
    void start() override {
        cout << "Car starting" << endl;
    }
};
```

**Java Code Example:**
```java
abstract class Vehicle { // Abstract class
    private String brand;
    
    public Vehicle(String b) {
        brand = b;
    }
    
    public abstract void start(); // Abstract method
    
    public void displayBrand() { // Concrete method
        System.out.println("Brand: " + brand);
    }
}

class Car extends Vehicle {
    public Car(String b) {
        super(b);
    }
    
    public void start() {
        System.out.println("Car starting");
    }
}
```

**C++ vs Java Difference:** C++ uses pure virtual functions to create abstract classes; Java uses `abstract` keyword. Both can have concrete and abstract methods. Both cannot be instantiated. Java has both abstract classes and interfaces; C++ uses abstract classes for both purposes.

---

### 46. Method Overriding

**Definition:** Redefining a parent class method in a derived class with the same signature.

**Explanation:** Method overriding allows a subclass to provide a specific implementation of a method already defined in its parent class. The overridden method must have the same signature (name, parameters, return type).

**C++ Code Example:**
```cpp
class Parent {
public:
    virtual void display() {
        cout << "Parent display" << endl;
    }
};

class Child : public Parent {
public:
    void display() override { // Method overriding
        cout << "Child display" << endl;
    }
};

int main() {
    Child c;
    c.display(); // Calls Child::display()
    return 0;
}
```

**Java Code Example:**
```java
class Parent {
    public void display() {
        System.out.println("Parent display");
    }
}

class Child extends Parent {
    @Override // Method overriding
    public void display() {
        System.out.println("Child display");
    }
    
    public static void main(String[] args) {
        Child c = new Child();
        c.display(); // Calls Child.display()
    }
}
```

**C++ vs Java Difference:** C++ requires `virtual` in base class for runtime polymorphism; Java methods are virtual by default. C++ uses `override` keyword (optional but recommended); Java uses `@Override` annotation (optional). Both enable runtime polymorphism.

---

### 47. Compile-Time Polymorphism (Early Binding/Static)

**Definition:** Polymorphism resolved at compile-time through function overloading or operator overloading.

**Explanation:** Compile-time polymorphism occurs when the compiler determines which function to call based on the argument types and count. It's faster than runtime polymorphism but less flexible. Also called static binding or early binding.

**C++ Code Example:**
```cpp
class Math {
public:
    int add(int a, int b) { // Overloaded
        return a + b;
    }
    
    double add(double a, double b) { // Overloaded
        return a + b;
    }
    
    int add(int a, int b, int c) { // Overloaded
        return a + b + c;
    }
};

int main() {
    Math m;
    cout << m.add(2, 3) << endl; // Calls int version
    cout << m.add(2.5, 3.7) << endl; // Calls double version
    return 0;
}
```

**Java Code Example:**
```java
class Math {
    public int add(int a, int b) { // Overloaded
        return a + b;
    }
    
    public double add(double a, double b) { // Overloaded
        return a + b;
    }
    
    public int add(int a, int b, int c) { // Overloaded
        return a + b + c;
    }
    
    public static void main(String[] args) {
        Math m = new Math();
        System.out.println(m.add(2, 3)); // Calls int version
        System.out.println(m.add(2.5, 3.7)); // Calls double version
    }
}
```

**C++ vs Java Difference:** Both support compile-time polymorphism through method overloading. C++ additionally supports operator overloading; Java doesn't (except for String concatenation). Resolution mechanism is identical in both. Performance is similar.

---

### 48. Run-Time Polymorphism (Late Binding/Dynamic)

**Definition:** Polymorphism resolved at runtime through method overriding and virtual functions.

**Explanation:** Runtime polymorphism occurs when the method to call is determined during execution based on the actual object type, not the reference type. Achieved through virtual functions (C++) or method overriding (Java). Also called dynamic binding or late binding.

**C++ Code Example:**
```cpp
class Animal {
public:
    virtual void speak() {
        cout << "Animal speaks" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* ptr;
    Dog d;
    ptr = &d;
    ptr->speak(); // Runtime decision - calls Dog::speak()
    return 0;
}
```

**Java Code Example:**
```java
class Animal {
    public void speak() {
        System.out.println("Animal speaks");
    }
}

class Dog extends Animal {
    @Override
    public void speak() {
        System.out.println("Woof!");
    }
    
    public static void main(String[] args) {
        Animal ref;
        Dog d = new Dog();
        ref = d;
        ref.speak(); // Runtime decision - calls Dog.speak()
    }
}
```

**C++ vs Java Difference:** C++ requires explicit `virtual` keyword; Java methods are virtual by default. C++ has vtable only for classes with virtual functions; Java has it for all classes. C++ runtime polymorphism has slight overhead; Java's is built-in.

---

### 49. Dynamic Binding

**Definition:** The process of linking a method call to the method implementation at runtime.

**Explanation:** Dynamic binding determines which method to execute based on the actual object type during runtime, not at compile time. It enables polymorphism and flexibility but has a small performance cost compared to static binding.

**C++ Code Example:**
```cpp
class Shape {
public:
    virtual void draw() {
        cout << "Drawing shape" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Drawing circle" << endl;
    }
};

void render(Shape* s) { // Dynamic binding occurs here
    s->draw(); // Bound at runtime
}

int main() {
    Circle c;
    render(&c); // Calls Circle::draw()
    return 0;
}
```

**Java Code Example:**
```java
class Shape {
    public void draw() {
        System.out.println("Drawing shape");
    }
}

class Circle extends Shape {
    @Override
    public void draw() {
        System.out.println("Drawing circle");
    }
}

class Demo {
    static void render(Shape s) { // Dynamic binding occurs here
        s.draw(); // Bound at runtime
    }
    
    public static void main(String[] args) {
        Circle c = new Circle();
        render(c); // Calls Circle.draw()
    }
}
```

**C++ vs Java Difference:** C++ dynamic binding requires virtual functions; Java has it by default for all non-final, non-static methods. C++ uses vtables for virtual functions; Java uses similar mechanism for all methods. Both resolve method calls at runtime.

---

### 50. Polymorphic Call

**Definition:** A method call that can invoke different method implementations based on the object's actual type.

**Explanation:** Polymorphic calls enable writing flexible code that works with base class references but executes derived class implementations. The actual method called depends on the runtime type of the object.

**C++ Code Example:**
```cpp
class Employee {
public:
    virtual double calculateSalary() {
        return 30000;
    }
};

class Manager : public Employee {
public:
    double calculateSalary() override {
        return 50000;
    }
};

void printSalary(Employee* e) {
    cout << e->calculateSalary() << endl; // Polymorphic call
}

int main() {
    Manager m;
    printSalary(&m); // Calls Manager::calculateSalary()
    return 0;
}
```

**Java Code Example:**
```java
class Employee {
    public double calculateSalary() {
        return 30000;
    }
}

class Manager extends Employee {
    @Override
    public double calculateSalary() {
        return 50000;
    }
}

class Demo {
    static void printSalary(Employee e) {
        System.out.println(e.calculateSalary()); // Polymorphic call
    }
    
    public static void main(String[] args) {
        Manager m = new Manager();
        printSalary(m); // Calls Manager.calculateSalary()
    }
}
```

**C++ vs Java Difference:** Both support polymorphic calls through inheritance and virtual functions. C++ requires virtual keyword; Java methods are virtual by default. Both use similar runtime resolution mechanisms. Both enable flexible, extensible code.

---

### 51. @Override Annotation

**Definition:** A Java annotation that indicates a method is intended to override a superclass method.

**Explanation:** The @Override annotation helps catch errors at compile-time if a method doesn't actually override a parent method (due to typos or signature mismatch). It's optional but highly recommended for code clarity and error prevention.

**C++ Code Example:**
```cpp
// C++ uses override keyword (not annotation)
class Base {
public:
    virtual void display() {
        cout << "Base" << endl;
    }
};

class Derived : public Base {
public:
    void display() override { // Compile error if not overriding
        cout << "Derived" << endl;
    }
    
    // void displya() override; // Compiler error - no such method
};
```

**Java Code Example:**
```java
class Base {
    public void display() {
        System.out.println("Base");
    }
}

class Derived extends Base {
    @Override // Annotation
    public void display() {
        System.out.println("Derived");
    }
    
    // @Override
    // public void displya() {} // Compiler error - typo detected
}
```

**C++ vs Java Difference:** Java uses @Override annotation (optional); C++ uses override keyword (optional in C++11+). Both provide compile-time checking. C++ override is a contextual keyword; Java's is an annotation. Both improve code safety and readability.

---

## Friends and Operators

### 52. Friend Function

**Definition:** A C++ function that is not a member of a class but has access to its private and protected members.

**Explanation:** Friend functions break encapsulation in a controlled way. They're useful for operator overloading, allowing functions outside the class to access private data. Java doesn't have friends; it uses package-private access instead.

**C++ Code Example:**
```cpp
class Box {
private:
    int width;
    
public:
    Box(int w) : width(w) {}
    
    friend void displayWidth(Box& b); // Friend function
};

void displayWidth(Box& b) { // Not a member function
    cout << "Width: " << b.width << endl; // Can access private
}

int main() {
    Box b(10);
    displayWidth(b);
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't have friend functions
// Use package-private access instead

package mypackage;

class Box {
    private int width;
    
    public Box(int w) {
        width = w;
    }
    
    int getWidth() { // Package-private method
        return width;
    }
}

class Helper { // Same package
    static void displayWidth(Box b) {
        System.out.println("Width: " + b.getWidth());
    }
}
```

**C++ vs Java Difference:** C++ has friend functions for selective access to private members. Java doesn't have friends; uses package-private access for similar functionality. C++ friends are more explicit; Java's approach is simpler but less granular.

---

### 53. Operator Overloading

**Definition:** Redefining the behavior of operators for user-defined types.

**Explanation:** Operator overloading allows custom classes to use standard operators (+, -, *, etc.) with intuitive syntax. C++ supports extensive operator overloading. Java doesn't allow user-defined operator overloading (except String + concatenation).

**C++ Code Example:**
```cpp
class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Overload + operator
    Complex operator+(const Complex& c) {
        return Complex(real + c.real, imag + c.imag);
    }
    
    void display() {
        cout << real << " + " << imag << "i" << endl;
    }
};

int main() {
    Complex c1(3, 4), c2(1, 2);
    Complex c3 = c1 + c2; // Uses overloaded +
    c3.display();
    return 0;
}
```

**Java Example:**
```java
// Java doesn't support operator overloading
// Use methods instead

class Complex {
    private double real, imag;
    
    public Complex(double r, double i) {
        real = r;
        imag = i;
    }
    
    public Complex add(Complex c) { // Method instead of operator
        return new Complex(real + c.real, imag + c.imag);
    }
    
    public void display() {
        System.out.println(real + " + " + imag + "i");
    }
}
```

**C++ vs Java Difference:** C++ supports operator overloading for user-defined types; Java doesn't (design decision to avoid complexity). C++ allows intuitive syntax; Java requires explicit method calls. C++ is more flexible; Java is simpler.

---

### 54. Inserter (<<)

**Definition:** The stream insertion operator overloaded to output objects to output streams.

**Explanation:** In C++, overloading << allows custom objects to be printed using cout. It's typically implemented as a friend function. Java uses toString() method instead for similar functionality.

**C++ Code Example:**
```cpp
class Point {
private:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    
    friend ostream& operator<<(ostream& out, const Point& p);
};

// Overload << operator
ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}

int main() {
    Point p(3, 4);
    cout << p << endl; // Uses overloaded <<
    return 0;
}
```

**Java Code Example:**
```java
// Java uses toString() method instead

class Point {
    private int x, y;
    
    public Point(int a, int b) {
        x = a;
        y = b;
    }
    
    @Override
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
    
    public static void main(String[] args) {
        Point p = new Point(3, 4);
        System.out.println(p); // Calls toString()
    }
}
```

**C++ vs Java Difference:** C++ uses operator overloading for << with streams. Java uses toString() method which is called automatically by println(). C++ approach is more operator-centric; Java's is method-centric. Both achieve readable output.

---

### 55. Extractor (>>)

**Definition:** The stream extraction operator overloaded to input data from input streams into objects.

**Explanation:** In C++, overloading >> allows reading data into custom objects from cin. It's typically a friend function that modifies object state. Java uses Scanner or other input methods instead.

**C++ Code Example:**
```cpp
class Point {
private:
    int x, y;
public:
    Point() : x(0), y(0) {}
    
    friend istream& operator>>(istream& in, Point& p);
    friend ostream& operator<<(ostream& out, const Point& p);
};

istream& operator>>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

ostream& operator<<(ostream& out, const Point& p) {
    out << "(" << p.x << ", " << p.y << ")";
    return out;
}
```

**Java Code Example:**
```java
import java.util.Scanner;

class Point {
    private int x, y;
    
    public void input(Scanner sc) {
        x = sc.nextInt();
        y = sc.nextInt();
    }
    
    public String toString() {
        return "(" + x + ", " + y + ")";
    }
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Point p = new Point();
        p.input(sc);
        System.out.println(p);
    }
}
```

**C++ vs Java Difference:** C++ uses >> operator overloading for input. Java uses explicit input methods with Scanner or similar classes. C++ syntax is more concise; Java's approach is more explicit. Both achieve object input functionality.

---

### 56. Binary Operator Overloading (Member)

**Definition:** Overloading operators that take two operands, implemented as member functions.

**Explanation:** Binary operators like +, -, *, / can be overloaded as member functions where the left operand is the implicit object (this). The right operand is passed as a parameter.

**C++ Code Example:**
```cpp
class Vector {
private:
    int x, y;
public:
    Vector(int a = 0, int b = 0) : x(a), y(b) {}
    
    // Binary operator as member function
    Vector operator+(const Vector& v) {
        return Vector(x + v.x, y + v.y);
    }
    
    Vector operator-(const Vector& v) {
        return Vector(x - v.x, y - v.y);
    }
    
    void display() {
        cout << "(" << x << ", " << y << ")" << endl;
    }
};
```

**Java Code Example:**
```java
// Java doesn't support operator overloading
// Use methods with meaningful names

class Vector {
    private int x, y;
    
    public Vector(int a, int b) {
        x = a;
        y = b;
    }
    
    public Vector add(Vector v) {
        return new Vector(x + v.x, y + v.y);
    }
    
    public Vector subtract(Vector v) {
        return new Vector(x - v.x, y - v.y);
    }
}
```

**C++ vs Java Difference:** C++ supports binary operator overloading as member functions. Java doesn't support operator overloading; requires named methods. C++ syntax is more intuitive for mathematical operations; Java is more explicit.

---

### 57. Unary Operator Overloading (Member)

**Definition:** Overloading operators that work with single operands, like ++, --, -, !.

**Explanation:** Unary operators operate on a single object. When overloaded as member functions, they use the implicit this pointer and take no parameters (except for postfix ++/-- which takes a dummy int).

**C++ Code Example:**
```cpp
class Counter {
private:
    int count;
public:
    Counter(int c = 0) : count(c) {}
    
    // Prefix increment
    Counter& operator++() {
        ++count;
        return *this;
    }
    
    // Postfix increment (dummy int parameter)
    Counter operator++(int) {
        Counter temp = *this;
        count++;
        return temp;
    }
    
    int getCount() { return count; }
};
```

**Java Code Example:**
```java
// Java doesn't support operator overloading
// Use methods instead

class Counter {
    private int count;
    
    public Counter(int c) {
        count = c;
    }
    
    public Counter increment() {
        count++;
        return this;
    }
    
    public int getCount() {
        return count;
    }
}
```

**C++ vs Java Difference:** C++ supports unary operator overloading (++, --, -, !, ~, etc.). Java doesn't support operator overloading; requires explicit methods. C++ distinguishes prefix/postfix with dummy int parameter; Java uses different method names.

---

### 58. Assignment Operator (=)

**Definition:** The operator used to copy values from one object to another.

**Explanation:** The assignment operator copies data from one existing object to another existing object. C++ provides a default but should be overloaded for classes with dynamic memory. Java uses reference assignment, not value copying.

**C++ Code Example:**
```cpp
class String {
private:
    char* data;
    int length;
public:
    String(const char* str = "") {
        length = strlen(str);
        data = new char[length + 1];
        strcpy(data, str);
    }
    
    // Assignment operator overload
    String& operator=(const String& s) {
        if (this != &s) { // Self-assignment check
            delete[] data;
            length = s.length;
            data = new char[length + 1];
            strcpy(data, s.data);
        }
        return *this;
    }
    
    ~String() { delete[] data; }
};
```

**Java Code Example:**
```java
// Java = operator assigns references, not values
// For copying, implement a copy method or constructor

class MyString {
    private String data;
    
    public MyString(String str) {
        data = str; // String is immutable
    }
    
    public MyString copy() { // Explicit copy method
        return new MyString(data);
    }
    
    public static void main(String[] args) {
        MyString s1 = new MyString("Hello");
        MyString s2 = s1; // Reference assignment
        MyString s3 = s1.copy(); // Value copy
    }
}
```

**C++ vs Java Difference:** C++ = operator can be overloaded for deep copying. Java = always assigns references, not values. C++ requires careful implementation for classes with pointers; Java doesn't have manual memory management. For copying in Java, use clone() or copy constructors.

---

### 59. Subscript Operator ([])

**Definition:** The operator used to access elements using array-like syntax.

**Explanation:** Overloading [] allows objects to be accessed like arrays. Useful for container classes. Returns reference to allow both reading and writing. C++ supports this; Java doesn't.

**C++ Code Example:**
```cpp
class Array {
private:
    int data[10];
public:
    Array() {
        for (int i = 0; i < 10; i++)
            data[i] = 0;
    }
    
    // Subscript operator overload
    int& operator[](int index) {
        if (index >= 0 && index < 10)
            return data[index];
        throw out_of_range("Index out of bounds");
    }
};

int main() {
    Array arr;
    arr[5] = 100; // Uses []
    cout << arr[5] << endl;
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't support [] operator overloading
// Use methods instead

class Array {
    private int[] data = new int[10];
    
    public int get(int index) {
        if (index >= 0 && index < 10)
            return data[index];
        throw new IndexOutOfBoundsException();
    }
    
    public void set(int index, int value) {
        if (index >= 0 && index < 10)
            data[index] = value;
        else
            throw new IndexOutOfBoundsException();
    }
}
```

**C++ vs Java Difference:** C++ supports [] operator overloading for custom types. Java doesn't; requires get() and set() methods. C++ syntax is more concise; Java is more explicit. Both can implement bounds checking.

---

### 60. Relational/Logical Operators

**Definition:** Operators used for comparison (==, !=, <, >, <=, >=) and logical operations (&&, ||, !).

**Explanation:** Relational operators compare objects and return boolean values. They're useful for sorting, searching, and conditional logic. C++ allows overloading; Java uses equals() and compareTo() methods.

**C++ Code Example:**
```cpp
class Point {
private:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    
    // Overload == operator
    bool operator==(const Point& p) const {
        return (x == p.x && y == p.y);
    }
    
    // Overload < operator
    bool operator<(const Point& p) const {
        return (x < p.x) || (x == p.x && y < p.y);
    }
};
```

**Java Code Example:**
```java
class Point {
    private int x, y;
    
    public Point(int a, int b) {
        x = a;
        y = b;
    }
    
    @Override
    public boolean equals(Object obj) {
        if (obj instanceof Point) {
            Point p = (Point) obj;
            return x == p.x && y == p.y;
        }
        return false;
    }
    
    public int compareTo(Point p) {
        if (x != p.x) return x - p.x;
        return y - p.y;
    }
}
```

**C++ vs Java Difference:** C++ can overload relational operators directly. Java uses equals() for equality and compareTo() for ordering. C++ syntax is more operator-like; Java uses method calls. Both achieve comparison functionality effectively.

---

### 61. Friend Operator Function

**Definition:** An operator overload implemented as a friend function rather than a member function.

**Explanation:** Some operators are better implemented as friend functions, especially when the left operand is not an object of the class (like cout << object). Friends access private members but aren't class members.

**C++ Code Example:**
```cpp
class Complex {
private:
    double real, imag;
public:
    Complex(double r = 0, double i = 0) : real(r), imag(i) {}
    
    // Friend operator functions
    friend Complex operator+(const Complex& c1, const Complex& c2);
    friend ostream& operator<<(ostream& out, const Complex& c);
};

Complex operator+(const Complex& c1, const Complex& c2) {
    return Complex(c1.real + c2.real, c1.imag + c2.imag);
}

ostream& operator<<(ostream& out, const Complex& c) {
    out << c.real << " + " << c.imag << "i";
    return out;
}
```

**Java Code Example:**
```java
// Java doesn't have friend functions or operator overloading
// Use regular methods

class Complex {
    private double real, imag;
    
    public Complex(double r, double i) {
        real = r;
        imag = i;
    }
    
    public Complex add(Complex c) {
        return new Complex(real + c.real, imag + c.imag);
    }
    
    public String toString() {
        return real + " + " + imag + "i";
    }
}
```

**C++ vs Java Difference:** C++ has friend operator functions for flexible operator overloading. Java doesn't support operator overloading or friends. C++ allows symmetric operations; Java requires explicit method calls. C++ is more flexible; Java is simpler.

---

### 62. Postfix/Prefix Operators

**Definition:** Increment (++) and decrement (--) operators in prefix (++x) and postfix (x++) forms.

**Explanation:** Prefix operators modify the operand and return the new value. Postfix operators return the old value then modify. C++ distinguishes them with a dummy int parameter; Java doesn't allow overloading.

**C++ Code Example:**
```cpp
class Integer {
private:
    int value;
public:
    Integer(int v = 0) : value(v) {}
    
    // Prefix ++
    Integer& operator++() {
        ++value;
        return *this; // Return new value
    }
    
    // Postfix ++ (dummy int)
    Integer operator++(int) {
        Integer temp = *this;
        value++;
        return temp; // Return old value
    }
    
    int getValue() { return value; }
};
```

**Java Code Example:**
```java
// Java doesn't support operator overloading
// Simulate with methods

class Integer {
    private int value;
    
    public Integer(int v) {
        value = v;
    }
    
    public Integer preIncrement() {
        value++;
        return this; // Return new value
    }
    
    public Integer postIncrement() {
        Integer temp = new Integer(value);
        value++;
        return temp; // Return old value
    }
    
    public int getValue() {
        return value;
    }
}
```

**C++ vs Java Difference:** C++ can overload prefix/postfix operators with dummy int parameter to distinguish them. Java doesn't support operator overloading; requires separate named methods. C++ syntax matches built-in types; Java uses method calls.

---

## Memory and Pointers

### 63. new Operator

**Definition:** An operator that dynamically allocates memory on the heap.

**Explanation:** The new operator allocates memory at runtime and returns a pointer (C++) or reference (Java) to the allocated object. Memory allocated with new persists until explicitly deallocated (C++) or garbage collected (Java).

**C++ Code Example:**
```cpp
class Student {
public:
    string name;
    Student(string n) : name(n) {
        cout << "Student created" << endl;
    }
    ~Student() {
        cout << "Student destroyed" << endl;
    }
};

int main() {
    Student* s = new Student("Alice"); // Heap allocation
    cout << s->name << endl;
    delete s; // Must manually free memory
    return 0;
}
```

**Java Code Example:**
```java
class Student {
    String name;
    
    public Student(String n) {
        name = n;
        System.out.println("Student created");
    }
    
    public static void main(String[] args) {
        Student s = new Student("Alice"); // Heap allocation
        System.out.println(s.name);
        // Automatic garbage collection, no delete needed
    }
}
```

**C++ vs Java Difference:** C++ new returns a pointer; Java new returns a reference. C++ requires manual delete; Java uses garbage collection. C++ new can fail and throw bad_alloc; Java throws OutOfMemoryError. Both allocate on heap.

---

### 64. delete Operator

**Definition:** A C++ operator that deallocates memory previously allocated with new.

**Explanation:** The delete operator frees heap memory and calls the destructor. Essential for preventing memory leaks. Use delete for single objects and delete[] for arrays. Java doesn't need delete; uses garbage collection.

**C++ Code Example:**
```cpp
class Resource {
public:
    int* data;
    
    Resource() {
        data = new int[100];
        cout << "Resource allocated" << endl;
    }
    
    ~Resource() {
        delete[] data;
        cout << "Resource freed" << endl;
    }
};

int main() {
    Resource* r = new Resource();
    delete r; // Calls destructor and frees memory
    
    int* arr = new int[10];
    delete[] arr; // Use delete[] for arrays
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't have delete operator
// Uses automatic garbage collection

class Resource {
    int[] data;
    
    public Resource() {
        data = new int[100];
        System.out.println("Resource allocated");
    }
    
    protected void finalize() { // Deprecated
        System.out.println("Being garbage collected");
    }
    
    public static void main(String[] args) {
        Resource r = new Resource();
        r = null; // Eligible for GC
        System.gc(); // Suggest GC (not guaranteed)
    }
}
```

**C++ vs Java Difference:** C++ requires explicit delete to free heap memory. Java has automatic garbage collection, no delete needed. C++ delete is immediate and deterministic; Java GC is automatic but timing is unpredictable. C++ offers more control; Java is safer.

---

### 65. Reference

**Definition:** An alias for an existing variable, providing an alternative name for the same memory location.

**Explanation:** References must be initialized when declared and cannot be reassigned. They act as aliases to existing objects. C++ has true references; Java has reference variables (which are more like pointers to objects).

**C++ Code Example:**
```cpp
void swap(int& a, int& b) { // Reference parameters
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10;
    int& ref = x; // Reference to x
    ref = 20; // Changes x
    cout << x << endl; // Outputs 20
    
    int a = 5, b = 7;
    swap(a, b); // Pass by reference
    cout << a << " " << b << endl; // 7 5
    return 0;
}
```

**Java Code Example:**
```java
// Java references are actually object references (like pointers)
class Point {
    int x, y;
}

class Demo {
    static void modify(Point p) {
        p.x = 100; // Modifies original object
    }
    
    public static void main(String[] args) {
        Point p1 = new Point();
        p1.x = 10;
        
        Point p2 = p1; // p2 references same object
        p2.x = 20; // Changes p1.x too
        
        modify(p1);
        System.out.println(p1.x); // 100
    }
}
```

**C++ vs Java Difference:** C++ references are true aliases that cannot be null or reassigned. Java "references" are actually object pointers that can be null and reassigned. C++ references are safer for function parameters; Java references are more flexible.

---

### 66. Reference Parameter

**Definition:** Function parameters that are references to arguments, allowing the function to modify original values.

**Explanation:** Reference parameters avoid copying and allow functions to modify caller's variables. C++ uses & for references; Java passes objects by reference automatically (primitives by value).

**C++ Code Example:**
```cpp
void increment(int& num) { // Reference parameter
    num++; // Modifies original
}

void displayAndModify(const string& str, int& count) {
    cout << str << endl; // const ref - no copy, can't modify
    count++; // non-const ref - can modify
}

int main() {
    int x = 10;
    increment(x);
    cout << x << endl; // 11
    
    string s = "Hello";
    int c = 0;
    displayAndModify(s, c);
    return 0;
}
```

**Java Code Example:**
```java
class Demo {
    static void increment(int num) {
        num++; // Doesn't affect original (primitives pass by value)
    }
    
    static void modifyObject(StringBuilder sb) {
        sb.append(" World"); // Modifies original object
    }
    
    public static void main(String[] args) {
        int x = 10;
        increment(x);
        System.out.println(x); // Still 10
        
        StringBuilder s = new StringBuilder("Hello");
        modifyObject(s);
        System.out.println(s); // Hello World
    }
}
```

**C++ vs Java Difference:** C++ has explicit reference parameters with &. Java passes object references by value (can modify object contents, not the reference itself). C++ can use const references to prevent modification; Java requires wrapper classes for primitive modification.

---

### 67. Object Pointer

**Definition:** A pointer variable that stores the memory address of an object.

**Explanation:** Object pointers allow dynamic object creation, polymorphism, and data structures like linked lists. C++ has explicit pointers; Java references behave similarly but with automatic memory management.

**C++ Code Example:**
```cpp
class Car {
public:
    string model;
    Car(string m) : model(m) {}
    void display() {
        cout << "Model: " << model << endl;
    }
};

int main() {
    Car* ptr = new Car("Tesla"); // Object pointer
    ptr->display(); // Access via pointer
    cout << ptr->model << endl;
    
    Car* arr = new Car[3]{ // Array of objects
        Car("BMW"), Car("Audi"), Car("Ford")
    };
    
    delete ptr;
    delete[] arr;
    return 0;
}
```

**Java Code Example:**
```java
class Car {
    String model;
    
    public Car(String m) {
        model = m;
    }
    
    public void display() {
        System.out.println("Model: " + model);
    }
    
    public static void main(String[] args) {
        Car ref = new Car("Tesla"); // Reference (like pointer)
        ref.display();
        System.out.println(ref.model);
        
        Car[] arr = new Car[3]; // Array of references
        arr[0] = new Car("BMW");
        arr[1] = new Car("Audi");
        arr[2] = new Car("Ford");
    }
}
```

**C++ vs Java Difference:** C++ uses explicit pointers with -> operator. Java uses references with . operator (no pointer syntax). C++ requires manual delete; Java has garbage collection. C++ pointers can do pointer arithmetic; Java references cannot.

---

### 68. Pointers to Derived Classes

**Definition:** Base class pointers that can point to derived class objects, enabling polymorphism.

**Explanation:** A base class pointer can hold addresses of derived class objects. When calling virtual functions through such pointers, the derived class version executes. This enables runtime polymorphism and is fundamental to OOP design patterns.

**C++ Code Example:**
```cpp
class Animal {
public:
    virtual void speak() {
        cout << "Animal sound" << endl;
    }
    virtual ~Animal() {}
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* ptr; // Base class pointer
    Dog d;
    ptr = &d; // Points to derived object
    ptr->speak(); // Calls Dog::speak()
    
    Animal* arr[2];
    arr[0] = new Dog();
    arr[0]->speak(); // Polymorphism
    delete arr[0];
    return 0;
}
```

**Java Code Example:**
```java
class Animal {
    public void speak() {
        System.out.println("Animal sound");
    }
}

class Dog extends Animal {
    @Override
    public void speak() {
        System.out.println("Woof!");
    }
    
    public static void main(String[] args) {
        Animal ref; // Base class reference
        Dog d = new Dog();
        ref = d; // References derived object
        ref.speak(); // Calls Dog.speak()
        
        Animal[] arr = new Animal[2];
        arr[0] = new Dog();
        arr[0].speak(); // Polymorphism
    }
}
```

**C++ vs Java Difference:** C++ uses pointers to base class; Java uses references. Both achieve polymorphism similarly. C++ requires virtual functions; Java methods are virtual by default. C++ needs virtual destructor for proper cleanup; Java handles this automatically.

---

### 69. Arrow Operator (->)

**Definition:** A C++ operator used to access members through a pointer.

**Explanation:** The arrow operator (->) dereferences a pointer and accesses a member in one operation. It's equivalent to (*ptr).member but more concise. Java doesn't have pointers, so it doesn't have this operator.

**C++ Code Example:**
```cpp
class Student {
public:
    string name;
    int age;
    
    void display() {
        cout << name << ", " << age << endl;
    }
};

int main() {
    Student* ptr = new Student();
    
    ptr->name = "Alice"; // Using arrow operator
    ptr->age = 20;
    ptr->display();
    
    // Equivalent to:
    (*ptr).name = "Alice"; // Dereference then access
    
    delete ptr;
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't have -> operator
// Uses . operator for both objects and references

class Student {
    String name;
    int age;
    
    void display() {
        System.out.println(name + ", " + age);
    }
    
    public static void main(String[] args) {
        Student ref = new Student();
        
        ref.name = "Alice"; // Using dot operator
        ref.age = 20;
        ref.display();
    }
}
```

**C++ vs Java Difference:** C++ uses -> for pointer member access and . for object member access. Java only uses . for all reference access (no distinction). C++ has two operators for clarity; Java's single operator is simpler.

---

### 70. Dot Operator (.)

**Definition:** An operator used to access members of an object or class.

**Explanation:** The dot operator accesses members (variables and methods) of an object. In C++, it's used with objects and references; in Java, it's used with references (and for static members with class names).

**C++ Code Example:**
```cpp
class Person {
public:
    string name;
    
    void greet() {
        cout << "Hello, " << name << endl;
    }
};

int main() {
    Person p; // Object
    p.name = "Bob"; // Dot operator with object
    p.greet();
    
    Person& ref = p; // Reference
    ref.name = "Alice"; // Dot operator with reference
    ref.greet();
    
    return 0;
}
```

**Java Code Example:**
```java
class Person {
    String name;
    static int count = 0;
    
    void greet() {
        System.out.println("Hello, " + name);
    }
    
    public static void main(String[] args) {
        Person p = new Person(); // Reference
        p.name = "Bob"; // Dot operator with reference
        p.greet();
        
        Person.count = 10; // Dot with class name for static
        System.out.println(Person.count);
    }
}
```

**C++ vs Java Difference:** C++ uses . for objects and references, -> for pointers. Java only uses . for all references and static access. C++ has :: for static members; Java uses . Both operators provide member access functionality.

---

## Special Functions and Modifiers

### 71. In-line Function

**Definition:** A function whose code is inserted at each call site rather than being called via jump instruction.

**Explanation:** Inline functions eliminate function call overhead for small, frequently called functions. The compiler replaces function calls with the actual function code. Use for simple, small functions. Both languages support this.

**C++ Code Example:**
```cpp
class Math {
public:
    // Inline function (implicit)
    int square(int x) {
        return x * x;
    }
    
    // Explicit inline
    inline int cube(int x);
};

inline int Math::cube(int x) {
    return x * x * x;
}

// Standalone inline
inline int add(int a, int b) {
    return a + b;
}
```

**Java Code Example:**
```java
class Math {
    // JVM decides inlining automatically
    // Small methods are typically inlined
    public int square(int x) {
        return x * x;
    }
    
    public int cube(int x) {
        return x * x * x;
    }
    
    // final methods are better candidates for inlining
    public final int add(int a, int b) {
        return a + b;
    }
}
```

**C++ vs Java Difference:** C++ has explicit `inline` keyword (compiler hint). Java JVM automatically inlines methods at runtime (JIT optimization). C++ inlining is compile-time; Java's is runtime. Java's approach is more automated; C++ gives explicit control.

---

### 72. const Member Function

**Definition:** A C++ member function that promises not to modify the object's state.

**Explanation:** Const member functions can be called on const objects and provide guarantees that object state won't change. They're part of const-correctness in C++. Java doesn't have this feature.

**C++ Code Example:**
```cpp
class Point {
private:
    int x, y;
public:
    Point(int a, int b) : x(a), y(b) {}
    
    int getX() const { // Const member function
        return x;
    }
    
    int getY() const {
        return y;
    }
    
    void setX(int a) { // Non-const
        x = a;
    }
    
    int distance() const { // Can call other const functions
        return sqrt(x*x + y*y);
    }
};

void display(const Point& p) {
    cout << p.getX() << ", " << p.getY() << endl; // OK
    // p.setX(10); // Error: can't call non-const on const object
}
```

**Java Code Example:**
```java
// Java doesn't have const member functions
// Use final for variables, but no const for methods

class Point {
    private int x, y;
    
    public Point(int a, int b) {
        x = a;
        y = b;
    }
    
    public int getX() { // No const keyword
        return x;
    }
    
    public int getY() {
        return y;
    }
    
    public void setX(int a) {
        x = a;
    }
}
```

**C++ vs Java Difference:** C++ has const member functions for const-correctness. Java doesn't have this feature; relies on documentation and conventions. C++ enforces immutability at compile-time; Java uses final for variables but not for methods preventing modification.

---

### 73. mutable Keyword

**Definition:** A C++ keyword that allows a member variable to be modified even in const member functions.

**Explanation:** Mutable allows specific members to be changed in const functions. Useful for caching, counters, or internal state that doesn't affect logical constness. Java doesn't have this concept.

**C++ Code Example:**
```cpp
class Cache {
private:
    int value;
    mutable int accessCount; // Can be modified in const functions
    mutable bool cached;
    
public:
    Cache(int v) : value(v), accessCount(0), cached(false) {}
    
    int getValue() const { // Const function
        accessCount++; // OK: accessCount is mutable
        cached = true; // OK: cached is mutable
        return value;
    }
    
    int getAccessCount() const {
        return accessCount;
    }
};
```

**Java Code Example:**
```java
// Java doesn't have mutable keyword
// All instance variables can be modified unless final

class Cache {
    private int value;
    private int accessCount = 0; // Can always modify
    private boolean cached = false;
    
    public Cache(int v) {
        value = v;
    }
    
    public int getValue() {
        accessCount++; // Always allowed
        cached = true;
        return value;
    }
    
    public int getAccessCount() {
        return accessCount;
    }
}
```

**C++ vs Java Difference:** C++ has mutable keyword for selective mutability in const contexts. Java doesn't have const member functions, so mutable isn't needed. C++ provides finer control over constness; Java has simpler model.

---

### 74. Static Member Variable

**Definition:** A class variable shared by all instances of the class, belonging to the class rather than any object.

**Explanation:** Static member variables maintain a single copy for the entire class. Changes affect all instances. Used for class-wide properties like counters, configuration, or shared resources.

**C++ Code Example:**
```cpp
class Student {
private:
    static int totalStudents; // Declaration
    int id;
    
public:
    Student() {
        id = ++totalStudents;
    }
    
    static int getTotalStudents() {
        return totalStudents;
    }
};

// Definition (required in C++)
int Student::totalStudents = 0;

int main() {
    Student s1, s2, s3;
    cout << Student::getTotalStudents() << endl; // 3
    return 0;
}
```

**Java Code Example:**
```java
class Student {
    private static int totalStudents = 0; // Can initialize here
    private int id;
    
    public Student() {
        id = ++totalStudents;
    }
    
    public static int getTotalStudents() {
        return totalStudents;
    }
    
    public static void main(String[] args) {
        Student s1 = new Student();
        Student s2 = new Student();
        Student s3 = new Student();
        System.out.println(Student.getTotalStudents()); // 3
    }
}
```

**C++ vs Java Difference:** C++ requires separate definition outside class (except inline static). Java allows initialization at declaration. Both access via ClassName::member (C++) or ClassName.member (Java). Both share single copy across all instances.

---

### 75. Static Member Function

**Definition:** A function that belongs to the class rather than any instance, accessible without creating an object.

**Explanation:** Static member functions can only access static members (can't use this pointer). They're called using the class name. Used for utility functions, factory methods, or operations on static data.

**C++ Code Example:**
```cpp
class MathUtil {
private:
    static int count;
    
public:
    static int add(int a, int b) { // Static member function
        return a + b;
    }
    
    static int multiply(int a, int b) {
        return a * b;
    }
    
    static void incrementCount() {
        count++; // Can access static members
        // this->count; // Error: no 'this' in static function
    }
};

int MathUtil::count = 0;

int main() {
    int sum = MathUtil::add(5, 3); // Call without object
    cout << sum << endl;
    return 0;
}
```

**Java Code Example:**
```java
class MathUtil {
    private static int count = 0;
    
    public static int add(int a, int b) { // Static method
        return a + b;
    }
    
    public static int multiply(int a, int b) {
        return a * b;
    }
    
    public static void incrementCount() {
        count++; // Can access static members
        // this.count; // Error: no 'this' in static context
    }
    
    public static void main(String[] args) {
        int sum = MathUtil.add(5, 3); // Call without object
        System.out.println(sum);
    }
}
```

**C++ vs Java Difference:** Both implement static member functions identically. C++ uses :: for access; Java uses . Both can't access instance members or use this. Both are called with class name. Functionality is essentially the same.

---

### 76. super Keyword

**Definition:** A Java keyword used to refer to the parent class's members or constructor.

**Explanation:** Super accesses parent class members when overridden in subclass, calls parent constructors, and disambiguates when names conflict. C++ doesn't have super; uses base class name directly.

**C++ Code Example:**
```cpp
// C++ doesn't have 'super' keyword
// Use base class name directly

class Parent {
public:
    void display() {
        cout << "Parent display" << endl;
    }
};

class Child : public Parent {
public:
    void display() {
        Parent::display(); // Call parent's display
        cout << "Child display" << endl;
    }
    
    Child() : Parent() { // Call parent constructor
        cout << "Child constructor" << endl;
    }
};
```

**Java Code Example:**
```java
class Parent {
    public void display() {
        System.out.println("Parent display");
    }
}

class Child extends Parent {
    @Override
    public void display() {
        super.display(); // Call parent's display using super
        System.out.println("Child display");
    }
    
    public Child() {
        super(); // Call parent constructor
        System.out.println("Child constructor");
    }
}
```

**C++ vs Java Difference:** Java has super keyword for parent class access. C++ uses BaseClassName:: syntax. Java super() must be first in constructor; C++ uses initializer list. Java's super is simpler; C++ requires class name.


**C++ vs Java Difference:** C++ static_cast is compile-time only, no runtime checks. Java casting includes runtime type checking. C++ has multiple cast operators; Java has one cast syntax with automatic checking. Java is safer; C++ offers more control.

---

