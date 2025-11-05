# Code Style Guide

This document outlines the coding standards and style guidelines for the CSE 1201 repository. Following these guidelines helps maintain code quality, readability, and consistency.

---

## 📋 Table of Contents

- [General Principles](#general-principles)
- [C++ Style Guide](#c-style-guide)
- [Java Style Guide](#java-style-guide)
- [Documentation Standards](#documentation-standards)
- [File Organization](#file-organization)

---

## 🎯 General Principles

### Code Quality Goals

1. **Readability**: Code should be easy to understand
2. **Consistency**: Follow established patterns
3. **Simplicity**: Keep it simple and clear
4. **Educational**: Code should teach, not confuse
5. **Maintainability**: Easy to update and improve

### Universal Rules

✅ **DO:**
- Write clear, self-documenting code
- Use meaningful variable and function names
- Add comments for complex logic
- Keep functions small and focused
- Handle errors appropriately
- Follow the DRY principle (Don't Repeat Yourself)

❌ **DON'T:**
- Use cryptic abbreviations
- Write overly complex code
- Ignore compiler warnings
- Leave commented-out code
- Use magic numbers without explanation
- Mix tabs and spaces

---

## 🔷 C++ Style Guide

### Naming Conventions

```cpp
// Classes: PascalCase
class StudentRecord { };
class BankAccount { };

// Functions and methods: camelCase
void calculateTotal() { }
int getStudentAge() { }

// Variables: camelCase
int studentCount;
double accountBalance;

// Constants: UPPER_CASE or kConstant
const int MAX_STUDENTS = 100;
const double PI = 3.14159;

// Member variables: prefix with m_ or suffix with _
class MyClass {
private:
    int m_value;      // or
    int value_;
};
```

### Formatting

```cpp
// Indentation: 4 spaces (no tabs)
class Example {
public:
    void method() {
        if (condition) {
            // Code here
        }
    }
};

// Braces: Same line for functions, next line for classes
void function() {
    // Code
}

class MyClass
{
    // Code
};

// Or consistently on the same line
class MyClass {
    // Code
};

// Spacing around operators
int sum = a + b;
bool result = (x > 5) && (y < 10);

// Pointer/Reference placement
int* ptr;    // or
int *ptr;    // Choose one style and be consistent
int& ref;
```

### Comments

```cpp
// Single-line comments for brief explanations
int count = 0;  // Initialize counter

/* Multi-line comments for detailed explanations
   that span multiple lines */

/**
 * Function documentation
 * Describes what the function does
 * @param input Description of parameter
 * @return Description of return value
 */
int processData(int input) {
    return input * 2;
}
```

### Best Practices

```cpp
// 1. Use const when appropriate
const int SIZE = 100;
void display() const { }

// 2. Initialize variables
int count = 0;
double rate = 0.0;

// 3. Use smart pointers (C++11+)
#include <memory>
std::unique_ptr<int> ptr = std::make_unique<int>(10);

// 4. Prefer range-based for loops (C++11+)
std::vector<int> numbers = {1, 2, 3, 4, 5};
for (const auto& num : numbers) {
    std::cout << num << std::endl;
}

// 5. Use auto for complex types (C++11+)
auto it = myMap.begin();

// 6. Avoid raw arrays, use std::vector
std::vector<int> data(10);  // instead of int data[10];

// 7. Use nullptr instead of NULL (C++11+)
int* ptr = nullptr;

// 8. Always use explicit for single-argument constructors
explicit MyClass(int value) : m_value(value) { }
```

### File Structure

```cpp
// header.h
#ifndef HEADER_H
#define HEADER_H

// Includes
#include <iostream>
#include <vector>

// Class declaration
class MyClass {
private:
    int m_value;

public:
    MyClass();
    void display() const;
};

#endif // HEADER_H

// implementation.cpp
#include "header.h"

// Constructor implementation
MyClass::MyClass() : m_value(0) {
    // Implementation
}

// Method implementation
void MyClass::display() const {
    std::cout << m_value << std::endl;
}
```

---

## ☕ Java Style Guide

### Naming Conventions

```java
// Classes and Interfaces: PascalCase
public class StudentRecord { }
public interface Drawable { }

// Methods: camelCase
public void calculateTotal() { }
public int getStudentAge() { }

// Variables: camelCase
int studentCount;
double accountBalance;

// Constants: UPPER_CASE
public static final int MAX_STUDENTS = 100;
public static final double PI = 3.14159;

// Packages: lowercase
package com.university.courses;
```

### Formatting

```java
// Indentation: 4 spaces
public class Example {
    public void method() {
        if (condition) {
            // Code here
        }
    }
}

// Braces: Opening brace on same line
public void method() {
    // Code
}

// Spacing
int sum = a + b;
boolean result = (x > 5) && (y < 10);

// Method parameters
public void processData(int value, String name) {
    // Code
}
```

### Comments

```java
// Single-line comment
int count = 0;  // Initialize counter

/*
 * Multi-line comment
 * for longer explanations
 */

/**
 * Javadoc comment for methods
 * @param input Description of parameter
 * @return Description of return value
 */
public int processData(int input) {
    return input * 2;
}
```

### Best Practices

```java
// 1. Use final for constants
public static final int MAX_SIZE = 100;

// 2. Initialize variables
int count = 0;
String name = "";

// 3. Use enhanced for loop
List<Integer> numbers = Arrays.asList(1, 2, 3, 4, 5);
for (Integer num : numbers) {
    System.out.println(num);
}

// 4. Use try-with-resources (Java 7+)
try (BufferedReader br = new BufferedReader(new FileReader("file.txt"))) {
    String line = br.readLine();
} catch (IOException e) {
    e.printStackTrace();
}

// 5. Use @Override annotation
@Override
public void method() {
    // Implementation
}

// 6. Use meaningful exception handling
try {
    // Code
} catch (SpecificException e) {
    // Handle specific exception
    System.err.println("Error: " + e.getMessage());
}

// 7. Use proper access modifiers
public class MyClass {
    private int value;  // Private by default
    
    public int getValue() {  // Public accessor
        return value;
    }
}

// 8. Follow the single responsibility principle
public class Student {
    // Only student-related functionality
}
```

### File Structure

```java
// One public class per file
// Filename must match class name

// MyClass.java
package com.example;

// Imports
import java.util.List;
import java.util.ArrayList;

/**
 * Class documentation
 */
public class MyClass {
    // Constants
    private static final int MAX_VALUE = 100;
    
    // Instance variables
    private int value;
    
    // Constructor
    public MyClass(int value) {
        this.value = value;
    }
    
    // Methods
    public void display() {
        System.out.println(value);
    }
}
```

---

## 📝 Documentation Standards

### File Headers

```cpp
/**
 * Filename: example.cpp
 * Description: Brief description of what this file does
 * Author: Your Name
 * Date: YYYY-MM-DD
 * Course: CSE 1201 - Object Oriented Programming
 * Topic: Relevant lecture or chapter
 */
```

### Function Documentation

```cpp
/**
 * Calculate the area of a circle
 * 
 * This function takes a radius and returns the area
 * using the formula: π * r²
 * 
 * @param radius The radius of the circle (must be positive)
 * @return The area of the circle
 * @throws IllegalArgumentException if radius is negative
 */
double calculateCircleArea(double radius) {
    if (radius < 0) {
        throw std::invalid_argument("Radius must be positive");
    }
    return 3.14159 * radius * radius;
}
```

### Inline Comments

```cpp
// Good: Explains WHY, not WHAT
// Use binary search for better performance on sorted array
int index = binarySearch(arr, target);

// Bad: States the obvious
// Loop through array
for (int i = 0; i < size; i++) {
    // Print element
    cout << arr[i];
}
```

---

## 📁 File Organization

### Directory Structure

```
Topic/
├── README.md           # Topic overview
├── examples/           # Example code
│   ├── basic.cpp
│   ├── advanced.cpp
├── exercises/          # Practice problems
│   ├── exercise1.cpp
├── solutions/          # Exercise solutions
│   ├── exercise1_solution.cpp
```

### File Naming

- **C++ Files**: 
  - Source: `descriptive_name.cpp`
  - Headers: `descriptive_name.h`
  - Example: `bank_account.cpp`, `bank_account.h`

- **Java Files**:
  - Must match class name
  - Example: `BankAccount.java`

- **Documentation**:
  - Use snake_case or kebab-case
  - Example: `installation_guide.md`, `cpp-style-guide.md`

---

## ✅ Before Submitting Code

Use this checklist:

- [ ] Code compiles without errors
- [ ] Code follows style guidelines
- [ ] Meaningful variable and function names
- [ ] Appropriate comments added
- [ ] No compiler warnings
- [ ] Code is properly indented
- [ ] No trailing whitespace
- [ ] Final newline at end of file
- [ ] Copyright/license information (if required)
- [ ] Documentation updated (if needed)

---

## 🔍 Code Review Criteria

When reviewing code, check for:

1. **Functionality**: Does it work correctly?
2. **Style**: Does it follow guidelines?
3. **Readability**: Is it easy to understand?
4. **Efficiency**: Is it reasonably optimized?
5. **Safety**: Are there potential bugs or security issues?
6. **Documentation**: Are comments helpful and accurate?

---

## 📚 Additional Resources

- [Google C++ Style Guide](https://google.github.io/styleguide/cppguide.html)
- [Google Java Style Guide](https://google.github.io/styleguide/javaguide.html)
- [C++ Core Guidelines](https://isocpp.github.io/CppCoreGuidelines/)
- [Oracle Java Code Conventions](https://www.oracle.com/java/technologies/javase/codeconventions-contents.html)

---

## 🤝 Questions?

If you have questions about code style:

1. Check this guide
2. Look at existing code examples
3. Ask in [discussions](https://github.com/M-F-Tushar/CSE-1201-Object-Oriented-Programming-Language/discussions)
4. Create an issue with the `question` label

---

**Remember**: Consistency is more important than personal preference. When in doubt, follow the existing style in the repository.

---

*Last Updated: November 2024*
