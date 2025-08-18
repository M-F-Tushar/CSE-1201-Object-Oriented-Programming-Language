# Chapter 12: Exception Handling and Text I/O - Complete Study Guide

## Table of Contents
1. [Introduction to Exception Handling](#1-introduction-to-exception-handling)
2. [Exception-Handling Overview](#2-exception-handling-overview)
3. [Exception Types](#3-exception-types)
4. [More on Exception Handling](#4-more-on-exception-handling)
5. [The finally Clause](#5-the-finally-clause)
6. [When to Use Exceptions](#6-when-to-use-exceptions)
7. [Rethrowing Exceptions](#7-rethrowing-exceptions)
8. [Chained Exceptions](#8-chained-exceptions)
9. [Defining Custom Exception Classes](#9-defining-custom-exception-classes)
10. [The File Class](#10-the-file-class)
11. [File Input and Output](#11-file-input-and-output)
12. [Reading Data from the Web](#12-reading-data-from-the-web)
13. [Case Study: Web Crawler](#13-case-study-web-crawler)

---

## 1. Introduction to Exception Handling

### What is Exception Handling?
Exception handling enables a program to deal with exceptional situations and continue its normal execution instead of terminating abnormally.

### Key Concepts:
- **Runtime Errors**: Occur while a program is running when the JVM detects an impossible operation
- **Exception**: An object that represents an error or condition preventing normal execution
- **Exception Handling**: The process of catching and managing these exceptional situations

### Common Runtime Errors:
- `ArrayIndexOutOfBoundsException`: Accessing array with invalid index
- `InputMismatchException`: Entering wrong data type (e.g., double when expecting integer)
- `ArithmeticException`: Division by zero with integers

### Example Problem:
```java
// This will throw ArithmeticException
int result = 5 / 0;  // Division by zero
```

---

## 2. Exception-Handling Overview

### 2.1 Basic Exception Handling Structure

The fundamental structure consists of:
- **try block**: Contains code that might throw an exception
- **catch block**: Handles the exception if it occurs
- **throw statement**: Creates and throws an exception

### 2.2 Example Progression

#### Without Exception Handling (Quotient.java):
```java
import java.util.Scanner;

public class Quotient {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter two integers: ");
        int number1 = input.nextInt();
        int number2 = input.nextInt();
        
        System.out.println(number1 + " / " + number2 + " is " + 
                          (number1 / number2));
    }
}
```
**Problem**: If user enters 0 for second number, program crashes with `ArithmeticException`.

#### Simple Fix with if Statement (QuotientWithIf.java):
```java
import java.util.Scanner;

public class QuotientWithIf {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter two integers: ");
        int number1 = input.nextInt();
        int number2 = input.nextInt();
        
        if (number2 != 0)
            System.out.println(number1 + " / " + number2 + 
                              " is " + (number1 / number2));
        else
            System.out.println("Divisor cannot be zero");
    }
}
```

#### Method-Based Approach (QuotientWithMethod.java):
```java
import java.util.Scanner;

public class QuotientWithMethod {
    public static int quotient(int number1, int number2) {
        if (number2 == 0) {
            System.out.println("Divisor cannot be zero");
            System.exit(1);  // Terminates entire program - not ideal!
        }
        return number1 / number2;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter two integers: ");
        int number1 = input.nextInt();
        int number2 = input.nextInt();
        
        int result = quotient(number1, number2);
        System.out.println(number1 + " / " + number2 + " is " + result);
    }
}
```
**Problem**: Method terminates entire program instead of letting caller decide.

#### Proper Exception Handling (QuotientWithException.java):
```java
import java.util.Scanner;

public class QuotientWithException {
    public static int quotient(int number1, int number2) {
        if (number2 == 0)
            throw new ArithmeticException("Divisor cannot be zero");
        
        return number1 / number2;
    }
    
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter two integers: ");
        int number1 = input.nextInt();
        int number2 = input.nextInt();
        
        try {
            int result = quotient(number1, number2);
            System.out.println(number1 + " / " + number2 + " is " + result);
        }
        catch (ArithmeticException ex) {
            System.out.println("Exception: an integer cannot be divided by zero");
        }
        
        System.out.println("Execution continues ...");
    }
}
```

### 2.3 Exception Handling Template
```java
try {
    // Code to run
    // Statement or method that may throw an exception
    // More code to run
}
catch (ExceptionType ex) {
    // Code to process the exception
}
```

### 2.4 Input Validation Example (InputMismatchExceptionDemo.java):
```java
import java.util.*;

public class InputMismatchExceptionDemo {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        boolean continueInput = true;
        
        do {
            try {
                System.out.print("Enter an integer: ");
                int number = input.nextInt();
                
                System.out.println("The number entered is " + number);
                continueInput = false;
            }
            catch (InputMismatchException ex) {
                System.out.println("Try again. (Incorrect input: an integer is required)");
                input.nextLine(); // Discard incorrect input
            }
        } while (continueInput);
    }
}
```

### Key Benefits of Exception Handling:
1. **Separation of Concerns**: Error detection (in called method) vs. error handling (in caller)
2. **Program Continuity**: Program continues running instead of crashing
3. **Flexible Error Management**: Caller decides how to handle errors

---

## 3. Exception Types

### 3.1 Exception Hierarchy

```
Object
  └── Throwable
      ├── Error (System Errors)
      │   ├── LinkageError
      │   └── VirtualMachineError
      └── Exception
          ├── IOException
          ├── ClassNotFoundException
          └── RuntimeException (Runtime Exceptions)
              ├── ArithmeticException
              ├── NullPointerException
              ├── IndexOutOfBoundsException
              └── IllegalArgumentException
```

### 3.2 Three Categories of Exceptions

#### System Errors (Error Class)
- **Description**: Internal system errors thrown by JVM
- **Characteristics**: Rarely occur, little can be done when they happen
- **Examples**:
  - `LinkageError`: Class dependency issues after compilation changes
  - `VirtualMachineError`: JVM broken or out of resources

#### Exceptions (Exception Class)
- **Description**: Errors caused by program and external circumstances
- **Characteristics**: Can be caught and handled
- **Examples**:
  - `ClassNotFoundException`: Trying to use non-existent class
  - `IOException`: Input/output related errors (invalid input, file not found)

#### Runtime Exceptions (RuntimeException Class)
- **Description**: Programming errors like bad casting, array bounds, numeric errors
- **Characteristics**: Generally thrown by JVM due to logic errors
- **Examples**:
  - `ArithmeticException`: Integer division by zero
  - `NullPointerException`: Accessing object through null reference
  - `IndexOutOfBoundsException`: Array index out of range
  - `IllegalArgumentException`: Invalid method argument

### 3.3 Checked vs. Unchecked Exceptions

#### Unchecked Exceptions:
- `RuntimeException`, `Error`, and their subclasses
- Compiler doesn't force you to handle them
- Usually indicate programming logic errors
- Can occur anywhere in the program

#### Checked Exceptions:
- All other exceptions (not `RuntimeException` or `Error`)
- Compiler forces you to handle them with try-catch or declare in method header
- Usually indicate recoverable conditions

### 3.4 Practice Examples

```java
// ArithmeticException (Unchecked)
public class Test {
    public static void main(String[] args) {
        System.out.println(1 / 0); // Throws ArithmeticException
    }
}

// IndexOutOfBoundsException (Unchecked)
public class Test {
    public static void main(String[] args) {
        int[] list = new int[5];
        System.out.println(list[5]); // Throws IndexOutOfBoundsException
    }
}

// StringIndexOutOfBoundsException (Unchecked)
public class Test {
    public static void main(String[] args) {
        String s = "abc";
        System.out.println(s.charAt(3)); // Throws StringIndexOutOfBoundsException
    }
}

// ClassCastException (Unchecked)
public class Test {
    public static void main(String[] args) {
        Object o = new Object();
        String d = (String)o; // Throws ClassCastException
    }
}

// NullPointerException (Unchecked)
public class Test {
    public static void main(String[] args) {
        Object o = null;
        System.out.println(o.toString()); // Throws NullPointerException
    }
}

// No Exception - floating point division by zero returns Infinity
public class Test {
    public static void main(String[] args) {
        System.out.println(1.0 / 0); // Prints: Infinity
    }
}
```

---

## 4. More on Exception Handling

### 4.1 Three Operations in Exception Handling
1. **Declaring Exceptions** (throws)
2. **Throwing Exceptions** (throw)
3. **Catching Exceptions** (try-catch)

### 4.2 Declaring Exceptions

#### Purpose:
- Inform caller about possible checked exceptions
- Only checked exceptions need to be declared
- System errors and runtime exceptions don't require declaration

#### Syntax:
```java
public void myMethod() throws IOException
public void myMethod() throws Exception1, Exception2, ExceptionN
```

#### Important Notes:
- Use `throws` keyword in method header
- Multiple exceptions separated by commas
- Cannot override superclass method to declare exceptions not in superclass

### 4.3 Throwing Exceptions

#### Creating and Throwing:
```java
// Method 1: Create then throw
IllegalArgumentException ex = new IllegalArgumentException("Wrong Argument");
throw ex;

// Method 2: Create and throw in one line
throw new IllegalArgumentException("Wrong Argument");
```

#### Exception Constructors:
Most exception classes have:
- No-arg constructor: `new Exception()`
- Constructor with message: `new Exception("Error message")`

### 4.4 Catching Exceptions

#### Basic Structure:
```java
try {
    statements; // May throw exceptions
}
catch (Exception1 exVar1) {
    // Handle exception1
}
catch (Exception2 exVar2) {
    // Handle exception2
}
catch (ExceptionN exVarN) {
    // Handle exceptionN
}
```

#### Exception Propagation Process:
When exception occurs:
1. Skip remaining statements in try block
2. Search for appropriate catch block from first to last
3. If found, execute catch block, then continue after try-catch
4. If not found, pass exception to calling method
5. Repeat until handled or program terminates

#### Important Rules:
- **Order Matters**: Subclass exceptions must come before superclass exceptions
- **Superclass Catching**: Catch block for superclass can catch subclass exceptions

```java
// WRONG - Compile error
try {
    // code
}
catch (Exception ex) {        // Superclass first
    // handle
}
catch (RuntimeException ex) { // Subclass second - unreachable!
    // handle
}

// CORRECT
try {
    // code
}
catch (RuntimeException ex) { // Subclass first
    // handle
}
catch (Exception ex) {        // Superclass second
    // handle
}
```

#### JDK 7 Multi-Catch Feature:
```java
catch (Exception1 | Exception2 | Exception3 ex) {
    // Same handling code for multiple exception types
}
```

### 4.5 Getting Information from Exceptions

#### Throwable Class Methods:
```java
java.lang.Throwable
+getMessage(): String          // Returns exception message
+toString(): String           // Returns exception class name + message
+printStackTrace(): void      // Prints stack trace to console
+getStackTrace(): StackTraceElement[]  // Returns stack trace array
```

#### Example (TestException.java):
```java
public class TestException {
    public static void main(String[] args) {
        try {
            System.out.println(sum(new int[] {1, 2, 3, 4, 5}));
        }
        catch (Exception ex) {
            ex.printStackTrace();
            System.out.println("\n" + ex.getMessage());
            System.out.println("\n" + ex.toString());
            
            System.out.println("\nTrace Info Obtained from getStackTrace");
            StackTraceElement[] traceElements = ex.getStackTrace();
            for (int i = 0; i < traceElements.length; i++) {
                System.out.print("method " + traceElements[i].getMethodName());
                System.out.print("(" + traceElements[i].getClassName() + ":");
                System.out.println(traceElements[i].getLineNumber() + ")");
            }
        }
    }
    
    private static int sum(int[] list) {
        int result = 0;
        for (int i = 0; i <= list.length; i++) // Error: should be i < list.length
            result += list[i];
        return result;
    }
}
```

### 4.6 Complete Example: CircleWithException

#### CircleWithException.java:
```java
public class CircleWithException {
    private double radius;
    private static int numberOfObjects = 0;
    
    public CircleWithException() {
        this(1.0);
    }
    
    public CircleWithException(double newRadius) {
        setRadius(newRadius);
        numberOfObjects++;
    }
    
    public double getRadius() {
        return radius;
    }
    
    public void setRadius(double newRadius) throws IllegalArgumentException {
        if (newRadius >= 0)
            radius = newRadius;
        else
            throw new IllegalArgumentException("Radius cannot be negative");
    }
    
    public static int getNumberOfObjects() {
        return numberOfObjects;
    }
    
    public double findArea() {
        return radius * radius * 3.14159;
    }
}
```

#### TestCircleWithException.java:
```java
public class TestCircleWithException {
    public static void main(String[] args) {
        try {
            CircleWithException c1 = new CircleWithException(5);
            CircleWithException c2 = new CircleWithException(-5); // Throws exception
            CircleWithException c3 = new CircleWithException(0);
        }
        catch (IllegalArgumentException ex) {
            System.out.println(ex);
        }
        
        System.out.println("Number of objects created: " +
                          CircleWithException.getNumberOfObjects());
    }
}
```

---

## 5. The finally Clause

### 5.1 Purpose and Syntax
The `finally` clause ensures code execution regardless of whether an exception occurs.

```java
try {
    statements;
}
catch (TheException ex) {
    handling ex;
}
finally {
    finalStatements; // Always executed
}
```

### 5.2 Execution Scenarios

#### Case 1: No Exception
1. Execute try block completely
2. Execute finally block
3. Continue with statements after try-catch-finally

#### Case 2: Exception Caught
1. Execute try block until exception occurs
2. Execute appropriate catch block
3. Execute finally block
4. Continue with statements after try-catch-finally

#### Case 3: Exception Not Caught
1. Execute try block until exception occurs
2. Execute finally block
3. Pass exception to caller (program may terminate)

### 5.3 Important Notes
- Finally block executes even if there's a `return` statement before it
- Catch block can be omitted when finally clause is used
- Finally is typically used for cleanup operations (closing files, releasing resources)

### 5.4 Example
```java
public class FinallyExample {
    public static void main(String[] args) {
        try {
            int result = divide(10, 0);
            System.out.println("Result: " + result);
        }
        catch (ArithmeticException ex) {
            System.out.println("Exception caught: " + ex.getMessage());
        }
        finally {
            System.out.println("Finally block always executes");
        }
        System.out.println("Program continues...");
    }
    
    static int divide(int a, int b) {
        return a / b;
    }
}
```

---

## 6. When to Use Exceptions

### 6.1 Guidelines for Exception Usage

#### Use Exceptions When:
- Error needs to be handled by caller
- Unexpected error conditions occur
- Method cannot complete its intended task
- Common exceptions that may occur across multiple classes

#### Don't Use Exceptions When:
- Simple, expected situations can be handled with if statements
- Performance is critical (exceptions have overhead)
- Simple logic tests suffice

### 6.2 Good vs. Bad Practice

#### Bad Practice:
```java
// Don't use exceptions for simple null checks
try {
    System.out.println(refVar.toString());
}
catch (NullPointerException ex) {
    System.out.println("refVar is null");
}
```

#### Good Practice:
```java
// Use simple if statement instead
if (refVar != null)
    System.out.println(refVar.toString());
else
    System.out.println("refVar is null");
```

### 6.3 Performance Considerations
Exception handling requires:
- Instantiating new exception object
- Rolling back the call stack
- Propagating exception through method chain
- Searching for appropriate handler

Use exceptions judiciously for truly exceptional circumstances.

### 6.4 Exercise Example
```java
// Question: Is this correct exception usage?
public static boolean isNumeric(String token) {
    try {
        Double.parseDouble(token);
        return true;
    }
    catch (java.lang.NumberFormatException ex) {
        return false;
    }
}

// Better approach without exceptions:
public static boolean isNumeric(String token) {
    if (token == null || token.trim().isEmpty()) {
        return false;
    }
    
    try {
        Double.parseDouble(token);
        return true;
    }
    catch (NumberFormatException e) {
        return false;
    }
}
```

---

## 7. Rethrowing Exceptions

### 7.1 Purpose
Sometimes a method needs to:
- Perform some cleanup before the exception propagates
- Log the exception but still notify the caller
- Add additional information before passing exception up

### 7.2 Syntax
```java
try {
    statements;
}
catch (TheException ex) {
    // Perform operations before exit
    throw ex; // Rethrow the same exception
}
```

### 7.3 Example
```java
public class RethrowExample {
    public static void main(String[] args) {
        try {
            processData();
        }
        catch (Exception ex) {
            System.out.println("Caught in main: " + ex.getMessage());
        }
    }
    
    static void processData() throws Exception {
        try {
            // Some operation that might fail
            int result = 10 / 0;
        }
        catch (ArithmeticException ex) {
            System.out.println("Logging error: " + ex.getMessage());
            // Perform cleanup
            cleanup();
            // Rethrow to notify caller
            throw ex;
        }
    }
    
    static void cleanup() {
        System.out.println("Performing cleanup...");
    }
}
```

### 7.4 Execution Flow with Rethrowing
1. Exception occurs in try block
2. Catch block executes (cleanup, logging, etc.)
3. Exception is rethrown to caller
4. Finally block executes (if present)
5. Exception propagates to calling method

---

## 8. Chained Exceptions

### 8.1 Purpose
Create a new exception with additional information while preserving the original exception's information.

### 8.2 Creating Chained Exceptions
```java
// Constructor for chained exceptions
new Exception("Additional info", originalException)
```

### 8.3 Example (ChainedExceptionDemo.java)
```java
public class ChainedExceptionDemo {
    public static void main(String[] args) {
        try {
            method1();
        }
        catch (Exception ex) {
            ex.printStackTrace();
        }
    }
    
    public static void method1() throws Exception {
        try {
            method2();
        }
        catch (Exception ex) {
            // Chain the original exception with new information
            throw new Exception("New info from method1", ex);
        }
    }
    
    public static void method2() throws Exception {
        throw new Exception("New info from method2");
    }
}
```

### 8.4 Output Analysis
```
java.lang.Exception: New info from method1
    at ChainedExceptionDemo.method1(ChainedExceptionDemo.java:16)
    at ChainedExceptionDemo.main(ChainedExceptionDemo.java:4)
Caused by: java.lang.Exception: New info from method2
    at ChainedExceptionDemo.method2(ChainedExceptionDemo.java:21)
    at ChainedExceptionDemo.method1(ChainedExceptionDemo.java:13)
    ... 1 more
```

The output shows:
1. New exception with additional context
2. Original exception that caused the problem
3. Complete stack trace from both exceptions

---

## 9. Defining Custom Exception Classes

### 9.1 When to Create Custom Exceptions
- Predefined exceptions don't adequately describe the problem
- Need to pass additional information to exception handler
- Want to create domain-specific exceptions for your application

### 9.2 Custom Exception Design
```java
public class CustomException extends Exception {
    // Additional fields for extra information
    private SomeType additionalInfo;
    
    // No-arg constructor
    public CustomException() {
        super();
    }
    
    // Constructor with message
    public CustomException(String message) {
        super(message);
    }
    
    // Constructor with additional information
    public CustomException(String message, SomeType info) {
        super(message);
        this.additionalInfo = info;
    }
    
    // Getter for additional information
    public SomeType getAdditionalInfo() {
        return additionalInfo;
    }
}
```

### 9.3 Complete Example: InvalidRadiusException

#### InvalidRadiusException.java:
```java
public class InvalidRadiusException extends Exception {
    private double radius;
    
    /** Construct an exception */
    public InvalidRadiusException(double radius) {
        super("Invalid radius " + radius);
        this.radius = radius;
    }
    
    /** Return the radius */
    public double getRadius() {
        return radius;
    }
}
```

#### TestCircleWithCustomException.java:
```java
public class TestCircleWithCustomException {
    public static void main(String[] args) {
        try {
            new CircleWithCustomException(5);
            new CircleWithCustomException(-5); // Throws custom exception
            new CircleWithCustomException(0);
        }
        catch (InvalidRadiusException ex) {
            System.out.println(ex);
            System.out.println("Invalid radius was: " + ex.getRadius());
        }
        
        System.out.println("Number of objects created: " +
                          CircleWithCustomException.getNumberOfObjects());
    }
}

class CircleWithCustomException {
    private double radius;
    private static int numberOfObjects = 0;
    
    public CircleWithCustomException() throws InvalidRadiusException {
        this(1.0);
    }
    
    public CircleWithCustomException(double newRadius) 
            throws InvalidRadiusException {
        setRadius(newRadius);
        numberOfObjects++;
    }
    
    public double getRadius() {
        return radius;
    }
    
    public void setRadius(double newRadius) throws InvalidRadiusException {
        if (newRadius >= 0)
            radius = newRadius;
        else
            throw new InvalidRadiusException(newRadius);
    }
    
    public static int getNumberOfObjects() {
        return numberOfObjects;
    }
    
    public double findArea() {
        return radius * radius * 3.14159;
    }
}
```

### 9.4 Best Practices
- **Make custom exceptions checked** (extend `Exception`, not `RuntimeException`)
- **Provide meaningful names** that describe the specific problem
- **Include relevant information** that helps with debugging
- **Follow standard constructor patterns** (no-arg and message constructors)
- **Add getters for additional information** stored in the exception

---

## 10. The File Class

### 10.1 Purpose and Overview
The `File` class provides an abstraction for file and directory operations, handling machine-dependent complexities in a platform-independent way.

### 10.2 Key Concepts

#### File Names:
- **Absolute File Name**: Complete path with drive letter (e.g., `c:\book\Welcome.java`)
- **Relative File Name**: Relative to current working directory (e.g., `Welcome.java`)
- **Directory Path**: Path to the directory containing the file

#### Platform Independence:
- Use forward slash `/` as directory separator (works on all platforms)
- Avoid absolute paths in programs for portability
- Backslash `\` in strings must be escaped as `\\`

### 10.3 File Class Methods

```java
// Constructors
File(String pathname)
File(String parent, String child)
File(File parent, String child)

// File Properties
boolean exists()              // Check if file/directory exists
boolean canRead()            // Check if file can be read
boolean canWrite()           // Check if file can be written
boolean isDirectory()        // Check if it's a directory
boolean isFile()            // Check if it's a file
boolean isAbsolute()        // Check if path is absolute
boolean isHidden()          // Check if file is hidden

// Path Information
String getAbsolutePath()     // Get complete absolute path
String getCanonicalPath()    // Get canonical path (resolves . and ..)
String getName()            // Get file/directory name only
String getPath()            // Get complete path as specified
String getParent()          // Get parent directory

// File Metadata
long lastModified()         // Get last modification time
long length()              // Get file size in bytes
File[] listFiles()         // Get files in directory (for directories)

// File Operations
boolean delete()            // Delete file/directory
boolean renameTo(File dest) // Rename/move file
boolean mkdir()             // Create directory
boolean mkdirs()           // Create directory with parents
```

### 10.4 Complete Example (TestFileClass.java)
```java
public class TestFileClass {
    public static void main(String[] args) {
        java.io.File file = new java.io.File("image/us.gif");
        
        System.out.println("Does it exist? " + file.exists());
        System.out.println("The file has " + file.length() + " bytes");
        System.out.println("Can it be read? " + file.canRead());
        System.out.println("Can it be written? " + file.canWrite());
        System.out.println("Is it a directory? " + file.isDirectory());
        System.out.println("Is it a file? " + file.isFile());
        System.out.println("Is it absolute? " + file.isAbsolute());
        System.out.println("Is it hidden? " + file.isHidden());
        System.out.println("Absolute path is " + file.getAbsolutePath());
        System.out.println("Last modified on " + 
                          new java.util.Date(file.lastModified()));
    }
}
```

### 10.5 Important Notes
- Creating a `File` object doesn't create actual file on disk
- Use `exists()` method to check if file actually exists
- File operations may require appropriate permissions
- `lastModified()` returns milliseconds since UNIX epoch (Jan 1, 1970)

---

## 11. File Input and Output

### 11.1 Overview
- **File Object**: Encapsulates file properties but doesn't handle I/O
- **I/O Classes**: Required for actual reading/writing operations
- **File Types**: Text files (characters) vs. Binary files (bytes)

### 11.2 Writing Data with PrintWriter

#### Creating PrintWriter:
```java
PrintWriter output = new PrintWriter(filename);
PrintWriter output = new PrintWriter(file);
```

#### PrintWriter Methods:
```java
print(String s)          // Write string
print(char c)           // Write character  
print(char[] array)     // Write character array
print(int i)            // Write integer
print(long l)           // Write long
print(float f)          // Write float
print(double d)         // Write double
print(boolean b)        // Write boolean
println(...)            // Print + line separator
printf(format, args)    // Formatted output
close()                 // Close the file (important!)
```

#### Example (WriteData.java):
```java
public class WriteData {
    public static void main(String[] args) throws IOException {
        java.io.File file = new java.io.File("scores.txt");
        
        // Check if file exists
        if (file.exists()) {
            System.out.println("File already exists");
            System.exit(1);
        }
        
        // Create PrintWriter
        java.io.PrintWriter output = new java.io.PrintWriter(file);
        
        // Write formatted output to file
        output.print("John T Smith ");
        output.println(90);
        output.print("Eric K Jones ");
        output.println(85);
        
        // Close the file - IMPORTANT!
        output.close();
    }
}
```

### 11.3 Try-with-Resources (JDK 7+)

#### Automatic Resource Management:
```java
try (ResourceType resource = new ResourceType(parameters)) {
    // Use the resource
} // Resource automatically closed
```

#### Example (WriteDataWithAutoClose.java):
```java
public class WriteDataWithAutoClose {
    public static void main(String[] args) throws Exception {
        java.io.File file = new java.io.File("scores.txt");
        
        if (file.exists()) {
            System.out.println("File already exists");
            System.exit(0);
        }
        
        try (
            // Declare and create resource
            java.io.PrintWriter output = new java.io.PrintWriter(file);
        ) {
            // Use the resource
            output.print("John T Smith ");
            output.println(90);
            output.print("Eric K Jones ");
            output.println(85);
        } // PrintWriter automatically closed here
    }
}
```

#### Benefits of Try-with-Resources:
- Automatic resource cleanup
- Prevents resource leaks
- Simpler, cleaner code
- Handles exceptions during close operations

### 11.4 Reading Data with Scanner

#### Creating Scanner for Files:
```java
Scanner input = new Scanner(System.in);        // From keyboard
Scanner input = new Scanner(new File(filename)); // From file
Scanner input = new Scanner("string data");     // From string
```

#### Scanner Methods:
```java
// Token Reading Methods
boolean hasNext()           // Check if more tokens available
String next()              // Read next token as string
String nextLine()          // Read entire line
byte nextByte()            // Read next token as byte
short nextShort()          // Read next token as short
int nextInt()             // Read next token as int
long nextLong()           // Read next token as long
float nextFloat()         // Read next token as float
double nextDouble()       // Read next token as double

// Utility Methods
void close()              // Close the scanner
Scanner useDelimiter(String pattern) // Set custom delimiter
```

#### Example (ReadData.java):
```java
import java.util.Scanner;

public class ReadData {
    public static void main(String[] args) throws Exception {
        // Create File instance
        java.io.File file = new java.io.File("scores.txt");
        
        // Create Scanner for the file
        Scanner input = new Scanner(file);
        
        // Read data from file
        while (input.hasNext()) {
            String firstName = input.next();
            String mi = input.next();
            String lastName = input.next();
            int score = input.nextInt();
            System.out.println(firstName + " " + mi + " " + lastName + " " + score);
        }
        
        // Close the file
        input.close();
    }
}
```

### 11.5 How Scanner Works

#### Token Reading Process:
1. Skip delimiters (whitespace by default)
2. Read token until next delimiter
3. Convert to appropriate type (for typed methods)
4. Delimiter remains in input stream

#### Default Delimiters:
- Space, tab, newline, carriage return
- Can be changed with `useDelimiter(String regex)`

#### next() vs nextLine():
- `next()`: Reads token delimited by whitespace
- `nextLine()`: Reads entire line including spaces, stops at line separator

#### Important Behavior Example:
```java
// File contains: "34 567"
Scanner input = new Scanner(new File("test.txt"));
int intValue = input.nextInt();    // Gets 34
String line = input.nextLine();   // Gets " 567" (space included)

// Keyboard input: user enters "34", presses Enter, enters "567", presses Enter
Scanner input = new Scanner(System.in);
int intValue = input.nextInt();    // Gets 34, leaves newline in buffer
String line = input.nextLine();   // Gets empty string (reads only newline)
```

### 11.6 Case Study: Text Replacement (ReplaceText.java)

#### Purpose:
Replace all occurrences of a string in a text file with a new string.

#### Usage:
```bash
java ReplaceText sourceFile targetFile oldString newString
```

#### Complete Implementation:
```java
import java.io.*;
import java.util.*;

public class ReplaceText {
    public static void main(String[] args) throws Exception {
        // Check command line parameter usage
        if (args.length != 4) {
            System.out.println(
                "Usage: java ReplaceText sourceFile targetFile oldStr newStr");
            System.exit(1);
        }
        
        // Check if source file exists
        File sourceFile = new File(args[0]);
        if (!sourceFile.exists()) {
            System.out.println("Source file " + args[0] + " does not exist");
            System.exit(2);
        }
        
        // Check if target file exists
        File targetFile = new File(args[1]);
        if (targetFile.exists()) {
            System.out.println("Target file " + args[1] + " already exists");
            System.exit(3);
        }
        
        try (
            // Create input and output files
            Scanner input = new Scanner(sourceFile);
            PrintWriter output = new PrintWriter(targetFile);
        ) {
            while (input.hasNext()) {
                String s1 = input.nextLine();
                String s2 = s1.replaceAll(args[2], args[3]);
                output.println(s2);
            }
        }
    }
}
```

#### Key Features:
- Command-line argument validation
- File existence checking
- Try-with-resources for automatic cleanup
- Line-by-line processing
- String replacement using `replaceAll()`

---

## 12. Reading Data from the Web

### 12.1 Overview
Java allows reading data from web files using URLs, treating web files similarly to local files.

### 12.2 URL Class

#### Creating URL Objects:
```java
import java.net.URL;
import java.net.MalformedURLException;

try {
    URL url = new URL("http://www.google.com/index.html");
} catch (MalformedURLException ex) {
    ex.printStackTrace();
}
```

#### Important Notes:
- Must include `http://` prefix
- `MalformedURLException` thrown for invalid URL syntax
- URL syntax must be exact (e.g., `http://www.google.com` not `www.google.com`)

### 12.3 Reading from URLs

#### Creating Scanner from URL:
```java
URL url = new URL("http://example.com/file.txt");
Scanner input = new Scanner(url.openStream());
```

### 12.4 Complete Example (ReadFileFromURL.java):

```java
import java.util.Scanner;

public class ReadFileFromURL {
    public static void main(String[] args) {
        System.out.print("Enter a URL: ");
        String URLString = new Scanner(System.in).next();
        
        try {
            java.net.URL url = new java.net.URL(URLString);
            int count = 0;
            Scanner input = new Scanner(url.openStream());
            
            while (input.hasNext()) {
                String line = input.nextLine();
                count += line.length();
            }
            
            System.out.println("The file size is " + count + " characters");
        }
        catch (java.net.MalformedURLException ex) {
            System.out.println("Invalid URL");
        }
        catch (java.io.IOException ex) {
            System.out.println("I/O Errors: no such file");
        }
    }
}
```

#### Sample Output:
```
Enter a URL: http://cs.armstrong.edu/liang/data/Lincoln.txt
The file size is 1469 characters

Enter a URL: http://www.yahoo.com
The file size is 190006 characters
```

### 12.5 Exception Handling for URLs

#### Common Exceptions:
- `MalformedURLException`: Invalid URL format
- `IOException`: URL exists but file not found or network issues

#### Error Scenarios:
```java
// Good format but non-existent file
"http://google.com/nonexistent.html" // Throws IOException

// Bad format  
"http:www.google.com/index.html" // Missing //, throws MalformedURLException
"www.google.com" // Missing http://, throws MalformedURLException
```

---

## 13. Case Study: Web Crawler

### 13.1 Purpose
Develop a program that automatically traverses web pages by following hyperlinks.

### 13.2 Algorithm
```
Add starting URL to pendingURLs list
While pendingURLs is not empty AND traversed count <= 100:
    Remove URL from pendingURLs
    If URL not in traversedURLs:
        Add URL to traversedURLs
        Display URL
        Extract all URLs from this page
        Add new URLs to pendingURLs (if not already traversed)
```

### 13.3 Complete Implementation (WebCrawler.java):

```java
import java.util.Scanner;
import java.util.ArrayList;

public class WebCrawler {
    public static void main(String[] args) {
        java.util.Scanner input = new java.util.Scanner(System.in);
        System.out.print("Enter a URL: ");
        String url = input.nextLine();
        crawler(url);
    }
    
    public static void crawler(String startingURL) {
        ArrayList<String> listOfPendingURLs = new ArrayList<>();
        ArrayList<String> listOfTraversedURLs = new ArrayList<>();
        
        listOfPendingURLs.add(startingURL);
        
        while (!listOfPendingURLs.isEmpty() && 
               listOfTraversedURLs.size() <= 100) {
            
            String urlString = listOfPendingURLs.remove(0);
            
            if (!listOfTraversedURLs.contains(urlString)) {
                listOfTraversedURLs.add(urlString);
                System.out.println("Crawl " + urlString);
                
                // Get all URLs from current page
                for (String s: getSubURLs(urlString)) {
                    if (!listOfTraversedURLs.contains(s))
                        listOfPendingURLs.add(s);
                }
            }
        }
    }
    
    public static ArrayList<String> getSubURLs(String urlString) {
        ArrayList<String> list = new ArrayList<>();
        
        try {
            java.net.URL url = new java.net.URL(urlString);
            Scanner input = new Scanner(url.openStream());
            int current = 0;
            
            while (input.hasNext()) {
                String line = input.nextLine();
                current = line.indexOf("http:", current);
                
                while (current > 0) {
                    int endIndex = line.indexOf("\"", current);
                    if (endIndex > 0) {
                        // Extract URL
                        list.add(line.substring(current, endIndex));
                        current = line.indexOf("http:", endIndex);
                    } else {
                        current = -1;
                    }
                }
            }
        }
        catch (Exception ex) {
            System.out.println("Error: " + ex.getMessage());
        }
        
        return list;
    }
}
```

### 13.4 Key Components Explained

#### Main Method:
- Prompts user for starting URL
- Calls crawler method to begin traversal

#### crawler Method:
- Maintains two lists: pending URLs and traversed URLs
- Processes URLs until list is empty or 100 pages traversed
- Prevents visiting same URL twice

#### getSubURLs Method:
- Reads web page content line by line
- Searches for "http:" patterns
- Extracts URLs assuming they end with quotation mark
- Returns list of found URLs

### 13.5 Algorithm Analysis

#### Data Structures:
- `listOfPendingURLs`: URLs waiting to be processed (queue-like behavior)
- `listOfTraversedURLs`: URLs already visited (prevents cycles)

#### URL Extraction Logic:
```java
// For each line in web page:
current = line.indexOf("http:", current);     // Find start of URL
endIndex = line.indexOf("\"", current);      // Find end of URL (quote)
url = line.substring(current, endIndex);     // Extract URL
```

#### Termination Conditions:
1. No more pending URLs (dead end or finite web graph)
2. Reached 100 traversed URLs (prevents infinite crawling)

### 13.6 Sample Output:
```
Enter a URL: http://www.cs.armstrong.edu/liang
Crawl http://www.cs.armstrong.edu/liang
Crawl http://www.cs.armstrong.edu
Crawl http://www.armstrong.edu
Crawl http://www.pearsonhighered.com/liang
...
```

### 13.7 Potential Improvements
- Handle different URL formats (https, relative URLs)
- Respect robots.txt files
- Add delay between requests
- Handle JavaScript-generated content
- Implement breadth-first vs depth-first traversal options
- Add URL filtering capabilities

---

## Practice Exercises and Review Questions

### Basic Exception Handling

#### Exercise 1: Exception Identification
What exceptions will the following code segments throw?

```java
// a)
System.out.println(1 / 0);

// b) 
int[] list = new int[5];
System.out.println(list[5]);

// c)
String s = "abc";
System.out.println(s.charAt(3));

// d)
Object o = new Object();
String d = (String)o;

// e)
Object o = null;
System.out.println(o.toString());

// f)
System.out.println(1.0 / 0);
```

**Answers:**
- a) `ArithmeticException` (integer division by zero)
- b) `ArrayIndexOutOfBoundsException` (index 5 in array of size 5)
- c) `StringIndexOutOfBoundsException` (index 3 in string of length 3)
- d) `ClassCastException` (cannot cast Object to String)
- e) `NullPointerException` (calling method on null reference)
- f) No exception (floating-point division by zero returns Infinity)

#### Exercise 2: Exception Flow Analysis
```java
public class Test {
    public static void main(String[] args) {
        try {
            for (int i = 0; i < 2; i++) {
                System.out.print(i + " ");
                System.out.println(1 / 0);
            }
        }
        catch (Exception ex) {
            System.out.println("Exception caught");
        }
    }
}
```

**Output:** `0 Exception caught`
**Explanation:** Loop executes once, prints "0 ", then throws exception and jumps to catch block.

### File I/O Practice

#### Exercise 3: File Operations
Write a program that:
1. Creates a file named "student_grades.txt"
2. Writes student names and grades
3. Reads and displays the content
4. Calculates average grade

```java
import java.io.*;
import java.util.Scanner;

public class StudentGrades {
    public static void main(String[] args) throws Exception {
        // Writing data
        try (PrintWriter output = new PrintWriter("student_grades.txt")) {
            output.println("Alice 95");
            output.println("Bob 87");
            output.println("Charlie 92");
            output.println("Diana 88");
        }
        
        // Reading and calculating
        try (Scanner input = new Scanner(new File("student_grades.txt"))) {
            int totalGrades = 0;
            int count = 0;
            
            System.out.println("Student Grades:");
            while (input.hasNext()) {
                String name = input.next();
                int grade = input.nextInt();
                System.out.println(name + ": " + grade);
                totalGrades += grade;
                count++;
            }
            
            if (count > 0) {
                double average = (double) totalGrades / count;
                System.out.printf("Average grade: %.2f%n", average);
            }
        }
    }
}
```

### Custom Exception Practice

#### Exercise 4: Bank Account Exception
Create a custom exception for invalid bank account operations:

```java
// Custom exception class
class InsufficientFundsException extends Exception {
    private double amount;
    private double balance;
    
    public InsufficientFundsException(double amount, double balance) {
        super("Insufficient funds: attempted $" + amount + 
              ", available $" + balance);
        this.amount = amount;
        this.balance = balance;
    }
    
    public double getAmount() { return amount; }
    public double getBalance() { return balance; }
}

// Bank account class
class BankAccount {
    private double balance;
    
    public BankAccount(double initialBalance) {
        this.balance = initialBalance;
    }
    
    public void withdraw(double amount) throws InsufficientFundsException {
        if (amount > balance) {
            throw new InsufficientFundsException(amount, balance);
        }
        balance -= amount;
    }
    
    public double getBalance() { return balance; }
}

// Test program
public class BankTest {
    public static void main(String[] args) {
        BankAccount account = new BankAccount(100.0);
        
        try {
            account.withdraw(150.0); // Should throw exception
        }
        catch (InsufficientFundsException ex) {
            System.out.println("Error: " + ex.getMessage());
            System.out.println("Attempted: $" + ex.getAmount());
            System.out.println("Available: $" + ex.getBalance());
        }
    }
}
```

---

## Key Terms Summary

- **Exception**: Object representing an error or abnormal condition
- **Checked Exception**: Must be caught or declared (IOException, ClassNotFoundException)
- **Unchecked Exception**: Not required to be caught (RuntimeException, Error)
- **Exception Propagation**: Process of passing exception up the call stack
- **try-catch-finally**: Exception handling structure
- **throw**: Keyword to create and throw an exception
- **throws**: Keyword to declare possible exceptions in method signature
- **Chained Exception**: Exception that wraps another exception with additional context
- **Custom Exception**: User-defined exception class extending Exception
- **File Class**: Represents file/directory for property operations (not I/O)
- **PrintWriter**: Class for writing text data to files
- **Scanner**: Class for reading text data from various sources
- **try-with-resources**: Automatic resource management syntax (JDK 7+)
- **URL**: Class for accessing web resources
- **Web Crawler**: Program that traverses web pages following links

---

## Chapter Summary

1. **Exception Handling Benefits**: Separates error detection from error handling, enables graceful error recovery, and makes programs more robust.

2. **Exception Hierarchy**: All exceptions inherit from Throwable, with Error (system errors) and Exception (recoverable errors) as main branches.

3. **Handling Strategy**: Use try-catch for expected recoverable errors, finally for cleanup, and custom exceptions for domain-specific problems.

4. **File Operations**: Use File class for file properties, PrintWriter for writing text, Scanner for reading text, and try-with-resources for automatic cleanup.

5. **Web Integration**: Java can read from URLs just like local files, enabling web-based data processing and crawling applications.

The combination of robust exception handling and flexible I/O capabilities makes Java suitable for building reliable applications that can handle errors gracefully and process data from various sources.
