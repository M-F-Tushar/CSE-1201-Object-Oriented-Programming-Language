# Chapter 4: Mathematical Functions, Characters, and Strings

## 4.1 Introduction

This chapter focuses on three fundamental programming concepts:
- **Mathematical functions** for performing common calculations
- **Character data type** for handling single characters
- **String objects** for working with text sequences

### Chapter Objectives
- Learn to use Java's built-in mathematical functions
- Understand character data type and Unicode encoding
- Master string manipulation and processing
- Apply these concepts to solve real-world problems

---

## 4.2 Common Mathematical Functions

Java's `Math` class provides numerous methods for mathematical operations. These methods are **static**, meaning you call them using `Math.methodName()` without creating an object.

### 4.2.1 Trigonometric Methods

| Method | Description | Example |
|--------|-------------|---------|
| `sin(radians)` | Trigonometric sine | `Math.sin(Math.PI/2)` → `1.0` |
| `cos(radians)` | Trigonometric cosine | `Math.cos(0)` → `1.0` |
| `tan(radians)` | Trigonometric tangent | `Math.tan(Math.PI/4)` → `1.0` |
| `toRadians(degrees)` | Convert degrees to radians | `Math.toRadians(90)` → `1.5708` |
| `toDegrees(radians)` | Convert radians to degrees | `Math.toDegrees(Math.PI/2)` → `90.0` |
| `asin(a)` | Inverse sine (arcsine) | `Math.asin(0.5)` → `0.5236` |
| `acos(a)` | Inverse cosine (arccosine) | `Math.acos(0.5)` → `1.0472` |
| `atan(a)` | Inverse tangent (arctangent) | `Math.atan(1.0)` → `0.7854` |

**Key Points:**
- All angle parameters are in **radians**
- Use `toRadians()` and `toDegrees()` for conversions
- Return values for inverse functions are in radians between -π/2 and π/2

### 4.2.2 Exponent Methods

| Method | Description | Example |
|--------|-------------|---------|
| `exp(x)` | Returns e^x | `Math.exp(1)` → `2.71828` |
| `log(x)` | Natural logarithm (ln x) | `Math.log(Math.E)` → `1.0` |
| `log10(x)` | Base-10 logarithm | `Math.log10(100)` → `2.0` |
| `pow(a, b)` | Returns a^b | `Math.pow(2, 3)` → `8.0` |
| `sqrt(x)` | Square root | `Math.sqrt(16)` → `4.0` |

### 4.2.3 Rounding Methods

| Method | Description | Behavior |
|--------|-------------|----------|
| `ceil(x)` | Round up to nearest integer | `Math.ceil(2.1)` → `3.0` |
| `floor(x)` | Round down to nearest integer | `Math.floor(2.9)` → `2.0` |
| `rint(x)` | Round to nearest even integer | `Math.rint(2.5)` → `2.0` |
| `round(x)` | Round to nearest integer | `Math.round(2.6f)` → `3` |

**Important Notes:**
- `ceil()`, `floor()`, and `rint()` return `double`
- `round()` returns `int` for `float` input, `long` for `double` input
- `rint()` uses "banker's rounding" (rounds to even number when exactly halfway)

### 4.2.4 Min, Max, and Absolute Value Methods

```java
Math.max(2, 3)      // Returns 3
Math.min(2.5, 4.6)  // Returns 2.5
Math.abs(-2.1)      // Returns 2.1
```

### 4.2.5 Random Number Generation

The `Math.random()` method generates a random `double` value: **0.0 ≤ value < 1.0**

**Common Patterns:**
```java
// Random integer between 0 and 9
(int)(Math.random() * 10)

// Random integer between 50 and 99
50 + (int)(Math.random() * 50)

// Random number between a and a+b (excluding a+b)
a + Math.random() * b
```

### 4.2.6 Case Study: Computing Angles of a Triangle

**Problem:** Given three points of a triangle, compute all three angles.

**Solution Steps:**
1. Calculate the three side lengths using distance formula
2. Apply law of cosines to find angles
3. Convert from radians to degrees

```java
// Distance formula: √((x2-x1)² + (y2-y1)²)
double a = Math.sqrt((x2-x3)*(x2-x3) + (y2-y3)*(y2-y3));

// Law of cosines: A = arccos((a²-b²-c²)/(-2bc))
double A = Math.toDegrees(Math.acos((a*a - b*b - c*c) / (-2*b*c)));
```

