# Chapter 5: Java Loops - Complete Guide

## 5.1 Introduction to Loops

### What is a Loop?
A loop is a programming construct that allows you to execute statements repeatedly without writing the same code multiple times.

### Problem Example
Instead of writing this 100 times:
```java
System.out.println("Welcome to Java!");
System.out.println("Welcome to Java!");
// ... 98 more times
```

We can use a loop:
```java
int count = 0;
while (count < 100) {
    System.out.println("Welcome to Java!");
    count++;
}
```

### Key Concepts
- **Loop Body**: The part containing statements to be repeated
- **Iteration**: One execution of the loop body
- **Loop-continuation-condition**: Boolean expression controlling loop execution

### Types of Loops in Java
1. **while loops**
2. **do-while loops** 
3. **for loops**

---

## 5.2 The while Loop

### Syntax
```java
while (loop-continuation-condition) {
    // Loop body
    Statement(s);
}
```

### How it Works
1. Evaluates the condition
2. If true → executes loop body → repeats
3. If false → terminates loop

### Example 1: Counter-Controlled Loop
```java
int sum = 0, i = 1;
while (i < 10) {
    sum = sum + i;
    i++;
}
System.out.println("sum is " + sum); // Output: sum is 45
```

**Explanation**: 
- Starts with i=1, sum=0
- Adds i to sum, then increments i
- Continues until i reaches 10
- Final sum: 1+2+3+4+5+6+7+8+9 = 45

### Common Errors

#### Infinite Loop Example
```java
int sum = 0, i = 1;
while (i < 10) {
    sum = sum + i;
    // Missing i++; causes infinite loop!
}
```

#### Off-by-One Error
```java
int count = 0;
while (count <= 100) {  // Should be count < 100
    System.out.println("Welcome to Java!");
    count++;
}
// This prints 101 times instead of 100!
```

### Case Study 1: Repeat Addition Quiz
**RepeatAdditionQuiz.java**
```java
import java.util.Scanner;

public class RepeatAdditionQuiz {
    public static void main(String[] args) {
        int number1 = (int)(Math.random() * 10);
        int number2 = (int)(Math.random() * 10);
        
        Scanner input = new Scanner(System.in);
        
        System.out.print("What is " + number1 + " + " + number2 + "? ");
        int answer = input.nextInt();
        
        while (number1 + number2 != answer) {
            System.out.print("Wrong answer. Try again. What is " 
                + number1 + " + " + number2 + "? ");
            answer = input.nextInt();
        }
        
        System.out.println("You got it!");
    }
}
```

### Case Study 2: Guessing Numbers Game
**GuessNumber.java**
```java
import java.util.Scanner;

public class GuessNumber {
    public static void main(String[] args) {
        // Generate random number 0-100
        int number = (int)(Math.random() * 101);
        
        Scanner input = new Scanner(System.in);
        System.out.println("Guess a magic number between 0 and 100");
        
        int guess = -1;
        while (guess != number) {
            System.out.print("\nEnter your guess: ");
            guess = input.nextInt();
            
            if (guess == number)
                System.out.println("Yes, the number is " + number);
            else if (guess > number)
                System.out.println("Your guess is too high");
            else
                System.out.println("Your guess is too low");
        }
    }
}
```

**Sample Output:**
```
Guess a magic number between 0 and 100
Enter your guess: 50
Your guess is too high
Enter your guess: 25
Your guess is too low
Enter your guess: 39
Yes, the number is 39
```

### Loop Design Strategy
1. **Step 1**: Identify statements that need repetition
2. **Step 2**: Wrap in basic loop structure:
   ```java
   while (true) {
       Statements;
   }
   ```
3. **Step 3**: Add proper condition and control statements:
   ```java
   while (loop-continuation-condition) {
       Statements;
       Additional controlling statements;
   }
   ```

