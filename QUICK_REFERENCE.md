# 📖 Quick Reference Guide

A fast reference to common OOP concepts, commands, and resources in this repository.

---

## 🚀 Quick Start Commands

### C++ Compilation

```bash
# Basic compilation
g++ filename.cpp -o output

# With C++17 standard and warnings
g++ -std=c++17 -Wall -Wextra filename.cpp -o output

# Multiple files
g++ file1.cpp file2.cpp -o output

# Run the program
./output                # Linux/Mac
output.exe              # Windows
```

### Java Compilation

```bash
# Compile
javac ClassName.java

# Run
java ClassName

# Compile with warnings
javac -Xlint:all ClassName.java
```

---

## 📚 Core OOP Concepts

### The Four Pillars of OOP

1. **Encapsulation** 🔒
   - Bundling data and methods together
   - Using access modifiers (private, public, protected)
   - See: [C++ Lecture 02](OOP%20in%20C++/Lecture_02:%20Introducing%20Classes/), [Java Chapter 9](OOP%20in%20Java/Chapter%209%20-%20Objects%20and%20Classes/)

2. **Inheritance** 🌳
   - Creating new classes from existing ones
   - Code reusability through parent-child relationships
   - See: [C++ Lecture 07](OOP%20in%20C++/Lecture_07:%20Inheritance/), [Java Chapter 11](OOP%20in%20Java/Chapter%2011%20-%20Inheritance%20and%20Polymorphism/)

3. **Polymorphism** 🎭
   - Same interface, different implementations
   - Method overloading and overriding
   - See: [C++ Lecture 05-06, 10](OOP%20in%20C++/), [Java Chapter 11](OOP%20in%20Java/Chapter%2011%20-%20Inheritance%20and%20Polymorphism/)

4. **Abstraction** 🎨
   - Hiding complex implementation details
   - Using abstract classes and interfaces
   - See: [C++ Lecture 10](OOP%20in%20C++/Lecture_10:%20Virtual%20Functions/), [Java Chapter 13](OOP%20in%20Java/Chapter%2013%20-%20Abstract%20Classes%20and%20Interfaces/)

---

## 🔑 Key C++ Concepts

### Classes and Objects
```cpp
class MyClass {
private:
    int data;
public:
    MyClass(int d) : data(d) {}  // Constructor
    ~MyClass() {}                 // Destructor
    void display() { cout << data; }
};

MyClass obj(10);  // Object creation
```

### Pointers and References
```cpp
int* ptr = new int(10);    // Pointer
int& ref = *ptr;           // Reference
delete ptr;                // Memory cleanup
```

### Inheritance
```cpp
class Base {
    // Base class
};

class Derived : public Base {
    // Derived class
};
```

### Virtual Functions
```cpp
class Base {
public:
    virtual void display() {
        // Can be overridden
    }
};
```

---

## ☕ Key Java Concepts

### Classes and Objects
```java
public class MyClass {
    private int data;
    
    public MyClass(int d) {  // Constructor
        this.data = d;
    }
    
    public void display() {
        System.out.println(data);
    }
}

MyClass obj = new MyClass(10);  // Object creation
```

### Inheritance
```java
public class Base {
    // Base class
}

public class Derived extends Base {
    // Derived class
}
```

### Interfaces
```java
public interface MyInterface {
    void method();  // Abstract method
}

public class MyClass implements MyInterface {
    public void method() {
        // Implementation
    }
}
```

### Exception Handling
```java
try {
    // Code that may throw exception
} catch (Exception e) {
    // Handle exception
} finally {
    // Always executes
}
```

---

## 📂 Repository Navigation

### By Topic

| Topic | C++ Location | Java Location |
|-------|--------------|---------------|
| **Basics** | [Lecture 01](OOP%20in%20C++/Lecture_01:%20An%20Overview%20of%20C++/) | [Chapter 1-2](OOP%20in%20Java/Chapter%201%20-%20Introduction%20to%20Computers,%20Programs,%20and%20Java/) |
| **Classes** | [Lecture 02-03](OOP%20in%20C++/Lecture_02:%20Introducing%20Classes/) | [Chapter 9](OOP%20in%20Java/Chapter%209%20-%20Objects%20and%20Classes/) |
| **Memory Management** | [Lecture 04](OOP%20in%20C++/Lecture_04:%20Arrays,%20Pointers,%20and%20References/) | N/A (Automatic) |
| **Overloading** | [Lecture 05-06](OOP%20in%20C++/Lecture_05:%20Function%20Overloading/) | [Chapter 6, 11](OOP%20in%20Java/Chapter%206%20-%20Methods/) |
| **Inheritance** | [Lecture 07](OOP%20in%20C++/Lecture_07:%20Inheritance/) | [Chapter 11](OOP%20in%20Java/Chapter%2011%20-%20Inheritance%20and%20Polymorphism/) |
| **I/O** | [Lecture 08-09](OOP%20in%20C++/Lecture_08:%20Introducing%20the%20C++%20IO%20System/) | [Chapter 12](OOP%20in%20Java/Chapter%2012%20-%20Exception%20Handling%20and%20Text%20I%20and%20O/) |
| **Polymorphism** | [Lecture 10](OOP%20in%20C++/Lecture_10:%20Virtual%20Functions/) | [Chapter 11](OOP%20in%20Java/Chapter%2011%20-%20Inheritance%20and%20Polymorphism/) |
| **Templates/Generics** | [Lecture 11, 14](OOP%20in%20C++/Lecture_11:%20Generic%20Functions/) | N/A (Built-in) |
| **Exceptions** | [Lecture 11](OOP%20in%20C++/Lecture_11:%20Generic%20Functions/) | [Chapter 12](OOP%20in%20Java/Chapter%2012%20-%20Exception%20Handling%20and%20Text%20I%20and%20O/) |
| **Abstract Classes** | [Lecture 10](OOP%20in%20C++/Lecture_10:%20Virtual%20Functions/) | [Chapter 13](OOP%20in%20Java/Chapter%2013%20-%20Abstract%20Classes%20and%20Interfaces/) |