---

## 4.3 Character Data Type and Operations

### 4.3.1 Character Basics

The `char` data type represents a **single character**.

```java
char letter = 'A';      // Character literal
char digit = '4';       // Digit character
char symbol = '$';      // Symbol character
```

**Important:** 
- Character literals use **single quotes** (`'A'`)
- String literals use **double quotes** (`"Hello"`)

### 4.3.2 Unicode and ASCII Encoding

**Unicode:** Universal character encoding system
- Original 16-bit design: 65,536 characters
- Extended to support 1,112,064 characters
- Format: `\u` followed by 4 hexadecimal digits

**ASCII:** American Standard Code for Information Interchange
- 8-bit encoding (128 characters)
- Subset of Unicode (`\u0000` to `\u007F`)

| Characters | ASCII Range | Unicode Range |
|------------|-------------|---------------|
| '0' to '9' | 48 to 57 | \u0030 to \u0039 |
| 'A' to 'Z' | 65 to 90 | \u0041 to \u005A |
| 'a' to 'z' | 97 to 122 | \u0061 to \u007A |

**Examples:**
```java
char letter1 = 'A';
char letter2 = '\u0041';  // Same as 'A'
char ch = 'a';
System.out.println(++ch); // Displays 'b'
```

### 4.3.3 Escape Sequences

Special characters represented with backslash notation:

| Escape Sequence | Character | Unicode | Decimal |
|----------------|-----------|---------|---------|
| `\b` | Backspace | \u0008 | 8 |
| `\t` | Tab | \u0009 | 9 |
| `\n` | Newline | \u000A | 10 |
| `\r` | Carriage Return | \u000D | 13 |
| `\\` | Backslash | \u005C | 92 |
| `\"` | Double Quote | \u0022 | 34 |

**Examples:**
```java
System.out.println("He said \"Java is fun\"");
// Output: He said "Java is fun"

System.out.println("\\t is a tab character");
// Output: \t is a tab character
```

### 4.3.4 Character Casting and Arithmetic

**Casting Rules:**
- `char` can be cast to any numeric type
- Numeric types can be cast to `char`
- Only lower 16 bits are used when casting to `char`

```java
char ch = (char)65;        // ch becomes 'A'
int code = (int)'A';       // code becomes 65
char ch2 = (char)65.25;    // ch2 becomes 'A' (65)

// Arithmetic with characters
int result = '2' + '3';    // result = 101 (50 + 51)
int sum = 2 + 'a';         // sum = 99 (2 + 97)
```

### 4.3.5 Character Comparison and Testing

**Comparison:** Based on Unicode values
```java
'a' < 'b'  // true (97 < 98)
'a' < 'A'  // false (97 > 65)
'1' < '8'  // true (49 < 56)
```

**Character Testing Methods:**

| Method | Description | Example |
|--------|-------------|---------|
| `Character.isDigit(ch)` | Is digit (0-9)? | `Character.isDigit('5')` → `true` |
| `Character.isLetter(ch)` | Is letter? | `Character.isLetter('A')` → `true` |
| `Character.isLetterOrDigit(ch)` | Is letter or digit? | `Character.isLetterOrDigit('$')` → `false` |
| `Character.isLowerCase(ch)` | Is lowercase? | `Character.isLowerCase('a')` → `true` |
| `Character.isUpperCase(ch)` | Is uppercase? | `Character.isUpperCase('A')` → `true` |
| `Character.toLowerCase(ch)` | Convert to lowercase | `Character.toLowerCase('A')` → `'a'` |
| `Character.toUpperCase(ch)` | Convert to uppercase | `Character.toUpperCase('a')` → `'A'` |

---

## 4.4 The String Type

Strings represent sequences of characters and are **reference types** (objects), not primitives.

### 4.4.1 String Declaration and Basic Methods

```java
String message = "Welcome to Java";  // String literal
```

**Basic String Methods:**