### Case Study 3: Multiple Subtraction Quiz
**SubtractionQuizLoop.java**
```java
import java.util.Scanner;

public class SubtractionQuizLoop {
    public static void main(String[] args) {
        final int NUMBER_OF_QUESTIONS = 5;
        int correctCount = 0;
        int count = 0;
        long startTime = System.currentTimeMillis();
        String output = "";
        Scanner input = new Scanner(System.in);
        
        while (count < NUMBER_OF_QUESTIONS) {
            // Generate two random single-digit integers
            int number1 = (int)(Math.random() * 10);
            int number2 = (int)(Math.random() * 10);
            
            // Ensure number1 >= number2
            if (number1 < number2) {
                int temp = number1;
                number1 = number2;
                number2 = temp;
            }
            
            // Ask question
            System.out.print("What is " + number1 + " - " + number2 + "? ");
            int answer = input.nextInt();
            
            // Grade answer
            if (number1 - number2 == answer) {
                System.out.println("You are correct!");
                correctCount++;
            } else {
                System.out.println("Your answer is wrong.\n" + number1
                    + " - " + number2 + " should be " + (number1 - number2));
            }
            
            count++;
            output += "\n" + number1 + "-" + number2 + "=" + answer +
                ((number1 - number2 == answer) ? " correct" : " wrong");
        }
        
        long endTime = System.currentTimeMillis();
        long testTime = endTime - startTime;
        
        System.out.println("Correct count is " + correctCount +
            "\nTest time is " + testTime / 1000 + " seconds\n" + output);
    }
}
```

### Sentinel-Controlled Loops
A **sentinel value** is a special input value that signals the end of input.

**SentinelValue.java**
```java
import java.util.Scanner;

public class SentinelValue {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter an integer (the input ends if it is 0): ");
        int data = input.nextInt();
        
        int sum = 0;
        while (data != 0) {
            sum += data;
            System.out.print("Enter an integer (the input ends if it is 0): ");
            data = input.nextInt();
        }
        
        System.out.println("The sum is " + sum);
    }
}
```

### Input/Output Redirection
- **Input redirection**: `java ClassName < input.txt`
- **Output redirection**: `java ClassName > output.txt`
- **Both**: `java ClassName < input.txt > output.txt`

---

## 5.3 The do-while Loop

### Key Difference
- **while loop**: Checks condition BEFORE executing body
- **do-while loop**: Executes body FIRST, then checks condition

### Syntax
```java
do {
    // Loop body
    Statement(s);
} while (loop-continuation-condition);
```

### When to Use
Use do-while when the loop body must execute **at least once**.

### Example: TestDoWhile.java
```java
import java.util.Scanner;

public class TestDoWhile {
    public static void main(String[] args) {
        int data;
        int sum = 0;
        Scanner input = new Scanner(System.in);
        
        do {
            System.out.print("Enter an integer (the input ends if it is 0): ");
            data = input.nextInt();
            sum += data;
        } while (data != 0);
        
        System.out.println("The sum is " + sum);
    }
}
```

**Note**: This version always asks for input at least once, even if user enters 0 first.

---

## 5.4 The for Loop

### Syntax
```java
for (initial-action; loop-continuation-condition; action-after-each-iteration) {
    // Loop body
    Statement(s);
}
```

### Components
1. **initial-action**: Usually initializes control variable
2. **loop-continuation-condition**: Boolean expression tested before each iteration
3. **action-after-each-iteration**: Usually increments/decrements control variable

### Basic Example
```java
for (int i = 0; i < 100; i++) {
    System.out.println("Welcome to Java!");
}
```

### Advanced for Loop Features

#### Multiple Variables
```java
for (int i = 0, j = 0; i + j < 10; i++, j++) {
    // Do something
}
```

#### Variable Scope
```java
for (int i = 0; i < 10; i++) {
    // i is only accessible within this loop
}
// i cannot be used here!
```

### Common Errors

#### Semicolon After for Clause
```java
// WRONG - semicolon creates empty loop body
for (int i = 0; i < 10; i++); {
    System.out.println("i is " + i);
}

// CORRECT
for (int i = 0; i < 10; i++) {
    System.out.println("i is " + i);
}
```

---

## 5.5 Which Loop to Use?

### Loop Types Classification
- **Pretest loops**: while, for (condition checked before execution)
- **Posttest loop**: do-while (condition checked after execution)

### Guidelines
- **for loop**: When number of iterations is known in advance
- **while loop**: When number of iterations is not predetermined
- **do-while loop**: When loop body must execute at least once

