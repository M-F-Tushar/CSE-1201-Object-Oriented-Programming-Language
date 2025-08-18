# Chapter 13: Abstract Classes and Interfaces - Complete Study Guide

## Table of Contents
1. [Introduction](#1-introduction)
2. [Abstract Classes](#2-abstract-classes)
3. [Case Study: The Abstract Number Class](#3-case-study-the-abstract-number-class)
4. [Case Study: Calendar and GregorianCalendar](#4-case-study-calendar-and-gregoriancalendar)
5. [Interfaces](#5-interfaces)
6. [The Comparable Interface](#6-the-comparable-interface)
7. [The Cloneable Interface](#7-the-cloneable-interface)
8. [Interfaces vs. Abstract Classes](#8-interfaces-vs-abstract-classes)
9. [Case Study: The Rational Class](#9-case-study-the-rational-class)
10. [Class Design Guidelines](#10-class-design-guidelines)

---

## 1. Introduction

### Key Concepts
- **Superclass**: Defines common behavior for related subclasses
- **Interface**: Defines common behavior for classes (including unrelated classes)
- **Problem**: How to sort geometric objects using the same method used for numbers/strings?

### Real-World Example
Imagine you want to use `java.util.Arrays.sort()` method to sort different types of objects:
- Numbers ✓ (works)
- Strings ✓ (works)  
- Geometric objects ❌ (doesn't work without interfaces)

**Why interfaces are needed**: To enable common operations on unrelated classes.

---

## 2. Abstract Classes

### 2.1 Definition and Purpose

#### What is an Abstract Class?
- **Cannot be instantiated** using the `new` operator
- Can contain **abstract methods** (methods without implementation)
- Used when a superclass is too general to create specific instances

#### Key Characteristics
- Contains common features for subclasses
- May have abstract methods that must be implemented by subclasses
- Denoted with `abstract` modifier
- In UML: class and method names are *italicized*

### 2.2 Example: GeometricObject Abstract Class

```java
public abstract class GeometricObject {
    private String color = "white";
    private boolean filled;
    private java.util.Date dateCreated;
    
    // Protected constructors (used by subclasses)
    protected GeometricObject() {
        dateCreated = new java.util.Date();
    }
    
    protected GeometricObject(String color, boolean filled) {
        dateCreated = new java.util.Date();
        this.color = color;
        this.filled = filled;
    }
    
    // Concrete methods
    public String getColor() { return color; }
    public void setColor(String color) { this.color = color; }
    public boolean isFilled() { return filled; }
    public void setFilled(boolean filled) { this.filled = filled; }
    public java.util.Date getDateCreated() { return dateCreated; }
    
    @Override
    public String toString() {
        return "created on " + dateCreated + "\ncolor: " + color + 
               " and filled: " + filled;
    }
    
    // Abstract methods (must be implemented by subclasses)
    public abstract double getArea();
    public abstract double getPerimeter();
}
```

### 2.3 Implementing Abstract Classes

#### Circle Class Implementation
```java
public class Circle extends GeometricObject {
    private double radius;
    
    public Circle() { }
    
    public Circle(double radius) {
        this.radius = radius;
    }
    
    public Circle(double radius, String color, boolean filled) {
        this.radius = radius;
        setColor(color);
        setFilled(filled);
    }
    
    // Must implement abstract methods
    @Override
    public double getArea() {
        return radius * radius * Math.PI;
    }
    
    @Override
    public double getPerimeter() {
        return 2 * radius * Math.PI;
    }
    
    public double getRadius() { return radius; }
    public void setRadius(double radius) { this.radius = radius; }
}
```

#### Rectangle Class Implementation
```java
public class Rectangle extends GeometricObject {
    private double width;
    private double height;
    
    public Rectangle() { }
    
    public Rectangle(double width, double height) {
        this.width = width;
        this.height = height;
    }
    
    // Must implement abstract methods
    @Override
    public double getArea() {
        return width * height;
    }
    
    @Override
    public double getPerimeter() {
        return 2 * (width + height);
    }
    
    // Getters and setters
    public double getWidth() { return width; }
    public void setWidth(double width) { this.width = width; }
    public double getHeight() { return height; }
    public void setHeight(double height) { this.height = height; }
}
```

### 2.4 Benefits of Abstract Methods

#### Test Program Demonstrating Benefits
```java
public class TestGeometricObject {
    public static void main(String[] args) {
        // Create geometric objects
        GeometricObject geoObject1 = new Circle(5);
        GeometricObject geoObject2 = new Rectangle(5, 3);
        
        System.out.println("The two objects have the same area? " +
                          equalArea(geoObject1, geoObject2));
        
        // Display objects
        displayGeometricObject(geoObject1);
        displayGeometricObject(geoObject2);
    }
    
    // Method for comparing areas (works because of abstract methods)
    public static boolean equalArea(GeometricObject object1,
                                   GeometricObject object2) {
        return object1.getArea() == object2.getArea();
    }
    
    // Method for displaying geometric objects
    public static void displayGeometricObject(GeometricObject object) {
        System.out.println();
        System.out.println("The area is " + object.getArea());
        System.out.println("The perimeter is " + object.getPerimeter());
    }
}
```

**Output:**
```
The two objects have the same area? false
The area is 78.53981633974483
The perimeter is 31.41592653589793
The area is 15.0
The perimeter is 16.0
```

**Why this works:**
- `geoObject1.getArea()` calls `Circle`'s implementation
- `geoObject2.getArea()` calls `Rectangle`'s implementation  
- JVM dynamically determines which method to invoke at runtime

### 2.5 Important Points About Abstract Classes

#### Rules and Restrictions
1. **Abstract methods in abstract classes only**: Non-abstract classes cannot contain abstract methods
2. **Complete implementation required**: Non-abstract subclasses must implement ALL abstract methods
3. **Cannot instantiate**: `new GeometricObject()` ❌ causes compilation error
4. **Constructors allowed**: Abstract classes can have constructors for subclass initialization
5. **Abstract without abstract methods**: Possible but unusual
6. **Method override to abstract**: Subclass can override concrete method as abstract
7. **Concrete superclass**: Abstract class can extend concrete class

#### Usage as Data Type
```java
// Valid - using abstract class as array type
GeometricObject[] objects = new GeometricObject[10];

// Valid - assigning concrete instances
objects[0] = new Circle(5);
objects[1] = new Rectangle(3, 4);

// Invalid - cannot instantiate abstract class
// GeometricObject obj = new GeometricObject(); ❌
```

### 2.6 Check Point Exercises

**Exercise 13.1**: Which of the following classes defines a legal abstract class?

```java
// (a) ❌ - Abstract method cannot have implementation
class A {
    abstract void unfinished() { }
}

// (b) ❌ - Wrong syntax order
public class abstract A {
    abstract void unfinished();
}

// (c) ❌ - Non-abstract class cannot have abstract method
class A {
    abstract void unfinished();
}

// (d) ❌ - Abstract method must be abstract
abstract class A {
    protected void unfinished();
}

// (e) ✓ - Correct
abstract class A {
    abstract void unfinished();
}

// (f) ✓ - Correct with return type
abstract class A {
    abstract int unfinished();
}
```

**Exercise 13.2**: Benefits of defining `getArea()` and `getPerimeter()` as abstract methods:
- Enables polymorphic behavior
- Allows methods like `equalArea()` to work with any geometric object
- Enforces implementation in subclasses
- Provides common interface for all geometric objects

**Exercise 13.3**: True or False?
- (a) **False** - Abstract classes cannot be instantiated
- (b) **True** - Abstract classes can be extended
- (c) **False** - Subclass of concrete class can be abstract
- (d) **False** - Subclass can override concrete method to be abstract
- (e) **True** - Abstract methods must be non-static

---

## 3. Case Study: The Abstract Number Class

### 3.1 The Number Class Hierarchy

#### Class Structure
```
java.lang.Number (abstract)
├── Double
├── Float  
├── Long
├── Integer
├── Short
├── Byte
├── BigInteger
└── BigDecimal
```

#### Abstract and Concrete Methods in Number Class
```java
public abstract class Number {
    // Abstract methods (must be implemented by subclasses)
    public abstract int intValue();
    public abstract long longValue(); 
    public abstract float floatValue();
    public abstract double doubleValue();
    
    // Concrete methods (implemented using abstract methods)
    public byte byteValue() {
        return (byte)intValue();
    }
    
    public short shortValue() {
        return (short)intValue();
    }
}
```

### 3.2 Practical Example: Finding Largest Number

```java
import java.util.ArrayList;
import java.math.*;

public class LargestNumbers {
    public static void main(String[] args) {
        ArrayList<Number> list = new ArrayList<>();
        list.add(45);                    // Integer (autoboxed)
        list.add(3445.53);              // Double (autoboxed)
        list.add(new BigInteger("3432323234344343101"));
        list.add(new BigDecimal("2.0909090989091343433344343"));
        
        System.out.println("The largest number is " + 
                          getLargestNumber(list));
    }
    
    public static Number getLargestNumber(ArrayList<Number> list) {
        if (list == null || list.size() == 0)
            return null;
            
        Number number = list.get(0);
        for (int i = 1; i < list.size(); i++)
            if (number.doubleValue() < list.get(i).doubleValue())
                number = list.get(i);
                
        return number;
    }
}
```

**Output:** `The largest number is 3432323234344343101`

**Key Point**: The `doubleValue()` method allows comparison of different numeric types.

### 3.3 Check Point Exercises

**Exercise 13.4**: Why does this cause runtime error?
```java
Number numberRef = new Integer(0);
Double doubleRef = (Double)numberRef;  // ❌ ClassCastException
```
**Answer**: `numberRef` refers to an `Integer` object, not a `Double` object. Cannot cast `Integer` to `Double`.

**Exercise 13.5**: Why does this cause runtime error?
```java
Number[] numberArray = new Integer[2];
numberArray[0] = new Double(1.5);  // ❌ ArrayStoreException
```
**Answer**: Array was created for `Integer` objects, cannot store `Double` objects.

**Exercise 13.6**: Show output:
```java
public class Test {
    public static void main(String[] args) {
        Number x = 3;  // Autoboxed to Integer
        System.out.println(x.intValue());     // 3
        System.out.println(x.doubleValue());  // 3.0
    }
}
```

**Exercise 13.7**: What's wrong?
```java
Number x = new Integer(3);
System.out.println(x.compareTo(new Integer(4)));  // ❌
```
**Answer**: `Number` class doesn't have `compareTo` method. Only specific classes like `Integer` implement `Comparable`.

**Exercise 13.8**: What's wrong?  
```java
Number x = new Integer(3);
System.out.println((Integer)x.compareTo(new Integer(4)));  // ❌
```
**Answer**: Wrong casting syntax. Should be `((Integer)x).compareTo(new Integer(4))`.

---

## 4. Case Study: Calendar and GregorianCalendar

### 4.1 Calendar Class Hierarchy

```java
java.util.Calendar (abstract)
└── java.util.GregorianCalendar (concrete)
```

### 4.2 Key Features

#### Abstract Method
- `add(int field, int amount)` - Implementation depends on calendar system

#### Field Constants
| Constant | Description |
|----------|-------------|
| `YEAR` | The year of the calendar |
| `MONTH` | The month (0-based: 0=January) |
| `DATE` | The day of the calendar |
| `HOUR` | Hour (12-hour notation) |
| `HOUR_OF_DAY` | Hour (24-hour notation) |
| `MINUTE` | The minute |
| `SECOND` | The second |
| `DAY_OF_WEEK` | Day within week (1=Sunday) |
| `DAY_OF_MONTH` | Same as DATE |
| `DAY_OF_YEAR` | Day number in year |
| `WEEK_OF_MONTH` | Week number within month |
| `WEEK_OF_YEAR` | Week number within year |
| `AM_PM` | AM/PM indicator (0=AM, 1=PM) |

### 4.3 Practical Example

```java
import java.util.*;

public class TestCalendar {
    public static void main(String[] args) {
        // Create calendar for current time
        Calendar calendar = new GregorianCalendar();
        System.out.println("Current time is " + new Date());
        System.out.println("YEAR: " + calendar.get(Calendar.YEAR));
        System.out.println("MONTH: " + calendar.get(Calendar.MONTH));
        System.out.println("DATE: " + calendar.get(Calendar.DATE));
        System.out.println("HOUR: " + calendar.get(Calendar.HOUR));
        System.out.println("HOUR_OF_DAY: " + calendar.get(Calendar.HOUR_OF_DAY));
        System.out.println("MINUTE: " + calendar.get(Calendar.MINUTE));
        System.out.println("SECOND: " + calendar.get(Calendar.SECOND));
        System.out.println("DAY_OF_WEEK: " + calendar.get(Calendar.DAY_OF_WEEK));
        System.out.println("DAY_OF_MONTH: " + calendar.get(Calendar.DAY_OF_MONTH));
        System.out.println("DAY_OF_YEAR: " + calendar.get(Calendar.DAY_OF_YEAR));
        System.out.println("WEEK_OF_MONTH: " + calendar.get(Calendar.WEEK_OF_MONTH));
        System.out.println("WEEK_OF_YEAR: " + calendar.get(Calendar.WEEK_OF_YEAR));
        System.out.println("AM_PM: " + calendar.get(Calendar.AM_PM));
        
        // Create specific calendar
        Calendar calendar1 = new GregorianCalendar(2001, 8, 11); // Sept 11, 2001
        String[] dayNameOfWeek = {"Sunday", "Monday", "Tuesday", "Wednesday",
                                 "Thursday", "Friday", "Saturday"};
        System.out.println("September 11, 2001 is a " +
            dayNameOfWeek[calendar1.get(Calendar.DAY_OF_WEEK) - 1]);
    }
}
```

### 4.4 Common Calendar Operations

```java
Calendar cal = new GregorianCalendar();

// Set specific field
cal.set(Calendar.DAY_OF_MONTH, 1);

// Add/subtract time
cal.add(Calendar.DAY_OF_MONTH, 5);    // Add 5 days
cal.add(Calendar.DAY_OF_MONTH, -5);   // Subtract 5 days

// Get maximum days in month
int maxDays = cal.getActualMaximum(Calendar.DAY_OF_MONTH);

// Convert between Calendar and Date
Date date = cal.getTime();    // Calendar to Date
cal.setTime(date);           // Date to Calendar
```

### 4.5 Check Point Exercises

**Exercise 13.9**: Can you create a Calendar object using the Calendar class?
**Answer**: No, Calendar is abstract. Use `new GregorianCalendar()`.

**Exercise 13.10**: Which method in Calendar class is abstract?
**Answer**: `add(int field, int amount)` method.

**Exercise 13.11**: How do you create a Calendar object for current time?
**Answer**: `Calendar calendar = new GregorianCalendar();`

**Exercise 13.12**: How do you get calendar components?
```java
Calendar c = new GregorianCalendar();
int year = c.get(Calendar.YEAR);
int month = c.get(Calendar.MONTH);
int date = c.get(Calendar.DATE);
int hour = c.get(Calendar.HOUR_OF_DAY);
int minute = c.get(Calendar.MINUTE);
int second = c.get(Calendar.SECOND);
```

---

## 5. Interfaces

### 5.1 Introduction to Interfaces

#### Definition
An **interface** is a class-like construct that contains:
- **Only constants** (public static final)
- **Only abstract methods** (public abstract)

#### Syntax
```java
modifier interface InterfaceName {
    /** Constant declarations */
    /** Abstract method signatures */
}
```

#### Key Characteristics
- Compiled into separate bytecode file
- Cannot be instantiated with `new` operator
- Can be used as data type for reference variables
- Classes implement interfaces using `implements` keyword

### 5.2 Example: Edible Interface

#### Interface Definition
```java
public interface Edible {
    /** Describe how to eat */
    public abstract String howToEat();
}
```

#### Implementation Classes
```java
// Abstract class Animal
abstract class Animal {
    public abstract String sound();
}

// Chicken implements both Animal and Edible
class Chicken extends Animal implements Edible {
    @Override
    public String howToEat() {
        return "Chicken: Fry it";
    }
    
    @Override
    public String sound() {
        return "Chicken: cock-a-doodle-doo";
    }
}

// Tiger extends Animal (not edible)
class Tiger extends Animal {
    @Override
    public String sound() {
        return "Tiger: RROOAARR";
    }
}

// Abstract Fruit implements Edible
abstract class Fruit implements Edible {
    // Data fields, constructors, and methods omitted
}

// Concrete fruit classes
class Apple extends Fruit {
    @Override
    public String howToEat() {
        return "Apple: Make apple cider";
    }
}

class Orange extends Fruit {
    @Override
    public String howToEat() {
        return "Orange: Make orange juice";
    }
}
```

#### Test Program
```java
public class TestEdible {
    public static void main(String[] args) {
        Object[] objects = {new Tiger(), new Chicken(), new Apple()};
        
        for (int i = 0; i < objects.length; i++) {
            if (objects[i] instanceof Edible)
                System.out.println(((Edible)objects[i]).howToEat());
                
            if (objects[i] instanceof Animal) {
                System.out.println(((Animal)objects[i]).sound());
            }
        }
    }
}
```

**Output:**
```
Tiger: RROOAARR
Chicken: Fry it
Chicken: cock-a-doodle-doo
Apple: Make apple cider
```

### 5.3 Interface Properties

#### Modifier Shortcuts
Since all interface members have default modifiers, these are equivalent:

```java
// Explicit modifiers
public interface T {
    public static final int K = 1;
    public abstract void p();
}

// Implicit modifiers (preferred)
public interface T {
    int K = 1;
    void p();
}
```

### 5.4 Check Point Exercises

**Exercise 13.13**: Can you create instance using `new A()` if A is interface?
**Answer**: No, interfaces cannot be instantiated.

**Exercise 13.14**: Can you declare reference variable with interface type?
```java
A x;  // ✓ Valid - interfaces can be used as types
```

**Exercise 13.15**: Which is correct interface?
```java
// (a) ❌ - Cannot have method implementation
interface A {
    void print() { };
}

// (b) ❌ - Wrong extends syntax, cannot have implementation  
abstract interface A extends I1, I2 {
    abstract void print() { };
}

// (c) ❌ - Missing return type
abstract interface A {
    print();
}

// (d) ✓ - Correct
interface A {
    void print();
}
```

**Exercise 13.16**: Show error in code:
```java
interface A {
    void m1();
}
class B implements A {
    void m1() {           // ❌ Missing public modifier
        System.out.println("m1");
    }
}
```
**Answer**: Interface methods are public by default, so implementation must be public.

---

## 6. The Comparable Interface

### 6.1 Introduction

#### Purpose
The `Comparable` interface enables objects to be compared and sorted.

#### Interface Definition
```java
package java.lang;
public interface Comparable<E> {
    public int compareTo(E o);
}
```

#### Return Values of compareTo()
- **Negative integer**: this object < specified object
- **Zero**: this object == specified object  
- **Positive integer**: this object > specified object

### 6.2 Classes Implementing Comparable

#### Built-in Classes
- `Byte`, `Short`, `Integer`, `Long`
- `Float`, `Double`
- `Character`
- `BigInteger`, `BigDecimal`
- `String`
- `Date`, `Calendar`

#### Example Comparisons
```java
System.out.println(new Integer(3).compareTo(new Integer(5)));  // -1 (3 < 5)
System.out.println("ABC".compareTo("ABE"));                    // -2 (ABC < ABE)

java.util.Date date1 = new java.util.Date(2013, 1, 1);
java.util.Date date2 = new java.util.Date(2012, 1, 1);  
System.out.println(date1.compareTo(date2));                    // 1 (date1 > date2)
```

### 6.3 Sorting Comparable Objects

#### Example: Sorting Different Types
```java
import java.math.*;

public class SortComparableObjects {
    public static void main(String[] args) {
        // Sort strings
        String[] cities = {"Savannah", "Boston", "Atlanta", "Tampa"};
        java.util.Arrays.sort(cities);
        for (String city: cities)
            System.out.print(city + " ");
        System.out.println();
        
        // Sort BigInteger objects  
        BigInteger[] hugeNumbers = {
            new BigInteger("2323231092923992"),
            new BigInteger("432232323239292"), 
            new BigInteger("54623239292")
        };
        java.util.Arrays.sort(hugeNumbers);
        for (BigInteger number: hugeNumbers)
            System.out.print(number + " ");
    }
}
```

**Output:**
```
Atlanta Boston Savannah Tampa
54623239292 432232323239292 2323231092923992
```

### 6.4 Creating Comparable Classes

#### Example: ComparableRectangle
```java
public class ComparableRectangle extends Rectangle 
                                implements Comparable<ComparableRectangle> {
    
    public ComparableRectangle(double width, double height) {
        super(width, height);
    }
    
    @Override
    public int compareTo(ComparableRectangle o) {
        if (getArea() > o.getArea())
            return 1;
        else if (getArea() < o.getArea())
            return -1;
        else
            return 0;
    }
    
    @Override
    public String toString() {
        return super.toString() + " Area: " + getArea();
    }
}
```

#### Sorting Rectangle Objects
```java
public class SortRectangles {
    public static void main(String[] args) {
        ComparableRectangle[] rectangles = {
            new ComparableRectangle(3.4, 5.4),
            new ComparableRectangle(13.24, 55.4),
            new ComparableRectangle(7.4, 35.4),
            new ComparableRectangle(1.4, 25.4)
        };
        
        java.util.Arrays.sort(rectangles);
        for (Rectangle rectangle: rectangles) {
            System.out.println(rectangle + " ");
        }
    }
}
```

**Output:**
```
Width: 3.4 Height: 5.4 Area: 18.36
Width: 1.4 Height: 25.4 Area: 35.559999999999995
Width: 7.4 Height: 35.4 Area: 261.96
Width: 13.24 Height: 55.4 Area: 733.496
```

### 6.5 Check Point Exercises

**Exercise 13.17**: True or false? If class implements Comparable, object can invoke compareTo method.
**Answer**: True.

**Exercise 13.18**: Correct method header for compareTo in String class?
**Answer**: `public int compareTo(String o)` - uses generic type.

**Exercise 13.19**: Can this code be compiled?
```java
Integer n1 = new Integer(3);
Object n2 = new Integer(4);
System.out.println(n1.compareTo(n2));  // ❌
```
**Answer**: No, `compareTo` expects `Integer` parameter, but `n2` is `Object` type.

**Exercise 13.20**: Benefits of implementing Comparable interface?
**Answer**: 
- Objects can be sorted using `Arrays.sort()`
- Objects work with other generic algorithms
- Consistent comparison behavior across applications

**Exercise 13.21**: What's wrong in this code?
```java
public class Test {
    public static void main(String[] args) {
        Person[] persons = {new Person(3), new Person(4), new Person(1)};
        java.util.Arrays.sort(persons);  // ❌
    }
}

class Person {
    private int id;
    Person(int id) { this.id = id; }
}
```
**Answer**: `Person` class doesn't implement `Comparable` interface.

---

## 7. The Cloneable Interface

### 7.1 Introduction

#### Definition
```java
package java.lang;
public interface Cloneable {
    // Empty interface - marker interface
}
```

#### Purpose
- **Marker interface**: Indicates class supports cloning
- Objects of implementing classes can be cloned using `clone()` method
- `clone()` method is defined in `Object` class

### 7.2 Cloning Examples

#### Cloning Calendar Objects
```java
Calendar calendar = new GregorianCalendar(2013, 2, 1);
Calendar calendar1 = calendar;                    // Reference copy
Calendar calendar2 = (Calendar)calendar.clone(); // Object copy

System.out.println("calendar == calendar1 is " + (calendar == calendar1));     // true
System.out.println("calendar == calendar2 is " + (calendar == calendar2));     // false
System.out.println("calendar.equals(calendar2) is " + calendar.equals(calendar2)); // true
```

#### Cloning ArrayList Objects
```java
ArrayList<Double> list1 = new ArrayList<>();
list1.add(1.5);
list1.add(2.5);
list1.add(3.5);

ArrayList<Double> list2 = (ArrayList<Double>)list1.clone(); // Clone
ArrayList<Double> list3 = list1;                            // Reference copy

list2.add(4.5);      // Only affects list2
list3.remove(1.5);   // Affects both list1 and list3

System.out.println("list1 is " + list1);  // [2.5, 3.5]
System.out.println("list2 is " + list2);  // [1.5, 2.5, 3.5, 4.5]  
System.out.println("list3 is " + list3);  // [2.5, 3.5]
```

#### Cloning Arrays
```java
int[] list1 = {1, 2};
int[] list2 = list1.clone();
list1[0] = 7;
list2[1] = 8;

System.out.println("list1 is " + list1[0] + ", " + list1[1]); // list1 is 7, 2
System.out.println("list2 is " + list2[0] + ", " + list2[1]); // list2 is 1, 8
```

### 7.3 Implementing Cloneable Interface

#### House Class Example
```java
public class House implements Cloneable, Comparable<House> {
    private int id;
    private double area;
    private java.util.Date whenBuilt;
    
    public House(int id, double area) {
        this.id = id;
        this.area = area;
        whenBuilt = new java.util.Date();
    }
    
    public int getId() { return id; }
    public double getArea() { return area; }
    public java.util.Date getWhenBuilt() { return whenBuilt; }
    
    @Override
    public Object clone() throws CloneNotSupportedException {
        return super.clone();  // Shallow copy
    }
    
    @Override
    public int compareTo(House o) {
        if (area > o.area)
            return 1;
        else if (area < o.area)
            return -1;
        else
            return 0;
    }
}
```

### 7.4 Shallow vs Deep Copy

#### Shallow Copy (Default)
- Copies primitive values directly
- Copies object references (not object contents)
- Default behavior of `Object.clone()`

#### Deep Copy (Custom Implementation)
```java
@Override
public Object clone() throws CloneNotSupportedException {
    // Perform shallow copy first
    House houseClone = (House)super.clone();
    // Deep copy for object fields
    houseClone.whenBuilt = (java.util.Date)(whenBuilt.clone());
    return houseClone;
}
```

#### Alternative Deep Copy (Handle Exception)
```java
@Override
public Object clone() {
    try {
        House houseClone = (House)super.clone();
        houseClone.whenBuilt = (java.util.Date)(whenBuilt.clone());
        return houseClone;
    }
    catch (CloneNotSupportedException ex) {
        return null;
    }
}
```

### 7.5 Check Point Exercises

**Exercise 13.22**: Can you invoke clone() if class doesn't implement Cloneable? Does Date implement Cloneable?
**Answer**: 
- No, `CloneNotSupportedException` will be thrown if class doesn't implement `Cloneable`
- Yes, `Date` class implements `Cloneable` interface

**Exercise 13.23**: What happens if House class didn't override clone() or didn't implement Cloneable?
**Answer**: 
- If doesn't override `clone()`: Cannot access method (it's protected in Object)
- If doesn't implement `Cloneable`: `CloneNotSupportedException` thrown at runtime

**Exercise 13.24**: Show output:
```java
java.util.Date date = new java.util.Date();
java.util.Date date1 = date;
java.util.Date date2 = (java.util.Date)(date.clone());
System.out.println(date == date1);        // true
System.out.println(date == date2);        // false  
System.out.println(date.equals(date2));   // true
```

**Exercise 13.25**: Show output:
```java
ArrayList<String> list = new ArrayList<>();
list.add("New York");
ArrayList<String> list1 = list;
ArrayList<String> list2 = (ArrayList<String>)(list.clone());
list.add("Atlanta");
System.out.println(list == list1);           // true
System.out.println(list == list2);           // false
System.out.println("list is " + list);       // [New York, Atlanta]
System.out.println("list1 is " + list1);     // [New York, Atlanta]
System.out.println("list2.get(0) is " + list2.get(0)); // New York
System.out.println("list2.size() is " + list2.size()); // 1
```

**Exercise 13.26**: What's wrong in this code?
```java
public class Test {
    public static void main(String[] args) {
        GeometricObject x = new Circle(3);
        GeometricObject y = x.clone();  // ❌
        System.out.println(x == y);
    }
}
```
**Answer**: `GeometricObject` doesn't implement `Cloneable` interface and doesn't have accessible `clone()` method.

---

## 8. Interfaces vs. Abstract Classes

### 8.1 Comparison Table

| Feature | Abstract Classes | Interfaces |
|---------|------------------|------------|
| **Variables** | No restrictions | Must be `public static final` |
| **Constructors** | Can have constructors (for subclass initialization) | Cannot have constructors |
| **Methods** | Any combination of concrete and abstract methods | Only `public abstract` methods |
| **Instantiation** | Cannot instantiate with `new` | Cannot instantiate with `new` |
| **Inheritance** | Single inheritance only | Multiple inheritance allowed |
| **Access Modifiers** | Any access modifier | All members implicitly `public` |

### 8.2 Multiple Inheritance

#### Class Inheritance (Single)
```java
public class NewClass extends BaseClass {
    // Can extend only ONE class
}
```

#### Interface Implementation (Multiple)
```java
public class NewClass extends BaseClass 
                    implements Interface1, Interface2, Interface3 {
    // Can implement MULTIPLE interfaces
}
```

#### Interface Inheritance (Multiple)
```java
public interface NewInterface extends Interface1, Interface2, Interface3 {
    // Interface can extend multiple interfaces
}
```

### 8.3 Design Guidelines

#### When to Use Abstract Classes
- **Strong is-a relationship**: Clear parent-child relationship
- **Example**: `GregorianCalendar` IS-A `Calendar`
- **Code reuse**: Need to share code among related classes
- **Access control**: Need non-public members

#### When to Use Interfaces
- **Weak is-a relationship**: Object possesses certain property
- **Example**: `String` IS-KIND-OF `Comparable`
- **Multiple inheritance**: Class needs multiple behaviors
- **Unrelated classes**: Common behavior for unrelated classes

### 8.4 Practical Example: Animal vs Edible

#### Using Abstract Class (Restrictive)
```java
abstract class Animal {
    public abstract String howToEat();
}

class Chicken extends Animal {
    @Override
    public String howToEat() { return "Fry it"; }
}

class Duck extends Animal {
    @Override  
    public String howToEat() { return "Roast it"; }
}

// Problem: Broccoli cannot extend Animal (not an animal!)
// class Broccoli extends Animal { ... } // ❌ Doesn't make sense
```

#### Using Interface (Flexible)
```java
interface Edible {
    public String howToEat();
}

class Chicken implements Edible {
    @Override
    public String howToEat() { return "Fry it"; }
}

class Duck implements Edible {
    @Override
    public String howToEat() { return "Roast it"; }
}

class Broccoli implements Edible {  // ✓ Makes sense!
    @Override  
    public String howToEat() { return "Stir-fry it"; }
}

// Polymorphic method
public static void eat(Edible stuff) {
    stuff.howToEat();
}
```

### 8.5 Type Relationships

#### Example Hierarchy
```java
Interface1_1    Interface1    Interface2_1
     |             |              |
     |         Interface1_2       |
     |             |              |
     +-------- Class1 --------+   |
                   |              |
               Class2 ------------+
                   |
             Interface2_2
```

**Object `c` of `Class2` is instance of:**
- `Object`
- `Class1`, `Class2`  
- `Interface1`, `Interface1_1`, `Interface1_2`
- `Interface2_1`, `Interface2_2`

### 8.6 Check Point Exercises

**Exercise 13.27**: Give example showing why interfaces are preferred over abstract classes.
**Answer**: Interfaces allow unrelated classes to share common behavior (like `Edible` for `Chicken` and `Broccoli`), while abstract classes force inheritance hierarchy.

**Exercise 13.28**: Define abstract classes and interfaces. Similarities and differences?

**Similarities:**
- Both cannot be instantiated
- Both can be used as data types
- Both support polymorphism
- Both define contracts for subclasses

**Differences:**
- Abstract classes can have concrete methods; interfaces cannot (until Java 8)
- Classes extend one abstract class; can implement multiple interfaces
- Abstract classes can have any access modifiers; interface members are public
- Abstract classes can have constructors; interfaces cannot

**Exercise 13.29**: True or false?
- (a) **True** - Interface compiled into separate bytecode file
- (b) **False** - Interfaces cannot have static methods (pre-Java 8)
- (c) **True** - Interface can extend multiple interfaces
- (d) **False** - Interface cannot extend abstract class
- (e) **False** - Abstract class cannot extend interface

---

## 9. Case Study: The Rational Class

### 9.1 Class Design

#### Purpose
Create a class to represent rational numbers (fractions) for exact arithmetic computations.

#### Class Hierarchy
```
java.lang.Number (abstract)
        |
    Rational (implements Comparable<Rational>)
```

#### UML Class Diagram
```
+----------------------------------+
|            Rational              |
+----------------------------------+
| -numerator: long                 |
| -denominator: long               |
+----------------------------------+
| +Rational()                      |
| +Rational(numerator: long,       |
|           denominator: long)     |
| +getNumerator(): long            |
| +getDenominator(): long          |
| +add(secondRational): Rational   |
| +subtract(secondRational): Rational |
| +multiply(secondRational): Rational |
| +divide(secondRational): Rational   |
| +toString(): String              |
| -gcd(n: long, d: long): long     |
+----------------------------------+
```

### 9.2 Mathematical Operations

#### Rational Number Arithmetic
- **Addition**: a/b + c/d = (ad + bc)/(bd)
- **Subtraction**: a/b - c/d = (ad - bc)/(bd)  
- **Multiplication**: a/b × c/d = (ac)/(bd)
- **Division**: a/b ÷ c/d = (ad)/(bc)

#### Reducing to Lowest Terms
- Find GCD (Greatest Common Divisor) of numerator and denominator
- Divide both by GCD
- Example: 6/9 → GCD(6,9)=3 → 2/3

### 9.3 Test Program

```java
public class TestRationalClass {
    public static void main(String[] args) {
        // Create rational numbers
        Rational r1 = new Rational(4, 2);  // Creates 2/1 (reduced)
        Rational r2 = new Rational(2, 3);  // Creates 2/3
        
        // Display arithmetic operations
        System.out.println(r1 + " + " + r2 + " = " + r1.add(r2));
        System.out.println(r1 + " - " + r2 + " = " + r1.subtract(r2));
        System.out.println(r1 + " * " + r2 + " = " + r1.multiply(r2));
        System.out.println(r1 + " / " + r2 + " = " + r1.divide(r2));
        System.out.println(r2 + " is " + r2.doubleValue());
    }
}
```

**Output:**
```
2 + 2/3 = 8/3
2 - 2/3 = 4/3  
2 * 2/3 = 4/3
2 / 2/3 = 3
2/3 is 0.6666666666666666
```

### 9.4 Implementation

```java
public class Rational extends Number implements Comparable<Rational> {
    // Data fields
    private long numerator = 0;
    private long denominator = 1;
    
    // Default constructor
    public Rational() {
        this(0, 1);
    }
    
    // Constructor with parameters
    public Rational(long numerator, long denominator) {
        long gcd = gcd(numerator, denominator);
        this.numerator = ((denominator > 0) ? 1 : -1) * numerator / gcd;
        this.denominator = Math.abs(denominator) / gcd;
    }
    
    // Find GCD of two numbers
    private static long gcd(long n, long d) {
        long n1 = Math.abs(n);
        long n2 = Math.abs(d);
        int gcd = 1;
        
        for (int k = 1; k <= n1 && k <= n2; k++) {
            if (n1 % k == 0 && n2 % k == 0)
                gcd = k;
        }
        return gcd;
    }
    
    // Getters
    public long getNumerator() { return numerator; }
    public long getDenominator() { return denominator; }
    
    // Arithmetic operations
    public Rational add(Rational secondRational) {
        long n = numerator * secondRational.getDenominator() +
                denominator * secondRational.getNumerator();
        long d = denominator * secondRational.getDenominator();
        return new Rational(n, d);
    }
    
    public Rational subtract(Rational secondRational) {
        long n = numerator * secondRational.getDenominator() -
                denominator * secondRational.getNumerator();
        long d = denominator * secondRational.getDenominator();
        return new Rational(n, d);
    }
    
    public Rational multiply(Rational secondRational) {
        long n = numerator * secondRational.getNumerator();
        long d = denominator * secondRational.getDenominator();
        return new Rational(n, d);
    }
    
    public Rational divide(Rational secondRational) {
        long n = numerator * secondRational.getDenominator();
        long d = denominator * secondRational.numerator;
        return new Rational(n, d);
    }
    
    // String representation
    @Override
    public String toString() {
        if (denominator == 1)
            return numerator + "";
        else
            return numerator + "/" + denominator;
    }
    
    // Override equals method
    @Override
    public boolean equals(Object other) {
        if ((this.subtract((Rational)(other))).getNumerator() == 0)
            return true;
        else
            return false;
    }
    
    // Implement abstract methods from Number class
    @Override
    public int intValue() {
        return (int)doubleValue();
    }
    
    @Override
    public float floatValue() {
        return (float)doubleValue();
    }
    
    @Override
    public double doubleValue() {
        return numerator * 1.0 / denominator;
    }
    
    @Override
    public long longValue() {
        return (long)doubleValue();
    }
    
    // Implement Comparable interface
    @Override
    public int compareTo(Rational o) {
        if (this.subtract(o).getNumerator() > 0)
            return 1;
        else if (this.subtract(o).getNumerator() < 0)
            return -1;
        else
            return 0;
    }
}
```

### 9.5 Key Design Features

#### Immutable Class
- No setter methods provided
- Once created, object contents cannot be changed
- Similar to `String` and wrapper classes

#### Automatic Reduction
- Constructor automatically reduces fraction to lowest terms
- Numerator carries the sign, denominator is always positive

#### Private Helper Methods
- `gcd()` method is private static (internal use only)
- Encapsulates implementation details

#### Overflow Issues
```java
// Example showing overflow problem
public class Test {
    public static void main(String[] args) {
        Rational r1 = new Rational(1, 123456789);
        Rational r2 = new Rational(1, 123456789);  
        Rational r3 = new Rational(1, 123456789);
        System.out.println("r1 * r2 * r3 is " + 
                          r1.multiply(r2.multiply(r3)));
        // Output: r1 * r2 * r3 is -1/2204193661661244627 (incorrect!)
    }
}
```

**Solution**: Use `BigInteger` for numerator and denominator (Programming Exercise 13.15).

### 9.6 Check Point Exercises

**Exercise 13.30**: Show output:
```java
Rational r1 = new Rational(-2, 6);  // Reduces to -1/3
System.out.println(r1.getNumerator());   // -1
System.out.println(r1.getDenominator()); // 3
System.out.println(r1.intValue());       // 0 (truncated)
System.out.println(r1.doubleValue());    // -0.3333333333333333
```

**Exercise 13.31**: Why is this code wrong?
```java
Rational r1 = new Rational(-2, 6);
Object r2 = new Rational(1, 45);
System.out.println(r2.compareTo(r1));  // ❌
```
**Answer**: `r2` is declared as `Object` type, which doesn't have `compareTo` method.

**Exercise 13.32**: Why is this code wrong?
```java
Object r1 = new Rational(-2, 6);
Rational r2 = new Rational(1, 45);
System.out.println(r2.compareTo(r1));  // ❌
```
**Answer**: `compareTo` expects `Rational` parameter, but `r1` is `Object` type. Need to cast: `r2.compareTo((Rational)r1)`.

**Exercise 13.33**: Simplify equals method in one line:
```java
// Instead of lines 82-85:
@Override
public boolean equals(Object other) {
    return this.subtract((Rational)other).getNumerator() == 0;
}
```

**Exercise 13.34**: Trace the program:
```java
Rational r1 = new Rational(1, 2);   // 1/2
Rational r2 = new Rational(1, -2);  // -1/2 (sign moved to numerator)
System.out.println(r1.add(r2));     // 1/2 + (-1/2) = 0
```

---

## 10. Class Design Guidelines

### 10.1 Cohesion

#### Single Responsibility Principle
- **Rule**: Class should describe a single entity
- **Good**: Separate `Student` and `Staff` classes
- **Bad**: Combined `StudentStaff` class

#### Separate Responsibilities
**Example**: String-related classes
- `String`: Immutable strings
- `StringBuilder`: Mutable strings (not synchronized)
- `StringBuffer`: Mutable strings (synchronized)

### 10.2 Consistency

#### Naming Conventions
- **Classes**: PascalCase (`GeometricObject`)
- **Methods**: camelCase (`getArea()`)
- **Constants**: UPPER_SNAKE_CASE (`MAX_SIZE`)

#### Method Naming Consistency
- **Good**: `length()` method in `String`, `StringBuilder`, `StringBuffer`
- **Bad**: Different method names for same operation

#### Constructor Guidelines
- Provide no-arg constructor when possible
- Document if no-arg constructor not supported
- Use private constructor to prevent instantiation (like `Math` class)

### 10.3 Encapsulation

#### Data Hiding
- **Rule**: Use `private` modifier for data fields
- **Provide getters**: Only if field should be readable
- **Provide setters**: Only if field should be modifiable

#### Example: Rational Class
```java
public class Rational {
    private long numerator;    // Encapsulated
    private long denominator;  // Encapsulated
    
    // Getters provided
    public long getNumerator() { return numerator; }
    public long getDenominator() { return denominator; }
    
    // No setters - immutable class
}
```

### 10.4 Clarity

#### Design Principles
- **Easy to explain**: Clear class purpose
- **Easy to understand**: Intuitive method behavior
- **Independent usage**: No restrictions on usage order

#### Method Independence
**Good Example**: `Loan` class
```java
public class Loan {
    private double loanAmount;
    private int numberOfYears;
    private double annualInterestRate;
    
    // Properties can be set in any order
    public void setLoanAmount(double amount) { ... }
    public void setNumberOfYears(int years) { ... }
    public void setAnnualInterestRate(double rate) { ... }
}
```

#### Avoid Derived Fields
**Bad Example**:
```java
public class Person {
    private java.util.Date birthDate;
    private int age;  // ❌ Can be derived from birthDate
}
```

**Good Example**:
```java
public class Person {
    private java.util.Date birthDate;
    
    public int getAge() {  // ✓ Calculated when needed
        // Calculate age from birthDate
    }
}
```

### 10.5 Completeness

#### Provide Comprehensive Functionality
- **Example**: `String` class has 40+ methods
- **Reason**: Useful in wide range of applications
- **Goal**: Anticipate various customer needs

### 10.6 Instance vs. Static

#### Decision Rules
- **Instance**: Dependent on specific object instance
- **Static**: Shared by all instances or independent of instances

#### Examples
```java
public class Circle {
    private double radius;              // Instance - specific to each circle
    private static int numberOfObjects; // Static - shared by all circles
    
    public double getArea() {          // Instance - depends on radius
        return radius * radius * Math.PI;
    }
    
    public static int getNumberOfObjects() { // Static - not tied to specific circle
        return numberOfObjects;
    }
}
```

#### Best Practices
- Reference static members through class name: `Circle.getNumberOfObjects()`
- Don't pass parameters to initialize static fields in constructors
- Avoid common error: defining instance method that should be static

**Good Design**:
```java
public class MathUtil {
    // Static method - doesn't depend on instance
    public static int factorial(int n) {
        int result = 1;
        for (int i = 1; i <= n; i++) {
            result *= i;
        }
        return result;
    }
}
```

### 10.7 Inheritance vs. Aggregation

#### Is-A Relationship (Inheritance)
- **Strong relationship**: Clear parent-child connection
- **Example**: `Apple` IS-A `Fruit`
- **Implementation**: `class Apple extends Fruit`

#### Has-A Relationship (Aggregation)
- **Composition relationship**: Object contains another object
- **Example**: `Person` HAS-A `Name`
- **Implementation**: `Person` class contains `Name` field

```java
// Inheritance (Is-A)
class Apple extends Fruit {
    // Apple IS-A Fruit
}

// Aggregation (Has-A)
class Person {
    private Name name;  // Person HAS-A Name
    private Address address;  // Person HAS-A Address
}
```

### 10.8 Interfaces vs. Abstract Classes Guidelines

#### When to Use Abstract Classes
- **Strong is-a relationship**: Clear inheritance hierarchy
- **Code sharing**: Need to provide common implementation
- **Example**: `GregorianCalendar` extends `Calendar`

#### When to Use Interfaces  
- **Weak is-a relationship**: Object possesses certain capability
- **Multiple inheritance**: Need multiple behaviors
- **Unrelated classes**: Common behavior across different hierarchies
- **Example**: `String` implements `Comparable`

#### Combined Approach
```java
// Interface defines contract
interface Drawable {
    void draw();
}

// Abstract class provides partial implementation
abstract class Shape implements Drawable {
    protected String color;
    
    public String getColor() { return color; }
    public void setColor(String color) { this.color = color; }
    
    // Concrete subclasses implement draw()
}

// Concrete implementation
class Circle extends Shape {
    @Override
    public void draw() {
        // Circle-specific drawing code
    }
}
```

### 10.9 Summary of Guidelines

#### Checklist for Good Class Design
1. ✅ **Cohesion**: Single, well-defined purpose
2. ✅ **Consistency**: Follow naming conventions and patterns
3. ✅ **Encapsulation**: Hide implementation details
4. ✅ **Clarity**: Easy to understand and use
5. ✅ **Completeness**: Provide comprehensive functionality
6. ✅ **Proper static/instance usage**: Choose appropriate access level
7. ✅ **Correct inheritance/aggregation**: Use appropriate relationships
8. ✅ **Interface vs abstract class**: Choose based on relationship type

---

## Key Terms Summary

| Term | Definition |
|------|------------|
| **Abstract Class** | Class that cannot be instantiated and may contain abstract methods |
| **Abstract Method** | Method declared without implementation, must be overridden in subclasses |
| **Interface** | Contract defining constants and abstract method signatures |
| **Marker Interface** | Empty interface used to mark classes with certain properties |
| **Shallow Copy** | Copies object references, not the objects themselves |
| **Deep Copy** | Creates new copies of all referenced objects |
| **Subinterface** | Interface that extends other interfaces |

---

## Chapter Summary

1. **Abstract classes** provide common structure while preventing direct instantiation
2. **Abstract methods** must be implemented by concrete subclasses
3. **Interfaces** define contracts that multiple unrelated classes can implement
4. **Comparable interface** enables object comparison and sorting
5. **Cloneable interface** marks objects as cloneable
6. **Multiple inheritance** is possible with interfaces but not classes
7. **Good design** requires attention to cohesion, consistency, encapsulation, and clarity
8. **Choose interfaces** for flexibility, **choose abstract classes** for code sharing

This comprehensive guide covers all concepts, examples, and exercises from Chapter 13, providing detailed explanations for easier understanding of abstract classes and interfaces in Java programming.