| Method | Description | Example |
|--------|-------------|---------|
| `length()` | Returns string length | `"Hello".length()` → `5` |
| `charAt(index)` | Returns character at index | `"Hello".charAt(1)` → `'e'` |
| `concat(str)` | Concatenates strings | `"Hello".concat(" World")` → `"Hello World"` |
| `toUpperCase()` | Converts to uppercase | `"hello".toUpperCase()` → `"HELLO"` |
| `toLowerCase()` | Converts to lowercase | `"HELLO".toLowerCase()` → `"hello"` |
| `trim()` | Removes leading/trailing whitespace | `" Hello ".trim()` → `"Hello"` |

**Important Concepts:**
- **Instance methods:** Called on specific string objects (`message.length()`)
- **Static methods:** Called on class name (`Math.pow()`)
- String indexing starts at **0**
- Empty string: `""` has length 0

### 4.4.2 String Input

```java
Scanner input = new Scanner(System.in);

// Read single word (stops at whitespace)
String word = input.next();

// Read entire line (stops at Enter)
String line = input.nextLine();

// Read character (read line, get first character)
String s = input.nextLine();
char ch = s.charAt(0);
```

**Caution:** Don't use `nextLine()` after `nextInt()`, `nextDouble()`, etc.

### 4.4.3 String Concatenation

**Two ways to concatenate:**
```java
String s1 = "Hello";
String s2 = "World";

// Method 1: concat() method
String s3 = s1.concat(" " + s2);

// Method 2: + operator (preferred)
String s3 = s1 + " " + s2;

// Augmented assignment
s1 += " World";  // s1 becomes "Hello World"
```

**Mixed Type Concatenation:**
```java
String result = "Chapter " + 2;        // "Chapter 2"
String result2 = "Sum: " + (3 + 4);    // "Sum: 7"
String result3 = "Values: " + 3 + 4;   // "Values: 34"
```

### 4.4.4 String Comparison

**Never use `==` for string content comparison!**

| Method | Description | Example |
|--------|-------------|---------|
| `equals(str)` | Exact match | `"Java".equals("Java")` → `true` |
| `equalsIgnoreCase(str)` | Case-insensitive match | `"Java".equalsIgnoreCase("JAVA")` → `true` |
| `compareTo(str)` | Lexicographic comparison | `"abc".compareTo("abg")` → `-4` |
| `compareToIgnoreCase(str)` | Case-insensitive comparison | `"ABC".compareToIgnoreCase("abc")` → `0` |

**compareTo() Return Values:**
- `0`: Strings are equal
- `< 0`: First string is lexicographically smaller
- `> 0`: First string is lexicographically larger

### 4.4.5 String Search Methods

| Method | Description | Example |
|--------|-------------|---------|
| `startsWith(prefix)` | Starts with prefix? | `"Welcome".startsWith("Wel")` → `true` |
| `endsWith(suffix)` | Ends with suffix? | `"Welcome".endsWith("me")` → `true` |
| `contains(str)` | Contains substring? | `"Welcome".contains("com")` → `true` |

### 4.4.6 Finding Characters and Substrings

**indexOf Methods:**
```java
String str = "Welcome to Java";

str.indexOf('W')           // Returns 0 (first occurrence)
str.indexOf('o')           // Returns 4 (first 'o')
str.indexOf('o', 5)        // Returns 9 (first 'o' after index 5)
str.indexOf("come")        // Returns 3 (substring start index)
str.indexOf("java")        // Returns -1 (not found, case-sensitive)
```

**lastIndexOf Methods:**
```java
str.lastIndexOf('o')       // Returns 9 (last 'o')
str.lastIndexOf('o', 5)    // Returns 4 (last 'o' before index 5)
str.lastIndexOf("Java")    // Returns 11 (last occurrence)
```

### 4.4.7 Substring Operations

```java
String message = "Welcome to Java";

// From index to end
message.substring(11)      // Returns "Java"

// From beginIndex to endIndex-1
message.substring(0, 7)    // Returns "Welcome"
message.substring(8, 10)   // Returns "to"

// Extract first and last name
String fullName = "John Smith";
int spaceIndex = fullName.indexOf(' ');
String firstName = fullName.substring(0, spaceIndex);           // "John"
String lastName = fullName.substring(spaceIndex + 1);          // "Smith"
```

**Important:** `endIndex` is **exclusive** - the character at `endIndex` is not included.

### 4.4.8 String-Number Conversion