### Equivalence Examples

#### while to for conversion
```java
// while loop
int count = 0;
while (count < 100) {
    // Loop body
    count++;
}

// Equivalent for loop
for (int count = 0; count < 100; count++) {
    // Loop body
}
```

---

## 5.6 Nested Loops

### Concept
A loop inside another loop. The inner loop completes all iterations for each iteration of the outer loop.

### Example: Multiplication Table
**MultiplicationTable.java**
```java
public class MultiplicationTable {
    public static void main(String[] args) {
        // Display table heading
        System.out.println(" Multiplication Table");
        
        // Display column numbers
        System.out.print("   ");
        for (int j = 1; j <= 9; j++)
            System.out.print("   " + j);
        
        System.out.println("\n————————————————————————————————————————");
        
        // Display table body
        for (int i = 1; i <= 9; i++) {
            System.out.print(i + " | ");
            for (int j = 1; j <= 9; j++) {
                System.out.printf("%4d", i * j);
            }
            System.out.println();
        }
    }
}
```

**Output:**
```
 Multiplication Table
      1   2   3   4   5   6   7   8   9
————————————————————————————————————————
1 |    1   2   3   4   5   6   7   8   9
2 |    2   4   6   8  10  12  14  16  18
3 |    3   6   9  12  15  18  21  24  27
4 |    4   8  12  16  20  24  28  32  36
5 |    5  10  15  20  25  30  35  40  45
6 |    6  12  18  24  30  36  42  48  54
7 |    7  14  21  28  35  42  49  56  63
8 |    8  16  24  32  40  48  56  64  72
9 |    9  18  27  36  45  54  63  72  81
```

### Performance Warning
```java
// This executes 1 trillion times!
for (int i = 0; i < 10000; i++)
    for (int j = 0; j < 10000; j++)
        for (int k = 0; k < 10000; k++)
            performAction(); // 10,000³ = 1,000,000,000,000 times
```

---

## 5.7 Minimizing Numeric Errors

### Problem with Floating-Point Loops
```java
// PROBLEMATIC CODE
float sum = 0;
for (float i = 0.01f; i <= 1.0f; i = i + 0.01f)
    sum += i;
System.out.println("The sum is " + sum); // Output: 50.499985 (not 50.50!)
```

### Why This Happens
- Floating-point numbers are approximations
- Small rounding errors accumulate
- Loop may not terminate exactly when expected

### Solutions

#### 1. Use Integer Counter
```java
double sum = 0;
double currentValue = 0.01;
for (int count = 0; count < 100; count++) {
    sum += currentValue;
    currentValue += 0.01;
}
// More accurate result
```

#### 2. Order of Operations Matters
```java
// Adding small to large (better)
for (int i = 1; i <= 100; i++)
    sum += 1.0/i;

// Adding large to small (less accurate)
for (int i = 100; i >= 1; i--)
    sum += 1.0/i;
```

---

## 5.8 Case Studies

### Case Study 1: Greatest Common Divisor (GCD)

#### Problem
Find the greatest common divisor of two integers.

#### Algorithm
1. Start with gcd = 1
2. Test each number k from 2 to min(n1, n2)
3. If k divides both n1 and n2, update gcd = k
4. Continue until all possibilities tested

**GreatestCommonDivisor.java**
```java
import java.util.Scanner;

public class GreatestCommonDivisor {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter first integer: ");
        int n1 = input.nextInt();
        System.out.print("Enter second integer: ");
        int n2 = input.nextInt();
        
        int gcd = 1;
        int k = 2;
        while (k <= n1 && k <= n2) {
            if (n1 % k == 0 && n2 % k == 0)
                gcd = k;
            k++;
        }
        
        System.out.println("The greatest common divisor for " + n1 +
            " and " + n2 + " is " + gcd);
    }
}
```

### Case Study 2: Future Tuition Calculation

#### Problem
If tuition is $10,000 and increases 7% yearly, when will it double?

**FutureTuition.java**
```java
public class FutureTuition {
    public static void main(String[] args) {
        double tuition = 10000; // Starting tuition
        int year = 0;
        
        while (tuition < 20000) {
            tuition = tuition * 1.07;
            year++;
        }
        
        System.out.println("Tuition will be doubled in " + year + " years");
        System.out.printf("Tuition will be $%.2f in %d years", tuition, year);
    }
}
```

