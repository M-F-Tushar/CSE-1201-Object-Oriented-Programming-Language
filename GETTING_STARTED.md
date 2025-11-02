# Getting Started Guide

Welcome to CSE 1201 - Object Oriented Programming Language repository! This guide will help you set up your environment and start learning.

## 📋 Table of Contents

1. [System Requirements](#system-requirements)
2. [Installation](#installation)
3. [Quick Start](#quick-start)
4. [Repository Navigation](#repository-navigation)
5. [Compiling and Running Programs](#compiling-and-running-programs)
6. [Common Issues](#common-issues)
7. [Learning Path](#learning-path)

## 💻 System Requirements

### For C++ Development

**Windows:**
- Windows 7 or later
- MinGW-w64 or Visual Studio with C++ support

**macOS:**
- macOS 10.12 or later
- Xcode Command Line Tools

**Linux:**
- Any modern Linux distribution
- g++ compiler (usually pre-installed)

### For Java Development

**All Platforms:**
- Java Development Kit (JDK) 8 or later
- Any text editor or IDE (VS Code, IntelliJ IDEA, Eclipse)

## 🔧 Installation

### Installing C++ Compiler

#### Windows (MinGW)

1. Download MinGW from [mingw-w64.org](https://www.mingw-w64.org/)
2. Run the installer
3. Add MinGW bin directory to PATH:
   ```
   C:\mingw-w64\...\mingw64\bin
   ```
4. Verify installation:
   ```bash
   g++ --version
   ```

#### macOS

1. Open Terminal
2. Install Xcode Command Line Tools:
   ```bash
   xcode-select --install
   ```
3. Verify installation:
   ```bash
   g++ --version
   ```

#### Linux (Ubuntu/Debian)

```bash
# Update package list
sudo apt update

# Install g++
sudo apt install g++ build-essential

# Verify installation
g++ --version
```

### Installing Java

#### Windows

1. Download JDK from [Oracle](https://www.oracle.com/java/technologies/downloads/) or [OpenJDK](https://openjdk.org/)
2. Run the installer
3. Set JAVA_HOME environment variable
4. Add Java bin directory to PATH
5. Verify installation:
   ```bash
   java -version
   javac -version
   ```

#### macOS

```bash
# Install using Homebrew
brew install openjdk@17

# Or download from Oracle/OpenJDK website

# Verify installation
java -version
javac -version
```

#### Linux (Ubuntu/Debian)

```bash
# Install default JDK
sudo apt update
sudo apt install default-jdk

# Verify installation
java -version
javac -version
```

## 🚀 Quick Start

### 1. Clone the Repository

```bash
git clone https://github.com/M-F-Tushar/CSE-1201-Object-Oriented-Programming-Language.git
cd CSE-1201-Object-Oriented-Programming-Language
```

### 2. Try Your First C++ Program

```bash
# Navigate to first lecture
cd "OOP in C++/Lecture_01: An Overview of C++/1. C++ Console I and O"

# Compile
g++ 1.cpp -o hello

# Run
./hello          # Linux/Mac
hello.exe        # Windows
```

### 3. Try Your First Java Program

```bash
# Navigate to Java code examples
cd "OOP in Java/Code_Example"

# Compile
javac Student.java

# Run
java Student
```

## 🗺️ Repository Navigation

### C++ Section Structure

```
OOP in C++/
├── Lecture_01/          # Basics: Console I/O, Comments, Classes
├── Lecture_02/          # Constructors, Destructors
├── Lecture_03/          # Object Assignment, Friend Functions
├── Lecture_04/          # Arrays, Pointers, References
├── Lecture_05/          # Function Overloading
├── Lecture_06/          # Operator Overloading
├── Lecture_07/          # Inheritance
├── Lecture_08-09/       # I/O System
├── Lecture_10/          # Virtual Functions, Polymorphism
├── Lecture_11/          # Templates, Exception Handling
├── Lecture_12-14/       # Advanced Topics, STL
└── Practice/            # Practice Problems
```

### Java Section Structure

```
OOP in Java/
├── Chapter 1-4/         # Basics: Variables, Control Structures
├── Chapter 5-8/         # Loops, Methods, Arrays
├── Chapter 9-10/        # Classes, Objects, OOP Thinking
├── Chapter 11-13/       # Inheritance, Exceptions, Interfaces
└── Code_Example/        # Additional Examples
```

## 🔨 Compiling and Running Programs

### C++ Programs

#### Basic Compilation

```bash
# Simple compile
g++ filename.cpp -o outputname

# Run
./outputname
```

#### With Debugging Information

```bash
g++ -g filename.cpp -o outputname
```

#### With Optimization

```bash
g++ -O2 filename.cpp -o outputname
```

#### With C++11/14/17 Standard

```bash
g++ -std=c++11 filename.cpp -o outputname
g++ -std=c++17 filename.cpp -o outputname
```

#### Multiple Files

```bash
g++ file1.cpp file2.cpp -o outputname
```

### Java Programs

#### Basic Compilation and Execution

```bash
# Compile
javac ClassName.java

# Run
java ClassName
```

#### With Package Structure

```bash
# Compile with package
javac -d . PackageName/ClassName.java

# Run with package
java PackageName.ClassName
```

#### Multiple Files

```bash
# Compile all java files in directory
javac *.java

# Or specific files
javac File1.java File2.java
```

## ❗ Common Issues

### C++ Issues

**Issue: "g++ command not found"**
- Solution: Install g++ compiler or add to PATH

**Issue: "undefined reference to..."**
- Solution: Link all necessary files during compilation

**Issue: Header file not found**
- Solution: Ensure header files are in the same directory or use `-I` flag

### Java Issues

**Issue: "javac/java command not found"**
- Solution: Install JDK and add to PATH

**Issue: "Could not find or load main class"**
- Solution: Ensure class name matches filename, check CLASSPATH

**Issue: "UnsupportedClassVersionError"**
- Solution: Ensure JDK and JRE versions match

## 📚 Learning Path

### Beginner Path (Weeks 1-4)

1. **Week 1**: C++ Basics
   - Console I/O
   - Variables and Data Types
   - Basic Program Structure

2. **Week 2**: Introduction to Classes
   - Class Definition
   - Objects
   - Constructors and Destructors

3. **Week 3**: Member Functions
   - Access Specifiers
   - Encapsulation
   - Object Interactions

4. **Week 4**: Java Basics
   - Java Syntax
   - Classes in Java
   - Comparison with C++

### Intermediate Path (Weeks 5-9)

5. **Week 5**: Arrays and Pointers (C++)
   - Arrays of Objects
   - Pointers to Objects
   - References

6. **Week 6**: Function Overloading
   - Function Overloading
   - Default Arguments
   - Copy Constructors

7. **Week 7**: Operator Overloading
   - Binary Operators
   - Unary Operators
   - Assignment Operator

8. **Week 8**: Inheritance
   - Single Inheritance
   - Multiple Inheritance
   - Protected Members

9. **Week 9**: Polymorphism
   - Virtual Functions
   - Abstract Classes
   - Runtime Polymorphism

### Advanced Path (Weeks 10-14)

10. **Week 10**: I/O Systems
    - File I/O in C++
    - Formatted I/O
    - Java I/O

11. **Week 11**: Exception Handling
    - Try-Catch Blocks
    - Custom Exceptions
    - Exception Hierarchies

12. **Week 12**: Templates (C++)
    - Function Templates
    - Class Templates
    - STL Basics

13. **Week 13**: Advanced Java
    - Interfaces
    - Abstract Classes
    - Packages

14. **Week 14**: Final Projects
    - Comprehensive Projects
    - Exam Preparation
    - Review

## 🎯 Study Tips

1. **Follow the Order**: Start with Lecture 1/Chapter 1 and progress sequentially
2. **Practice Daily**: Code along with examples
3. **Read Documentation**: Each folder has detailed markdown guides
4. **Experiment**: Modify code to understand behavior
5. **Debug**: Use print statements to understand program flow
6. **Review**: Regularly revisit earlier topics

## 🆘 Getting Help

If you encounter issues:

1. Check the [Common Issues](#common-issues) section
2. Review lecture notes and documentation
3. Search for error messages online
4. Open an issue on GitHub
5. Refer to [CONTRIBUTING.md](CONTRIBUTING.md)

## 📖 Additional Resources

### Online Resources

- [cplusplus.com](http://www.cplusplus.com/) - C++ Reference
- [cppreference.com](https://en.cppreference.com/) - Comprehensive C++ Reference
- [Oracle Java Tutorials](https://docs.oracle.com/javase/tutorial/) - Official Java Tutorials
- [GeeksforGeeks](https://www.geeksforgeeks.org/) - Programming Examples

### Recommended IDEs

**C++:**
- Visual Studio Code (Free, Cross-platform)
- CLion (Paid, Student license available)
- Code::Blocks (Free, Cross-platform)

**Java:**
- IntelliJ IDEA (Free Community Edition)
- Eclipse (Free, Cross-platform)
- NetBeans (Free, Cross-platform)

## 🎓 Next Steps

Once you're comfortable with the basics:

1. Complete practice problems
2. Attempt exam materials
3. Build your own projects
4. Contribute to the repository
5. Help other learners

---

Happy Coding! 🚀

If you find this guide helpful, please ⭐ star the repository!