**String to Number:**
```java
// String to int
int value = Integer.parseInt("123");        // 123

// String to double
double value = Double.parseDouble("123.45"); // 123.45
```

**Number to String:**
```java
// Any number to string
String str = 123 + "";           // "123"
String str2 = 45.67 + "";        // "45.67"
```

---

## 4.5 Case Studies

### 4.5.1 Case Study: Guessing Birthdays

**The Magic:** Uses binary representation to determine birthday with 5 questions.

**How it works:**
- Each set represents a binary digit position
- Set1: 1st bit (value 1)
- Set2: 2nd bit (value 2)  
- Set3: 3rd bit (value 4)
- Set4: 4th bit (value 8)
- Set5: 5th bit (value 16)

**Example:** Birthday 19 = binary 10011
- Appears in Set1 (1), Set2 (2), and Set5 (16)
- Sum: 1 + 2 + 16 = 19

```java
String set1 = " 1  3  5  7\n 9 11 13 15\n17 19 21 23\n25 27 29 31";
// ... other sets

int day = 0;
if (userAnswersYesForSet1) day += 1;
if (userAnswersYesForSet2) day += 2;
if (userAnswersYesForSet3) day += 4;
if (userAnswersYesForSet4) day += 8;
if (userAnswersYesForSet5) day += 16;
```

### 4.5.2 Case Study: Hexadecimal to Decimal Conversion

**Problem:** Convert single hex digit to decimal value.

**Solution Approach:**
```java
char ch = hexString.charAt(0);

if (ch >= 'A' && ch <= 'F') {
    int value = ch - 'A' + 10;  // A=10, B=11, ..., F=15
} else if (Character.isDigit(ch)) {
    // For '0'-'9', the character itself represents the digit
    int value = ch - '0';
}
```

**Key Insight:** Character arithmetic using Unicode values
- `'A' - 'A' = 0`, so `'B' - 'A' = 1`, etc.
- Add 10 because A represents decimal 10

### 4.5.3 Case Study: Lottery Program with Strings

**Improvements over integer version:**
- Easier to extract individual digits
- Simpler comparison logic
- More readable code

```java
// Generate random two-digit lottery
String lottery = "" + (int)(Math.random() * 10) + (int)(Math.random() * 10);

// Extract digits
char lotteryDigit1 = lottery.charAt(0);
char lotteryDigit2 = lottery.charAt(1);
char guessDigit1 = guess.charAt(0);
char guessDigit2 = guess.charAt(1);

// Check conditions
if (guess.equals(lottery)) {
    // Exact match: $10,000
} else if (guessDigit1 == lotteryDigit2 && guessDigit2 == lotteryDigit1) {
    // All digits match: $3,000
} else if (/* one digit matches */) {
    // One digit match: $1,000
}
```

---

## 4.6 Formatting Console Output

The `printf()` method provides formatted output similar to C programming.

### 4.6.1 Basic Syntax

```java
System.out.printf(format, item1, item2, ..., itemk);
```

### 4.6.2 Format Specifiers

| Specifier | Type | Example Output |
|-----------|------|----------------|
| `%b` | Boolean | `true`, `false` |
| `%c` | Character | `'A'` |
| `%d` | Decimal integer | `200` |
| `%f` | Floating-point | `45.460000` |
| `%e` | Scientific notation | `4.556000e+01` |
| `%s` | String | `"Java is cool"` |

### 4.6.3 Width and Precision

**Format Pattern:** `%[flags][width][.precision]conversion`

```java
System.out.printf("%5d", 123);        // "  123" (width 5, right-aligned)
System.out.printf("%-5d", 123);       // "123  " (left-aligned)
System.out.printf("%10.2f", 45.678);  // "     45.68" (width 10, 2 decimal places)
System.out.printf("%.2f", 45.678);    // "45.68" (2 decimal places)
```

**Examples:**
```java
System.out.printf("%-10s%-10s%-10s\n", "Name", "Age", "Salary");
System.out.printf("%-10s%-10d%-10.2f\n", "John", 25, 50000.00);
```

Output:
```
Name      Age       Salary    
John      25        50000.00  
```

---

## Practice Problems and Solutions

### Check Point 4.1: Method Evaluations

