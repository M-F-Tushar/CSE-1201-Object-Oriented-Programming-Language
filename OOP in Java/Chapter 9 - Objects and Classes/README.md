# Chapter 9: Objects and Classes - Complete Study Guide

## Table of Contents
1. [Introduction to Object-Oriented Programming](#introduction)
2. [Defining Classes for Objects](#defining-classes)
3. [Examples: Creating Classes and Objects](#examples)
4. [Constructors](#constructors)
5. [Accessing Objects via Reference Variables](#accessing-objects)
6. [Using Classes from Java Library](#java-library)
7. [Static Variables, Constants, and Methods](#static-members)
8. [Visibility Modifiers](#visibility)
9. [Data Field Encapsulation](#encapsulation)
10. [Passing Objects to Methods](#passing-objects)
11. [Array of Objects](#array-objects)
12. [Immutable Objects and Classes](#immutable)
13. [Scope of Variables](#scope)
14. [The this Reference](#this-reference)

---

## 1. Introduction to Object-Oriented Programming {#introduction}

### Key Concepts

**Object-Oriented Programming (OOP)** enables development of large-scale software and GUIs effectively.

### What is an Object?
An **object** represents an entity in the real world that can be distinctly identified.

**Examples:** student, desk, circle, button, loan

### Object Characteristics

1. **Identity**: Each object has a unique identity
2. **State (Properties/Attributes)**: Represented by data fields with current values
3. **Behavior (Actions)**: Defined by methods

### Example: Circle Object
- **State**: radius (data field)
- **Behavior**: getArea(), getPerimeter(), setRadius() (methods)

### Class Definition
A **class** is a template, blueprint, or contract that defines:
- What an object's data fields will be
- What methods the object will have

**Key Relationship**: Class is to Object as Recipe is to Apple Pie
- You can create many objects (apple pies) from one class (recipe)

---

## 2. Defining Classes for Objects {#defining-classes}

### Class Structure

```java
class ClassName {
    // Data fields
    dataType dataField1;
    dataType dataField2;
    
    // Constructors
    ClassName() {
        // Constructor body
    }
    
    ClassName(parameters) {
        // Constructor body
    }
    
    // Methods
    returnType methodName(parameters) {
        // Method body
    }
}
```

### UML Class Diagram Notation

```
ClassName
-----------------
dataFieldName: dataFieldType
-----------------
ClassName(parameterName: parameterType)
methodName(parameterName: parameterType): returnType
```

### Example: Circle Class

```java
class Circle {
    /** The radius of this circle */
    double radius = 1;
    
    /** Construct a circle object */
    Circle() {
    }
    
    /** Construct a circle object */
    Circle(double newRadius) {
        radius = newRadius;
    }
    
    /** Return the area of this circle */
    double getArea() {
        return radius * radius * Math.PI;
    }
    
    /** Return the perimeter of this circle */
    double getPerimeter() {
        return 2 * radius * Math.PI;
    }
    
    /** Set new radius for this circle */
    void setRadius(double newRadius) {
        radius = newRadius;
    }
}
```

---

## 3. Examples: Creating Classes and Objects {#examples}

### Example 1: TestSimpleCircle Program

**Main Class (Client):**
```java
public class TestSimpleCircle {
    public static void main(String[] args) {
        // Create a circle with radius 1
        SimpleCircle circle1 = new SimpleCircle();
        System.out.println("The area of the circle of radius "
            + circle1.radius + " is " + circle1.getArea());
        
        // Create a circle with radius 25
        SimpleCircle circle2 = new SimpleCircle(25);
        System.out.println("The area of the circle of radius "
            + circle2.radius + " is " + circle2.getArea());
        
        // Create a circle with radius 125
        SimpleCircle circle3 = new SimpleCircle(125);
        System.out.println("The area of the circle of radius "
            + circle3.radius + " is " + circle3.getArea());
        
        // Modify circle radius
        circle2.radius = 100;
        System.out.println("The area of the circle of radius "
            + circle2.radius + " is " + circle2.getArea());
    }
}
```

**SimpleCircle Class:**
```java
class SimpleCircle {
    double radius;
    
    /** Construct a circle with radius 1 */
    SimpleCircle() {
        radius = 1;
    }
    
    /** Construct a circle with a specified radius */
    SimpleCircle(double newRadius) {
        radius = newRadius;
    }
    
    /** Return the area of this circle */
    double getArea() {
        return radius * radius * Math.PI;
    }
    
    /** Return the perimeter of this circle */
    double getPerimeter() {
        return 2 * radius * Math.PI;
    }
    
    /** Set a new radius for this circle */
    void setRadius(double newRadius) {
        radius = newRadius;
    }
}
```

**Output:**
```
The area of the circle of radius 1.0 is 3.141592653589793
The area of the circle of radius 25.0 is 1963.4954084936207
The area of the circle of radius 125.0 is 49087.385212340516
The area of the circle of radius 100.0 is 31415.926535897932
```

### Example 2: TV Class

**UML Diagram:**
```
TV
-----------------
channel: int (1 to 120)
volumeLevel: int (1 to 7)
on: boolean
-----------------
+TV()
+turnOn(): void
+turnOff(): void
+setChannel(newChannel: int): void
+setVolume(newVolumeLevel: int): void
+channelUp(): void
+channelDown(): void
+volumeUp(): void
+volumeDown(): void
```

**TV Class Implementation:**
```java
public class TV {
    int channel = 1;        // Default channel is 1
    int volumeLevel = 1;    // Default volume level is 1
    boolean on = false;     // TV is off
    
    public TV() {
    }
    
    public void turnOn() {
        on = true;
    }
    
    public void turnOff() {
        on = false;
    }
    
    public void setChannel(int newChannel) {
        if (on && newChannel >= 1 && newChannel <= 120)
            channel = newChannel;
    }
    
    public void setVolume(int newVolumeLevel) {
        if (on && newVolumeLevel >= 1 && newVolumeLevel <= 7)
            volumeLevel = newVolumeLevel;
    }
    
    public void channelUp() {
        if (on && channel < 120)
            channel++;
    }
    
    public void channelDown() {
        if (on && channel > 1)
            channel--;
    }
    
    public void volumeUp() {
        if (on && volumeLevel < 7)
            volumeLevel++;
    }
    
    public void volumeDown() {
        if (on && volumeLevel > 1)
            volumeLevel--;
    }
}
```

**Test Program:**
```java
public class TestTV {
    public static void main(String[] args) {
        TV tv1 = new TV();
        tv1.turnOn();
        tv1.setChannel(30);
        tv1.setVolume(3);
        
        TV tv2 = new TV();
        tv2.turnOn();
        tv2.channelUp();
        tv2.channelUp();
        tv2.volumeUp();
        
        System.out.println("tv1's channel is " + tv1.channel
            + " and volume level is " + tv1.volumeLevel);
        System.out.println("tv2's channel is " + tv2.channel
            + " and volume level is " + tv2.volumeLevel);
    }
}
```

**Output:**
```
tv1's channel is 30 and volume level is 3
tv2's channel is 3 and volume level is 2
```

---

## 4. Constructors {#constructors}

### Constructor Characteristics
1. **Same name** as the class
2. **No return type** (not even void)
3. **Invoked using new operator** when object is created
4. **Purpose**: Initialize objects

### Constructor Types

#### No-argument Constructor
```java
public Circle() {
    radius = 1.0;
}
```

#### Parameterized Constructor
```java
public Circle(double newRadius) {
    radius = newRadius;
}
```

### Constructor Overloading
Multiple constructors with different parameter lists:

```java
public class Circle {
    private double radius;
    
    // No-arg constructor
    public Circle() {
        radius = 1.0;
    }
    
    // Constructor with parameter
    public Circle(double newRadius) {
        radius = newRadius;
    }
}
```

### Default Constructor
- Provided automatically if **no constructors** are defined
- Has empty body: `public ClassName() { }`
- **Not provided** if any constructor is explicitly defined

### Common Mistake
❌ **Wrong:**
```java
public void Circle() {  // This is a method, not constructor!
}
```

✅ **Correct:**
```java
public Circle() {  // This is a constructor
}
```

---

## 5. Accessing Objects via Reference Variables {#accessing-objects}

### Reference Variables and Types

#### Declaration Syntax
```java
ClassName objectRefVar;
```

#### Creating Objects
```java
objectRefVar = new ClassName();
```

#### Combined Declaration and Creation
```java
ClassName objectRefVar = new ClassName();
```

### Example
```java
Circle myCircle;                    // Declaration
myCircle = new Circle();            // Creation
// OR
Circle myCircle = new Circle();     // Combined
```

### Accessing Members

#### Data Fields
```java
objectRefVar.dataField
```

#### Methods
```java
objectRefVar.method(arguments)
```

### Example Usage
```java
Circle myCircle = new Circle(5.0);
double radius = myCircle.radius;        // Access data field
double area = myCircle.getArea();       // Invoke method
```

### Important Concepts

#### Instance Variables vs Instance Methods
- **Instance Variable**: Data field dependent on specific instance
- **Instance Method**: Method invoked on specific instance
- **Calling Object**: The object on which method is invoked

#### Anonymous Objects
Objects created without assigning to variable:
```java
new Circle();   // Anonymous object
System.out.println("Area is " + new Circle(5).getArea());
```

### Reference Data Fields and null

#### Default Values
- **Reference type**: `null`
- **Numeric type**: `0`
- **boolean**: `false`
- **char**: `'\u0000'`

#### Example
```java
class Student {
    String name;        // Default: null
    int age;           // Default: 0
    boolean isScienceMajor;  // Default: false
    char gender;       // Default: '\u0000'
}
```

### NullPointerException
Common runtime error when invoking method on null reference:

❌ **Causes Error:**
```java
Circle c = null;
double area = c.getArea();  // NullPointerException!
```

✅ **Correct:**
```java
Circle c = new Circle();
double area = c.getArea();  // OK
```

### Primitive vs Reference Types

#### Memory Storage Difference

**Primitive Type Assignment:**
```java
int i = 1;
int j = 2;
i = j;  // Copies value of j to i
```

**Reference Type Assignment:**
```java
Circle c1 = new Circle(5);
Circle c2 = new Circle(9);
c1 = c2;  // c1 and c2 now reference the same object
```

#### Garbage Collection
- Objects no longer referenced become **garbage**
- Java runtime automatically **collects garbage**
- Explicit assignment to null helps: `c1 = null;`

---

## 6. Using Classes from Java Library {#java-library}

### Date Class (java.util.Date)

#### UML Diagram
```
java.util.Date
-----------------
+Date()
+Date(elapseTime: long)
+toString(): String
+getTime(): long
+setTime(elapseTime: long): void
```

#### Usage Example
```java
java.util.Date date = new java.util.Date();
System.out.println("The elapsed time since Jan 1, 1970 is " +
    date.getTime() + " milliseconds");
System.out.println(date.toString());
```

**Output:**
```
The elapsed time since Jan 1, 1970 is 1324903419651 milliseconds
Mon Dec 26 07:43:39 EST 2011
```

### Random Class (java.util.Random)

#### UML Diagram
```
java.util.Random
-----------------
+Random()
+Random(seed: long)
+nextInt(): int
+nextInt(n: int): int
+nextLong(): long
+nextDouble(): double
+nextFloat(): float
+nextBoolean(): boolean
```

#### Seed Concept
- **Seed**: Number to initialize random number generator
- **Same seed** = **same sequence** of random numbers
- **No-arg constructor** uses current time as seed

#### Example
```java
Random random1 = new Random(3);
Random random2 = new Random(3);

System.out.print("From random1: ");
for (int i = 0; i < 10; i++)
    System.out.print(random1.nextInt(1000) + " ");

System.out.print("\nFrom random2: ");
for (int i = 0; i < 10; i++)
    System.out.print(random2.nextInt(1000) + " ");
```

**Output:**
```
From random1: 734 660 210 581 128 202 549 564 459 961
From random2: 734 660 210 581 128 202 549 564 459 961
```

### Point2D Class (javafx.geometry.Point2D)

#### UML Diagram
```
javafx.geometry.Point2D
-----------------
+Point2D(x: double, y: double)
+distance(x: double, y: double): double
+distance(p: Point2D): double
+getX(): double
+getY(): double
+toString(): String
```

#### Example Program
```java
import java.util.Scanner;
import javafx.geometry.Point2D;

public class TestPoint2D {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter point1's x-, y-coordinates: ");
        double x1 = input.nextDouble();
        double y1 = input.nextDouble();
        System.out.print("Enter point2's x-, y-coordinates: ");
        double x2 = input.nextDouble();
        double y2 = input.nextDouble();
        
        Point2D p1 = new Point2D(x1, y1);
        Point2D p2 = new Point2D(x2, y2);
        System.out.println("p1 is " + p1.toString());
        System.out.println("p2 is " + p2.toString());
        System.out.println("The distance between p1 and p2 is " +
            p1.distance(p2));
    }
}
```

**Sample Output:**
```
Enter point1's x-, y-coordinates: 1.5 5.5
Enter point2's x-, y-coordinates: -5.3 -4.4
p1 is Point2D [x = 1.5, y = 5.5]
p2 is Point2D [x = -5.3, y = -4.4]
The distance between p1 and p2 is 12.010412149464313
```

---

## 7. Static Variables, Constants, and Methods {#static-members}

### Instance vs Static Members

#### Instance Members
- **Instance Variable**: Belongs to individual object
- **Instance Method**: Accessed through object reference
- Each object has **separate copy**

#### Static Members
- **Static Variable (Class Variable)**: Shared by all objects
- **Static Method**: Can be called without creating object
- **Single copy** shared by all instances

### Example: CircleWithStaticMembers

```java
public class CircleWithStaticMembers {
    /** The radius of the circle */
    double radius;                    // Instance variable
    
    /** The number of objects created */
    static int numberOfObjects = 0;   // Static variable
    
    /** Construct a circle with radius 1 */
    CircleWithStaticMembers() {
        radius = 1;
        numberOfObjects++;            // Increment static variable
    }
    
    /** Construct a circle with a specified radius */
    CircleWithStaticMembers(double newRadius) {
        radius = newRadius;
        numberOfObjects++;            // Increment static variable
    }
    
    /** Return numberOfObjects */
    static int getNumberOfObjects() { // Static method
        return numberOfObjects;
    }
    
    /** Return the area of this circle */
    double getArea() {                // Instance method
        return radius * radius * Math.PI;
    }
}
```

### Test Program
```java
public class TestCircleWithStaticMembers {
    public static void main(String[] args) {
        System.out.println("Before creating objects");
        System.out.println("The number of Circle objects is " +
            CircleWithStaticMembers.numberOfObjects);
        
        // Create c1
        CircleWithStaticMembers c1 = new CircleWithStaticMembers();
        
        // Display c1 BEFORE c2 is created
        System.out.println("\nAfter creating c1");
        System.out.println("c1: radius (" + c1.radius +
            ") and number of Circle objects (" +
            c1.numberOfObjects + ")");
        
        // Create c2
        CircleWithStaticMembers c2 = new CircleWithStaticMembers(5);
        
        // Modify c1
        c1.radius = 9;
        
        // Display c1 and c2 AFTER c2 was created
        System.out.println("\nAfter creating c2 and modifying c1");
        System.out.println("c1: radius (" + c1.radius +
            ") and number of Circle objects (" +
            c1.numberOfObjects + ")");
        System.out.println("c2: radius (" + c2.radius +
            ") and number of Circle objects (" +
            c2.numberOfObjects + ")");
    }
}
```

**Output:**
```
Before creating objects
The number of Circle objects is 0

After creating c1
c1: radius (1.0) and number of Circle objects (1)

After creating c2 and modifying c1
c1: radius (9.0) and number of Circle objects (2)
c2: radius (5.0) and number of Circle objects (2)
```

### Static Constants
Constants should be declared as `final static`:

```java
final static double PI = 3.14159265358979323846;
```

### Access Rules

#### What Instance Methods Can Access:
- ✅ Instance variables
- ✅ Instance methods
- ✅ Static variables
- ✅ Static methods

#### What Static Methods Can Access:
- ❌ Instance variables (directly)
- ❌ Instance methods (directly)
- ✅ Static variables
- ✅ Static methods

### Example of Access Rules

❌ **Wrong:**
```java
public class A {
    int i = 5;              // Instance variable
    static int k = 2;       // Static variable
    
    public static void main(String[] args) {
        int j = i;          // ERROR: Can't access instance variable
        m1();               // ERROR: Can't call instance method
    }
    
    public void m1() {      // Instance method
        // This is OK
    }
}
```

✅ **Correct:**
```java
public class A {
    int i = 5;              // Instance variable
    static int k = 2;       // Static variable
    
    public static void main(String[] args) {
        A a = new A();      // Create object first
        int j = a.i;        // OK: Access through object
        a.m1();             // OK: Call through object
    }
    
    public void m1() {      // Instance method
        i = i + k;          // OK: Instance method can access both
    }
}
```

### Design Guidelines

#### When to Use Instance Members:
- Variable/method depends on **specific instance**
- Example: `radius` in Circle class

#### When to Use Static Members:
- Variable/method **independent** of any specific instance
- Example: `Math.random()`, `Math.pow()`

### Best Practices
1. Use `ClassName.staticVariable` instead of `object.staticVariable`
2. Use `ClassName.staticMethod()` instead of `object.staticMethod()`
3. Improves code readability

---

## 8. Visibility Modifiers {#visibility}

### Modifier Types

#### public
- Accessible from **any other class**
- Can be used for classes, methods, and data fields

#### private
- Accessible only from **within its own class**
- Cannot be used for classes (only for class members)

#### Default (Package-private)
- Accessible by **any class in same package**
- Used when no modifier is specified

### Access Control Examples

#### Class C1 in Package p1:
```java
package p1;
public class C1 {
    public int x;        // public access
    int y;               // package access
    private int z;       // private access
    
    public void m1() { }     // public method
    void m2() { }            // package method
    private void m3() { }    // private method
}
```

#### Class C2 in Same Package (p1):
```java
package p1;
public class C2 {
    void aMethod() {
        C1 o = new C1();
        // ✅ can access o.x;      (public)
        // ✅ can access o.y;      (package)
        // ❌ cannot access o.z;   (private)
        // ✅ can invoke o.m1();   (public)
        // ✅ can invoke o.m2();   (package)
        // ❌ cannot invoke o.m3(); (private)
    }
}
```

#### Class C3 in Different Package (p2):
```java
package p2;
public class C3 {
    void aMethod() {
        C1 o = new C1();
        // ✅ can access o.x;      (public)
        // ❌ cannot access o.y;   (package)
        // ❌ cannot access o.z;   (private)
        // ✅ can invoke o.m1();   (public)
        // ❌ cannot invoke o.m2(); (package)
        // ❌ cannot invoke o.m3(); (private)
    }
}
```

### Class-Level Visibility

#### Public Class:
```java
public class C1 { }  // Accessible from any package
```

#### Package-Private Class:
```java
class C1 { }  // Accessible only within same package
```

### Access from Inside vs Outside Class

#### Inside Class (Allowed):
```java
public class C {
    private boolean x;
    
    public static void main(String[] args) {
        C c = new C();
        System.out.println(c.x);        // ✅ OK - inside class
        System.out.println(c.convert()); // ✅ OK - inside class
    }
    
    private int convert() {              // ✅ OK - inside class
        return x ? 1 : -1;
    }
}
```

#### Outside Class (Restricted):
```java
public class Test {
    public static void main(String[] args) {
        C c = new C();
        System.out.println(c.x);        // ❌ ERROR - private
        System.out.println(c.convert()); // ❌ ERROR - private
    }
}
```

### Private Constructor
Prevents object creation from outside the class:

```java
public class Math {
    private Math() {  // No one can create Math objects
    }
}
```

---

## 9. Data Field Encapsulation {#encapsulation}

### Why Encapsulate Data Fields?

#### Problems with Public Data Fields:
1. **Data Tampering**: Fields can be set to invalid values
2. **Maintenance Issues**: Changes require modifying client code
3. **No Control**: Cannot validate data before assignment

#### Example Problem:
```java
public class Circle {
    public double radius;  // Anyone can modify this!
}

// In client code:
Circle c = new Circle();
c.radius = -5;  // Invalid! But no way to prevent this
```

### Encapsulation Solution

#### Make Data Fields Private:
```java
public class Circle {
    private double radius;  // Protected from direct access
}
```

#### Provide Getter and Setter Methods:

```java
public class CircleWithPrivateDataFields {
    private double radius = 1;
    private static int numberOfObjects = 0;
    
    // Constructors
    public CircleWithPrivateDataFields() {
        numberOfObjects++;
    }
    
    public CircleWithPrivateDataFields(double newRadius) {
        radius = newRadius;
        numberOfObjects++;
    }
    
    // Getter method (Accessor)
    public double getRadius() {
        return radius;
    }
    
    // Setter method (Mutator)
    public void setRadius(double newRadius) {
        radius = (newRadius >= 0) ? newRadius : 0;  // Validation!
    }
    
    // Static getter
    public static int getNumberOfObjects() {
        return numberOfObjects;
    }
    
    // Other methods
    public double getArea() {
        return radius * radius * Math.PI;
    }
}
```

### Getter and Setter Conventions

#### Getter Methods:
```java
public returnType getPropertyName()
```

#### Boolean Getters:
```java
public boolean isPropertyName()  // For boolean properties
```

#### Setter Methods:
```java
public void setPropertyName(dataType propertyValue)
```

### Example Usage:
```java
public class TestCircleWithPrivateDataFields {
    public static void main(String[] args) {
        // Create a circle with radius 5.0
        CircleWithPrivateDataFields myCircle =
            new CircleWithPrivateDataFields(5.0);
        System.out.println("The area of the circle of radius "
            + myCircle.getRadius() + " is " + myCircle.getArea());
        
        // Increase myCircle's radius by 10%
        myCircle.setRadius(myCircle.getRadius() * 1.1);
        System.out.println("The area of the circle of radius "
            + myCircle.getRadius() + " is " + myCircle.getArea());
        
        System.out.println("The number of objects created is "
            + CircleWithPrivateDataFields.getNumberOfObjects());
    }
}
```

### Benefits of Encapsulation

1. **Data Protection**: Invalid values can be rejected
2. **Easy Maintenance**: Implementation can change without affecting clients
3. **Control**: Can add logging, validation, etc.
4. **Flexibility**: Can compute values instead of storing them

### UML Notation for Visibility

```
Circle
-----------------
-radius: double          (- indicates private)
-numberOfObjects: int    (- indicates private)
-----------------
+Circle()                (+ indicates public)
+getRadius(): double     (+ indicates public)
+setRadius(radius: double): void
+getArea(): double
+getNumberOfObjects(): int
```

---

## 10. Passing Objects to Methods {#passing-objects}

### Pass-by-Value Concept
Java uses **pass-by-value** for all parameters:
- **Primitive types**: Value is copied
- **Reference types**: Reference (address) is copied

### Simple Example

```java
public class Test {
    public static void main(String[] args) {
        CircleWithPrivateDataFields myCircle = 
            new CircleWithPrivateDataFields(5.0);
        printCircle(myCircle);  // Pass object reference
    }
    
    public static void printCircle(CircleWithPrivateDataFields c) {
        System.out.println("The area of the circle of radius "
            + c.getRadius() + " is " + c.getArea());
    }
}
```

### Detailed Example: TestPassObject

```java
public class TestPassObject {
    public static void main(String[] args) {
        // Create a Circle object with radius 1
        CircleWithPrivateDataFields myCircle =
            new CircleWithPrivateDataFields(1);
        
        // Print areas for radius 1, 2, 3, 4, and 5.
        int n = 5;
        printAreas(myCircle, n);
        
        // See myCircle.radius and n after method call
        System.out.println("\n" + "Radius is " + myCircle.getRadius());
        System.out.println("n is " + n);
    }
    
    public static void printAreas(
            CircleWithPrivateDataFields c, int times) {
        System.out.println("Radius \t\tArea");
        while (times >= 1) {
            System.out.println(c.getRadius() + "\t\t" + c.getArea());
            c.setRadius(c.getRadius() + 1);  // Modifies the object
            times--;                         // Modifies local copy
        }
    }
}
```

**Output:**
```
Radius		Area
1.0		3.141592653589793
2.0		12.566370614359172
3.0		29.274333882308138
4.0		50.26548245743669
5.0		79.53981633974483

Radius is 6.0    ← Object was modified
n is 5          ← Primitive value unchanged
```

### Memory Diagram Explanation

**Call Stack and Heap:**
```
Stack                    Heap
---------               --------
main method:            Circle Object
  n: 5         ------>  radius: 6.0
  myCircle: ref         numberOfObjects: 1

printAreas method:
  times: 0              (Same Circle Object)
  c: ref        ------>  radius: 6.0
```

### Key Points:

1. **Primitive Parameter** (`int times`):
   - Value `5` is copied to `times`
   - Changes to `times` don't affect `n`

2. **Reference Parameter** (`CircleWithPrivateDataFields c`):
   - Reference to object is copied to `c`
   - Both `myCircle` and `c` point to same object
   - Changes through `c` affect the object

### Pass-by-Sharing
Reference passing is often called **pass-by-sharing**:
- The object referenced in method is the same as the object being passed

### Practice Examples with Solutions

#### Example 1: Count Object
```java
public class Test {
    public static void main(String[] args) {
        Count myCount = new Count();  // count = 1
        int times = 0;
        for (int i = 0; i < 100; i++)
            increment(myCount, times);
        System.out.println("count is " + myCount.count);  // 101
        System.out.println("times is " + times);           // 0
    }
    
    public static void increment(Count c, int times) {
        c.count++;  // Modifies object through reference
        times++;    // Modifies local copy only
    }
}

class Count {
    public int count;
    
    public Count(int c) {
        count = c;
    }
    
    public Count() {
        count = 1;  // Default value
    }
}
```

**Output:**
```
count is 101
times is 0
```

**Explanation:**
- `myCount.count` starts at 1, incremented 100 times → 101
- `times` remains 0 because only local copy is modified

#### Example 2: Swap Methods
```java
public class Test {
    public static void main(String[] args) {
        Circle circle1 = new Circle(1);
        Circle circle2 = new Circle(2);
        
        swap1(circle1, circle2);
        System.out.println("After swap1: circle1 = " +
            circle1.radius + " circle2 = " + circle2.radius);
            
        swap2(circle1, circle2);
        System.out.println("After swap2: circle1 = " +
            circle1.radius + " circle2 = " + circle2.radius);
    }
    
    public static void swap1(Circle x, Circle y) {
        Circle temp = x;  // Swaps references locally
        x = y;
        y = temp;
    }
    
    public static void swap2(Circle x, Circle y) {
        double temp = x.radius;  // Swaps actual data
        x.radius = y.radius;
        y.radius = temp;
    }
}

class Circle {
    double radius;
    
    Circle(double newRadius) {
        radius = newRadius;
    }
}
```

**Output:**
```
After swap1: circle1 = 1.0 circle2 = 2.0
After swap2: circle1 = 2.0 circle2 = 1.0
```

**Explanation:**
- `swap1`: Only swaps local reference copies, original objects unchanged
- `swap2`: Swaps actual data in the objects

---

## 11. Array of Objects {#array-objects}

### Creating Array of Objects

#### Declaration and Creation:
```java
Circle[] circleArray = new Circle[10];  // Array of 10 Circle references
```

#### Initialization:
```java
for (int i = 0; i < circleArray.length; i++) {
    circleArray[i] = new Circle();  // Create actual Circle objects
}
```

### Important Notes:
1. Array of objects is actually **array of reference variables**
2. Each element initially contains **null**
3. Must create individual objects separately

### Memory Diagram:
```
circleArray -----> [ref0] -----> Circle object 0 (radius: ?)
                   [ref1] -----> Circle object 1 (radius: ?)
                   [ref2] -----> Circle object 2 (radius: ?)
                   ...
                   [ref9] -----> Circle object 9 (radius: ?)
```

### Complete Example: TotalArea Program

```java
public class TotalArea {
    public static void main(String[] args) {
        // Declare circleArray
        CircleWithPrivateDataFields[] circleArray;
        
        // Create circleArray
        circleArray = createCircleArray();
        
        // Print circleArray and total areas of the circles
        printCircleArray(circleArray);
    }
    
    /** Create an array of Circle objects */
    public static CircleWithPrivateDataFields[] createCircleArray() {
        CircleWithPrivateDataFields[] circleArray =
            new CircleWithPrivateDataFields[5];
        
        for (int i = 0; i < circleArray.length; i++) {
            circleArray[i] =
                new CircleWithPrivateDataFields(Math.random() * 100);
        }
        
        // Return Circle array
        return circleArray;
    }
    
    /** Print an array of circles and their total area */
    public static void printCircleArray(
            CircleWithPrivateDataFields[] circleArray) {
        System.out.printf("%-30s%-15s\n", "Radius", "Area");
        for (int i = 0; i < circleArray.length; i++) {
            System.out.printf("%-30f%-15f\n", 
                circleArray[i].getRadius(),
                circleArray[i].getArea());
        }
        
        System.out.println("────────────────────────────────────────────────");
        
        // Compute and display the result
        System.out.printf("%-30s%-15f\n", "The total area of circles is",
            sum(circleArray));
    }
    
    /** Add circle areas */
    public static double sum(CircleWithPrivateDataFields[] circleArray) {
        // Initialize sum
        double sum = 0;
        
        // Add areas to sum
        for (int i = 0; i < circleArray.length; i++)
            sum += circleArray[i].getArea();
        
        return sum;
    }
}
```

**Sample Output:**
```
Radius                        Area           
70.577708                     15649.941866   
44.152266                     6124.291736    
24.867853                     1942.792644    
5.680718                      101.380949     
36.734246                     4239.280350    
────────────────────────────────────────────────
The total area of circles is 28056.687544   
```

### Common Error Example:
```java
public class Test {
    public static void main(String[] args) {
        java.util.Date[] dates = new java.util.Date[10];
        System.out.println(dates[0]);           // Output: null
        System.out.println(dates[0].toString()); // NullPointerException!
    }
}
```

**Problem:** Array elements are null, need to create objects first:
```java
dates[0] = new java.util.Date();  // Create object first
System.out.println(dates[0].toString());  // Now it works
```

---

## 12. Immutable Objects and Classes {#immutable}

### Definition
- **Immutable Object**: Contents cannot be changed once created
- **Immutable Class**: Class that creates immutable objects

### Examples of Immutable Classes:
- `String` class
- Wrapper classes (`Integer`, `Double`, etc.)

### Requirements for Immutable Class:

1. **All data fields must be private**
2. **No mutator (setter) methods**
3. **No accessor methods that return mutable objects**

### Example: Student Class (Not Immutable)

```java
public class Student {
    private int id;
    private String name;
    private java.util.Date dateCreated;  // Mutable object!
    
    public Student(int ssn, String newName) {
        id = ssn;
        name = newName;
        dateCreated = new java.util.Date();
    }
    
    public int getId() {
        return id;
    }
    
    public String getName() {
        return name;
    }
    
    public java.util.Date getDateCreated() {
        return dateCreated;  // Returns reference to mutable object!
    }
}
```

#### Why Not Immutable?
```java
public class Test {
    public static void main(String[] args) {
        Student student = new Student(111223333, "John");
        java.util.Date dateCreated = student.getDateCreated();
        dateCreated.setTime(200000);  // Modifies the student's dateCreated!
    }
}
```

### Creating Immutable Student Class:

```java
public class ImmutableStudent {
    private final int id;
    private final String name;
    private final java.util.Date dateCreated;
    
    public ImmutableStudent(int ssn, String newName) {
        id = ssn;
        name = newName;
        dateCreated = new java.util.Date();
    }
    
    public int getId() {
        return id;
    }
    
    public String getName() {
        return name;
    }
    
    public java.util.Date getDateCreated() {
        return new java.util.Date(dateCreated.getTime());  // Return copy!
    }
}
```

### Benefits of Immutable Objects:

1. **Thread Safety**: No synchronization needed
2. **Security**: Cannot be modified accidentally
3. **Caching**: Hash codes can be cached
4. **Sharing**: Safe to share references

### Making Circle Immutable:
```java
public class ImmutableCircle {
    private final double radius;
    
    public ImmutableCircle() {
        radius = 1.0;
    }
    
    public ImmutableCircle(double newRadius) {
        radius = newRadius;
    }
    
    public double getRadius() {
        return radius;
    }
    
    public double getArea() {
        return radius * radius * Math.PI;
    }
    
    // No setRadius method - class is immutable
}
```

---

## 13. Scope of Variables {#scope}

### Variable Types and Scope:

1. **Class Variables (Data Fields)**: Scope is entire class
2. **Local Variables**: Scope is the block where declared
3. **Parameters**: Scope is the method

### Scope Rules:

#### Class Variables:
- Can be accessed from **anywhere in the class**
- Can be declared in **any order** (with exceptions)
- Include **instance** and **static** variables

#### Exception to Ordering:
```java
public class F {
    private int i;      // Must be declared before j
    private int j = i + 1;  // j depends on i
}
```

### Example: Variable Scope

```java
public class Circle {
    private double radius = 1;  // Class variable
    
    public double findArea() {
        return radius * radius * Math.PI;  // Can access radius
    }
    
    public void setRadius(double radius) {  // Parameter hides class variable
        this.radius = radius;  // Use 'this' to access class variable
    }
}
```

### Hidden Variables Example:

```java
public class F {
    private int x = 0;  // Instance variable
    private int y = 0;  // Instance variable
    
    public F() {
    }
    
    public void p() {
        int x = 1;  // Local variable hides instance variable
        System.out.println("x = " + x);  // Prints 1 (local variable)
        System.out.println("y = " + y);  // Prints 0 (instance variable)
    }
}
```

### Complex Scope Example:

```java
public class Test {
    private static int i = 0;  // Static variable
    private static int j = 0;  // Static variable
    
    public static void main(String[] args) {
        int i = 2;     // Local variable hides static variable
        int k = 3;     // Local variable
        {
            int j = 3; // Local variable hides static variable
            System.out.println("i + j is " + i + j);  // 23 (local vars)
        }
        k = i + j;     // i=2 (local), j=0 (static, local j out of scope)
        System.out.println("k is " + k);   // 2
        System.out.println("j is " + j);   // 0 (static variable)
    }
}
```

**Output:**
```
i + j is 23
k is 2
j is 0
```

### Best Practice:
**Avoid using class variable names as local variable names** to prevent confusion.

---

## 14. The this Reference {#this-reference}

### Purpose of 'this'
The `this` keyword refers to the **current object** - the object whose method is being called.

### Uses of 'this':

1. **Reference hidden data fields**
2. **Invoke other constructors**
3. **Pass current object to other methods**
4. **Make code more readable**

### Example 1: Referencing Hidden Data Fields

```java
public class Circle {
    private double radius;
    
    public Circle(double radius) {
        this.radius = radius;  // 'this.radius' is instance variable
                              // 'radius' is parameter
    }
    
    public void setRadius(double radius) {
        this.radius = radius;  // Distinguish between parameter and field
    }
    
    public double getRadius() {
        return this.radius;    // 'this' is optional here
        // return radius;      // Same as above
    }
}
```

### Example 2: Static vs Instance Context

```java
public class F {
    private int i = 5;              // Instance variable
    private static double k = 0;    // Static variable
    
    public void setI(int i) {
        this.i = i;  // 'this' refers to calling object
    }
    
    public static void setK(double k) {
        F.k = k;     // Use class name for static variable
        // this.k = k;  // ERROR: 'this' not available in static context
    }
}
```

#### Usage:
```java
F f1 = new F();
F f2 = new F();

f1.setI(10);  // this.i = 10, where 'this' refers to f1
f2.setI(45);  // this.i = 45, where 'this' refers to f2
F.setK(33);   // F.k = 33 (static method)
```

### Example 3: Constructor Chaining

```java
public class Circle {
    private double radius;
    
    public Circle(double radius) {
        this.radius = radius;
    }
    
    public Circle() {
        this(1.0);  // Call other constructor with default radius
    }
    
    // Could also have:
    public Circle(int diameter) {
        this(diameter / 2.0);  // Call first constructor
    }
}
```

### Constructor Chaining Rules:

1. **Must be first statement** in constructor
2. **Cannot call constructor from regular method**
3. **Cannot have recursive constructor calls**

#### Example of Constructor Chaining:
```java
public class Student {
    private String name;
    private int age;
    private String major;
    
    // Most comprehensive constructor
    public Student(String name, int age, String major) {
        this.name = name;
        this.age = age;
        this.major = major;
    }
    
    // Constructor with default major
    public Student(String name, int age) {
        this(name, age, "Undeclared");  // Call 3-parameter constructor
    }
    
    // Constructor with default age and major
    public Student(String name) {
        this(name, 18);  // Call 2-parameter constructor
    }
    
    // Default constructor
    public Student() {
        this("Unknown");  // Call 1-parameter constructor
    }
}
```

### Common Errors:

#### Error 1: Wrong placement of this()
```java
public class C {
    private int p;
    
    public C() {
        System.out.println("C's no-arg constructor invoked");
        this(0);  // ERROR: this() must be first statement
    }
    
    public C(int p) {
        this.p = p;
    }
}
```

#### Error 2: Wrong assignment in setter
```java
public class C {
    private int p;
    
    public void setP(int p) {
        p = p;  // ERROR: assigns parameter to itself
                // Should be: this.p = p;
    }
}
```

#### Error 3: Using this with static
```java
public class Test {
    private int id;
    
    public void m1() {
        this.id = 45;  // OK: this available in instance method
    }
    
    public static void m2() {
        this.id = 45;  // ERROR: this not available in static method
    }
}
```

### When 'this' is Optional:

```java
public class Circle {
    private double radius;
    
    public double getArea() {
        // These are equivalent:
        return this.radius * this.radius * Math.PI;
        return radius * radius * Math.PI;
    }
    
    public String toString() {
        // These are equivalent:
        return "radius: " + this.radius + " area: " + this.getArea();
        return "radius: " + radius + " area: " + getArea();
    }
}
```

### Best Practices:

1. **Use this** when parameter names match field names
2. **Use this()** for constructor chaining
3. **Optional this** can improve code clarity
4. **Avoid this** in static methods (causes compile error)

---

## Key Terms Summary

| Term | Definition |
|------|------------|
| **Object** | An instance of a class representing a real-world entity |
| **Class** | A template/blueprint defining object structure and behavior |
| **Constructor** | Special method to initialize objects (same name as class, no return type) |
| **Instance Variable** | Data field belonging to specific object |
| **Static Variable** | Data field shared by all objects of the class |
| **Instance Method** | Method that operates on specific object |
| **Static Method** | Method that can be called without creating object |
| **Encapsulation** | Making data fields private and providing getter/setter methods |
| **this** | Reference to current object |
| **null** | Special value indicating no object reference |
| **Pass-by-value** | Java's parameter passing mechanism |
| **Immutable** | Object whose state cannot be changed after creation |
| **UML** | Unified Modeling Language for class diagrams |

---

## Important Checkpoint Questions and Answers

### Section 9.2-9.3 Questions:

**Q9.1:** Describe the relationship between an object and its defining class.
**Answer:** A class is a template or blueprint that defines the structure and behavior of objects. An object is a specific instance of a class. The relationship is similar to a cookie cutter (class) and the cookies made from it (objects).

**Q9.2:** How do you define a class?
**Answer:** 
```java
[visibility] class ClassName {
    // Data fields
    // Constructors  
    // Methods
}
```

**Q9.3:** How do you declare an object's reference variable?
**Answer:** `ClassName objectRefVar;`

**Q9.4:** How do you create an object?
**Answer:** `objectRefVar = new ClassName();` or combined: `ClassName objectRefVar = new ClassName();`

### Section 9.4 Questions:

**Q9.5:** What are the differences between constructors and methods?
**Answer:** 
- Constructors: Same name as class, no return type, called with `new`
- Methods: Any name, have return type, called on objects

**Q9.6:** When will a class have a default constructor?
**Answer:** Only when no constructors are explicitly defined in the class.

### Section 9.7 Questions:

**Q9.17:** For class F, which statements are correct?
```java
public class F {
    int i;
    static String s;
    void imethod() { }
    static void smethod() { }
}
```

**Answer:** 
- `f.i` ✅, `f.s` ✅, `f.imethod()` ✅, `f.smethod()` ✅
- `F.i` ❌, `F.s` ✅, `F.imethod()` ❌, `F.smethod()` ✅

---

This comprehensive guide covers all major concepts from Chapter 9 on Objects and Classes, with detailed explanations, examples, and practice problems to ensure thorough understanding of OOP fundamentals in Java.
