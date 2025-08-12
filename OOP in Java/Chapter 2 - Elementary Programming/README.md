# Chapter 2: Elementary Programming - Complete Study Guide

## 2.1 Introduction

### Overview
This chapter focuses on learning elementary programming techniques to solve real-world problems. You'll learn to use primitive data types, variables, constants, operators, expressions, and input/output operations.

### Key Learning Objectives
- Write simple programs to solve computational problems
- Understand the basic problem-solving process: analyze → design → implement
- Learn to work with variables, constants, and basic data types
- Master input/output operations
- Apply mathematical operations in programming

### Real-World Application Example
**Problem**: Calculate monthly payment for a student loan
- **Input**: Loan amount, loan term, annual interest rate
- **Output**: Monthly payment and total payment
- **Process**: Apply mathematical formulas in Java code

---

## 2.2 Writing a Simple Program

### The Programming Process
Writing a program involves two main steps:
1. **Designing a strategy** for solving the problem
2. **Implementing the strategy** using a programming language

### Algorithm Development
An **algorithm** describes how to solve a problem by listing:
- Actions that need to be taken
- Order of execution

### Example: Computing Circle Area

#### Algorithm (in natural language):
1. Read in the circle's radius
2. Compute the area using formula: area = radius × radius × π
3. Display the result

#### Algorithm (in pseudocode):
```
BEGIN
  INPUT radius
  SET area = radius * radius * 3.14159
  OUTPUT area
END
```

### Complete Program Implementation

```java
public class ComputeArea {
    public static void main(String[] args) {
        double radius;    // Declare radius variable
        double area;      // Declare area variable
        
        // Assign a radius
        radius = 20;      // radius is now 20
        
        // Compute area
        area = radius * radius * 3.14159;
        
        // Display results
        System.out.println("The area for the circle of radius " +
                          radius + " is " + area);
    }
}
```

### Key Concepts Explained

#### Variables
- **Definition**: Symbols that represent values stored in computer memory
- **Purpose**: Store data that can be used and modified during program execution
- **Naming**: Use descriptive names (e.g., `radius`, `area` instead of `x`, `y`)

#### Data Types
- **Purpose**: Tell the compiler what kind of data a variable can store
- **Examples**: `double` for floating-point numbers, `int` for integers

#### String Concatenation
The `+` operator has dual purposes:
1. **Addition**: `5 + 3 = 8`
2. **String concatenation**: `"Hello " + "World" = "Hello World"`

When combining strings with numbers, numbers are automatically converted to strings.

### Program Tracing
Track variable values as the program executes:

| Line | radius | area |
|------|--------|------|
| 3    | no value | no value |
| 4    | no value | no value |
| 7    | 20 | no value |
| 10   | 20 | 1256.636 |

### Important Notes
- String literals cannot span multiple lines
- Use concatenation operator to break long strings:
```java
// WRONG:
System.out.println("This is a very long string that
                   spans multiple lines");

// CORRECT:
System.out.println("This is a very long string that " +
                  "spans multiple lines");
```

### Check Point 2.1
**Problem**: Identify and fix errors in this code:
```java
public class Test {
    public void main(string[] args) {  // Error 1: should be "String[]"
                                      // Error 2: should be "public static void"
        double i = 50.0;
        double k = i + 50.0;
        double j = k + 1;
        
        System.out.println("j is " + j + " and  // Error 3: string not closed
        k is " + k);                            // Error 4: should be on same line
    }
}
```

**Fixes**:
1. Change `string[]` to `String[]`
2. Add `static` keyword: `public static void main`
3. Close the string properly or use concatenation
4. Put the entire string on one line or use proper concatenation

---

## 2.3 Reading Input from the Console

### The Problem with Fixed Values
In the previous example, the radius was hardcoded (fixed) in the source code. To use different values, you'd need to:
1. Modify the source code
2. Recompile the program
3. Run again

This is inefficient and impractical.

### Solution: Scanner Class
Java provides the `Scanner` class for reading user input from the console.

### Standard Input/Output Devices
- **System.out**: Standard output (usually the monitor)
- **System.in**: Standard input (usually the keyboard)
- **System.out.println()**: Display output and move to next line
- **System.out.print()**: Display output without moving to next line

### Creating and Using Scanner

#### Step 1: Import Scanner
```java
import java.util.Scanner;  // Import statement at top of file
```

#### Step 2: Create Scanner Object
```java
Scanner input = new Scanner(System.in);
```

#### Step 3: Read Input
```java
double radius = input.nextDouble();  // Read a double value
```

### Complete Example: Interactive Circle Area Calculator

```java
import java.util.Scanner;

public class ComputeAreaWithConsoleInput {
    public static void main(String[] args) {
        // Create a Scanner object
        Scanner input = new Scanner(System.in);
        
        // Prompt the user to enter a radius
        System.out.print("Enter a number for radius: ");
        double radius = input.nextDouble();
        
        // Compute area
        double area = radius * radius * 3.14159;
        
        // Display results
        System.out.println("The area for the circle of radius " +
                          radius + " is " + area);
    }
}
```

### Sample Runs
```
Enter a number for radius: 2.5
The area for the circle of radius 2.5 is 19.6349375

Enter a number for radius: 23
The area for the circle of radius 23.0 is 1661.90111
```

### Reading Multiple Inputs

```java
import java.util.Scanner;

public class ComputeAverage {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        // Prompt the user to enter three numbers
        System.out.print("Enter three numbers: ");
        double number1 = input.nextDouble();
        double number2 = input.nextDouble();
        double number3 = input.nextDouble();
        
        // Compute average
        double average = (number1 + number2 + number3) / 3;
        
        // Display results
        System.out.println("The average of " + number1 + " " + number2
                          + " " + number3 + " is " + average);
    }
}
```

### Input Flexibility
Users can enter numbers in two ways:
1. **All on one line**: `1 2 3` (separated by spaces)
2. **Multiple lines**: Press Enter after each number

### Import Statements

#### Specific Import
```java
import java.util.Scanner;  // Import only Scanner class
```

#### Wildcard Import
```java
import java.util.*;  // Import all classes from java.util package
```

**Performance Note**: No performance difference between specific and wildcard imports.

### IPO Pattern
Most early programs follow the **IPO** pattern:
- **I**nput: Receive input from user
- **P**rocess: Perform calculations using the input
- **O**utput: Display the results

### Error Handling
- If user enters non-numeric input (e.g., "5a" instead of "5"), a runtime error occurs
- Chapter 12 covers exception handling for robust input validation

### Check Points 2.2-2.3

**2.2**: How to let user enter a double value?
```java
Scanner input = new Scanner(System.in);
double value = input.nextDouble();
```

**2.3**: Performance difference between import statements?
**Answer**: No performance difference between `import java.util.Scanner;` and `import java.util.*;`

---

## 2.4 Identifiers

### Definition
**Identifiers** are names that identify elements in a program such as:
- Classes
- Methods  
- Variables
- Constants

### Identifier Naming Rules

#### Must Follow These Rules:
1. **Character composition**: Letters, digits, underscores (_), dollar signs ($)
2. **Starting character**: Must start with letter, underscore (_), or dollar sign ($)
3. **Cannot start with digit**: `2A` is invalid
4. **Cannot be reserved words**: `class`, `public`, `int` are invalid
5. **Cannot be literals**: `true`, `false`, `null` are invalid
6. **Any length**: No limit on identifier length

#### Examples:
- **Valid**: `$2`, `ComputeArea`, `area`, `radius`, `print`, `_value`, `$amount`
- **Invalid**: `2A`, `d+4`, `class`, `public`, `true`

### Case Sensitivity
Java is case-sensitive, so these are different identifiers:
- `area`
- `Area` 
- `AREA`

### Best Practices

#### Use Descriptive Names
```java
// GOOD:
int numberOfStudents = 25;
double monthlyInterestRate = 0.05;

// POOR:
int n = 25;
double rate = 0.05;
```

#### Avoid Abbreviations
```java
// BETTER:
int numberOfStudents;

// AVOID:
int numStuds;
int numOfStuds;
int noOfStudents;
```

#### Dollar Sign Convention
- Avoid using `$` in identifiers
- By convention, `$` should only be used in mechanically generated code

### Check Point 2.4
**Question**: Which identifiers are valid? Which are Java keywords?

**Identifiers to check**: `miles`, `Test`, `a++`, `--a`, `4#R`, `$4`, `#44`, `apps`, `class`, `public`, `int`, `x`, `y`, `radius`