**(a)** `Math.sqrt(4)` → `2.0`
**(b)** `Math.sin(2 * Math.PI)` → `0.0` (approximately)
**(c)** `Math.cos(2 * Math.PI)` → `1.0`
**(d)** `Math.pow(2, 2)` → `4.0`
**(e)** `Math.log(Math.E)` → `1.0`
**(f)** `Math.exp(1)` → `2.71828` (approximately)
**(g)** `Math.max(2, Math.min(3, 4))` → `Math.max(2, 3)` → `3`
**(h)** `Math.rint(-2.5)` → `-2.0` (rounds to even)
**(i)** `Math.ceil(-2.5)` → `-2.0`
**(j)** `Math.floor(-2.5)` → `-3.0`
**(k)** `Math.round(-2.5f)` → `-2` (int)
**(l)** `Math.round(-2.5)` → `-2` (long)
**(m)** `Math.rint(2.5)` → `2.0` (rounds to even)
**(n)** `Math.ceil(2.5)` → `3.0`
**(o)** `Math.floor(2.5)` → `2.0`
**(p)** `Math.round(2.5f)` → `3` (int)
**(q)** `Math.round(2.5)` → `3` (long)
**(r)** `Math.round(Math.abs(-2.5))` → `Math.round(2.5)` → `3`

### Check Point 4.2-4.7: Quick Answers

**4.2** True - trigonometric methods use radians
**4.3** `double radians = Math.toRadians(47);`
**4.4** `double degrees = Math.toDegrees(Math.PI / 7);`
**4.5** 
- Between 34-55: `34 + (int)(Math.random() * 22)`
- Between 0-999: `(int)(Math.random() * 1000)`
- Between 5.5-55.5: `5.5 + Math.random() * 50`

**4.6** Math class is in `java.lang` package, which is automatically imported
**4.7** 
- `Math.log(Math.exp(5.5))` → `5.5`
- `Math.exp(Math.log(5.5))` → `5.5`
- `Math.asin(Math.sin(Math.PI/6))` → `Math.PI/6`
- `Math.sin(Math.asin(Math.PI/6))` → Error (Math.PI/6 > 1)

### Character Exercises (4.8-4.15)

**4.11 Evaluation:**
```java
int i = '1';        // i = 49 (Unicode of '1')
int j = '1' + '2' * ('4' - '3') + 'b' / 'a';
// j = 49 + 50 * 1 + 98/97 = 49 + 50 + 1 = 100
int k = 'a';        // k = 97
char c = 90;        // c = 'Z'
```

**4.13 Program Output:**
```java
char x = 'a';  // x = 'a'
char y = 'c';  // y = 'c'
System.out.println(++x);    // Prints 'b' (x becomes 'b')
System.out.println(y++);    // Prints 'c' (y becomes 'd' after)
System.out.println(x - y);  // Prints -2 ('b'=98, 'd'=100, 98-100=-2)
```

**4.14 Random lowercase letter:**
```java
char randomLetter = (char)('a' + Math.random() * 26);
```

**4.15 Comparison outputs:**
```java
System.out.println('a' < 'b');   // true
System.out.println('a' <= 'A');  // false
System.out.println('a' > 'b');   // false  
System.out.println('a' >= 'A');  // true
System.out.println('a' == 'a');  // true
System.out.println('a' != 'b');  // true
```

### String Exercises (4.16-4.20)

**4.16 String Operations:**
Given:
```java
String s1 = "Welcome to Java";
String s2 = "Programming is fun";
String s3 = "Welcome to Java";
```

**(a)** `s1 == s2` → `false` (different objects)
**(b)** `s2 == s3` → `false` (different objects)
**(c)** `s1.equals(s2)` → `false` (different content)
**(d)** `s1.equals(s3)` → `true` (same content)
**(e)** `s1.compareTo(s2)` → `7` (positive, 'W' > 'P')
**(f)** `s2.compareTo(s3)` → `-7` (negative, 'P' < 'W')
**(g)** `s2.compareTo(s2)` → `0` (equal)
**(h)** `s1.charAt(0)` → `'W'`
**(i)** `s1.indexOf('j')` → `-1` (not found, case-sensitive)
**(j)** `s1.indexOf("to")` → `8`
**(k)** `s1.lastIndexOf('a')` → `14`
**(l)** `s1.lastIndexOf("o", 15)` → `9`
**(m)** `s1.length()` → `15`
**(n)** `s1.substring(5)` → `"me to Java"`
**(o)** `s1.substring(5, 11)` → `"me to "`
**(p)** `s1.startsWith("Wel")` → `true`
**(q)** `s1.endsWith("Java")` → `true`
**(r)** `s1.toLowerCase()` → `"welcome to java"`
**(s)** `s1.toUpperCase()` → `"WELCOME TO JAVA"`
**(t)** `s1.concat(s2)` → `"Welcome to JavaProgramming is fun"`
**(u)** `s1.contains(s2)` → `false`
**(v)** `"\t Wel \t".trim()` → `"Wel"`

