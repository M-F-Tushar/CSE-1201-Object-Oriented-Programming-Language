# Chapter 11: Inheritance and Polymorphism - Complete Guide

## Table of Contents
1. [Introduction](#introduction)
2. [Superclasses and Subclasses](#superclasses-and-subclasses)
3. [Using the super Keyword](#using-the-super-keyword)
4. [Overriding Methods](#overriding-methods)
5. [Overriding vs. Overloading](#overriding-vs-overloading)
6. [The Object Class and Its toString() Method](#the-object-class-and-its-tostring-method)
7. [Polymorphism](#polymorphism)
8. [Dynamic Binding](#dynamic-binding)
9. [Casting Objects and the instanceof Operator](#casting-objects-and-the-instanceof-operator)
10. [The Object's equals Method](#the-objects-equals-method)
11. [The ArrayList Class](#the-arraylist-class)
12. [Useful Methods for Lists](#useful-methods-for-lists)
13. [Case Study: A Custom Stack Class](#case-study-a-custom-stack-class)
14. [The protected Data and Methods](#the-protected-data-and-methods)
15. [Preventing Extending and Overriding](#preventing-extending-and-overriding)

---

## Introduction

**Inheritance** is a fundamental concept in object-oriented programming that allows you to define new classes from existing classes. This promotes **code reuse** and creates hierarchical relationships between classes.

### Key Benefits of Inheritance:
- **Code Reusability**: Avoid redundant code by inheriting common features
- **Maintainability**: Changes in superclass automatically apply to subclasses
- **Extensibility**: Add new features to existing classes without modifying them
- **Polymorphism**: Use objects of different types through a common interface

### Why Use Inheritance?
Consider designing classes for geometric objects like circles, rectangles, and triangles. These classes share many common features (color, filled status, creation date). Instead of duplicating code, we can create a general `GeometricObject` class and extend it for specific shapes.

---

## Superclasses and Subclasses

### Basic Concepts

**Superclass (Parent/Base Class)**: The general class that provides common features
**Subclass (Child/Derived Class)**: The specialized class that extends the superclass

### Inheritance Hierarchy Example

```java
// Superclass
public class GeometricObject {
    private String color = "white";
    private boolean filled = false;
    private Date dateCreated;
    
    // Constructors and methods...
}

// Subclasses
public class Circle extends GeometricObject {
    private double radius;
    // Circle-specific methods...
}

public class Rectangle extends GeometricObject {
    private double width, height;
    // Rectangle-specific methods...
}
```

### Complete Example: SimpleGeometricObject Class

```java
public class SimpleGeometricObject {
    private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;

    /** Default constructor */
    public SimpleGeometricObject() {
        dateCreated = new java.util.Date();
    }

    /** Constructor with color and filled */
    public SimpleGeometricObject(String color, boolean filled) {
        dateCreated = new java.util.Date();
        this.color = color;
        this.filled = filled;
    }

    // Getter and setter methods
    public String getColor() { return color; }
    public void setColor(String color) { this.color = color; }
    public boolean isFilled() { return filled; }
    public void setFilled(boolean filled) { this.filled = filled; }
    public java.util.Date getDateCreated() { return dateCreated; }

    public String toString() {
        return "created on " + dateCreated + "\ncolor: " + color +
               " and filled: " + filled;
    }
}
```

### Circle Subclass Example

```java
public class CircleFromSimpleGeometricObject extends SimpleGeometricObject {
    private double radius;

    public CircleFromSimpleGeometricObject() {}

    public CircleFromSimpleGeometricObject(double radius) {
        this.radius = radius;
    }

    public CircleFromSimpleGeometricObject(double radius, String color, boolean filled) {
        this.radius = radius;
        setColor(color);      // Using inherited method
        setFilled(filled);    // Using inherited method
    }

    // Circle-specific methods
    public double getRadius() { return radius; }
    public void setRadius(double radius) { this.radius = radius; }
    public double getArea() { return radius * radius * Math.PI; }
    public double getDiameter() { return 2 * radius; }
    public double getPerimeter() { return 2 * radius * Math.PI; }

    public void printCircle() {
        System.out.println("The circle is created " + getDateCreated() +
                          " and the radius is " + radius);
    }
}
```

### Rectangle Subclass Example

```java
public class RectangleFromSimpleGeometricObject extends SimpleGeometricObject {
    private double width;
    private double height;

    public RectangleFromSimpleGeometricObject() {}

    public RectangleFromSimpleGeometricObject(double width, double height) {
        this.width = width;
        this.height = height;
    }

    public RectangleFromSimpleGeometricObject(double width, double height, 
                                            String color, boolean filled) {
        this.width = width;
        this.height = height;
        setColor(color);
        setFilled(filled);
    }

    // Rectangle-specific methods
    public double getWidth() { return width; }
    public void setWidth(double width) { this.width = width; }
    public double getHeight() { return height; }
    public void setHeight(double height) { this.height = height; }
    public double getArea() { return width * height; }
    public double getPerimeter() { return 2 * (width + height); }
}
```

### Important Notes About Inheritance

1. **Subclass is NOT a subset**: A subclass usually contains MORE information than its superclass
2. **Private fields are not accessible**: Private data fields in superclass cannot be directly accessed in subclass
3. **is-a relationship**: Inheritance models "is-a" relationships (Circle IS-A GeometricObject)
4. **Single inheritance**: Java allows only one parent class per subclass
5. **No blind extension**: Don't extend classes just to reuse methods without logical relationship

### Check Point Questions (11.1-11.3)

**11.1** True or false? A subclass is a subset of a superclass.
**Answer**: False. A subclass usually contains more information and methods than its superclass.

**11.2** What keyword do you use to define a subclass?
**Answer**: `extends`

**11.3** What is single inheritance? What is multiple inheritance? Does Java support multiple inheritance?
**Answer**: 
- **Single inheritance**: A class can extend only one superclass
- **Multiple inheritance**: A class can extend multiple superclasses
- Java supports only single inheritance for classes (but multiple inheritance through interfaces)

---

## Using the super Keyword

The `super` keyword refers to the superclass and can be used in two ways:
1. **To call a superclass constructor**
2. **To call a superclass method**

### Calling Superclass Constructors

#### Syntax:
```java
super();              // Calls no-arg constructor
super(parameters);    // Calls constructor with parameters
```

#### Rules:
- Must be the **first statement** in the constructor
- If not explicitly called, compiler automatically adds `super()`

#### Example:
```java
public CircleFromSimpleGeometricObject(double radius, String color, boolean filled) {
    super(color, filled);  // Call superclass constructor
    this.radius = radius;
}
```

### Constructor Chaining

When creating a subclass object, constructors are called in a chain from the most general (Object) to the most specific class.

#### Example Demonstrating Constructor Chaining:

```java
public class Faculty extends Employee {
    public static void main(String[] args) {
        new Faculty();  // This will trigger constructor chaining
    }

    public Faculty() {
        System.out.println("(4) Performs Faculty's tasks");
    }
}

class Employee extends Person {
    public Employee() {
        this("(2) Invoke Employee's overloaded constructor");
        System.out.println("(3) Performs Employee's tasks ");
    }

    public Employee(String s) {
        System.out.println(s);
    }
}

class Person {
    public Person() {
        System.out.println("(1) Performs Person's tasks");
    }
}
```

**Output:**
```
(1) Performs Person's tasks
(2) Invoke Employee's overloaded constructor
(3) Performs Employee's tasks
(4) Performs Faculty's tasks
```

### Calling Superclass Methods

#### Syntax:
```java
super.methodName(parameters);
```

#### Example:
```java
public void printCircle() {
    System.out.println("The circle is created " + 
                      super.getDateCreated() + " and the radius is " + radius);
}
```

### Check Point Questions (11.4-11.6)

**11.4** What is the output of running class C in (a)? What problem arises in compiling program in (b)?

(a) **Output**: "A's no-arg constructor is invoked"
(b) **Problem**: Class B's constructor tries to call A's no-arg constructor, but A only has a constructor with int parameter.

**11.5** How does a subclass invoke its superclass's constructor?
**Answer**: Using `super()` or `super(parameters)` as the first statement in the constructor.

**11.6** True or false? When invoking a constructor from a subclass, its superclass's no-arg constructor is always invoked.
**Answer**: False. The superclass constructor that gets invoked depends on the `super()` call used.

---

## Overriding Methods

**Method overriding** occurs when a subclass provides a specific implementation of a method that is already defined in its superclass.

### Rules for Method Overriding:
1. Same method signature (name, parameters, return type)
2. Method must be accessible (not private)
3. Static methods cannot be overridden (they are hidden)

### Example: Overriding toString()

```java
public class CircleFromSimpleGeometricObject extends SimpleGeometricObject {
    // ... other code ...

    @Override
    public String toString() {
        return super.toString() + "\nradius is " + radius;
    }
}
```

### Key Points:
- Use `super.methodName()` to call the superclass version
- Cannot use `super.super.methodName()` (syntax error)
- Private methods cannot be overridden
- Static methods are hidden, not overridden

### Check Point Questions (11.7-11.10)

**11.7** True or false? You can override a private method defined in a superclass.
**Answer**: False. Private methods are not accessible outside their own class.

**11.8** True or false? You can override a static method defined in a superclass.
**Answer**: False. Static methods can be hidden but not overridden.

**11.9** How do you explicitly invoke a superclass's constructor from a subclass?
**Answer**: Use `super()` or `super(parameters)` as the first statement in the constructor.

**11.10** How do you invoke an overridden superclass method from a subclass?
**Answer**: Use `super.methodName(parameters)`.

---

## Overriding vs. Overloading

### Key Differences:

| Aspect | Overriding | Overloading |
|--------|------------|-------------|
| **Location** | Different classes (inheritance) | Same class or inheritance |
| **Signature** | Same signature and return type | Same name, different parameters |
| **Purpose** | Provide specific implementation | Multiple versions of same method |

### Example Demonstrating Both:

#### (a) Overriding Example:
```java
class B {
    public void p(double i) {
        System.out.println(i * 2);
    }
}

class A extends B {
    // This method OVERRIDES the method in B
    public void p(double i) {
        System.out.println(i);
    }
}

public class Test {
    public static void main(String[] args) {
        A a = new A();
        a.p(10);    // Output: 10.0
        a.p(10.0);  // Output: 10.0
    }
}
```

#### (b) Overloading Example:
```java
class B {
    public void p(double i) {
        System.out.println(i * 2);
    }
}

class A extends B {
    // This method OVERLOADS the method in B
    public void p(int i) {
        System.out.println(i);
    }
}

public class Test {
    public static void main(String[] args) {
        A a = new A();
        a.p(10);    // Output: 10 (calls p(int))
        a.p(10.0);  // Output: 20.0 (calls p(double) from B)
    }
}
```

### Override Annotation

Use `@Override` annotation to catch mistakes:

```java
@Override
public String toString() {
    return super.toString() + "\nradius is " + radius;
}
```

**Benefits:**
- Compiler checks if method actually overrides
- Prevents typos (e.g., `tostring` instead of `toString`)
- Makes code more readable

### Check Point Questions (11.11-11.16)

**11.11** Identify problems in the following code:
```java
public class Circle {
    private double radius;
    
    public Circle(double radius) {
        radius = radius;  // Problem: should be this.radius = radius;
    }
    
    // ... other methods ...
}

class B extends Circle {
    private double length;
    
    B(double radius, double length) {
        Circle(radius);        // Problem: should be super(radius);
        length = length;       // Problem: should be this.length = length;
    }
    
    @Override
    public double getArea() {
        return getArea() * length;  // Problem: infinite recursion
    }
}
```

**Problems:**
1. Line 5: Should be `this.radius = radius;`
2. Line 21: Should be `super(radius);`
3. Line 22: Should be `this.length = length;`
4. Line 27: Creates infinite recursion, should be `super.getArea() * length;`

---

## The Object Class and Its toString() Method

### Every Class Inherits from Object

All classes in Java implicitly extend the `Object` class:

```java
public class ClassName {        public class ClassName extends Object {
    // ...                 ≡       // ...
}                               }
```

### The toString() Method

**Default behavior**: Returns `ClassName@hexMemoryAddress`

```java
Loan loan = new Loan();
System.out.println(loan.toString()); // Output: Loan@15037e5
```

**Override for meaningful output**:
```java
@Override
public String toString() {
    return "created on " + dateCreated + "\ncolor: " + color +
           " and filled: " + filled;
}
```

### Automatic toString() Invocation

These are equivalent:
```java
System.out.println(object.toString());
System.out.println(object);  // Automatically calls toString()
```

---

## Polymorphism

**Polymorphism** (Greek: "many forms") means that a variable of a supertype can refer to a subtype object.

### Key Terms:
- **Supertype**: Type defined by superclass
- **Subtype**: Type defined by subclass

### Example:

```java
public class PolymorphismDemo {
    public static void main(String[] args) {
        // Polymorphic calls
        displayObject(new CircleFromSimpleGeometricObject(1, "red", false));
        displayObject(new RectangleFromSimpleGeometricObject(1, 1, "black", true));
    }

    public static void displayObject(SimpleGeometricObject object) {
        System.out.println("Created on " + object.getDateCreated() +
                          ". Color is " + object.getColor());
    }
}
```

**Key Point**: The `displayObject` method accepts any subclass of `SimpleGeometricObject`.

### Benefits of Polymorphism:
1. **Code flexibility**: One method works with multiple types
2. **Extensibility**: Add new subclasses without changing existing code
3. **Maintainability**: Centralized logic for common operations

---

## Dynamic Binding

**Dynamic binding** determines which method implementation to use at runtime based on the object's actual type.

### Key Terms:
- **Declared type**: The type used in variable declaration
- **Actual type**: The actual class of the object referenced

### Example:

```java
public class DynamicBindingDemo {
    public static void main(String[] args) {
        m(new GraduateStudent());  // Output: Student
        m(new Student());          // Output: Student  
        m(new Person());           // Output: Person
        m(new Object());           // Output: java.lang.Object@hexAddress
    }

    public static void m(Object x) {
        System.out.println(x.toString());  // Dynamic binding occurs here
    }
}

class GraduateStudent extends Student {
    // No toString() override
}

class Student extends Person {
    @Override
    public String toString() {
        return "Student";
    }
}

class Person extends Object {
    @Override
    public String toString() {
        return "Person";
    }
}
```

### How Dynamic Binding Works:
1. JVM searches for method implementation starting from the actual object's class
2. Searches up the inheritance hierarchy until method is found
3. Uses the first implementation found

### Method Matching vs. Method Binding:
- **Method Matching**: Decided at compile time based on declared type
- **Method Binding**: Decided at runtime based on actual type

### Check Point Questions (11.17-11.23)

**11.17** What is polymorphism? What is dynamic binding?
**Answer**: 
- Polymorphism: A supertype variable can refer to subtype objects
- Dynamic binding: JVM decides which method implementation to use at runtime

**11.19** Can you assign `new int[50]`, `new Integer[50]`, `new String[50]`, or `new Object[50]` into a variable of `Object[]` type?
**Answer**: `new Integer[50]`, `new String[50]`, and `new Object[50]` can be assigned. `new int[50]` cannot because primitive arrays are not Object arrays.

---

## Casting Objects and the instanceof Operator

### Object Casting

**Casting objects** involves converting an object reference from one type to another.

### Types of Casting:
1. **Implicit casting (Upcasting)**: Subclass to superclass (always safe)
2. **Explicit casting (Downcasting)**: Superclass to subclass (requires verification)

### Examples:

```java
// Implicit casting (upcasting) - always safe
Object o = new Student();  // Student IS-A Object

// Explicit casting (downcasting) - needs verification
Student s = (Student) o;   // Must cast explicitly
```

### The instanceof Operator

Use `instanceof` to check object type before casting:

```java
Object myObject = new Circle();

if (myObject instanceof Circle) {
    System.out.println("The circle diameter is " +
                      ((Circle)myObject).getDiameter());
}
```

### Complete Casting Example:

```java
public class CastingDemo {
    public static void main(String[] args) {
        Object object1 = new CircleFromSimpleGeometricObject(1);
        Object object2 = new RectangleFromSimpleGeometricObject(1, 1);

        displayObject(object1);
        displayObject(object2);
    }

    public static void displayObject(Object object) {
        if (object instanceof CircleFromSimpleGeometricObject) {
            System.out.println("The circle area is " +
                ((CircleFromSimpleGeometricObject)object).getArea());
            System.out.println("The circle diameter is " +
                ((CircleFromSimpleGeometricObject)object).getDiameter());
        }
        else if (object instanceof RectangleFromSimpleGeometricObject) {
            System.out.println("The rectangle area is " +
                ((RectangleFromSimpleGeometricObject)object).getArea());
        }
    }
}
```

### Important Notes:
- **Parentheses matter**: Use `((Circle)object).getArea()` not `(Circle)object.getArea()`
- **Casting doesn't create new objects**: Both references point to the same object
- **ClassCastException**: Thrown if casting fails at runtime

### Check Point Questions (11.24-11.27)

**11.24** True/False statements:
- You can always successfully cast an instance of a subclass to a superclass: **True**
- You can always successfully cast an instance of a superclass to a subclass: **False**

**11.26** Fruit inheritance hierarchy answers:
Given: `Fruit fruit = new GoldenDelicious(); Orange orange = new Orange();`

a. Is fruit instanceof Fruit? **True**
b. Is fruit instanceof Orange? **False**
c. Is fruit instanceof Apple? **True**
d. Is fruit instanceof GoldenDelicious? **True**
e. Is fruit instanceof McIntosh? **False**

---

## The Object's equals Method

### Default equals Implementation

```java
public boolean equals(Object obj) {
    return (this == obj);  // Compares references, not content
}
```

### Overriding equals Method

```java
public boolean equals(Object o) {
    if (o instanceof Circle)
        return radius == ((Circle)o).radius;
    else
        return this == o;
}
```

### == vs equals():
- **==**: Compares references (are they the same object?)
- **equals()**: Compares content (when properly overridden)

### Common Mistake

Wrong signature (creates overloading instead of overriding):
```java
public boolean equals(Circle circle) { ... }  // Wrong!
```

Correct signature:
```java
public boolean equals(Object circle) { ... }   // Correct!
```

### Check Point Question 11.28-11.29

**11.28** Does every object have a toString method and an equals method?
**Answer**: Yes, inherited from Object class. They should be overridden for meaningful behavior.

---

## The ArrayList Class

**ArrayList** is a resizable array that can store objects of any type.

### Key Features:
- **Dynamic size**: Grows and shrinks automatically
- **Generic type**: Specify element type using `<>`
- **Rich API**: Many useful methods for list operations

### Creating ArrayList:

```java
ArrayList<String> cities = new ArrayList<>();
ArrayList<Integer> numbers = new ArrayList<>();
ArrayList<CircleFromSimpleGeometricObject> circles = new ArrayList<>();
```

### Common ArrayList Methods:

| Method | Description |
|--------|-------------|
| `add(element)` | Appends element to end |
| `add(index, element)` | Inserts element at index |
| `get(index)` | Returns element at index |
| `set(index, element)` | Replaces element at index |
| `remove(index)` | Removes element at index |
| `remove(element)` | Removes first occurrence |
| `size()` | Returns number of elements |
| `isEmpty()` | Checks if list is empty |
| `contains(element)` | Checks if element exists |
| `indexOf(element)` | Returns first index of element |
| `clear()` | Removes all elements |

### Complete ArrayList Example:

```java
import java.util.ArrayList;

public class TestArrayList {
    public static void main(String[] args) {
        // Create a list to store cities
        ArrayList<String> cityList = new ArrayList<>();

        // Add cities
        cityList.add("London");    // [London]
        cityList.add("Denver");    // [London, Denver]
        cityList.add("Paris");     // [London, Denver, Paris]
        cityList.add("Miami");     // [London, Denver, Paris, Miami]
        cityList.add("Seoul");     // [London, Denver, Paris, Miami, Seoul]
        cityList.add("Tokyo");     // [London, Denver, Paris, Miami, Seoul, Tokyo]

        // Display information
        System.out.println("List size? " + cityList.size());                    // 6
        System.out.println("Is Miami in the list? " + cityList.contains("Miami")); // true
        System.out.println("Denver index: " + cityList.indexOf("Denver"));      // 1
        System.out.println("Is empty? " + cityList.isEmpty());                  // false

        // Insert at specific position
        cityList.add(2, "Xian");   // [London, Denver, Xian, Paris, Miami, Seoul, Tokyo]

        // Remove elements
        cityList.remove("Miami");   // [London, Denver, Xian, Paris, Seoul, Tokyo]
        cityList.remove(1);         // [London, Xian, Paris, Seoul, Tokyo]

        // Display contents
        System.out.println(cityList.toString());

        // Display in reverse order
        for (int i = cityList.size() - 1; i >= 0; i--) {
            System.out.print(cityList.get(i) + " ");
        }
    }
}
```

### ArrayList vs Array Comparison:

| Operation | Array | ArrayList |
|-----------|-------|-----------|
| **Creation** | `String[] a = new String[10]` | `ArrayList<String> list = new ArrayList<>()` |
| **Access** | `a[index]` | `list.get(index)` |
| **Update** | `a[index] = value` | `list.set(index, value)` |
| **Size** | `a.length` | `list.size()` |
| **Add** | Not directly supported | `list.add(value)` |
| **Insert** | Complex | `list.add(index, value)` |
| **Remove** | Complex | `list.remove(index)` |

### Generic Types and Primitives

**Cannot use primitives directly:**
```java
ArrayList<int> list = new ArrayList<>();  // Compile error!
```

**Use wrapper classes:**
```java
ArrayList<Integer> list = new ArrayList<>();  // Correct!
list.add(5);  // Autoboxing: int → Integer
int value = list.get(0);  // Auto-unboxing: Integer → int
```

### For-Each Loop with ArrayList:

```java
ArrayList<Integer> numbers = new ArrayList<>();
// ... add numbers ...

for (int number : numbers) {
    System.out.print(number + " ");
}
```

### Distinct Numbers Example:

```java
import java.util.ArrayList;
import java.util.Scanner;

public class DistinctNumbers {
    public static void main(String[] args) {
        ArrayList<Integer> list = new ArrayList<>();
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter integers (input ends with 0): ");
        int value;
        
        do {
            value = input.nextInt();
            if (!list.contains(value) && value != 0) {
                list.add(value);
            }
        } while (value != 0);
        
        // Display distinct numbers
        for (int number : list) {
            System.out.print(number + " ");
        }
    }
}
```

### Check Point Questions (11.30-11.34)

**11.30** How do you do the following?
a. Create ArrayList for doubles: `ArrayList<Double> list = new ArrayList<>();`
b. Append object: `list.add(object)`
c. Insert at beginning: `list.add(0, object)`
d. Find size: `list.size()`
e. Remove object: `list.remove(object)`
f. Remove last: `list.remove(list.size()-1)`
g. Check contains: `list.contains(object)`
h. Get at index: `list.get(index)`

---

## Useful Methods for Lists

### Converting Between Arrays and ArrayLists

#### Array to ArrayList:
```java
String[] array = {"red", "green", "blue"};
ArrayList<String> list = new ArrayList<>(Arrays.asList(array));
```

#### ArrayList to Array:
```java
String[] array1 = new String[list.size()];
list.toArray(array1);
```

### Sorting Lists

```java
Integer[] array = {3, 5, 95, 4, 15, 34, 3, 6, 5};
ArrayList<Integer> list = new ArrayList<>(Arrays.asList(array));
java.util.Collections.sort(list);
System.out.println(list);  // [3, 3, 4, 5, 5, 6, 15, 34, 95]
```

### Finding Max and Min

```java
System.out.println(java.util.Collections.max(list));  // 95
System.out.println(java.util.Collections.min(list));  // 3
```

### Shuffling Lists

```java
java.util.Collections.shuffle(list);
System.out.println(list);  // Random order
```

### Check Point Questions (11.35-11.36)

**11.35** Correct the error:
```java
// Wrong:
int[] array = {3, 5, 95, 4, 15, 34, 3, 6, 5};
ArrayList<Integer> list = new ArrayList<>(Arrays.asList(array));

// Correct:
Integer[] array = {3, 5, 95, 4, 15, 34, 3, 6, 5};
ArrayList<Integer> list = new ArrayList<>(Arrays.asList(array));
```

---

## Case Study: A Custom Stack Class

### MyStack Class Implementation

```java
import java.util.ArrayList;

public class MyStack {
    private ArrayList<Object> list = new ArrayList<>();

    public boolean isEmpty() {
        return list.isEmpty();
    }

    public int getSize() {
        return list.size();
    }

    public Object peek() {
        return list.get(getSize() - 1);
    }

    public Object pop() {
        Object o = list.get(getSize() - 1);
        list.remove(getSize() - 1);
        return o;
    }

    public void push(Object o) {
        list.add(o);
    }

    @Override
    public String toString() {
        return "stack: " + list.toString();
    }
}
```

### Design Principle: Composition vs Inheritance

**Composition (Has-A)**: MyStack HAS-A ArrayList
- Better encapsulation
- Exposes only necessary methods
- More flexible design

**Inheritance (Is-A)**: MyStack IS-A ArrayList
- Inherits all ArrayList methods (many unnecessary)
- Less control over interface
- Tighter coupling

**Recommendation**: Use composition for this case.

---

## The protected Data and Methods

### Visibility Modifiers

| Modifier | Same Class | Same Package | Subclass (different package) | Different Package |
|----------|------------|--------------|----------------------------|-------------------|
| `private` | ✓ | ❌ | ❌ | ❌ |
| default (no modifier) | ✓ | ✓ | ❌ | ❌ |
| `protected` | ✓ | ✓ | ✓ | ❌ |
| `public` | ✓ | ✓ | ✓ | ✓ |

### When to Use Each Modifier:
- **private**: Internal implementation details
- **default**: Package-level access
- **protected**: For subclasses to extend functionality
- **public**: Public interface for all users

### Example:

```java
public class C1 {
    public int x;        // Accessible everywhere
    protected int y;     // Accessible in subclasses and same package
    int z;              // Default: accessible in same package only
    private int u;      // Accessible only in this class

    protected void m() {
        // Protected method
    }
}
```

### Usage Guidelines:
- **For users of the class**: Use `public` methods and constructors
- **For extenders of the class**: Use `protected` methods and fields
- **For internal implementation**: Use `private` methods and fields
- **For package collaboration**: Use default (no modifier)

### Important Notes:
- A subclass can **strengthen** visibility (protected → public) but cannot **weaken** it
- Only members can use `private` and `protected` modifiers
- Classes can only use `public` or default modifiers

### Check Point Questions (11.37-11.40)

**11.37** What modifier for same package access but not different package?
**Answer**: Default (no modifier)

**11.38** What modifier so different package cannot access class, but subclasses in any package can access it?
**Answer**: This is impossible for classes. Use `protected` for members.

**11.39** Classes A and B in same package - can class B be compiled?
- With blanks (default): **Yes**
- With private: **No** (cannot access private members)
- With protected: **Yes**

**11.40** Classes A and B in different packages - can class B be compiled?
- With blanks (default): **No** (default not accessible across packages)
- With private: **No** (private not accessible)
- With protected: **Yes** (B extends A, so can access protected members)

---

## Preventing Extending and Overriding

### The final Modifier

The `final` modifier prevents extension and overriding:

1. **final class**: Cannot be extended
2. **final method**: Cannot be overridden
3. **final variable**: Cannot be reassigned (constant)

### Final Classes

```java
public final class Math {
    // Cannot be extended
}

public final class String {
    // Cannot be extended
}

// This would cause compile error:
// public class MyString extends String { } // Error!
```

### Final Methods

```java
public class Test {
    public final void m() {
        // This method cannot be overridden
    }
}

public class SubTest extends Test {
    // This would cause compile error:
    // public void m() { } // Error! Cannot override final method
}
```

### Final Variables (Constants)

```java
public class Circle {
    private final double PI = 3.14159;  // Constant
    
    public void someMethod() {
        final int localConstant = 100;   // Local constant
        // localConstant = 200;  // Error! Cannot reassign final variable
    }
}
```

### Examples of Final Classes in Java:
- `java.lang.String`
- `java.lang.Math`  
- `java.lang.StringBuilder`
- `java.lang.StringBuffer`
- All wrapper classes (`Integer`, `Double`, etc.)

### When to Use final:
- **Classes**: When you want to prevent inheritance (security, design integrity)
- **Methods**: When you want to prevent overriding of critical functionality
- **Variables**: For constants that shouldn't change

### Check Point Questions (11.41-11.42)

**11.41** How do you prevent a class from being extended? How do you prevent a method from being overridden?
**Answer**: 
- Prevent class extension: Use `final class ClassName`
- Prevent method overriding: Use `final` modifier on method

**11.42** True/False statements:
a. A protected datum or method can be accessed by any class in the same package: **True**
b. A protected datum or method can be accessed by any class in different packages: **False**
c. A protected datum or method can be accessed by its subclasses in any package: **True**
d. A final class can have instances: **True**
e. A final class can be extended: **False**
f. A final method can be overridden: **False**

---

## Key Terms Summary

| Term | Definition |
|------|------------|
| **Inheritance** | Mechanism to define new classes from existing classes |
| **Superclass/Supertype** | Parent class that provides common features |
| **Subclass/Subtype** | Child class that extends superclass |
| **Method Overriding** | Providing specific implementation in subclass |
| **Polymorphism** | Supertype variable can refer to subtype objects |
| **Dynamic Binding** | Method implementation determined at runtime |
| **Casting Objects** | Converting object reference from one type to another |
| **instanceof** | Operator to test object type |
| **Constructor Chaining** | Calling constructors up the inheritance hierarchy |
| **is-a Relationship** | Logical relationship modeled by inheritance |
| **has-a Relationship** | Logical relationship modeled by composition |

---

## Chapter Summary

### Major Concepts Covered:

1. **Inheritance Fundamentals**
   - Define subclasses using `extends` keyword
   - Subclasses inherit accessible members from superclass
   - Java supports single inheritance only

2. **Constructor Behavior**
   - Subclass constructors must call superclass constructors
   - Use `super()` or `super(parameters)` as first statement
   - Constructor chaining ensures proper object initialization

3. **Method Overriding**
   - Provide specific implementations in subclasses
   - Use `@Override` annotation for safety
   - Cannot override private or static methods

4. **The Object Class**
   - All classes inherit from Object
   - Override `toString()` for meaningful string representation
   - Override `equals()` for content comparison

5. **Polymorphism and Dynamic Binding**
   - Write generic code that works with multiple types
   - Method implementation chosen at runtime based on actual type
   - Enables flexible and maintainable code

6. **Object Casting**
   - Upcasting is always safe (implicit)
   - Downcasting requires explicit casting and verification
   - Use `instanceof` to check type before casting

7. **ArrayList Class**
   - Resizable array for storing objects
   - Rich API with many useful methods
   - Supports generic types for type safety

8. **Visibility Modifiers**
   - Control access to classes and members
   - `private` < default < `protected` < `public`
   - Choose appropriate level for intended use

9. **Final Modifier**
   - Prevents inheritance (`final` class)
   - Prevents overriding (`final` method)
   - Creates constants (`final` variable)

### Best Practices:

1. **Use inheritance for is-a relationships**
2. **Favor composition over inheritance when appropriate**
3. **Always use `@Override` annotation when overriding**
4. **Provide no-arg constructors when possible**
5. **Use `protected` for members intended for subclasses**
6. **Override `toString()` and `equals()` methods meaningfully**
7. **Use `instanceof` before casting objects**
8. **Choose appropriate visibility modifiers**
9. **Use generic types with ArrayList for type safety**
10. **Consider using `final` for classes/methods that shouldn't be extended/overridden**

### Common Pitfalls to Avoid:

1. **Confusing overriding with overloading**
2. **Not calling superclass constructor properly**
3. **Trying to access private superclass members directly**
4. **Casting without checking with `instanceof`**
5. **Using wrong signature for `equals()` method**
6. **Blindly extending classes without logical is-a relationship**
7. **Forgetting that subclasses contain more than superclasses**
8. **Not understanding the difference between `==` and `equals()`**

This comprehensive guide covers all the essential concepts of inheritance and polymorphism in Java, providing both theoretical understanding and practical examples for effective object-oriented programming.