### By Difficulty

- **Beginner**: Lectures 01-02, Chapters 1-4
- **Intermediate**: Lectures 03-07, Chapters 5-9
- **Advanced**: Lectures 08-14, Chapters 10-13

---

## 🛠️ Common Issues & Solutions

### C++ Issues

**Problem**: `undefined reference to...`
```bash
# Solution: Link all required files
g++ main.cpp class.cpp -o output
```

**Problem**: Memory leaks
```cpp
// Solution: Always delete allocated memory
int* ptr = new int(10);
delete ptr;  // Don't forget!
```

**Problem**: Segmentation fault
```cpp
// Solution: Check for null pointers
if (ptr != nullptr) {
    // Use pointer
}
```

### Java Issues

**Problem**: `Could not find or load main class`
```bash
# Solution: Ensure class name matches filename
javac ClassName.java
java ClassName  # Not ClassName.java
```

**Problem**: `NullPointerException`
```java
// Solution: Check for null
if (obj != null) {
    obj.method();
}
```

---

## 📝 Useful Documentation

### Repository Guides
- 📖 [Getting Started](GETTING_STARTED.md) - Setup and installation
- 🗺️ [Content Index](CONTENT_INDEX.md) - All materials catalog
- 🤝 [Contributing](CONTRIBUTING.md) - How to contribute
- 💬 [Support](SUPPORT.md) - Getting help
- 🔒 [Security](SECURITY.md) - Security policy

### External Resources

#### C++
- [cppreference.com](https://en.cppreference.com/) - Complete C++ reference
- [cplusplus.com](http://www.cplusplus.com/) - Tutorials and reference
- [LearnCpp.com](https://www.learncpp.com/) - Free tutorials

#### Java
- [Oracle Java Docs](https://docs.oracle.com/en/java/) - Official documentation
- [Java Tutorials](https://docs.oracle.com/javase/tutorial/) - Official tutorials
- [W3Schools Java](https://www.w3schools.com/java/) - Quick reference

#### General OOP
- [GeeksforGeeks](https://www.geeksforgeeks.org/) - Concepts and examples
- [Design Patterns](https://refactoring.guru/design-patterns) - Common patterns

---

## 🎓 Study Tips

1. **Start Sequential**: Begin with Lecture 1/Chapter 1
2. **Practice Daily**: Code along with examples
3. **Understand Don't Memorize**: Focus on concepts
4. **Debug Often**: Learn from errors
5. **Use Documentation**: Check guides when stuck
6. **Ask Questions**: Use [issue templates](.github/ISSUE_TEMPLATE/)
7. **Review Regularly**: Revisit earlier topics

---

## 🔍 Search Tips

### GitHub Search
- Find specific topics: `keyword in:path`
- Search code: `function_name language:cpp`
- Find files: `filename:*.cpp`

### In This Repo
- Use [Content Index](CONTENT_INDEX.md) for organized navigation
- Check folder README files for detailed info
- Use Ctrl+F to search within files

---

## 📊 Repository Statistics

- **C++ Programs**: 139+
- **Java Programs**: 17+
- **Documentation Files**: 80+
- **Lectures/Chapters**: 27
- **Topics Covered**: 50+

---

## ⚡ Quick Links

| Need | Link |
|------|------|
| Setup Help | [Getting Started](GETTING_STARTED.md) |
| Find Topic | [Content Index](CONTENT_INDEX.md) |
| Report Bug | [Bug Report](.github/ISSUE_TEMPLATE/bug_report.yml) |
| Ask Question | [Question Template](.github/ISSUE_TEMPLATE/question.yml) |
| Suggest Feature | [Feature Request](.github/ISSUE_TEMPLATE/feature_request.yml) |
| Get Support | [Support Guide](SUPPORT.md) |
| Contribute | [Contributing Guide](CONTRIBUTING.md) |

---

## 🎯 Common Tasks

### Setting Up Development Environment
1. Install compiler/JDK ([guide](GETTING_STARTED.md#installation))
2. Clone repository
3. Navigate to desired topic
4. Compile and run examples

### Studying a New Topic
1. Read topic's README.md
2. Review code examples
3. Understand concepts
4. Try practice problems
5. Test your understanding

### Getting Help
1. Check relevant documentation
2. Search existing issues
3. Ask in [discussions](https://github.com/M-F-Tushar/CSE-1201-Object-Oriented-Programming-Language/discussions)
4. Create an issue if needed

---

## 📱 Keep Learning

Remember:
- ✅ Make mistakes - they're learning opportunities
- ✅ Practice regularly - consistency is key
- ✅ Ask questions - no question is too small
- ✅ Help others - teaching reinforces learning
- ✅ Have fun - enjoy the journey!

---

**Happy Coding! 🚀**

*For detailed information, always refer to the complete documentation in the repository.*