**4.18 Output Analysis:**
```java
System.out.println("1" + 1);       // "11" (string concatenation)
System.out.println('1' + 1);       // 50 (49 + 1, character arithmetic)
System.out.println("1" + 1 + 1);   // "111" (left-to-right concatenation)
System.out.println("1" + (1 + 1)); // "12" (parentheses force addition)
System.out.println('1' + 1 + 1);   // 51 (49 + 1 + 1, all arithmetic)
```

**4.19 Expression Evaluation:**
```java
1 + "Welcome " + 1 + 1           // "1Welcome 11"
1 + "Welcome " + (1 + 1)         // "1Welcome 2"
1 + "Welcome " + ('\u0001' + 1)  // "1Welcome 2"
1 + "Welcome " + 'a' + 1         // "1Welcome a1"
```

---

## Programming Exercises

### Exercise 4.1: Pentagon Area
```java
import java.util.Scanner;

public class PentagonArea {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the length from center to vertex: ");
        double r = input.nextDouble();
        
        // Calculate side length: s = 2r * sin(π/5)
        double s = 2 * r * Math.sin(Math.PI / 5);
        
        // Calculate area: Area = (5 * s²) / (4 * tan(π/5))
        double area = (5 * s * s) / (4 * Math.tan(Math.PI / 5));
        
        System.out.printf("The area of the pentagon is %.2f\n", area);
    }
}
```

### Exercise 4.2: Great Circle Distance
```java
import java.util.Scanner;

public class GreatCircleDistance {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter point 1 (latitude and longitude) in degrees: ");
        double x1 = Math.toRadians(input.nextDouble());
        double y1 = Math.toRadians(input.nextDouble());
        
        System.out.print("Enter point 2 (latitude and longitude) in degrees: ");
        double x2 = Math.toRadians(input.nextDouble());
        double y2 = Math.toRadians(input.nextDouble());
        
        // Great circle distance formula
        double distance = 6371.01 * Math.acos(
            Math.sin(x1) * Math.sin(x2) + 
            Math.cos(x1) * Math.cos(x2) * Math.cos(y1 - y2)
        );
        
        System.out.println("The distance between the two points is " + distance + " km");
    }
}
```

### Exercise 4.8: ASCII Code to Character
```java
import java.util.Scanner;

public class ASCIIToChar {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter an ASCII code: ");
        int ascii = input.nextInt();
        
        if (ascii >= 0 && ascii <= 127) {
            char character = (char) ascii;
            System.out.println("The character for ASCII code " + ascii + " is " + character);
        } else {
            System.out.println("Invalid ASCII code. Must be between 0 and 127.");
        }
    }
}
```

### Exercise 4.13: Vowel or Consonant
```java
import java.util.Scanner;

public class VowelConsonant {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a letter: ");
        String s = input.nextLine();
        
        if (s.length() != 1) {
            System.out.println("Please enter exactly one character");
            return;
        }
        
        char ch = Character.toLowerCase(s.charAt(0));
        
        if (Character.isLetter(ch)) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                System.out.println(s.charAt(0) + " is a vowel");
            } else {
                System.out.println(s.charAt(0) + " is a consonant");
            }
        } else {
            System.out.println(s.charAt(0) + " is an invalid input");
        }
    }
}
```