**Output:**
```
Tuition will be doubled in 11 years
Tuition will be $21048.52 in 11 years
```

### Case Study 3: Decimal to Hexadecimal Conversion

#### Algorithm
1. Repeatedly divide decimal by 16
2. Remainder gives hex digit (0-9, A-F)
3. Continue until quotient becomes 0
4. Read remainders in reverse order

**Dec2Hex.java**
```java
import java.util.Scanner;

public class Dec2Hex {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a decimal number: ");
        int decimal = input.nextInt();
        
        String hex = "";
        
        while (decimal != 0) {
            int hexValue = decimal % 16;
            
            // Convert to hex character
            char hexDigit = (hexValue <= 9 && hexValue >= 0) ?
                (char)(hexValue + '0') : (char)(hexValue - 10 + 'A');
            
            hex = hexDigit + hex; // Prepend to build result
            decimal = decimal / 16;
        }
        
        System.out.println("The hex number is " + hex);
    }
}
```

**Example Conversion (1234 to hex):**
```
1234 ÷ 16 = 77 remainder 2 → '2'
77 ÷ 16 = 4 remainder 13 → 'D'
4 ÷ 16 = 0 remainder 4 → '4'
Result: 4D2
```

---

## 5.9 Keywords break and continue

### break Statement
Immediately terminates the loop.

**TestBreak.java**
```java
public class TestBreak {
    public static void main(String[] args) {
        int sum = 0;
        int number = 0;
        
        while (number < 20) {
            number++;
            sum += number;
            if (sum >= 100)
                break; // Exit loop when sum >= 100
        }
        
        System.out.println("The number is " + number); // 14
        System.out.println("The sum is " + sum);       // 105
    }
}
```

### continue Statement
Skips the rest of current iteration, continues with next iteration.

**TestContinue.java**
```java
public class TestContinue {
    public static void main(String[] args) {
        int sum = 0;
        int number = 0;
        
        while (number < 20) {
            number++;
            if (number == 10 || number == 11)
                continue; // Skip adding 10 and 11
            sum += number;
        }
        
        System.out.println("The sum is " + sum); // 189 (210 - 10 - 11)
    }
}
```

### Practical Example: Finding Smallest Factor
```java
int factor = 2;
while (factor <= n) {
    if (n % factor == 0)
        break; // Found factor, exit loop
    factor++;
}
System.out.println("The smallest factor other than 1 for " + n + " is " + factor);
```

---

## 5.10 Case Study: Checking Palindromes

### Problem
Check if a string reads the same forwards and backwards.

### Algorithm
1. Compare first character with last character
2. Compare second character with second-to-last character
3. Continue toward middle until mismatch found or all checked

**Palindrome.java**
```java
import java.util.Scanner;

public class Palindrome {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        System.out.print("Enter a string: ");
        String s = input.nextLine();
        
        int low = 0;                    // First character index
        int high = s.length() - 1;      // Last character index
        boolean isPalindrome = true;
        
        while (low < high) {
            if (s.charAt(low) != s.charAt(high)) {
                isPalindrome = false;
                break;
            }
            low++;
            high--;
        }
        
        if (isPalindrome)
            System.out.println(s + " is a palindrome");
        else
            System.out.println(s + " is not a palindrome");
    }
}
```

**Examples:**
- "noon" → is a palindrome
- "moon" → is not a palindrome

---

## 5.11 Case Study: Displaying Prime Numbers

### Problem
Display the first 50 prime numbers, 10 per line.

### Algorithm
1. For each number starting from 2:
   - Test if it's prime (no divisors from 2 to number/2)
   - If prime, increment count and display
   - Stop when count reaches 50

