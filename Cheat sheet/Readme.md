# Complete OOP Concepts Reference Guide 

## Table of Contents

1. [Fundamental Structure and Lifetime](#fundamental-structure-and-lifetime)
   - Object
   - Class
   - Member Function
   - Constructor
   - Destructor
   - Copy Constructor
   - Converting Constructor
   - explicit Keyword
   - this Pointer
   - Scope Resolution Operator (::)
   - Parameterized Constructor
   - Default Constructor
   - Constructor Chaining
   - Constructor/Destructor Order (Inheritance)
   - Object Lifecycle
   - Instantiation
   - Main Class
   - Main Method
   - Instance Variable/Method
   - Static Variable/Method
   - Anonymous Object
   - Immutable Object/Class
   - Garbage Collection

2. [Access Control and Inheritance](#access-control-and-inheritance)
   - Private Member
   - Public Member
   - Protected Member
   - Base Class (Superclass)
   - Derived Class (Subclass)
   - Public Inheritance
   - Private Inheritance
   - Protected Inheritance
   - Multiple Inheritance
   - Virtual Base Class
   - Single Inheritance
   - Interface Inheritance
   - Access Modifiers
   - Data Field Encapsulation
   - default (Package-private)
   - Getter (Accessor) Method
   - Setter (Mutator) Method
   - final Modifier

3. [Polymorphism and Virtual Functions](#polymorphism-and-virtual-functions)
   - Function Overloading (Method Overloading)
   - Virtual Function
   - Pure Virtual Function
   - Abstract Class
   - Method Overriding
   - Compile-Time Polymorphism (Early Binding/Static)
   - Run-Time Polymorphism (Late Binding/Dynamic)
   - Dynamic Binding
   - Polymorphic Call
   - @Override Annotation

4. [Friends and Operators](#friends-and-operators)
   - Friend Function
   - Operator Overloading
   - Inserter (<<)
   - Extractor (>>)
   - Binary Operator Overloading (Member)
   - Unary Operator Overloading (Member)
   - Assignment Operator (=)
   - Subscript Operator ([])
   - Relational/Logical Operators
   - Friend Operator Function
   - Postfix/Prefix Operators

5. [Memory and Pointers](#memory-and-pointers)
   - new Operator
   - delete Operator
   - Reference
   - Reference Parameter
   - Object Pointer
   - Pointers to Derived Classes
   - Arrow Operator (->)
   - Dot Operator (.)

6. [Special Functions and Modifiers](#special-functions-and-modifiers)
   - In-line Function
   - const Member Function
   - mutable Keyword
   - Static Member Variable
   - Static Member Function
   - super Keyword

7. [RTTI and Casting](#rtti-and-casting)
   - Run-Time Type Identification (RTTI)
   - typeid Operator
   - dynamic_cast
   - const_cast
   - static_cast
   - reinterpret_cast
   - Upcasting (Implicit)
   - Downcasting (Explicit)
   - instanceof Operator
   - type_info Object

8. [Templates and Generics](#templates-and-generics)
   - Generic Function (Template)
   - Generic Class (Template Class)
   - Namespace
   - using Statement
   - Formal Generic Type
   - Wildcard Generic Type
   - Template Instantiation

9. [Standard Template Library (STL)](#standard-template-library-stl)
   - STL
   - Containers
   - Algorithms
   - Iterators
   - vector
   - list
   - queue
   - stack
   - map
   - Random-access Iterator
   - Bidirectional Iterator
   - Forward Iterator
   - Input Iterator
   - Output Iterator
   - size_type
   - iterator type
   - value_type

10. [Exception Handling](#exception-handling)
    - Exception Handling
    - try Block
    - throw Statement
    - catch Block
    - Checked Exception
    - Unchecked Exception
    - RuntimeException
    - Error
    - Chained Exceptions
    - Throwable

11. [Interfaces and Abstract Classes](#interfaces-and-abstract-classes)
    - Interface
    - Abstract Method
    - Interface Contents
    - Implementation (implements Keyword)
    - Comparable Interface
    - Cloneable Interface
    - Marker Interface
    - Functional Interface
    - Subinterface
    - extends Keyword

12. [Relationships and Design](#relationships-and-design)
    - Encapsulation
    - Inheritance
    - Polymorphism
    - Abstraction
    - Association
    - Aggregation
    - Composition
    - "is-a" Relationship
    - "has-a" Relationship
    - "is-kind-of" Relationship
    - Hierarchical Classification
    - Code Reusability
    - Data Hiding
    - Information Hiding
    - Class Abstraction

13. [Object Methods and Utilities](#object-methods-and-utilities)
    - equals Method
    - toString Method
    - clone() Method
    - compareTo Method
    - Wrapper Class
    - Integer
    - Double
    - Autoboxing
    - Autounboxing

14. [Advanced Features](#advanced-features)
    - Inner Class
    - Anonymous Inner Class
    - Lambda Expression
    - UML Class Diagram
    - State (attributes)
    - Behavior (methods)
    - Identity (unique name)
    - Object Identity
    - Black Box
    - Contract (class contract)
    - No-arg Constructor
    - Protective Shield
    - Controlled Interface
    - Formal Generic Type Parameter
    - Generic Type Argument

---

## Fundamental Structure and Lifetime

### Table of Contents
1. [Object](#1-object)
2. [Class](#2-class)
3. [Member Function](#3-member-function)
4. [Constructor](#4-constructor)
5. [Destructor](#5-destructor)
6. [Copy Constructor](#6-copy-constructor)
7. [Converting Constructor](#7-converting-constructor)
8. [explicit Keyword](#8-explicit-keyword)
9. [this Pointer](#9-this-pointer)
10. [Scope Resolution Operator (::)](#10-scope-resolution-operator-)
11. [Parameterized Constructor](#11-parameterized-constructor)
12. [Default Constructor](#12-default-constructor)
13. [Constructor Chaining](#13-constructor-chaining)
14. [Constructor/Destructor Order (Inheritance)](#14-constructordestructor-order-inheritance)
15. [Object Lifecycle](#15-object-lifecycle)
16. [Instantiation](#16-instantiation)
17. [Main Class](#17-main-class)
18. [Main Method](#18-main-method)
19. [Instance Variable/Method](#19-instance-variablemethod)
20. [Static Variable/Method](#20-static-variablemethod)
21. [Anonymous Object](#21-anonymous-object)
22. [Immutable Object/Class](#22-immutable-objectclass)
23. [Garbage Collection](#23-garbage-collection)

---

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

**Python Code Example:**
```python
class Student:
    name = ""
    age = 0

s1 = Student()  # s1 is an object
s1.name = "Alice"
s1.age = 20
print(s1.name, s1.age)
```

**Key Differences:** In C++, objects can be created on the stack (automatic storage) or heap (dynamic storage). In Java, all objects are created on the heap using `new`, and variables hold references to objects, not the objects themselves. In Python, objects are created by calling the class name as a function (e.g., `s1 = Student()`), and all objects are on the heap with automatic memory management via reference counting supplemented by a cyclic garbage collector.

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

**Python Code Example:**
```python
class Rectangle:
    def __init__(self):
        self.__width = 0
        self.__height = 0

    def set_dimensions(self, w, h):
        self.__width = w
        self.__height = h

    def get_area(self):
        return self.__width * self.__height
```

**Key Differences:** C++ classes use semicolon at the end of class definition. Java classes don't require semicolons. C++ has default private access for class members, while Java has package-private (default) access. In Python, class definitions use `class ClassName:` syntax (no semicolons, no braces), and default member access is public; `__` prefix performs name mangling to avoid accidental name collisions in subclasses (use `_` prefix by convention to signal internal members).

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

**Python Code Example:**
```python
class Circle:
    def __init__(self):
        self.__radius = 0.0

    def set_radius(self, r):  # Member method
        self.__radius = r

    def get_area(self):  # Member method
        return 3.14 * self.__radius * self.__radius
```

**Key Differences:** C++ member functions can be defined inside or outside the class using scope resolution operator (::). Java methods are always defined within the class body. C++ supports const member functions; Java doesn't have this feature. In Python, methods are defined using `def` inside the class body and always receive `self` as the first parameter explicitly; there is no `const` equivalent.

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

**Python Code Example:**
```python
class Book:
    def __init__(self, title="Unknown", pages=0):  # Constructor (__init__)
        self.title = title
        self.pages = pages

b1 = Book()                  # Default values
b2 = Book("Python 101", 300) # Parameterized
```

**Key Differences:** C++ objects can be created without `new`, automatically calling constructor. Java requires explicit `new` keyword. C++ supports member initializer lists for efficiency; Java uses assignment in constructor body. Python uses `__init__` as the constructor, which can have default parameters to serve as both default and parameterized constructors in one.

---

### 5. Destructor

**Definition:** A special member function that is automatically called when an object is destroyed.

**Explanation:** Destructors clean up resources (like memory, file handles) before an object is destroyed. In C++, the destructor name is the class name preceded by a tilde (~). Java uses finalizers (deprecated) or try-with-resources instead. Python has `__del__`, but its invocation is non-deterministic; Python's context manager protocol (`__enter__`/`__exit__`) is the idiomatic way to manage resources.

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

**Python Code Example:**
```python
class FileHandler:
    def __init__(self, name):
        self.filename = name
        print(f"File opened: {self.filename}")

    def __del__(self):  # Destructor
        print(f"File closed: {self.filename}")

fh = FileHandler("data.txt")
# Destructor called when object is garbage collected
```

**Key Differences:** C++ has explicit destructors called automatically when objects go out of scope. Java relies on garbage collection and doesn't have destructors. Java's `finalize()` method (deprecated) is unpredictable, so explicit cleanup methods are preferred. Python has `__del__` as a destructor, but like Java its invocation timing is unpredictable (depends on garbage collector); use context managers (`with` statement) for reliable cleanup.

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

**Python Code Example:**
```python
import copy

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __copy__(self):  # Shallow copy support
        return Point(self.x, self.y)

p1 = Point(1, 2)
p2 = copy.copy(p1)  # Uses __copy__
print(p2.x, p2.y)  # 1 2
```

**Key Differences:** C++ automatically provides a default copy constructor and calls it implicitly. Java doesn't have automatic copy constructors; you must implement them manually. Java passes objects by reference, so copying happens less frequently. Python uses the `copy` module (`copy.copy()` for shallow, `copy.deepcopy()` for deep copy) or implements `__copy__`/`__deepcopy__`; there is no automatic copy constructor.

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

**Python Code Example:**
```python
class Distance:
    def __init__(self, meters):
        if isinstance(meters, str):
            self.meters = int(meters)  # Convert from string
        else:
            self.meters = meters

    def display(self):
        print(f"Distance: {self.meters}m")

d = Distance(100)
d2 = Distance("200")  # Converts string to int
d2.display()
```

**Key Differences:** C++ allows implicit conversion via converting constructors (can be prevented with `explicit`). Java doesn't support implicit object conversion; all constructor calls must be explicit with the `new` keyword. Python doesn't have converting constructors; type conversion is handled by `__init__` checking input types (e.g., `isinstance`) or by `@classmethod` factory methods.

---

### 8. explicit Keyword

**Definition:** A C++ keyword that prevents implicit type conversions through constructors. Python and Java do not have an equivalent keyword, as they use different approaches to avoid unintended conversions.

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

**Python Code Example:**
```python
# Python doesn't have 'explicit' keyword
# Use @classmethod for named constructors to be explicit

class Score:
    def __init__(self, value):
        self.value = value

    @classmethod
    def from_percentage(cls, pct):  # Explicit named constructor
        return cls(int(pct))

s = Score(95)           # Direct construction
s2 = Score.from_percentage(95.5)  # Explicit conversion
```

**Key Differences:** C++ has the `explicit` keyword to prevent implicit conversions. Java doesn't need this keyword because it doesn't support implicit constructor conversions; all object creation must use the `new` keyword explicitly. Python has no `explicit` keyword; use `@classmethod` named constructors or type checking in `__init__` to enforce explicit construction.

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

**Python Code Example:**
```python
class Account:
    def __init__(self, balance):
        self.balance = balance  # 'self' is Python's 'this'

    def deposit(self, amount):
        self.balance += amount
        return self  # Return current object (method chaining)

acc = Account(1000)
acc.deposit(500).deposit(200)  # Method chaining
print(acc.balance)  # 1700
```

**Key Differences:** In C++, `this` is a pointer (use `->` to access members). In Java, `this` is a reference (use `.` to access members). C++ `this` is a pointer constant; Java `this` is a final reference. In Python, `self` is the equivalent of `this`, but it must be explicitly declared as the first parameter of every instance method; it is a regular reference, not a pointer.

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

**Python Code Example:**
```python
# Python uses module.class or ClassName.method() notation

class Calculator:
    @staticmethod
    def multiply(a, b):
        return a * b

    def add(self, a, b):
        return a + b

# Access via class name (equivalent to ::)
result = Calculator.multiply(3, 4)
print(result)  # 12
```

**Key Differences:** C++ has the `::` operator for defining members outside the class and accessing nested scopes. Java requires all methods to be defined within the class body and uses dot notation for static member access. Python has no `::` operator; use `ClassName.method()` for class/static method access and module-level namespace using dot notation.

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

**Python Code Example:**
```python
class Employee:
    def __init__(self, name, emp_id, salary):  # Parameterized constructor
        self.name = name
        self.emp_id = emp_id
        self.salary = salary

emp = Employee("John", 101, 50000.0)
print(emp.name, emp.emp_id)
```

**Key Differences:** Both languages support parameterized constructors similarly. C++ can use member initializer lists for efficiency. Java uses assignment in constructor body. C++ objects can be created on stack; Java requires heap allocation with `new`. Python's `__init__` method serves as the parameterized constructor; default parameter values allow a single `__init__` to act as both default and parameterized constructor.

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

**Python Code Example:**
```python
class Product:
    def __init__(self, name="Unknown", price=0.0):  # Default constructor
        self.name = name
        self.price = price

p = Product()  # Uses defaults
p2 = Product("Laptop", 999.99)
print(p.name)  # Unknown
```

**Key Differences:** Both languages auto-generate default constructors if none are defined. C++ default constructor leaves primitive types uninitialized for local objects; Java initializes all fields to default values (0, null, false). C++ syntax doesn't require `new`. Python's `__init__` with default parameter values provides default-constructor behavior; if no `__init__` is defined, the base `object.__init__` is used.

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

**Python Code Example:**
```python
class Vehicle:
    def __init__(self, brand="Unknown", year=2000):
        self.brand = brand
        self.year = year
        print("Vehicle created")

class Car(Vehicle):
    def __init__(self, brand, year, model):
        super().__init__(brand, year)  # Constructor chaining via super()
        self.model = model

c = Car("Toyota", 2023, "Camry")
```

**Key Differences:** C++11 introduced delegating constructors using initializer lists. Java uses `this()` which must be the first statement. Java's syntax is more explicit; C++'s uses initialization list syntax. Both achieve code reuse effectively. Python uses `super().__init__()` to call the parent constructor; within the same class, default parameter values or separate class methods are used instead of `this()`.

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

**Python Code Example:**
```python
class Base:
    def __init__(self):
        print("Base constructor")

    def __del__(self):
        print("Base destructor")

class Derived(Base):
    def __init__(self):
        super().__init__()  # Base constructor called first
        print("Derived constructor")

    def __del__(self):
        print("Derived destructor")
        super().__del__()  # Base destructor called after
```

**Key Differences:** C++ has explicit destructors called in reverse order of construction. Java relies on garbage collection without explicit destructors. C++ destructor order is deterministic and immediate; Java cleanup is non-deterministic. Python constructors are called from base to derived (using `super().__init__()`); `__del__` destructors are called by the garbage collector in an undefined order.

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

**Python Code Example:**
```python
class Resource:
    def __init__(self):
        print("Created")

    def use(self):
        print("Using")

    def __del__(self):
        print("Destroyed")

r = Resource()  # Created
r.use()         # Using
del r           # Destroyed explicitly
```

**Key Differences:** C++ objects have deterministic lifecycles with explicit destruction when leaving scope. Java objects persist until garbage collected, making lifecycle timing unpredictable. C++ requires manual memory management for heap objects; Java handles this automatically. Python objects are created on the heap and managed by reference counting (CPython) plus cyclic garbage collection; destruction via `__del__` is non-deterministic, so `with` statements are preferred for resource cleanup.

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

**Python Code Example:**
```python
class Car:
    def __init__(self, model):
        self.model = model

c1 = Car("Tesla")   # Instantiation
c2 = Car("BMW")     # Another instance
print(c1.model)  # Tesla
print(c2.model)  # BMW
```

**Key Differences:** C++ allows stack and heap instantiation; Java only heap with `new`. C++ stack objects are automatically destroyed; Java relies on garbage collection. C++ requires explicit `delete` for heap objects; Java automates this. Python creates all objects on the heap by calling the class name; memory is managed automatically via reference counting and GC, with no explicit `delete` needed.

---

### 17. Main Class

**Definition:** The class containing the main method, serving as the entry point of a program. In Python, there is no required main class; the script entry point is typically guarded by `if __name__ == '__main__':`.

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

**Python Code Example:**
```python
# Python doesn't require a main class
# Convention: use if __name__ == "__main__"

class MyApp:
    def run(self):
        print("App running")

if __name__ == "__main__":
    app = MyApp()
    app.run()
```

**Key Differences:** Java requires a main class containing the main method. C++ has a standalone main function without requiring a class. Java's main must be public static void; C++ main returns int. Java enforces filename matching class name. Python doesn't require a main class; scripts are executed top-to-bottom, and `if __name__ == '__main__':` is the idiomatic entry point guard.

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

**Python Code Example:**
```python
import sys

def main():
    print("Hello World")
    print(f"Arguments: {len(sys.argv) - 1}")

if __name__ == "__main__":
    main()
```

**Key Differences:** C++ main returns int (exit status); Java main returns void. C++ main can exist outside a class; Java main must be in a class. Java requires `public static void` signature; C++ just requires return type int. Python has no main method requirement; `if __name__ == '__main__':` is the standard idiom for entry point code, and the block is optional.

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

**Python Code Example:**
```python
class Counter:
    def __init__(self):
        self.count = 0  # Instance variable

    def increment(self):  # Instance method
        self.count += 1

    def get_count(self):  # Instance method
        return self.count

c1 = Counter()
c2 = Counter()
c1.increment()
print(c1.get_count())  # 1
print(c2.get_count())  # 0 (independent)
```

**Key Differences:** Both languages support instance variables/methods similarly. C++ instance methods can be declared const. Java instance variables are automatically initialized to default values; C++ leaves them uninitialized unless explicitly set. Access syntax is identical in both. Python instance variables are created in `__init__` by assigning to `self.variable`; they are public by default—use `_` prefix by convention for internal members and `__` prefix for name mangling to avoid collision in subclasses. Instance methods always take `self` as first parameter.

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

**Python Code Example:**
```python
class Bank:
    total_accounts = 0  # Class (static) variable

    def __init__(self):
        Bank.total_accounts += 1

    @staticmethod
    def get_total_accounts():  # Static method
        return Bank.total_accounts

b1 = Bank()
b2 = Bank()
print(Bank.get_total_accounts())  # 2
```

**Key Differences:** C++ requires static variables to be defined outside the class (except inline static). Java allows initialization in-place. Both use `ClassName::method()` (C++) or `ClassName.method()` (Java) for static method calls. C++ uses `::`, Java uses `.`. Python uses the `@staticmethod` decorator for static methods (no `self` or `cls`); class variables are defined at class level; `@classmethod` receives `cls` as the first parameter.

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

**Python Code Example:**
```python
class Message:
    def display(self, msg):
        print(msg)

# Anonymous object: created and used immediately
Message().display("Hello")  # No variable assigned
```

**Key Differences:** C++ anonymous objects are destructed immediately after the statement. Java anonymous objects persist until garbage collected. C++ syntax allows `ClassName()` directly; Java requires `new ClassName()`. Both are useful for one-time operations. Python creates temporary objects in expressions (e.g., `Student().greet()`); they are garbage collected when no longer referenced, similar to Java's behavior.

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

**Python Code Example:**
```python
class Point:
    def __init__(self, x, y):
        self.__x = x
        self.__y = y

    @property
    def x(self):
        return self.__x

    @property
    def y(self):
        return self.__y
    # No setters - immutable

p = Point(3, 4)
print(p.x, p.y)  # 3 4
# p.x = 5  # AttributeError: can't set attribute
```

**Key Differences:** C++ uses `const` for immutable fields; Java uses `final`. Java's String is immutable by design. C++ requires careful const-correctness. Java provides better immutability support with final classes. Both benefit from immutability for thread safety. Python achieves immutability using `__slots__` combined with properties, overriding `__setattr__`, or using `@dataclass(frozen=True)`; built-in types like `int`, `str`, and `tuple` are immutable by design.

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

**Python Code Example:**
```python
import gc

class MyObj:
    pass

obj = MyObj()
obj = None  # Object eligible for GC

gc.collect()  # Manually trigger garbage collection

# Python uses reference counting + cyclic GC
print(gc.get_count())  # View GC stats
```

**Key Differences:** Java has automatic garbage collection; C++ doesn't (requires manual delete or smart pointers). Java GC timing is unpredictable; C++ destruction is deterministic. C++ offers more control over memory; Java provides safety and convenience. Python uses reference counting as its primary GC mechanism (CPython), with a cyclic garbage collector to handle reference cycles; like Java, it provides automatic memory management without explicit `delete`.

---

## Access Control and Inheritance

### Table of Contents
24. [Private Member](#24-private-member)
25. [Public Member](#25-public-member)
26. [Protected Member](#26-protected-member)
27. [Base Class (Superclass)](#27-base-class-superclass)
28. [Derived Class (Subclass)](#28-derived-class-subclass)
29. [Public Inheritance](#29-public-inheritance)
30. [Private Inheritance](#30-private-inheritance)
31. [Protected Inheritance](#31-protected-inheritance)
32. [Multiple Inheritance](#32-multiple-inheritance)
33. [Virtual Base Class](#33-virtual-base-class)
34. [Single Inheritance](#34-single-inheritance)
35. [Interface Inheritance](#35-interface-inheritance)
36. [Access Modifiers](#36-access-modifiers)
37. [Data Field Encapsulation](#37-data-field-encapsulation)
38. [default (Package-private)](#38-default-package-private)
39. [Getter (Accessor) Method](#39-getter-accessor-method)
40. [Setter (Mutator) Method](#40-setter-mutator-method)
41. [final Modifier](#41-final-modifier)

---

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

**Python Code Example:**
```python
class BankAccount:
    def __init__(self, balance):
        self.__balance = balance  # Private (name mangling: _BankAccount__balance)

    def get_balance(self):
        return self.__balance  # Accessible within class

acc = BankAccount(1000)
print(acc.get_balance())  # 1000
# print(acc.__balance)  # AttributeError
```

**Key Differences:** Both languages implement private members identically. C++ has class-level access (all instances of a class can access each other's private members). Java has the same behavior. C++ default access for class is private; Java's is package-private. In Python, there is no true private access; a single underscore prefix (`_name`) is a convention for 'internal use', while double underscore (`__name`) triggers name mangling to `_ClassName__name` to avoid accidental override in subclasses.

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

**Python Code Example:**
```python
class Person:
    def __init__(self, name, age):
        self.name = name   # Public member
        self.age = age     # Public member

    def greet(self):       # Public method
        print(f"Hi, I'm {self.name}")

p = Person("Alice", 25)
print(p.name)   # Direct access
p.greet()
```

**Key Differences:** Public members work identically in both languages. C++ struct has default public access; Java doesn't have struct. Both languages use public for class interface design. Access syntax is the same in both. In Python, all members are public by default; use underscore conventions (`_` or `__`) to signal restricted access.

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

**Python Code Example:**
```python
class Animal:
    def __init__(self, name):
        self._name = name  # Protected (convention: single underscore)

    def _speak(self):  # Protected method
        print(f"{self._name} makes a sound")

class Dog(Animal):
    def bark(self):
        self._speak()  # Accessible in subclass
        print(f"{self._name} barks")
```

**Key Differences:** C++ protected members are accessible by friends and within the same package in derived classes. Java protected members are also package-accessible. C++ has more complex protected inheritance rules. Both allow derived class access. In Python, a single underscore prefix (`_name`) is the convention for protected/internal members; it is not enforced by the language.

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

**Python Code Example:**
```python
class Shape:  # Base class
    def __init__(self, color):
        self.color = color

    def display(self):
        print(f"Color: {self.color}")

class Circle(Shape):  # Derived from Shape
    def __init__(self, color, radius):
        super().__init__(color)
        self.radius = radius
```

**Key Differences:** C++ uses `:` for inheritance syntax; Java uses `extends`. C++ supports multiple inheritance from multiple base classes; Java allows only single inheritance (but multiple interfaces). C++ has virtual inheritance; Java doesn't need it. Python uses `class Derived(Base):` syntax for inheritance; `super()` accesses the base class; supports multiple inheritance with MRO (Method Resolution Order) using C3 linearization.

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

**Python Code Example:**
```python
class Animal:  # Base class
    def __init__(self, name):
        self.name = name

    def eat(self):
        print(f"{self.name} eats")

class Dog(Animal):  # Derived class
    def __init__(self, name, breed):
        super().__init__(name)
        self.breed = breed

    def bark(self):
        print(f"{self.name} barks!")
```

**Key Differences:** C++ uses `:` followed by access specifier (public/protected/private); Java uses `extends`. C++ can inherit from multiple classes; Java only one class. Java uses `super()` to call parent constructor; C++ uses initializer list. Python subclasses are defined as `class Child(Parent):`; `super()` calls parent methods; Python supports multiple inheritance natively.

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

**Python Code Example:**
```python
class Vehicle:
    def __init__(self, brand):
        self.brand = brand  # Accessible publicly

    def start(self):
        print(f"{self.brand} started")

class Car(Vehicle):  # Python inheritance is public by default
    def __init__(self, brand, model):
        super().__init__(brand)
        self.model = model

c = Car("Toyota", "Corolla")
c.start()         # Inherited public method
print(c.brand)    # Inherited public attribute
```

**Key Differences:** C++ has explicit public inheritance (`: public BaseClass`). Java's `extends` is always public inheritance by default. C++ offers private and protected inheritance options; Java doesn't. Both maintain the is-a relationship with public inheritance. Python inheritance is always analogous to public inheritance; there is no access specifier in the inheritance syntax — `class Child(Parent):` is the only form.

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

**Python Code Example:**
```python
# Python doesn't have private inheritance
# Can simulate using composition or name-mangling conventions

class Engine:
    def start(self):
        print("Engine started")

class Car:
    def __init__(self):
        self.__engine = Engine()  # Composition simulates private inheritance

    def drive(self):
        self.__engine.start()  # Internal use only

c = Car()
c.drive()
```

**Key Differences:** C++ supports private inheritance with `: private BaseClass`. Java doesn't have private inheritance; composition is used instead. C++ private inheritance is rarely used; composition is preferred in both languages for has-a relationships. Python has no private inheritance; the recommended alternative is composition (has-a relationship), just as in Java.

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

**Python Code Example:**
```python
# Python doesn't have protected inheritance
# By convention, use single underscore for "protected" intent

class Base:
    def _protected_method(self):
        print("Protected method")

class Derived(Base):  # All inheritance is public in Python
    def access_protected(self):
        self._protected_method()  # Accessible in subclass

d = Derived()
d.access_protected()
```

**Key Differences:** C++ has protected inheritance (`: protected BaseClass`). Java only supports public inheritance. Protected inheritance in C++ is very rare and generally avoided. Java's simpler inheritance model is easier to understand and use. Python has no protected inheritance; single underscore convention (`_`) signals intended restricted access, but all members are accessible from subclasses.

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

**Python Code Example:**
```python
class Flyable:
    def fly(self):
        print("Flying")

class Swimmable:
    def swim(self):
        print("Swimming")

class Duck(Flyable, Swimmable):  # Multiple inheritance
    def quack(self):
        print("Quack!")

d = Duck()
d.fly()    # From Flyable
d.swim()   # From Swimmable
d.quack()
```

**Key Differences:** C++ supports multiple inheritance from multiple classes. Java only allows single class inheritance but multiple interface implementation. C++ has diamond problem requiring virtual inheritance; Java avoids this complexity. Java's approach is simpler and safer. Python supports multiple inheritance natively (`class C(A, B):`); the MRO (Method Resolution Order) using C3 linearization resolves method lookup order and handles diamond inheritance without needing virtual base classes.

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

**Python Code Example:**
```python
class A:
    def method(self):
        print("A.method")

class B(A):
    pass

class C(A):
    pass

class D(B, C):  # Python MRO handles diamond problem automatically
    pass

d = D()
d.method()  # Calls A.method once (MRO: D -> B -> C -> A)
print(D.__mro__)
```

**Key Differences:** C++ requires virtual base classes to solve diamond problem in multiple inheritance. Java doesn't have this issue due to single inheritance model. C++ virtual inheritance adds complexity; Java's simpler model avoids the problem entirely. Python resolves the diamond problem automatically using MRO (C3 linearization); there is no `virtual` base class keyword — `super()` in all classes ensures each base `__init__` is called only once.

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

**Python Code Example:**
```python
class Animal:
    def __init__(self, name):
        self.name = name

    def eat(self):
        print(f"{self.name} eats")

class Dog(Animal):  # Single inheritance
    def bark(self):
        print(f"{self.name} barks!")

dog = Dog("Rex")
dog.eat()   # Inherited
dog.bark()  # Own method
```

**Key Differences:** C++ allows both single and multiple inheritance. Java enforces single inheritance for classes (but multiple for interfaces). Both languages commonly use single inheritance. Single inheritance is simpler and more maintainable in both languages. Python supports single inheritance with `class Child(Parent):`; it also supports multiple inheritance, unlike Java's class single-inheritance restriction.

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

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class Printable(ABC):  # Abstract class as interface
    @abstractmethod
    def print_info(self):
        pass

class Document(Printable):
    def __init__(self, content):
        self.content = content

    def print_info(self):  # Must implement
        print(self.content)

doc = Document("Hello World")
doc.print_info()
```

**Key Differences:** Java has dedicated `interface` keyword; C++ uses abstract classes. Java interfaces can have default methods (Java 8+); C++ can have regular methods in abstract classes. Java uses `implements`; C++ uses inheritance syntax. Python has no `interface` keyword; abstract base classes (`abc.ABC` with `@abstractmethod`) serve the same role; duck typing also allows interface-like polymorphism without formal inheritance.

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

**Python Code Example:**
```python
class MyClass:
    def __init__(self):
        self.public_var = "public"        # Public
        self._protected_var = "protected"  # Protected (convention)
        self.__private_var = "private"     # Private (name mangling)

    def show(self):
        print(self.public_var)
        print(self._protected_var)
        print(self.__private_var)

obj = MyClass()
print(obj.public_var)       # OK
print(obj._protected_var)   # OK (convention only)
# print(obj.__private_var)  # AttributeError
```

**Key Differences:** Java has four levels (private, protected, public, default/package-private). C++ has three (private, protected, public) plus friend. Java's default is package-private; C++ class default is private. Java has finer package-level control. Python has no formal access modifiers; it uses naming conventions: no prefix (public), `_` prefix (protected/internal by convention), `__` prefix (name-mangled). Access is not enforced by the interpreter.

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

**Python Code Example:**
```python
class Student:
    def __init__(self, name, grade):
        self.__name = name    # Encapsulated
        self.__grade = grade  # Encapsulated

    @property
    def name(self):
        return self.__name

    @property
    def grade(self):
        return self.__grade

    @grade.setter
    def grade(self, value):
        if 0 <= value <= 100:
            self.__grade = value

s = Student("Alice", 90)
s.grade = 95
print(s.grade)  # 95
```

**Key Differences:** Both languages implement encapsulation identically using private fields and public methods. Naming conventions differ slightly (Java uses JavaBeans style strictly). Both benefit equally from encapsulation for maintainability and data integrity. Python achieves encapsulation through naming conventions (`_` and `__` prefixes) and properties (`@property`); there are no formal access modifiers enforced at runtime.

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

**Python Code Example:**
```python
# Python uses module-level privacy by convention
# Names starting with _ are "module-private" (convention)

class MyClass:
    def public_method(self):     # Public
        print("Public")

    def _internal_method(self):  # Module-private by convention
        print("Internal")

# In Python, "_" prefix signals "not for public use"
obj = MyClass()
obj.public_method()     # Fine
obj._internal_method()  # Allowed but discouraged
```

**Key Differences:** Java has package-private (default) access level. C++ doesn't have packages; uses namespaces which don't provide access control. C++ uses friend for selective access. Java's package system provides better modularity. Python has no package-private access level; module-level underscore prefix (`_name`) is the convention for module-internal names (hidden from `from module import *`), but is not enforced.

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

**Python Code Example:**
```python
class Person:
    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    @property
    def name(self):  # Getter using property decorator
        return self.__name

    @property
    def age(self):
        return self.__age

p = Person("Alice", 25)
print(p.name)  # Alice  (calls getter)
print(p.age)   # 25
```

**Key Differences:** Both implement getters identically. Java follows strict JavaBeans naming convention (get + CapitalizedFieldName). C++ const getters (`double getCelsius() const`) prevent modification. Both languages benefit from getters for encapsulation and flexibility. Python uses the `@property` decorator to create getters, allowing attribute-style access (`obj.value`) while executing getter logic; no strict naming convention like Java's `getX()` is required.

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

**Python Code Example:**
```python
class Person:
    def __init__(self, name, age):
        self.__name = name
        self.__age = age

    @property
    def age(self):
        return self.__age

    @age.setter
    def age(self, value):  # Setter with validation
        if value >= 0:
            self.__age = value
        else:
            print("Invalid age")

p = Person("Bob", 25)
p.age = 30   # Calls setter
p.age = -5   # Invalid age
```

**Key Differences:** Both implement setters identically. Java follows JavaBeans convention (set + CapitalizedFieldName). Both allow validation logic. Java has builder pattern for complex object creation; C++ has similar patterns. Both benefit from controlled mutation. Python uses `@property_name.setter` decorator for setters, allowing `obj.value = x` syntax while executing setter logic; no `setX()` naming convention is enforced.

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

**Python Code Example:**
```python
# Python doesn't have 'final' keyword
# Use conventions or typing.Final for constants

from typing import Final

MAX_SIZE: Final = 100  # Final constant (type hint, not enforced)

class Point:
    def __init__(self, x, y):
        self._x: Final = x  # Signals immutability
        self._y: Final = y

# To prevent subclassing, override __init_subclass__
class NoSubclass:
    def __init_subclass__(cls, **kwargs):
        raise TypeError("Cannot subclass NoSubclass")
```

**Key Differences:** Java uses `final` for variables, methods, and classes. C++ uses `const` for variables and `final` for virtual methods only. C++ doesn't prevent class inheritance with `final` keyword on class. Java's `final` is more comprehensive. Python has no `final` keyword; use `@property` without a setter to create read-only attributes, or document intent with naming conventions; `Final` from `typing` module provides static type hint support.

---

## Polymorphism and Virtual Functions

### Table of Contents
42. [Function Overloading (Method Overloading)](#42-function-overloading-method-overloading)
43. [Virtual Function](#43-virtual-function)
44. [Pure Virtual Function](#44-pure-virtual-function)
45. [Abstract Class](#45-abstract-class)
46. [Method Overriding](#46-method-overriding)
47. [Compile-Time Polymorphism (Early Binding/Static)](#47-compile-time-polymorphism-early-bindingstatic)
48. [Run-Time Polymorphism (Late Binding/Dynamic)](#48-run-time-polymorphism-late-bindingdynamic)
49. [Dynamic Binding](#49-dynamic-binding)
50. [Polymorphic Call](#50-polymorphic-call)
51. [@Override Annotation](#51-override-annotation)

---

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

**Python Code Example:**
```python
# Python doesn't support true method overloading
# Use default arguments or *args instead

class Calculator:
    def add(self, a, b, c=0):  # Default argument simulates overloading
        return a + b + c

    def multiply(self, *args):  # Variable args
        result = 1
        for n in args:
            result *= n
        return result

calc = Calculator()
print(calc.add(2, 3))     # 5
print(calc.add(2, 3, 4))  # 9
```

**Key Differences:** Both support function overloading identically based on parameter types and count. C++ can overload by const-ness of parameters; Java cannot. Return type doesn't affect overloading in either language. Both resolve at compile-time. Python doesn't support traditional method overloading by signature; instead, use default parameter values, `*args`/`**kwargs`, or `functools.singledispatch` for type-based dispatch.

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

**Python Code Example:**
```python
class Shape:
    def area(self):  # Virtual by default in Python
        return 0

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):  # Override
        return 3.14 * self.radius ** 2

class Rectangle(Shape):
    def __init__(self, w, h):
        self.width = w
        self.height = h

    def area(self):  # Override
        return self.width * self.height

shapes = [Circle(5), Rectangle(4, 6)]
for s in shapes:
    print(s.area())  # Dynamic dispatch
```

**Key Differences:** C++ requires explicit `virtual` keyword; Java methods are virtual by default (except final, static, private). C++ has vtable overhead only for virtual functions; Java has it for all methods. C++ needs virtual destructors; Java handles this automatically. In Python, all instance methods are effectively virtual (overridable) by default; there is no `virtual` keyword. Use `abc.ABC` with `@abstractmethod` for abstract/pure-virtual behavior.

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

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self) -> float:  # Pure virtual (abstract method)
        pass

    @abstractmethod
    def perimeter(self) -> float:
        pass

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius

    def area(self):
        return 3.14 * self.radius ** 2

    def perimeter(self):
        return 2 * 3.14 * self.radius
```

**Key Differences:** C++ uses `= 0` for pure virtual functions; Java uses `abstract` keyword. C++ abstract classes can have constructors and data members; Java abstract classes too. Java has interfaces for pure abstraction; C++ uses abstract classes. Python uses `@abstractmethod` from the `abc` module to declare pure virtual methods; a class with abstract methods cannot be instantiated, similar to C++ pure virtual functions.

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

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class Animal(ABC):  # Abstract class
    def __init__(self, name):
        self.name = name

    @abstractmethod
    def speak(self):  # Abstract method
        pass

    def eat(self):  # Concrete method
        print(f"{self.name} eats")

class Dog(Animal):
    def speak(self):
        print(f"{self.name} says Woof!")

# animal = Animal("test")  # TypeError: Can't instantiate abstract class
dog = Dog("Rex")
dog.speak()
```

**Key Differences:** C++ uses pure virtual functions to create abstract classes; Java uses `abstract` keyword. Both can have concrete and abstract methods. Both cannot be instantiated. Java has both abstract classes and interfaces; C++ uses abstract classes for both purposes. Python creates abstract classes by inheriting from `abc.ABC` and decorating methods with `@abstractmethod`; attempting to instantiate an abstract class raises `TypeError`.

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

**Python Code Example:**
```python
class Animal:
    def speak(self):
        print("Some sound")

class Dog(Animal):
    def speak(self):  # Overrides parent method
        print("Woof!")

class Cat(Animal):
    def speak(self):  # Overrides parent method
        print("Meow!")

animals = [Dog(), Cat()]
for animal in animals:
    animal.speak()  # Polymorphic call
```

**Key Differences:** C++ requires `virtual` in base class for runtime polymorphism; Java methods are virtual by default. C++ uses `override` keyword (optional but recommended); Java uses `@Override` annotation (optional). Both enable runtime polymorphism. Python supports method overriding natively; override a method by redefining it in the subclass with the same name. There is no `@Override` annotation, but `super().method()` calls the parent's version.

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

**Python Code Example:**
```python
# Python is dynamically typed - all binding is at runtime
# Simulate operator overloading (closest to compile-time poly)

class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):  # Operator overloading
        return Vector(self.x + other.x, self.y + other.y)

    def __str__(self):
        return f"({self.x}, {self.y})"

v1 = Vector(1, 2)
v2 = Vector(3, 4)
print(v1 + v2)  # (4, 6)
```

**Key Differences:** Both support compile-time polymorphism through method overloading. C++ additionally supports operator overloading; Java doesn't (except for String concatenation). Resolution mechanism is identical in both. Performance is similar. Python does not support compile-time (static) polymorphism through overloading; it relies on duck typing and default arguments. `functools.singledispatch` can simulate type-based dispatch.

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

**Python Code Example:**
```python
class Shape:
    def draw(self):
        print("Drawing shape")

class Circle(Shape):
    def draw(self):
        print("Drawing circle")

class Square(Shape):
    def draw(self):
        print("Drawing square")

# All method calls in Python are resolved at runtime
def render(shape: Shape):
    shape.draw()  # Runtime polymorphism

render(Circle())   # Drawing circle
render(Square())   # Drawing square
```

**Key Differences:** C++ requires explicit `virtual` keyword; Java methods are virtual by default. C++ has vtable only for classes with virtual functions; Java has it for all classes. C++ runtime polymorphism has slight overhead; Java's is built-in. Python achieves run-time polymorphism through duck typing and method overriding; all method calls are dynamically dispatched by default, making `virtual` keyword unnecessary.

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

**Python Code Example:**
```python
class Base:
    def method(self):
        print("Base method")

class Derived(Base):
    def method(self):
        print("Derived method")

def call_method(obj):
    obj.method()  # Resolved at runtime (dynamic binding)

b = Base()
d = Derived()
call_method(b)  # Base method
call_method(d)  # Derived method
```

**Key Differences:** C++ dynamic binding requires virtual functions; Java has it by default for all non-final, non-static methods. C++ uses vtables for virtual functions; Java uses similar mechanism for all methods. Both resolve method calls at runtime. Python uses dynamic binding for all attribute and method lookups by default; method resolution uses the MRO at runtime, making all Python method calls dynamically bound.

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

**Python Code Example:**
```python
class Animal:
    def sound(self):
        pass

class Dog(Animal):
    def sound(self):
        return "Woof"

class Cat(Animal):
    def sound(self):
        return "Meow"

class Cow(Animal):
    def sound(self):
        return "Moo"

animals = [Dog(), Cat(), Cow()]
for animal in animals:
    print(animal.sound())  # Polymorphic calls
```

**Key Differences:** Both support polymorphic calls through inheritance and virtual functions. C++ requires virtual keyword; Java methods are virtual by default. Both use similar runtime resolution mechanisms. Both enable flexible, extensible code. Python supports polymorphic calls through duck typing and method overriding; any object with the expected method can be used, regardless of its class hierarchy.

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

**Python Code Example:**
```python
# Python doesn't have @Override annotation
# Use typing or override decorator from typing_extensions

class Base:
    def greet(self):
        print("Hello from Base")

class Derived(Base):
    def greet(self):  # Implicitly overrides
        print("Hello from Derived")

# Python 3.12+ has @override from typing
# from typing import override
# @override
# def greet(self): ...
```

**Key Differences:** Java uses @Override annotation (optional); C++ uses override keyword (optional in C++11+). Both provide compile-time checking. C++ override is a contextual keyword; Java's is an annotation. Both improve code safety and readability. Python has no `@Override` annotation; overriding is implicit by redefining a method with the same name in a subclass. Python 3.12+ introduced `@override` from `typing` as an optional static type hint.

---

## Friends and Operators

### Table of Contents
52. [Friend Function](#52-friend-function)
53. [Operator Overloading](#53-operator-overloading)
54. [Inserter (<<)](#54-inserter-)
55. [Extractor (>>)](#55-extractor-)
56. [Binary Operator Overloading (Member)](#56-binary-operator-overloading-member)
57. [Unary Operator Overloading (Member)](#57-unary-operator-overloading-member)
58. [Assignment Operator (=)](#58-assignment-operator-)
59. [Subscript Operator ([])](#59-subscript-operator-)
60. [Relational/Logical Operators](#60-relationallogical-operators)
61. [Friend Operator Function](#61-friend-operator-function)
62. [Postfix/Prefix Operators](#62-postfixprefix-operators)

---

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

**Python Code Example:**
```python
# Python doesn't have 'friend' keyword
# Use module-level functions that access class internals
# or use name-mangling access

class Box:
    def __init__(self, volume):
        self.__volume = volume

def compare_boxes(box1, box2):  # Module-level "friend" function
    # Access via name-mangled attribute
    return box1._Box__volume > box2._Box__volume

b1 = Box(10)
b2 = Box(20)
print(compare_boxes(b1, b2))  # False
```

**Key Differences:** C++ has friend functions for selective access to private members. Java doesn't have friends; uses package-private access for similar functionality. C++ friends are more explicit; Java's approach is simpler but less granular. Python has no friend function concept; all methods can access class internals through `self`, and module-level functions can access objects through their public/convention-private attributes. Use underscore conventions for intent.

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

**Python Code Example:**
```python
class Complex:
    def __init__(self, real, imag):
        self.real = real
        self.imag = imag

    def __add__(self, other):  # Overload +
        return Complex(self.real + other.real, self.imag + other.imag)

    def __str__(self):
        return f"{self.real} + {self.imag}i"

c1 = Complex(2, 3)
c2 = Complex(1, 4)
print(c1 + c2)  # 3 + 7i
```

**Key Differences:** C++ supports operator overloading for user-defined types; Java doesn't (design decision to avoid complexity). C++ allows intuitive syntax; Java requires explicit method calls. C++ is more flexible; Java is simpler. Python has extensive operator overloading support through dunder (double-underscore) methods: `__add__` for `+`, `__sub__` for `-`, `__mul__` for `*`, `__eq__` for `==`, etc.

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

**Python Code Example:**
```python
# Python uses __str__ and __repr__ instead of << operator

class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __str__(self):   # Used by print() and str()
        return f"Point({self.x}, {self.y})"

    def __repr__(self):  # Used by repr() and debuggers
        return f"Point(x={self.x}, y={self.y})"

p = Point(3, 4)
print(p)       # Point(3, 4) - uses __str__
print(repr(p)) # Point(x=3, y=4) - uses __repr__
```

**Key Differences:** C++ uses operator overloading for << with streams. Java uses toString() method which is called automatically by println(). C++ approach is more operator-centric; Java's is method-centric. Both achieve readable output. Python has no stream insertion operator; use `__str__` and `__repr__` dunder methods to define string representations, and the built-in `print()` function for output.

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

**Python Code Example:**
```python
# Python doesn't have >> for input; use input() or csv/json modules

class Point:
    def __init__(self, x=0, y=0):
        self.x = x
        self.y = y

    @classmethod
    def from_input(cls):  # Equivalent to extraction
        data = input("Enter x y: ").split()
        return cls(int(data[0]), int(data[1]))

    def __str__(self):
        return f"Point({self.x}, {self.y})"

# p = Point.from_input()  # Interactive input
p = Point(3, 4)
print(p)
```

**Key Differences:** C++ uses >> operator overloading for input. Java uses explicit input methods with Scanner or similar classes. C++ syntax is more concise; Java's approach is more explicit. Both achieve object input functionality. Python has no stream extraction operator; use `input()` for user input and file methods like `read()` or `readline()` for file reading.

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

**Python Code Example:**
```python
class Vector:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __add__(self, other):   # Binary + overload
        return Vector(self.x + other.x, self.y + other.y)

    def __sub__(self, other):   # Binary - overload
        return Vector(self.x - other.x, self.y - other.y)

    def __str__(self):
        return f"({self.x}, {self.y})"

v1 = Vector(3, 4)
v2 = Vector(1, 2)
print(v1 + v2)  # (4, 6)
print(v1 - v2)  # (2, 2)
```

**Key Differences:** C++ supports binary operator overloading as member functions. Java doesn't support operator overloading; requires named methods. C++ syntax is more intuitive for mathematical operations; Java is more explicit. Python uses dunder methods for binary operator overloading: `__add__` for `+`, `__sub__` for `-`, `__mul__` for `*`, `__truediv__` for `/`; reflected versions like `__radd__` handle right-hand operand cases.

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

**Python Code Example:**
```python
class Counter:
    def __init__(self, value):
        self.value = value

    def __neg__(self):   # Unary - overload
        return Counter(-self.value)

    def __abs__(self):   # Unary abs() overload
        return Counter(abs(self.value))

    def __str__(self):
        return str(self.value)

c = Counter(-5)
print(-c)    # 5
print(abs(c)) # 5
```

**Key Differences:** C++ supports unary operator overloading (++, --, -, !, ~, etc.). Java doesn't support operator overloading; requires explicit methods. C++ distinguishes prefix/postfix with dummy int parameter; Java uses different method names. Python uses dunder methods for unary operators: `__neg__` for unary `-`, `__pos__` for unary `+`, `__invert__` for `~`, `__abs__` for `abs()`.

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

**Python Code Example:**
```python
import copy

class Matrix:
    def __init__(self, data):
        self.data = [row[:] for row in data]  # Deep copy

    def assign(self, other):  # Manual assignment (deep copy)
        self.data = [row[:] for row in other.data]
        return self

# Python's = is reference assignment; use copy for value semantics
m1 = Matrix([[1, 2], [3, 4]])
m2 = copy.deepcopy(m1)  # True copy (not just reference)
m2.data[0][0] = 99
print(m1.data[0][0])  # 1 (unchanged)
```

**Key Differences:** C++ = operator can be overloaded for deep copying. Java = always assigns references, not values. C++ requires careful implementation for classes with pointers; Java doesn't have manual memory management. For copying in Java, use clone() or copy constructors. Python uses `__iadd__`, `__isub__`, etc. for augmented assignment (`+=`, `-=`); the basic `=` assignment is handled by the interpreter and cannot be overloaded. Deep copy uses `copy.deepcopy()`.

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

**Python Code Example:**
```python
class Matrix:
    def __init__(self, rows, cols):
        self.data = [[0] * cols for _ in range(rows)]

    def __getitem__(self, index):  # Overload []
        return self.data[index]

    def __setitem__(self, index, value):  # Overload []=
        self.data[index] = value

m = Matrix(3, 3)
m[0] = [1, 2, 3]
print(m[0])  # [1, 2, 3]
print(m[0][1])  # 2
```

**Key Differences:** C++ supports [] operator overloading for custom types. Java doesn't; requires get() and set() methods. C++ syntax is more concise; Java is more explicit. Both can implement bounds checking. Python uses `__getitem__`, `__setitem__`, and `__delitem__` dunder methods to overload the `[]` subscript operator.

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

**Python Code Example:**
```python
class Temperature:
    def __init__(self, celsius):
        self.celsius = celsius

    def __eq__(self, other):  # ==
        return self.celsius == other.celsius

    def __lt__(self, other):  # <
        return self.celsius < other.celsius

    def __le__(self, other):  # <=
        return self.celsius <= other.celsius

t1 = Temperature(100)
t2 = Temperature(50)
print(t1 == t2)  # False
print(t2 < t1)   # True
```

**Key Differences:** C++ can overload relational operators directly. Java uses equals() for equality and compareTo() for ordering. C++ syntax is more operator-like; Java uses method calls. Both achieve comparison functionality effectively. Python overloads comparison operators using `__lt__`, `__le__`, `__gt__`, `__ge__`, `__eq__`, `__ne__`; logical operators (`and`, `or`, `not`) use `__bool__` and cannot be overloaded directly.

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

**Python Code Example:**
```python
# Python uses module-level functions or __radd__ for commutative ops

class Money:
    def __init__(self, amount):
        self.amount = amount

    def __add__(self, other):
        if isinstance(other, (int, float)):
            return Money(self.amount + other)
        return Money(self.amount + other.amount)

    def __radd__(self, other):  # Handles: number + Money
        return self.__add__(other)

    def __str__(self):
        return f"${self.amount}"

m = Money(50)
print(m + 10)   # $60
print(10 + m)   # $60 (uses __radd__)
```

**Key Differences:** C++ has friend operator functions for flexible operator overloading. Java doesn't support operator overloading or friends. C++ allows symmetric operations; Java requires explicit method calls. C++ is more flexible; Java is simpler. Python has no friend functions; module-level functions or static methods can provide similar operator functionality, but Python's dunder method system covers most operator overloading needs.

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

**Python Code Example:**
```python
# Python doesn't have ++ / -- operators
# Use += / -= or override for custom behavior

class Counter:
    def __init__(self, value=0):
        self.value = value

    def increment(self):  # Equivalent to prefix ++
        self.value += 1
        return self

    def decrement(self):  # Equivalent to prefix --
        self.value -= 1
        return self

    def __str__(self):
        return str(self.value)

c = Counter(5)
c.increment()
print(c)  # 6
c.decrement()
print(c)  # 5
```

**Key Differences:** C++ can overload prefix/postfix operators with dummy int parameter to distinguish them. Java doesn't support operator overloading; requires separate named methods. C++ syntax matches built-in types; Java uses method calls. Python supports `__iadd__`/`__isub__` for compound assignment; it does not have `++`/`--` increment/decrement operators. Use `+= 1` and `-= 1` instead.

---

## Memory and Pointers

### Table of Contents
63. [new Operator](#63-new-operator)
64. [delete Operator](#64-delete-operator)
65. [Reference](#65-reference)
66. [Reference Parameter](#66-reference-parameter)
67. [Object Pointer](#67-object-pointer)
68. [Pointers to Derived Classes](#68-pointers-to-derived-classes)
69. [Arrow Operator (->)](#69-arrow-operator--)
70. [Dot Operator (.)](#70-dot-operator-)

---

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

**Python Code Example:**
```python
# Python allocates memory automatically; no 'new' keyword needed

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

# Memory is automatically allocated when object is created
n1 = Node(10)  # Equivalent to 'new Node(10)' in C++/Java
n2 = Node(20)
n1.next = n2
print(n1.data, n1.next.data)  # 10 20
```

**Key Differences:** C++ new returns a pointer; Java new returns a reference. C++ requires manual delete; Java uses garbage collection. C++ new can fail and throw bad_alloc; Java throws OutOfMemoryError. Both allocate on heap. Python has no `new` keyword; objects are created by calling the class: `obj = ClassName()`. Memory allocation is handled by `__new__` (rarely overridden) and initialization by `__init__`.

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

**Python Code Example:**
```python
# Python uses garbage collection; no 'delete' needed
# Use 'del' to remove a reference

class Resource:
    def __init__(self, name):
        self.name = name
        print(f"Resource '{name}' created")

    def __del__(self):
        print(f"Resource '{self.name}' deleted")

r = Resource("file")
del r  # Removes reference; __del__ called if ref count = 0

# Context managers are preferred for deterministic cleanup
with open("example.txt", "w") as f:
    pass  # File automatically closed
```

**Key Differences:** C++ requires explicit delete to free heap memory. Java has automatic garbage collection, no delete needed. C++ delete is immediate and deterministic; Java GC is automatic but timing is unpredictable. C++ offers more control; Java is safer. Python has no `delete` operator; use `del obj` to remove a reference (object is garbage collected when reference count reaches zero). Python's GC handles memory automatically.

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

**Python Code Example:**
```python
# Python variables are references to objects

def modify(lst):
    lst.append(4)  # Modifies original (reference semantics)

my_list = [1, 2, 3]
modify(my_list)
print(my_list)  # [1, 2, 3, 4]

# To avoid modification, pass a copy
def no_modify(lst):
    lst = lst + [4]  # Creates new list

no_modify(my_list)
print(my_list)  # [1, 2, 3, 4] unchanged
```

**Key Differences:** C++ references are true aliases that cannot be null or reassigned. Java "references" are actually object pointers that can be null and reassigned. C++ references are safer for function parameters; Java references are more flexible. In Python, all variables are references (similar to Java); there are no value semantics for objects. Assignment creates a new reference to the same object, not a copy.

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

**Python Code Example:**
```python
# Python passes mutable objects by reference

class Counter:
    def __init__(self):
        self.count = 0

def increment(counter):  # Reference parameter
    counter.count += 1   # Modifies original

c = Counter()
increment(c)
increment(c)
print(c.count)  # 2
```

**Key Differences:** C++ has explicit reference parameters with &. Java passes object references by value (can modify object contents, not the reference itself). C++ can use const references to prevent modification; Java requires wrapper classes for primitive modification. Python uses pass-by-object-reference (also called pass-by-assignment); mutable objects (lists, dicts) can be modified through the parameter, while reassigning the parameter doesn't affect the caller.

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

**Python Code Example:**
```python
# Python variables act like pointers (references)

class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

head = Node(1)   # 'head' is a reference (like a pointer)
head.next = Node(2)
head.next.next = Node(3)

# Traverse linked list
current = head  # Reference assignment
while current:
    print(current.data, end=" ")
    current = current.next
# Output: 1 2 3
```

**Key Differences:** C++ uses explicit pointers with -> operator. Java uses references with . operator (no pointer syntax). C++ requires manual delete; Java has garbage collection. C++ pointers can do pointer arithmetic; Java references cannot. Python has no explicit pointers; all object variables are implicitly references. Use `id()` to get the memory address. Python's memory model is similar to Java's reference model.

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

**Python Code Example:**
```python
class Animal:
    def speak(self):
        print("Generic sound")

class Dog(Animal):
    def speak(self):
        print("Woof!")

class Cat(Animal):
    def speak(self):
        print("Meow!")

# Python references can hold any subclass instance (like base pointers)
animals: list[Animal] = [Dog(), Cat(), Dog()]
for animal in animals:
    animal.speak()  # Calls derived class method (polymorphism)
```

**Key Differences:** C++ uses pointers to base class; Java uses references. Both achieve polymorphism similarly. C++ requires virtual functions; Java methods are virtual by default. C++ needs virtual destructor for proper cleanup; Java handles this automatically. Python achieves polymorphism through duck typing and inheritance without explicit pointer syntax; a variable holding any object can call overridden methods dynamically.

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

**Python Code Example:**
```python
# Python uses dot (.) for all attribute/method access
# There is no -> operator; '.' works for both objects and "pointers"

class Person:
    def __init__(self, name):
        self.name = name

    def greet(self):
        print(f"Hello, I'm {self.name}")

p = Person("Alice")
p.greet()       # Same as -> in C++
print(p.name)   # Attribute access
```

**Key Differences:** C++ uses -> for pointer member access and . for object member access. Java only uses . for all reference access (no distinction). C++ has two operators for clarity; Java's single operator is simpler. Python has no arrow operator; member access always uses dot notation (`.`) for all objects, since Python variables are always references, never raw pointers.

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

**Python Code Example:**
```python
class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def area(self):
        return self.width * self.height

r = Rectangle(5, 3)
print(r.width)    # Dot operator for attribute
print(r.area())   # Dot operator for method call
r.width = 10      # Dot operator for assignment
```

**Key Differences:** C++ uses . for objects and references, -> for pointers. Java only uses . for all references and static access. C++ has :: for static members; Java uses . Both operators provide member access functionality. Python uses dot notation for all member access (attributes and methods): `obj.attribute`, `obj.method()`; no `->` operator exists since there are no raw pointers.

---

## Special Functions and Modifiers

### Table of Contents
71. [In-line Function](#71-in-line-function)
72. [const Member Function](#72-const-member-function)
73. [mutable Keyword](#73-mutable-keyword)
74. [Static Member Variable](#74-static-member-variable)
75. [Static Member Function](#75-static-member-function)
76. [super Keyword](#76-super-keyword)

---

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

**Python Code Example:**
```python
# Python doesn't have inline functions
# All functions are implicitly inlined by the interpreter as needed
# Use lambda for small anonymous functions

square = lambda x: x * x  # Lambda (similar concept to inline)

# Short functions are generally inlined by CPython
def cube(x):  # Regular function (interpreted, not compiled)
    return x ** 3

print(square(5))  # 25
print(cube(3))    # 27
```

**Key Differences:** C++ has explicit `inline` keyword (compiler hint). Java JVM automatically inlines methods at runtime (JIT optimization). C++ inlining is compile-time; Java's is runtime. Java's approach is more automated; C++ gives explicit control. Python has no `inline` keyword; the interpreter (CPython) does not perform inlining. Small functions can be written as `lambda` expressions or simple `def` blocks; performance optimization is handled by the runtime.

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

**Python Code Example:**
```python
# Python doesn't have const methods
# Use @property and avoid modifying state in "getter" methods

class Circle:
    def __init__(self, radius):
        self.__radius = radius

    @property
    def radius(self):  # Read-only property (const-like)
        return self.__radius

    def area(self):  # Convention: methods that don't modify state
        return 3.14 * self.__radius ** 2

c = Circle(5)
print(c.area())    # 78.5
print(c.radius)    # 5
# c.radius = 10    # AttributeError (no setter)
```

**Key Differences:** C++ has const member functions for const-correctness. Java doesn't have this feature; relies on documentation and conventions. C++ enforces immutability at compile-time; Java uses final for variables but not for methods preventing modification. Python has no `const` member functions; use `@property` without a setter to expose read-only attributes, and document read-only intent in docstrings. Frozen dataclasses (`@dataclass(frozen=True)`) provide immutable objects.

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

**Python Code Example:**
```python
# Python doesn't have 'mutable' keyword
# All instance attributes are mutable by default
# Use @property with setter for controlled mutability

class Config:
    def __init__(self):
        self._debug = False      # Mutable
        self._version = "1.0.0"  # Intended to be read-only

    @property
    def debug(self):
        return self._debug

    @debug.setter
    def debug(self, value):  # Allowed to change
        self._debug = value

c = Config()
c.debug = True  # Can modify
print(c.debug)  # True
```

**Key Differences:** C++ has mutable keyword for selective mutability in const contexts. Java doesn't have const member functions, so mutable isn't needed. C++ provides finer control over constness; Java has simpler model. Python has no `mutable` keyword; all instance attributes are mutable by default. To make an attribute effectively read-only, use `@property` without a setter or `__slots__`.

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

**Python Code Example:**
```python
class Employee:
    company = "TechCorp"       # Class variable (static)
    total_employees = 0        # Class variable (static)

    def __init__(self, name):
        self.name = name
        Employee.total_employees += 1

print(Employee.company)        # TechCorp
e1 = Employee("Alice")
e2 = Employee("Bob")
print(Employee.total_employees)  # 2
```

**Key Differences:** C++ requires separate definition outside class (except inline static). Java allows initialization at declaration. Both access via ClassName::member (C++) or ClassName.member (Java). Both share single copy across all instances. Python class variables (defined at class level, outside `__init__`) are shared across all instances, equivalent to static member variables. Access via `ClassName.var` or `self.__class__.var`.

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

**Python Code Example:**
```python
class MathUtils:
    PI = 3.14159

    @staticmethod
    def square(x):  # Static method
        return x * x

    @classmethod
    def circle_area(cls, r):  # Class method
        return cls.PI * r * r

print(MathUtils.square(4))        # 16
print(MathUtils.circle_area(5))   # 78.53975
```

**Key Differences:** Both implement static member functions identically. C++ uses :: for access; Java uses . Both can't access instance members or use this. Both are called with class name. Functionality is essentially the same. Python uses the `@staticmethod` decorator for static methods (no `self` or `cls` parameter); `@classmethod` receives `cls` as the first parameter and can access class-level state.

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

**Python Code Example:**
```python
class Animal:
    def __init__(self, name):
        self.name = name

    def speak(self):
        print(f"{self.name} makes a sound")

class Dog(Animal):
    def __init__(self, name, breed):
        super().__init__(name)  # Call parent constructor
        self.breed = breed

    def speak(self):
        super().speak()         # Call parent method
        print(f"{self.name} barks!")

dog = Dog("Rex", "Labrador")
dog.speak()
```

**Key Differences:** Java has super keyword for parent class access. C++ uses BaseClassName:: syntax. Java super() must be first in constructor; C++ uses initializer list. Java's super is simpler; C++ requires class name. Python uses `super()` (no arguments needed in Python 3) to call parent class methods; it works with MRO to correctly resolve method calls in multiple inheritance hierarchies.

---

## RTTI and Casting

### Table of Contents
77. [Run-Time Type Identification (RTTI)](#77-run-time-type-identification-rtti)
78. [typeid Operator](#78-typeid-operator)
79. [dynamic_cast](#79-dynamic_cast)
80. [const_cast](#80-const_cast)
81. [static_cast](#81-static_cast)
82. [reinterpret_cast](#82-reinterpret_cast)
83. [Upcasting (Implicit)](#83-upcasting-implicit)
84. [Downcasting (Explicit)](#84-downcasting-explicit)
85. [instanceof Operator](#85-instanceof-operator)
86. [type_info Object](#86-type_info-object)

---

### 77. Run-Time Type Identification (RTTI)

**Definition:** A mechanism that allows the type of an object to be determined during program execution.

**Explanation:** RTTI provides runtime information about objects, enabling dynamic type checking and safe downcasting. It's useful when working with polymorphic class hierarchies where the exact type isn't known at compile time.

**C++ Code Example:**
```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

class Animal { virtual void speak() {} };
class Dog : public Animal {};

int main() {
    Animal* a = new Dog();
    cout << typeid(*a).name() << endl; // Outputs: Dog
    return 0;
}
```

**Java Code Example:**
```java
class Animal {}
class Dog extends Animal {}

public class Main {
    public static void main(String[] args) {
        Animal a = new Dog();
        System.out.println(a.getClass().getName()); // Outputs: Dog
    }
}
```

**Python Code Example:**
```python
class Animal:
    pass

class Dog(Animal):
    pass

class Cat(Animal):
    pass

dog = Dog()
cat = Cat()

print(type(dog))          # <class '__main__.Dog'>
print(type(dog).__name__) # Dog
print(isinstance(dog, Animal))  # True (RTTI check)
print(isinstance(dog, Cat))     # False
```

**Key Differences:** C++ requires virtual functions in the base class for RTTI to work with pointers/references. Java has built-in RTTI for all objects through the `getClass()` method and `instanceof` operator. Python provides built-in RTTI through `type()`, `isinstance()`, and `issubclass()`; every object carries full type information at runtime, making RTTI always available.

---

### 78. typeid Operator

**Definition:** A C++ operator that returns type information about an expression.

**Explanation:** The `typeid` operator returns a reference to a `type_info` object representing the type of the expression. It works at runtime for polymorphic types and at compile time for non-polymorphic types.

**C++ Code Example:**
```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int x = 5;
    double y = 3.14;
    cout << typeid(x).name() << endl; // Outputs: i (int)
    cout << typeid(y).name() << endl; // Outputs: d (double)
    return 0;
}
```

**Java Code Example:**
```java
// Java uses getClass() method instead
public class Main {
    public static void main(String[] args) {
        Integer x = 5;
        Double y = 3.14;
        System.out.println(x.getClass().getName()); // Outputs: java.lang.Integer
        System.out.println(y.getClass().getName()); // Outputs: java.lang.Double
    }
}
```

**Python Code Example:**
```python
class Shape:
    pass

class Circle(Shape):
    pass

c = Circle()
s = Shape()

print(type(c))           # <class '__main__.Circle'>
print(type(c).__name__)  # Circle
print(type(c) is Circle) # True
print(type(c) is Shape)  # False (exact type check)
```

**Key Differences:** C++ has the `typeid` operator, while Java uses the `getClass()` method. C++ returns a `type_info` object, while Java returns a `Class` object. Python uses `type(obj)` to get the exact type of an object and `isinstance(obj, Type)` for type checking; `obj.__class__.__name__` gives the class name as a string.

---

### 79. dynamic_cast

**Definition:** A C++ casting operator that performs safe downcasting with runtime type checking.

**Explanation:** `dynamic_cast` is used to safely convert pointers or references along an inheritance hierarchy. It returns `nullptr` (for pointers) or throws `bad_cast` (for references) if the cast is invalid.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

class Animal { virtual void speak() {} };
class Dog : public Animal { void bark() { cout << "Woof!" << endl; } };

int main() {
    Animal* a = new Dog();
    Dog* d = dynamic_cast<Dog*>(a);
    if (d) d->bark(); // Safe cast, outputs: Woof!
    return 0;
}
```

**Java Code Example:**
```java
// Java uses instanceof and explicit cast
class Animal {}
class Dog extends Animal { 
    void bark() { System.out.println("Woof!"); }
}

public class Main {
    public static void main(String[] args) {
        Animal a = new Dog();
        if (a instanceof Dog) {
            Dog d = (Dog) a; // Safe cast
            d.bark(); // Outputs: Woof!
        }
    }
}
```

**Python Code Example:**
```python
class Animal:
    def speak(self):
        pass

class Dog(Animal):
    def bark(self):
        print("Woof!")

def process(animal):
    if isinstance(animal, Dog):  # Equivalent to dynamic_cast
        dog = animal  # Safe downcast
        dog.bark()
    else:
        print("Not a Dog")

process(Dog())      # Woof!
process(Animal())   # Not a Dog
```

**Key Differences:** C++ has `dynamic_cast` operator, while Java uses `instanceof` check followed by explicit casting. C++ returns `nullptr` on failure for pointers; Java throws `ClassCastException` on invalid casts. Python has no explicit casting; use `isinstance()` to check type before accessing derived-class-specific attributes. Duck typing reduces the need for explicit downcasting.

---

### 80. const_cast

**Definition:** A C++ casting operator that adds or removes const or volatile qualifiers.

**Explanation:** `const_cast` is used to modify the const-ness of a variable. It's the only C++ cast that can remove constness, but modifying a truly const object leads to undefined behavior.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

void modify(const int* p) {
    int* modifiable = const_cast<int*>(p);
    *modifiable = 20;
}

int main() {
    int x = 10;
    modify(&x);
    cout << x << endl; // Outputs: 20
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't have const_cast equivalent
// Java uses 'final' for constants, which cannot be cast away
public class Main {
    public static void main(String[] args) {
        final int x = 10;
        // x = 20; // Compilation error - cannot modify final variable
        System.out.println(x);
    }
}
```

**Python Code Example:**
```python
# Python doesn't have const_cast; objects are mutable by default
# Use object.__dict__ to bypass property restrictions if needed

class Config:
    def __init__(self, value):
        self._value = value

    @property
    def value(self):
        return self._value

conf = Config(42)
# "cast away const" - directly modify internal state
conf.__dict__['_value'] = 100  # Bypass property (use with caution)
print(conf.value)  # 100
```

**Key Differences:** C++ has `const_cast` to modify constness. Java has no equivalent; `final` variables cannot have their immutability removed. Python has no `const_cast`; there is no const qualifier to remove. Use `@property` without setter for read-only attributes; immutability is enforced at the design level.

---

### 81. static_cast

**Definition:** A C++ casting operator that performs compile-time type conversions.

**Explanation:** `static_cast` performs explicit type conversions that are checked at compile time. It's used for well-defined conversions like numeric conversions, upcasting, and downcasting (without runtime checks).

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    double d = 3.14;
    int i = static_cast<int>(d); // Convert double to int
    cout << i << endl; // Outputs: 3
    return 0;
}
```

**Java Code Example:**
```java
// Java uses explicit cast syntax
public class Main {
    public static void main(String[] args) {
        double d = 3.14;
        int i = (int) d; // Convert double to int
        System.out.println(i); // Outputs: 3
    }
}
```

**Python Code Example:**
```python
# Python uses built-in conversion functions for type casting

x = 3.14
i = int(x)        # float to int (like static_cast<int>)
f = float(42)     # int to float
s = str(42)       # int to string

class Celsius:
    def __init__(self, temp):
        self.temp = temp

    def to_fahrenheit(self):
        return self.temp * 9/5 + 32

c = Celsius(100)
print(int(c.to_fahrenheit()))  # 212
```

**Key Differences:** C++ uses `static_cast<Type>(value)` syntax, while Java uses `(Type) value` syntax. Both perform compile-time conversions without runtime overhead. Python uses built-in conversion functions for type casting: `int()`, `float()`, `str()`, `bool()`; there is no static_cast keyword — all casting is explicit via constructor-like calls.

---

### 82. reinterpret_cast

**Definition:** A C++ casting operator that performs low-level reinterpretation of bit patterns.

**Explanation:** `reinterpret_cast` converts any pointer type to any other pointer type, or integers to pointers and vice versa. It's dangerous and implementation-dependent, used mainly for low-level programming.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    int x = 65;
    char* c = reinterpret_cast<char*>(&x);
    cout << "First byte: " << (int)c[0] << endl;
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't have reinterpret_cast equivalent
// Java doesn't allow arbitrary pointer manipulation
// Closest is using ByteBuffer for bit manipulation
import java.nio.ByteBuffer;

public class Main {
    public static void main(String[] args) {
        int x = 65;
        ByteBuffer buffer = ByteBuffer.allocate(4);
        buffer.putInt(x);
        byte b = buffer.get(0);
        System.out.println("First byte: " + (int)b);
    }
}
```

**Python Code Example:**
```python
import struct

# Python uses struct or ctypes for low-level type reinterpretation

# Reinterpret float bytes as integer
f_val = 3.14
bytes_val = struct.pack('f', f_val)
i_val = struct.unpack('I', bytes_val)[0]
print(hex(i_val))  # Raw bit representation of 3.14

# This is dangerous (equivalent to reinterpret_cast)
```

**Key Differences:** C++ allows `reinterpret_cast` for low-level bit manipulation. Java doesn't allow arbitrary pointer casting; uses `ByteBuffer` or similar classes for byte-level operations. Python has no `reinterpret_cast`; low-level memory reinterpretation can be done with the `struct` or `ctypes` modules, but is rarely needed due to Python's managed memory model.

---

### 83. Upcasting (Implicit)

**Definition:** Converting a derived class reference/pointer to a base class reference/pointer.

**Explanation:** Upcasting is the process of treating a derived class object as a base class object. It's always safe and happens implicitly because a derived object "is-a" base object.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

class Animal { public: virtual void speak() { cout << "Animal sound" << endl; } };
class Dog : public Animal { public: void speak() { cout << "Woof!" << endl; } };

int main() {
    Dog d;
    Animal* a = &d; // Implicit upcast
    a->speak(); // Outputs: Woof! (polymorphism)
    return 0;
}
```

**Java Code Example:**
```java
class Animal { void speak() { System.out.println("Animal sound"); } }
class Dog extends Animal { void speak() { System.out.println("Woof!"); } }

public class Main {
    public static void main(String[] args) {
        Dog d = new Dog();
        Animal a = d; // Implicit upcast
        a.speak(); // Outputs: Woof! (polymorphism)
    }
}
```

**Python Code Example:**
```python
class Animal:
    def speak(self):
        print("Generic sound")

class Dog(Animal):
    def speak(self):
        print("Woof!")

dog = Dog()
animal: Animal = dog  # Implicit upcast (Python is duck-typed)
animal.speak()        # Still calls Dog.speak() - dynamic dispatch

# Type annotation doesn't affect runtime behavior
print(type(animal))   # <class '__main__.Dog'>
```

**Key Differences:** Both languages perform upcasting implicitly and safely. The mechanism is essentially the same in both languages. Python upcasting is implicit and automatic; assigning a derived class instance to a base class variable or parameter works naturally due to Python's duck typing and inheritance model.

---

### 84. Downcasting (Explicit)

**Definition:** Converting a base class reference/pointer to a derived class reference/pointer.

**Explanation:** Downcasting attempts to treat a base class reference as a more specific derived class. It requires explicit casting and can fail at runtime if the actual object is not of the target type.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

class Animal { virtual void speak() {} };
class Dog : public Animal { public: void bark() { cout << "Woof!" << endl; } };

int main() {
    Animal* a = new Dog();
    Dog* d = dynamic_cast<Dog*>(a); // Explicit downcast
    if (d) d->bark();
    return 0;
}
```

**Java Code Example:**
```java
class Animal {}
class Dog extends Animal { void bark() { System.out.println("Woof!"); } }

public class Main {
    public static void main(String[] args) {
        Animal a = new Dog();
        if (a instanceof Dog) {
            Dog d = (Dog) a; // Explicit downcast
            d.bark();
        }
    }
}
```

**Python Code Example:**
```python
class Animal:
    def speak(self):
        print("Sound")

class Dog(Animal):
    def fetch(self):
        print("Fetching!")

def process(animal: Animal):
    if isinstance(animal, Dog):  # Safe downcast check
        dog: Dog = animal         # Explicit downcast
        dog.fetch()               # Dog-specific method
    else:
        animal.speak()

process(Dog())    # Fetching!
process(Animal()) # Sound
```

**Key Differences:** C++ uses `dynamic_cast` for safe downcasting. Java uses `instanceof` check with explicit cast. Both require runtime verification. Python downcasting is implicit; use `isinstance()` to verify the type before accessing subclass-specific attributes. No explicit cast syntax is needed.

---

### 85. instanceof Operator

**Definition:** A Java operator that tests whether an object is an instance of a specific class or interface.

**Explanation:** The `instanceof` operator returns `true` if the object is an instance of the specified type or any of its subclasses. It's used for safe type checking before downcasting.

**C++ Code Example:**
```cpp
// C++ doesn't have instanceof; uses dynamic_cast instead
#include <iostream>
using namespace std;

class Animal { virtual ~Animal() {} };
class Dog : public Animal {};

int main() {
    Animal* a = new Dog();
    Dog* d = dynamic_cast<Dog*>(a);
    if (d != nullptr) {
        cout << "a is a Dog" << endl;
    }
    return 0;
}
```

**Java Code Example:**
```java
class Animal {}
class Dog extends Animal {}

public class Main {
    public static void main(String[] args) {
        Animal a = new Dog();
        if (a instanceof Dog) {
            System.out.println("a is a Dog");
        }
    }
}
```

**Python Code Example:**
```python
class Shape:
    pass

class Circle(Shape):
    pass

class Rectangle(Shape):
    pass

c = Circle()
r = Rectangle()

print(isinstance(c, Circle))    # True  (like instanceof)
print(isinstance(c, Shape))     # True  (parent class check)
print(isinstance(c, Rectangle)) # False
print(issubclass(Circle, Shape))# True  (class hierarchy check)
```

**Key Differences:** Java has the `instanceof` operator. C++ uses `dynamic_cast` and checks for `nullptr` (pointers) or catches `bad_cast` (references). Python uses `isinstance(obj, ClassName)` for type checking, equivalent to Java's `instanceof`; `type(obj) is ClassName` gives exact type without considering inheritance.

---

### 86. type_info Object

**Definition:** A C++ class that holds implementation-specific information about a type.

**Explanation:** The `type_info` class is returned by the `typeid` operator. It provides methods like `name()` to get type name and operator `==` to compare types.

**C++ Code Example:**
```cpp
#include <iostream>
#include <typeinfo>
using namespace std;

int main() {
    int x = 5;
    const type_info& ti = typeid(x);
    cout << ti.name() << endl; // Type name (implementation-specific)
    if (typeid(x) == typeid(int)) {
        cout << "x is an int" << endl;
    }
    return 0;
}
```

**Java Code Example:**
```java
// Java uses Class object instead
public class Main {
    public static void main(String[] args) {
        Integer x = 5;
        Class<?> cls = x.getClass();
        System.out.println(cls.getName()); // java.lang.Integer
        if (cls == Integer.class) {
            System.out.println("x is an Integer");
        }
    }
}
```

**Python Code Example:**
```python
class Vehicle:
    pass

class Car(Vehicle):
    pass

car = Car()

# Python's type() returns type object (like type_info)
t = type(car)
print(t.__name__)     # Car
print(t.__bases__)    # (<class '__main__.Vehicle'>,)
print(t.__mro__)      # MRO (Method Resolution Order)

# Compare types
print(type(car) == Car)      # True
print(type(car) == Vehicle)  # False
```

**Key Differences:** C++ uses `type_info` class. Java uses `Class` object with more extensive reflection capabilities. Java's `Class` provides more runtime information. Python's equivalent is the `type` object returned by `type(obj)`; `obj.__class__` gives the class, and the `inspect` module provides detailed type information.

---

## Templates and Generics

### Table of Contents
87. [Generic Function (Template)](#87-generic-function-template)
88. [Generic Class (Template Class)](#88-generic-class-template-class)
89. [Namespace](#89-namespace)
90. [using Statement](#90-using-statement)
91. [Formal Generic Type](#91-formal-generic-type)
92. [Wildcard Generic Type](#92-wildcard-generic-type)
93. [Template Instantiation](#93-template-instantiation)

---

### 87. Generic Function (Template)

**Definition:** A function template that can work with any data type without sacrificing type safety.

**Explanation:** Templates (C++) and Generics (Java) allow creation of functions that can operate on different types. They enable code reuse and type-safe generic programming.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

template <typename T>
T maximum(T a, T b) {
    return (a > b) ? a : b;
}

int main() {
    cout << maximum(5, 10) << endl;      // Outputs: 10
    cout << maximum(3.14, 2.71) << endl; // Outputs: 3.14
    return 0;
}
```

**Java Code Example:**
```java
public class Main {
    public static <T extends Comparable<T>> T maximum(T a, T b) {
        return (a.compareTo(b) > 0) ? a : b;
    }
    
    public static void main(String[] args) {
        System.out.println(maximum(5, 10));      // Outputs: 10
        System.out.println(maximum(3.14, 2.71)); // Outputs: 3.14
    }
}
```

**Python Code Example:**
```python
from typing import TypeVar

T = TypeVar('T')

def find_max(a: T, b: T) -> T:  # Generic function
    return a if a > b else b

print(find_max(3, 7))           # 7 (int)
print(find_max(3.14, 2.71))     # 3.14 (float)
print(find_max("apple", "banana"))  # banana (str)
```

**Key Differences:** C++ templates are compiled for each type used (code generation at compile time). Java generics use type erasure (single compiled version with runtime type checking). C++ templates are more powerful but increase code size. Python functions are inherently generic due to duck typing; `functools.singledispatch` enables type-based dispatch; `TypeVar` from `typing` module adds optional type hints for generic functions.

---

### 12. Generic Function (Template)

**Definition:** A function that can operate on different data types specified as parameters.

**Explanation:** Generic functions use type parameters to work with any data type, providing type safety while avoiding code duplication.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

template <typename T>
void swap(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 1, y = 2;
    swap(x, y);
    cout << x << " " << y << endl; // Outputs: 2 1
    return 0;
}
```

**Java Code Example:**
```java
public class Main {
    public static <T> void swap(T[] arr, int i, int j) {
        T temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    
    public static void main(String[] args) {
        Integer[] arr = {1, 2};
        swap(arr, 0, 1);
        System.out.println(arr[0] + " " + arr[1]); // Outputs: 2 1
    }
}
```

**Python Code Example:**
```python
from typing import TypeVar, List

T = TypeVar('T')

def swap(arr: List[T], i: int, j: int) -> None:  # Generic function
    arr[i], arr[j] = arr[j], arr[i]

# Works with any type
int_arr = [1, 2, 3]
swap(int_arr, 0, 1)
print(int_arr)  # [2, 1, 3]

str_arr = ["hello", "world"]
swap(str_arr, 0, 1)
print(str_arr)  # ['world', 'hello']
```

**Key Differences:** C++ can use template functions with any type directly. Java generic methods work with reference types (objects) and require workarounds for primitives or array parameters. Python functions are inherently generic due to duck typing; TypeVar adds optional static type hints.

---

### 88. Generic Class (Template Class)

**Definition:** A class that can work with any data type specified as a type parameter.

**Explanation:** Generic classes encapsulate operations that can work with different types while maintaining type safety. They're instantiated with specific types.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

template <typename T>
class Box {
    T value;
public:
    Box(T v) : value(v) {}
    T getValue() { return value; }
};

int main() {
    Box<int> intBox(42);
    Box<string> strBox("Hello");
    cout << intBox.getValue() << endl;
    cout << strBox.getValue() << endl;
    return 0;
}
```

**Java Code Example:**
```java
class Box<T> {
    private T value;
    
    public Box(T v) {
        value = v;
    }
    
    public T getValue() {
        return value;
    }
}

public class Main {
    public static void main(String[] args) {
        Box<Integer> intBox = new Box<>(42);
        Box<String> strBox = new Box<>("Hello");
        System.out.println(intBox.getValue());
        System.out.println(strBox.getValue());
    }
}
```

**Python Code Example:**
```python
from typing import Generic, TypeVar

T = TypeVar('T')

class Stack(Generic[T]):  # Generic class
    def __init__(self):
        self._items: list[T] = []

    def push(self, item: T) -> None:
        self._items.append(item)

    def pop(self) -> T:
        return self._items.pop()

    def is_empty(self) -> bool:
        return len(self._items) == 0

s: Stack[int] = Stack()
s.push(1)
s.push(2)
print(s.pop())  # 2
```

**Key Differences:** C++ template classes generate separate code for each type. Java generic classes use type erasure (runtime type information is lost). C++ allows non-type template parameters (e.g., integers). Python classes are inherently generic due to duck typing; use `TypeVar` and `Generic` from the `typing` module to create type-annotated generic classes (e.g., `class Stack(Generic[T]):`).

---

### 89. Namespace

**Definition:** A declarative region that provides scope to identifiers to prevent name conflicts.

**Explanation:** Namespaces organize code into logical groups and prevent naming collisions between different parts of code or libraries.

**C++ Code Example:**
```cpp
#include <iostream>

namespace Math {
    int add(int a, int b) {
        return a + b;
    }
}

int main() {
    std::cout << Math::add(5, 3) << std::endl; // Outputs: 8
    return 0;
}
```

**Java Code Example:**
```java
// Java uses packages instead of namespaces
package com.example.math; // This would be in a separate file

class MathUtils {
    public static int add(int a, int b) {
        return a + b;
    }
}

// In main file:
// import com.example.math.MathUtils;
// MathUtils.add(5, 3);
```

**Python Code Example:**
```python
# Python uses modules as namespaces

# geometry.py (module = namespace)
# def area(radius): return 3.14 * radius ** 2

import math  # math is a namespace

print(math.pi)           # 3.14159...
print(math.sqrt(16))     # 4.0

# Create your own namespace with a class or module
class GeometryUtils:
    PI = 3.14159

    @staticmethod
    def circle_area(r):
        return GeometryUtils.PI * r * r

print(GeometryUtils.circle_area(5))
```

**Key Differences:** C++ uses `namespace` keyword. Java uses `package` system with directory structure. C++ namespaces can be nested and reopened; Java packages correspond to directory hierarchy. Python uses modules as its primary namespace mechanism; `import module` and `from module import name` provide namespace control. Python also has local, enclosing, global, and built-in scopes (LEGB rule).

---

### 90. using Statement

**Definition:** A C++ statement that introduces names from a namespace into the current scope.

**Explanation:** The `using` statement allows access to namespace members without fully qualifying them, reducing verbosity. It can import entire namespaces or specific members.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

int main() {
    cout << "Hello" << endl; // No need for std::cout
    return 0;
}
```

**Java Code Example:**
```java
// Java uses import statements
import java.util.ArrayList;
import java.util.*; // Import all from package

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>(); // No need for full path
    }
}
```

**Python Code Example:**
```python
# Python uses 'import' and 'from ... import ...' (like 'using namespace')

from math import sqrt, pi  # Like 'using namespace math'

print(sqrt(16))  # 4.0 (no need for math.sqrt)
print(pi)        # 3.14159...

# Alias imports
import numpy as np  # Create alias (like 'using np = numpy')
# np.array([1, 2, 3])
```

**Key Differences:** C++ `using namespace` can be used anywhere in code. Java `import` statements must be at the top of file. C++ can import entire namespaces into local scopes; Java imports are file-level only. Python uses `from module import name` or `import module as alias` for namespace imports; `with` statement is Python's equivalent for resource management (context managers).

---

### 91. Formal Generic Type

**Definition:** The type parameter declared in a generic class or method definition.

**Explanation:** Formal generic types are placeholders (like `T`, `E`, `K`, `V`) used in generic definitions. They're replaced with actual types when the generic is instantiated.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

// T is the formal generic type
template <typename T>
class Container {
    T element;
public:
    Container(T e) : element(e) {}
    T get() { return element; }
};

int main() {
    Container<int> c(42); // int is the actual type
    cout << c.get() << endl;
    return 0;
}
```

**Java Code Example:**
```java
// T is the formal generic type
class Container<T> {
    private T element;
    
    public Container(T e) {
        element = e;
    }
    
    public T get() {
        return element;
    }
}

public class Main {
    public static void main(String[] args) {
        Container<Integer> c = new Container<>(42); // Integer is the actual type
        System.out.println(c.get());
    }
}
```

**Python Code Example:**
```python
from typing import TypeVar, Generic

T = TypeVar('T')  # Formal generic type parameter

class Box(Generic[T]):
    def __init__(self, item: T):
        self.item = item

    def get(self) -> T:
        return self.item

int_box = Box[int](42)
str_box = Box[str]("Hello")
print(int_box.get())  # 42
print(str_box.get())  # Hello
```

**Key Differences:** Both languages use similar syntax with angle brackets. C++ uses `typename` or `class` keyword before the parameter; Java uses just the identifier. Terminology is the same in both. Python uses `TypeVar` from the `typing` module to define formal generic type parameters (e.g., `T = TypeVar('T')`); at runtime, Python classes and functions work with any type due to duck typing.

---

### 92. Wildcard Generic Type

**Definition:** A special generic type parameter in Java that represents an unknown type.

**Explanation:** Wildcards (`?`) in Java allow flexibility in generic type parameters. They can be unbounded (`?`), upper-bounded (`? extends Type`), or lower-bounded (`? super Type`).

**C++ Code Example:**
```cpp
// C++ doesn't have wildcard types like Java
// Uses template specialization or function overloading
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(const vector<T>& v) {
    for (const auto& elem : v) {
        cout << elem << " ";
    }
    cout << endl;
}

int main() {
    vector<int> v = {1, 2, 3};
    printVector(v); // Works with any type
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    // Wildcard with upper bound
    public static void printList(List<? extends Number> list) {
        for (Number n : list) {
            System.out.print(n + " ");
        }
        System.out.println();
    }
    
    public static void main(String[] args) {
        List<Integer> intList = Arrays.asList(1, 2, 3);
        List<Double> doubleList = Arrays.asList(1.1, 2.2, 3.3);
        printList(intList);
        printList(doubleList);
    }
}
```

**Python Code Example:**
```python
from typing import Any, List, Union

def print_list(items: List[Any]) -> None:  # Any is like wildcard (?)
    for item in items:
        print(item)

def process(value: Union[int, str, float]) -> str:  # Bounded wildcard
    return str(value)

print_list([1, "hello", 3.14])
print(process(42))
print(process("world"))
```

**Key Differences:** Java has wildcard types (`?`, `? extends`, `? super`) for flexible generic parameters. C++ doesn't have wildcards; uses template parameters that can accept any type or constrained with concepts (C++20). Python uses `Any` from `typing` for unconstrained types, and `Union[A, B]` or `A | B` (Python 3.10+) for bounded alternatives; covariance/contravariance is specified with `TypeVar(covariant=True)` or `contravariant=True`.

---

### 93. Template Instantiation

**Definition:** The process of generating concrete code from a template by substituting type parameters with actual types.

**Explanation:** When a template is used with a specific type, the compiler generates (instantiates) the corresponding code. Each unique type creates a separate instantiation.

**C++ Code Example:**
```cpp
#include <iostream>
using namespace std;

template <typename T>
class Array {
    T* data;
    int size;
public:
    Array(int s) : size(s) { data = new T[s]; }
    ~Array() { delete[] data; }
};

int main() {
    Array<int> intArr(10);    // Instantiation for int
    Array<double> doubleArr(5); // Instantiation for double
    return 0;
}
```

**Java Code Example:**
```java
// Java uses type erasure, not true instantiation
class Array<T> {
    private Object[] data;
    private int size;
    
    public Array(int s) {
        size = s;
        data = new Object[s];
    }
}

public class Main {
    public static void main(String[] args) {
        Array<Integer> intArr = new Array<>(10);
        Array<Double> doubleArr = new Array<>(5);
        // Only one bytecode version exists at runtime
    }
}
```

**Python Code Example:**
```python
from typing import TypeVar, Generic

T = TypeVar('T')

class Pair(Generic[T]):
    def __init__(self, first: T, second: T):
        self.first = first
        self.second = second

    def swap(self) -> 'Pair[T]':
        return Pair(self.second, self.first)

# Template instantiation at usage time
int_pair = Pair[int](1, 2)       # Instantiation with int
str_pair = Pair[str]("a", "b")   # Instantiation with str
swapped = int_pair.swap()
print(swapped.first, swapped.second)  # 2 1
```

**Key Differences:** C++ creates separate compiled code for each type (template instantiation). Java creates one version and uses type erasure (type information removed at runtime, only one compiled version exists). Python has no template instantiation step; generic classes using `TypeVar` and `Generic` are instantiated like regular classes at runtime, with type checking done by static analyzers like `mypy`.

---

## Standard Template Library (STL)

### Table of Contents
94. [STL](#94-stl)
95. [Containers](#95-containers)
96. [Algorithms](#96-algorithms)
97. [Iterators](#97-iterators)
98. [vector](#98-vector)
99. [list](#99-list)
100. [queue](#100-queue)
101. [stack](#101-stack)
102. [map](#102-map)
103. [Random-access Iterator](#103-random-access-iterator)
104. [Bidirectional Iterator](#104-bidirectional-iterator)
105. [Forward Iterator](#105-forward-iterator)
106. [Input Iterator](#106-input-iterator)
107. [Output Iterator](#107-output-iterator)
108. [size_type](#108-size_type)
109. [iterator type](#109-iterator-type)
110. [value_type](#110-value_type)

---

### 94. STL

**Definition:** The Standard Template Library - A C++ library providing generic container classes, algorithms, and iterators.

**Explanation:** STL is a powerful collection of template-based data structures and algorithms that provides efficient, reusable components for common programming tasks.

**C++ Code Example:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9};
    sort(v.begin(), v.end());
    for (int x : v) {
        cout << x << " "; // Outputs: 1 2 5 8 9
    }
    return 0;
}
```

**Java Code Example:**
```java
// Java has Collections Framework (similar concept)
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(5, 2, 8, 1, 9));
        Collections.sort(list);
        for (int x : list) {
            System.out.print(x + " "); // Outputs: 1 2 5 8 9
        }
    }
}
```

**Python Code Example:**
```python
# Python's standard library provides equivalent data structures

from collections import deque, OrderedDict
import heapq

# Python's built-in equivalents to C++ STL
my_list = [1, 2, 3]          # vector equivalent
my_deque = deque([1, 2, 3])  # deque equivalent
my_dict = {"a": 1, "b": 2}   # map equivalent
my_set = {1, 2, 3}           # set equivalent

print(my_list)
print(my_deque)
```

**Key Differences:** C++ has STL (part of C++ Standard Library). Java has Collections Framework. STL uses templates; Java uses generics. STL has more emphasis on iterators; Java uses interfaces like `Iterable`. Python's standard library includes rich built-in data structures (list, dict, set, tuple) and the `collections` module (deque, OrderedDict, Counter); the `heapq`, `bisect`, and `itertools` modules provide algorithmic utilities.

---

### 95. Containers

**Definition:** Template classes in STL that store collections of objects.

**Explanation:** STL containers are data structures like vectors, lists, sets, and maps that manage collections of elements with different characteristics and performance trade-offs.

**C++ Code Example:**
```cpp
#include <iostream>
#include <vector>
#include <list>
#include <set>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3};      // Dynamic array
    list<int> l = {4, 5, 6};        // Doubly-linked list
    set<int> s = {7, 8, 9};         // Ordered set
    
    cout << v[0] << " " << l.front() << " " << *s.begin() << endl;
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(1, 2, 3)); // Dynamic array
        LinkedList<Integer> linkedList = new LinkedList<>(Arrays.asList(4, 5, 6));
        Set<Integer> set = new TreeSet<>(Arrays.asList(7, 8, 9)); // Ordered set
        
        System.out.println(list.get(0) + " " + linkedList.getFirst() + " " + set.iterator().next());
    }
}
```

**Python Code Example:**
```python
# Python container equivalents

my_list = [1, 2, 3, 4]       # list (vector)
my_tuple = (1, 2, 3)         # tuple (array)
my_dict = {"key": "value"}   # dict (map)
my_set = {1, 2, 3}           # set

# Check containment
print(2 in my_list)   # True
print(3 in my_set)    # True
print("key" in my_dict)  # True
```

**Key Differences:** C++ STL containers are template-based. Java Collections are interface-based with implementations. C++ has more variety (e.g., `deque`, `multiset`). Both provide similar functionality with different syntax. Python's built-in containers include `list` (dynamic array), `dict` (hash map), `set` (hash set), `tuple` (immutable sequence); the `collections` module adds `deque`, `OrderedDict`, `Counter`, `defaultdict`.

---

### 96. Algorithms

**Definition:** Template functions in STL that perform operations on containers.

**Explanation:** STL algorithms are generic functions for searching, sorting, modifying, and manipulating data in containers. They work with iterators to be container-independent.

**C++ Code Example:**
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> v = {5, 2, 8, 1, 9};
    
    sort(v.begin(), v.end());
    auto it = find(v.begin(), v.end(), 8);
    
    if (it != v.end()) {
        cout << "Found: " << *it << endl;
    }
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(5, 2, 8, 1, 9));
        
        Collections.sort(list);
        boolean found = Collections.binarySearch(list, 8) >= 0;
        
        if (found) {
            System.out.println("Found: 8");
        }
    }
}
```

**Python Code Example:**
```python
# Python's equivalent algorithms

nums = [3, 1, 4, 1, 5, 9, 2, 6]

# Sorting (like std::sort)
sorted_nums = sorted(nums)
print(sorted_nums)  # [1, 1, 2, 3, 4, 5, 6, 9]

# Finding (like std::find)
print(5 in nums)           # True
print(nums.index(5))       # 4

# Filtering (like std::copy_if)
evens = list(filter(lambda x: x % 2 == 0, nums))
print(evens)  # [4, 2, 6]
```

**Key Differences:** C++ STL algorithms are in `<algorithm>` header and use iterators. Java algorithms are in `Collections` class and work with collection objects. C++ has more extensive algorithm library. Python provides built-in functions (`sorted()`, `min()`, `max()`, `sum()`) and the `functools`, `itertools`, and `heapq` modules for algorithmic operations; the `collections` module adds higher-level data structure algorithms.

---

### 97. Iterators

**Definition:** Objects that allow traversal through container elements.

**Explanation:** Iterators provide a uniform way to access container elements sequentially without exposing the underlying structure. They act like pointers to elements.

**C++ Code Example:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    for (vector<int>::iterator it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    cout << endl;
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        
        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }
        System.out.println();
    }
}
```

**Python Code Example:**
```python
# Python's iterator protocol

class MyRange:
    def __init__(self, start, end):
        self.current = start
        self.end = end

    def __iter__(self):  # Makes it iterable
        return self

    def __next__(self):  # Iterator method
        if self.current >= self.end:
            raise StopIteration
        value = self.current
        self.current += 1
        return value

for i in MyRange(0, 5):
    print(i, end=" ")  # 0 1 2 3 4
```

**Key Differences:** C++ iterators behave like pointers with `*` dereference and `++` increment. Java iterators use `hasNext()` and `next()` methods. C++ has multiple iterator categories; Java has simpler iterator interface. Python has first-class iterator support; any object implementing `__iter__` and `__next__` is an iterator. Generator functions (using `yield`) provide a concise way to create iterators.

---

### 98. vector

**Definition:** A dynamic array container that can grow or shrink in size.

**Explanation:** Vector provides random access, dynamic sizing, and efficient insertion/deletion at the end. It's the most commonly used sequence container.

**C++ Code Example:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    
    cout << "Size: " << v.size() << endl;
    cout << "Element at index 1: " << v[1] << endl;
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        list.add(10);
        list.add(20);
        list.add(30);
        
        System.out.println("Size: " + list.size());
        System.out.println("Element at index 1: " + list.get(1));
    }
}
```

**Python Code Example:**
```python
# Python list is equivalent to C++ vector

vector = []             # Empty vector

vector.append(10)       # push_back
vector.append(20)
vector.append(30)
vector.insert(1, 15)    # insert at index

print(vector)           # [10, 15, 20, 30]
print(len(vector))      # size()
print(vector[0])        # front element
vector.pop()            # pop_back
print(vector)           # [10, 15, 20]
```

**Key Differences:** C++ `vector` uses `push_back()` and `[]` operator. Java `ArrayList` uses `add()` and `get()` methods. Both provide dynamic arrays with similar performance characteristics. Python's `list` is the equivalent of C++ `vector`; it is a dynamic array that supports `append()`, `extend()`, `insert()`, `pop()`, and indexing. No type constraint — lists can hold mixed types.

---

### 99. list

**Definition:** A doubly-linked list container.

**Explanation:** List provides efficient insertion and deletion at any position but no random access. Elements are stored in nodes with links to previous and next elements.

**C++ Code Example:**
```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l;
    l.push_back(10);
    l.push_front(5);
    l.push_back(20);
    
    for (int x : l) {
        cout << x << " "; // Outputs: 5 10 20
    }
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        LinkedList<Integer> list = new LinkedList<>();
        list.add(10);
        list.addFirst(5);
        list.add(20);
        
        for (int x : list) {
            System.out.print(x + " "); // Outputs: 5 10 20
        }
    }
}
```

**Python Code Example:**
```python
from collections import deque

# Python list or deque (doubly-linked list behavior)

dll = deque()
dll.append(1)       # push_back
dll.append(2)
dll.appendleft(0)   # push_front
dll.append(3)

print(list(dll))    # [0, 1, 2, 3]

dll.pop()           # pop_back
dll.popleft()       # pop_front
print(list(dll))    # [1, 2]
```

**Key Differences:** C++ `list` is a doubly-linked list with `push_front()` and `push_back()`. Java `LinkedList` is similar with `addFirst()` and `add()`. Both provide O(1) insertion/deletion but O(n) access. Python's `collections.deque` is the closest equivalent to C++ `std::list` (doubly-linked list); Python's built-in `list` is a dynamic array. `deque` supports O(1) append/pop from both ends.

---

### 100. queue

**Definition:** A FIFO (First-In-First-Out) container adapter.

**Explanation:** Queue provides operations for adding elements at the back and removing from the front, following the first-in-first-out principle.

**C++ Code Example:**
```cpp
#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    
    cout << "Front: " << q.front() << endl; // Outputs: 10
    q.pop();
    cout << "New front: " << q.front() << endl; // Outputs: 20
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Queue<Integer> q = new LinkedList<>();
        q.offer(10);
        q.offer(20);
        q.offer(30);
        
        System.out.println("Front: " + q.peek()); // Outputs: 10
        q.poll();
        System.out.println("New front: " + q.peek()); // Outputs: 20
    }
}
```

**Python Code Example:**
```python
from collections import deque

# Python deque used as queue (FIFO)

queue = deque()

queue.append("first")   # enqueue
queue.append("second")
queue.append("third")

print(queue[0])          # front: first
print(queue.popleft())   # dequeue: first
print(queue.popleft())   # dequeue: second
print(len(queue))        # 1
```

**Key Differences:** C++ `queue` uses `push()`, `pop()`, `front()`. Java `Queue` interface uses `offer()`, `poll()`, `peek()`. C++ is a container adapter; Java is an interface with various implementations. Python provides `queue.Queue` (thread-safe), `collections.deque` (general use), and `heapq` (priority queue); `deque.appendleft()`/`popleft()` implement FIFO queue behavior.

---

### 101. stack

**Definition:** A LIFO (Last-In-First-Out) container adapter.

**Explanation:** Stack provides operations for adding and removing elements from the top only, following the last-in-first-out principle.

**C++ Code Example:**
```cpp
#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    
    cout << "Top: " << s.top() << endl; // Outputs: 30
    s.pop();
    cout << "New top: " << s.top() << endl; // Outputs: 20
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Stack<Integer> s = new Stack<>();
        s.push(10);
        s.push(20);
        s.push(30);
        
        System.out.println("Top: " + s.peek()); // Outputs: 30
        s.pop();
        System.out.println("New top: " + s.peek()); // Outputs: 20
    }
}
```

**Python Code Example:**
```python
# Python list used as stack (LIFO)

stack = []

stack.append(10)  # push
stack.append(20)
stack.append(30)

print(stack[-1])  # top: 30
print(stack.pop())  # pop: 30
print(stack.pop())  # pop: 20
print(len(stack))   # 1
```

**Key Differences:** Both languages have similar `Stack` classes with `push()`, `pop()`, and `top()`/`peek()` methods. C++ stack is a container adapter; Java `Stack` is a legacy class (Deque recommended for new code). Python uses a `list` as a stack with `append()` (push) and `pop()` (pop) operations; `collections.deque` can also be used. There is no dedicated `Stack` class in the standard library.

---

### 102. map

**Definition:** An associative container that stores key-value pairs with unique keys.

**Explanation:** Map maintains elements sorted by key and provides fast lookup, insertion, and deletion based on keys. Each key maps to exactly one value.

**C++ Code Example:**
```cpp
#include <iostream>
#include <map>
using namespace std;

int main() {
    map<string, int> ages;
    ages["Alice"] = 25;
    ages["Bob"] = 30;
    
    cout << "Alice's age: " << ages["Alice"] << endl;
    cout << "Size: " << ages.size() << endl;
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Map<String, Integer> ages = new TreeMap<>();
        ages.put("Alice", 25);
        ages.put("Bob", 30);
        
        System.out.println("Alice's age: " + ages.get("Alice"));
        System.out.println("Size: " + ages.size());
    }
}
```

**Python Code Example:**
```python
# Python dict is equivalent to C++ std::map

scores = {}  # Empty map

scores["Alice"] = 95   # Insert
scores["Bob"] = 87
scores["Charlie"] = 92

print(scores["Alice"])  # 95 (access)

for name, score in sorted(scores.items()):  # Iterate (sorted)
    print(f"{name}: {score}")

del scores["Bob"]  # Erase
print("Bob" in scores)  # False
```

**Key Differences:** C++ `map` uses `[]` operator and maintains sorted order (typically red-black tree). Java `TreeMap` uses `put()`/`get()` and is also sorted. Java also has `HashMap` for unsorted, faster access. Python's `dict` is the equivalent of C++ `std::map`/`std::unordered_map`; Python dicts are ordered by insertion order (Python 3.7+) and use hash tables for O(1) average access.

---

### 103. Random-access Iterator

**Definition:** An iterator that provides random access to elements with constant time complexity.

**Explanation:** Random-access iterators support all pointer operations including arithmetic (addition, subtraction, comparison). They allow jumping to any element directly.

**C++ Code Example:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30, 40, 50};
    
    auto it = v.begin();
    it += 2; // Jump to third element
    cout << *it << endl; // Outputs: 30
    cout << *(it + 1) << endl; // Outputs: 40
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't have random-access iterators
// Use ListIterator or direct index access
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(10, 20, 30, 40, 50));
        
        // Direct access instead
        System.out.println(list.get(2)); // Outputs: 30
        System.out.println(list.get(3)); // Outputs: 40
    }
}
```

**Python Code Example:**
```python
# Python lists support random access via indices

my_list = [10, 20, 30, 40, 50]

# Random access (like random-access iterator)
print(my_list[0])   # First element
print(my_list[4])   # Last element
print(my_list[2])   # Middle element

# Slice (range access)
print(my_list[1:4])  # [20, 30, 40]

# Arithmetic on "iterator" (index)
idx = 2
print(my_list[idx + 1])  # 40
```

**Key Differences:** C++ has random-access iterators for containers like `vector` and `deque`. Java doesn't have iterator categories; uses `ListIterator` for bidirectional access or direct indexing for random access. Python supports random access via indexing (`seq[i]`) on sequences like `list` and `tuple`; the `__getitem__` dunder method enables random-access iteration in custom classes.

---

### 104. Bidirectional Iterator

**Definition:** An iterator that can move both forward and backward through elements.

**Explanation:** Bidirectional iterators support `++` (forward) and `--` (backward) operations but not arithmetic operations. Used by containers like `list`, `set`, and `map`.

**C++ Code Example:**
```cpp
#include <iostream>
#include <list>
using namespace std;

int main() {
    list<int> l = {10, 20, 30, 40};
    
    auto it = l.end();
    --it; // Move backward
    cout << *it << endl; // Outputs: 40
    --it;
    cout << *it << endl; // Outputs: 30
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new LinkedList<>(Arrays.asList(10, 20, 30, 40));
        
        ListIterator<Integer> it = list.listIterator(list.size());
        System.out.println(it.previous()); // Outputs: 40
        System.out.println(it.previous()); // Outputs: 30
    }
}
```

**Python Code Example:**
```python
from collections import deque

# Python's deque supports bidirectional iteration

d = deque([1, 2, 3, 4, 5])

# Forward iteration
for item in d:
    print(item, end=" ")
print()

# Backward iteration (reversed)
for item in reversed(d):
    print(item, end=" ")
print()

# Manual bidirectional using index
lst = [10, 20, 30, 40]
i = 0
while i < len(lst):
    print(lst[i], end=" ")
    i += 1
```

**Key Differences:** C++ uses `++` and `--` operators on iterators. Java uses `ListIterator` with `next()` and `previous()` methods. C++ has explicit iterator categories; Java doesn't. Python supports bidirectional iteration through `reversed()` on sequences and `__reversed__` dunder method; generators only support forward iteration.

---

### 105. Forward Iterator

**Definition:** An iterator that can only move forward through elements.

**Explanation:** Forward iterators support `++` operation and multi-pass iteration (can iterate multiple times over the same range). Cannot move backward.

**C++ Code Example:**
```cpp
#include <iostream>
#include <forward_list>
using namespace std;

int main() {
    forward_list<int> fl = {10, 20, 30};
    
    for (auto it = fl.begin(); it != fl.end(); ++it) {
        cout << *it << " "; // Outputs: 10 20 30
    }
    return 0;
}
```

**Java Code Example:**
```java
// Java's standard Iterator is forward-only
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(10, 20, 30));
        
        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            System.out.print(it.next() + " "); // Outputs: 10 20 30
        }
    }
}
```

**Python Code Example:**
```python
# Python's iterator protocol is a forward iterator

class ForwardIterator:
    def __init__(self, data):
        self.data = data
        self.index = 0

    def __iter__(self):
        return self

    def __next__(self):
        if self.index >= len(self.data):
            raise StopIteration
        value = self.data[self.index]
        self.index += 1
        return value

it = ForwardIterator([1, 2, 3, 4])
for val in it:
    print(val, end=" ")  # 1 2 3 4
```

**Key Differences:** C++ has explicit forward iterator category for containers like `forward_list`. Java's default `Iterator` is forward-only but isn't categorized as such. Functionality is similar. Python iterators are forward-only by default; any object implementing `__iter__` and `__next__` provides forward iteration; generators and `iter()` built-in create forward iterators.

---

### 106. Input Iterator

**Definition:** An iterator that can read elements sequentially in a single pass.

**Explanation:** Input iterators are the most basic read-only iterators. They support single-pass iteration (can only traverse once) and are typically used for reading from input streams.

**C++ Code Example:**
```cpp
#include <iostream>
#include <iterator>
#include <sstream>
using namespace std;

int main() {
    istringstream iss("10 20 30");
    
    istream_iterator<int> start(iss);
    istream_iterator<int> end;
    
    while (start != end) {
        cout << *start << " "; // Outputs: 10 20 30
        ++start;
    }
    return 0;
}
```

**Java Code Example:**
```java
// Java uses Scanner or BufferedReader for input
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner("10 20 30");
        
        while (scanner.hasNextInt()) {
            System.out.print(scanner.nextInt() + " "); // Outputs: 10 20 30
        }
        scanner.close();
    }
}
```

**Python Code Example:**
```python
# Python generators are single-pass input iterators

def read_numbers(n):  # Generator (input iterator)
    for i in range(n):
        yield i * i  # Yields values one at a time

gen = read_numbers(5)
print(next(gen))  # 0
print(next(gen))  # 1
print(next(gen))  # 4

# Iterate over all values
for val in read_numbers(5):
    print(val, end=" ")  # 0 1 4 9 16
```

**Key Differences:** C++ has explicit input iterator category (`istream_iterator`). Java doesn't categorize iterators but uses classes like `Scanner` for input. C++ iterators are more generic; Java uses specialized input classes. Python's iterator protocol (`__iter__`/`__next__`) is the equivalent of input iterators; `for` loops, `map()`, and `filter()` consume iterators sequentially.

---

### 107. Output Iterator

**Definition:** An iterator that can write elements sequentially in a single pass.

**Explanation:** Output iterators are write-only iterators used for sequential output operations. They support single-pass iteration and are typically used with output streams or algorithms.

**C++ Code Example:**
```cpp
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    
    ostream_iterator<int> out(cout, " ");
    copy(v.begin(), v.end(), out); // Outputs: 10 20 30
    return 0;
}
```

**Java Code Example:**
```java
// Java doesn't have output iterators
// Use PrintWriter or similar for output
import java.util.*;
import java.io.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(10, 20, 30);
        PrintWriter out = new PrintWriter(System.out);
        
        for (int x : list) {
            out.print(x + " "); // Outputs: 10 20 30
        }
        out.flush();
    }
}
```

**Python Code Example:**
```python
# Python uses file objects or custom classes for output iteration

class OutputIterator:
    def __init__(self):
        self.data = []

    def write(self, value):  # Output iterator method
        self.data.append(value)
        return self

out = OutputIterator()
out.write(1).write(2).write(3)  # Chained output
print(out.data)  # [1, 2, 3]

# File as output iterator
import sys
for i in range(3):
    sys.stdout.write(str(i) + " ")  # 0 1 2
```

**Key Differences:** C++ has explicit output iterator category (`ostream_iterator`). Java doesn't have output iterators; uses output stream classes directly. C++ integrates iterators with algorithms; Java uses different approach. Python uses generators, list comprehensions, and `yield` for output-like iteration patterns; `itertools` provides many output-style iterator tools.

---

### 108. size_type

**Definition:** An unsigned integer type representing the size of a container.

**Explanation:** `size_type` is a typedef defined by containers to represent sizes and counts. It's guaranteed to be large enough to represent the maximum size of the container.

**C++ Code Example:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {1, 2, 3, 4, 5};
    
    vector<int>::size_type sz = v.size();
    cout << "Size: " << sz << endl;
    
    for (vector<int>::size_type i = 0; i < sz; ++i) {
        cout << v[i] << " ";
    }
    return 0;
}
```

**Java Code Example:**
```java
// Java uses int for size
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(1, 2, 3, 4, 5));
        
        int size = list.size();
        System.out.println("Size: " + size);
        
        for (int i = 0; i < size; i++) {
            System.out.print(list.get(i) + " ");
        }
    }
}
```

**Python Code Example:**
```python
# Python uses int for sizes; len() returns int

my_list = [1, 2, 3, 4, 5]

size = len(my_list)         # Equivalent to size_type
print(type(size))           # <class 'int'>
print(size)                 # 5

# Python int is arbitrary precision (no overflow)
large = list(range(1000))
print(len(large))           # 1000

# sys.getsizeof for memory size
import sys
print(sys.getsizeof(my_list))  # Memory size in bytes
```

**Key Differences:** C++ containers define `size_type` (usually `std::size_t`, unsigned). Java uses `int` for sizes (signed, limited to 2^31-1). C++ is more flexible for very large containers. Python uses `len(container)` to get the size of any container; the return type is a plain `int` (arbitrary precision). No separate `size_type` is needed.

---

### 109. iterator type

**Definition:** A typedef representing the iterator type for a container.

**Explanation:** Each container defines its own `iterator` type that can be used to traverse elements. This type varies based on the container's structure.

**C++ Code Example:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v = {10, 20, 30};
    
    // Using iterator type
    vector<int>::iterator it;
    for (it = v.begin(); it != v.end(); ++it) {
        cout << *it << " ";
    }
    return 0;
}
```

**Java Code Example:**
```java
import java.util.*;

public class Main {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(10, 20, 30));
        
        // Using Iterator type
        Iterator<Integer> it = list.iterator();
        while (it.hasNext()) {
            System.out.print(it.next() + " ");
        }
    }
}
```

**Python Code Example:**
```python
# Python iterator types

my_list = [1, 2, 3]

it = iter(my_list)          # List iterator
print(type(it))             # <class 'list_iterator'>

my_dict = {"a": 1, "b": 2}
dict_it = iter(my_dict)     # Dict key iterator
print(type(dict_it))        # <class 'dict_keyiterator'>

# Check if object is iterator
from collections.abc import Iterator
print(isinstance(it, Iterator))  # True
```

**Key Differences:** C++ containers have `iterator` and `const_iterator` typedefs specific to each container. Java uses generic `Iterator<T>` interface for all collections. C++ iterators act like pointers; Java iterators use methods. Python iterators are objects implementing `__iter__` and `__next__`; use `iter(collection)` to get an iterator and `next(iterator)` to advance it; `type()` returns the iterator's type.

---

### 110. value_type

**Definition:** A typedef representing the type of elements stored in a container.

**Explanation:** `value_type` is defined by containers to specify the type of elements they hold. It's useful for writing generic code that works with different container types.

**C++ Code Example:**
```cpp
#include <iostream>
#include <vector>
using namespace std;

template <typename Container>
void printFirst(const Container& c) {
    typename Container::value_type first = *c.begin();
    cout << "First element: " << first << endl;
}

int main() {
    vector<int> v = {100, 200, 300};
    printFirst(v); // Outputs: First element: 100
    return 0;
}
```

**Java Code Example:**
```java
// Java uses generic type parameter directly
import java.util.*;

public class Main {
    public static <T> void printFirst(List<T> list) {
        T first = list.get(0);
        System.out.println("First element: " + first);
    }
    
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>(Arrays.asList(100, 200, 300));
        printFirst(list); // Outputs: First element: 100
    }
}
```

**Python Code Example:**
```python
# Python is dynamically typed; no explicit value_type
# Use type annotations for clarity

from typing import List

def sum_list(items: List[int]) -> int:  # value_type = int
    return sum(items)

# Python infers element types at runtime
numbers = [1, 2, 3, 4, 5]
first = numbers[0]
print(type(first))  # <class 'int'>

strings = ["a", "b", "c"]
print(type(strings[0]))  # <class 'str'>
```

**Key Differences:** C++ containers define `value_type` typedef for element type. Java uses the generic type parameter directly (no separate typedef). Both achieve type safety but with different mechanisms. Python containers hold references to objects of any type (no explicit `value_type`); use `type(element)` to get the type of a stored value. Type hints like `List[int]` from `typing` add optional static type annotations.

## Exception Handling

### Table of Contents
111. [Exception Handling](#111-exception-handling)
112. [try Block](#112-try-block)
113. [throw Statement](#113-throw-statement)
114. [catch Block](#114-catch-block)
115. [Checked Exception](#115-checked-exception)
116. [Unchecked Exception](#116-unchecked-exception)
117. [RuntimeException](#117-runtimeexception)
118. [Error](#118-error)
119. [Chained Exceptions](#119-chained-exceptions)
120. [Throwable](#120-throwable)

---

### 111. Exception Handling

**Definition:** A mechanism to handle runtime errors and maintain normal program flow.

**Explanation:** Exception handling allows programs to catch and respond to errors gracefully instead of crashing. It separates error-handling code from regular code, making programs more robust and maintainable.

**C++ Example:**
```cpp
#include <iostream>
using namespace std;

int divide(int a, int b) {
    if (b == 0) throw "Division by zero!";
    return a / b;
}

int main() {
    try {
        int result = divide(10, 0);
    } catch (const char* msg) {
        cout << "Error: " << msg << endl;
    }
    return 0;
}
```

**Java Example:**
```java
public class Main {
    public static int divide(int a, int b) {
        if (b == 0) throw new ArithmeticException("Division by zero!");
        return a / b;
    }
    
    public static void main(String[] args) {
        try {
            int result = divide(10, 0);
        } catch (ArithmeticException e) {
            System.out.println("Error: " + e.getMessage());
        }
    }
}
```

**Python Code Example:**
```python
try:
    result = 10 / 0
except ZeroDivisionError as e:
    print(f"Error: {e}")
except Exception as e:
    print(f"General error: {e}")
else:
    print("No exception occurred")
finally:
    print("Always executed")
```

**Key Differences:** Java has a more structured exception hierarchy with checked and unchecked exceptions. C++ doesn't distinguish between checked/unchecked exceptions and allows throwing any type.

---

### 112. try Block

**Definition:** A code block that contains statements which might throw exceptions.

**Explanation:** The try block wraps code that may produce errors. If an exception occurs within the try block, control immediately transfers to the corresponding catch block.

**C++ Example:**
```cpp
try {
    int* arr = new int[1000000000000]; // May throw bad_alloc
    delete[] arr;
}
```

**Java Example:**
```java
try {
    int[] arr = new int[1000000000];
    System.out.println("Array created");
}
```

**Python Code Example:**
```python
def divide(a, b):
    try:
        result = a / b          # Code that may raise exception
        print(f"Result: {result}")
    except ZeroDivisionError:
        print("Cannot divide by zero")
    return result if b != 0 else None

divide(10, 2)   # Result: 5.0
divide(10, 0)   # Cannot divide by zero
```

**Key Differences:** Both work similarly, but Java's try block can be used with resources (try-with-resources) for automatic resource management.

---

### 113. throw Statement

**Definition:** A keyword used to explicitly throw an exception.

**Explanation:** The throw statement signals that an error has occurred. It creates an exception object and transfers control to the nearest catch block that can handle it.

**C++ Example:**
```cpp
void checkAge(int age) {
    if (age < 18) {
        throw runtime_error("Age must be 18 or older");
    }
}
```

**Java Example:**
```java
void checkAge(int age) {
    if (age < 18) {
        throw new IllegalArgumentException("Age must be 18 or older");
    }
}
```

**Python Code Example:**
```python
def validate_age(age):
    if age < 0:
        raise ValueError("Age cannot be negative")  # raise = throw
    if age > 150:
        raise ValueError("Age seems too large")
    return age

try:
    validate_age(-5)
except ValueError as e:
    print(f"Caught: {e}")  # Caught: Age cannot be negative
```

**Key Differences:** C++ can throw any type (int, string, custom objects). Java typically throws objects that inherit from Throwable.

---

### 114. catch Block

**Definition:** A code block that handles exceptions thrown from a try block.

**Explanation:** The catch block specifies the type of exception it handles and contains code to respond to that error. Multiple catch blocks can handle different exception types.

**C++ Example:**
```cpp
try {
    throw 404;
} catch (int errorCode) {
    cout << "Error code: " << errorCode << endl;
} catch (...) {
    cout << "Unknown error" << endl;
}
```

**Java Example:**
```java
try {
    throw new FileNotFoundException("File not found");
} catch (FileNotFoundException e) {
    System.out.println("Error: " + e.getMessage());
} catch (Exception e) {
    System.out.println("General error");
}
```

**Python Code Example:**
```python
def process_file(filename):
    try:
        with open(filename, 'r') as f:
            content = f.read()
    except FileNotFoundError:     # Catch specific exception
        print(f"File not found: {filename}")
    except PermissionError:       # Catch another type
        print("No permission to read file")
    except Exception as e:        # Catch any exception
        print(f"Unexpected error: {e}")

process_file("missing.txt")  # File not found: missing.txt
```

**Key Differences:** C++ uses `catch(...)` to catch all exceptions. Java uses `catch(Exception e)` for general exceptions but cannot catch Errors this way.

---

### 115. Checked Exception

**Definition:** Exceptions that must be declared or caught at compile time.

**Explanation:** Checked exceptions are verified by the compiler. Methods that throw checked exceptions must declare them using 'throws' keyword, forcing the caller to handle them.

**C++ Example:**
```cpp
// C++ does not have checked exceptions
// All exceptions are unchecked
```

**Java Example:**
```java
import java.io.*;

void readFile(String path) throws IOException {
    FileReader file = new FileReader(path);
    // File operations
    file.close();
}
```

**Python Code Example:**
```python
# Python doesn't distinguish checked/unchecked exceptions
# Convention: document exceptions with docstrings

class InsufficientFundsError(Exception):
    """Raised when withdrawal exceeds balance."""
    pass

class BankAccount:
    def __init__(self, balance):
        self.balance = balance

    def withdraw(self, amount):
        """
        Raises:
            InsufficientFundsError: If amount > balance
        """
        if amount > self.balance:
            raise InsufficientFundsError("Insufficient funds")
        self.balance -= amount
```

**Key Differences:** Checked exceptions exist only in Java. C++ treats all exceptions as unchecked, giving more flexibility but less compile-time safety.

---

### 116. Unchecked Exception

**Definition:** Exceptions that are not checked at compile time.

**Explanation:** Unchecked exceptions occur at runtime and don't need to be declared or caught. They typically represent programming errors like null pointers or array bounds violations.

**C++ Example:**
```cpp
void process(int* ptr) {
    int value = *ptr; // May crash if ptr is null
}
```

**Java Example:**
```java
public void process(String text) {
    int len = text.length(); // NullPointerException if text is null
}
```

**Python Code Example:**
```python
# Most Python exceptions are "unchecked" (no forced handling)

def get_element(lst, index):
    return lst[index]  # May raise IndexError (unchecked)

def divide(a, b):
    return a / b  # May raise ZeroDivisionError (unchecked)

# These don't need to be caught (but should be handled gracefully)
try:
    result = get_element([1, 2, 3], 10)
except IndexError as e:
    print(f"Index error: {e}")  # list index out of range
```

**Key Differences:** In C++, all exceptions are unchecked. In Java, RuntimeException and its subclasses are unchecked.

---

### 117. RuntimeException

**Definition:** Base class for unchecked exceptions in Java.

**Explanation:** RuntimeException represents exceptions that occur during program execution and typically indicate programming bugs. These don't need to be declared or caught.

**C++ Example:**
```cpp
// C++ uses runtime_error for similar purposes
#include <stdexcept>

throw runtime_error("Unexpected condition");
```

**Java Example:**
```java
public void divide(int a, int b) {
    if (b == 0) {
        throw new ArithmeticException("Cannot divide by zero");
    }
}
```

**Python Code Example:**
```python
# Python runtime exceptions (subclasses of Exception)

# Common runtime exceptions:
# ValueError, TypeError, IndexError, KeyError, AttributeError

def safe_divide(a, b):
    if not isinstance(a, (int, float)):
        raise TypeError(f"Expected number, got {type(a)}")  # RuntimeException
    if b == 0:
        raise ZeroDivisionError("Division by zero")
    return a / b

try:
    safe_divide("hello", 2)
except TypeError as e:
    print(f"TypeError: {e}")
```

**Key Differences:** Java has RuntimeException as a specific unchecked exception class. C++ has std::runtime_error but all exceptions are unchecked.

---

### 118. Error

**Definition:** Serious problems that applications should not try to catch.

**Explanation:** Errors represent serious issues typically outside the application's control, like OutOfMemoryError or StackOverflowError. They indicate conditions that recovery is usually not possible.

**C++ Example:**
```cpp
// C++ doesn't distinguish Error from Exception
// Use standard exception classes
throw bad_alloc(); // Memory allocation failure
```

**Java Example:**
```java
// Example of Error (not recommended to throw manually)
// Error occurs automatically in severe situations
public void causeStackOverflow() {
    causeStackOverflow(); // StackOverflowError
}
```

**Python Code Example:**
```python
# Python has BaseException hierarchy
# Error classes: Exception > Error (various)
# Critical errors: SystemExit, KeyboardInterrupt (BaseException)

try:
    raise MemoryError("Out of memory")  # System error
except MemoryError as e:
    print(f"Memory Error: {e}")

# SystemExit is like Java's Error (not typically caught)
# import sys; sys.exit(1)  # Raises SystemExit
```

**Key Differences:** Java has a distinct Error class hierarchy separate from Exception. C++ doesn't make this distinction.

---

### 119. Chained Exceptions

**Definition:** Linking one exception to another to preserve the cause of an error.

**Explanation:** Chained exceptions allow you to wrap one exception inside another, maintaining the original error context while providing additional information. This helps in debugging complex error scenarios.

**C++ Example:**
```cpp
#include <exception>
#include <iostream>
using namespace std;

class MyException : public exception {
    string msg;
public:
    MyException(string m) : msg(m) {}
    const char* what() const noexcept { return msg.c_str(); }
};

void process() {
    try {
        throw runtime_error("Original error");
    } catch (exception& e) {
        throw MyException(string("Wrapped: ") + e.what());
    }
}
```

**Java Example:**
```java
public void process() throws Exception {
    try {
        throw new IOException("File error");
    } catch (IOException e) {
        throw new Exception("Processing failed", e); // Chained
    }
}
```

**Python Code Example:**
```python
class DatabaseError(Exception):
    pass

class AppError(Exception):
    pass

def query_database():
    raise DatabaseError("Connection failed")

def fetch_user():
    try:
        query_database()
    except DatabaseError as e:
        raise AppError("Failed to fetch user") from e  # Exception chaining

try:
    fetch_user()
except AppError as e:
    print(f"App error: {e}")
    print(f"Caused by: {e.__cause__}")
```

**Key Differences:** Java has built-in support for chained exceptions via constructors and getCause(). C++ requires manual implementation.

---

### 120. Throwable

**Definition:** The superclass of all errors and exceptions in Java.

**Explanation:** Throwable is the root class for all objects that can be thrown using the throw statement. All exceptions and errors inherit from Throwable.

**C++ Example:**
```cpp
// C++ uses std::exception as base class
#include <exception>

class MyException : public std::exception {
    const char* what() const noexcept {
        return "Custom exception";
    }
};
```

**Java Example:**
```java
// All exceptions inherit from Throwable
public class CustomException extends Throwable {
    public CustomException(String message) {
        super(message);
    }
}
```

**Python Code Example:**
```python
# Python's BaseException is the equivalent of Java's Throwable

class CustomException(Exception):  # Inherits from Exception (like Throwable)
    def __init__(self, message, code=0):
        super().__init__(message)
        self.code = code

    def __str__(self):
        return f"[Error {self.code}] {super().__str__()}"

try:
    raise CustomException("Something went wrong", code=404)
except CustomException as e:
    print(e)  # [Error 404] Something went wrong
```

**Key Differences:** Java uses Throwable as the root. C++ uses std::exception as the base but allows throwing any type.

---

## Interfaces and Abstract Classes

### Table of Contents
121. [Interface](#121-interface)
122. [Abstract Method](#122-abstract-method)
123. [Interface Contents](#123-interface-contents)
124. [Implementation (implements Keyword)](#124-implementation-implements-keyword)
125. [Comparable Interface](#125-comparable-interface)
126. [Cloneable Interface](#126-cloneable-interface)
127. [Marker Interface](#127-marker-interface)
128. [Functional Interface](#128-functional-interface)
129. [Subinterface](#129-subinterface)
130. [extends Keyword](#130-extends-keyword)

---

### 121. Interface

**Definition:** A contract that defines methods a class must implement, containing only abstract methods and constants.

**Explanation:** Interfaces specify what a class must do, not how. They enable multiple inheritance of type and support polymorphism. Classes implement interfaces to guarantee certain behaviors.

**C++ Example:**
```cpp
class Drawable {
public:
    virtual void draw() = 0; // Pure virtual function
    virtual ~Drawable() {}
};

class Circle : public Drawable {
public:
    void draw() override {
        cout << "Drawing circle" << endl;
    }
};
```

**Java Example:**
```java
interface Drawable {
    void draw(); // Abstract method
}

class Circle implements Drawable {
    public void draw() {
        System.out.println("Drawing circle");
    }
}
```

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class Drawable(ABC):  # Interface equivalent
    @abstractmethod
    def draw(self):
        pass

    @abstractmethod
    def resize(self, factor):
        pass

class Circle(Drawable):
    def draw(self):
        print("Drawing circle")

    def resize(self, factor):
        print(f"Resizing circle by {factor}")

c = Circle()
c.draw()
c.resize(2)
```

**Key Differences:** C++ uses abstract classes with pure virtual functions. Java has dedicated 'interface' keyword. Java 8+ allows default methods in interfaces.

---

### 122. Abstract Method

**Definition:** A method declared without an implementation that must be overridden in subclasses.

**Explanation:** Abstract methods define the signature but leave the implementation to derived classes. They enforce a contract that subclasses must fulfill.

**C++ Example:**
```cpp
class Animal {
public:
    virtual void makeSound() = 0; // Abstract method
};

class Dog : public Animal {
public:
    void makeSound() override {
        cout << "Woof!" << endl;
    }
};
```

**Java Example:**
```java
abstract class Animal {
    abstract void makeSound(); // Abstract method
}

class Dog extends Animal {
    void makeSound() {
        System.out.println("Woof!");
    }
}
```

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class Vehicle(ABC):
    @abstractmethod
    def start_engine(self):  # Abstract method - must be overridden
        pass

    @abstractmethod
    def stop_engine(self):
        pass

    def status(self):  # Concrete method
        print("Vehicle status: OK")

class Car(Vehicle):
    def start_engine(self):
        print("Car engine started")

    def stop_engine(self):
        print("Car engine stopped")
```

**Key Differences:** C++ uses `= 0` syntax for pure virtual functions. Java uses 'abstract' keyword explicitly.

---

### 123. Interface Contents

**Definition:** The members allowed within an interface definition.

**Explanation:** Traditionally, interfaces contain abstract methods and constants. Modern Java allows default methods, static methods, and private methods in interfaces.

**C++ Example:**
```cpp
// C++ abstract class (interface-like)
class Device {
public:
    virtual void turnOn() = 0;
    virtual void turnOff() = 0;
    static const int MAX_POWER = 100;
};
```

**Java Example:**
```java
interface Device {
    void turnOn();  // Abstract method
    void turnOff(); // Abstract method
    int MAX_POWER = 100; // Constant (public static final)
    
    default void reset() { // Default method (Java 8+)
        turnOff();
        turnOn();
    }
}
```

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class Serializable(ABC):
    VERSION = "1.0"  # Constant (like interface constant)

    @abstractmethod
    def serialize(self) -> str:  # Abstract method
        pass

    @abstractmethod
    def deserialize(self, data: str):
        pass

    def get_version(self):  # Default method (Python allows concrete methods)
        return self.VERSION

class JsonDoc(Serializable):
    def serialize(self):
        return '{"data": "value"}'

    def deserialize(self, data):
        import json
        return json.loads(data)
```

**Key Differences:** Java interfaces can have default implementations (Java 8+). C++ abstract classes can have any member types including fields and constructors.

---

### 124. Implementation (implements Keyword)

**Definition:** The keyword used to declare that a class provides the behavior specified by an interface.

**Explanation:** When a class implements an interface, it must provide concrete implementations for all abstract methods declared in that interface.

**C++ Example:**
```cpp
// C++ uses inheritance with colon
class Printer : public Printable {
public:
    void print() override {
        cout << "Printing..." << endl;
    }
};
```

**Java Example:**
```java
class Printer implements Printable {
    public void print() {
        System.out.println("Printing...");
    }
}
```

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class Printable(ABC):
    @abstractmethod
    def print_info(self):
        pass

class Saveable(ABC):
    @abstractmethod
    def save(self):
        pass

# Implementing multiple interfaces (ABC classes)
class Document(Printable, Saveable):  # "implements" both
    def __init__(self, content):
        self.content = content

    def print_info(self):
        print(self.content)

    def save(self):
        print(f"Saving: {self.content}")

doc = Document("Hello World")
doc.print_info()
doc.save()
```

**Key Differences:** Java uses 'implements' keyword for interfaces and 'extends' for classes. C++ uses inheritance (`:`) for both.

---

### 125. Comparable Interface

**Definition:** An interface that defines a natural ordering for objects of a class.

**Explanation:** Comparable allows objects to be compared and sorted. It contains the compareTo() method which returns negative, zero, or positive values indicating ordering.

**C++ Example:**
```cpp
class Student {
public:
    int id;
    Student(int i) : id(i) {}
    
    bool operator<(const Student& other) const {
        return id < other.id;
    }
};
```

**Java Example:**
```java
class Student implements Comparable<Student> {
    int id;
    
    public int compareTo(Student other) {
        return Integer.compare(this.id, other.id);
    }
}
```

**Python Code Example:**
```python
from functools import total_ordering

@total_ordering  # Generates missing comparison methods
class Student:
    def __init__(self, name, gpa):
        self.name = name
        self.gpa = gpa

    def __eq__(self, other):
        return self.gpa == other.gpa

    def __lt__(self, other):   # Comparable equivalent
        return self.gpa < other.gpa

students = [Student("Alice", 3.8), Student("Bob", 3.5), Student("Charlie", 3.9)]
students.sort()  # Uses __lt__
for s in students:
    print(s.name, s.gpa)
```

**Key Differences:** C++ uses operator overloading (`<`, `>`, etc.). Java uses the Comparable interface with compareTo() method.

---

### 126. Cloneable Interface

**Definition:** A marker interface indicating that a class allows object cloning.

**Explanation:** Cloneable signals that an object can be safely cloned using the clone() method. Without implementing this interface, clone() throws CloneNotSupportedException.

**C++ Example:**
```cpp
class Person {
public:
    string name;
    
    Person(string n) : name(n) {}
    
    Person(const Person& other) { // Copy constructor
        name = other.name;
    }
};
```

**Java Example:**
```java
class Person implements Cloneable {
    String name;
    
    protected Object clone() throws CloneNotSupportedException {
        return super.clone();
    }
}
```

**Python Code Example:**
```python
import copy

class Employee:
    def __init__(self, name, salary):
        self.name = name
        self.salary = salary
        self.skills = []

    def __copy__(self):   # Shallow copy
        new = Employee(self.name, self.salary)
        new.skills = self.skills
        return new

    def __deepcopy__(self, memo):  # Deep copy
        new = Employee(self.name, self.salary)
        new.skills = copy.deepcopy(self.skills, memo)
        return new

e1 = Employee("Alice", 60000)
e1.skills = ["Python", "Java"]
e2 = copy.deepcopy(e1)  # Clone
print(e2.name, e2.skills)
```

**Key Differences:** C++ uses copy constructors and assignment operators. Java uses Cloneable interface and clone() method.

---

### 127. Marker Interface

**Definition:** An interface with no methods that serves as a flag to provide metadata about a class.

**Explanation:** Marker interfaces don't define behavior but indicate that a class has certain properties or capabilities. The compiler or runtime uses this information.

**C++ Example:**
```cpp
// C++ doesn't have marker interfaces
// Use empty base classes or type traits
class Serializable {}; // Empty class as marker

class Data : public Serializable {
    int value;
};
```

**Java Example:**
```java
// Serializable is a built-in marker interface
import java.io.Serializable;

class Data implements Serializable {
    int value;
}
```

**Python Code Example:**
```python
# Python uses ABC or simple class inheritance as marker interfaces

class Serializable:  # Marker "interface" (no methods)
    pass

class Cacheable:     # Another marker
    pass

class UserProfile(Serializable, Cacheable):  # "Implements" markers
    def __init__(self, name):
        self.name = name

profile = UserProfile("Alice")

# Check "marker" at runtime
print(isinstance(profile, Serializable))  # True
print(isinstance(profile, Cacheable))     # True
```

**Key Differences:** Java has explicit marker interfaces (Serializable, Cloneable). C++ achieves similar effects through templates, traits, or empty base classes.

---

### 128. Functional Interface

**Definition:** An interface with exactly one abstract method, used for lambda expressions.

**Explanation:** Functional interfaces enable functional programming features. They can have multiple default or static methods but only one abstract method. Used extensively with lambda expressions and method references.

**C++ Example:**
```cpp
#include <functional>

// Using std::function
function<int(int, int)> add = [](int a, int b) {
    return a + b;
};

int result = add(5, 3); // 8
```

**Java Example:**
```java
@FunctionalInterface
interface Calculator {
    int calculate(int a, int b);
}

Calculator add = (a, b) -> a + b;
int result = add.calculate(5, 3); // 8
```

**Python Code Example:**
```python
from typing import Callable

# Python callables and lambdas are functional interface equivalents

# Function as callable
def square(x: int) -> int:
    return x * x

# Lambda expression (inline functional interface)
cube: Callable[[int], int] = lambda x: x ** 3

def apply(func: Callable[[int], int], value: int) -> int:
    return func(value)

print(apply(square, 4))    # 16
print(apply(cube, 3))      # 27
print(apply(lambda x: x + 1, 5))  # 6
```

**Key Differences:** C++ uses std::function and lambdas directly. Java uses @FunctionalInterface annotation and has built-in functional interfaces (Predicate, Function, Consumer).

---

### 129. Subinterface

**Definition:** An interface that extends another interface, inheriting its methods.

**Explanation:** Subinterfaces create a hierarchy of interfaces. A subinterface inherits all abstract methods from its parent interface and can add new ones.

**C++ Example:**
```cpp
class Readable {
public:
    virtual void read() = 0;
};

class Editable : public Readable {
public:
    virtual void edit() = 0;
};
```

**Java Example:**
```java
interface Readable {
    void read();
}

interface Editable extends Readable {
    void edit();
}
```

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class Readable(ABC):  # Parent interface
    @abstractmethod
    def read(self):
        pass

class ReadWritable(Readable):  # Subinterface (extends Readable)
    @abstractmethod
    def write(self, data):
        pass

class FileStream(ReadWritable):
    def read(self):
        print("Reading data")

    def write(self, data):
        print(f"Writing: {data}")

fs = FileStream()
fs.read()
fs.write("Hello")
```

**Key Differences:** Both support interface inheritance. Java uses 'extends' for interface-to-interface relationships. C++ uses standard inheritance.

---

### 130. extends Keyword

**Definition:** A keyword used to create inheritance relationships between classes or interfaces.

**Explanation:** 'extends' establishes an "is-a" relationship where the child inherits members from the parent. In Java, it's used for both class and interface inheritance.

**C++ Example:**
```cpp
class Vehicle {
    int speed;
};

class Car : public Vehicle { // Inheritance using colon
    int doors;
};
```

**Java Example:**
```java
class Vehicle {
    int speed;
}

class Car extends Vehicle {
    int doors;
}
```

**Python Code Example:**
```python
# Python uses class ChildClass(ParentClass) syntax

class Animal:       # Base class
    def eat(self):
        print("Animal eats")

class Mammal(Animal):  # extends Animal
    def breathe(self):
        print("Breathes with lungs")

class Dog(Mammal):  # extends Mammal (multi-level)
    def bark(self):
        print("Woof!")

dog = Dog()
dog.eat()     # From Animal
dog.breathe() # From Mammal
dog.bark()    # Own method
```

**Key Differences:** Java uses 'extends' keyword. C++ uses colon (`:`) with access specifiers (public, private, protected).

---

## Relationships and Design

### Table of Contents
131. [Encapsulation](#131-encapsulation)
132. [Inheritance](#132-inheritance)
133. [Polymorphism](#133-polymorphism)
134. [Abstraction](#134-abstraction)
135. [Association](#135-association)
136. [Aggregation](#136-aggregation)
137. [Composition](#137-composition)
138. ["is-a" Relationship](#138-is-a-relationship)
139. ["has-a" Relationship](#139-has-a-relationship)
140. ["is-kind-of" Relationship](#140-is-kind-of-relationship)
141. [Hierarchical Classification](#141-hierarchical-classification)
142. [Code Reusability](#142-code-reusability)
143. [Data Hiding](#143-data-hiding)
144. [Information Hiding](#144-information-hiding)
145. [Class Abstraction](#145-class-abstraction)

---

### 131. Encapsulation

**Definition:** Bundling data and methods that operate on that data within a single unit, hiding internal details.

**Explanation:** Encapsulation restricts direct access to object components, exposing only necessary parts through public methods (getters/setters). This protects data integrity and allows implementation changes without affecting external code.

**C++ Example:**
```cpp
class BankAccount {
private:
    double balance;
public:
    void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    double getBalance() { return balance; }
};
```

**Java Example:**
```java
class BankAccount {
    private double balance;
    
    public void deposit(double amount) {
        if (amount > 0) balance += amount;
    }
    public double getBalance() { return balance; }
}
```

**Python Code Example:**
```python
class BankAccount:
    def __init__(self, owner, balance):
        self.__owner = owner     # Encapsulated data
        self.__balance = balance

    def deposit(self, amount):   # Controlled interface
        if amount > 0:
            self.__balance += amount

    def withdraw(self, amount):
        if 0 < amount <= self.__balance:
            self.__balance -= amount

    def get_balance(self):       # Controlled access
        return self.__balance

acc = BankAccount("Alice", 1000)
acc.deposit(500)
print(acc.get_balance())  # 1500
```

**Key Differences:** Both languages support encapsulation similarly through access modifiers (private, public, protected).

---

### 132. Inheritance

**Definition:** A mechanism where a new class derives properties and behaviors from an existing class.

**Explanation:** Inheritance creates parent-child relationships between classes, promoting code reuse. The child class inherits members from the parent and can add new features or override existing ones.

**C++ Example:**
```cpp
class Animal {
public:
    void eat() { cout << "Eating" << endl; }
};

class Dog : public Animal {
public:
    void bark() { cout << "Barking" << endl; }
};
```

**Java Example:**
```java
class Animal {
    void eat() { System.out.println("Eating"); }
}

class Dog extends Animal {
    void bark() { System.out.println("Barking"); }
}
```

**Python Code Example:**
```python
class Shape:        # Base class
    def __init__(self, color):
        self.color = color

    def area(self):
        return 0

class Circle(Shape):  # Inherits from Shape
    def __init__(self, color, radius):
        super().__init__(color)
        self.radius = radius

    def area(self):
        return 3.14 * self.radius ** 2

c = Circle("red", 5)
print(c.color)     # red (inherited)
print(c.area())    # 78.5
```

**Key Differences:** C++ supports multiple inheritance. Java allows single inheritance for classes but multiple inheritance through interfaces.

---

### 133. Polymorphism

**Definition:** The ability of objects to take multiple forms, allowing methods to behave differently based on the object type.

**Explanation:** Polymorphism enables a single interface to represent different underlying forms. It includes method overloading (compile-time) and method overriding (runtime polymorphism).

**C++ Example:**
```cpp
class Shape {
public:
    virtual void draw() { cout << "Drawing shape" << endl; }
};

class Circle : public Shape {
public:
    void draw() override { cout << "Drawing circle" << endl; }
};

Shape* shape = new Circle();
shape->draw(); // Outputs: Drawing circle
```

**Java Example:**
```java
class Shape {
    void draw() { System.out.println("Drawing shape"); }
}

class Circle extends Shape {
    void draw() { System.out.println("Drawing circle"); }
}

Shape shape = new Circle();
shape.draw(); // Outputs: Drawing circle
```

**Python Code Example:**
```python
class Animal:
    def __init__(self, name):
        self.name = name

    def sound(self):
        return "..."

class Dog(Animal):
    def sound(self):
        return "Woof!"

class Cat(Animal):
    def sound(self):
        return "Meow!"

def make_sound(animal: Animal):
    print(f"{animal.name}: {animal.sound()}")

make_sound(Dog("Rex"))   # Rex: Woof!
make_sound(Cat("Whiskers"))  # Whiskers: Meow!
```

**Key Differences:** Both support polymorphism. C++ requires 'virtual' keyword for runtime polymorphism. Java methods are virtual by default.

---

### 134. Abstraction

**Definition:** Hiding complex implementation details and showing only essential features of an object.

**Explanation:** Abstraction focuses on what an object does rather than how it does it. It's achieved through abstract classes and interfaces, providing a simplified view of complex systems.

**C++ Example:**
```cpp
class Database {
public:
    virtual void connect() = 0;
    virtual void query(string sql) = 0;
};

class MySQL : public Database {
public:
    void connect() { /* MySQL specific */ }
    void query(string sql) { /* Execute query */ }
};
```

**Java Example:**
```java
abstract class Database {
    abstract void connect();
    abstract void query(String sql);
}

class MySQL extends Database {
    void connect() { /* MySQL specific */ }
    void query(String sql) { /* Execute query */ }
}
```

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class DatabaseConnector(ABC):  # Abstract class hides implementation
    @abstractmethod
    def connect(self):
        pass

    @abstractmethod
    def execute(self, query):
        pass

class MySQLConnector(DatabaseConnector):
    def connect(self):
        print("Connected to MySQL")

    def execute(self, query):
        print(f"MySQL: {query}")

db = MySQLConnector()
db.connect()
db.execute("SELECT * FROM users")
```

**Key Differences:** Both support abstraction through abstract classes and interfaces. Implementation is very similar.

---

### 135. Association

**Definition:** A relationship where objects are independent but can interact with each other.

**Explanation:** Association represents a "uses-a" relationship between classes. Objects can exist independently, and the relationship can be one-to-one, one-to-many, or many-to-many.

**C++ Example:**
```cpp
class Teacher {
    string name;
};

class Student {
    Teacher* teacher; // Association
public:
    void setTeacher(Teacher* t) { teacher = t; }
};
```

**Java Example:**
```java
class Teacher {
    String name;
}

class Student {
    Teacher teacher; // Association
    
    void setTeacher(Teacher t) { teacher = t; }
}
```

**Python Code Example:**
```python
class Teacher:
    def __init__(self, name):
        self.name = name

class Student:
    def __init__(self, name):
        self.name = name
        self.teacher = None  # Association (optional relationship)

    def set_teacher(self, teacher: Teacher):
        self.teacher = teacher

teacher = Teacher("Dr. Smith")
student = Student("Alice")
student.set_teacher(teacher)
print(f"{student.name}'s teacher: {student.teacher.name}")
```

**Key Differences:** No significant difference. Both use references/pointers to establish associations.

---

### 136. Aggregation

**Definition:** A special form of association representing a "has-a" relationship where parts can exist independently of the whole.

**Explanation:** Aggregation implies ownership but not strong lifecycle dependency. The contained object can exist without the container. It's a weaker relationship than composition.

**C++ Example:**
```cpp
class Department {
    string name;
};

class University {
    vector<Department*> departments; // Aggregation
public:
    void addDepartment(Department* d) {
        departments.push_back(d);
    }
};
```

**Java Example:**
```java
class Department {
    String name;
}

class University {
    List<Department> departments = new ArrayList<>();
    
    void addDepartment(Department d) {
        departments.add(d);
    }
}
```

**Python Code Example:**
```python
class Engine:
    def __init__(self, hp):
        self.horsepower = hp

    def start(self):
        print(f"{self.horsepower}hp engine started")

class Car:
    def __init__(self, model, engine: Engine):  # Aggregation
        self.model = model
        self.engine = engine  # Car HAS-A Engine

    def drive(self):
        self.engine.start()
        print(f"{self.model} is moving")

engine = Engine(200)    # Engine exists independently
car = Car("Tesla", engine)
car.drive()
```

**Key Differences:** Implementation is similar. The conceptual difference between aggregation and association is more about design intent than syntax.

---

### 137. Composition

**Definition:** A strong "has-a" relationship where the contained object cannot exist independently of the container.

**Explanation:** Composition represents whole-part relationships with strong lifecycle dependency. When the container is destroyed, its parts are also destroyed. It implies exclusive ownership.

**C++ Example:**
```cpp
class Engine {
    int horsepower;
};

class Car {
    Engine engine; // Composition (by value)
public:
    Car() : engine() {} // Engine created with Car
    // Engine destroyed when Car is destroyed
};
```

**Java Example:**
```java
class Engine {
    int horsepower;
}

class Car {
    private Engine engine = new Engine(); // Composition
    
    // Engine lifecycle tied to Car
}
```

**Python Code Example:**
```python
class Heart:
    def __init__(self):
        print("Heart created")

    def beat(self):
        print("Thump thump")

    def __del__(self):
        print("Heart destroyed")

class Human:  # Composition: Human owns Heart
    def __init__(self, name):
        self.name = name
        self.heart = Heart()  # Created with Human

    def live(self):
        self.heart.beat()

h = Human("Alice")
h.live()
del h  # Heart also destroyed
```

**Key Differences:** C++ can use value semantics (member objects) for true composition. Java uses references but implies ownership through design.

---

### 138. "is-a" Relationship

**Definition:** An inheritance relationship where a subclass is a type of its superclass.

**Explanation:** The "is-a" relationship is established through inheritance. It means the derived class is a specialized version of the base class and can be used wherever the base class is expected.

**C++ Example:**
```cpp
class Vehicle {};

class Car : public Vehicle {}; // Car IS-A Vehicle

Vehicle* v = new Car(); // Valid
```

**Java Example:**
```java
class Vehicle {}

class Car extends Vehicle {} // Car IS-A Vehicle

Vehicle v = new Car(); // Valid
```

**Python Code Example:**
```python
class Animal:
    def breathe(self):
        print("Breathing")

class Dog(Animal):  # Dog IS-A Animal
    def bark(self):
        print("Woof!")

dog = Dog()

# Verify is-a relationship
print(isinstance(dog, Dog))    # True
print(isinstance(dog, Animal)) # True (Dog is-a Animal)
print(issubclass(Dog, Animal)) # True
```

**Key Differences:** Both languages implement "is-a" through inheritance with similar semantics.

---

### 139. "has-a" Relationship

**Definition:** A composition or aggregation relationship where one class contains another as a member.

**Explanation:** The "has-a" relationship represents ownership or association. A class has a member of another class type, either through composition (strong) or aggregation (weak).

**C++ Example:**
```cpp
class Engine {};

class Car {
    Engine engine; // Car HAS-A Engine
};
```

**Java Example:**
```java
class Engine {}

class Car {
    Engine engine; // Car HAS-A Engine
}
```

**Python Code Example:**
```python
class Wheel:
    def __init__(self, size):
        self.size = size

class Car:  # Car HAS-A Wheel (has-a relationship)
    def __init__(self, model):
        self.model = model
        self.wheels = [Wheel(18) for _ in range(4)]  # 4 wheels

    def describe(self):
        print(f"{self.model} has {len(self.wheels)} wheels of size {self.wheels[0].size}")

car = Car("BMW")
car.describe()  # BMW has 4 wheels of size 18
```

**Key Differences:** Implementation is nearly identical. Both use member variables to establish "has-a" relationships.

---

### 140. "is-kind-of" Relationship

**Definition:** A classification relationship similar to inheritance but emphasizing categorization.

**Explanation:** This relationship is essentially another way to describe inheritance, emphasizing that the subclass is a specific kind or category of the superclass.

**C++ Example:**
```cpp
class Fruit {};

class Apple : public Fruit {}; // Apple IS-KIND-OF Fruit
```

**Java Example:**
```java
class Fruit {}

class Apple extends Fruit {} // Apple IS-KIND-OF Fruit
```

**Python Code Example:**
```python
class Fruit:
    def taste(self):
        return "sweet"

class Apple(Fruit):  # Apple is-kind-of Fruit
    def color(self):
        return "red"

class GrannySmith(Apple):  # GrannySmith is-kind-of Apple (and Fruit)
    def color(self):
        return "green"

apple = GrannySmith()
print(isinstance(apple, Fruit))       # True (is-kind-of Fruit)
print(isinstance(apple, Apple))       # True
print(apple.taste())                   # sweet (inherited)
```

**Key Differences:** No technical difference; it's a semantic interpretation of inheritance in both languages.

---

### 141. Hierarchical Classification

**Definition:** Organizing classes in a tree-like structure based on generalization and specialization.

**Explanation:** Hierarchical classification creates a taxonomy of classes from general (abstract) to specific (concrete). Higher levels contain common features, while lower levels add specialization.

**C++ Example:**
```cpp
class Animal {};
class Mammal : public Animal {};
class Dog : public Mammal {};
class Cat : public Mammal {};
// Hierarchy: Animal -> Mammal -> Dog/Cat
```

**Java Example:**
```java
class Animal {}
class Mammal extends Animal {}
class Dog extends Mammal {}
class Cat extends Mammal {}
// Hierarchy: Animal -> Mammal -> Dog/Cat
```

**Python Code Example:**
```python
class LivingThing:
    def breathe(self): print("Breathing")

class Animal(LivingThing):
    def move(self): print("Moving")

class Mammal(Animal):
    def nurse_young(self): print("Nursing")

class Dog(Mammal):
    def bark(self): print("Woof!")

class Cat(Mammal):
    def meow(self): print("Meow!")

dog = Dog()
dog.breathe()    # From LivingThing
dog.move()       # From Animal
dog.nurse_young()  # From Mammal
dog.bark()       # From Dog
```

**Key Differences:** Both support class hierarchies through inheritance with similar structures.

---

### 142. Code Reusability

**Definition:** The ability to use existing code in new contexts without rewriting it.

**Explanation:** Code reusability reduces duplication and development time. It's achieved through inheritance, composition, interfaces, and generic programming, allowing tested code to be leveraged in multiple places.

**C++ Example:**
```cpp
class Logger {
public:
    void log(string msg) {
        cout << "[LOG] " << msg << endl;
    }
};

class Application {
    Logger logger; // Reusing Logger
public:
    void run() {
        logger.log("Application started");
    }
};
```

**Java Example:**
```java
class Logger {
    void log(String msg) {
        System.out.println("[LOG] " + msg);
    }
}

class Application {
    Logger logger = new Logger(); // Reusing Logger
    
    void run() {
        logger.log("Application started");
    }
}
```

**Python Code Example:**
```python
class Logger:  # Reusable component
    def log(self, message):
        print(f"[LOG] {message}")

class DatabaseManager:
    def __init__(self):
        self.logger = Logger()  # Reuse Logger

    def connect(self):
        self.logger.log("Connecting to database")

class FileManager:
    def __init__(self):
        self.logger = Logger()  # Reuse same Logger

    def open_file(self, name):
        self.logger.log(f"Opening {name}")

db = DatabaseManager()
db.connect()
fm = FileManager()
fm.open_file("data.txt")
```

**Key Differences:** Both achieve code reusability through similar OOP mechanisms.

---

### 143. Data Hiding

**Definition:** Restricting access to object data by making it private and providing controlled access through methods.

**Explanation:** Data hiding protects internal state from unauthorized access and modification. It's a key aspect of encapsulation, ensuring data integrity by controlling how data is accessed and modified.

**C++ Example:**
```cpp
class Account {
private:
    double balance; // Hidden data
public:
    void deposit(double amt) {
        if (amt > 0) balance += amt;
    }
};
```

**Java Example:**
```java
class Account {
    private double balance; // Hidden data
    
    public void deposit(double amt) {
        if (amt > 0) balance += amt;
    }
}
```

**Python Code Example:**
```python
class Employee:
    def __init__(self, name, salary):
        self.__name = name      # Hidden (private)
        self.__salary = salary  # Hidden (private)

    def get_name(self):
        return self.__name

    def get_salary(self):
        return self.__salary

    def give_raise(self, percent):
        self.__salary *= (1 + percent / 100)

emp = Employee("Alice", 50000)
print(emp.get_name())    # Alice
emp.give_raise(10)
print(emp.get_salary())  # 55000.0
```

**Key Differences:** Both use private access modifiers for data hiding with identical semantics.

---

### 144. Information Hiding

**Definition:** Concealing implementation details and internal workings of a module from external code.

**Explanation:** Information hiding is broader than data hiding, encompassing implementation details, algorithms, and internal structures. It allows internal changes without affecting external code that uses the module.

**C++ Example:**
```cpp
class Encryptor {
private:
    string algorithm; // Hidden implementation detail
    void prepareKey() {} // Hidden method
public:
    string encrypt(string data) {
        prepareKey();
        // Encryption logic hidden
        return data;
    }
};
```

**Java Example:**
```java
class Encryptor {
    private String algorithm; // Hidden implementation
    
    private void prepareKey() {} // Hidden method
    
    public String encrypt(String data) {
        prepareKey();
        // Encryption logic hidden
        return data;
    }
}
```

**Python Code Example:**
```python
class SmartTV:
    def __init__(self):
        self.__internal_buffer = []      # Hidden implementation
        self.__hardware_interface = None  # Hidden detail

    def turn_on(self):  # Public interface
        self.__initialize_hardware()
        print("TV is on")

    def __initialize_hardware(self):  # Hidden implementation
        self.__hardware_interface = "GPU active"
        print("Hardware initialized")

tv = SmartTV()
tv.turn_on()   # Simple interface
# tv.__initialize_hardware()  # AttributeError (hidden)
```

**Key Differences:** Both implement information hiding through private members and methods identically.

---

### 145. Class Abstraction

**Definition:** Separating the interface (what a class does) from implementation (how it does it).

**Explanation:** Class abstraction defines public contracts while hiding implementation complexity. Users interact with the class through its public interface without needing to understand internal mechanics.

**C++ Example:**
```cpp
class Stack {
private:
    int arr[100];
    int top;
public:
    void push(int x) { arr[++top] = x; }
    int pop() { return arr[top--]; }
    // Implementation hidden from users
};
```

**Java Example:**
```java
class Stack {
    private int[] arr = new int[100];
    private int top;
    
    public void push(int x) { arr[++top] = x; }
    public int pop() { return arr[top--]; }
    // Implementation hidden from users
}
```

**Python Code Example:**
```python
from abc import ABC, abstractmethod

class Stack(ABC):  # Abstract class defines the "what"
    @abstractmethod
    def push(self, item):
        pass

    @abstractmethod
    def pop(self):
        pass

    @abstractmethod
    def peek(self):
        pass

class ListStack(Stack):  # Concrete "how"
    def __init__(self):
        self._items = []

    def push(self, item):
        self._items.append(item)

    def pop(self):
        return self._items.pop()

    def peek(self):
        return self._items[-1]

s = ListStack()
s.push(1)
s.push(2)
print(s.peek())  # 2
```

**Key Differences:** Both achieve class abstraction through encapsulation with similar approaches.

---

## Summary: Object-Oriented Programming Concepts Guide

This comprehensive guide covers essential OOP concepts including exception handling mechanisms, interface design patterns, and fundamental object-oriented design principles. The examples demonstrate how these concepts are implemented in both C++ and Java, highlighting similarities and key differences between the languages.

**Key Takeaways:**
- Exception handling provides robust error management with language-specific features
- Interfaces and abstract classes enable flexible design through contracts and polymorphism
- OOP principles (encapsulation, inheritance, polymorphism, abstraction) form the foundation of maintainable software
- Relationships (association, aggregation, composition) model real-world interactions between objects
- Both C++ and Java support core OOP concepts with syntax and semantic variations

## Object Methods and Utilities

### Table of Contents
146. [equals Method](#146-equals-method)
147. [toString Method](#147-tostring-method)
148. [clone() Method](#148-clone-method)
149. [compareTo Method](#149-compareto-method)
150. [Wrapper Class](#150-wrapper-class)
151. [Integer](#151-integer)
152. [Double](#152-double)
153. [Autoboxing](#153-autoboxing)
154. [Autounboxing](#154-autounboxing)

---

### 146. equals Method

**Definition:** A method used to compare two objects for equality based on their content rather than memory reference.

**Explanation:** The equals method checks whether two objects are logically equivalent. By default, it compares memory addresses, but it's typically overridden to compare the actual data within objects. This allows meaningful comparisons of object state.

**C++ Code Example:**
```cpp
class Person {
    string name;
    int age;
public:
    bool operator==(const Person& other) const {
        return name == other.name && age == other.age;
    }
};

// Usage
Person p1{"John", 25};
Person p2{"John", 25};
if (p1 == p2) { /* equal */ }
```

**Java Code Example:**
```java
class Person {
    String name;
    int age;
    
    @Override
    public boolean equals(Object obj) {
        if (this == obj) return true;
        if (obj == null || getClass() != obj.getClass()) return false;
        Person other = (Person) obj;
        return age == other.age && name.equals(other.name);
    }
}

// Usage
Person p1 = new Person("John", 25);
Person p2 = new Person("John", 25);
if (p1.equals(p2)) { /* equal */ }
```

**Python Code Example:**
```python
class Point:
    def __init__(self, x, y):
        self.x = x
        self.y = y

    def __eq__(self, other):  # Equivalent to equals()
        if not isinstance(other, Point):
            return False
        return self.x == other.x and self.y == other.y

    def __hash__(self):  # Required when __eq__ is overridden
        return hash((self.x, self.y))

p1 = Point(3, 4)
p2 = Point(3, 4)
p3 = Point(1, 2)
print(p1 == p2)  # True
print(p1 == p3)  # False
```

**Key Differences:** In C++, operator overloading (==) is used for equality comparison. In Java, the equals() method is inherited from Object class and should be overridden. Java also requires hashCode() to be overridden when equals() is overridden.

---

### 147. toString Method

**Definition:** A method that returns a string representation of an object.

**Explanation:** The toString method converts an object into a human-readable string format. This is useful for debugging, logging, and displaying object information. It provides a textual description of the object's state.

**C++ Code Example:**
```cpp
class Person {
    string name;
    int age;
public:
    string toString() const {
        return "Person{name='" + name + "', age=" + to_string(age) + "}";
    }
};

// Usage
Person p{"Alice", 30};
cout << p.toString() << endl;
```

**Java Code Example:**
```java
class Person {
    String name;
    int age;
    
    @Override
    public String toString() {
        return "Person{name='" + name + "', age=" + age + "}";
    }
}

// Usage
Person p = new Person("Alice", 30);
System.out.println(p.toString());
// or simply: System.out.println(p);
```

**Python Code Example:**
```python
class Student:
    def __init__(self, name, gpa):
        self.name = name
        self.gpa = gpa

    def __str__(self):   # Called by print() and str()
        return f"Student[name={self.name}, gpa={self.gpa}]"

    def __repr__(self):  # Called by repr() and in containers
        return f"Student('{self.name}', {self.gpa})"

s = Student("Alice", 3.8)
print(s)          # Student[name=Alice, gpa=3.8]
print(repr(s))    # Student('Alice', 3.8)
print(str(s))     # Student[name=Alice, gpa=3.8]
```

**Key Differences:** In C++, toString() is a custom method you define. In Java, toString() is inherited from Object class and automatically called when printing objects. Java's System.out.println() implicitly calls toString().

---

### 148. clone() Method

**Definition:** A method that creates and returns a copy of an object.

**Explanation:** The clone method produces a duplicate of an object. It can perform shallow copying (copying references) or deep copying (copying referenced objects too). This allows creating independent copies of objects without affecting the original.

**C++ Code Example:**
```cpp
class Person {
    string name;
    int age;
public:
    Person* clone() const {
        return new Person(*this); // copy constructor
    }
};

// Usage
Person* p1 = new Person{"Bob", 28};
Person* p2 = p1->clone();
```

**Java Code Example:**
```java
class Person implements Cloneable {
    String name;
    int age;
    
    @Override
    public Person clone() throws CloneNotSupportedException {
        return (Person) super.clone();
    }
}

// Usage
Person p1 = new Person("Bob", 28);
Person p2 = p1.clone();
```

**Python Code Example:**
```python
import copy

class Config:
    def __init__(self, settings):
        self.settings = settings.copy()

    def __copy__(self):  # Shallow clone
        return Config(self.settings)

    def __deepcopy__(self, memo):  # Deep clone
        return Config(copy.deepcopy(self.settings, memo))

c1 = Config({"theme": "dark", "lang": "en"})
c2 = copy.copy(c1)       # Shallow clone
c3 = copy.deepcopy(c1)   # Deep clone
c2.settings["theme"] = "light"
print(c1.settings["theme"])  # dark (c1 unaffected by shallow)
```

**Key Differences:** C++ uses copy constructors naturally. Java requires implementing Cloneable interface and handling CloneNotSupportedException. Java's default clone() performs shallow copy; deep copy requires manual implementation.

---

### 149. compareTo Method

**Definition:** A method that compares two objects to determine their ordering.

**Explanation:** The compareTo method returns a negative integer, zero, or positive integer if the current object is less than, equal to, or greater than the specified object. This enables sorting and ordering of objects in collections.

**C++ Code Example:**
```cpp
class Person {
    string name;
    int age;
public:
    int compareTo(const Person& other) const {
        if (age < other.age) return -1;
        if (age > other.age) return 1;
        return 0;
    }
};

// Usage
Person p1{"Alice", 25};
Person p2{"Bob", 30};
int result = p1.compareTo(p2); // returns -1
```

**Java Code Example:**
```java
class Person implements Comparable<Person> {
    String name;
    int age;
    
    @Override
    public int compareTo(Person other) {
        return Integer.compare(this.age, other.age);
    }
}

// Usage
Person p1 = new Person("Alice", 25);
Person p2 = new Person("Bob", 30);
int result = p1.compareTo(p2); // returns -1
```

**Python Code Example:**
```python
from functools import total_ordering

@total_ordering
class Temperature:
    def __init__(self, celsius):
        self.celsius = celsius

    def compare_to(self, other):  # compareTo equivalent
        if self.celsius < other.celsius:
            return -1
        elif self.celsius > other.celsius:
            return 1
        return 0

    def __eq__(self, other):
        return self.celsius == other.celsius

    def __lt__(self, other):
        return self.celsius < other.celsius

t1 = Temperature(100)
t2 = Temperature(50)
print(t1.compare_to(t2))   # 1 (t1 > t2)
print(sorted([t1, t2]))     # Sorted by temperature
```

**Key Differences:** C++ doesn't have a built-in Comparable interface; compareTo is a custom method. Java has the Comparable<T> interface that must be implemented. Java's collections use compareTo for natural ordering automatically.

---

### 150. Wrapper Class

**Definition:** A class that encapsulates a primitive data type as an object.

**Explanation:** Wrapper classes convert primitive types into objects, allowing them to be used where objects are required (like in collections). They provide utility methods for conversion and manipulation of primitive values.

**C++ Code Example:**
```cpp
// C++ doesn't have wrapper classes in the same way
// Standard types are directly usable in templates
template<typename T>
class Wrapper {
    T value;
public:
    Wrapper(T v) : value(v) {}
    T getValue() const { return value; }
};

// Usage
Wrapper<int> num(42);
```

**Java Code Example:**
```java
// Java has built-in wrapper classes
Integer num = new Integer(42); // deprecated
Integer num2 = Integer.valueOf(42); // preferred

// Usage
int primitive = num2.intValue();
String str = num2.toString();
```

**Python Code Example:**
```python
# Python's int, float, str etc. are already objects (no separate wrappers)
# int is the "wrapper" for integers in Python

x = 42              # int object
y = int("42")       # Convert string to int
z = int(3.14)       # Convert float to int

print(type(x))              # <class 'int'>
print(x.bit_length())       # 6 (method on int object)
print(int.from_bytes(b'\x00\x10', 'big'))  # 16

# Python numbers have useful methods
print((255).to_bytes(2, 'big'))  # b'\x00\xff'
```

**Key Differences:** C++ doesn't need wrapper classes as primitives can be used directly in templates. Java requires wrapper classes (Integer, Double, etc.) because collections can only store objects, not primitives. Java wrappers are immutable.

---

### 151. Integer

**Definition:** A wrapper class that encapsulates an int primitive value as an object.

**Explanation:** The Integer class wraps the primitive int type, providing methods for conversion, parsing, and arithmetic operations. It allows int values to be used in contexts requiring objects and provides utility functions like parsing strings to integers.

**C++ Code Example:**
```cpp
// C++ uses int directly, but here's a wrapper approach
class Integer {
    int value;
public:
    Integer(int v) : value(v) {}
    int intValue() const { return value; }
    static int parseInt(const string& s) {
        return stoi(s);
    }
};

// Usage
Integer num(100);
int val = Integer::parseInt("42");
```

**Java Code Example:**
```java
// Java's built-in Integer class
Integer num = Integer.valueOf(100);
int val = num.intValue();

// Parsing and utility methods
int parsed = Integer.parseInt("42");
int max = Integer.MAX_VALUE;
String binary = Integer.toBinaryString(10);
```

**Python Code Example:**
```python
# Python's int is the equivalent of Java's Integer wrapper

x = int(42)         # Integer object
y = int("FF", 16)   # From hex string -> 255 in decimal

print(x.bit_length())  # Number of bits needed
print(abs(-42))        # 42
print(max(1, 2, 3))    # 3
print(min(1, 2, 3))    # 1

# Convert between types (like Integer methods)
print(bin(42))   # '0b101010'
print(hex(255))  # '0xff'
print(oct(8))    # '0o10'
```

**Key Differences:** C++ uses int primitives directly without wrappers. Java's Integer class is immutable and provides extensive utility methods like parseInt(), valueOf(), and constants like MAX_VALUE. Java requires Integer for generic collections.

---

### 152. Double

**Definition:** A wrapper class that encapsulates a double primitive value as an object.

**Explanation:** The Double class wraps the primitive double type, providing methods for floating-point operations, conversions, and special value handling (NaN, infinity). It enables double values to be used as objects in collections and provides parsing capabilities.

**C++ Code Example:**
```cpp
// C++ uses double directly
class Double {
    double value;
public:
    Double(double v) : value(v) {}
    double doubleValue() const { return value; }
    static double parseDouble(const string& s) {
        return stod(s);
    }
};

// Usage
Double num(3.14);
double val = Double::parseDouble("2.718");
```

**Java Code Example:**
```java
// Java's built-in Double class
Double num = Double.valueOf(3.14);
double val = num.doubleValue();

// Parsing and special values
double parsed = Double.parseDouble("2.718");
boolean isNaN = Double.isNaN(val);
double inf = Double.POSITIVE_INFINITY;
```

**Python Code Example:**
```python
# Python's float is the equivalent of Java's Double wrapper

x = float(3.14)
y = float("3.14")    # From string
z = float(42)        # From int

print(type(x))             # <class 'float'>
print(round(x, 1))         # 3.1
print(abs(-3.14))          # 3.14

import math
print(math.isnan(float('nan')))   # True
print(math.isinf(float('inf')))   # True
print(math.floor(3.7))            # 3
print(math.ceil(3.2))             # 4
```

**Key Differences:** C++ uses double primitives without wrappers. Java's Double class provides methods for special floating-point values (NaN, infinity) and is required for using doubles in generic collections. Both languages handle floating-point similarly at the primitive level.

---

### 153. Autoboxing

**Definition:** The automatic conversion of primitive types to their corresponding wrapper class objects.

**Explanation:** Autoboxing is a compiler feature that automatically converts primitives to objects when needed, such as when adding primitives to collections. This eliminates the need for explicit wrapper object creation and makes code more readable.

**C++ Code Example:**
```cpp
// C++ doesn't have autoboxing in the Java sense
// Templates work directly with primitives
template<typename T>
void add(vector<T>& vec, T value) {
    vec.push_back(value);
}

// Usage - primitives work directly
vector<int> numbers;
numbers.push_back(42); // no boxing needed
```

**Java Code Example:**
```java
// Java automatically boxes primitives
List<Integer> numbers = new ArrayList<>();
numbers.add(42); // int is autoboxed to Integer

// Works seamlessly
int x = 10;
Integer y = x; // autoboxing: int to Integer
```

**Python Code Example:**
```python
# Python has no distinction between primitives and objects
# All values are objects - "autoboxing" is automatic

x = 42      # int object (already "boxed")
y = 3.14    # float object
z = True    # bool object

# Everything can be stored in a list (no boxing needed)
mixed = [42, 3.14, True, "hello"]
print([type(v).__name__ for v in mixed])

# No performance overhead for boxing/unboxing
nums = [1, 2, 3, 4, 5]  # list of int objects
total = sum(nums)         # Works seamlessly
print(total)  # 15
```

**Key Differences:** C++ doesn't have autoboxing because templates work directly with any type including primitives. Java introduced autoboxing in Java 5 to simplify working with wrapper classes, automatically converting primitives to objects when needed.

---

### 154. Autounboxing

**Definition:** The automatic conversion of wrapper class objects back to their corresponding primitive types.

**Explanation:** Autounboxing is the reverse of autoboxing, automatically extracting the primitive value from a wrapper object when needed. This occurs in arithmetic operations, comparisons, or assignments to primitive variables, making code cleaner.

**C++ Code Example:**
```cpp
// C++ doesn't need unboxing
// Templates preserve the original type
vector<int> numbers = {1, 2, 3};
int sum = 0;
for (int n : numbers) {
    sum += n; // direct use of int
}
```

**Java Code Example:**
```java
// Java automatically unboxes wrapper objects
Integer num = 100;
int x = num; // autounboxing: Integer to int

// In operations
Integer a = 10;
Integer b = 20;
int sum = a + b; // both autounboxed for addition
```

**Python Code Example:**
```python
# Python has no unboxing - values are always objects
# Arithmetic works directly on objects

x = int(42)    # "Boxed" int
y = int(10)

result = x + y  # Direct arithmetic (no unboxing needed)
print(result)   # 52
print(type(result))  # <class 'int'>

# Python int is immutable, so all operations return new objects
a = 5
b = a + 3   # Returns new int object
print(id(a) == id(b))  # False (different objects)
```

**Key Differences:** C++ doesn't require unboxing since primitives aren't boxed. Java autounboxing can cause NullPointerException if the wrapper object is null. This is a Java-specific feature that pairs with autoboxing.

---

## Advanced Features

### Table of Contents
155. [Inner Class](#155-inner-class)
156. [Anonymous Inner Class](#156-anonymous-inner-class)
157. [Lambda Expression](#157-lambda-expression)
158. [UML Class Diagram](#158-uml-class-diagram)
159. [State (attributes)](#159-state-attributes)
160. [Behavior (methods)](#160-behavior-methods)
161. [Identity (unique name)](#161-identity-unique-name)
162. [Object Identity](#162-object-identity)
163. [Black Box](#163-black-box)
164. [Contract (class contract)](#164-contract-class-contract)
165. [No-arg Constructor](#165-no-arg-constructor)
166. [Protective Shield](#166-protective-shield)
167. [Controlled Interface](#167-controlled-interface)
168. [Formal Generic Type Parameter](#168-formal-generic-type-parameter)
169. [Generic Type Argument](#169-generic-type-argument)

---

### 155. Inner Class

**Definition:** A class defined within another class, having access to the outer class's members.

**Explanation:** Inner classes are nested classes that have a relationship with an instance of the outer class. They can access all members of the outer class including private ones. Inner classes are useful for logically grouping classes that are only used in one place and for implementing helper functionality.

**C++ Code Example:**
```cpp
class Outer {
    int outerData = 10;
    
    class Inner {
        Outer* outer;
    public:
        Inner(Outer* o) : outer(o) {}
        void display() {
            cout << outer->outerData << endl;
        }
    };
    
public:
    Inner* createInner() {
        return new Inner(this);
    }
};

// Usage
Outer outer;
auto inner = outer.createInner();
inner->display();
```

**Java Code Example:**
```java
class Outer {
    private int outerData = 10;
    
    class Inner {
        void display() {
            System.out.println(outerData); // direct access
        }
    }
    
    public Inner createInner() {
        return new Inner();
    }
}

// Usage
Outer outer = new Outer();
Outer.Inner inner = outer.createInner();
inner.display();
```

**Python Code Example:**
```python
class Outer:
    class Inner:  # Inner class
        def __init__(self, value):
            self.value = value

        def display(self):
            print(f"Inner value: {self.value}")

    def __init__(self):
        self.inner = Outer.Inner(42)  # Create inner class instance

    def use_inner(self):
        self.inner.display()

obj = Outer()
obj.use_inner()

# Create inner class directly
inner_obj = Outer.Inner(100)
inner_obj.display()
```

**Key Differences:** Java inner classes have implicit reference to outer class instance and automatic access to outer members. C++ nested classes require explicit pointer to outer class and don't have automatic access privileges. Java's syntax is cleaner for inner class instantiation.

---

### 156. Anonymous Inner Class

**Definition:** A nameless inner class defined and instantiated in a single expression.

**Explanation:** Anonymous inner classes are used to create one-time-use classes without formally declaring them. They're commonly used to implement interfaces or extend classes inline, particularly for event handlers or callbacks. They provide a concise way to create objects with custom behavior.

**C++ Code Example:**
```cpp
// C++ doesn't have anonymous classes
// Use lambda or named local class
class Button {
public:
    void onClick(function<void()> handler) {
        handler();
    }
};

// Usage with lambda (similar concept)
Button btn;
btn.onClick([]() {
    cout << "Button clicked" << endl;
});
```

**Java Code Example:**
```java
interface ClickHandler {
    void onClick();
}

class Button {
    void setClickHandler(ClickHandler handler) {
        handler.onClick();
    }
}

// Usage with anonymous inner class
Button btn = new Button();
btn.setClickHandler(new ClickHandler() {
    @Override
    public void onClick() {
        System.out.println("Button clicked");
    }
});
```

**Python Code Example:**
```python
# Python uses lambda or on-the-fly class creation

class Button:
    def __init__(self, on_click):
        self.on_click = on_click

    def click(self):
        self.on_click()

# Lambda as anonymous function (simplest case)
btn = Button(on_click=lambda: print("Button clicked!"))
btn.click()

# type() for anonymous class creation
AnonClass = type('AnonClass', (), {'greet': lambda self: print("Hello!")})
obj = AnonClass()
obj.greet()
```

**Key Differences:** C++ doesn't have anonymous inner classes; lambdas serve a similar purpose. Java anonymous inner classes can implement interfaces or extend classes inline. Java 8+ lambdas have largely replaced anonymous inner classes for functional interfaces.

---

### 157. Lambda Expression

**Definition:** A concise way to represent an anonymous function that can be passed as an argument.

**Explanation:** Lambda expressions provide a clear and compact way to represent single-method interfaces or function objects. They eliminate the need for anonymous inner classes when implementing functional interfaces, making code more readable and functional in style.

**C++ Code Example:**
```cpp
#include <algorithm>
#include <vector>

// Lambda expression
vector<int> numbers = {3, 1, 4, 1, 5};
sort(numbers.begin(), numbers.end(), 
     [](int a, int b) { return a < b; });

// With capture
int threshold = 3;
auto filtered = count_if(numbers.begin(), numbers.end(),
    [threshold](int n) { return n > threshold; });
```

**Java Code Example:**
```java
import java.util.*;

// Lambda expression
List<Integer> numbers = Arrays.asList(3, 1, 4, 1, 5);
numbers.sort((a, b) -> a - b);

// With streams
int threshold = 3;
long count = numbers.stream()
    .filter(n -> n > threshold)
    .count();
```

**Python Code Example:**
```python
# Python has native lambda support

square = lambda x: x ** 2
add = lambda x, y: x + y

print(square(5))    # 25
print(add(3, 4))    # 7

# Lambdas with higher-order functions
numbers = [1, 2, 3, 4, 5]
squared = list(map(lambda x: x ** 2, numbers))
evens = list(filter(lambda x: x % 2 == 0, numbers))
print(squared)  # [1, 4, 9, 16, 25]
print(evens)    # [2, 4]
```

**Key Differences:** C++ lambdas have explicit capture clauses ([], [=], [&]) for accessing outer variables. Java lambdas capture variables implicitly but they must be effectively final. C++ lambdas are more flexible with mutable captures and return type specification.

---

### 158. UML Class Diagram

**Definition:** A visual representation of classes, their attributes, methods, and relationships in a system.

**Explanation:** UML Class Diagrams show the static structure of a system by illustrating classes with their attributes and methods, along with relationships like inheritance, association, and dependency. They help in designing and documenting object-oriented systems before implementation.

**C++ Code Example:**
```cpp
// Representing this UML:
// Person: -name: string, -age: int, +getName(): string
class Person {
private:
    string name;
    int age;
public:
    string getName() const { return name; }
};

// Inheritance relationship
class Student : public Person {
private:
    string studentId;
};
```

**Java Code Example:**
```java
// Representing this UML:
// Person: -name: String, -age: int, +getName(): String
class Person {
    private String name;
    private int age;
    
    public String getName() { return name; }
}

// Inheritance relationship
class Student extends Person {
    private String studentId;
}
```

**Python Code Example:**
```python
# Demonstrating UML Class Diagram concepts in Python

class Person:  # Class box: Person
    # Attributes (state)
    name: str
    age: int

    def __init__(self, name: str, age: int):
        self.name = name    # + name: str (public)
        self._id = 0        # - id: int (protected)
        self.__secret = ""  # - secret: str (private)

    def greet(self) -> str:     # + greet(): str
        return f"Hello, {self.name}"

    def _validate(self) -> bool:  # # _validate(): bool (protected)
        return self.age >= 0
```

**Key Differences:** Both languages represent UML diagrams similarly. C++ uses public/private/protected inheritance which adds complexity to UML representation. Java's single inheritance and interface implementation are more straightforward to diagram. Notation is language-agnostic.

---

### 159. State (attributes)

**Definition:** The data or properties that define the current condition of an object.

**Explanation:** State represents the values stored in an object's fields or attributes at any given time. It captures what an object knows about itself. The state can change over time through method calls, and different objects of the same class can have different states.

**C++ Code Example:**
```cpp
class BankAccount {
private:
    double balance;  // state
    string owner;    // state
    bool isActive;   // state
    
public:
    void deposit(double amount) {
        balance += amount; // changing state
    }
};

// Two objects, different states
BankAccount acc1; // balance=0
BankAccount acc2; // balance=0
```

**Java Code Example:**
```java
class BankAccount {
    private double balance;  // state
    private String owner;    // state
    private boolean isActive; // state
    
    public void deposit(double amount) {
        balance += amount; // changing state
    }
}

// Two objects, different states
BankAccount acc1 = new BankAccount(); // balance=0
BankAccount acc2 = new BankAccount(); // balance=0
```

**Python Code Example:**
```python
class Car:
    # State is defined by instance attributes
    def __init__(self, make, model, year):
        self.make = make      # State: manufacturer
        self.model = model    # State: model name
        self.year = year      # State: year
        self.speed = 0        # State: current speed
        self.is_running = False  # State: engine status

    def get_state(self):
        return {
            "make": self.make,
            "model": self.model,
            "speed": self.speed,
            "running": self.is_running
        }

car = Car("Toyota", "Camry", 2023)
print(car.get_state())
```

**Key Differences:** No significant difference between C++ and Java for representing state. Both use member variables/fields. Java fields are automatically initialized to default values (0, null, false), while C++ members may contain garbage values if not initialized.

---

### 160. Behavior (methods)

**Definition:** The actions or operations that an object can perform, defined by its methods.

**Explanation:** Behavior defines what an object can do through its methods. Methods operate on the object's state and define the object's functionality. Behavior is shared among all instances of a class, though the results may differ based on each object's state.

**C++ Code Example:**
```cpp
class Dog {
    string name;
    
public:
    // Behaviors (methods)
    void bark() {
        cout << name << " says: Woof!" << endl;
    }
    
    void eat(string food) {
        cout << name << " is eating " << food << endl;
    }
};

// Usage
Dog dog;
dog.bark();  // behavior
dog.eat("bone"); // behavior
```

**Java Code Example:**
```java
class Dog {
    private String name;
    
    // Behaviors (methods)
    public void bark() {
        System.out.println(name + " says: Woof!");
    }
    
    public void eat(String food) {
        System.out.println(name + " is eating " + food);
    }
}

// Usage
Dog dog = new Dog();
dog.bark();  // behavior
dog.eat("bone"); // behavior
```

**Python Code Example:**
```python
class Robot:
    def __init__(self, name):
        self.name = name
        self.energy = 100  # State

    # Behaviors (methods)
    def move(self, direction):  # Behavior
        self.energy -= 10
        print(f"{self.name} moves {direction}")

    def charge(self):           # Behavior
        self.energy = 100
        print(f"{self.name} is charging")

    def work(self, task):       # Behavior
        self.energy -= 20
        print(f"{self.name} working on: {task}")

robot = Robot("R2D2")
robot.move("forward")
robot.work("assembly")
```

**Key Differences:** No significant difference in representing behavior. Both languages use methods. C++ has const methods to indicate behavior that doesn't modify state. Java doesn't have this distinction but uses final for variables and methods.

---

### 161. Identity (unique name)

**Definition:** The unique characteristic that distinguishes one object from another, typically its memory address or reference.

**Explanation:** Identity means each object is unique and can be distinguished from other objects even if they have identical state. In programming, identity is usually represented by the object's memory address. Two objects can have the same values but different identities.

**C++ Code Example:**
```cpp
class Person {
    string name;
};

// Two objects with same state but different identity
Person* p1 = new Person{"Alice"};
Person* p2 = new Person{"Alice"};

// Different identities (memory addresses)
cout << p1 << endl; // e.g., 0x7fff5fbff8a0
cout << p2 << endl; // e.g., 0x7fff5fbff8b0
bool sameIdentity = (p1 == p2); // false
```

**Java Code Example:**
```java
class Person {
    String name;
}

// Two objects with same state but different identity
Person p1 = new Person("Alice");
Person p2 = new Person("Alice");

// Different identities (references)
System.out.println(System.identityHashCode(p1));
System.out.println(System.identityHashCode(p2));
boolean sameIdentity = (p1 == p2); // false
```

**Python Code Example:**
```python
class Person:
    _id_counter = 0

    def __init__(self, name):
        Person._id_counter += 1
        self.id = Person._id_counter  # Unique identity
        self.name = name

    def __repr__(self):
        return f"Person(id={self.id}, name={self.name})"

p1 = Person("Alice")
p2 = Person("Bob")
p3 = Person("Alice")  # Same name but different identity

print(p1)  # Person(id=1, name=Alice)
print(p2)  # Person(id=2, name=Bob)
print(p3)  # Person(id=3, name=Alice)
print(p1 is p3)  # False (different objects)
```

**Key Differences:** C++ uses memory addresses directly for identity comparison with pointer equality. Java uses references and provides System.identityHashCode() to get identity. The == operator compares identity in both languages (memory address in C++, reference in Java).

---

### 162. Object Identity

**Definition:** The property that makes each object instance unique and distinguishable from others.

**Explanation:** Object identity is what makes an object distinct, regardless of its state. Even if two objects have identical attributes, they remain separate entities with unique identities. This concept is fundamental for comparing objects by reference versus by value.

**C++ Code Example:**
```cpp
class Car {
    string model;
};

Car c1{"Tesla"};
Car c2{"Tesla"};

// Identity comparison (by address)
bool sameObject = (&c1 == &c2); // false

// For pointers
Car* p1 = &c1;
Car* p2 = &c1;
bool sameIdentity = (p1 == p2); // true
```

**Java Code Example:**
```java
class Car {
    String model;
}

Car c1 = new Car("Tesla");
Car c2 = new Car("Tesla");

// Identity comparison (by reference)
boolean sameObject = (c1 == c2); // false

Car r1 = c1;
Car r2 = c1;
boolean sameIdentity = (r1 == r2); // true
```

**Python Code Example:**
```python
class Singleton:
    _instance = None

    def __new__(cls):
        if cls._instance is None:
            cls._instance = super().__new__(cls)
        return cls._instance

a = Singleton()
b = Singleton()

print(a is b)     # True (same object)
print(id(a))      # Memory address
print(id(b))      # Same address

# id() shows memory address (object identity)
x = [1, 2, 3]
y = x            # Same reference
z = [1, 2, 3]   # Different object
print(x is y)    # True
print(x is z)    # False
```

**Key Differences:** C++ uses address-of operator (&) to get object identity for stack objects, and pointer comparison for heap objects. Java uses reference comparison with ==. Java's equals() method compares state, while == compares identity. C++ overloads == for value comparison.

---

### 163. Black Box

**Definition:** A concept where an object's internal implementation is hidden, exposing only its interface.

**Explanation:** The black box principle treats objects as entities whose internal workings are concealed from users. Users interact with objects through public methods without needing to understand the internal implementation. This abstraction allows implementation changes without affecting code that uses the object.

**C++ Code Example:**
```cpp
class Calculator {
private:
    // Hidden internal implementation
    double memory;
    double complexAlgorithm(double x) {
        return x * x + 2 * x + 1;
    }
    
public:
    // Public interface (black box boundary)
    double calculate(double input) {
        return complexAlgorithm(input);
    }
};

// User doesn't know how it works internally
Calculator calc;
double result = calc.calculate(5);
```

**Java Code Example:**
```java
class Calculator {
    // Hidden internal implementation
    private double memory;
    
    private double complexAlgorithm(double x) {
        return x * x + 2 * x + 1;
    }
    
    // Public interface (black box boundary)
    public double calculate(double input) {
        return complexAlgorithm(input);
    }
}

// User doesn't know how it works internally
Calculator calc = new Calculator();
double result = calc.calculate(5);
```

**Python Code Example:**
```python
class EmailSender:
    """
    Black Box: Users call send_email() without knowing implementation.
    """
    def send_email(self, to, subject, body):  # Public interface
        self.__validate(to)
        self.__connect_smtp()
        self.__compose_message(to, subject, body)
        self.__deliver()
        print(f"Email sent to {to}")

    def __validate(self, addr): pass           # Hidden
    def __connect_smtp(self): pass             # Hidden
    def __compose_message(self, *args): pass   # Hidden
    def __deliver(self): pass                  # Hidden

mailer = EmailSender()
mailer.send_email("user@test.com", "Hello", "World")  # Simple interface
```

**Key Differences:** Both languages implement black box principle through access modifiers. C++ has friend classes/functions that can break encapsulation. Java's encapsulation is stricter with no friend concept. Both achieve information hiding effectively through private members.

---

### 164. Contract (class contract)

**Definition:** The agreement between a class and its users defining what the class guarantees and what it expects.

**Explanation:** A class contract specifies the expected behavior, preconditions, postconditions, and invariants of a class. It's an implicit or explicit agreement about how methods should be called and what they will return. Contracts ensure reliable interactions between objects and classes.

**C++ Code Example:**
```cpp
class Stack {
private:
    vector<int> items;
    
public:
    // Contract: push adds element to top
    void push(int value) {
        items.push_back(value);
    }
    
    // Contract: pop removes top, requires non-empty stack
    int pop() {
        if (items.empty()) 
            throw runtime_error("Stack empty");
        int value = items.back();
        items.pop_back();
        return value;
    }
};
```

**Java Code Example:**
```java
class Stack {
    private List<Integer> items = new ArrayList<>();
    
    // Contract: push adds element to top
    public void push(int value) {
        items.add(value);
    }
    
    // Contract: pop removes top, requires non-empty stack
    public int pop() {
        if (items.isEmpty()) 
            throw new IllegalStateException("Stack empty");
        return items.remove(items.size() - 1);
    }
}
```

**Python Code Example:**
```python
class Stack:
    """
    Class Contract:
    - push(item): Add item to top. Pre: item is not None. Post: size increases by 1.
    - pop(): Remove top item. Pre: stack is not empty. Post: size decreases by 1.
    - peek(): Return top item without removing. Pre: stack is not empty.
    """
    def __init__(self):
        self._items = []

    def push(self, item):
        assert item is not None, "Item must not be None"  # Precondition
        self._items.append(item)

    def pop(self):
        assert not self.is_empty(), "Stack must not be empty"  # Precondition
        return self._items.pop()

    def is_empty(self):
        return len(self._items) == 0
```

**Key Differences:** C++ can use assertions and exceptions to enforce contracts. Java has formal contract support through interfaces and exceptions. Both can document contracts with comments. Java's interface mechanism provides stronger contract enforcement than C++ abstract classes.

---

### 165. No-arg Constructor

**Definition:** A constructor that takes no parameters, used to create objects with default values.

**Explanation:** A no-arg constructor initializes an object without requiring any arguments. It's called the default constructor if it's the only constructor or if explicitly defined. If no constructors are defined, the compiler provides a default no-arg constructor automatically.

**C++ Code Example:**
```cpp
class Person {
    string name;
    int age;
    
public:
    // No-arg constructor
    Person() : name("Unknown"), age(0) {
        cout << "Default person created" << endl;
    }
    
    // Parameterized constructor
    Person(string n, int a) : name(n), age(a) {}
};

// Usage
Person p1;              // calls no-arg constructor
Person p2("Alice", 25); // calls parameterized
```

**Java Code Example:**
```java
class Person {
    String name;
    int age;
    
    // No-arg constructor
    public Person() {
        this.name = "Unknown";
        this.age = 0;
        System.out.println("Default person created");
    }
    
    // Parameterized constructor
    public Person(String name, int age) {
        this.name = name;
        this.age = age;
    }
}

// Usage
Person p1 = new Person();        // no-arg
Person p2 = new Person("Alice", 25); // parameterized
```

**Python Code Example:**
```python
class Config:
    def __init__(self):  # No-arg constructor
        self.host = "localhost"
        self.port = 8080
        self.debug = False
        self.max_connections = 100

    def __str__(self):
        return f"Config(host={self.host}, port={self.port})"

config = Config()  # No-arg instantiation
print(config)      # Config(host=localhost, port=8080)
config.port = 9090
print(config)      # Config(host=localhost, port=9090)
```

**Key Differences:** C++ uses initializer lists for member initialization in constructors. Java initializes fields inline or in constructor body. Both languages auto-generate a default no-arg constructor only if no other constructors exist. C++ allows default parameter values, Java doesn't.

---

### 166. Protective Shield

**Definition:** The encapsulation mechanism that protects object data from unauthorized or harmful access.

**Explanation:** The protective shield concept refers to access control through private, protected, and public modifiers. It shields internal data from direct manipulation, forcing interaction through controlled public methods. This prevents invalid state changes and maintains object integrity.

**C++ Code Example:**
```cpp
class BankAccount {
private:
    double balance; // protected by private access
    
public:
    void deposit(double amount) {
        if (amount > 0) // validation shield
            balance += amount;
    }
    
    bool withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false; // protective logic
    }
};
```

**Java Code Example:**
```java
class BankAccount {
    private double balance; // protected by private access
    
    public void deposit(double amount) {
        if (amount > 0) // validation shield
            balance += amount;
    }
    
    public boolean withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            return true;
        }
        return false; // protective logic
    }
}
```

**Python Code Example:**
```python
class SecureData:
    def __init__(self, data):
        self.__data = data          # Private: protected from outside

    def get_data(self, key):        # Controlled access
        if self.__authenticate(key):
            return self.__data
        raise PermissionError("Invalid key")

    def __authenticate(self, key):  # Hidden implementation
        return key == "secret123"

secure = SecureData("sensitive_info")
try:
    print(secure.get_data("secret123"))  # sensitive_info
    print(secure.get_data("wrong"))      # PermissionError
except PermissionError as e:
    print(f"Access denied: {e}")
```

**Key Differences:** Both languages implement protective shields through access modifiers similarly. C++ has friend declarations that can bypass protection. Java's protection is more absolute. Both use validation in methods to maintain data integrity as part of the protective mechanism.

---

### 167. Controlled Interface

**Definition:** The public methods of a class that provide regulated access to its functionality.

**Explanation:** A controlled interface is the set of public methods that external code can use to interact with an object. It acts as a gateway, ensuring all interactions go through validated, controlled pathways. This allows the class to maintain invariants and prevent misuse while providing necessary functionality.

**C++ Code Example:**
```cpp
class TemperatureController {
private:
    double temperature;
    const double MIN_TEMP = -50.0;
    const double MAX_TEMP = 100.0;
    
public:
    // Controlled interface
    bool setTemperature(double temp) {
        if (temp >= MIN_TEMP && temp <= MAX_TEMP) {
            temperature = temp;
            return true;
        }
        return false; // control logic
    }
    
    double getTemperature() const {
        return temperature;
    }
};
```

**Java Code Example:**
```java
class TemperatureController {
    private double temperature;
    private static final double MIN_TEMP = -50.0;
    private static final double MAX_TEMP = 100.0;
    
    // Controlled interface
    public boolean setTemperature(double temp) {
        if (temp >= MIN_TEMP && temp <= MAX_TEMP) {
            temperature = temp;
            return true;
        }
        return false; // control logic
    }
    
    public double getTemperature() {
        return temperature;
    }
}
```

**Python Code Example:**
```python
class ATM:
    def __init__(self, balance):
        self.__balance = balance  # Internal state hidden

    # Public controlled interface
    def check_balance(self):
        return f"Balance: ${self.__balance}"

    def withdraw(self, amount, pin):
        if pin != 1234:
            raise ValueError("Invalid PIN")
        if amount > self.__balance:
            raise ValueError("Insufficient funds")
        self.__balance -= amount
        return f"Withdrew ${amount}"

    # Private implementation details
    def __log_transaction(self, tx): pass

atm = ATM(1000)
print(atm.check_balance())    # Balance: $1000
print(atm.withdraw(100, 1234))  # Withdrew $100
```

**Key Differences:** Both languages implement controlled interfaces through public methods with validation. C++ can use const methods to indicate read-only operations. Java uses final for constants. The concept and implementation are nearly identical in both languages.

---

### 168. Formal Generic Type Parameter

**Definition:** A placeholder type used in generic class or method declarations, to be replaced with actual types later.

**Explanation:** Formal generic type parameters (like T, E, K, V) are declared in angle brackets when defining generic classes or methods. They act as type variables that will be substituted with concrete types when the generic is instantiated. This enables writing type-safe, reusable code that works with different types.

**C++ Code Example:**
```cpp
// T is the formal generic type parameter
template<typename T>
class Box {
private:
    T content;
    
public:
    Box(T value) : content(value) {}
    T getContent() const { return content; }
};

// Multiple type parameters
template<typename K, typename V>
class Pair {
    K key;
    V value;
};
```

**Java Code Example:**
```java
// T is the formal generic type parameter
class Box<T> {
    private T content;
    
    public Box(T value) {
        this.content = value;
    }
    
    public T getContent() {
        return content;
    }
}

// Multiple type parameters
class Pair<K, V> {
    private K key;
    private V value;
}
```

**Python Code Example:**
```python
from typing import TypeVar, Generic

T = TypeVar('T')          # Formal generic type parameter
K = TypeVar('K')          # Key type parameter
V = TypeVar('V')          # Value type parameter

class Pair(Generic[K, V]):  # Formal type parameters K, V
    def __init__(self, key: K, value: V):
        self.key = key
        self.value = value

    def get_key(self) -> K:
        return self.key

    def get_value(self) -> V:
        return self.value

p = Pair[str, int]("age", 25)
print(p.get_key())    # age
print(p.get_value())  # 25
```

**Key Differences:** C++ uses template<typename T> or template<class T> syntax. Java uses class Name<T> syntax. C++ templates are compiled per instantiation (code generation), while Java uses type erasure (single compiled version). C++ allows non-type template parameters, Java doesn't.

---

### 169. Generic Type Argument

**Definition:** The actual concrete type provided when instantiating a generic class or calling a generic method.

**Explanation:** Generic type arguments are the specific types (like Integer, String, Double) that replace formal type parameters when creating an instance of a generic class or calling a generic method. They allow the same generic code to work with different types while maintaining type safety. The argument is specified at instantiation time.

**C++ Code Example:**
```cpp
template<typename T>
class Container {
    T item;
public:
    Container(T i) : item(i) {}
    T getItem() const { return item; }
};

// Integer is the generic type argument
Container<int> intContainer(42);

// String is the generic type argument
Container<string> strContainer("Hello");

// Custom class as type argument
Container<Person> personContainer(Person{"Alice", 30});
```

**Java Code Example:**
```java
class Container<T> {
    private T item;
    
    public Container(T item) {
        this.item = item;
    }
    
    public T getItem() {
        return item;
    }
}

// Integer is the generic type argument
Container<Integer> intContainer = new Container<>(42);

// String is the generic type argument
Container<String> strContainer = new Container<>("Hello");

// Custom class as type argument
Container<Person> personContainer = new Container<>(new Person("Alice", 30));
```

**Python Code Example:**
```python
from typing import TypeVar, Generic, List

T = TypeVar('T')

class Repository(Generic[T]):
    def __init__(self):
        self._items: List[T] = []

    def add(self, item: T) -> None:
        self._items.append(item)

    def get_all(self) -> List[T]:
        return self._items.copy()

# Type arguments specified at usage (instantiation)
int_repo: Repository[int] = Repository()   # T = int
str_repo: Repository[str] = Repository()   # T = str

int_repo.add(1)
int_repo.add(2)
str_repo.add("hello")
print(int_repo.get_all())   # [1, 2]
print(str_repo.get_all())   # ['hello']
```

**Key Differences:** C++ type arguments can be any type including primitives (int, double). Java type arguments must be reference types (Integer, Double, not primitives). Java 7+ has diamond operator (<>) for type inference. C++ performs complete instantiation per type, Java uses type erasure with runtime type information removed.

---

## Summary: Complete OOP Concepts Reference

This reference guide covers essential object-oriented programming concepts used in both C++ and Java. Key differences between the languages include:

- **Memory Management:** C++ requires manual memory management (new/delete), Java has automatic garbage collection
- **Generics vs Templates:** C++ templates generate code per type, Java generics use type erasure
- **Access Control:** Both have similar access modifiers, but C++ has friend declarations
- **Wrapper Classes:** Java requires wrappers for primitives in collections, C++ doesn't
- **Method Overriding:** Java uses @Override annotation, C++ uses virtual/override keywords
- **Boxing:** Java has autoboxing/unboxing, C++ uses primitives directly in templates

Both languages support fundamental OOP principles of encapsulation, inheritance, and polymorphism with slight syntactic and implementation differences.