### Exercise 4.15: Phone Key Pads
```java
import java.util.Scanner;

public class PhoneKeyPad {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a letter: ");
        String s = input.nextLine();
        
        if (s.length() != 1) {
            System.out.println("Please enter exactly one character");
            return;
        }
        
        char ch = Character.toUpperCase(s.charAt(0));
        
        if (ch >= 'A' && ch <= 'C') {
            System.out.println("The corresponding number is 2");
        } else if (ch >= 'D' && ch <= 'F') {
            System.out.println("The corresponding number is 3");
        } else if (ch >= 'G' && ch <= 'I') {
            System.out.println("The corresponding number is 4");
        } else if (ch >= 'J' && ch <= 'L') {
            System.out.println("The corresponding number is 5");
        } else if (ch >= 'M' && ch <= 'O') {
            System.out.println("The corresponding number is 6");
        } else if (ch >= 'P' && ch <= 'S') {
            System.out.println("The corresponding number is 7");
        } else if (ch >= 'T' && ch <= 'V') {
            System.out.println("The corresponding number is 8");
        } else if (ch >= 'W' && ch <= 'Z') {
            System.out.println("The corresponding number is 9");
        } else {
            System.out.println(ch + " is an invalid input");
        }
    }
}
```

### Exercise 4.21: Check SSN Format
```java
import java.util.Scanner;

public class CheckSSN {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a SSN: ");
        String ssn = input.nextLine();
        
        // Check if length is correct (11 characters: DDD-DD-DDDD)
        if (ssn.length() != 11) {
            System.out.println(ssn + " is an invalid social security number");
            return;
        }
        
        // Check format: positions 3 and 6 should be dashes
        if (ssn.charAt(3) != '-' || ssn.charAt(6) != '-') {
            System.out.println(ssn + " is an invalid social security number");
            return;
        }
        
        // Check that all other positions are digits
        boolean isValid = true;
        for (int i = 0; i < ssn.length(); i++) {
            if (i == 3 || i == 6) continue; // Skip dash positions
            if (!Character.isDigit(ssn.charAt(i))) {
                isValid = false;
                break;
            }
        }
        
        if (isValid) {
            System.out.println(ssn + " is a valid social security number");
        } else {
            System.out.println(ssn + " is an invalid social security number");
        }
    }
}
```

### Exercise 4.23: Payroll Statement
```java
import java.util.Scanner;

public class PayrollStatement {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter employee's name: ");
        String name = input.nextLine();
        
        System.out.print("Enter number of hours worked in a week: ");
        double hours = input.nextDouble();
        
        System.out.print("Enter hourly pay rate: ");
        double payRate = input.nextDouble();
        
        System.out.print("Enter federal tax withholding rate: ");
        double federalRate = input.nextDouble();
        
        System.out.print("Enter state tax withholding rate: ");
        double stateRate = input.nextDouble();
        
        // Calculations
        double grossPay = hours * payRate;
        double federalWithholding = grossPay * federalRate;
        double stateWithholding = grossPay * stateRate;
        double totalDeduction = federalWithholding + stateWithholding;
        double netPay = grossPay - totalDeduction;
        
        // Display payroll statement
        System.out.println("Employee Name: " + name);
        System.out.printf("Hours Worked: %.1f\n", hours);
        System.out.printf("Pay Rate: $%.2f\n", payRate);
        System.out.printf("Gross Pay: $%.2f\n", grossPay);
        System.out.println("Deductions:");
        System.out.printf("  Federal Withholding (%.1f%%): $%.2f\n", 
                         federalRate * 100, federalWithholding);
        System.out.printf("  State Withholding (%.1f%%): $%.2f\n", 
                         stateRate * 100, stateWithholding);
        System.out.printf("  Total Deduction: $%.2f\n", totalDeduction);
        System.out.printf("Net Pay: $%.2f\n", netPay);
    }
}
```