**Analysis**:
- **Valid identifiers**: `miles`, `Test`, `$4`, `apps`, `x`, `y`, `radius`
- **Invalid identifiers**: `a++` (contains +), `--a` (contains -), `4#R` (starts with digit, contains #), `#44` (starts with #)
- **Java keywords**: `class`, `public`, `int`

---

## 2.5 Variables

### Definition and Purpose
**Variables** are used to represent values that may change during program execution. They're called "variables" because their values can vary (change).

### Variable Characteristics
Every variable has four properties:
1. **Name**: Identifier for the variable
2. **Type**: Kind of data it can store
3. **Size**: Amount of memory allocated
4. **Value**: Current data stored

### Variable Declaration Syntax
```java
datatype variableName;
```

### Examples of Variable Declarations
```java
int count;           // Declare count as integer
double radius;       // Declare radius as double
double interestRate; // Declare interestRate as double
```

### Declaring Multiple Variables

#### Same Type Together:
```java
datatype variable1, variable2, ..., variablen;

// Example:
int i, j, k;  // Declare i, j, and k as int variables
```

### Variable Initialization

#### Method 1: Declare then Initialize
```java
int count;
count = 1;
```

#### Method 2: Declare and Initialize Together
```java
int count = 1;  // Preferred method
```

#### Method 3: Multiple Variables with Initialization
```java
int i = 1, j = 2;  // Declare and initialize multiple variables
```

### Variable Scope
**Scope**: The part of the program where a variable can be referenced.

**Important Rules**:
- Variable must be declared before use
- Variable must be assigned a value before it can be used
- Variables declared in a method must be initialized before use

### Variable Value Changes Example
```java
// Initial assignment
radius = 1.0;                           // radius: 1.0
area = radius * radius * 3.14159;       // area: 3.14159
System.out.println("The area is " + area + " for radius " + radius);

// Value changes
radius = 2.0;                           // radius: 2.0 (changed)
area = radius * radius * 3.14159;       // area: 12.56636 (changed)
System.out.println("The area is " + area + " for radius " + radius);
```

### Best Practices
1. **Declare and initialize together** when possible
2. **Use descriptive names** that indicate the variable's purpose
3. **Initialize before use** to avoid compilation errors

### Check Point 2.5
**Problem**: Identify and fix errors:
```java
public class Test {
    public static void main(String[] args) {
        int i = k + 2;  // Error: k is not declared
        System.out.println(i);
    }
}
```

**Fix**: Declare `k` before using it:
```java
public class Test {
    public static void main(String[] args) {
        int k = 5;      // Declare and initialize k
        int i = k + 2;  // Now k is available
        System.out.println(i);
    }
}
```

---

## 2.6 Assignment Statements and Assignment Expressions

### Assignment Statement
An **assignment statement** designates a value for a variable.

### Syntax
```java
variable = expression;
```

### Assignment Operator
The equal sign (`=`) is the **assignment operator** in Java.

### Expression Definition
An **expression** represents a computation involving:
- Values
- Variables  
- Operators
- Results in a single value

### Assignment Examples
```java
int y = 1;                              // Assign 1 to y
double radius = 1.0;                    // Assign 1.0 to radius
int x = 5 * (3 / 2);                   // Assign result of expression to x
x = y + 1;                             // Assign y + 1 to x
double area = radius * radius * 3.14159; // Compute and assign area
```

### Self-Assignment
Variables can appear on both sides of assignment:
```java
x = x + 1;  // Add 1 to current value of x
```

**Execution Steps**:
1. Evaluate right side: `x + 1`
2. Assign result to left side variable: `x`

### Important Notes

#### Mathematical vs Programming Context
- **Mathematics**: `x = 2x + 1` is an equation
- **Java**: `x = 2 * x + 1` is an assignment statement

#### Assignment as Expression
Assignment statements are also expressions:
```java
System.out.println(x = 1);  // Valid! Assigns 1 to x and prints 1
```

This is equivalent to:
```java
x = 1;
System.out.println(x);
```

### Multiple Assignment
```java
i = j = k = 1;  // Assigns 1 to k, then k to j, then j to i
```

Equivalent to:
```java
k = 1;
j = k;
i = j;
```

### Data Type Compatibility
The left side variable type must be compatible with right side value:
```java
int x = 1.0;    // ERROR: Cannot assign double to int without casting
int x = 1;      // CORRECT: int value to int variable
```

### Check Point 2.6
**Problem**: Fix the errors:
```java
public class Test {
    public static void main(String[] args) {
        int i = j = k = 2;  // Error: j and k not declared
        System.out.println(i + " " + j + " " + k);
    }
}
```

**Fix**: Declare all variables:
```java
public class Test {
    public static void main(String[] args) {
        int i, j, k;        // Declare all variables first
        i = j = k = 2;      // Then assign values
        System.out.println(i + " " + j + " " + k);
    }
}
```

---

## 2.7 Named Constants

### Definition
A **named constant** (or simply **constant**) is an identifier that represents a permanent value that never changes during program execution.

### Why Use Constants?
In the circle area program, π (pi) is always 3.14159. Instead of typing this value repeatedly, we can declare it as a constant.

### Syntax
```java
final datatype CONSTANTNAME = value;
```

### Key Requirements
- Must use `final` keyword
- Must be declared and initialized in the same statement
- Cannot be changed after initialization

### Example: Using PI as a Constant
```java
import java.util.Scanner;

public class ComputeAreaWithConstant {
    public static void main(String[] args) {
        final double PI = 3.14159;  // Declare a constant
        
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a number for radius: ");
        double radius = input.nextDouble();
        
        // Compute area using constant
        double area = radius * radius * PI;
        
        System.out.println("The area for the circle of radius " +
                          radius + " is " + area);
    }
}
```

### Benefits of Using Constants

#### 1. Avoid Repetition
Instead of typing `3.14159` multiple times throughout your program.

#### 2. Easy Maintenance
To change the precision of PI from 3.14159 to 3.14159265, you only need to change it in one location.

#### 3. Improved Readability
`PI` is more meaningful than `3.14159` in the code.

#### 4. Prevent Accidental Changes
The `final` keyword prevents accidental modification of the value.

### More Constant Examples
```java
final int DAYS_IN_WEEK = 7;
final double INCHES_PER_FOOT = 12.0;
final int SECONDS_PER_MINUTE = 60;
final double GRAVITY = 9.8;
```

### Check Point 2.7
**Question**: What are the benefits of using constants? Declare an int constant SIZE with value 20.

**Benefits**:
1. No need to repeatedly type the same value
2. Easy to change the value in one location
3. Makes program more readable with descriptive names

**Declaration**:
```java
final int SIZE = 20;
```

---

## 2.8 Naming Conventions

### Importance
Following Java naming conventions makes programs:
- Easy to read
- Professional-looking
- Less error-prone
- Consistent with Java community standards

### Variable and Method Names
- **Use lowercase** for the first word
- **Capitalize first letter** of each subsequent word
- **Examples**: `radius`, `area`, `computeArea`, `monthlyPayment`

### Class Names
- **Capitalize first letter** of each word
- **Examples**: `ComputeArea`, `Scanner`, `System`

### Constant Names
- **All uppercase letters**
- **Use underscores** between words
- **Examples**: `PI`, `MAX_VALUE`, `DAYS_IN_WEEK`

### Naming Convention Examples

#### Variables and Methods:
```java
double radius;
double interestRate;
int numberOfStudents;
void calculateArea();
void printResults();
```

#### Classes:
```java
public class ComputeArea { }
public class StudentGradeCalculator { }
public class BankAccount { }
```

#### Constants:
```java
final double PI = 3.14159;
final int MAX_STUDENTS = 30;
final double KILOMETERS_PER_MILE = 1.609;
```

### Important Warnings

#### Avoid Existing Class Names
Don't use names that already exist in Java library:
```java
// WRONG: System is already a Java class
public class System { }

// CORRECT: Choose a different name
public class SystemMonitor { }
```

### Check Point 2.8
**Question**: What are the naming conventions? Which items can be constant, method, variable, or class?

**Items to classify**: `MAX_VALUE`, `Test`, `read`, `readDouble`

**Analysis**:
- `MAX_VALUE`: **Constant** (all uppercase with underscore)
- `Test`: **Class** (first letter capitalized)
- `read`: **Variable or method** (lowercase)
- `readDouble`: **Variable or method** (camelCase)

### Check Point 2.9
**Algorithm Translation**:
```
Step 1: Declare a double variable named miles with initial value 100
Step 2: Declare a double constant named KILOMETERS_PER_MILE with value 1.609
Step 3: Declare a double variable named kilometers, multiply miles and KILOMETERS_PER_MILE, and assign the result to kilometers
Step 4: Display kilometers to the console
```

**Java Code**:
```java
double miles = 100.0;                                    // Step 1
final double KILOMETERS_PER_MILE = 1.609;              // Step 2
double kilometers = miles * KILOMETERS_PER_MILE;        // Step 3
System.out.println(kilometers);                         // Step 4
```

**Result**: kilometers = 160.9

---

## 2.9 Numeric Data Types and Operations

### 2.9.1 Numeric Types

Java provides **eight primitive data types** for different kinds of values. Six are for numeric values.

### Integer Types

| Type | Range | Storage Size | Description |
|------|-------|--------------|-------------|
| `byte` | -128 to 127 | 8-bit signed | Smallest integer type |
| `short` | -32,768 to 32,767 | 16-bit signed | Small integer type |
| `int` | -2,147,483,648 to 2,147,483,647 | 32-bit signed | Standard integer type |
| `long` | -9,223,372,036,854,775,808 to 9,223,372,036,854,775,807 | 64-bit signed | Large integer type |

### Floating-Point Types

| Type | Range | Storage Size | Precision |
|------|-------|--------------|-----------|
| `float` | ±3.4E±38 (7 digits) | 32-bit IEEE 754 | Single precision |
| `double` | ±1.7E±308 (15-17 digits) | 64-bit IEEE 754 | Double precision |

### Choosing the Right Type

#### For Integers:
- Use `int` for most integer operations (recommended for simplicity)
- Use `byte` if you know the value fits in -128 to 127
- Use `long` for very large numbers

#### For Floating-Point:
- Use `double` for most decimal operations (recommended for accuracy)
- Use `float` only when memory is critical and precision can be sacrificed

### IEEE 754 Standard
- International standard for representing floating-point numbers
- Java uses 32-bit IEEE 754 for `float`
- Java uses 64-bit IEEE 754 for `double`

### 2.9.2 Reading Numbers from the Keyboard

### Scanner Methods for Different Types

| Method | Return Type | Description |
|--------|-------------|-------------|
| `nextByte()` | `byte` | Reads a byte value |
| `nextShort()` | `short` | Reads a short value |
| `nextInt()` | `int` | Reads an int value |
| `nextLong()` | `long` | Reads a long value |
| `nextFloat()` | `float` | Reads a float value |
| `nextDouble()` | `double` | Reads a double value |

### Reading Different Types Example
```java
Scanner input = new Scanner(System.in);

System.out.print("Enter a byte value: ");
byte byteValue = input.nextByte();

System.out.print("Enter a short value: ");
short shortValue = input.nextShort();

System.out.print("Enter an int value: ");
int intValue = input.nextInt();

System.out.print("Enter a long value: ");
long longValue = input.nextLong();

System.out.print("Enter a float value: ");
float floatValue = input.nextFloat();
```

### Input Range Validation
- Entering a value outside the type's range causes runtime error
- Example: Entering 128 for `byte` type causes error (range is -128 to 127)

### 2.9.3 Numeric Operators

### Basic Arithmetic Operators

| Operator | Name | Example | Result |
|----------|------|---------|--------|
| `+` | Addition | `34 + 1` | 35 |
| `-` | Subtraction | `34.0 - 0.1` | 33.9 |
| `*` | Multiplication | `300 * 30` | 9000 |
| `/` | Division | `1.0 / 2.0` | 0.5 |
| `%` | Remainder/Modulo | `20 % 3` | 2 |

### Division Operator Details

#### Integer Division
When both operands are integers, result is integer (fractional part truncated):
```java
5 / 2     // Result: 2 (not 2.5)
-5 / 2    // Result: -2 (not -2.5)
```

#### Floating-Point Division
When at least one operand is floating-point:
```java
5.0 / 2   // Result: 2.5
5 / 2.0   // Result: 2.5
5.0 / 2.0 // Result: 2.5
```

### Remainder (%) Operator

#### How It Works
The remainder operator returns what's left after division:
```java
7 % 3   // 7 ÷ 3 = 2 remainder 1, so result is 1
20 % 3  // 20 ÷ 3 = 6 remainder 2, so result is 2
12 % 4  // 12 ÷ 4 = 3 remainder 0, so result is 0
```

#### Visual Representation
```
13 ÷ 3 = 4 remainder 1
    Quotient: 4
    Remainder: 1
    So: 13 % 3 = 1
```

#### With Negative Numbers
- Remainder has same sign as dividend (left operand)
```java
-7 % 3    // Result: -1
7 % -3    // Result: 1
-7 % -3   // Result: -1
```

#### Practical Applications

**1. Even/Odd Detection:**
```java
if (number % 2 == 0) {
    System.out.println("Even number");
} else {
    System.out.println("Odd number");
}
```

**2. Day of Week Calculation:**
```java
// If today is Saturday (day 6), what day is it in 10 days?
int today = 6;  // Saturday
int futureDay = (today + 10) % 7;  // Result: 2 (Tuesday)
```

### Complete Example: DisplayTime.java
```java
import java.util.Scanner;

public class DisplayTime {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter an integer for seconds: ");
        int seconds = input.nextInt();
        
        int minutes = seconds / 60;              // Find minutes
        int remainingSeconds = seconds % 60;     // Find remaining seconds
        
        System.out.println(seconds + " seconds is " + minutes +
                          " minutes and " + remainingSeconds + " seconds");
    }
}
```

**Sample Run**:
```
Enter an integer for seconds: 500
500 seconds is 8 minutes and 20 seconds
```

**Trace Table**:
| Line | seconds | minutes | remainingSeconds |
|------|---------|---------|------------------|
| 8    | 500     |         |                  |
| 10   | 500     | 8       |                  |
| 11   | 500     | 8       | 20               |

### Unary vs Binary Operators

#### Unary Operators (one operand):
```java
-5      // Negation
+5      // Positive (rarely used)
```

#### Binary Operators (two operands):
```java
4 - 5   // Subtraction
4 + 5   // Addition
```

### 2.9.4 Exponent Operations

### Math.pow() Method
For exponent operations, Java provides `Math.pow(a, b)` which computes a^b.

### Syntax and Examples
```java
Math.pow(base, exponent)

// Examples:
Math.pow(2, 3)      // 2³ = 8.0
Math.pow(4, 0.5)    // √4 = 2.0
Math.pow(2.5, 2)    // 2.5² = 6.25
Math.pow(2.5, -2)   // 2.5⁻² = 0.16
```

### Important Notes
- `Math.pow()` always returns a `double` value
- The `Math` class is in `java.lang` package (automatically imported)
- Parameters can be integers or floating-point numbers

### Check Points 2.10-2.17

**2.10**: Data type ranges and memory requirements
- **Smallest memory**: `byte` (8 bits)
- **Largest values**: See table above for specific ranges

**2.11**: Remainder operations
```java
56 % 6    // Result: 2
78 % -4   // Result: 2  
-34 % 5   // Result: -4
-34 % -5  // Result: -4
5 % 1     // Result: 0
1 % 5     // Result: 1
```

**2.12**: Day calculation
If today is Tuesday (day 2), in 100 days:
```java
(2 + 100) % 7 = 102 % 7 = 4  // Friday
```

**2.13**: Division results
```java
25 / 4        // Result: 6 (integer division)
25.0 / 4      // Result: 6.25 (floating-point division)
```

**2.14**: Expression evaluation
```java
System.out.println(2 * (5 / 2 + 5 / 2));  // 2 * (2 + 2) = 8
System.out.println(2 * 5 / 2 + 2 * 5 / 2); // 5 + 5 = 10
System.out.println(2 * (5 / 2));           // 2 * 2 = 4
System.out.println(2 * 5 / 2);             // 10 / 2 = 5
```

**2.15**: Mixed operations
```java
System.out.println("25 / 4 is " + 25 / 4);         // "25 / 4 is 6"
System.out.println("25 / 4.0 is " + 25 / 4.0);     // "25 / 4.0 is 6.25"
System.out.println("3 * 2 / 4 is " + 3 * 2 / 4);   // "3 * 2 / 4 is 1"
System.out.println("3.0 * 2 / 4 is " + 3.0 * 2 / 4); // "3.0 * 2 / 4 is 1.5"
```

**2.16**: Exponent expression
```java
System.out.println(Math.pow(2, 3.5));  // Displays result of 2^3.5
```

**2.17**: Expression for m * r²
```java
Math.pow(r, 2) * m    // or m * Math.pow(r, 2)
```

---

## 2.10 Numeric Literals

### Definition
A **literal** is a constant value that appears directly in the program source code.

### Examples
```java
int numberOfYears = 34;     // 34 is an integer literal
double weight = 0.305;      // 0.305 is a floating-point literal
```

### 2.10.1 Integer Literals

#### Range Constraints
- Integer literals must fit in the variable type
- Compile error occurs if literal is too large

#### Examples of Valid/Invalid Assignments
```java
byte b = 127;     // VALID: 127 fits in byte range (-128 to 127)
byte b = 128;     // ERROR: 128 exceeds byte range
```

#### Default Type
- Integer literals are assumed to be `int` type by default
- Range: -2,147,483,648 to 2,147,483,647

#### Long Literals
For values outside `int` range, append `L` or `l`:
```java
long bigNumber = 2147483648L;  // Must use L suffix
long another = 2147483648l;    // l works but L is preferred
```

**Why L is preferred**: Lowercase `l` looks like digit `1`

#### Different Number Systems

**Binary Literals** (prefix `0b` or `0B`):
```java
System.out.println(0B1111);  // Displays 15
System.out.println(0b1010);  // Displays 10
```

**Octal Literals** (prefix `0`):
```java
System.out.println(07777);   // Displays 4095
System.out.println(0123);    // Displays 83
```

**Hexadecimal Literals** (prefix `0x` or `0X`):
```java
System.out.println(0XFFFF);  // Displays 65535
System.out.println(0x1A3);   // Displays 419
```

### 2.10.2 Floating-Point Literals

#### Default Type
- Floating-point literals are `double` by default
- `5.0` is treated as `double`, not `float`

#### Type Suffixes

**Float Suffix** (`f` or `F`):
```java
float number1 = 100.2f;
float number2 = 100.2F;
```

**Double Suffix** (`d` or `D`):
```java
double number1 = 100.2d;
double number2 = 100.2D;
```

#### Precision Comparison
```java
System.out.println("1.0 / 3.0 is " + 1.0 / 3.0);
// Output: 1.0 / 3.0 is 0.3333333333333333 (16 digits)

System.out.println("1.0F / 3.0F is " + 1.0F / 3.0F);
// Output: 1.0F / 3.0F is 0.33333334 (8 digits)
```

### 2.10.3 Scientific Notation

#### Mathematical Form
Scientific notation represents numbers as: **a × 10^b**

#### Examples
- 123.456 = 1.23456 × 10²
- 0.0123456 = 1.23456 × 10⁻²

#### Java Syntax
Use `E` or `e` to represent "× 10^":

```java
double value1 = 1.23456E2;    // 1.23456 × 10² = 123.456
double value2 = 1.23456E+2;   // Same as above
double value3 = 1.23456E-2;   // 1.23456 × 10⁻² = 0.0123456
double value4 = 5.0e3;        // 5.0 × 10³ = 5000.0
```

#### Why Called "Floating-Point"?
When 50.534 is stored as 5.0534E+1, the decimal point "floats" to a new position.

### Underscore in Numeric Literals
For readability, Java allows underscores between digits:

```java
// VALID:
long ssn = 232_45_4519;
long creditCard = 2324_4545_4519_3415L;
double pi = 3.141_592_653_589_793;

// INVALID:
int wrong1 = 45_;     // Cannot end with underscore
int wrong2 = _45;     // Cannot start with underscore
```

### Check Points 2.18-2.21

**2.18**: Floating-point precision
- `float`: 7-8 significant digits
- `double`: 15-17 significant digits

**2.19**: Valid floating-point literals
- **Valid**: `12.3`, `12.3e+2`, `23.4e-2`, `-334.4`, `20.5`, `39F`, `40D`
- All are syntactically correct

**2.20**: Equivalent to 52.534
- `5.2534e+1` ✓ (5.2534 × 10¹ = 52.534)
- `0.52534e+2` ✓ (0.52534 × 10² = 52.534)
- `525.34e-1` ✓ (525.34 × 10⁻¹ = 52.534)
- `5.2534e+0` ✗ (5.2534 × 10⁰ = 5.2534)

**2.21**: Valid literals with underscores
- `5_2534e+1` ✓ (underscore between digits)
- `_2534` ✗ (starts with underscore)
- `5_2` ✓ (underscore between digits)
- `5_` ✗ (ends with underscore)

---

## 2.11 Evaluating Expressions and Operator Precedence

### Expression Evaluation
Java expressions follow the same rules as arithmetic expressions.

### Arithmetic to Java Translation
**Arithmetic expression**:
```
3 + 4x/5 - 10(y - 5)(a + b + c)/x + 9(4/x + (9 + x)/y)
```

**Java expression**:
```java
(3 + 4 * x) / 5 - 10 * (y - 5) * (a + b + c) / x +
9 * (4 / x + (9 + x) / y)
```

### Operator Precedence Rules

#### Precedence Order (highest to lowest):
1. **Parentheses**: `()` - evaluated first, innermost first
2. **Multiplication, Division, Remainder**: `*`, `/`, `%` - left to right
3. **Addition, Subtraction**: `+`, `-` - left to right

### Step-by-Step Evaluation Example
```java
3 + 4 * 4 + 5 * (4 + 3) - 1

Step 1: 3 + 4 * 4 + 5 * 7 - 1        // (4 + 3) = 7
Step 2: 3 + 16 + 5 * 7 - 1            // 4 * 4 = 16
Step 3: 3 + 16 + 35 - 1               // 5 * 7 = 35
Step 4: 19 + 35 - 1                   // 3 + 16 = 19
Step 5: 54 - 1                        // 19 + 35 = 54
Step 6: 53                            // 54 - 1 = 53
```

### Practical Example: Fahrenheit to Celsius Conversion

#### Mathematical Formula:
celsius = (5/9) × (fahrenheit - 32)

#### Java Implementation:
```java
import java.util.Scanner;

public class FahrenheitToCelsius {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a degree in Fahrenheit: ");
        double fahrenheit = input.nextDouble();
        
        // Convert Fahrenheit to Celsius
        double celsius = (5.0 / 9) * (fahrenheit - 32);
        
        System.out.println("Fahrenheit " + fahrenheit + " is " +
                          celsius + " in Celsius");
    }
}
```

#### Critical Division Note
- `5 / 9` in Java equals `0` (integer division)
- `5.0 / 9` equals `0.5555...` (floating-point division)
- Always use `5.0 / 9` for correct result

**Sample Run**:
```
Enter a degree in Fahrenheit: 100
Fahrenheit 100.0 is 37.77777777777778 in Celsius
```

### Check Point 2.22
**Write Java expressions for**:

**a.** `4/(3(r + 34)) - 9(a + bc) + (3 + d(2 + a))/(a + bd)`

**Java**:
```java
4 / (3 * (r + 34)) - 9 * (a + b * c) + 
(3 + d * (2 + a)) / (a + b * d)
```

**b.** `5.5 × (r + 2.5)^2.5 + t`

**Java**:
```java
5.5 * Math.pow(r + 2.5, 2.5) + t
```

---

## 2.12 Case Study: Displaying the Current Time

### Problem Statement
Develop a program that displays the current time in GMT format: `hour:minute:second` (e.g., 13:19:8).

### Understanding System.currentTimeMillis()
- Returns current time in **milliseconds**
- Measured since **UNIX epoch**: midnight, January 1, 1970 GMT
- Returns a `long` value (e.g., 1203183068328 milliseconds)

### Algorithm Steps

1. **Get total milliseconds** since UNIX epoch
2. **Convert to total seconds** by dividing by 1000
3. **Extract current second** using remainder: `totalSeconds % 60`
4. **Get total minutes** by dividing seconds by 60
5. **Extract current minute** using remainder: `totalMinutes % 60`
6. **Get total hours** by dividing minutes by 60  
7. **Extract current hour** using remainder: `totalHours % 24`

### Detailed Calculation Example
Starting with: `1203183068328` milliseconds

```java
// Step 1: Total milliseconds (given)
long totalMilliseconds = 1203183068328L;

// Step 2: Convert to seconds
long totalSeconds = totalMilliseconds / 1000;  // = 1203183068

// Step 3: Extract current second
long currentSecond = totalSeconds % 60;        // = 8

// Step 4: Get total minutes
long totalMinutes = totalSeconds / 60;         // = 20053051

// Step 5: Extract current minute  
long currentMinute = totalMinutes % 60;        // = 31

// Step 6: Get total hours
long totalHours = totalMinutes / 60;           // = 334217

// Step 7: Extract current hour
long currentHour = totalHours % 24;            // = 17
```

### Complete Program Implementation
```java
public class ShowCurrentTime {
    public static void main(String[] args) {
        // Obtain the total milliseconds since midnight, Jan 1, 1970
        long totalMilliseconds = System.currentTimeMillis();
        
        // Obtain the total seconds since midnight, Jan 1, 1970
        long totalSeconds = totalMilliseconds / 1000;
        
        // Compute the current second in the minute
        long currentSecond = totalSeconds % 60;
        
        // Obtain the total minutes
        long totalMinutes = totalSeconds / 60;
        
        // Compute the current minute in the hour
        long currentMinute = totalMinutes % 60;
        
        // Obtain the total hours
        long totalHours = totalMinutes / 60;
        
        // Compute the current hour
        long currentHour = totalHours % 24;
        
        // Display results
        System.out.println("Current time is " + currentHour + ":" +
                          currentMinute + ":" + currentSecond + " GMT");
    }
}
```

### Sample Output
```
Current time is 17:31:8 GMT
```

### Program Trace Table
| Line | totalMilliseconds | totalSeconds | currentSecond | totalMinutes | currentMinute | totalHours | currentHour |
|------|------------------|--------------|---------------|--------------|---------------|------------|-------------|
| 4    | 1203183068328    |              |               |              |               |            |             |
| 7    | 1203183068328    | 1203183068   |               |              |               |            |             |
| 10   | 1203183068328    | 1203183068   | 8             |              |               |            |             |
| 13   | 1203183068328    | 1203183068   | 8             | 20053051     |               |            |             |
| 16   | 1203183068328    | 1203183068   | 8             | 20053051     | 31            |            |             |
| 19   | 1203183068328    | 1203183068   | 8             | 20053051     | 31            | 334217     |             |
| 22   | 1203183068328    | 1203183068   | 8             | 20053051     | 31            | 334217     | 17          |

### Output Formatting Note
- Single digit seconds display as "8" instead of "08"
- Can be improved using formatting methods (covered in later exercises)

### Why Use `long` Data Type?
- `System.currentTimeMillis()` returns a `long` value
- The number of milliseconds since 1970 is very large
- All calculations use `long` to maintain precision

### Check Point 2.23
**Question**: How do you obtain the current second, minute, and hour?

**Answer**:
```java
long totalMilliseconds = System.currentTimeMillis();
long totalSeconds = totalMilliseconds / 1000;
long currentSecond = totalSeconds % 60;
long totalMinutes = totalSeconds / 60;
long currentMinute = totalMinutes % 60;
long totalHours = totalMinutes / 60;
long currentHour = totalHours % 24;
```

---

## 2.13 Augmented Assignment Operators

### Purpose
**Augmented assignment operators** combine arithmetic operations with assignment for concise code.

### Common Pattern
Many programs use this pattern:
```java
variable = variable operator value;
```

Examples:
```java
count = count + 1;      // Increment count by 1
total = total + price;  // Add price to total
balance = balance * 1.05; // Increase balance by 5%
```

### Augmented Assignment Operators

| Operator | Name | Example | Equivalent |
|----------|------|---------|------------|
| `+=` | Addition assignment | `i += 8` | `i = i + 8` |
| `-=` | Subtraction assignment | `i -= 8` | `i = i - 8` |
| `*=` | Multiplication assignment | `i *= 8` | `i = i * 8` |
| `/=` | Division assignment | `i /= 8` | `i = i / 8` |
| `%=` | Remainder assignment | `i %= 8` | `i = i % 8` |

### Examples in Action
```java
int count = 10;
count += 5;        // count becomes 15
count -= 3;        // count becomes 12
count *= 2;        // count becomes 24
count /= 4;        // count becomes 6
count %= 5;        // count becomes 1
```

### Operator Precedence
Augmented assignment is performed **after** all other operators in the expression:

```java
x /= 4 + 5.5 * 1.5;
```

This is equivalent to:
```java
x = x / (4 + 5.5 * 1.5);    // Division happens after full expression evaluation
```

### Important Syntax Rules

#### No Spaces Allowed
```java
count + = 5;    // WRONG: space between + and =
count += 5;     // CORRECT: no spaces
```

#### Assignment vs Expression Usage
Augmented operators can be used as both statements and expressions:

```java
x += 2;                    // Used as statement
System.out.println(x += 2); // Used as expression
```

### Check Point 2.24
**Problem**: Show the output:
```java
double a = 6.5;
a += a + 1;
System.out.println(a);
a = 6;
a /= 2;
System.out.println(a);
```

**Solution**:
```java
double a = 6.5;
a += a + 1;           // a = a + (a + 1) = 6.5 + (6.5 + 1) = 6.5 + 7.5 = 14.0
System.out.println(a); // Output: 14.0

a = 6;
a /= 2;               // a = a / 2 = 6 / 2 = 3.0
System.out.println(a); // Output: 3.0
```

---

## 2.14 Increment and Decrement Operators

### Overview
The increment (`++`) and decrement (`--`) operators provide shorthand for adding or subtracting 1 from a variable.

### Basic Usage
```java
int i = 3, j = 3;
i++;    // i becomes 4 (postincrement)
j--;    // j becomes 2 (postdecrement)
```

### Operator Positions

#### Postfix (Post-increment/decrement)
Operator comes **after** the variable:
```java
i++;    // Postincrement
j--;    // Postdecrement
```

#### Prefix (Pre-increment/decrement)  
Operator comes **before** the variable:
```java
++i;    // Preincrement
--j;    // Predecrement
```

### When Position Matters
The position matters when the operator is used within a larger expression.

### Detailed Comparison Table

| Operator | Name | Description | Example (assume i = 1) |
|----------|------|-------------|------------------------|
| `++var` | Preincrement | Increment var by 1, then use new value | `int j = ++i;` → j=2, i=2 |
| `var++` | Postincrement | Use current var value, then increment by 1 | `int j = i++;` → j=1, i=2 |
| `--var` | Predecrement | Decrement var by 1, then use new value | `int j = --i;` → j=0, i=0 |
| `var--` | Postdecrement | Use current var value, then decrement by 1 | `int j = i--;` → j=1, i=0 |

### Detailed Examples

#### Example 1: Postincrement
```java
int i = 10;
int newNum = 10 * i++;
System.out.println("i is " + i + ", newNum is " + newNum);
```

**Execution order**:
1. Use current value of `i` (10) in multiplication: `10 * 10 = 100`
2. Increment `i` by 1: `i` becomes 11
3. **Output**: `i is 11, newNum is 100`

#### Example 2: Preincrement
```java
int i = 10;
int newNum = 10 * (++i);
System.out.println("i is " + i + ", newNum is " + newNum);
```

**Execution order**:
1. Increment `i` by 1: `i` becomes 11
2. Use new value of `i` (11) in multiplication: `10 * 11 = 110`
3. **Output**: `i is 11, newNum is 110`

#### Example 3: Complex Expression
```java
double x = 1.0;
double y = 5.0;
double z = x-- + (++y);
```

**Execution order**:
1. `++y`: Increment y to 6.0, use 6.0 in expression
2. `x--`: Use current x value (1.0) in expression, then decrement x to 0.0
3. Calculate: `z = 1.0 + 6.0 = 7.0`

**Final values**: x=0.0, y=6.0, z=7.0

### Best Practices and Warnings

#### Keep It Simple
```java
// GOOD: Clear and simple
int count = 5;
count++;
System.out.println(count);

// AVOID: Complex and confusing
int k = ++i + i++;  // Hard to understand, error-prone
```

#### Recommendation
- Use increment/decrement operators for simple cases
- Avoid using them in complex expressions
- When in doubt, use separate statements for clarity

### Check Points 2.25-2.26

**2.25**: Which statements are true?
- a. Any expression can be used as a statement. ✓ **TRUE**
- b. The expression `x++` can be used as a statement. ✓ **TRUE**
- c. The statement `x = x + 5` is also an expression. ✓ **TRUE**
- d. The statement `x = y = x = 0` is illegal. ✗ **FALSE** (it's legal)

**2.26**: Show the output:
```java
int a = 6;
int b = a++;        // b gets current value of a (6), then a increments to 7
System.out.println(a);  // Output: 7
System.out.println(b);  // Output: 6

a = 6;
b = ++a;            // a increments to 7, then b gets new value of a (7)
System.out.println(a);  // Output: 7  
System.out.println(b);  // Output: 7
```

---

## 2.15 Numeric Type Conversions

### Automatic Type Conversion
Java automatically converts between numeric types when needed.

### Widening vs Narrowing

#### Widening (Automatic)
Converting from smaller range to larger range:
```java
int → long → float → double
byte → short → int → long → float → double
```

Examples:
```java
int intValue = 5;
double doubleValue = intValue;  // Automatic widening: 5 → 5.0
long longValue = intValue;      // Automatic widening: 5 → 5L
```

#### Narrowing (Explicit Casting Required)
Converting from larger range to smaller range:
```java
double → float → long → int → short → byte
```

### Explicit Casting

#### Syntax
```java
(targetType) value
```

#### Examples
```java
System.out.println((int)1.7);      // Output: 1 (fractional part truncated)
System.out.println((double)1 / 2); // Output: 0.5 (1 becomes 1.0)
System.out.println(1 / 2);         // Output: 0 (integer division)
```

### Mixed-Type Operations
When different numeric types are used together, Java automatically promotes to the "wider" type:

```java
3 * 4.5     // int 3 becomes 3.0, result is 3.0 * 4.5 = 13.5
5 + 2.0     // int 5 becomes 5.0, result is 5.0 + 2.0 = 7.0
```

### Important Casting Notes

#### Information Loss Warning
```java
double d = 4.9;
int i = (int)d;     // i becomes 4, loses .9
```

#### Original Variable Unchanged
```java
double d = 4.5;
int i = (int)d;     // i becomes 4, but d is still 4.5
```

#### Augmented Assignment Casting
```java
int sum = 0;
sum += 4.5;         // Equivalent to: sum = (int)(sum + 4.5);
                    // Result: sum becomes 4
```

#### Literal Assignment Rules
```java
int i = 1;
byte b = i;         // ERROR: Explicit casting required

// But this is OK:
byte b = 1;         // OK: literal 1 is within byte range
```

### Practical Example: Sales Tax with Proper Formatting
```java
import java.util.Scanner;

public class SalesTax {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter purchase amount: ");
        double purchaseAmount = input.nextDouble();
        
        double tax = purchaseAmount * 0.06;
        
        // Display tax with 2 decimal places using casting
        System.out.println("Sales tax is $" + (int)(tax * 100) / 100.0);
    }
}
```

**How the formatting works**:
```
If tax = 11.853:
tax * 100 = 1185.3
(int)(tax * 100) = 1185 (truncated)
1185 / 100.0 = 11.85 (two decimal places)
```

### Check Points 2.27-2.31

**2.27**: Can different numeric types be used together?
**Answer**: Yes, Java automatically converts to compatible types.

**2.28**: What does casting from double to int do?
**Answer**: Truncates fractional part. Casting doesn't change the original variable.

**2.29**: Show output:
```java
float f = 12.5F;
int i = (int)f;
System.out.println("f is " + f);    // Output: f is 12.5
System.out.println("i is " + i);    // Output: i is 12
```

**2.30**: Change `(int)(tax * 100) / 100.0` to `(int)(tax * 100) / 100`
**Result**: Would perform integer division, giving `11` instead of `11.85`

**2.31**: Show output:
```java
double amount = 5;
System.out.println(amount / 2);     // Output: 2.5 (double division)
System.out.println(5 / 2);          // Output: 2 (integer division)
```

---

## 2.16 Software Development Process

### The Software Development Life Cycle
Developing software follows a systematic process with multiple stages.

### Seven Stages of Development

#### 1. Requirements Specification
- **Purpose**: Understand what the software needs to do
- **Process**: Close interaction between users and developers
- **Output**: Detailed documentation of software requirements
- **Challenge**: Problems aren't always well-defined initially

#### 2. System Analysis  
- **Purpose**: Analyze data flow and identify system input/output
- **Strategy**: Start with desired output, work backward to determine needed input
- **Focus**: Understanding the data transformations required

#### 3. System Design
- **Purpose**: Design process for obtaining output from input
- **Approach**: Break down problem into manageable components
- **Core Concept**: Input → Process → Output (IPO)
- **Strategy**: Use abstraction and modular design

#### 4. Implementation
- **Purpose**: Translate design into actual code
- **Activities**: 
  - Writing code for each component
  - Integration of components
  - Self-testing and debugging
- **Output**: Working software programs

#### 5. Testing
- **Purpose**: Ensure code meets requirements and eliminate bugs
- **Who**: Independent team (not the developers)
- **Scope**: Comprehensive testing of all functionality

#### 6. Deployment
- **Purpose**: Make software available to users
- **Options**: 
  - Install on individual machines
  - Deploy to servers for web access

#### 7. Maintenance
- **Purpose**: Update and improve the product over time
- **Activities**:
  - Fix newly discovered bugs
  - Add new features
  - Performance improvements
  - Security updates

### Iterative Nature
The process is **iterative** - you may need to go back to previous stages when:
- Errors are discovered
- Requirements change
- New issues arise

### Case Study: Loan Payment Calculator

#### Stage 1: Requirements Specification
The program must:
- Accept user input for interest rate, loan amount, and loan term
- Calculate and display monthly payment and total payment

#### Stage 2: System Analysis

**Required Output**:
- Monthly payment
- Total payment

**Mathematical Formulas**:
```
monthlyPayment = loanAmount × monthlyInterestRate / 
                 (1 - 1/(1 + monthlyInterestRate)^(numberOfYears × 12))

totalPayment = monthlyPayment × numberOfYears × 12
```

**Required Input**:
- Annual interest rate (convert to monthly)
- Loan amount
- Number of years

#### Stage 3: System Design

**Step-by-step process**:
1. Prompt user for annual interest rate, years, and loan amount
2. Convert annual interest rate to monthly decimal rate
3. Apply loan payment formula
4. Calculate total payment
5. Display results

**Interest Rate Conversion**:
- Input: Annual rate as percentage (e.g., 4.5%)
- Conversion: Divide by 1200 to get monthly decimal rate
- Example: 4.5% → 4.5/1200 = 0.00375

#### Stage 4: Implementation
```java
import java.util.Scanner;

public class ComputeLoan {
    public static void main(String[] args) {
        // Create Scanner
        Scanner input = new Scanner(System.in);
        
        // Enter annual interest rate
        System.out.print("Enter annual interest rate, e.g., 7.25%: ");
        double annualInterestRate = input.nextDouble();
        
        // Convert to monthly rate
        double monthlyInterestRate = annualInterestRate / 1200;
        
        // Enter number of years
        System.out.print("Enter number of years as an integer, e.g., 5: ");
        int numberOfYears = input.nextInt();
        
        // Enter loan amount
        System.out.print("Enter loan amount, e.g., 120000.95: ");
        double loanAmount = input.nextDouble();
        
        // Calculate monthly payment
        double monthlyPayment = loanAmount * monthlyInterestRate / 
            (1 - 1 / Math.pow(1 + monthlyInterestRate, numberOfYears * 12));
        
        // Calculate total payment
        double totalPayment = monthlyPayment * numberOfYears * 12;
        
        // Display results with 2 decimal places
        System.out.println("The monthly payment is $" +
                          (int)(monthlyPayment * 100) / 100.0);
        System.out.println("The total payment is $" +
                          (int)(totalPayment * 100) / 100.0);
    }
}
```

#### Stage 5: Testing
**Sample Run**:
```
Enter annual interest rate, e.g., 5.75%: 5.75
Enter number of years as an integer, e.g., 5: 15
Enter loan amount, e.g., 120000.95: 250000
The monthly payment is $2076.02
The total payment is $373684.53
```

### Program Trace Table
| Line | annualInterestRate | monthlyInterestRate | numberOfYears | loanAmount | monthlyPayment | totalPayment |
|------|-------------------|-------------------|---------------|------------|----------------|--------------|
| 10   | 5.75              |                   |               |            |                |              |
| 13   | 5.75              | 0.0047916666666   |               |            |                |              |
| 18   | 5.75              | 0.0047916666666   | 15            |            |                |              |
| 22   | 5.75              | 0.0047916666666   | 15            | 250000     |                |              |
| 25   | 5.75              | 0.0047916666666   | 15            | 250000     | 2076.0252175   |              |
| 27   | 5.75              | 0.0047916666666   | 15            | 250000     | 2076.0252175   | 373684.539   |

### Implementation Notes

#### Data Type Choices
- `numberOfYears`: Use `int` (whole numbers only)
- `loanAmount`, `monthlyPayment`: Use `double` (precision needed)
- Could use `byte` for `numberOfYears`, but `int` is simpler

#### Math Class Usage
- `Math.pow()` computes exponents
- `Math` class is in `java.lang` package (automatically imported)
- No explicit import needed

#### Formatting with Casting
```java
(int)(monthlyPayment * 100) / 100.0
```
This technique displays two decimal places by:
1. Multiply by 100: `2076.0252175 * 100 = 207602.52175`
2. Cast to int: `(int)207602.52175 = 207602`
3. Divide by 100.0: `207602 / 100.0 = 2076.02`

### Development Best Practices

#### Incremental Development
- Code and test steps one at a time
- Add functionality incrementally
- Easier to locate and fix problems

#### Formula Translation Tips
- Carefully translate mathematical formulas to Java
- Use parentheses to ensure correct order of operations
- Use `Math.pow()` for exponents

### Check Point 2.32
**Question**: Write the expression: `(-b + √(b² - 4ac)) / 2a`

**Java Code**:
```java
(-b + Math.sqrt(b * b - 4 * a * c)) / (2 * a)
```

---

## 2.17 Case Study: Counting Monetary Units

### Problem Statement
Create a program that breaks a dollar amount into the minimum number of dollars, quarters, dimes, nickels, and pennies.

### Requirements
- **Input**: Amount in dollars and cents (e.g., 11.56)
- **Output**: Breakdown into monetary units
- **Goal**: Minimize the total number of coins

### Algorithm Design

#### Step-by-step Approach:
1. Read the amount as a decimal number
2. Convert to cents (multiply by 100)
3. Extract dollars (divide cents by 100)
4. Find remaining cents (use remainder operator)
5. Extract quarters from remaining cents
6. Continue with dimes, nickels, and pennies

#### Detailed Algorithm:
```
1. INPUT: amount (e.g., 11.56)
2. cents = amount × 100 (e.g., 1156)
3. dollars = cents ÷ 100 (e.g., 11)
4. remainingCents = cents % 100 (e.g., 56)
5. quarters = remainingCents ÷ 25 (e.g., 2)
6. remainingCents = remainingCents % 25 (e.g., 6)
7. dimes = remainingCents ÷ 10 (e.g., 0)
8. remainingCents = remainingCents % 10 (e.g., 6)
9. nickels = remainingCents ÷ 5 (e.g., 1)
10. pennies = remainingCents % 5 (e.g., 1)
```

### Implementation
```java
import java.util.Scanner;

public class ComputeChange {
    public static void main(String[] args) {
        // Create Scanner
        Scanner input = new Scanner(System.in);
        
        // Receive the amount
        System.out.print("Enter an amount in double, for example 11.56: ");
        double amount = input.nextDouble();
        
        // Convert to cents to avoid floating-point precision issues
        int remainingAmount = (int)(amount * 100);
        
        // Find the number of one dollars
        int numberOfOneDollars = remainingAmount / 100;
        remainingAmount = remainingAmount % 100;
        
        // Find the number of quarters in the remaining amount
        int numberOfQuarters = remainingAmount / 25;
        remainingAmount = remainingAmount % 25;
        
        // Find the number of dimes in the remaining amount
        int numberOfDimes = remainingAmount / 10;
        remainingAmount = remainingAmount % 10;
        
        // Find the number of nickels in the remaining amount
        int numberOfNickels = remainingAmount / 5;
        remainingAmount = remainingAmount % 5;
        
        // Find the number of pennies in the remaining amount
        int numberOfPennies = remainingAmount;
        
        // Display results
        System.out.println("Your amount " + amount + " consists of");
        System.out.println("    " + numberOfOneDollars + " dollars");
        System.out.println("    " + numberOfQuarters + " quarters");
        System.out.println("    " + numberOfDimes + " dimes");
        System.out.println("    " + numberOfNickels + " nickels");
        System.out.println("    " + numberOfPennies + " pennies");
    }
}
```

### Sample Execution
```
Enter an amount, for example, 11.56: 11.56
Your amount 11.56 consists of
    11 dollars
    2 quarters
    0 dimes
    1 nickels
    1 pennies
```

### Program Trace

| Line | amount | remainingAmount | dollars | quarters | dimes | nickels | pennies |
|------|--------|----------------|---------|----------|-------|---------|---------|
| 11   | 11.56  |                |         |          |       |         |         |
| 13   | 11.56  | 1156           |         |          |       |         |         |
| 16   | 11.56  | 1156           | 11      |          |       |         |         |
| 17   | 11.56  | 56             | 11      |          |       |         |         |
| 20   | 11.56  | 56             | 11      | 2        |       |         |         |
| 21   | 11.56  | 6              | 11      | 2        |       |         |         |
| 24   | 11.56  | 6              | 11      | 2        | 0     |         |         |
| 25   | 11.56  | 6              | 11      | 2        | 0     |         |         |
| 28   | 11.56  | 6              | 11      | 2        | 0     | 1       |         |
| 29   | 11.56  | 1              | 11      | 2        | 0     | 1       |         |
| 32   | 11.56  | 1              | 11      | 2        | 0     | 1       | 1       |

### Key Programming Concepts

#### Division and Remainder Pattern
```java
// Extract the largest unit
int units = total / unitValue;
// Get what's left over
total = total % unitValue;
```

#### Variable Reuse Strategy
- Use `remainingAmount` to track the changing remainder
- Original `amount` stays unchanged for final display
- More efficient than creating multiple variables

### Precision Problem
**Issue**: Floating-point arithmetic can cause precision errors.

**Example**:
```java
double amount = 10.03;
int cents = (int)(amount * 100);  // May result in 1002 instead of 1003!
```

**Cause**: `10.03 * 100` might equal `1002.9999999999999`

**Solution**: Enter amount as integer cents (see Exercise 2.22)

### Check Point 2.33
**Question**: Show output with input 1.99

**Solution**:
```
1.99 * 100 = 199 cents
199 ÷ 100 = 1 dollar, remainder 99
99 ÷ 25 = 3 quarters, remainder 24
24 ÷ 10 = 2 dimes, remainder 4
4 ÷ 5 = 0 nickels, remainder 4
4 pennies remain
```

**Output**:
```
Your amount 1.99 consists of
    1 dollars
    3 quarters
    2 dimes
    0 nickels
    4 pennies
```

---

## 2.18 Common Errors and Pitfalls

### Common Error 1: Undeclared/Uninitialized Variables

#### Undeclared Variables
```java
double interestRate = 0.05;
double interest = interestrate * 45;  // ERROR: 'interestrate' not declared
```
**Problem**: Java is case-sensitive. `interestRate` ≠ `interestrate`

#### Uninitialized Variables
```java
double interestRate;
double interest = interestRate * 45;  // ERROR: interestRate not initialized
```
**Problem**: Variable declared but never assigned a value.

#### Unused Variables
```java
double interestRate = 0.05;
double taxRate = 0.05;           // WARNING: unused variable
double interest = interestRate * 45;
```
**Problem**: `taxRate` is declared but never used (potential logic error).

### Common Error 2: Integer Overflow

#### What is Overflow?
When a calculation result exceeds the storage capacity of a data type.

#### Examples
```java
int value = 2147483647 + 1;      // Overflow! Result: -2147483648
int value = -2147483648 - 1;     // Overflow! Result: 2147483647
```

#### Why This Happens
- `int` range: -2,147,483,648 to 2,147,483,647
- Values wrap around when limits are exceeded
- Java doesn't warn about overflow

#### Prevention
- Use `long` for large integer calculations
- Be aware of maximum values in calculations
- Consider using `BigInteger` for very large numbers

### Common Error 3: Round-off Errors

#### Cause
Floating-point numbers cannot be stored with complete precision.

#### Examples
```java
System.out.println(1.0 - 0.1 - 0.1 - 0.1 - 0.1 - 0.1);
// Output: 0.5000000000000001 (not 0.5)

System.out.println(1.0 - 0.9);
// Output: 0.09999999999999998 (not 0.1)
```

#### Why This Happens
- Computers use binary representation for decimal numbers
- Some decimal numbers cannot be exactly represented in binary
- Accumulated errors from multiple operations

#### Solutions
- Use integers when exact precision is needed
- Round results when displaying
- Use `BigDecimal` for financial calculations requiring exact precision

### Common Error 4: Unintended Integer Division

#### The Problem
Using `/` operator with two integers performs integer division (truncates result).

#### Examples
```java
int number1 = 1, number2 = 2;
double average = (number1 + number2) / 2;  // Result: 1.0 (not 1.5)
```

#### Why This Happens
- `(1 + 2) / 2` = `3 / 2` = `1` (integer division)
- Result assigned to `double` variable, but damage already done

#### Solutions
```java
// Method 1: Make one operand floating-point
double average = (number1 + number2) / 2.0;

// Method 2: Cast to double
double average = (double)(number1 + number2) / 2;

// Method 3: Cast variables
double average = ((double)number1 + number2) / 2;
```

### Common Pitfall 1: Redundant Input Objects

#### The Problem
Creating multiple Scanner objects unnecessarily.

#### Bad Example
```java
Scanner input = new Scanner(System.in);
System.out.print("Enter an integer: ");
int v1 = input.nextInt();

Scanner input1 = new Scanner(System.in);    // UNNECESSARY!
System.out.print("Enter a double value: ");
double v2 = input1.nextDouble();
```

#### Why It's Bad
- Inefficient (creates extra objects)
- May cause subtle input reading errors
- Wastes memory

#### Good Solution
```java
Scanner input = new Scanner(System.in);
System.out.print("Enter an integer: ");
int v1 = input.nextInt();

System.out.print("Enter a double value: ");
double v2 = input.nextDouble();    // Reuse same Scanner
```

### Prevention Strategies

#### For Variables
1. Always initialize variables before use
2. Use meaningful variable names
3. Remove unused variables
4. Use IDE warnings to catch issues

#### For Numeric Errors
1. Choose appropriate data types for expected ranges
2. Be aware of integer division vs floating-point division
3. Use explicit casting when needed
4. Test with boundary values

#### For Input
1. Reuse Scanner objects
2. Validate input ranges when possible
3. Handle potential input errors gracefully

### Check Points 2.34-2.37

**2.34**: Can you redeclare a variable as different type?
**Answer**: No, once declared, a variable's type cannot be changed in the same scope.

**2.35**: What is integer overflow? Can floating-point operations cause overflow?
**Answer**: Integer overflow occurs when a calculation exceeds the data type's range. Yes, floating-point operations can also overflow (result becomes infinity).

**2.36**: Will overflow cause a runtime error?
**Answer**: No, Java continues execution but gives incorrect results.

**2.37**: What is round-off error? Do integer/floating-point operations cause them?
**Answer**: Round-off error is the difference between calculated and exact values. Integer operations don't cause round-off errors (they're exact), but floating-point operations do.

---

## Key Terms Summary

| Term | Definition |
|------|------------|
| **Algorithm** | Step-by-step procedure for solving a problem |
| **Assignment operator (=)** | Operator that assigns a value to a variable |
| **Assignment statement** | Statement that assigns a value to a variable |
| **Casting** | Explicit conversion from one data type to another |
| **Constant** | Identifier that represents a permanent value |
| **Data type** | Classification that specifies what kind of value a variable can hold |
| **Expression** | Combination of variables, operators, and values that evaluates to a single value |
| **Identifier** | Name used to identify elements like variables, methods, classes |
| **Increment operator (++)** | Operator that increases a variable's value by 1 |
| **Decrement operator (--)** | Operator that decreases a variable's value by 1 |
| **Literal** | Constant value that appears directly in program source code |
| **Overflow** | Condition when a value exceeds the storage capacity of its data type |
| **Primitive data type** | Basic data type built into Java (byte, short, int, long, float, double, char, boolean) |
| **Pseudocode** | Algorithm description using mixture of natural language and programming code |
| **Scope** | Part of program where a variable can be referenced |
| **Underflow** | Condition when a floating-point value is too small to be represented |
| **UNIX epoch** | Midnight, January 1, 1970 GMT - starting point for system time |
| **Variable** | Named memory location that stores a value |
| **Widening** | Automatic conversion from smaller to larger data type range |
| **Narrowing** | Explicit conversion from larger to smaller data type range |

---

## Programming Exercises

### Sections 2.2-2.12

#### **Exercise 2.1**: Convert Celsius to Fahrenheit
**Problem**: Write a program that converts Celsius to Fahrenheit using: `fahrenheit = (9 / 5) * celsius + 32`

**Solution**:
```java
import java.util.Scanner;

public class CelsiusToFahrenheit {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a degree in Celsius: ");
        double celsius = input.nextDouble();
        
        double fahrenheit = (9.0 / 5) * celsius + 32;
        
        System.out.println(celsius + " Celsius is " + fahrenheit + " Fahrenheit");
    }
}
```

**Key Points**:
- Use `9.0 / 5` instead of `9 / 5` to avoid integer division
- Formula: F = (9/5) × C + 32

#### **Exercise 2.2**: Compute Volume of a Cylinder
**Problem**: Calculate area and volume of a cylinder using:
- `area = radius * radius * π`
- `volume = area * length`

**Solution**:
```java
import java.util.Scanner;

public class ComputeCylinderVolume {
    public static void main(String[] args) {
        final double PI = 3.14159;
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter the radius and length of a cylinder: ");
        double radius = input.nextDouble();
        double length = input.nextDouble();
        
        double area = radius * radius * PI;
        double volume = area * length;
        
        System.out.println("The area is " + area);
        System.out.println("The volume is " + volume);
    }
}
```

#### **Exercise 2.3**: Convert Feet to Meters
**Problem**: Convert feet to meters using: 1 foot = 0.305 meters

**Solution**:
```java
import java.util.Scanner;

public class FeetToMeters {
    public static void main(String[] args) {
        final double METERS_PER_FOOT = 0.305;
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a value for feet: ");
        double feet = input.nextDouble();
        
        double meters = feet * METERS_PER_FOOT;
        
        System.out.println(feet + " feet is " + meters + " meters");
    }
}
```

#### **Exercise 2.4**: Convert Pounds to Kilograms
**Problem**: Convert pounds to kilograms using: 1 pound = 0.454 kilograms

**Solution**:
```java
import java.util.Scanner;

public class PoundsToKilograms {
    public static void main(String[] args) {
        final double KILOGRAMS_PER_POUND = 0.454;
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a number in pounds: ");
        double pounds = input.nextDouble();
        
        double kilograms = pounds * KILOGRAMS_PER_POUND;
        
        System.out.println(pounds + " pounds is " + kilograms + " kilograms");
    }
}
```

#### **Exercise 2.5**: Calculate Tips (Financial Application)
**Problem**: Calculate gratuity and total from subtotal and tip rate

**Solution**:
```java
import java.util.Scanner;

public class CalculateTip {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter the subtotal and a gratuity rate: ");
        double subtotal = input.nextDouble();
        double gratuityRate = input.nextDouble();
        
        double gratuity = subtotal * (gratuityRate / 100);
        double total = subtotal + gratuity;
        
        System.out.println("The gratuity is $" + gratuity + 
                          " and total is $" + total);
    }
}
```

#### **Exercise 2.6**: Sum Digits in an Integer
**Problem**: Add all digits in an integer between 0 and 1000

**Hint**: Use `%` to extract digits and `/` to remove extracted digit

**Solution**:
```java
import java.util.Scanner;

public class SumDigits {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a number between 0 and 1000: ");
        int number = input.nextInt();
        
        // Extract digits using % and /
        int digit1 = number % 10;           // Units digit
        number = number / 10;
        int digit2 = number % 10;           // Tens digit  
        number = number / 10;
        int digit3 = number % 10;           // Hundreds digit
        
        int sum = digit1 + digit2 + digit3;
        
        System.out.println("The sum of the digits is " + sum);
    }
}
```

**How it works** (example: 932):
- `932 % 10 = 2` (units), `932 / 10 = 93`
- `93 % 10 = 3` (tens), `93 / 10 = 9` 
- `9 % 10 = 9` (hundreds)
- Sum: 2 + 3 + 9 = 14

#### **Exercise 2.7**: Find Number of Years
**Problem**: Convert minutes to years and days (assume 365 days per year)

**Solution**:
```java
import java.util.Scanner;

public class MinutesToYears {
    public static void main(String[] args) {
        final int MINUTES_PER_HOUR = 60;
        final int HOURS_PER_DAY = 24;
        final int DAYS_PER_YEAR = 365;
        final int MINUTES_PER_DAY = MINUTES_PER_HOUR * HOURS_PER_DAY;
        final int MINUTES_PER_YEAR = MINUTES_PER_DAY * DAYS_PER_YEAR;
        
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter the number of minutes: ");
        long minutes = input.nextLong();
        
        long years = minutes / MINUTES_PER_YEAR;
        long remainingMinutes = minutes % MINUTES_PER_YEAR;
        long days = remainingMinutes / MINUTES_PER_DAY;
        
        System.out.println(minutes + " minutes is approximately " + 
                          years + " years and " + days + " days");
    }
}
```

#### **Exercise 2.8**: Current Time with Time Zone
**Problem**: Modify ShowCurrentTime to accept time zone offset

**Solution**:
```java
import java.util.Scanner;

public class ShowCurrentTimeWithTimeZone {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter the time zone offset to GMT: ");
        int timeZoneOffset = input.nextInt();
        
        // Get current time
        long totalMilliseconds = System.currentTimeMillis();
        long totalSeconds = totalMilliseconds / 1000;
        long currentSecond = totalSeconds % 60;
        long totalMinutes = totalSeconds / 60;
        long currentMinute = totalMinutes % 60;
        long totalHours = totalMinutes / 60;
        long currentHour = (totalHours + timeZoneOffset) % 24;
        
        // Handle negative hours
        if (currentHour < 0) {
            currentHour += 24;
        }
        
        System.out.println("The current time is " + currentHour + ":" +
                          currentMinute + ":" + currentSecond);
    }
}
```

### Advanced Exercises (Sections 2.13-2.17)

#### **Exercise 2.9**: Physics - Acceleration
**Problem**: Calculate average acceleration using: `a = (v1 - v0) / t`

**Solution**:
```java
import java.util.Scanner;

public class ComputeAcceleration {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter v0, v1, and t: ");
        double v0 = input.nextDouble();
        double v1 = input.nextDouble();
        double t = input.nextDouble();
        
        double acceleration = (v1 - v0) / t;
        
        System.out.println("The average acceleration is " + acceleration);
    }
}
```

#### **Exercise 2.10**: Science - Calculating Energy
**Problem**: Calculate energy to heat water using: `Q = M * (finalTemp - initialTemp) * 4184`

**Solution**:
```java
import java.util.Scanner;

public class ComputeEnergy {
    public static void main(String[] args) {
        final double ENERGY_PER_KG_CELSIUS = 4184;
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter the amount of water in kilograms: ");
        double mass = input.nextDouble();
        
        System.out.print("Enter the initial temperature: ");
        double initialTemp = input.nextDouble();
        
        System.out.print("Enter the final temperature: ");
        double finalTemp = input.nextDouble();
        
        double energy = mass * (finalTemp - initialTemp) * ENERGY_PER_KG_CELSIUS;
        
        System.out.println("The energy needed is " + energy);
    }
}
```

#### **Exercise 2.11**: Population Projection
**Problem**: Project population growth over specified years

**Solution**:
```java
import java.util.Scanner;

public class PopulationProjection {
    public static void main(String[] args) {
        final int CURRENT_POPULATION = 312032486;
        final int SECONDS_PER_YEAR = 365 * 24 * 60 * 60;
        final int BIRTH_RATE = 7;    // one birth every 7 seconds
        final int DEATH_RATE = 13;   // one death every 13 seconds
        final int IMMIGRANT_RATE = 45; // one immigrant every 45 seconds
        
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter the number of years: ");
        int years = input.nextInt();
        
        // Calculate population changes per year
        int birthsPerYear = SECONDS_PER_YEAR / BIRTH_RATE;
        int deathsPerYear = SECONDS_PER_YEAR / DEATH_RATE;
        int immigrantsPerYear = SECONDS_PER_YEAR / IMMIGRANT_RATE;
        
        int netChangePerYear = birthsPerYear - deathsPerYear + immigrantsPerYear;
        
        int futurePopulation = CURRENT_POPULATION + (years * netChangePerYear);
        
        System.out.println("The population in " + years + 
                          " years is " + futurePopulation);
    }
}
```

#### **Exercise 2.12**: Physics - Runway Length
**Problem**: Calculate minimum runway length using: `length = v² / (2a)`

**Solution**:
```java
import java.util.Scanner;

public class ComputeRunwayLength {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter speed and acceleration: ");
        double speed = input.nextDouble();
        double acceleration = input.nextDouble();
        
        double length = Math.pow(speed, 2) / (2 * acceleration);
        
        System.out.println("The minimum runway length for this airplane is " + 
                          length);
    }
}
```

#### **Exercise 2.13**: Financial Application - Compound Value
**Problem**: Calculate savings account value after 6 months with monthly deposits

**Mathematical progression**:
- Month 1: `100 * (1 + 0.00417) = 100.417`
- Month 2: `(100 + 100.417) * (1 + 0.00417) = 201.252`
- And so on...

**Solution**:
```java
import java.util.Scanner;

public class ComputeSavings {
    public static void main(String[] args) {
        final double MONTHLY_INTEREST_RATE = 0.05 / 12; // 5% annual = 0.00417 monthly
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter the monthly saving amount: ");
        double monthlySaving = input.nextDouble();
        
        // Calculate account value after each month
        double accountValue = 0;
        
        // Month 1
        accountValue = (accountValue + monthlySaving) * (1 + MONTHLY_INTEREST_RATE);
        
        // Month 2  
        accountValue = (accountValue + monthlySaving) * (1 + MONTHLY_INTEREST_RATE);
        
        // Month 3
        accountValue = (accountValue + monthlySaving) * (1 + MONTHLY_INTEREST_RATE);
        
        // Month 4
        accountValue = (accountValue + monthlySaving) * (1 + MONTHLY_INTEREST_RATE);
        
        // Month 5
        accountValue = (accountValue + monthlySaving) * (1 + MONTHLY_INTEREST_RATE);
        
        // Month 6
        accountValue = (accountValue + monthlySaving) * (1 + MONTHLY_INTEREST_RATE);
        
        System.out.println("After the sixth month, the account value is $" + 
                          (int)(accountValue * 100) / 100.0);
    }
}
```

#### **Exercise 2.14**: Health Application - Computing BMI
**Problem**: Calculate Body Mass Index using weight in pounds and height in inches
- 1 pound = 0.45359237 kilograms
- 1 inch = 0.0254 meters
- BMI = weight(kg) / height(m)²

**Solution**:
```java
import java.util.Scanner;

public class ComputeBMI {
    public static void main(String[] args) {
        final double KILOGRAMS_PER_POUND = 0.45359237;
        final double METERS_PER_INCH = 0.0254;
        
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter weight in pounds: ");
        double weightInPounds = input.nextDouble();
        
        System.out.print("Enter height in inches: ");
        double heightInInches = input.nextDouble();
        
        // Convert to metric units
        double weightInKilograms = weightInPounds * KILOGRAMS_PER_POUND;
        double heightInMeters = heightInInches * METERS_PER_INCH;
        
        // Calculate BMI
        double bmi = weightInKilograms / Math.pow(heightInMeters, 2);
        
        System.out.println("BMI is " + bmi);
    }
}
```

#### **Exercise 2.15**: Geometry - Distance Between Two Points
**Problem**: Calculate distance using: `distance = √[(x₂-x₁)² + (y₂-y₁)²]`

**Solution**:
```java
import java.util.Scanner;

public class ComputeDistance {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter x1 and y1: ");
        double x1 = input.nextDouble();
        double y1 = input.nextDouble();
        
        System.out.print("Enter x2 and y2: ");
        double x2 = input.nextDouble();
        double y2 = input.nextDouble();
        
        double distance = Math.pow(Math.pow(x2 - x1, 2) + Math.pow(y2 - y1, 2), 0.5);
        
        System.out.println("The distance between the two points is " + distance);
    }
}
```

---

## Chapter Summary

This comprehensive guide covered all essential concepts from Chapter 2: Elementary Programming. Key achievements include:

### **Fundamental Concepts Mastered**:
1. **Program Structure**: Understanding basic Java program anatomy
2. **Variables and Data Types**: Working with different numeric types
3. **Input/Output**: Using Scanner for user input and System.out for display
4. **Mathematical Operations**: Arithmetic operators and operator precedence
5. **Constants**: Using final keyword for unchanging values
6. **Type Conversions**: Automatic widening and explicit casting
7. **Software Development Process**: Requirements → Analysis → Design → Implementation → Testing

### **Problem-Solving Skills Developed**:
- Breaking complex problems into smaller steps
- Translating mathematical formulas into Java code
- Using appropriate data types for different scenarios
- Handling user input and formatting output
- Debugging common programming errors

### **Programming Best Practices Learned**:
- Use descriptive variable names
- Follow Java naming conventions
- Initialize variables before use
- Choose appropriate data types
- Use constants for unchanging values
- Format output for readability
- Test programs thoroughly

This chapter provided the foundation for all future Java programming concepts, establishing essential skills in problem-solving, coding, and debugging that will be built upon in subsequent chapters.
