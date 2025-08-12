# Complete Java Methods Study Guide - Chapter 6

## Table of Contents
1. [Introduction to Methods](#1-introduction-to-methods)
2. [Defining a Method](#2-defining-a-method)
3. [Calling a Method](#3-calling-a-method)
4. [void Method Example](#4-void-method-example)
5. [Passing Arguments by Values](#5-passing-arguments-by-values)
6. [Modularizing Code](#6-modularizing-code)
7. [Case Study: Converting Hexadecimals to Decimals](#7-case-study-converting-hexadecimals-to-decimals)
8. [Overloading Methods](#8-overloading-methods)
9. [The Scope of Variables](#9-the-scope-of-variables)
10. [Case Study: Generating Random Characters](#10-case-study-generating-random-characters)
11. [Method Abstraction and Stepwise Refinement](#11-method-abstraction-and-stepwise-refinement)
12. [Programming Exercises](#12-programming-exercises)

---

## 1. Introduction to Methods

### Why Methods?
Methods solve the problem of code repetition and make programs more organized and maintainable.

### Problem Without Methods
Consider calculating sums for different ranges:
```java
// Repetitive code without methods
int sum = 0;
for (int i = 1; i <= 10; i++)
    sum += i;
System.out.println("Sum from 1 to 10 is " + sum);

sum = 0;
for (int i = 20; i <= 37; i++)
    sum += i;
System.out.println("Sum from 20 to 37 is " + sum);

sum = 0;
for (int i = 35; i <= 49; i++)
    sum += i;
System.out.println("Sum from 35 to 49 is " + sum);
```

### Solution With Methods
```java
public static int sum(int i1, int i2) {
    int result = 0;
    for (int i = i1; i <= i2; i++)
        result += i;
    return result;
}

public static void main(String[] args) {
    System.out.println("Sum from 1 to 10 is " + sum(1, 10));
    System.out.println("Sum from 20 to 37 is " + sum(20, 37));
    System.out.println("Sum from 35 to 49 is " + sum(35, 49));
}
```

### Benefits of Using Methods
1. **Code Reusability**: Write once, use multiple times
2. **Modularity**: Break complex problems into smaller parts
3. **Easier Debugging**: Isolate errors to specific methods
4. **Better Organization**: Clear structure and readable code
5. **Team Collaboration**: Different developers can work on different methods

---

## 2. Defining a Method

### Method Definition Syntax
```java
modifier returnValueType methodName(list of parameters) {
    // Method body;
}
```

### Method Components Explained

#### Example: Finding Maximum of Two Numbers
```java
public static int max(int num1, int num2) {
    int result;
    if (num1 > num2)
        result = num1;
    else
        result = num2;
    return result;
}
```

#### Component Breakdown:
- **Modifier**: `public static`
  - `public`: Can be accessed from other classes
  - `static`: Belongs to the class, not to any instance
- **Return Value Type**: `int` - specifies what type of data the method returns
- **Method Name**: `max` - identifier for the method
- **Parameters**: `int num1, int num2` - input variables
- **Method Body**: The implementation code
- **Return Statement**: `return result;` - returns the computed value

### Key Terminology
- **Formal Parameters**: Variables in method header (num1, num2)
- **Actual Parameters/Arguments**: Values passed when calling method (3, 4)
- **Parameter List**: Type, order, and number of parameters
- **Method Signature**: Method name + parameter list
- **Value-Returning Method**: Returns a value (has return type)
- **Void Method**: Doesn't return a value (return type is void)

### Important Notes
1. Each parameter must be declared separately: `max(int num1, int num2)` ✓
2. Wrong way: `max(int num1, num2)` ✗
3. A return statement is required for value-returning methods
4. Parameters are optional - a method can have no parameters

---

## 3. Calling a Method

### How Method Calls Work
When you call a method, program control transfers to that method. When the method finishes, control returns to the caller.

### Complete Example: TestMax.java
```java
public class TestMax {
    /** Main method */
    public static void main(String[] args) {
        int i = 5;
        int j = 2;
        int k = max(i, j);  // Method call
        System.out.println("The maximum of " + i + " and " + j + " is " + k);
    }

    /** Return the max of two numbers */
    public static int max(int num1, int num2) {
        int result;
        if (num1 > num2)
            result = num1;
        else
            result = num2;
        return result;
    }
}
```

### Two Ways to Call Methods

#### 1. Value-Returning Methods
```java
// Assign return value to variable
int larger = max(3, 4);

// Use in expression
System.out.println(max(3, 4));
```

#### 2. Void Methods
```java
// Must be called as a statement
System.out.println("Welcome to Java!");
```

### Call Stack and Activation Records
- **Call Stack**: Memory area storing method information
- **Activation Record**: Contains parameters and local variables for each method call
- **LIFO (Last In, First Out)**: Most recently called method is removed first

#### Call Stack Example:
1. Main method starts → Main's activation record created
2. max method called → max's activation record added on top
3. max method finishes → max's activation record removed
4. Control returns to main → Main continues execution

### Memory Management During Method Calls
```
Stack State During Execution:
(a) Main method starts:     [main: i=5, j=2, k=undefined]
(b) max method called:      [main: i=5, j=2, k=undefined]
                           [max: num1=5, num2=2, result=undefined]
(c) max method executing:   [main: i=5, j=2, k=undefined]
                           [max: num1=5, num2=2, result=5]
(d) max method returns:     [main: i=5, j=2, k=5]
```

---

## 4. void Method Example

### Understanding void Methods
void methods perform operations but don't return values.

### Example 1: PrintGrade Method
```java
public class TestVoidMethod {
    public static void main(String[] args) {
        System.out.print("The grade is ");
        printGrade(78.5);  // void method call
        
        System.out.print("The grade is ");
        printGrade(59.5);
    }

    public static void printGrade(double score) {
        if (score >= 90.0) {
            System.out.println('A');
        }
        else if (score >= 80.0) {
            System.out.println('B');
        }
        else if (score >= 70.0) {
            System.out.println('C');
        }
        else if (score >= 60.0) {
            System.out.println('D');
        }
        else {
            System.out.println('F');
        }
    }
}
```

### Comparison: void vs Value-Returning Method

#### void Method (printGrade)
- **Purpose**: Prints grade directly
- **Call**: `printGrade(78.5);` (statement)
- **Return**: Nothing

#### Value-Returning Method (getGrade)
```java
public static char getGrade(double score) {
    if (score >= 90.0)
        return 'A';
    else if (score >= 80.0)
        return 'B';
    else if (score >= 70.0)
        return 'C';
    else if (score >= 60.0)
        return 'D';
    else
        return 'F';
}

// Usage in main method
System.out.print("The grade is " + getGrade(78.5));
```

### return Statement in void Methods
```java
public static void printGrade(double score) {
    if (score < 0 || score > 100) {
        System.out.println("Invalid score");
        return;  // Early termination
    }
    
    // Rest of the method...
    if (score >= 90.0) {
        System.out.println('A');
    }
    // ... other conditions
}
```

**Key Points:**
- `return;` can terminate a void method early
- No value is returned with the return statement
- Useful for input validation and error handling

---

## 5. Passing Arguments by Values

### Understanding Pass-by-Value
In Java, all arguments are passed by value. This means:
- The **value** of the argument is copied to the parameter
- Changes to the parameter don't affect the original variable
- Each parameter has its own memory space

### Example 1: Simple Increment
```java
public class Increment {
    public static void main(String[] args) {
        int x = 1;
        System.out.println("Before the call, x is " + x);  // x = 1
        increment(x);
        System.out.println("After the call, x is " + x);   // x = 1 (unchanged!)
    }

    public static void increment(int n) {
        n++;  // Only the parameter n is incremented
        System.out.println("n inside the method is " + n);  // n = 2
    }
}
```

**Output:**
```
Before the call, x is 1
n inside the method is 2
After the call, x is 1
```

### Example 2: Attempted Swap (Doesn't Work!)
```java
public class TestPassByValue {
    public static void main(String[] args) {
        int num1 = 1;
        int num2 = 2;
        
        System.out.println("Before swapping: num1=" + num1 + ", num2=" + num2);
        swap(num1, num2);
        System.out.println("After swapping: num1=" + num1 + ", num2=" + num2);
    }

    public static void swap(int n1, int n2) {
        System.out.println("\tInside swap method");
        System.out.println("\t\tBefore: n1=" + n1 + ", n2=" + n2);
        
        // Swap the parameters (not the original variables!)
        int temp = n1;
        n1 = n2;
        n2 = temp;
        
        System.out.println("\t\tAfter: n1=" + n1 + ", n2=" + n2);
    }
}
```

**Output:**
```
Before swapping: num1=1, num2=2
    Inside swap method
        Before: n1=1, n2=2
        After: n1=2, n2=1
After swapping: num1=1, num2=2
```

### Memory Visualization
```
Original Variables:     Parameters (Separate Memory):
num1 = 1               n1 = 1 (copy of num1's value)
num2 = 2               n2 = 2 (copy of num2's value)

After swap operation:
num1 = 1 (unchanged)   n1 = 2 (swapped)
num2 = 2 (unchanged)   n2 = 1 (swapped)
```

### Important Rules
1. **Parameter Order Association**: Arguments must match parameters in order, number, and compatible type
2. **Compatible Types**: Can pass int to double parameter (automatic conversion)
3. **Variable Names**: Parameter names can be same as argument variable names (still separate memory)

---

## 6. Modularizing Code

### Benefits of Modularization
1. **Isolation**: Separate concerns and logic
2. **Debugging**: Narrow scope of error detection
3. **Reusability**: Use methods in multiple programs
4. **Clarity**: Easier to read and understand

### Example 1: Greatest Common Divisor
```java
import java.util.Scanner;

public class GreatestCommonDivisorMethod {
    /** Main method */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter first integer: ");
        int n1 = input.nextInt();
        System.out.print("Enter second integer: ");
        int n2 = input.nextInt();
        
        System.out.println("The greatest common divisor for " + n1 +
                          " and " + n2 + " is " + gcd(n1, n2));
    }

    /** Return the gcd of two integers */
    public static int gcd(int n1, int n2) {
        int gcd = 1; // Initial gcd is 1
        int k = 2;   // Possible gcd
        
        while (k <= n1 && k <= n2) {
            if (n1 % k == 0 && n2 % k == 0)
                gcd = k; // Update gcd
            k++;
        }
        
        return gcd;
    }
}
```

### Example 2: Prime Numbers (Modularized)
```java
public class PrimeNumberMethod {
    public static void main(String[] args) {
        System.out.println("The first 50 prime numbers are \n");
        printPrimeNumbers(50);
    }

    public static void printPrimeNumbers(int numberOfPrimes) {
        final int NUMBER_OF_PRIMES_PER_LINE = 10;
        int count = 0;
        int number = 2;
        
        while (count < numberOfPrimes) {
            if (isPrime(number)) {
                count++;
                
                if (count % NUMBER_OF_PRIMES_PER_LINE == 0) {
                    System.out.printf("%-5s\n", number);
                }
                else {
                    System.out.printf("%-5s", number);
                }
            }
            number++;
        }
    }

    /** Check whether number is prime */
    public static boolean isPrime(int number) {
        for (int divisor = 2; divisor <= number / 2; divisor++) {
            if (number % divisor == 0) {
                return false; // Not prime
            }
        }
        return true; // Is prime
    }
}
```

### Modularization Advantages
1. **Large Problem → Smaller Subproblems**: Easier to solve
2. **Method Reuse**: `isPrime` can be used by other programs
3. **Independent Development**: Each method can be developed separately
4. **Team Collaboration**: Different programmers can work on different methods

---

## 7. Case Study: Converting Hexadecimals to Decimals

### Problem Understanding
Convert hexadecimal numbers to decimal using the formula:
```
hnhn-1hn-2...h2h1h0 = hn×16^n + hn-1×16^(n-1) + ... + h1×16^1 + h0×16^0
```

### Horner's Algorithm
More efficient approach:
```
Result = (...((hn×16 + hn-1)×16 + hn-2)×16 + ... + h1)×16 + h0
```

### Complete Implementation
```java
import java.util.Scanner;

public class Hex2Dec {
    /** Main method */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a hex number: ");
        String hex = input.nextLine();
        
        System.out.println("The decimal value for hex number " +
                          hex + " is " + hexToDecimal(hex.toUpperCase()));
    }

    /** Convert hex string to decimal */
    public static int hexToDecimal(String hex) {
        int decimalValue = 0;
        for (int i = 0; i < hex.length(); i++) {
            char hexChar = hex.charAt(i);
            decimalValue = decimalValue * 16 + hexCharToDecimal(hexChar);
        }
        return decimalValue;
    }

    /** Convert single hex character to decimal */
    public static int hexCharToDecimal(char ch) {
        if (ch >= 'A' && ch <= 'F')
            return 10 + ch - 'A';  // A=10, B=11, ..., F=15
        else // ch is '0', '1', ..., or '9'
            return ch - '0';       // '0'=0, '1'=1, ..., '9'=9
    }
}
```

### Algorithm Trace for "AB8C"
```
i | hexChar | hexCharToDecimal | decimalValue
--|---------|------------------|-------------
  |         |                  | 0 (initial)
0 | A       | 10               | 0×16 + 10 = 10
1 | B       | 11               | 10×16 + 11 = 171
2 | 8       | 8                | 171×16 + 8 = 2744
3 | C       | 12               | 2744×16 + 12 = 43916
```

### Key Concepts
1. **Character Arithmetic**: `'5' - '0' = 5`, `'A' - 'A' = 0`
2. **Case Handling**: Convert to uppercase for consistency
3. **Modular Design**: Separate hex-to-decimal conversion from character conversion

---

## 8. Overloading Methods

### What is Method Overloading?
Multiple methods with the **same name** but **different parameter lists** in the same class.

### Complete Example: Multiple max Methods
```java
public class TestMethodOverloading {
    /** Main method */
    public static void main(String[] args) {
        // Invoke max with int parameters
        System.out.println("The maximum of 3 and 4 is " + max(3, 4));
        
        // Invoke max with double parameters
        System.out.println("The maximum of 3.0 and 5.4 is " + max(3.0, 5.4));
        
        // Invoke max with three double parameters
        System.out.println("The maximum of 3.0, 5.4, and 10.14 is " + 
                          max(3.0, 5.4, 10.14));
    }

    /** Return the max of two int values */
    public static int max(int num1, int num2) {
        if (num1 > num2)
            return num1;
        else
            return num2;
    }

    /** Find the max of two double values */
    public static double max(double num1, double num2) {
        if (num1 > num2)
            return num1;
        else
            return num2;
    }

    /** Return the max of three double values */
    public static double max(double num1, double num2, double num3) {
        return max(max(num1, num2), num3);  // Calling other overloaded methods
    }
}
```

### Method Resolution Rules
1. **Exact Match**: `max(3, 4)` calls `max(int, int)`
2. **Compatible Types**: `max(2, 2.5)` calls `max(double, double)` (int promoted to double)
3. **Best Match**: Compiler chooses the most specific match

### Overloading Rules
- ✓ **Different parameter lists** (number, type, or order)
- ✗ **Cannot overload based on return type only**
- ✗ **Cannot overload based on modifiers only**

### Ambiguous Invocation Example
```java
// This causes compilation error!
public class AmbiguousOverloading {
    public static void main(String[] args) {
        System.out.println(max(1, 2));  // Ambiguous!
    }

    public static double max(int num1, double num2) {
        // implementation
    }
    
    public static double max(double num1, int num2) {
        // implementation
    }
}
```
**Problem**: `max(1, 2)` could match either method - compiler can't decide!

---

## 9. The Scope of Variables

### Variable Scope Rules
The **scope** of a variable is the part of the program where the variable can be accessed.

### Local Variables
- **Definition**: Variables declared inside a method
- **Scope**: From declaration to end of containing block
- **Requirement**: Must be declared and initialized before use

### Scope Examples

#### Example 1: Method Parameter Scope
```java
public static void method1() {
    // Scope of parameter covers entire method
    for (int i = 1; i < 10; i++) {  // i's scope: entire loop
        int j;  // j's scope: from here to end of loop body
        // Both i and j can be used here
    }
    // i and j are not accessible here
}
```

#### Example 2: Valid Variable Declarations
```java
public static void method1() {
    int x = 1;
    int y = 1;
    
    // Valid: i declared in non-nested blocks
    for (int i = 1; i < 10; i++) {
        x += i;
    }
    
    for (int i = 1; i < 10; i++) {  // Different i, different scope
        y += i;
    }
}
```

#### Example 3: Invalid Nested Declaration
```java
public static void method2() {
    int i = 1;
    int sum = 0;
    
    for (int i = 1; i < 10; i++)  // ERROR! i already declared
        sum += i;
}
```

### Common Scope Errors

#### Error 1: Using Variable Outside Scope
```java
// WRONG!
for (int i = 0; i < 10; i++) {
    // i is accessible here
}
System.out.println(i);  // ERROR! i not accessible outside loop
```

#### Error 2: Variable Declaration Order
```java
public static void method() {
    System.out.println(x);  // ERROR! x not yet declared
    int x = 5;
}
```

### Best Practices
1. **Declare variables close to where they're used**
2. **Use meaningful variable names**
3. **Avoid variable name conflicts**
4. **Initialize variables when declaring them**

---

## 10. Case Study: Generating Random Characters

### Character Generation Concepts
Characters are represented by Unicode values (0 to 65535).

### Random Character Generation Formulas

#### 1. Any Random Character
```java
(int)(Math.random() * 65536)  // 0 to 65535
```

#### 2. Random Character Between Two Characters
```java
(char)(ch1 + Math.random() * (ch2 - ch1 + 1))
```

#### 3. Random Lowercase Letter
```java
(char)('a' + Math.random() * ('z' - 'a' + 1))
```

### Complete RandomCharacter Class
```java
public class RandomCharacter {
    /** Generate a random character between ch1 and ch2 */
    public static char getRandomCharacter(char ch1, char ch2) {
        return (char)(ch1 + Math.random() * (ch2 - ch1 + 1));
    }

    /** Generate a random lowercase letter */
    public static char getRandomLowerCaseLetter() {
        return getRandomCharacter('a', 'z');
    }

    /** Generate a random uppercase letter */
    public static char getRandomUpperCaseLetter() {
        return getRandomCharacter('A', 'Z');
    }

    /** Generate a random digit character */
    public static char getRandomDigitCharacter() {
        return getRandomCharacter('0', '9');
    }

    /** Generate a random character */
    public static char getRandomCharacter() {
        return getRandomCharacter('\u0000', '\uFFFF');
    }
}
```

### Test Program
```java
public class TestRandomCharacter {
    /** Main method */
    public static void main(String[] args) {
        final int NUMBER_OF_CHARS = 175;
        final int CHARS_PER_LINE = 25;
        
        // Print random lowercase letters, 25 per line
        for (int i = 0; i < NUMBER_OF_CHARS; i++) {
            char ch = RandomCharacter.getRandomLowerCaseLetter();
            if ((i + 1) % CHARS_PER_LINE == 0)
                System.out.println(ch);
            else
                System.out.print(ch);
        }
    }
}
```

### Character Arithmetic Explanation
```java
// Character codes:
'0' = 48, '1' = 49, ..., '9' = 57
'A' = 65, 'B' = 66, ..., 'Z' = 90
'a' = 97, 'b' = 98, ..., 'z' = 122

// Converting character to number:
'5' - '0' = 57 - 48 = 9  // Wrong! Should be 5
'5' - '0' = 5            // Correct interpretation

// Converting letter to position:
'C' - 'A' = 67 - 65 = 2  // C is the 3rd letter (0-indexed: position 2)
```

---

## 11. Method Abstraction and Stepwise Refinement

### Method Abstraction Concept
- **Client**: Uses the method without knowing implementation details
- **Black Box**: Method implementation is hidden
- **Interface**: Method signature defines how to use the method

### Stepwise Refinement Process
**Divide and Conquer Strategy**: Break large problems into smaller, manageable subproblems.

### Case Study: Print Calendar Program

#### Problem Decomposition
```
Level 1: printCalendar (main problem)
├── readInput
└── printMonth

Level 2: printMonth
├── printMonthTitle
└── printMonthBody

Level 3: printMonthTitle
└── getMonthName

Level 3: printMonthBody
├── getStartDay
└── getNumberOfDaysInMonth

Level 4: getStartDay
└── getTotalNumberOfDays

Level 5: getTotalNumberOfDays
├── isLeapYear
└── getNumberOfDaysInMonth
```

### Implementation Approaches

#### 1. Top-Down Approach
- Start with main method
- Use **stubs** (incomplete methods) for unimplemented parts
- Gradually implement each method

#### 2. Bottom-Up Approach
- Start with lowest-level methods
- Use **drivers** (test programs) to test each method
- Build up to complete program

### Complete Calendar Program
```java
import java.util.Scanner;

public class PrintCalendar {
    /** Main method */
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter full year (e.g., 2012): ");
        int year = input.nextInt();
        
        System.out.print("Enter month as number between 1 and 12: ");
        int month = input.nextInt();
        
        printMonth(year, month);
    }

    /** Print the calendar for a month in a year */
    public static void printMonth(int year, int month) {
        printMonthTitle(year, month);
        printMonthBody(year, month);
    }

    /** Print the month title, e.g., March 2012 */
    public static void printMonthTitle(int year, int month) {
        System.out.println("  " + getMonthName(month) + " " + year);
        System.out.println("-----------------------------");
        System.out.println(" Sun Mon Tue Wed Thu Fri Sat");
    }

    /** Get the English name for the month */
    public static String getMonthName(int month) {
        String monthName = "";
        switch (month) {
            case 1: monthName = "January"; break;
            case 2: monthName = "February"; break;
            case 3: monthName = "March"; break;
            case 4: monthName = "April"; break;
            case 5: monthName = "May"; break;
            case 6: monthName = "June"; break;
            case 7: monthName = "July"; break;
            case 8: monthName = "August"; break;
            case 9: monthName = "September"; break;
            case 10: monthName = "October"; break;
            case 11: monthName = "November"; break;
            case 12: monthName = "December";
        }
        return monthName;
    }

    /** Print month body */
    public static void printMonthBody(int year, int month) {
        int startDay = getStartDay(year, month);
        int numberOfDaysInMonth = getNumberOfDaysInMonth(year, month);
        
        // Pad space before the first day of the month
        int i = 0;
        for (i = 0; i < startDay; i++)
            System.out.print("    ");

        for (i = 1; i <= numberOfDaysInMonth; i++) {
            System.out.printf("%4d", i);
            
            if ((i + startDay) % 7 == 0)
                System.out.println();
        }
        
        System.out.println();
    }

    /** Get the start day of month/1/year */
    public static int getStartDay(int year, int month) {
        final int START_DAY_FOR_JAN_1_1800 = 3;
        int totalNumberOfDays = getTotalNumberOfDays(year, month);
        return (totalNumberOfDays + START_DAY_FOR_JAN_1_1800) % 7;
    }

    /** Get the total number of days since January 1, 1800 */
    public static int getTotalNumberOfDays(int year, int month) {
        int total = 0;
        
        // Get total days from 1800 to 1/1/year
        for (int i = 1800; i < year; i++) {
            if (isLeapYear(i))
                total = total + 366;
            else
                total = total + 365;
        }
        
        // Add days from Jan to the month prior to the calendar month
        for (int i = 1; i < month; i++)
            total = total + getNumberOfDaysInMonth(year, i);
        
        return total;
    }

    /** Get the number of days in a month */
    public static int getNumberOfDaysInMonth(int year, int month) {
        if (month == 1 || month == 3 || month == 5 || month == 7 ||
            month == 8 || month == 10 || month == 12)
            return 31;

        if (month == 4 || month == 6 || month == 9 || month == 11)
            return 30;

        if (month == 2) 
            return isLeapYear(year) ? 29 : 28;

        return 0; // Invalid month
    }

    /** Determine if it is a leap year */
    public static boolean isLeapYear(int year) {
        return year % 400 == 0 || (year % 4 == 0 && year % 100 != 0);
    }
}
```

### Benefits of Stepwise Refinement
1. **Simpler Program**: Break complex logic into understandable parts
2. **Code Reusability**: Methods like `isLeapYear` can be used multiple times
3. **Easier Development**: Each method can be developed independently
4. **Better Debugging**: Errors are isolated to specific methods
5. **Team Collaboration**: Different programmers can work on different methods
6. **Incremental Testing**: Test each method as you build the program

---

## 12. Programming Exercises

### Section 6.2-6.9: Basic Method Exercises

#### Exercise 6.1: Pentagonal Numbers
**Problem**: Write a method that returns the nth pentagonal number using formula: n(3n-1)/2

```java
public class PentagonalNumbers {
    public static void main(String[] args) {
        System.out.println("First 100 pentagonal numbers:");
        
        for (int i = 1; i <= 100; i++) {
            System.out.printf("%-6d", getPentagonalNumber(i));
            if (i % 10 == 0) System.out.println();
        }
    }
    
    /** Returns the nth pentagonal number */
    public static int getPentagonalNumber(int n) {
        return n * (3 * n - 1) / 2;
    }
}
```

#### Exercise 6.2: Sum Digits in Integer
**Problem**: Write a method that computes sum of digits in an integer

```java
import java.util.Scanner;

public class SumDigits {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter an integer: ");
        long n = input.nextLong();
        
        System.out.println("Sum of digits in " + n + " is " + sumDigits(n));
    }
    
    /** Sum all digits in a long integer */
    public static int sumDigits(long n) {
        int sum = 0;
        n = Math.abs(n); // Handle negative numbers
        
        while (n > 0) {
            sum += n % 10;  // Extract last digit
            n /= 10;        // Remove last digit
        }
        
        return sum;
    }
}
```

**Algorithm Explanation**:
```
Example: sumDigits(234)
n = 234, sum = 0
n % 10 = 4, sum = 0 + 4 = 4, n = 234/10 = 23
n % 10 = 3, sum = 4 + 3 = 7, n = 23/10 = 2  
n % 10 = 2, sum = 7 + 2 = 9, n = 2/10 = 0
Return sum = 9
```

#### Exercise 6.3: Palindrome Integer
**Problem**: Check if an integer is a palindrome using a reverse method

```java
import java.util.Scanner;

public class PalindromeInteger {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter an integer: ");
        int number = input.nextInt();
        
        if (isPalindrome(number)) {
            System.out.println(number + " is a palindrome");
        } else {
            System.out.println(number + " is not a palindrome");
        }
    }
    
    /** Return the reversal of an integer */
    public static int reverse(int number) {
        int reversed = 0;
        int original = Math.abs(number); // Handle negative numbers
        
        while (original > 0) {
            reversed = reversed * 10 + original % 10;
            original /= 10;
        }
        
        return number < 0 ? -reversed : reversed;
    }
    
    /** Check if number is a palindrome */
    public static boolean isPalindrome(int number) {
        return number == reverse(number);
    }
}
```

#### Exercise 6.4: Display Integer Reversed
**Problem**: Display an integer in reverse order

```java
import java.util.Scanner;

public class DisplayReversed {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter an integer: ");
        int number = input.nextInt();
        
        System.out.print("Reversed: ");
        reverse(number);
        System.out.println();
    }
    
    /** Display an integer in reverse order */
    public static void reverse(int number) {
        if (number < 0) {
            System.out.print("-");
            number = -number;
        }
        
        while (number > 0) {
            System.out.print(number % 10);
            number /= 10;
        }
    }
}
```

#### Exercise 6.5: Sort Three Numbers
**Problem**: Display three numbers in increasing order

```java
import java.util.Scanner;

public class SortThreeNumbers {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter three numbers: ");
        double num1 = input.nextDouble();
        double num2 = input.nextDouble();
        double num3 = input.nextDouble();
        
        displaySortedNumbers(num1, num2, num3);
    }
    
    /** Display three numbers in increasing order */
    public static void displaySortedNumbers(double num1, double num2, double num3) {
        // Find minimum, maximum, and middle values
        double min, mid, max;
        
        if (num1 <= num2 && num1 <= num3) {
            min = num1;
            if (num2 <= num3) {
                mid = num2;
                max = num3;
            } else {
                mid = num3;
                max = num2;
            }
        } else if (num2 <= num1 && num2 <= num3) {
            min = num2;
            if (num1 <= num3) {
                mid = num1;
                max = num3;
            } else {
                mid = num3;
                max = num1;
            }
        } else {
            min = num3;
            if (num1 <= num2) {
                mid = num1;
                max = num2;
            } else {
                mid = num2;
                max = num1;
            }
        }
        
        System.out.println("Numbers in increasing order: " + min + " " + mid + " " + max);
    }
}
```

#### Exercise 6.6: Display Pattern
**Problem**: Display a triangular pattern of numbers

```java
import java.util.Scanner;

public class DisplayPattern {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter n: ");
        int n = input.nextInt();
        
        displayPattern(n);
    }
    
    /** Display pattern */
    public static void displayPattern(int n) {
        for (int i = 1; i <= n; i++) {
            // Print leading spaces
            for (int j = 0; j < n - i; j++) {
                System.out.print("  ");
            }
            
            // Print descending numbers
            for (int j = i; j >= 1; j--) {
                System.out.print(j + " ");
            }
            
            System.out.println();
        }
    }
}
```

**Pattern Example for n=4**:
```
      1
    2 1
  3 2 1
4 3 2 1
```

#### Exercise 6.7: Future Investment Value
**Problem**: Calculate future investment value

```java
import java.util.Scanner;

public class FutureInvestment {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("The amount invested: ");
        double investment = input.nextDouble();
        
        System.out.print("Annual interest rate: ");
        double annualRate = input.nextDouble();
        
        double monthlyRate = annualRate / 100 / 12;
        
        System.out.println("Years\tFuture Value");
        for (int year = 1; year <= 30; year++) {
            double futureValue = futureInvestmentValue(investment, monthlyRate, year);
            System.out.printf("%d\t%.2f\n", year, futureValue);
        }
    }
    
    /** Calculate future investment value */
    public static double futureInvestmentValue(double investmentAmount, 
                                              double monthlyInterestRate, 
                                              int years) {
        return investmentAmount * Math.pow(1 + monthlyInterestRate, years * 12);
    }
}
```

#### Exercise 6.8: Temperature Conversion
**Problem**: Convert between Celsius and Fahrenheit

```java
public class TemperatureConversion {
    public static void main(String[] args) {
        System.out.println("Celsius\tFahrenheit\t|\tFahrenheit\tCelsius");
        System.out.println("-----------------------------------------------------");
        
        for (double celsius = 40.0, fahrenheit = 120.0; 
             celsius >= 31.0; 
             celsius -= 1.0, fahrenheit -= 10.0) {
            
            System.out.printf("%.1f\t%.1f\t\t|\t%.1f\t\t%.2f\n", 
                celsius, 
                celsiusToFahrenheit(celsius),
                fahrenheit,
                fahrenheitToCelsius(fahrenheit));
        }
    }
    
    /** Convert from Celsius to Fahrenheit */
    public static double celsiusToFahrenheit(double celsius) {
        return (9.0 / 5) * celsius + 32;
    }
    
    /** Convert from Fahrenheit to Celsius */
    public static double fahrenheitToCelsius(double fahrenheit) {
        return (5.0 / 9) * (fahrenheit - 32);
    }
}
```

#### Exercise 6.9: Feet and Meters Conversion
**Problem**: Convert between feet and meters

```java
public class LengthConversion {
    public static void main(String[] args) {
        System.out.println("Feet\tMeters\t|\tMeters\tFeet");
        System.out.println("---------------------------------------");
        
        for (double feet = 1.0, meters = 20.0; 
             feet <= 10.0; 
             feet += 1.0, meters += 5.0) {
            
            System.out.printf("%.1f\t%.3f\t|\t%.1f\t%.3f\n", 
                feet, 
                footToMeter(feet),
                meters,
                meterToFoot(meters));
        }
    }
    
    /** Convert from feet to meters */
    public static double footToMeter(double foot) {
        return 0.305 * foot;
    }
    
    /** Convert from meters to feet */
    public static double meterToFoot(double meter) {
        return 3.279 * meter;
    }
}
```

### Advanced Exercises (6.10-6.16)

#### Exercise 6.10: Count Prime Numbers
**Problem**: Find number of prime numbers less than 10,000

```java
public class CountPrimes {
    public static void main(String[] args) {
        int count = 0;
        
        for (int i = 2; i < 10000; i++) {
            if (isPrime(i)) {
                count++;
            }
        }
        
        System.out.println("Number of prime numbers less than 10,000: " + count);
    }
    
    /** Check whether number is prime */
    public static boolean isPrime(int number) {
        if (number < 2) return false;
        
        for (int divisor = 2; divisor <= Math.sqrt(number); divisor++) {
            if (number % divisor == 0) {
                return false;
            }
        }
        return true;
    }
}
```

#### Exercise 6.11: Compute Commission
**Problem**: Calculate sales commission based on sales amount

```java
public class ComputeCommission {
    public static void main(String[] args) {
        System.out.println("Sales Amount\tCommission");
        System.out.println("--------------------------");
        
        for (double sales = 10000; sales <= 100000; sales += 5000) {
            System.out.printf("%.0f\t\t%.1f\n", sales, computeCommission(sales));
        }
    }
    
    /** Compute commission based on sales amount */
    public static double computeCommission(double salesAmount) {
        double commission = 0;
        
        if (salesAmount <= 5000) {
            commission = salesAmount * 0.08;
        } else if (salesAmount <= 10000) {
            commission = 5000 * 0.08 + (salesAmount - 5000) * 0.10;
        } else {
            commission = 5000 * 0.08 + 5000 * 0.10 + (salesAmount - 10000) * 0.12;
        }
        
        return commission;
    }
}
```

#### Exercise 6.14: Estimate π (Pi)
**Problem**: Estimate π using the series: π = 4(1 - 1/3 + 1/5 - 1/7 + 1/9 - ...)

```java
public class EstimatePi {
    public static void main(String[] args) {
        System.out.println("i\tm(i)");
        System.out.println("---------------");
        
        for (int i = 1; i <= 901; i += 100) {
            System.out.printf("%d\t%.4f\n", i, estimatePi(i));
        }
    }
    
    /** Estimate pi using the given series */
    public static double estimatePi(int terms) {
        double pi = 0.0;
        
        for (int i = 1; i <= terms; i++) {
            if (i % 2 == 1) {
                pi += 1.0 / (2 * i - 1);
            } else {
                pi -= 1.0 / (2 * i - 1);
            }
        }
        
        return 4 * pi;
    }
}
```

### Complex Problem-Solving Exercises

#### Exercise 6.18: Password Validation
**Problem**: Check if a password meets security requirements

```java
import java.util.Scanner;

public class PasswordValidation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a password: ");
        String password = input.nextLine();
        
        if (isValidPassword(password)) {
            System.out.println("Valid Password");
        } else {
            System.out.println("Invalid Password");
        }
    }
    
    /** Check if password is valid */
    public static boolean isValidPassword(String password) {
        // Rule 1: At least 8 characters
        if (password.length() < 8) {
            return false;
        }
        
        // Rule 2: Only letters and digits
        // Rule 3: At least 2 digits
        int digitCount = 0;
        
        for (int i = 0; i < password.length(); i++) {
            char ch = password.charAt(i);
            
            if (Character.isDigit(ch)) {
                digitCount++;
            } else if (!Character.isLetter(ch)) {
                return false; // Contains non-letter, non-digit character
            }
        }
        
        return digitCount >= 2; // Must have at least 2 digits
    }
}
```

#### Exercise 6.22: Square Root Approximation (Babylonian Method)
**Problem**: Approximate square root using iterative method

```java
import java.util.Scanner;

public class BabylonianSquareRoot {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a number: ");
        long n = input.nextLong();
        
        System.out.println("Square root of " + n + " is approximately " + sqrt(n));
        System.out.println("Java's Math.sqrt: " + Math.sqrt(n));
    }
    
    /** Approximate square root using Babylonian method */
    public static double sqrt(long n) {
        if (n == 0) return 0;
        
        double lastGuess = 1.0;  // Initial guess
        double nextGuess;
        
        do {
            nextGuess = (lastGuess + n / lastGuess) / 2.0;
            
            if (Math.abs(nextGuess - lastGuess) < 0.0001) {
                break;
            }
            
            lastGuess = nextGuess;
        } while (true);
        
        return nextGuess;
    }
}
```

**Algorithm Explanation**:
```
Example: sqrt(16)
Initial guess = 1.0
nextGuess = (1.0 + 16/1.0) / 2 = 8.5
nextGuess = (8.5 + 16/8.5) / 2 = 5.191
nextGuess = (5.191 + 16/5.191) / 2 = 4.136
...continues until difference < 0.0001...
Final result ≈ 4.0
```

#### Exercise 6.31: Credit Card Validation (Luhn Algorithm)
**Problem**: Validate credit card numbers using the Luhn check

```java
import java.util.Scanner;

public class CreditCardValidation {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a credit card number as a long integer: ");
        long number = input.nextLong();
        
        if (isValid(number)) {
            System.out.println(number + " is valid");
        } else {
            System.out.println(number + " is invalid");
        }
    }
    
    /** Return true if the card number is valid */
    public static boolean isValid(long number) {
        // Check if number has 13-16 digits
        int size = getSize(number);
        if (size < 13 || size > 16) {
            return false;
        }
        
        // Check if starts with valid prefix
        if (!(prefixMatched(number, 4) || 
              prefixMatched(number, 5) || 
              prefixMatched(number, 37) || 
              prefixMatched(number, 6))) {
            return false;
        }
        
        // Apply Luhn algorithm
        int sum = sumOfDoubleEvenPlace(number) + sumOfOddPlace(number);
        return sum % 10 == 0;
    }
    
    /** Get the result from Step 2 (double every second digit from right) */
    public static int sumOfDoubleEvenPlace(long number) {
        int sum = 0;
        String numStr = Long.toString(number);
        
        // Process every second digit from right to left
        for (int i = numStr.length() - 2; i >= 0; i -= 2) {
            int digit = Character.getNumericValue(numStr.charAt(i));
            sum += getDigit(digit * 2);
        }
        
        return sum;
    }
    
    /** Return this number if single digit, otherwise sum of two digits */
    public static int getDigit(int number) {
        return number < 10 ? number : number / 10 + number % 10;
    }
    
    /** Return sum of odd-place digits from right */
    public static int sumOfOddPlace(long number) {
        int sum = 0;
        String numStr = Long.toString(number);
        
        // Process every digit at odd position from right (1st, 3rd, 5th, etc.)
        for (int i = numStr.length() - 1; i >= 0; i -= 2) {
            sum += Character.getNumericValue(numStr.charAt(i));
        }
        
        return sum;
    }
    
    /** Return true if the digit d is a prefix for number */
    public static boolean prefixMatched(long number, int d) {
        return getPrefix(number, getSize(d)) == d;
    }
    
    /** Return the number of digits in d */
    public static int getSize(long d) {
        return Long.toString(d).length();
    }
    
    /** Return the first k digits from number */
    public static long getPrefix(long number, int k) {
        String numStr = Long.toString(number);
        if (numStr.length() < k) {
            return number;
        }
        return Long.parseLong(numStr.substring(0, k));
    }
}
```

### Key Concepts Summary

#### Method Design Principles
1. **Single Responsibility**: Each method should do one thing well
2. **Clear Naming**: Method names should describe what they do
3. **Appropriate Parameters**: Include all necessary inputs
4. **Proper Return Types**: Return appropriate data types
5. **Input Validation**: Check for invalid inputs
6. **Documentation**: Use clear comments and examples

#### Common Method Patterns
1. **Calculation Methods**: Perform mathematical operations
2. **Validation Methods**: Check if data meets criteria
3. **Conversion Methods**: Transform data from one format to another
4. **Utility Methods**: Provide commonly needed functionality
5. **Display Methods**: Format and present data

#### Testing Strategies
1. **Unit Testing**: Test each method independently
2. **Boundary Testing**: Test edge cases and limits
3. **Invalid Input Testing**: Test with bad data
4. **Integration Testing**: Test methods working together

---

## Key Terms and Definitions

- **Method**: A collection of statements grouped together to perform an operation
- **Method Header**: Specifies modifiers, return type, name, and parameters
- **Method Body**: Contains the implementation code
- **Method Signature**: Method name + parameter list
- **Formal Parameters**: Variables declared in method header
- **Actual Parameters/Arguments**: Values passed when calling method
- **Return Statement**: Returns control and optionally a value to caller
- **Method Overloading**: Multiple methods with same name, different parameters
- **Pass-by-Value**: Arguments are copied to parameters
- **Local Variable**: Variable declared inside a method
- **Scope**: Part of program where variable can be accessed
- **Method Abstraction**: Using method without knowing implementation
- **Stepwise Refinement**: Breaking large problem into smaller subproblems
- **Stub**: Incomplete method used during development
- **Driver**: Test program for individual methods

## Best Practices Checklist

✓ Use descriptive method names
✓ Keep methods focused on single tasks  
✓ Validate input parameters
✓ Use appropriate return types
✓ Include proper documentation
✓ Test methods independently
✓ Handle edge cases and errors
✓ Follow consistent naming conventions
✓ Avoid overly complex methods
✓ Use meaningful variable names
