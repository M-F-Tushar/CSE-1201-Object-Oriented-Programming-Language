# Chapter 10: Object-Oriented Thinking - Complete Study Guide

## Table of Contents
1. [Introduction](#1-introduction)
2. [Class Abstraction and Encapsulation](#2-class-abstraction-and-encapsulation)
3. [Thinking in Objects](#3-thinking-in-objects)
4. [Class Relationships](#4-class-relationships)
5. [Case Study: Designing the Course Class](#5-case-study-designing-the-course-class)
6. [Case Study: Designing a Class for Stacks](#6-case-study-designing-a-class-for-stacks)
7. [Processing Primitive Data Type Values as Objects](#7-processing-primitive-data-type-values-as-objects)
8. [Automatic Conversion between Primitive Types and Wrapper Class Types](#8-automatic-conversion-between-primitive-types-and-wrapper-class-types)
9. [The BigInteger and BigDecimal Classes](#9-the-biginteger-and-bigdecimal-classes)
10. [The String Class](#10-the-string-class)
11. [The StringBuilder and StringBuffer Classes](#11-the-stringbuilder-and-stringbuffer-classes)

---

## 1. Introduction

### Key Concepts
- **Procedural Programming**: Focuses on designing methods and functions
- **Object-Oriented Programming**: Couples data and methods together into objects
- **Class Design**: The process of creating reusable, modular software components

### Learning Objectives
- Understand the differences between procedural and object-oriented programming
- Learn to design classes effectively
- Master the benefits of object-oriented programming
- Apply object-oriented thinking to problem-solving

---

## 2. Class Abstraction and Encapsulation

### 2.1 Core Concepts

#### Class Abstraction
- **Definition**: Separation of class implementation from the use of a class
- **Purpose**: Hide implementation details from users
- **Benefit**: Users can work with classes without knowing internal workings

#### Class Encapsulation
- **Definition**: Details of implementation are hidden from the user
- **Also known as**: Abstract Data Type (ADT)
- **Key Point**: Implementation is like a black box

### 2.2 Real-World Analogy: Computer Components
```
Computer System Example:
- CPU, memory, disk, motherboard, fan
- Each component = object with properties and methods
- You don't need to know internal workings
- Only need to know how components interact
```

### 2.3 Loan Class Example

#### UML Diagram Structure
```
Loan Class:
- Data Fields (private):
  * annualInterestRate: double
  * numberOfYears: int
  * loanAmount: double
  * loanDate: java.util.Date

- Constructors:
  * Loan() - default constructor
  * Loan(annualInterestRate, numberOfYears, loanAmount)

- Methods:
  * getAnnualInterestRate(): double
  * setAnnualInterestRate(double): void
  * getNumberOfYears(): int
  * setNumberOfYears(int): void
  * getLoanAmount(): double
  * setLoanAmount(double): void
  * getMonthlyPayment(): double
  * getTotalPayment(): double
  * getLoanDate(): Date
```

#### TestLoanClass.java Example
```java
public class TestLoanClass {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        // Get user input
        System.out.print("Enter annual interest rate, for example, 8.25: ");
        double annualInterestRate = input.nextDouble();
        
        System.out.print("Enter number of years as an integer: ");
        int numberOfYears = input.nextInt();
        
        System.out.print("Enter loan amount, for example, 120000.95: ");
        double loanAmount = input.nextDouble();
        
        // Create Loan object
        Loan loan = new Loan(annualInterestRate, numberOfYears, loanAmount);
        
        // Display results
        System.out.printf("The loan was created on %s\n" +
            "The monthly payment is %.2f\nThe total payment is %.2f\n",
            loan.getLoanDate().toString(), 
            loan.getMonthlyPayment(),
            loan.getTotalPayment());
    }
}
```

#### Loan.java Implementation
```java
public class Loan {
    private double annualInterestRate;
    private int numberOfYears;
    private double loanAmount;
    private java.util.Date loanDate;
    
    // Default constructor
    public Loan() {
        this(2.5, 1, 1000);
    }
    
    // Parameterized constructor
    public Loan(double annualInterestRate, int numberOfYears, double loanAmount) {
        this.annualInterestRate = annualInterestRate;
        this.numberOfYears = numberOfYears;
        this.loanAmount = loanAmount;
        loanDate = new java.util.Date();
    }
    
    // Getter methods
    public double getAnnualInterestRate() { return annualInterestRate; }
    public int getNumberOfYears() { return numberOfYears; }
    public double getLoanAmount() { return loanAmount; }
    public java.util.Date getLoanDate() { return loanDate; }
    
    // Setter methods
    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }
    public void setNumberOfYears(int numberOfYears) {
        this.numberOfYears = numberOfYears;
    }
    public void setLoanAmount(double loanAmount) {
        this.loanAmount = loanAmount;
    }
    
    // Calculation methods
    public double getMonthlyPayment() {
        double monthlyInterestRate = annualInterestRate / 1200;
        double monthlyPayment = loanAmount * monthlyInterestRate / 
            (1 - (1 / Math.pow(1 + monthlyInterestRate, numberOfYears * 12)));
        return monthlyPayment;
    }
    
    public double getTotalPayment() {
        return getMonthlyPayment() * numberOfYears * 12;
    }
}
```

### 2.4 Check Point Questions with Answers

**Question 10.1**: If you redefine the Loan class without setter methods, is the class immutable?

**Answer**: No, the class would not be completely immutable because the `loanDate` field is of type `java.util.Date`, which is mutable. Even without setter methods, the date object's internal state could be changed through its methods.

---

## 3. Thinking in Objects

### 3.1 Paradigm Comparison

#### Procedural Paradigm
- Focuses on designing methods
- Data and operations are separate
- Requires passing data to methods

#### Object-Oriented Paradigm  
- Couples data and methods into objects
- Focuses on objects and operations on objects
- Data and operations are integrated

### 3.2 BMI Class Example

#### Problem Evolution
1. **Original approach**: Static method `getBMI(double weight, double height)`
2. **Limitation**: Cannot associate weight/height with person's name and birth date
3. **Solution**: Create BMI class with instance data fields

#### UML Diagram
```
BMI Class:
- Data Fields (private):
  * name: String
  * age: int  
  * weight: double (in pounds)
  * height: double (in inches)
  * KILOGRAMS_PER_POUND: double = 0.45359237 (static final)
  * METERS_PER_INCH: double = 0.0254 (static final)

- Constructors:
  * BMI(name, age, weight, height)
  * BMI(name, weight, height) - default age 20

- Methods:
  * getBMI(): double
  * getStatus(): String
  * getName(): String
  * getAge(): int
  * getWeight(): double
  * getHeight(): double
```

#### UseBMIClass.java Example
```java
public class UseBMIClass {
    public static void main(String[] args) {
        BMI bmi1 = new BMI("Kim Yang", 18, 145, 70);
        System.out.println("The BMI for " + bmi1.getName() + " is " +
            bmi1.getBMI() + " " + bmi1.getStatus());
        
        BMI bmi2 = new BMI("Susan King", 215, 70);
        System.out.println("The BMI for " + bmi2.getName() + " is " +
            bmi2.getBMI() + " " + bmi2.getStatus());
    }
}
```

#### BMI.java Implementation
```java
public class BMI {
    private String name;
    private int age;
    private double weight; // in pounds
    private double height; // in inches
    public static final double KILOGRAMS_PER_POUND = 0.45359237;
    public static final double METERS_PER_INCH = 0.0254;
    
    // Constructor with all parameters
    public BMI(String name, int age, double weight, double height) {
        this.name = name;
        this.age = age;
        this.weight = weight;
        this.height = height;
    }
    
    // Constructor with default age
    public BMI(String name, double weight, double height) {
        this(name, 20, weight, height);
    }
    
    // Calculate BMI
    public double getBMI() {
        double bmi = weight * KILOGRAMS_PER_POUND /
            ((height * METERS_PER_INCH) * (height * METERS_PER_INCH));
        return Math.round(bmi * 100) / 100.0;
    }
    
    // Get BMI status
    public String getStatus() {
        double bmi = getBMI();
        if (bmi < 18.5)
            return "Underweight";
        else if (bmi < 25)
            return "Normal";
        else if (bmi < 30)
            return "Overweight";
        else
            return "Obese";
    }
    
    // Getter methods
    public String getName() { return name; }
    public int getAge() { return age; }
    public double getWeight() { return weight; }
    public double getHeight() { return height; }
}
```

### 3.3 Advantages of Object-Oriented Approach
1. **Data Integration**: Combines data with operations that pertain to them
2. **Real-World Modeling**: Mirrors real-world objects with attributes and activities  
3. **Software Reusability**: Improves code reuse across different programs
4. **Easier Development**: Makes programs easier to develop and maintain
5. **Cooperation Model**: Java programs become collections of cooperating objects

### 3.4 Check Point Questions with Answers

**Question 10.2**: Is the BMI class defined in Listing 10.4 immutable?

**Answer**: No, the BMI class is not immutable because all the data fields (name, age, weight, height) have corresponding getter methods, but there are no setter methods to change the values after object creation. However, since the fields are private and there are no setter methods, the class is effectively immutable after construction.

---

## 4. Class Relationships

### 4.1 Types of Relationships
1. **Association**: General binary relationship describing activity between classes
2. **Aggregation**: Special association representing ownership (has-a relationship)
3. **Composition**: Exclusive ownership relationship
4. **Inheritance**: (Covered in next chapter)

### 4.2 Association

#### Definition and Characteristics
- **Association**: General binary relationship between two classes
- **Examples**: 
  - Student taking a course
  - Faculty member teaching a course

#### UML Notation Elements
- **Solid line**: Connects two classes
- **Label**: Optional description of relationship (e.g., "Take", "Teach")
- **Direction triangle**: Shows relationship direction
- **Role names**: Describes role of each class (e.g., "teacher")
- **Multiplicity**: Specifies how many objects are involved

#### Multiplicity Examples
```
Notation    Meaning
1           Exactly one
0..1        Zero or one
*           Unlimited number
m..n        Between m and n (inclusive)
5..60       Between 5 and 60 students
0..3        Zero to three courses
```

#### Implementation Example
```java
// Student class
public class Student {
    private Course[] courseList;
    
    public void addCourse(Course s) {
        // Implementation to add course
    }
}

// Course class  
public class Course {
    private Student[] classList;
    private Faculty faculty;
    
    public void addStudent(Student s) {
        // Implementation to add student
    }
    
    public void setFaculty(Faculty faculty) {
        this.faculty = faculty;
    }
}

// Faculty class
public class Faculty {
    private Course[] courseList;
    
    public void addCourse(Course c) {
        // Implementation to add course
    }
}
```

### 4.3 Aggregation and Composition

#### Aggregation
- **Definition**: Special association representing ownership
- **Characteristic**: Object can be owned by multiple aggregating objects
- **UML Symbol**: Empty diamond attached to aggregating class
- **Example**: Student has an Address (address can be shared)

#### Composition  
- **Definition**: Exclusive ownership relationship
- **Characteristic**: Object exclusively owned by one aggregating object
- **UML Symbol**: Filled diamond attached to aggregating class
- **Example**: Student has a Name (name is unique to student)

#### Terms
- **Aggregating object**: The owner object
- **Aggregating class**: Class of the owner object
- **Aggregated object**: The owned object  
- **Aggregated class**: Class of the owned object

#### Implementation Example
```java
// Aggregated classes
public class Name {
    // Name implementation
}

public class Address {
    // Address implementation  
}

// Aggregating class
public class Student {
    private Name name;      // Composition relationship
    private Address address; // Aggregation relationship
    
    // Student implementation
}
```

#### Self-Aggregation Example
```java
public class Person {
    // Single supervisor
    private Person supervisor;
    
    // Multiple supervisors
    private Person[] supervisors;
}
```

### 4.4 Check Point Questions with Answers

**Question 10.3**: What are common relationships among classes?
**Answer**: The common relationships are:
- Association: General binary relationship between classes
- Aggregation: Has-a relationship where objects can be shared
- Composition: Exclusive has-a relationship
- Inheritance: Is-a relationship (covered in next chapter)

**Question 10.4**: What is association? What is aggregation? What is composition?
**Answer**: 
- **Association**: General relationship describing activities between two classes
- **Aggregation**: Special association representing non-exclusive ownership (has-a relationship)
- **Composition**: Special association representing exclusive ownership

**Question 10.5**: What is UML notation of aggregation and composition?
**Answer**:
- **Aggregation**: Empty diamond (◇) attached to aggregating class
- **Composition**: Filled diamond (♦) attached to aggregating class

**Question 10.6**: Why are both aggregation and composition referred to as composition?
**Answer**: Both represent "has-a" relationships and are implemented similarly using data fields in classes. For simplicity, the text refers to both as composition since the implementation approach is the same.

---

## 5. Case Study: Designing the Course Class

### 5.1 Problem Statement
Design a class to model courses where:
- Each course has a name
- Each course has enrolled students
- You can add/drop students to/from the course

### 5.2 UML Design
```
Course Class:
- Data Fields (private):
  * courseName: String
  * students: String[]
  * numberOfStudents: int

- Constructor:
  * Course(courseName: String)

- Methods:
  * getCourseName(): String
  * addStudent(student: String): void
  * dropStudent(student: String): void
  * getStudents(): String[]
  * getNumberOfStudents(): int
```

### 5.3 TestCourse.java Example
```java
public class TestCourse {
    public static void main(String[] args) {
        Course course1 = new Course("Data Structures");
        Course course2 = new Course("Database Systems");
        
        // Add students to course1
        course1.addStudent("Peter Jones");
        course1.addStudent("Kim Smith");
        course1.addStudent("Anne Kennedy");
        
        // Add students to course2
        course2.addStudent("Peter Jones");
        course2.addStudent("Steve Smith");
        
        // Display course1 information
        System.out.println("Number of students in course1: " + 
            course1.getNumberOfStudents());
        String[] students = course1.getStudents();
        for (int i = 0; i < course1.getNumberOfStudents(); i++)
            System.out.print(students[i] + ", ");
        
        System.out.println();
        System.out.print("Number of students in course2: " + 
            course2.getNumberOfStudents());
    }
}
```

### 5.4 Course.java Implementation
```java
public class Course {
    private String courseName;
    private String[] students = new String[100]; // Fixed capacity
    private int numberOfStudents;
    
    // Constructor
    public Course(String courseName) {
        this.courseName = courseName;
    }
    
    // Add a student to the course
    public void addStudent(String student) {
        students[numberOfStudents] = student;
        numberOfStudents++;
    }
    
    // Get all students (returns the array)
    public String[] getStudents() {
        return students;
    }
    
    // Get number of students
    public int getNumberOfStudents() {
        return numberOfStudents;
    }
    
    // Get course name
    public String getCourseName() {
        return courseName;
    }
    
    // Drop a student (left as exercise)
    public void dropStudent(String student) {
        // Implementation left as Programming Exercise 10.9
    }
}
```

### 5.5 Key Design Decisions
1. **Fixed Array Size**: Uses array of size 100 (limitation)
2. **Encapsulation**: Users interact through public methods only
3. **Flexibility**: Internal implementation can change without affecting users
4. **Data Structure**: Could use different storage (ArrayList, etc.) internally

### 5.6 Expected Output
```
Number of students in course1: 3
Peter Jones, Kim Smith, Anne Kennedy,
Number of students in course2: 2
```

---

## 6. Case Study: Designing a Class for Stacks

### 6.1 Stack Concept
- **Definition**: Data structure with Last-In-First-Out (LIFO) behavior
- **Applications**: Method invocation management, expression evaluation
- **Operations**: Push (add), Pop (remove), Peek (view top), Empty check

### 6.2 Stack Behavior Illustration
```
Initial: []
Push 1: [1]
Push 2: [1, 2] 
Push 3: [1, 2, 3]
Pop: [1, 2] (returns 3)
Pop: [1] (returns 2)
Pop: [] (returns 1)
```

### 6.3 UML Design
```
StackOfIntegers Class:
- Data Fields (private):
  * elements: int[]
  * size: int
  * DEFAULT_CAPACITY: int = 16 (static final)

- Constructors:
  * StackOfIntegers()
  * StackOfIntegers(capacity: int)

- Methods:
  * empty(): boolean
  * peek(): int
  * push(value: int): void
  * pop(): int
  * getSize(): int
```

### 6.4 TestStackOfIntegers.java Example
```java
public class TestStackOfIntegers {
    public static void main(String[] args) {
        StackOfIntegers stack = new StackOfIntegers();
        
        // Push integers 0 through 9
        for (int i = 0; i < 10; i++)
            stack.push(i);
        
        // Pop and display all integers
        while (!stack.empty())
            System.out.print(stack.pop() + " ");
    }
}
```

### 6.5 StackOfIntegers.java Implementation
```java
public class StackOfIntegers {
    private int[] elements;
    private int size;
    public static final int DEFAULT_CAPACITY = 16;
    
    // Default constructor
    public StackOfIntegers() {
        this(DEFAULT_CAPACITY);
    }
    
    // Constructor with specified capacity
    public StackOfIntegers(int capacity) {
        elements = new int[capacity];
    }
    
    // Push a new integer to the top of the stack
    public void push(int value) {
        if (size >= elements.length) {
            // Double the capacity when full
            int[] temp = new int[elements.length * 2];
            System.arraycopy(elements, 0, temp, 0, elements.length);
            elements = temp;
        }
        
        elements[size++] = value;
    }
    
    // Return and remove the top element from the stack
    public int pop() {
        return elements[--size];
    }
    
    // Return the top element from the stack without removing it
    public int peek() {
        return elements[size - 1];
    }
    
    // Test whether the stack is empty
    public boolean empty() {
        return size == 0;
    }
    
    // Return the number of elements in the stack
    public int getSize() {
        return size;
    }
}
```

### 6.6 Key Design Features
1. **Dynamic Capacity**: Automatically doubles array size when full
2. **Memory Efficiency**: Uses array for internal storage
3. **Stack Pointer**: `size - 1` indicates top element index
4. **Error Prevention**: Methods assume proper usage (no bounds checking shown)

### 6.7 Internal Structure Visualization
```
elements array:
[0] [1] [2] [3] ... [capacity-1]
 ↑   ↑   ↑   ↑
bottom      top(size-1)    unused
```

### 6.8 Expected Output
```
9 8 7 6 5 4 3 2 1 0
```

---

## 7. Processing Primitive Data Type Values as Objects

### 7.1 Why Wrapper Classes?
- **Problem**: Primitive types are not objects (performance reasons)
- **Need**: Many Java methods require objects as arguments  
- **Solution**: Wrapper classes to "wrap" primitive values into objects

### 7.2 Wrapper Class Overview
```
Primitive Type  →  Wrapper Class
boolean        →  Boolean
char           →  Character  
byte           →  Byte
short          →  Short
int            →  Integer
long           →  Long
float          →  Float
double         →  Double
```

### 7.3 Integer and Double Class Features

#### Constructors
```java
// Integer constructors
Integer i1 = new Integer(5);
Integer i2 = new Integer("5");

// Double constructors  
Double d1 = new Double(5.0);
Double d2 = new Double("5.0");
```

#### Key Characteristics
- **No no-arg constructors**: Must provide initial value
- **Immutable**: Values cannot be changed after creation
- **Constants**: MAX_VALUE, MIN_VALUE for each numeric type

#### Constants Examples
```java
System.out.println("Max integer: " + Integer.MAX_VALUE);      // 2,147,483,647
System.out.println("Min positive float: " + Float.MIN_VALUE); // 1.4E-45
System.out.println("Max double: " + Double.MAX_VALUE);        // 1.797...E+308
```

#### Conversion Methods
```java
// All numeric wrapper classes have:
byteValue(), shortValue(), intValue(), 
longValue(), floatValue(), doubleValue()

// Examples
new Double(12.4).intValue()    // returns 12
new Integer(12).doubleValue()  // returns 12.0
```

#### Comparison Methods
```java
// compareTo method returns 1, 0, or -1
new Double(12.4).compareTo(new Double(12.3))  // returns 1
new Double(12.3).compareTo(new Double(12.3))  // returns 0  
new Double(12.3).compareTo(new Double(12.51)) // returns -1
```

### 7.4 Static Methods

#### valueOf Methods
```java
// Create wrapper objects from strings
Double doubleObject = Double.valueOf("12.4");
Integer integerObject = Integer.valueOf("12");
```

#### Parsing Methods
```java
// Parse strings to primitive values (decimal)
int i = Integer.parseInt("123");
double d = Double.parseDouble("123.45");

// Parse strings to primitive values (different radix)
Integer.parseInt("11", 2)   // returns 3 (binary)
Integer.parseInt("12", 8)   // returns 10 (octal)
Integer.parseInt("13", 10)  // returns 13 (decimal)
Integer.parseInt("1A", 16)  // returns 26 (hexadecimal)
```

#### Converting Decimal to Hex
```java
String.format("%x", 26)  // returns "1a"
String.format("%X", 26)  // returns "1A"
```

### 7.5 Check Point Questions with Answers

**Question 10.7**: Describe primitive-type wrapper classes.
**Answer**: Wrapper classes allow primitive data types to be treated as objects. They provide constructors to create objects from primitive values or strings, conversion methods to extract primitive values, comparison methods, and static utility methods for parsing and formatting.

**Question 10.8**: Can each of the following statements be compiled?
```java
a. Integer i = new Integer("23");        // ✓ Yes
b. Integer i = new Integer(23);          // ✓ Yes  
c. Integer i = Integer.valueOf("23");    // ✓ Yes
d. Integer i = Integer.parseInt("23", 8); // ✗ No - parseInt returns int, not Integer
e. Double d = new Double();              // ✗ No - no no-arg constructor
f. Double d = Double.valueOf("23.45");   // ✓ Yes
g. int i = (Integer.valueOf("23")).intValue(); // ✓ Yes
h. double d = (Double.valueOf("23.4")).doubleValue(); // ✓ Yes
i. int i = (Double.valueOf("23.4")).intValue(); // ✓ Yes
j. String s = (Double.valueOf("23.4")).toString(); // ✓ Yes
```

**Question 10.9**: How do you convert types?
**Answer**:
- Integer to String: `String.valueOf(123)` or `123 + ""`
- String to Integer: `Integer.parseInt("123")`  
- Double to String: `String.valueOf(123.45)` or `123.45 + ""`
- String to Double: `Double.parseDouble("123.45")`

**Question 10.10**: Show the output:
```java
public class Test {
    public static void main(String[] args) {
        Integer x = new Integer(3);
        System.out.println(x.intValue());           // Output: 3
        System.out.println(x.compareTo(new Integer(4))); // Output: -1
    }
}
```

**Question 10.11**: What is the output?
```java
public class Test {
    public static void main(String[] args) {
        System.out.println(Integer.parseInt("10"));     // 10
        System.out.println(Integer.parseInt("10", 10)); // 10  
        System.out.println(Integer.parseInt("10", 16)); // 16
        System.out.println(Integer.parseInt("11"));     // 11
        System.out.println(Integer.parseInt("11", 10)); // 11
        System.out.println(Integer.parseInt("11", 16)); // 17
    }
}
```

---

## 8. Automatic Conversion between Primitive Types and Wrapper Class Types

### 8.1 Concepts

#### Boxing and Unboxing
- **Boxing**: Converting primitive value to wrapper object
- **Unboxing**: Converting wrapper object to primitive value
- **Autoboxing**: Automatic boxing by compiler
- **Autounboxing**: Automatic unboxing by compiler

### 8.2 Manual vs Automatic Conversion

#### Traditional Approach (Manual)
```java
Integer intObject = new Integer(2);  // Manual boxing
int value = intObject.intValue();    // Manual unboxing
```

#### Modern Approach (Automatic)
```java
Integer intObject = 2;     // Autoboxing
int value = intObject;     // Autounboxing
```

### 8.3 Practical Examples

#### Array Example
```java
Integer[] intArray = {1, 2, 3};  // Autoboxing: 1,2,3 → Integer objects
System.out.println(intArray[0] + intArray[1] + intArray[2]); // Autounboxing for addition
```

#### Method Parameter Example
```java
public void processInteger(Integer i) {
    // Method expects Integer object
}

processInteger(42);  // Autoboxing: 42 → new Integer(42)
```

#### Collection Example
```java
ArrayList<Integer> list = new ArrayList<>();
list.add(42);        // Autoboxing: 42 → Integer object
int value = list.get(0); // Autounboxing: Integer object → int
```

### 8.4 Check Point Questions with Answers

**Question 10.12**: What are autoboxing and autounboxing? Are the following statements correct?
**Answer**: 
- **Autoboxing**: Automatic conversion from primitive to wrapper object
- **Autounboxing**: Automatic conversion from wrapper object to primitive

```java
a. Integer x = 3 + new Integer(5);  // ✓ Yes - autoboxing result of addition
b. Integer x = 3;                   // ✓ Yes - autoboxing
c. Double x = 3;                    // ✓ Yes - autoboxing int to Double
d. Double x = 3.0;                  // ✓ Yes - autoboxing double to Double  
e. int x = new Integer(3);          // ✓ Yes - autounboxing
f. int x = new Integer(3) + new Integer(4); // ✓ Yes - autounboxing for addition
```

**Question 10.13**: Show the output:
```java
public class Test {
    public static void main(String[] args) {
        Double x = 3.5;                    // Autoboxing
        System.out.println(x.intValue());  // 3 (truncates decimal)
        System.out.println(x.compareTo(4.5)); // -1 (3.5 < 4.5)
    }
}
```

---

## 9. The BigInteger and BigDecimal Classes

### 9.1 Purpose and Need
- **BigInteger**: For integers larger than Long.MAX_VALUE (9,223,372,036,854,775,807)
- **BigDecimal**: For decimal numbers requiring arbitrary precision
- **Both are immutable**: Operations return new objects

### 9.2 BigInteger Usage

#### Creating BigInteger Objects
```java
BigInteger a = new BigInteger("9223372036854775807");
BigInteger b = new BigInteger("2");
```

#### Arithmetic Operations
```java
BigInteger sum = a.add(b);
BigInteger difference = a.subtract(b);  
BigInteger product = a.multiply(b);
BigInteger quotient = a.divide(b);
BigInteger remainder = a.remainder(b);
```

#### Comparison
```java
int result = a.compareTo(b);  // Returns -1, 0, or 1
```

#### Constants
```java
BigInteger.ZERO   // Represents 0
BigInteger.ONE    // Represents 1  
BigInteger.TEN    // Represents 10
```

#### Example: Large Multiplication
```java
BigInteger a = new BigInteger("9223372036854775807");
BigInteger b = new BigInteger("2");
BigInteger c = a.multiply(b);
System.out.println(c); // Output: 18446744073709551614
```

### 9.3 BigDecimal Usage

#### Creating BigDecimal Objects
```java
BigDecimal a = new BigDecimal("1.0");
BigDecimal b = new BigDecimal("3");
```

#### Division with Precision Control
```java
// May throw ArithmeticException if result doesn't terminate
BigDecimal result1 = a.divide(b);  // Risky

// Safe division with scale and rounding
BigDecimal result2 = a.divide(b, 20, BigDecimal.ROUND_UP);
System.out.println(result2); // Output: 0.33333333333333333334
```

#### Rounding Modes
```java
BigDecimal.ROUND_UP         // Round away from zero
BigDecimal.ROUND_DOWN       // Round towards zero  
BigDecimal.ROUND_CEILING    // Round towards positive infinity
BigDecimal.ROUND_FLOOR      // Round towards negative infinity
BigDecimal.ROUND_HALF_UP    // Round to nearest, ties away from zero
BigDecimal.ROUND_HALF_DOWN  // Round to nearest, ties towards zero
BigDecimal.ROUND_HALF_EVEN  // Round to nearest, ties to even number
```

### 9.4 LargeFactorial.java Example
```java
import java.math.*;

public class LargeFactorial {
    public static void main(String[] args) {
        System.out.println("50! is \n" + factorial(50));
    }
    
    public static BigInteger factorial(long n) {
        BigInteger result = BigInteger.ONE;
        for (int i = 1; i <= n; i++)
            result = result.multiply(new BigInteger(i + ""));
        
        return result;
    }
}
```

#### Output
```
50! is
30414093201713378043612608166064768844377641568960512000000000000
```

### 9.5 Check Point Questions with Answers

**Question 10.14**: What is the output of the following code?
```java
public class Test {
    public static void main(String[] args) {
        java.math.BigInteger x = new java.math.BigInteger("3");
        java.math.BigInteger y = new java.math.BigInteger("7");
        java.math.BigInteger z = x.add(y);
        System.out.println("x is " + x);  // x is 3
        System.out.println("y is " + y);  // y is 7  
        System.out.println("z is " + z);  // z is 10
    }
}
```

**Note**: BigInteger objects are immutable, so x and y remain unchanged after the add operation.

---

## 10. The String Class

### 10.1 String Fundamentals
- **Immutable**: Contents cannot be changed once created
- **Object Nature**: String literals are treated as String objects
- **Rich API**: 13 constructors and 40+ methods

### 10.2 Constructing Strings

#### From String Literals
```java
String message1 = new String("Welcome to Java");  // Explicit constructor
String message2 = "Welcome to Java";              // Direct assignment (preferred)
```

#### From Character Arrays
```java
char[] charArray = {'G', 'o', 'o', 'd', ' ', 'D', 'a', 'y'};
String message = new String(charArray);  // Creates "Good Day"
```

### 10.3 Immutable Strings and Interned Strings

#### String Immutability Demonstration
```java
String s = "Java";
s = "HTML";
```

**Explanation**: 
- First line creates String object with "Java"
- Second line creates NEW String object with "HTML"  
- Original "Java" object still exists but is no longer referenced

#### String Interning
```java
String s1 = "Welcome to Java";           // Interned string
String s2 = new String("Welcome to Java"); // New object
String s3 = "Welcome to Java";           // Same interned string as s1

System.out.println("s1 == s2 is " + (s1 == s2)); // false
System.out.println("s1 == s3 is " + (s1 == s3)); // true
```

**Key Points**:
- JVM uses unique instances for string literals with same character sequence
- Improves efficiency and saves memory
- `s1` and `s3` refer to same interned string object
- `s2` is a separate object despite same content

### 10.4 Replacing and Splitting Strings

#### Replace Methods
```java
String original = "Welcome";

// Replace characters
String result1 = original.replace('e', 'A');        // "WAlcomA"

// Replace first occurrence  
String result2 = original.replaceFirst("e", "AB");  // "WABlcome"

// Replace all occurrences
String result3 = original.replaceAll("e", "AB");    // "WABlcomAB"

// Replace substring
String result4 = original.replace("el", "AB");      // "WABcome"
```

#### Split Method
```java
String[] tokens = "Java#HTML#Perl".split("#");
for (int i = 0; i < tokens.length; i++)
    System.out.print(tokens[i] + " ");  // Output: Java HTML Perl
```

### 10.5 Regular Expressions (Regex)

#### What are Regular Expressions?
- **Definition**: String describing a pattern for matching sets of strings
- **Purpose**: Validate input, match patterns, replace/split by patterns
- **Power**: Much more flexible than simple string matching

#### matches() Method
```java
// Simple matching (like equals)
"Java".matches("Java");    // true

// Pattern matching  
"Java is fun".matches("Java.*");     // true - starts with "Java"
"Java is cool".matches("Java.*");    // true - starts with "Java"  
"Java is powerful".matches("Java.*"); // true - starts with "Java"
```

#### Common Regex Patterns
```java
\\d         // Single digit
\\d{3}      // Exactly 3 digits
\\d{2,4}    // 2 to 4 digits
.           // Any single character
.*          // Any sequence of characters
[abc]       // Any of: a, b, or c
[a-z]       // Any lowercase letter
[A-Z]       // Any uppercase letter
[0-9]       // Any digit (same as \\d)
```

#### Practical Examples
```java
// Social Security Number pattern
"440-02-4534".matches("\\d{3}-\\d{2}-\\d{4}");  // true

// Replace with regex
String s = "a+b$#c".replaceAll("[$+#]", "NNN");  // "aNNNbNNNNNNc"

// Split with regex  
String[] tokens = "Java,C?C#,C++".split("[.,:;?]");
// Result: ["Java", "C", "C#", "C++"]
```

### 10.6 Conversion between Strings and Arrays

#### String to Character Array
```java
char[] chars = "Java".toCharArray();
// chars[0] = 'J', chars[1] = 'a', chars[2] = 'v', chars[3] = 'a'
```

#### getChars Method
```java
char[] dst = {'J', 'A', 'V', 'A', '1', '3', '0', '1'};
"CS3720".getChars(2, 6, dst, 4);
// dst becomes {'J', 'A', 'V', 'A', '3', '7', '2', '0'}
```

#### Character Array to String
```java
// Using constructor
String str1 = new String(new char[]{'J', 'a', 'v', 'a'});

// Using valueOf method
String str2 = String.valueOf(new char[]{'J', 'a', 'v', 'a'});
```

### 10.7 Converting Values to Strings

#### Static valueOf Methods
```java
String.valueOf(true);      // "true"
String.valueOf('A');       // "A"  
String.valueOf(123);       // "123"
String.valueOf(123.45);    // "123.45"
String.valueOf(new char[]{'A', 'B'}); // "AB"
```

#### String Concatenation Alternative
```java
// Traditional approach
String s1 = String.valueOf(5.44);  // "5.44"

// Concatenation approach  
String s2 = 5.44 + "";            // "5.44"
```

### 10.8 String Formatting

#### format() Method
```java
String s = String.format("%7.2f%6d%-4s", 45.556, 14, "AB");
System.out.println(s);  // "  45.56    14AB  "
```

#### Relationship with printf
```java
// These are equivalent:
System.out.printf(format, item1, item2, ...);
System.out.print(String.format(format, item1, item2, ...));
```

### 10.9 Check Point Questions with Answers

**Question 10.15**: Results of expressions with string variables:
```java
String s1 = "Welcome to Java";
String s2 = s1;
String s3 = new String("Welcome to Java");  
String s4 = "Welcome to Java";
```

**Answers**:
```java
a. s1 == s2                    // true (same reference)
b. s1 == s3                    // false (different objects)  
c. s1 == s4                    // true (same interned string)
d. s1.equals(s3)              // true (same content)
e. s1.equals(s4)              // true (same content)
f. "Welcome to Java".replace("Java", "HTML")  // "Welcome to HTML"
g. s1.replace('o', 'T')       // "WelcTme tT Java"
h. s1.replaceAll("o", "T")    // "WelcTme tT Java"  
i. s1.replaceFirst("o", "T")  // "WelcTme to Java"
j. s1.toCharArray()           // char array: ['W','e','l','c','o','m','e',' ','t','o',' ','J','a','v','a']
```

**Question 10.16**: Which string creation is better?
```java
String s = "Welcome to Java";           // Better - uses interned string
String s = new String("Welcome to Java"); // Less efficient - creates new object
```
**Answer**: The first approach is better because it uses string interning for memory efficiency.

**Question 10.17**: Output of code:
```java
String s1 = "Welcome to Java";
String s2 = s1.replace("o", "abc");
System.out.println(s1);  // "Welcome to Java" (unchanged)
System.out.println(s2);  // "Welcabcme tabcJava" (new string)
```

**Question 10.18**: Code for string operations:
```java
String s1 = "Welcome";
String s2 = "welcome";

// a. Replace all 'e' with 'E' in s1
s2 = s1.replace('e', 'E');  // "WElcomE"

// b. Split "Welcome to Java and HTML" and assign first two tokens
String[] tokens = "Welcome to Java and HTML".split(" ");
s1 = tokens[0];  // "Welcome"  
s2 = tokens[1];  // "to"
```

**Question 10.19**: Does any method in String class change contents?
**Answer**: No, String objects are immutable. All methods that appear to modify strings actually return new String objects.

**Question 10.20**: What is s.length() for new String()?
```java
String s = new String();
System.out.println(s.length()); // 0 (empty string)
```

**Question 10.21**: How to convert to string?
**Answer**:
- char to String: `String.valueOf('A')` or `'A' + ""`
- char[] to String: `String.valueOf(charArray)` or `new String(charArray)`  
- number to String: `String.valueOf(123)` or `123 + ""`

**Question 10.22**: Why NullPointerException?
```java
public class Test {
    private String text;  // Instance variable
    
    public Test(String s) {
        String text = s;  // LOCAL variable, not instance variable!
    }
    
    public static void main(String[] args) {
        Test test = new Test("ABC");
        System.out.println(test.text.toLowerCase()); // text is null!
    }
}
```
**Answer**: Line 5 creates a local variable instead of assigning to instance variable. Should be `this.text = s;`

**Question 10.23**: What is wrong?
```java
public class Test {
    String text;
    
    public void Test(String s) {  // This is a METHOD, not CONSTRUCTOR!
        text = s;
    }
    
    public static void main(String[] args) {
        Test test = new Test("ABC");  // Calls default constructor, not Test method
        System.out.println(test);     // text is null
    }
}
```
**Answer**: Line 4 defines a method, not a constructor. Constructor should not have `void` return type.

**Question 10.24**: Output of regex code:
```java
public class Test {
    public static void main(String[] args) {
        System.out.println("Hi, ABC, good".matches("ABC "));     // false
        System.out.println("Hi, ABC, good".matches(".*ABC.*"));  // true  
        System.out.println("A,B;C".replaceAll(",;", "#"));      // "A,B;C" (no match)
        System.out.println("A,B;C".replaceAll("[,;]", "#"));    // "A#B#C"
        String[] tokens = "A,B;C".split("[,;]");
        for (int i = 0; i < tokens.length; i++)
            System.out.print(tokens[i] + " ");  // "A B C "
    }
}
```

**Question 10.25**: Output of character counting:
```java
public class Test {
    public static void main(String[] args) {
        String s = "Hi, Good Morning";
        System.out.println(m(s));  // Output: 3
    }
    
    public static int m(String s) {
        int count = 0;
        for (int i = 0; i < s.length(); i++)
            if (Character.isUpperCase(s.charAt(i)))
                count++;  // Counts: H, G, M
        return count;
    }
}
```

---

## 11. The StringBuilder and StringBuffer Classes

### 11.1 Purpose and Differences

#### Why StringBuilder/StringBuffer?
- **String limitation**: Immutable - cannot modify contents
- **StringBuilder/StringBuffer**: Mutable - can add, insert, append, delete
- **Flexibility**: Dynamic content modification

#### StringBuilder vs StringBuffer
| Feature | StringBuilder | StringBuffer |
|---------|---------------|--------------|
| Thread Safety | Not synchronized | Synchronized |
| Performance | Faster (single thread) | Slower (thread-safe) |
| Usage | Single thread access | Multiple thread access |

### 11.2 StringBuilder Constructors

```java
// Empty builder with default capacity 16
StringBuilder sb1 = new StringBuilder();

// Empty builder with specified capacity  
StringBuilder sb2 = new StringBuilder(50);

// Builder initialized with string
StringBuilder sb3 = new StringBuilder("Hello");
```

### 11.3 Modifying StringBuilder Content

#### Append Methods
```java
StringBuilder sb = new StringBuilder();
sb.append("Welcome");        // "Welcome"
sb.append(' ');             // "Welcome "  
sb.append("to");            // "Welcome to"
sb.append(' ');             // "Welcome to "
sb.append("Java");          // "Welcome to Java"

// Method chaining (since append returns StringBuilder)
StringBuilder sb2 = new StringBuilder()
    .append("Welcome")
    .append(" ")
    .append("to")  
    .append(" ")
    .append("Java");
```

#### Insert Methods
```java
StringBuilder sb = new StringBuilder("Welcome to Java");
sb.insert(11, "HTML and ");  // "Welcome to HTML and Java"
```

#### Delete Methods
```java
StringBuilder sb = new StringBuilder("Welcome to Java");

sb.delete(8, 11);      // "Welcome Java" (deletes " to")
sb.deleteCharAt(8);    // "Welcome o Java" (deletes 't')
```

#### Other Modification Methods
```java
StringBuilder sb = new StringBuilder("Welcome to Java");

sb.reverse();                    // "avaJ ot emocleW"
sb.replace(11, 15, "HTML");     // "Welcome to HTML" 
sb.setCharAt(0, 'w');           // "welcome to Java"
```

### 11.4 StringBuilder Properties and Utility Methods

#### Capacity and Length
```java
StringBuilder sb = new StringBuilder("Java");

System.out.println(sb.length());    // 4 (actual characters)
System.out.println(sb.capacity()); // 20 (16 + 4, default + initial string length)

sb.setLength(10);               // Pad with null characters if needed
sb.trimToSize();               // Reduce capacity to actual length
```

#### Character Access
```java
StringBuilder sb = new StringBuilder("Java");
char ch = sb.charAt(0);        // 'J'
```

#### Conversion Methods  
```java
StringBuilder sb = new StringBuilder("Hello");
String str = sb.toString();    // Convert to String

// Substring methods (return String, don't modify StringBuilder)
String sub1 = sb.substring(1);     // "ello"
String sub2 = sb.substring(1, 3);  // "el"
```

### 11.5 Internal Structure and Performance

#### Capacity Management
- **Initial capacity**: 16 characters (default constructor)
- **Growth strategy**: When capacity exceeded, new array size = 2 * (previous size + 1)
- **Memory efficiency**: Use appropriate initial capacity to avoid resizing

#### Performance Tips
```java
// Good: Specify initial capacity if known
StringBuilder sb = new StringBuilder(1000);

// Good: Reduce capacity after building
sb.trimToSize();

// Avoid: Frequent capacity changes
StringBuilder sb = new StringBuilder(); // Only capacity 16
for (int i = 0; i < 1000; i++) {
    sb.append("data"); // Multiple array resizings!
}
```

### 11.6 Case Study: Ignoring Nonalphanumeric Characters When Checking Palindromes

#### Problem Statement
Write a program that ignores nonalphanumeric characters when checking if a string is a palindrome.

#### Solution Strategy
1. Filter string by keeping only letters and digits
2. Reverse the filtered string  
3. Compare original filtered string with reversed string

#### PalindromeIgnoreNonAlphanumeric.java
```java
import java.util.Scanner;

public class PalindromeIgnoreNonAlphanumeric {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a string: ");
        String s = input.nextLine();
        
        System.out.println("Ignoring nonalphanumeric characters, \nis " +
            s + " a palindrome? " + isPalindrome(s));
    }
    
    /** Return true if a string is a palindrome */
    public static boolean isPalindrome(String s) {
        // Create filtered string with only alphanumeric characters
        String s1 = filter(s);
        
        // Create reversed string
        String s2 = reverse(s1);
        
        // Check if filtered string equals its reverse
        return s2.equals(s1);
    }
    
    /** Create a new string by eliminating nonalphanumeric chars */
    public static String filter(String s) {
        StringBuilder stringBuilder = new StringBuilder();
        
        // Examine each character and add only letters/digits
        for (int i = 0; i < s.length(); i++) {
            if (Character.isLetterOrDigit(s.charAt(i))) {
                stringBuilder.append(s.charAt(i));
            }
        }
        
        return stringBuilder.toString();
    }
    
    /** Create a new string by reversing a specified string */
    public static String reverse(String s) {
        StringBuilder stringBuilder = new StringBuilder(s);
        stringBuilder.reverse();
        return stringBuilder.toString();
    }
}
```

#### Sample Runs
```
Enter a string: ab<c>cb?a
Ignoring nonalphanumeric characters,
is ab<c>cb?a a palindrome? true

Enter a string: abcc><?cab  
Ignoring nonalphanumeric characters,
is abcc><?cab a palindrome? false
```

#### Key Points
- Uses `Character.isLetterOrDigit()` to identify valid characters
- StringBuilder provides efficient string building and reversing
- Methods return new strings without modifying originals
- Alternative approach to character-by-character comparison from Chapter 5

### 11.7 Check Point Questions with Answers

**Question 10.26**: What is the difference between StringBuilder and StringBuffer?
**Answer**: 
- **StringBuilder**: Not synchronized, faster, use for single-thread access
- **StringBuffer**: Synchronized, slower, use for multi-thread access
- Both have same methods and functionality otherwise

**Question 10.27**: How do you create a string builder from a string? How do you return a string from a string builder?
**Answer**:
```java
// Create from string
StringBuilder sb = new StringBuilder("Hello World");

// Return string  
String str = sb.toString();
```

**Question 10.28**: Write three statements to reverse a string s using StringBuilder:
**Answer**:
```java
StringBuilder sb = new StringBuilder(s);
sb.reverse();
String reversed = sb.toString();
```

**Question 10.29**: Write three statements to delete substring from index 4 to 10:
**Answer**:
```java
StringBuilder sb = new StringBuilder(s);
sb.delete(4, 11);  // Note: endIndex is exclusive
String result = sb.toString();
```

**Question 10.30**: What is the internal storage for characters?
**Answer**:
- **String**: Uses internal char array (immutable)
- **StringBuilder**: Uses internal char array (mutable, resizable)

**Question 10.31**: Show the value of s1 after each statement:
```java
StringBuilder s1 = new StringBuilder("Java");
StringBuilder s2 = new StringBuilder("HTML");
```

**Answers**:
```java
a. s1.append(" is fun");     // "Java is fun"
b. s1.append(s2);           // "JavaHTML"  
c. s1.insert(2, "is fun");  // "Jais funva"
d. s1.insert(1, s2);        // "JHTMLava"
e. s1.charAt(2);            // 'v' (doesn't change s1)
f. s1.length();             // 4 (doesn't change s1)
g. s1.deleteCharAt(3);      // "Jav"
h. s1.delete(1, 3);         // "Ja"  
i. s1.reverse();            // "avaJ"
j. s1.replace(1, 3, "Computer"); // "JComputera"
k. s1.substring(1, 3);      // "av" (doesn't change s1)
l. s1.substring(2);         // "va" (doesn't change s1)
```

**Question 10.32**: Show output of program:
```java
public class Test {
    public static void main(String[] args) {
        String s = "Java";
        StringBuilder builder = new StringBuilder(s);
        change(s, builder);
        System.out.println(s);       // "Java" (String is immutable)
        System.out.println(builder); // "Java and HTML" (StringBuilder is mutable)
    }
    
    private static void change(String s, StringBuilder builder) {
        s = s + " and HTML";         // Creates new String, doesn't affect original
        builder.append(" and HTML"); // Modifies the StringBuilder object
    }
}
```

---

## Key Terms Summary

- **Abstract Data Type (ADT)**: A class that hides implementation details
- **Aggregation**: Has-a relationship where objects can be shared
- **Boxing**: Converting primitive value to wrapper object  
- **Class Abstraction**: Separation of implementation from usage
- **Class Encapsulation**: Hiding implementation details
- **Class's Contract**: Public methods and their expected behavior
- **Composition**: Exclusive has-a relationship
- **Has-a Relationship**: Object ownership relationship
- **Multiplicity**: Number specification in UML relationships
- **Stack**: Last-In-First-Out data structure
- **Unboxing**: Converting wrapper object to primitive value

## Chapter Summary

### Key Learning Points

1. **Paradigm Shift**: Object-oriented programming integrates data with operations, unlike procedural programming which separates them.

2. **Wrapper Classes**: Enable primitive types to be used as objects, with automatic boxing/unboxing for convenience.

3. **Big Number Classes**: BigInteger and BigDecimal handle arbitrarily large numbers and high-precision calculations.

4. **String Immutability**: String objects cannot be changed; operations return new objects. JVM optimizes through string interning.

5. **Regular Expressions**: Powerful pattern matching for string validation, replacement, and splitting.

6. **StringBuilder Efficiency**: Mutable alternative to String for dynamic content modification.

7. **Class Relationships**: Association, aggregation, and composition define how classes interact and depend on each other.

8. **Encapsulation Benefits**: Hide implementation details while providing clean public interfaces for class usage.

This comprehensive guide covers all concepts, examples, and exercises from Chapter 10, providing detailed explanations for better understanding of object-oriented thinking principles.
