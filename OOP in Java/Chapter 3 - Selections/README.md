# Java Chapter 3: Selections - Complete Study Guide

## Table of Contents
1. [Introduction to Selection Statements](#1-introduction)
2. [Boolean Data Type](#2-boolean-data-type)
3. [If Statements](#3-if-statements)
4. [Two-Way if-else Statements](#4-two-way-if-else-statements)
5. [Nested if and Multi-Way if-else Statements](#5-nested-if-and-multi-way-if-else-statements)
6. [Common Errors and Pitfalls](#6-common-errors-and-pitfalls)
7. [Generating Random Numbers](#7-generating-random-numbers)
8. [Case Study: Computing Body Mass Index](#8-case-study-computing-body-mass-index)
9. [Case Study: Computing Taxes](#9-case-study-computing-taxes)
10. [Logical Operators](#10-logical-operators)
11. [Case Study: Determining Leap Year](#11-case-study-determining-leap-year)
12. [Case Study: Lottery](#12-case-study-lottery)
13. [Switch Statements](#13-switch-statements)
14. [Conditional Expressions](#14-conditional-expressions)
15. [Operator Precedence and Associativity](#15-operator-precedence-and-associativity)
16. [Debugging](#16-debugging)
17. [Practice Exercises](#17-practice-exercises)

---

## 1. Introduction to Selection Statements

### What are Selection Statements?
Selection statements allow programs to make decisions and execute different code paths based on conditions. They solve the problem of handling different scenarios in your program.

### Problem Example
Consider a program that calculates the area of a circle. What happens if the user enters a negative radius?
```java
// Without selection statements - produces invalid results
double radius = -5;
double area = radius * radius * 3.14159; // Results in positive area!
```

### Solution with Selection Statements
```java
if (radius < 0) {
    System.out.println("Incorrect input");
} else {
    area = radius * radius * 3.14159;
    System.out.println("Area is " + area);
}
```

### Key Concepts
- **Selection Statements**: Code structures that choose which statements to execute
- **Boolean Expression**: An expression that evaluates to either `true` or `false`
- **Condition**: A Boolean expression used to make decisions

---

## 2. Boolean Data Type

### Understanding Boolean Type
The `boolean` data type can store only two values: `true` or `false`.

### Declaration and Assignment
```java
boolean lightsOn = true;
boolean isRaining = false;
```

### Relational Operators
These operators compare two values and return a boolean result:

| Operator | Symbol | Name | Example (radius = 5) | Result |
|----------|--------|------|---------------------|--------|
| `<` | < | less than | `radius < 0` | `false` |
| `<=` | ≤ | less than or equal to | `radius <= 0` | `false` |
| `>` | > | greater than | `radius > 0` | `true` |
| `>=` | ≥ | greater than or equal to | `radius >= 0` | `true` |
| `==` | = | equal to | `radius == 0` | `false` |
| `!=` | ≠ | not equal to | `radius != 0` | `true` |

### Important Note
⚠️ **Common Mistake**: Don't confuse `==` (comparison) with `=` (assignment)
- `==` compares two values
- `=` assigns a value to a variable

### Example Program
```java
double radius = 1;
System.out.println(radius > 0); // Outputs: true
```

---

## 3. If Statements

### One-Way if Statement
Executes code only if the condition is true.

#### Syntax
```java
if (boolean-expression) {
    statement(s);
}
```

#### Flowchart Logic
```
[Start] → [Check Condition] → [True?] → [Execute Statements] → [End]
                                ↓
                              [False] → [Skip Statements] → [End]
```

#### Example: SimpleIfDemo.java
```java
import java.util.Scanner;

public class SimpleIfDemo {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter an integer: ");
        int number = input.nextInt();

        if (number % 5 == 0)
            System.out.println("HiFive");

        if (number % 2 == 0)
            System.out.println("HiEven");
    }
}
```

**Sample Runs:**
- Input: 4 → Output: "HiEven"
- Input: 30 → Output: "HiFive" and "HiEven"

#### Braces Rules
- Braces `{}` are optional for single statements
- **Best Practice**: Always use braces to avoid errors

```java
// Without braces (risky)
if (number % 2 == 0)
    System.out.println("Even");

// With braces (recommended)
if (number % 2 == 0) {
    System.out.println("Even");
}
```

---

## 4. Two-Way if-else Statements

### Purpose
Executes one set of statements if condition is true, another set if false.

#### Syntax
```java
if (boolean-expression) {
    statement(s)-for-true-case;
} else {
    statement(s)-for-false-case;
}
```

#### Flowchart Logic
```
[Start] → [Check Condition] → [True?] → [Execute True Statements] → [End]
                                ↓
                              [False] → [Execute False Statements] → [End]
```

#### Example: Even or Odd
```java
if (number % 2 == 0) {
    System.out.println(number + " is even.");
} else {
    System.out.println(number + " is odd.");
}
```

#### Practical Example: Radius Validation
```java
if (radius >= 0) {
    area = radius * radius * PI;
    System.out.println("The area for the circle of radius " + radius + " is " + area);
} else {
    System.out.println("Negative input");
}
```

---

## 5. Nested if and Multi-Way if-else Statements

### Nested if Statements
An if statement can contain another if statement.

#### Example: Nested Structure
```java
if (i > k) {
    if (j > k) {
        System.out.println("i and j are greater than k");
    }
} else {
    System.out.println("i is less than or equal to k");
}
```

### Multi-Way if-else Statements
Used for multiple alternative conditions.

#### Grade Assignment Example
```java
// Less preferred format (deeply nested)
if (score >= 90.0) {
    System.out.print("A");
} else {
    if (score >= 80.0) {
        System.out.print("B");
    } else {
        if (score >= 70.0) {
            System.out.print("C");
        } else {
            if (score >= 60.0) {
                System.out.print("D");
            } else {
                System.out.print("F");
            }
        }
    }
}

// Preferred format (multi-way if-else)
if (score >= 90.0)
    System.out.print("A");
else if (score >= 80.0)
    System.out.print("B");
else if (score >= 70.0)
    System.out.print("C");
else if (score >= 60.0)
    System.out.print("D");
else
    System.out.print("F");
```

#### Execution Flow
1. Check first condition (`score >= 90.0`)
2. If false, check next condition (`score >= 80.0`)
3. Continue until a condition is true or reach the `else`
4. Execute corresponding statement and exit

---

## 6. Common Errors and Pitfalls

### Common Error 1: Forgetting Necessary Braces
```java
// Wrong - only first statement is in if block
if (radius >= 0)
    area = radius * radius * PI;
    System.out.println("The area is " + area); // Always executes!

// Correct - both statements in if block
if (radius >= 0) {
    area = radius * radius * PI;
    System.out.println("The area is " + area);
}
```

### Common Error 2: Wrong Semicolon at if Line
```java
// Wrong - creates empty if statement
if (radius >= 0); {  // Semicolon creates empty block
    area = radius * radius * PI;  // Always executes
}

// Correct
if (radius >= 0) {
    area = radius * radius * PI;
}
```

### Common Error 3: Redundant Testing of Boolean Values
```java
// Poor style
if (even == true)
    System.out.println("It is even.");

// Better style
if (even)
    System.out.println("It is even.");

// Dangerous mistake (using = instead of ==)
if (even = true)  // This assigns true to even!
    System.out.println("It is even.");
```

### Common Error 4: Dangling else Ambiguity
```java
// Confusing indentation
int i = 1, j = 2, k = 3;
if (i > j)
    if (i > k)
        System.out.println("A");
else
    System.out.println("B");  // Which if does this else belong to?

// The else actually belongs to the second if
int i = 1, j = 2, k = 3;
if (i > j)
    if (i > k)
        System.out.println("A");
    else
        System.out.println("B");  // Belongs to second if

// To force else to match first if, use braces
if (i > j) {
    if (i > k)
        System.out.println("A");
} else {
    System.out.println("B");  // Now belongs to first if
}
```

### Common Error 5: Equality Test of Floating-Point Values
```java
// Unreliable due to floating-point precision
double x = 1.0 - 0.1 - 0.1 - 0.1 - 0.1 - 0.1;
System.out.println(x == 0.5); // Displays false!

// Correct approach - test if values are close enough
final double EPSILON = 1E-14;
double x = 1.0 - 0.1 - 0.1 - 0.1 - 0.1 - 0.1;
if (Math.abs(x - 0.5) < EPSILON)
    System.out.println(x + " is approximately 0.5");
```

### Common Pitfall 1: Simplifying Boolean Variable Assignment
```java
// Unnecessarily verbose
if (number % 2 == 0)
    even = true;
else
    even = false;

// Better - direct assignment
boolean even = number % 2 == 0;
```

### Common Pitfall 2: Avoiding Duplicate Code
```java
// Code duplication
if (inState) {
    tuition = 5000;
    System.out.println("The tuition is " + tuition);
} else {
    tuition = 15000;
    System.out.println("The tuition is " + tuition);
}

// Better - eliminate duplication
if (inState) {
    tuition = 5000;
} else {
    tuition = 15000;
}
System.out.println("The tuition is " + tuition);
```

---

## 7. Generating Random Numbers

### Math.random() Method
- Returns a random `double` value: `0.0 ≤ value < 1.0`
- Better than using `System.currentTimeMillis()`

#### Generating Random Integers
```java
// Generate random single-digit integer (0-9)
int digit = (int)(Math.random() * 10);

// Generate random integer in range [min, max]
int randomInRange = (int)(Math.random() * (max - min + 1)) + min;
```

### Example: SubtractionQuiz.java
```java
import java.util.Scanner;

public class SubtractionQuiz {
    public static void main(String[] args) {
        // 1. Generate two random single-digit integers
        int number1 = (int)(Math.random() * 10);
        int number2 = (int)(Math.random() * 10);

        // 2. If number1 < number2, swap them
        if (number1 < number2) {
            int temp = number1;
            number1 = number2;
            number2 = temp;
        }

        // 3. Ask question
        System.out.print("What is " + number1 + " - " + number2 + "? ");
        Scanner input = new Scanner(System.in);
        int answer = input.nextInt();

        // 4. Check answer
        if (number1 - number2 == answer) {
            System.out.println("You are correct!");
        } else {
            System.out.println("Your answer is wrong.");
            System.out.println(number1 + " - " + number2 + " should be " + (number1 - number2));
        }
    }
}
```

**Sample Runs:**
- Input: `What is 6 - 6? 0` → Output: "You are correct!"
- Input: `What is 9 - 2? 5` → Output: "Your answer is wrong. 9 - 2 should be 7"

---

## 8. Case Study: Computing Body Mass Index

### Problem Statement
Calculate and interpret BMI based on weight and height.

#### BMI Formula
```
BMI = weight (kg) / height² (m²)
```

#### BMI Categories
| BMI Range | Interpretation |
|-----------|----------------|
| BMI < 18.5 | Underweight |
| 18.5 ≤ BMI < 25.0 | Normal |
| 25.0 ≤ BMI < 30.0 | Overweight |
| 30.0 ≤ BMI | Obese |

### Complete Program: ComputeAndInterpretBMI.java
```java
import java.util.Scanner;

public class ComputeAndInterpretBMI {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Input
        System.out.print("Enter weight in pounds: ");
        double weight = input.nextDouble();
        
        System.out.print("Enter height in inches: ");
        double height = input.nextDouble();

        // Constants for conversion
        final double KILOGRAMS_PER_POUND = 0.45359237;
        final double METERS_PER_INCH = 0.0254;

        // Convert and compute BMI
        double weightInKilograms = weight * KILOGRAMS_PER_POUND;
        double heightInMeters = height * METERS_PER_INCH;
        double bmi = weightInKilograms / (heightInMeters * heightInMeters);

        // Display result and interpretation
        System.out.println("BMI is " + bmi);
        if (bmi < 18.5)
            System.out.println("Underweight");
        else if (bmi < 25)
            System.out.println("Normal");
        else if (bmi < 30)
            System.out.println("Overweight");
        else
            System.out.println("Obese");
    }
}
```

**Sample Run:**
```
Enter weight in pounds: 146
Enter height in inches: 70
BMI is 20.948603801493316
Normal
```

---

## 9. Case Study: Computing Taxes

### Problem Description
Calculate US federal income tax based on filing status and taxable income.

#### 2009 Tax Brackets (Single Filers)
| Tax Rate | Income Range |
|----------|--------------|
| 10% | $0 - $8,350 |
| 15% | $8,351 - $33,950 |
| 25% | $33,951 - $82,250 |
| 28% | $82,251 - $171,550 |
| 33% | $171,551 - $372,950 |
| 35% | $372,951+ |

### Tax Calculation Logic
For income of $400,000:
- First $8,350 taxed at 10%
- Next $25,600 taxed at 15%
- Next $48,300 taxed at 25%
- And so on...

### Complete Program: ComputeTax.java
```java
import java.util.Scanner;

public class ComputeTax {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);

        // Input filing status
        System.out.print("(0-single filer, 1-married jointly or " +
            "qualifying widow(er), 2-married separately, 3-head of " +
            "household) Enter the filing status: ");
        int status = input.nextInt();

        // Input taxable income
        System.out.print("Enter the taxable income: ");
        double income = input.nextDouble();

        // Compute tax
        double tax = 0;

        if (status == 0) { // Single filers
            if (income <= 8350)
                tax = income * 0.10;
            else if (income <= 33950)
                tax = 8350 * 0.10 + (income - 8350) * 0.15;
            else if (income <= 82250)
                tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + 
                      (income - 33950) * 0.25;
            else if (income <= 171550)
                tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + 
                      (82250 - 33950) * 0.25 + (income - 82250) * 0.28;
            else if (income <= 372950)
                tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + 
                      (82250 - 33950) * 0.25 + (171550 - 82250) * 0.28 + 
                      (income - 171550) * 0.33;
            else
                tax = 8350 * 0.10 + (33950 - 8350) * 0.15 + 
                      (82250 - 33950) * 0.25 + (171550 - 82250) * 0.28 + 
                      (372950 - 171550) * 0.33 + (income - 372950) * 0.35;
        }
        else if (status == 1) {
            // Married filing jointly (implementation needed)
        }
        else if (status == 2) {
            // Married filing separately (implementation needed)
        }
        else if (status == 3) {
            // Head of household (implementation needed)
        }
        else {
            System.out.println("Error: invalid status");
            System.exit(1);
        }

        // Display result
        System.out.println("Tax is " + (int)(tax * 100) / 100.0);
    }
}
```

**Sample Run:**
```
Enter the filing status: 0
Enter the taxable income: 400000
Tax is 117683.5
```

---

## 10. Logical Operators

### Boolean Operators
Combine multiple boolean expressions into compound expressions.

| Operator | Name | Description |
|----------|------|-------------|
| `!` | NOT | Logical negation |
| `&&` | AND | Logical conjunction |
| `\|\|` | OR | Logical disjunction |
| `^` | XOR | Exclusive OR |

### Truth Tables

#### NOT Operator (!)
| p | !p |
|---|-----|
| true | false |
| false | true |

**Example:** `!(age > 18)` is `false` if age is 24

#### AND Operator (&&)
| p1 | p2 | p1 && p2 |
|----|----|---------:|
| false | false | false |
| false | true | false |
| true | false | false |
| true | true | true |

**Example:** `(age > 18) && (weight >= 140)` requires both conditions to be true

#### OR Operator (||)
| p1 | p2 | p1 \|\| p2 |
|----|----|---------:|
| false | false | false |
| false | true | true |
| true | false | true |
| true | true | true |

**Example:** `(age > 18) || (weight < 140)` requires at least one condition to be true

#### XOR Operator (^)
| p1 | p2 | p1 ^ p2 |
|----|----|---------:|
| false | false | false |
| false | true | true |
| true | false | true |
| true | true | false |

**Example:** `(age > 34) ^ (weight >= 140)` requires exactly one condition to be true

### Example Program: TestBooleanOperators.java
```java
import java.util.Scanner;

public class TestBooleanOperators {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter an integer: ");
        int number = input.nextInt();

        if (number % 2 == 0 && number % 3 == 0)
            System.out.println(number + " is divisible by 2 and 3.");

        if (number % 2 == 0 || number % 3 == 0)
            System.out.println(number + " is divisible by 2 or 3.");

        if (number % 2 == 0 ^ number % 3 == 0)
            System.out.println(number + " is divisible by 2 or 3, but not both.");
    }
}
```

**Sample Runs:**
- Input: 4 → Output: "4 is divisible by 2 or 3." and "4 is divisible by 2 or 3, but not both."
- Input: 18 → Output: "18 is divisible by 2 and 3." and "18 is divisible by 2 or 3."

### Short-Circuit Evaluation
- `&&`: If first operand is false, second operand is not evaluated
- `||`: If first operand is true, second operand is not evaluated

```java
// If x is 0, (x != 0) is false, so (y / x > 5) is never evaluated
if ((x != 0) && (y / x > 5)) {
    // Safe from division by zero
}
```

### De Morgan's Law
Used to simplify boolean expressions:
- `!(condition1 && condition2)` = `!condition1 || !condition2`
- `!(condition1 || condition2)` = `!condition1 && !condition2`

**Examples:**
```java
// Original
!(number % 2 == 0 && number % 3 == 0)
// Simplified
(number % 2 != 0 || number % 3 != 0)

// Original  
!(number == 2 || number == 3)
// Simplified
number != 2 && number != 3
```

---

## 11. Case Study: Determining Leap Year

### Leap Year Rules
A year is a leap year if:
1. Divisible by 4 AND not divisible by 100, OR
2. Divisible by 400

### Step-by-Step Logic
```java
// Step 1: Check if divisible by 4
boolean isLeapYear = (year % 4 == 0);

// Step 2: Check if divisible by 4 but not by 100
isLeapYear = isLeapYear && (year % 100 != 0);

// Step 3: Check if divisible by 400 (override step 2)
isLeapYear = isLeapYear || (year % 400 == 0);

// Combined expression
isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
```

### Complete Program: LeapYear.java
```java
import java.util.Scanner;

public class LeapYear {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter a year: ");
        int year = input.nextInt();

        // Check if leap year
        boolean isLeapYear = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);

        // Display result
        System.out.println(year + " is a leap year? " + isLeapYear);
    }
}
```

**Sample Runs:**
- Input: 2008 → Output: "2008 is a leap year? true"
- Input: 1900 → Output: "1900 is a leap year? false"
- Input: 2000 → Output: "2000 is a leap year? true"

---

## 12. Case Study: Lottery

### Game Rules
1. **Exact match**: Award $10,000
2. **All digits match (any order)**: Award $3,000  
3. **One digit matches**: Award $1,000
4. **No match**: No award

### Digit Extraction Technique
```java
int lottery = 47;
int lotteryDigit1 = lottery / 10;    // 4
int lotteryDigit2 = lottery % 10;    // 7
```

### Complete Program: Lottery.java
```java
import java.util.Scanner;

public class Lottery {
    public static void main(String[] args) {
        // Generate lottery number
        int lottery = (int)(Math.random() * 100);

        // Get user guess
        Scanner input = new Scanner(System.in);
        System.out.print("Enter your lottery pick (two digits): ");
        int guess = input.nextInt();

        // Extract digits
        int lotteryDigit1 = lottery / 10;
        int lotteryDigit2 = lottery % 10;
        int guessDigit1 = guess / 10;
        int guessDigit2 = guess % 10;

        System.out.println("The lottery number is " + lottery);

        // Check results in order of highest award first
        if (guess == lottery)
            System.out.println("Exact match: you win $10,000");
        else if (guessDigit2 == lotteryDigit1 && guessDigit1 == lotteryDigit2)
            System.out.println("Match all digits: you win $3,000");
        else if (guessDigit1 == lotteryDigit1 || guessDigit1 == lotteryDigit2 || 
                 guessDigit2 == lotteryDigit1 || guessDigit2 == lotteryDigit2)
            System.out.println("Match one digit: you win $1,000");
        else
            System.out.println("Sorry, no match");
    }
}
```

**Sample Runs:**
- Guess: 15, Lottery: 15 → "Exact match: you win $10,000"
- Guess: 45, Lottery: 54 → "Match all digits: you win $3,000"  
- Guess: 23, Lottery: 34 → "Match one digit: you win $1,000"

---

## 13. Switch Statements

### Purpose
Simplify multiple condition checking when comparing a variable against several constant values.

#### Syntax
```java
switch (switch-expression) {
    case value1: 
        statement(s)1;
        break;
    case value2: 
        statement(s)2;
        break;
    // ...
    default: 
        statement(s)-for-default;
}
```

### Switch Rules
1. **Switch expression types**: `char`, `byte`, `short`, `int`, or `String`
2. **Case values**: Must be constants (not variables)
3. **Break statement**: Optional but usually needed to prevent fall-through
4. **Default case**: Optional, executes when no case matches

### Example: Chinese Zodiac
```java
import java.util.Scanner;

public class ChineseZodiac {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a year: ");
        int year = input.nextInt();

        switch (year % 12) {
            case 0: System.out.println("monkey"); break;
            case 1: System.out.println("rooster"); break;
            case 2: System.out.println("dog"); break;
            case 3: System.out.println("pig"); break;
            case 4: System.out.println("rat"); break;
            case 5: System.out.println("ox"); break;
            case 6: System.out.println("tiger"); break;
            case 7: System.out.println("rabbit"); break;
            case 8: System.out.println("dragon"); break;
            case 9: System.out.println("snake"); break;
            case 10: System.out.println("horse"); break;
            case 11: System.out.println("sheep");
        }
    }
}
```

### Fall-Through Behavior
```java
// Example of intentional fall-through
switch (day) {
    case 1:
    case 2:
    case 3:
    case 4:
    case 5: 
        System.out.println("Weekday"); 
        break;
    case 0:
    case 6: 
        System.out.println("Weekend");
}
```

---

## 14. Conditional Expressions

### Ternary Operator
A concise way to write simple if-else statements.

#### Syntax
```java
boolean-expression ? expression1 : expression2;
```

#### How It Works
- If `boolean-expression` is true, result is `expression1`
- If `boolean-expression` is false, result is `expression2`

### Examples

#### Simple Assignment
```java
// Traditional if-else
if (x > 0)
    y = 1;
else
    y = -1;

// Conditional expression
y = (x > 0) ? 1 : -1;
```

#### Finding Maximum
```java
max = (num1 > num2) ? num1 : num2;
```

#### Display Messages
```java
System.out.println((num % 2 == 0) ? "num is even" : "num is odd");
```

### When to Use
- **Use conditional expressions for**: Simple assignments or short expressions
- **Use if-else for**: Complex logic or multiple statements

---

## 15. Operator Precedence and Associativity

### Precedence Rules
Operators are evaluated in order of precedence (highest to lowest):

| Precedence Level | Operators |
|------------------|-----------|
| 1 (Highest) | `var++`, `var--` (Postfix) |
| 2 | `+`, `-` (Unary), `++var`, `--var` (Prefix) |
| 3 | `(type)` (Casting) |
| 4 | `!` (NOT) |
| 5 | `*`, `/`, `%` |
| 6 | `+`, `-` (Binary) |
| 7 | `<`, `<=`, `>`, `>=` (Relational) |
| 8 | `==`, `!=` (Equality) |
| 9 | `^` (Exclusive OR) |
| 10 | `&&` (AND) |
| 11 | `||` (OR) |
| 12 (Lowest) | `=`, `+=`, `-=`, `*=`, `/=`, `%=` (Assignment) |

### Associativity Rules
- **Left Associative**: Most binary operators (`+`, `-`, `*`, `/`, `%`, `<`, `>`, `==`, `!=`, `&&`, `||`)
- **Right Associative**: Assignment operators (`=`, `+=`, `-=`, etc.)

### Examples

#### Expression Evaluation
```java
3 + 4 * 4 > 5 * (4 + 3) - 1 && (4 - 3 > 5)
```

**Step-by-step evaluation:**
1. Parentheses first: `(4 + 3) = 7` and `(4 - 3 > 5) = false`
2. Multiplication: `4 * 4 = 16` and `5 * 7 = 35`
3. Addition/Subtraction: `3 + 16 = 19` and `35 - 1 = 34`
4. Relational: `19 > 34 = false`
5. Logical AND: `false && false = false`

#### Left Associativity Example
```java
a - b + c - d
// Evaluated as: ((a - b) + c) - d
```

#### Right Associativity Example
```java
a = b += c = 5
// Evaluated as: a = (b += (c = 5))
// If a=1, b=1, c=1 initially, result: a=6, b=6, c=5
```

---

## 16. Debugging

### What is Debugging?
**Debugging** is the process of finding and fixing errors (bugs) in programs.

### Types of Errors
1. **Syntax Errors**: Easy to find (compiler shows them)
2. **Runtime Errors**: Displayed when program crashes
3. **Logic Errors**: Hardest to find (program runs but produces wrong results)

### Debugging Techniques

#### 1. Hand Tracing
Manually follow program execution with sample data.

#### 2. Print Statements
Insert temporary output to see variable values:
```java
System.out.println("Debug: x = " + x + ", y = " + y);
```

#### 3. Using a Debugger
Professional debugging tools provide:
- **Single-step execution**: Execute one statement at a time
- **Breakpoints**: Pause execution at specific lines
- **Variable inspection**: View current variable values
- **Call stack**: See method call sequence

### Debugging Tips
- **Incremental Development**: Write small amounts of code and test frequently
- **Test All Cases**: Ensure your program works for all possible inputs
- **Use IDE Debuggers**: Eclipse, NetBeans, IntelliJ IDEA have built-in debuggers

---

## 17. Practice Exercises

### Check Your Understanding Questions

#### 3.1 List six relational operators.
**Answer:** `<`, `<=`, `>`, `>=`, `==`, `!=`

#### 3.2 Boolean Expression Results (assume x = 1)
- `(x > 0)` → `true`
- `(x < 0)` → `false`
- `(x != 0)` → `true`
- `(x >= 0)` → `true`
- `(x != 1)` → `false`

#### 3.4 Write an if statement that assigns 1 to x if y is greater than 0.
```java
if (y > 0) {
    x = 1;
}
```

#### 3.5 Write an if statement that increases pay by 3% if score is greater than 90.
```java
if (score > 90) {
    pay = pay * 1.03;  // or pay *= 1.03;
}
```

#### 3.6 Increase pay by 3% if score > 90, otherwise by 1%.
```java
if (score > 90) {
    pay *= 1.03;
} else {
    pay *= 1.01;
}
```

### Programming Exercises

#### Exercise 3.1: Quadratic Equation Solver
**Problem:** Solve quadratic equations using the discriminant.

**Formula:** For ax² + bx + c = 0
- Discriminant = b² - 4ac
- If discriminant > 0: Two real roots
- If discriminant = 0: One real root  
- If discriminant < 0: No real roots

**Solution:**
```java
import java.util.Scanner;

public class QuadraticSolver {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a, b, c: ");
        double a = input.nextDouble();
        double b = input.nextDouble();
        double c = input.nextDouble();
        
        double discriminant = b * b - 4 * a * c;
        
        if (discriminant > 0) {
            double root1 = (-b + Math.pow(discriminant, 0.5)) / (2 * a);
            double root2 = (-b - Math.pow(discriminant, 0.5)) / (2 * a);
            System.out.println("The equation has two roots " + root1 + " and " + root2);
        } else if (discriminant == 0) {
            double root = -b / (2 * a);
            System.out.println("The equation has one root " + root);
        } else {
            System.out.println("The equation has no real roots");
        }
    }
}
```

#### Exercise 3.3: Linear Equation Solver (2x2 System)
**Problem:** Solve system of linear equations using Cramer's rule.

**Solution:**
```java
import java.util.Scanner;

public class LinearEquationSolver {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a, b, c, d, e, f: ");
        double a = input.nextDouble();
        double b = input.nextDouble();
        double c = input.nextDouble();
        double d = input.nextDouble();
        double e = input.nextDouble();
        double f = input.nextDouble();
        
        double determinant = a * d - b * c;
        
        if (determinant == 0) {
            System.out.println("The equation has no solution");
        } else {
            double x = (e * d - b * f) / determinant;
            double y = (a * f - e * c) / determinant;
            System.out.println("x is " + x + " and y is " + y);
        }
    }
}
```

#### Exercise 3.5: Future Day Calculator
**Problem:** Calculate what day of the week it will be after a given number of days.

**Solution:**
```java
import java.util.Scanner;

public class FutureDay {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter today's day (0=Sunday, 1=Monday, ..., 6=Saturday): ");
        int today = input.nextInt();
        
        System.out.print("Enter the number of days elapsed since today: ");
        int elapsedDays = input.nextInt();
        
        int futureDay = (today + elapsedDays) % 7;
        
        String[] dayNames = {"Sunday", "Monday", "Tuesday", "Wednesday", 
                           "Thursday", "Friday", "Saturday"};
        
        System.out.println("Today is " + dayNames[today] + 
                          " and the future day is " + dayNames[futureDay]);
    }
}
```

#### Exercise 3.8: Sort Three Integers
**Problem:** Read three integers and display them in non-decreasing order.

**Solution:**
```java
import java.util.Scanner;

public class SortThreeIntegers {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter three integers: ");
        int num1 = input.nextInt();
        int num2 = input.nextInt();
        int num3 = input.nextInt();
        
        // Sort using nested if statements
        int min, middle, max;
        
        if (num1 <= num2 && num1 <= num3) {
            min = num1;
            if (num2 <= num3) {
                middle = num2;
                max = num3;
            } else {
                middle = num3;
                max = num2;
            }
        } else if (num2 <= num1 && num2 <= num3) {
            min = num2;
            if (num1 <= num3) {
                middle = num1;
                max = num3;
            } else {
                middle = num3;
                max = num1;
            }
        } else {
            min = num3;
            if (num1 <= num2) {
                middle = num1;
                max = num2;
            } else {
                middle = num2;
                max = num1;
            }
        }
        
        System.out.println("The sorted numbers are " + min + " " + middle + " " + max);
    }
}
```

#### Exercise 3.11: Days in Month Calculator
**Problem:** Display number of days in a given month and year.

**Solution:**
```java
import java.util.Scanner;

public class DaysInMonth {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a month (1-12): ");
        int month = input.nextInt();
        
        System.out.print("Enter a year: ");
        int year = input.nextInt();
        
        String monthName = "";
        int daysInMonth = 0;
        
        switch (month) {
            case 1: monthName = "January"; daysInMonth = 31; break;
            case 2: 
                monthName = "February";
                // Check for leap year
                if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0))
                    daysInMonth = 29;
                else
                    daysInMonth = 28;
                break;
            case 3: monthName = "March"; daysInMonth = 31; break;
            case 4: monthName = "April"; daysInMonth = 30; break;
            case 5: monthName = "May"; daysInMonth = 31; break;
            case 6: monthName = "June"; daysInMonth = 30; break;
            case 7: monthName = "July"; daysInMonth = 31; break;
            case 8: monthName = "August"; daysInMonth = 31; break;
            case 9: monthName = "September"; daysInMonth = 30; break;
            case 10: monthName = "October"; daysInMonth = 31; break;
            case 11: monthName = "November"; daysInMonth = 30; break;
            case 12: monthName = "December"; daysInMonth = 31; break;
            default: 
                System.out.println("Invalid month");
                return;
        }
        
        System.out.println(monthName + " " + year + " had " + daysInMonth + " days");
    }
}
```

#### Exercise 3.12: Palindrome Number Checker
**Problem:** Check if a three-digit number is a palindrome.

**Solution:**
```java
import java.util.Scanner;

public class PalindromeChecker {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a three-digit integer: ");
        int number = input.nextInt();
        
        // Extract digits
        int firstDigit = number / 100;
        int lastDigit = number % 10;
        
        if (firstDigit == lastDigit) {
            System.out.println(number + " is a palindrome");
        } else {
            System.out.println(number + " is not a palindrome");
        }
    }
}
```

#### Exercise 3.17: Rock-Paper-Scissors Game
**Problem:** Create a rock-paper-scissors game against the computer.

**Rules:**
- Scissor (0) cuts Paper (2)
- Rock (1) crushes Scissor (0)  
- Paper (2) wraps Rock (1)

**Solution:**
```java
import java.util.Scanner;

public class RockPaperScissors {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        // Generate computer choice
        int computer = (int)(Math.random() * 3);
        
        // Get user choice
        System.out.print("scissor (0), rock (1), paper (2): ");
        int user = input.nextInt();
        
        // Convert numbers to names
        String[] choices = {"scissor", "rock", "paper"};
        
        System.out.print("The computer is " + choices[computer] + 
                        ". You are " + choices[user] + ". ");
        
        // Determine winner
        if (computer == user) {
            System.out.println("It is a draw");
        } else if ((user == 0 && computer == 2) ||    // scissor cuts paper
                   (user == 1 && computer == 0) ||    // rock crushes scissor
                   (user == 2 && computer == 1)) {    // paper wraps rock
            System.out.println("You won");
        } else {
            System.out.println("You lost");
        }
    }
}
```

#### Exercise 3.22: Point in Circle
**Problem:** Check if a point (x, y) is inside a circle centered at (0, 0) with radius 10.

**Mathematical Formula:** Point is inside if distance ≤ radius
Distance = √((x₂-x₁)² + (y₂-y₁)²)

**Solution:**
```java
import java.util.Scanner;

public class PointInCircle {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a point with two coordinates: ");
        double x = input.nextDouble();
        double y = input.nextDouble();
        
        // Calculate distance from origin
        double distance = Math.sqrt(x * x + y * y);
        
        if (distance <= 10) {
            System.out.println("Point (" + x + ", " + y + ") is in the circle");
        } else {
            System.out.println("Point (" + x + ", " + y + ") is not in the circle");
        }
    }
}
```

#### Exercise 3.24: Card Picker Simulation
**Problem:** Simulate picking a random card from a 52-card deck.

**Solution:**
```java
public class CardPicker {
    public static void main(String[] args) {
        // Generate random card (0-51)
        int cardNumber = (int)(Math.random() * 52);
        
        // Determine rank (0-12)
        int rank = cardNumber % 13;
        String[] ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", "10", 
                         "Jack", "Queen", "King"};
        
        // Determine suit (0-3)
        int suit = cardNumber / 13;
        String[] suits = {"Clubs", "Diamonds", "Hearts", "Spades"};
        
        System.out.println("The card you picked is " + ranks[rank] + " of " + suits[suit]);
    }
}
```

---

## Key Programming Concepts Summary

### 1. Decision Making in Programming
- Programs need to make choices based on different conditions
- Selection statements provide this capability
- Essential for handling user input validation and different scenarios

### 2. Boolean Logic Foundation
- Boolean expressions are the foundation of all selection statements
- Understanding truth tables helps predict program behavior
- Relational operators create boolean expressions from comparisons

### 3. Control Flow Patterns
- **Sequential**: Execute statements in order
- **Selection**: Choose which statements to execute
- **Repetition**: (Covered in later chapters)

### 4. Code Quality Principles
- **Readability**: Use proper indentation and braces
- **Maintainability**: Avoid code duplication
- **Reliability**: Handle all possible cases
- **Testing**: Verify all execution paths

### 5. Problem-Solving Approach
1. **Analyze**: Understand the problem requirements
2. **Design**: Plan the logic flow
3. **Implement**: Write the code
4. **Test**: Verify with different inputs
5. **Debug**: Fix any issues found

---

## Common Programming Patterns

### Input Validation Pattern
```java
Scanner input = new Scanner(System.in);
System.out.print("Enter a positive number: ");
double number = input.nextDouble();

if (number <= 0) {
    System.out.println("Invalid input: number must be positive");
} else {
    // Process valid input
    System.out.println("Processing: " + number);
}
```

### Range Checking Pattern
```java
if (score >= 90) {
    grade = 'A';
} else if (score >= 80) {
    grade = 'B';
} else if (score >= 70) {
    grade = 'C';
} else if (score >= 60) {
    grade = 'D';
} else {
    grade = 'F';
}
```

### Multiple Condition Pattern
```java
// Using logical operators
if (age >= 18 && hasLicense && hasInsurance) {
    System.out.println("Can drive legally");
} else {
    System.out.println("Cannot drive legally");
}
```

### Category Classification Pattern
```java
switch (dayOfWeek) {
    case 1: case 2: case 3: case 4: case 5:
        System.out.println("Weekday");
        break;
    case 0: case 6:
        System.out.println("Weekend");
        break;
    default:
        System.out.println("Invalid day");
}
```

---

## Best Practices

### 1. Always Use Braces
```java
// Even for single statements
if (condition) {
    statement;
}
```

### 2. Test All Paths
- Ensure every possible condition is tested
- Include boundary cases (edge values)
- Test invalid inputs

### 3. Use Descriptive Variable Names
```java
// Poor
if (x > 0) { ... }

// Better  
if (temperature > 0) { ... }
```

### 4. Handle Invalid Input
```java
if (month < 1 || month > 12) {
    System.out.println("Invalid month");
    return;
}
```

### 5. Use Constants for Magic Numbers
```java
final double FREEZING_POINT = 32.0;
if (temperature <= FREEZING_POINT) {
    System.out.println("Water freezes");
}
```

---

## Chapter Summary

### Key Points Learned
1. **Boolean Type**: Foundation for all decision making in programs
2. **Relational Operators**: Compare values and produce boolean results
3. **If Statements**: Execute code conditionally
4. **If-else Statements**: Choose between two alternatives
5. **Multi-way if-else**: Handle multiple alternatives efficiently
6. **Logical Operators**: Combine multiple conditions
7. **Switch Statements**: Clean way to handle many discrete values
8. **Conditional Expressions**: Concise way for simple if-else logic
9. **Debugging**: Essential skill for finding and fixing errors

### Programming Skills Developed
- Input validation
- Decision-making logic
- Error handling
- Code organization
- Testing strategies
- Problem decomposition

### Next Steps
- Practice with more complex selection scenarios
- Learn about loops (repetition statements)
- Combine selection with loops for powerful programming patterns
- Study methods and modular programming

This chapter forms the foundation for all conditional logic in Java programming. Master these concepts through practice and experimentation!
