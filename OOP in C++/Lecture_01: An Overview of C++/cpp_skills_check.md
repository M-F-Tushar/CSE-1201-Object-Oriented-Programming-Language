# C++ Skills Check Solutions

## 1. Brief Descriptions of Core OOP Concepts

**Polymorphism**: The ability of objects of different types to respond to the same interface or function call in their own specific way. In C++, this is achieved through virtual functions and function overloading. For example, a `draw()` function can work differently for Circle, Rectangle, and Triangle objects.

**Encapsulation**: The bundling of data (variables) and methods (functions) that operate on that data into a single unit (class), while hiding internal implementation details from the outside world. This is achieved using access specifiers (private, protected, public).

**Inheritance**: A mechanism where a new class (derived class) can inherit properties and behaviors from an existing class (base class). This promotes code reuse and establishes "is-a" relationships between classes.

## 2. Including Comments in C++ Programs

C++ supports two types of comments:

- **Single-line comments**: Use `//` for comments that extend to the end of the line
  ```cpp
  int x = 5; // This is a single-line comment
  ```

- **Multi-line comments**: Use `/* */` for comments that span multiple lines
  ```cpp
  /* This is a multi-line comment
     that can span several lines
     and is useful for longer explanations */
  ```

## 3. Program to Calculate Power of Two Numbers

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int base, exponent;
    
    cout << "Enter the base number: ";
    cin >> base;
    
    cout << "Enter the exponent: ";
    cin >> exponent;
    
    // Using pow() function from cmath library
    double result = pow(base, exponent);
    
    cout << base << " raised to the power of " << exponent 
         << " is " << result << endl;
    
    return 0;
}
```

**Explanation**: This program uses C++-style I/O (`cin` and `cout`) to input two integers and uses the `pow()` function from `<cmath>` to calculate the power. The `pow()` function returns a double, so we store the result in a double variable.

## 4. Overloaded rev_str() Function

```cpp
#include <iostream>
#include <cstring>
using namespace std;

// Version 1: Single argument - reverses string in place
void rev_str(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len / 2; i++) {
        char temp = str[i];
        str[i] = str[len - 1 - i];
        str[len - 1 - i] = temp;
    }
}

// Version 2: Two arguments - original stays unchanged, reversed goes to second
void rev_str(char original[], char reversed[]) {
    int len = strlen(original);
    for (int i = 0; i < len; i++) {
        reversed[i] = original[len - 1 - i];
    }
    reversed[len] = '\0'; // Null terminate
}

int main() {
    char s1[80], s2[80];
    strcpy(s1, "hello");
    
    // Test two-argument version
    rev_str(s1, s2);
    cout << "Original: " << s1 << endl;
    cout << "Reversed: " << s2 << endl;
    
    // Test one-argument version
    rev_str(s1);
    cout << "s1 after in-place reversal: " << s1 << endl;
    
    return 0;
}
```

**Explanation**: Function overloading allows us to create two versions of `rev_str()` with different parameter lists. The compiler automatically chooses the correct version based on the number of arguments passed. The single-argument version modifies the original string, while the two-argument version preserves the original.

## 5. Converting New-Style to Old-Style C++

**Original new-style program**:
```cpp
#include <iostream>
using namespace std;

int f(int a);

int main() {
    cout << f(10);
    return 0;
}

int f(int a) {
    return a * 3.1416;
}
```

**Converted to old-style**:
```cpp
#include <iostream.h>

int f(int a);

int main() {
    cout << f(10);
    return 0;
}

int f(int a) {
    return a * 3.1416;
}
```

**Explanation**: The main differences are:
- Old-style uses `#include <iostream.h>` instead of `#include <iostream>`
- Old-style doesn't use `using namespace std;` because the standard namespace wasn't used in older C++ implementations
- The `cout` object was available directly without namespace qualification

## 6. The bool Data Type

The `bool` data type is a built-in C++ data type that can hold one of two values:
- `true` (typically represented as 1)
- `false` (typically represented as 0)

**Key characteristics**:
- Size: Usually 1 byte (8 bits), though this can vary by implementation
- Used for logical operations and conditions
- Automatically converts: non-zero values become `true`, zero becomes `false`
- When converted to integers: `true` becomes 1, `false` becomes 0

**Example usage**:
```cpp
bool isReady = true;
bool isComplete = false;

if (isReady && !isComplete) {
    cout << "Ready but not complete" << endl;
}

int x = 5;
bool isPositive = (x > 0); // true
```

The `bool` type makes code more readable and self-documenting compared to using integers for boolean logic.