**PrimeNumber.java**
```java
public class PrimeNumber {
    public static void main(String[] args) {
        final int NUMBER_OF_PRIMES = 50;
        final int NUMBER_OF_PRIMES_PER_LINE = 10;
        int count = 0;
        int number = 2;
        
        System.out.println("The first 50 prime numbers are \n");
        
        while (count < NUMBER_OF_PRIMES) {
            boolean isPrime = true;
            
            // Test if number is prime
            for (int divisor = 2; divisor <= number / 2; divisor++) {
                if (number % divisor == 0) {
                    isPrime = false;
                    break;
                }
            }
            
            // Display if prime
            if (isPrime) {
                count++;
                if (count % NUMBER_OF_PRIMES_PER_LINE == 0) {
                    System.out.println(number);
                } else {
                    System.out.print(number + " ");
                }
            }
            
            number++;
        }
    }
}
```

**Output:**
```
The first 50 prime numbers are 

2 3 5 7 11 13 17 19 23 29
31 37 41 43 47 53 59 61 67 71
73 79 83 89 97 101 103 107 109 113
127 131 137 139 149 151 157 163 167 173
179 181 191 193 197 199 211 223 227 229
```

---

## Programming Exercises Summary

### Basic Exercises (5.1-5.6)
- **5.1**: Count positive/negative numbers and compute average
- **5.2**: Generate random addition questions
- **5.3**: Kilograms to pounds conversion table
- **5.4**: Miles to kilometers conversion table
- **5.5**: Side-by-side conversion tables
- **5.6**: Two-way conversion tables

### Financial Applications (5.7, 5.21, 5.22, 5.30, 5.31, 5.39, 5.42)
- **5.7**: Future tuition calculation
- **5.21**: Loan comparison with various interest rates
- **5.22**: Loan amortization schedule
- **5.30**: Compound savings value
- **5.31**: CD (Certificate of Deposit) value
- **5.39**: Sales commission calculation
- **5.42**: Modified sales amount finder

### Mathematical Problems (5.12, 5.13, 5.14, 5.23-5.26, 5.35, 5.43, 5.45)
- **5.12**: Find smallest n where n² > 12,000
- **5.13**: Find largest n where n³ < 12,000
- **5.14**: Alternative GCD algorithm
- **5.23**: Cancellation errors demonstration
- **5.24**: Series summation
- **5.25**: π approximation
- **5.26**: e approximation
- **5.35**: Mathematical series summation
- **5.43**: Combinations calculation
- **5.45**: Mean and standard deviation

### Pattern and Display Problems (5.15, 5.17-5.20, 5.27-5.29)
- **5.15**: ASCII character table
- **5.16**: Integer factorization
- **5.17**: Number pyramid
- **5.18**: Four different patterns
- **5.19**: Powers of 2 pyramid
- **5.20**: Prime numbers between 2 and 1000
- **5.27**: Leap years display
- **5.28**: First day of each month
- **5.29**: Calendar display

### String Processing (5.46-5.51)
- **5.46**: Reverse a string
- **5.47**: ISBN-13 validation
- **5.48**: Characters at odd positions
- **5.49**: Count vowels and consonants
- **5.50**: Count uppercase letters
- **5.51**: Longest common prefix

### Number System Conversions (5.37, 5.38, 5.44)
- **5.37**: Decimal to binary
- **5.38**: Decimal to octal
- **5.44**: Display binary representation

### Games and Simulations (5.32, 5.34, 5.40, 5.41)
- **5.32**: Two-digit lottery
- **5.33**: Perfect numbers
- **5.34**: Rock-paper-scissors game
- **5.40**: Coin flip simulation
- **5.41**: Find max and count occurrences

---

## Key Takeaways

### Best Practices
1. **Think before coding** - Plan your algorithm first
2. **Code incrementally** - Start simple, then add complexity
3. **Avoid infinite loops** - Ensure condition eventually becomes false
4. **Watch for off-by-one errors** - Double-check loop bounds
5. **Use appropriate loop type** - for (known iterations), while (unknown iterations), do-while (at least once)

### Common Pitfalls
- Infinite loops due to missing increment/decrement
- Off-by-one errors in conditions
- Floating-point precision issues
- Semicolon after for clause
- Variable scope issues

### Performance Considerations
- Nested loops can be extremely slow
- Order of operations affects floating-point accuracy
- Break statements can improve efficiency

### Programming Philosophy
- Loops are fundamental to programming
- Multiple solutions exist for most problems
- Break problems into smaller subproblems
- Test and debug incrementally