### Exercise 4.24: Order Three Cities
```java
import java.util.Scanner;

public class OrderThreeCities {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter the first city: ");
        String city1 = input.nextLine();
        
        System.out.print("Enter the second city: ");
        String city2 = input.nextLine();
        
        System.out.print("Enter the third city: ");
        String city3 = input.nextLine();
        
        // Sort the cities alphabetically
        String first, second, third;
        
        if (city1.compareTo(city2) <= 0 && city1.compareTo(city3) <= 0) {
            // city1 is smallest
            first = city1;
            if (city2.compareTo(city3) <= 0) {
                second = city2;
                third = city3;
            } else {
                second = city3;
                third = city2;
            }
        } else if (city2.compareTo(city1) <= 0 && city2.compareTo(city3) <= 0) {
            // city2 is smallest
            first = city2;
            if (city1.compareTo(city3) <= 0) {
                second = city1;
                third = city3;
            } else {
                second = city3;
                third = city1;
            }
        } else {
            // city3 is smallest
            first = city3;
            if (city1.compareTo(city2) <= 0) {
                second = city1;
                third = city2;
            } else {
                second = city2;
                third = city1;
            }
        }
        
        System.out.println("The three cities in alphabetical order are " + 
                          first + " " + second + " " + third);
    }
}
```

### Exercise 4.25: Generate Vehicle Plate Numbers
```java
public class GenerateVehiclePlate {
    public static void main(String[] args) {
        // Generate three uppercase letters
        String plateNumber = "";
        
        for (int i = 0; i < 3; i++) {
            char letter = (char)('A' + Math.random() * 26);
            plateNumber += letter;
        }
        
        // Generate four digits
        for (int i = 0; i < 4; i++) {
            int digit = (int)(Math.random() * 10);
            plateNumber += digit;
        }
        
        System.out.println("Generated vehicle plate number: " + plateNumber);
    }
}
```

### Exercise 4.26: Compute Change (Fixed Version)
```java
import java.util.Scanner;

public class ComputeChangeFixed {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the amount as a string (e.g., 11.56): ");
        String amount = input.nextLine();
        
        // Find the decimal point
        int decimalIndex = amount.indexOf('.');
        
        if (decimalIndex == -1) {
            // No decimal point, assume whole dollars
            int dollars = Integer.parseInt(amount);
            int cents = 0;
            
            System.out.println("Your amount " + dollars + " dollars consists of:");
            System.out.println(dollars + " dollars");
            System.out.println("0 quarters");
            System.out.println("0 dimes");
            System.out.println("0 nickels");
            System.out.println("0 pennies");
        } else {
            // Extract dollars and cents
            String dollarPart = amount.substring(0, decimalIndex);
            String centPart = amount.substring(decimalIndex + 1);
            
            int dollars = Integer.parseInt(dollarPart);
            int cents = Integer.parseInt(centPart);
            
            // Calculate change breakdown
            int quarters = cents / 25;
            cents = cents % 25;
            
            int dimes = cents / 10;
            cents = cents % 10;
            
            int nickels = cents / 5;
            cents = cents % 5;
            
            int pennies = cents;
            
            System.out.println("Your amount " + amount + " consists of:");
            System.out.println(dollars + " dollars");
            System.out.println(quarters + " quarters");
            System.out.println(dimes + " dimes");
            System.out.println(nickels + " nickels");
            System.out.println(pennies + " pennies");
        }
    }
}
```

---

## Summary and Key Takeaways

### Mathematical Functions
- **Math class** provides static methods for mathematical operations
- **Trigonometric methods** work with radians, not degrees
- **Rounding methods** have different behaviors: `ceil()`, `floor()`, `rint()`, `round()`
- **Random numbers** can be generated in any range using `Math.random()`

### Characters
- **char type** represents single characters using Unicode
- **Escape sequences** represent special characters (`\n`, `\t`, `\"`, etc.)
- **Character arithmetic** uses Unicode values
- **Character class** provides useful testing and conversion methods

### Strings
- **Strings are objects**, not primitives
- **String comparison** should use `equals()` and `compareTo()`, never `==`
- **String methods** are instance methods called on string objects
- **String concatenation** can use `+` operator or `concat()` method
- **Substring operations** use zero-based indexing
- **String-number conversion** uses `Integer.parseInt()` and concatenation

### Formatting
- **printf()** provides formatted output with format specifiers
- **Width and precision** can be specified for alignment and decimal places
- **Left/right justification** controlled by minus flag

### Programming Best Practices
1. **Use appropriate data types** for different kinds of data
2. **Handle edge cases** in input validation
3. **Use meaningful variable names** and comments
4. **Test programs** with various inputs
5. **Follow consistent formatting** for readability

This comprehensive guide covers all concepts, examples, and exercises from Chapter 4, providing a solid foundation for understanding mathematical functions, characters, and strings in Java programming.
