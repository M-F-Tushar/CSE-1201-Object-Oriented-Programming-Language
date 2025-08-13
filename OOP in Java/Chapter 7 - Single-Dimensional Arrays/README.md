# Chapter 7: Single-Dimensional Arrays - Complete Guide

## Table of Contents
1. [Introduction to Arrays](#introduction)
2. [Array Basics](#array-basics)
3. [Case Studies](#case-studies)
4. [Array Operations](#array-operations)
5. [Searching and Sorting](#searching-sorting)
6. [Advanced Topics](#advanced-topics)
7. [Checkpoint Questions](#checkpoint-questions)

---

## 1. Introduction to Arrays {#introduction}

### Problem Statement
Imagine you need to read 100 numbers, compute their average, and find how many numbers are above the average. Without arrays, you would need to:
- Declare 100 individual variables (number0, number1, ..., number99)
- Write almost identical code 100 times

This approach is **impractical** and **inefficient**.

### What is an Array?
An **array** is a data structure that stores a fixed-size sequential collection of elements of the same type. Think of it as a collection of variables of the same type, all accessed through a single name.

### Key Benefits
- **Efficient storage**: Store large amounts of data in organized manner
- **Easy access**: Access elements using index notation
- **Simplified coding**: Reduce repetitive code significantly

---

## 2. Array Basics {#array-basics}

### 2.1 Declaring Array Variables

#### Syntax
```java
elementType[] arrayRefVar;  // Preferred style
// OR
elementType arrayRefVar[];  // C/C++ style (not preferred)
```

#### Examples
```java
double[] myList;        // Declares array variable
int[] scores;           // Array of integers
String[] names;         // Array of strings
char[] letters;         // Array of characters
```

#### Important Notes
- Declaration only creates a storage location for the array reference
- No memory is allocated for the array itself
- Initial value of array variable is `null`

### 2.2 Creating Arrays

#### Syntax
```java
arrayRefVar = new elementType[arraySize];
```

#### Combined Declaration and Creation
```java
elementType[] arrayRefVar = new elementType[arraySize];
```

#### Examples
```java
// Step by step
double[] myList;                    // Declare
myList = new double[10];            // Create

// Combined
double[] myList = new double[10];   // Declare and create
int[] scores = new int[5];          // Array of 5 integers
```

### 2.3 Array Size and Default Values

#### Array Length
- Size is fixed after creation
- Access size using `arrayRefVar.length`
- **Note**: `length` is a property, not a method (no parentheses)

```java
double[] myList = new double[10];
System.out.println(myList.length); // Prints: 10
```

#### Default Values
When an array is created, elements are initialized to:
- **Numeric types**: `0`
- **char type**: `\u0000` (null character)
- **boolean type**: `false`
- **Object references**: `null`

```java
int[] numbers = new int[5];    // All elements are 0
boolean[] flags = new boolean[3]; // All elements are false
```

### 2.4 Accessing Array Elements

#### Index-Based Access
- Array indices are **0-based**: range from `0` to `arrayRefVar.length-1`
- Use square brackets `[]` for access (not parentheses like some languages)

```java
double[] myList = new double[10];

// Assigning values
myList[0] = 5.6;    // First element
myList[1] = 4.5;    // Second element
myList[9] = 11123;  // Last element (index 9 for array of size 10)

// Accessing values
double value = myList[0];           // Get first element
myList[2] = myList[0] + myList[1];  // Use in expressions
```

#### Array Visualization
```
Array: myList (size 10)
Index:  [0]  [1]  [2]  [3]  [4]  [5]  [6]  [7]  [8]  [9]
Value: 5.6  4.5  3.3  13.2  4.0 34.33 34.0 45.45 99.993 11123
```

### 2.5 Array Initializers

#### Shorthand Notation
```java
elementType[] arrayRefVar = {value0, value1, ..., valuek};
```

#### Examples
```java
double[] myList = {1.9, 2.9, 3.4, 3.5};
int[] numbers = {1, 2, 3, 4, 5};
String[] names = {"Alice", "Bob", "Charlie"};
```

#### Equivalent Long Form
```java
// This initializer:
double[] myList = {1.9, 2.9, 3.4, 3.5};

// Is equivalent to:
double[] myList = new double[4];
myList[0] = 1.9;
myList[1] = 2.9;
myList[2] = 3.4;
myList[3] = 3.5;
```

#### Important Rules
- Must declare, create, and initialize in **one statement**
- Cannot split the initialization:
```java
// WRONG - This will cause compilation error
double[] myList;
myList = {1.9, 2.9, 3.4, 3.5};  // Error!

// CORRECT
double[] myList = {1.9, 2.9, 3.4, 3.5};
```

### 2.6 Processing Arrays

Arrays are commonly processed using loops, especially `for` loops, because:
1. All elements are the same type
2. Array size is known
3. Sequential processing is natural

#### Common Array Processing Patterns

##### 1. Initializing with Input Values
```java
Scanner input = new Scanner(System.in);
double[] myList = new double[10];

System.out.print("Enter " + myList.length + " values: ");
for (int i = 0; i < myList.length; i++) {
    myList[i] = input.nextDouble();
}
```

##### 2. Initializing with Random Values
```java
double[] myList = new double[10];
for (int i = 0; i < myList.length; i++) {
    myList[i] = Math.random() * 100;  // Random values 0-99.999...
}
```

##### 3. Displaying Array Elements
```java
// Regular arrays
for (int i = 0; i < myList.length; i++) {
    System.out.print(myList[i] + " ");
}

// Special case: char arrays can be printed directly
char[] city = {'D', 'a', 'l', 'l', 'a', 's'};
System.out.println(city);  // Prints: Dallas
```

##### 4. Summing All Elements
```java
double total = 0;
for (int i = 0; i < myList.length; i++) {
    total += myList[i];
}
System.out.println("Sum: " + total);
```

##### 5. Finding the Largest Element
```java
double max = myList[0];  // Start with first element
for (int i = 1; i < myList.length; i++) {
    if (myList[i] > max) {
        max = myList[i];
    }
}
System.out.println("Maximum: " + max);
```

##### 6. Finding Index of Largest Element
```java
double max = myList[0];
int indexOfMax = 0;
for (int i = 1; i < myList.length; i++) {
    if (myList[i] > max) {
        max = myList[i];
        indexOfMax = i;
    }
}
System.out.println("Max value " + max + " at index " + indexOfMax);
```

##### 7. Random Shuffling (Fisher-Yates Algorithm)
```java
for (int i = myList.length - 1; i > 0; i--) {
    // Generate random index from 0 to i
    int j = (int)(Math.random() * (i + 1));
    
    // Swap myList[i] with myList[j]
    double temp = myList[i];
    myList[i] = myList[j];
    myList[j] = temp;
}
```

##### 8. Shifting Elements Left
```java
// Save first element
double temp = myList[0];

// Shift all elements one position left
for (int i = 1; i < myList.length; i++) {
    myList[i - 1] = myList[i];
}

// Put first element at the end
myList[myList.length - 1] = temp;
```

##### 9. Simplifying Coding with Arrays
```java
// Instead of lengthy if-else statements
String[] months = {"January", "February", "March", "April", 
                   "May", "June", "July", "August", 
                   "September", "October", "November", "December"};

System.out.print("Enter month number (1-12): ");
int monthNumber = input.nextInt();
System.out.println("The month is " + months[monthNumber - 1]);
```

### 2.7 Enhanced For Loop (foreach)

#### Syntax
```java
for (elementType element : arrayRefVar) {
    // Process the element
}
```

#### Examples
```java
double[] myList = {1.9, 2.9, 3.4, 3.5};

// Traditional for loop
for (int i = 0; i < myList.length; i++) {
    System.out.println(myList[i]);
}

// Enhanced for loop (foreach)
for (double element : myList) {
    System.out.println(element);
}
```

#### When to Use Enhanced For Loop
- **Use when**: Reading/processing elements sequentially
- **Don't use when**: 
  - Need index information
  - Want to modify array elements
  - Need to traverse in reverse order
  - Need to skip elements

### 2.8 Common Programming Errors

#### ArrayIndexOutOfBoundsException
```java
int[] list = new int[5];  // Valid indices: 0, 1, 2, 3, 4

// These will throw ArrayIndexOutOfBoundsException:
list[5] = 10;   // Index 5 is out of bounds
list[-1] = 5;   // Negative index
```

#### Off-by-One Errors
```java
int[] list = new int[10];

// WRONG - uses <= instead of <
for (int i = 0; i <= list.length; i++) {  // Will access list[10]!
    System.out.print(list[i] + " ");
}

// CORRECT
for (int i = 0; i < list.length; i++) {
    System.out.print(list[i] + " ");
}
```

---

## 3. Case Studies {#case-studies}

### Case Study 1: Analyzing Numbers

**Problem**: Write a program that reads n numbers, calculates their average, and counts how many are above average.

#### Complete Solution
```java
public class AnalyzeNumbers {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        
        // Get array size from user
        System.out.print("Enter the number of items: ");
        int n = input.nextInt();
        
        // Create array and initialize variables
        double[] numbers = new double[n];
        double sum = 0;
        
        // Read numbers and calculate sum
        System.out.print("Enter the numbers: ");
        for (int i = 0; i < n; i++) {
            numbers[i] = input.nextDouble();
            sum += numbers[i];
        }
        
        // Calculate average
        double average = sum / n;
        
        // Count numbers above average
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (numbers[i] > average) {
                count++;
            }
        }
        
        // Display results
        System.out.println("Average is " + average);
        System.out.println("Number of elements above average is " + count);
    }
}
```

#### Sample Run
```
Enter the number of items: 10
Enter the numbers: 3.4 5 6 1 6.5 7.8 3.5 8.5 6.3 9.5
Average is 5.75
Number of elements above the average is 6
```

### Case Study 2: Deck of Cards

**Problem**: Create a program that randomly selects four cards from a standard 52-card deck.

#### Card Representation System
- Cards numbered 0-51
- **Suits**: Spades (0-12), Hearts (13-25), Diamonds (26-38), Clubs (39-51)
- **Rank calculation**: `cardNumber % 13`
- **Suit calculation**: `cardNumber / 13`

#### Mapping Tables
```java
String[] suits = {"Spades", "Hearts", "Diamonds", "Clubs"};
String[] ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9", 
                  "10", "Jack", "Queen", "King"};
```

#### Complete Solution
```java
public class DeckOfCards {
    public static void main(String[] args) {
        // Create deck and lookup arrays
        int[] deck = new int[52];
        String[] suits = {"Spades", "Hearts", "Diamonds", "Clubs"};
        String[] ranks = {"Ace", "2", "3", "4", "5", "6", "7", "8", "9",
                          "10", "Jack", "Queen", "King"};
        
        // Initialize deck with values 0-51
        for (int i = 0; i < deck.length; i++) {
            deck[i] = i;
        }
        
        // Shuffle the deck using Fisher-Yates algorithm
        for (int i = 0; i < deck.length; i++) {
            int index = (int)(Math.random() * deck.length);
            // Swap deck[i] with deck[index]
            int temp = deck[i];
            deck[i] = deck[index];
            deck[index] = temp;
        }
        
        // Display first four cards
        for (int i = 0; i < 4; i++) {
            String suit = suits[deck[i] / 13];
            String rank = ranks[deck[i] % 13];
            System.out.println("Card number " + deck[i] + ": " 
                             + rank + " of " + suit);
        }
    }
}
```

#### Sample Output
```
Card number 6: 7 of Spades
Card number 48: 10 of Clubs
Card number 11: Queen of Spades
Card number 24: Queen of Hearts
```

### Case Study 3: Counting Letter Occurrences

**Problem**: Generate 100 random lowercase letters and count the occurrence of each letter.

#### Strategy
1. Create array of 100 random characters
2. Create array of 26 integers to count each letter (a-z)
3. Use ASCII arithmetic: `counts[chars[i] - 'a']++`

#### Complete Solution
```java
public class CountLettersInArray {
    public static void main(String[] args) {
        // Create array of random characters
        char[] chars = createArray();
        
        // Display the array
        System.out.println("The lowercase letters are:");
        displayArray(chars);
        
        // Count occurrences
        int[] counts = countLetters(chars);
        
        // Display counts
        System.out.println();
        System.out.println("The occurrences of each letter are:");
        displayCounts(counts);
    }
    
    public static char[] createArray() {
        char[] chars = new char[100];
        for (int i = 0; i < chars.length; i++) {
            chars[i] = RandomCharacter.getRandomLowerCaseLetter();
        }
        return chars;
    }
    
    public static void displayArray(char[] chars) {
        for (int i = 0; i < chars.length; i++) {
            if ((i + 1) % 20 == 0) {
                System.out.println(chars[i]);
            } else {
                System.out.print(chars[i] + " ");
            }
        }
    }
    
    public static int[] countLetters(char[] chars) {
        int[] counts = new int[26];  // One for each letter a-z
        
        for (int i = 0; i < chars.length; i++) {
            counts[chars[i] - 'a']++;  // ASCII arithmetic
        }
        
        return counts;
    }
    
    public static void displayCounts(int[] counts) {
        for (int i = 0; i < counts.length; i++) {
            if ((i + 1) % 10 == 0) {
                System.out.println(counts[i] + " " + (char)(i + 'a'));
            } else {
                System.out.print(counts[i] + " " + (char)(i + 'a') + " ");
            }
        }
    }
}
```

---

## 4. Array Operations {#array-operations}

### 4.1 Copying Arrays

#### Problem with Assignment Operator
```java
int[] list1 = {1, 2, 3, 4, 5};
int[] list2 = {6, 7, 8, 9, 10};

list2 = list1;  // This does NOT copy elements!
```

This assignment only copies the **reference**, not the array contents. Both variables now point to the same array.

#### Method 1: Loop-Based Copying
```java
int[] sourceArray = {2, 3, 1, 5, 10};
int[] targetArray = new int[sourceArray.length];

for (int i = 0; i < sourceArray.length; i++) {
    targetArray[i] = sourceArray[i];
}
```

#### Method 2: System.arraycopy
```java
System.arraycopy(sourceArray, srcPos, targetArray, tarPos, length);
```

**Parameters**:
- `sourceArray`: Source array
- `srcPos`: Starting position in source
- `targetArray`: Destination array (must be pre-allocated)
- `tarPos`: Starting position in destination
- `length`: Number of elements to copy

**Example**:
```java
int[] source = {3, 4, 5};
int[] target = new int[source.length];
System.arraycopy(source, 0, target, 0, source.length);
```

### 4.2 Passing Arrays to Methods

#### Key Concepts
- Arrays are **objects** in Java
- When you pass an array to a method, you pass the **reference**
- Changes made to array elements in the method **affect** the original array
- This is called **pass-by-sharing**

#### Example: Why Primitive vs Array Passing Differs
```java
public class TestPassArray {
    public static void main(String[] args) {
        int[] a = {1, 2};
        
        // This won't work - primitives are passed by value
        System.out.println("Before swap: " + a[0] + ", " + a[1]);
        swap(a[0], a[1]);
        System.out.println("After swap: " + a[0] + ", " + a[1]);
        // Output: Before swap: 1, 2
        //         After swap: 1, 2 (no change!)
        
        // This works - array reference is passed
        System.out.println("Before array swap: " + a[0] + ", " + a[1]);
        swapFirstTwoInArray(a);
        System.out.println("After array swap: " + a[0] + ", " + a[1]);
        // Output: Before array swap: 1, 2
        //         After array swap: 2, 1 (swapped!)
    }
    
    // This method fails to swap because it works with copies
    public static void swap(int n1, int n2) {
        int temp = n1;
        n1 = n2;
        n2 = temp;
    }
    
    // This method succeeds because it modifies the actual array
    public static void swapFirstTwoInArray(int[] array) {
        int temp = array[0];
        array[0] = array[1];
        array[1] = temp;
    }
}
```

#### Anonymous Arrays
You can create arrays without explicit reference variables:
```java
public static void printArray(int[] array) {
    for (int i = 0; i < array.length; i++) {
        System.out.print(array[i] + " ");
    }
}

// Call with anonymous array
printArray(new int[]{3, 1, 2, 6, 4, 2});
```

### 4.3 Returning Arrays from Methods

Methods can return arrays by returning the array reference:

```java
public static int[] reverse(int[] list) {
    int[] result = new int[list.length];
    
    for (int i = 0, j = result.length - 1; i < list.length; i++, j--) {
        result[j] = list[i];
    }
    
    return result;  // Return the array reference
}

// Usage
int[] list1 = {1, 2, 3, 4, 5, 6};
int[] list2 = reverse(list1);  // list2 gets the reversed array
```

### 4.4 Variable-Length Argument Lists

#### Syntax
```java
public static void methodName(dataType... parameterName) {
    // Method body - parameterName is treated as an array
}
```

#### Example
```java
public class VarArgsDemo {
    public static void main(String[] args) {
        printMax(34, 3, 3, 2, 56.5);        // Variable arguments
        printMax(new double[]{1, 2, 3});     // Array argument
    }
    
    public static void printMax(double... numbers) {
        if (numbers.length == 0) {
            System.out.println("No argument passed");
            return;
        }
        
        double result = numbers[0];
        for (int i = 1; i < numbers.length; i++) {
            if (numbers[i] > result) {
                result = numbers[i];
            }
        }
        
        System.out.println("The max value is " + result);
    }
}
```

#### Rules for Variable-Length Parameters
1. Only **one** variable-length parameter per method
2. Must be the **last** parameter
3. Any regular parameters must come **before** it

---

## 5. Searching and Sorting {#searching-sorting}

### 5.1 Linear Search

#### How It Works
Linear search compares the key with each element sequentially until found or array is exhausted.

#### Implementation
```java
public class LinearSearch {
    public static int linearSearch(int[] list, int key) {
        for (int i = 0; i < list.length; i++) {
            if (key == list[i]) {
                return i;  // Found at index i
            }
        }
        return -1;  // Not found
    }
}
```

#### Performance Analysis
- **Best case**: O(1) - found at first position
- **Worst case**: O(n) - found at last position or not found
- **Average case**: O(n/2) - on average, check half the elements

#### Usage Example
```java
int[] list = {1, 4, 4, 2, 5, -3, 6, 2};
int i = linearSearch(list, 4);   // Returns 1 (first occurrence)
int j = linearSearch(list, -4);  // Returns -1 (not found)
int k = linearSearch(list, -3);  // Returns 5
```

### 5.2 Binary Search

#### Prerequisites
- Array must be **sorted** in ascending order

#### How It Works
1. Compare key with middle element
2. If key < middle: search left half
3. If key = middle: found!
4. If key > middle: search right half
5. Repeat until found or search space exhausted

#### Step-by-Step Example
Searching for key 11 in `{2, 4, 7, 10, 11, 45, 50, 59, 60, 66, 69, 70, 79}`:

```
Step 1: low=0, high=12, mid=6
        list[6]=50, key=11 < 50, so search left half
        
Step 2: low=0, high=5, mid=2  
        list[2]=7, key=11 > 7, so search right half
        
Step 3: low=3, high=5, mid=4
        list[4]=11, key=11 = 11, FOUND at index 4!
```

#### Implementation
```java
public class BinarySearch {
    public static int binarySearch(int[] list, int key) {
        int low = 0;
        int high = list.length - 1;
        
        while (high >= low) {
            int mid = (low + high) / 2;
            
            if (key < list[mid]) {
                high = mid - 1;
            } else if (key == list[mid]) {
                return mid;  // Found
            } else {
                low = mid + 1;
            }
        }
        
        return -low - 1;  // Not found, return insertion point
    }
}
```

#### Why Return -low - 1?
When key is not found, returning -low - 1 gives:
- Negative value (indicates not found)
- Insertion point information: `-returnValue - 1` gives where key should be inserted

#### Performance Analysis
- **Time Complexity**: O(log₂n)
- For array of 1024 elements: maximum 11 comparisons vs 1023 for linear search
- Much more efficient for large sorted arrays

### 5.3 Selection Sort

#### How It Works
1. Find smallest element in entire array, swap with first element
2. Find smallest element in remaining array, swap with second element
3. Continue until array is sorted

#### Visual Example
Sorting `{2, 9, 5, 4, 8, 1, 6}`:

```
Initial:  [2, 9, 5, 4, 8, 1, 6]
Step 1:   [1, 9, 5, 4, 8, 2, 6]  // 1 (smallest) swapped with 2
Step 2:   [1, 2, 5, 4, 8, 9, 6]  // 2 (smallest in remaining) swapped with 9
Step 3:   [1, 2, 4, 5, 8, 9, 6]  // 4 swapped with 5
Step 4:   [1, 2, 4, 5, 8, 9, 6]  // 5 already in position
Step 5:   [1, 2, 4, 5, 6, 9, 8]  // 6 swapped with 8
Step 6:   [1, 2, 4, 5, 6, 8, 9]  // 8 swapped with 9
Final:    [1, 2, 4, 5, 6, 8, 9]  // Sorted!
```

#### Implementation
```java
public class SelectionSort {
    public static void selectionSort(double[] list) {
        for (int i = 0; i < list.length - 1; i++) {
            // Find minimum in the subarray list[i..list.length-1]
            double currentMin = list[i];
            int currentMinIndex = i;
            
            for (int j = i + 1; j < list.length; j++) {
                if (currentMin > list[j]) {
                    currentMin = list[j];
                    currentMinIndex = j;
                }
            }
            
            // Swap list[i] with list[currentMinIndex] if necessary
            if (currentMinIndex != i) {
                list[currentMinIndex] = list[i];
                list[i] = currentMin;
            }
        }
    }
}
```

#### Performance Analysis
- **Time Complexity**: O(n²)
- **Space Complexity**: O(1) - sorts in place
- **Stability**: Not stable (equal elements may change relative order)

### 5.4 The java.util.Arrays Class

Java provides built-in methods for common array operations:

#### Sorting
```java
import java.util.Arrays;

double[] numbers = {6.0, 4.4, 1.9, 2.9, 3.4, 3.5};
Arrays.sort(numbers);           // Sort entire array
Arrays.parallelSort(numbers);   // Parallel sort (faster on multi-core)

char[] chars = {'a', 'A', '4', 'F', 'D', 'P'};
Arrays.sort(chars, 1, 3);       // Sort partial array [1, 3)
```

#### Binary Search
```java
int[] list = {2, 4, 7, 10, 11, 45, 50, 59, 60, 66, 69, 70, 79};
int index1 = Arrays.binarySearch(list, 11);  // Returns 4
int index2 = Arrays.binarySearch(list, 12);  // Returns -6 (insertion point)
```

#### Array Comparison
```java
int[] list1 = {2, 4, 7, 10};
int[] list2 = {2, 4, 7, 10};
int[] list3 = {4, 2, 7, 10};

System.out.println(Arrays.equals(list1, list2)); // true
System.out.println(Arrays.equals(list2, list3)); // false
```

#### Filling Arrays
```java
int[] list1 = {2, 4, 7, 10};
Arrays.fill(list1, 5);          // Fill entire array with 5

int[] list2 = {2, 4, 7, 7, 7, 10};
Arrays.fill(list2, 1, 5, 8);    // Fill elements [1, 5) with 8
```

#### String Representation
```java
int[] list = {2, 4, 7, 10};
System.out.println(Arrays.toString(list)); // Prints: [2, 4, 7, 10]
```

---

## 6. Advanced Topics {#advanced-topics}

### 6.1 Command-Line Arguments

The `main` method can receive arguments from the command line through its `String[] args` parameter.

#### Basic Usage
```java
public class TestMain {
    public static void main(String[] args) {
        System.out.println("Number of arguments: " + args.length);
        for (int i = 0; i < args.length; i++) {
            System.out.println("args[" + i + "]: " + args[i]);
        }
    }
}
```

#### Command Line Examples
```bash
java TestMain arg0 arg1 arg2
# Output:
# Number of arguments: 3
# args[0]: arg0
# args[1]: arg1
# args[2]: arg2

java TestMain "First num" alpha 53
# Output:
# Number of arguments: 3
# args[0]: First num
# args[1]: alpha
# args[2]: 53
```

#### Important Notes About Command-Line Arguments
- Arguments are separated by spaces
- Strings with spaces must be enclosed in double quotes
- All arguments are received as strings (even numbers)
- If no arguments provided, `args.length` is 0 (not null)

### 6.2 Case Study: Command-Line Calculator

**Problem**: Create a calculator that performs arithmetic operations on integers passed as command-line arguments.

#### Usage
```bash
java Calculator 2 + 3    # Output: 2 + 3 = 5
java Calculator 10 - 4   # Output: 10 - 4 = 6
java Calculator 7 . 8    # Output: 7 . 8 = 56 (. represents multiplication)
java Calculator 15 / 3   # Output: 15 / 3 = 5
```

#### Complete Implementation
```java
public class Calculator {
    public static void main(String[] args) {
        // Check if correct number of arguments provided
        if (args.length != 3) {
            System.out.println("Usage: java Calculator operand1 operator operand2");
            System.exit(1);
        }
        
        // Parse operands
        int operand1 = Integer.parseInt(args[0]);
        int operand2 = Integer.parseInt(args[2]);
        int result = 0;
        
        // Determine operation based on operator
        switch (args[1].charAt(0)) {
            case '+':
                result = operand1 + operand2;
                break;
            case '-':
                result = operand1 - operand2;
                break;
            case '.':  // Using . instead of * to avoid shell expansion
                result = operand1 * operand2;
                break;
            case '/':
                result = operand1 / operand2;
                break;
            default:
                System.out.println("Unsupported operator: " + args[1]);
                System.exit(1);
        }
        
        // Display result
        System.out.println(args[0] + " " + args[1] + " " + args[2] + " = " + result);
    }
}
```

#### Why Use '.' Instead of '*'?
The asterisk (*) has special meaning in command shells - it expands to all files in the current directory. Using '.' avoids this issue.

---

## 7. Checkpoint Questions and Solutions {#checkpoint-questions}

### Basic Array Concepts

**Question 7.1**: How do you declare an array reference variable and create an array?

**Answer**:
```java
// Declaration
dataType[] arrayRefVar;

// Creation
arrayRefVar = new dataType[arraySize];

// Combined
dataType[] arrayRefVar = new dataType[arraySize];

// Examples
int[] numbers = new int[10];      // Array of 10 integers
double[] scores = new double[5];  // Array of 5 doubles
String[] names = new String[3];   // Array of 3 String references
```

**Question 7.2**: When is memory allocated for an array?

**Answer**: Memory is allocated when the array is **created** using the `new` operator, not when the array variable is declared. Declaration only creates a reference variable.

**Question 7.3**: What is the output of the following code?
```java
int x = 30;
int[] numbers = new int[x];
x = 60;
System.out.println("x is " + x);
System.out.println("The size of numbers is " + numbers.length);
```

**Answer**:
```
x is 60
The size of numbers is 30
```

**Explanation**: The array size is determined at creation time (when x was 30) and cannot be changed afterward.

**Question 7.4**: True or false for the following statements:
- Every element in an array has the same type. **TRUE**
- The array size is fixed after an array reference variable is declared. **FALSE** (size is fixed after creation, not declaration)
- The array size is fixed after it is created. **TRUE**
- The elements in an array must be a primitive data type. **FALSE** (can be objects too)

**Question 7.5**: Which statements are valid?
```java
int i = new int(30);           // INVALID - wrong syntax
double d[] = new double[30];   // VALID - alternative declaration style
char[] r = new char(1..30);    // INVALID - wrong syntax
int i[] = (3, 4, 3, 2);       // INVALID - missing braces and new
float f[] = {2.3, 4.5, 6.6};  // VALID - array initializer
char[] c = new char();         // INVALID - no size specified
```

### Array Access and Processing

**Question 7.6**: How do you access elements in an array?

**Answer**: Use square bracket notation with zero-based indexing:
```java
arrayRefVar[index]  // where index is 0 to arrayRefVar.length-1
```

**Question 7.7**: What is the array index type? What is the lowest index? What is the representation of the third element in array named a?

**Answer**:
- **Index type**: int (or any expression that evaluates to int)
- **Lowest index**: 0
- **Third element**: `a[2]` (since indexing starts at 0)

**Question 7.8**: Write statements to:

**a. Create an array to hold 10 double values:**
```java
double[] array = new double[10];
```

**b. Assign value 5.5 to the last element:**
```java
array[array.length - 1] = 5.5;
```

**c. Display sum of first two elements:**
```java
System.out.println("Sum: " + (array[0] + array[1]));
```

**d. Loop that computes sum of all elements:**
```java
double sum = 0;
for (int i = 0; i < array.length; i++) {
    sum += array[i];
}
System.out.println("Total sum: " + sum);
```

**e. Loop that finds minimum element:**
```java
double min = array[0];
for (int i = 1; i < array.length; i++) {
    if (array[i] < min) {
        min = array[i];
    }
}
System.out.println("Minimum: " + min);
```

**f. Generate random index and display element:**
```java
int randomIndex = (int)(Math.random() * array.length);
System.out.println("Element at index " + randomIndex + ": " + array[randomIndex]);
```

**g. Array initializer with given values:**
```java
double[] array2 = {3.5, 5.5, 4.52, 5.6};
```

### Error Handling and Debugging

**Question 7.9**: What happens when your program attempts to access an array element with an invalid index?

**Answer**: Java throws an `ArrayIndexOutOfBoundsException` at runtime. This is an unchecked exception that terminates the program if not handled.

**Question 7.10**: Identify and fix errors in the following code:
```java
public class Test {
    public static void main(String[] args) {
        double[100] r;                          // ERROR: Wrong syntax
        
        for (int i = 0; i < r.length(); i++);  // ERROR: Semicolon, length()
        r(i) = Math.random * 100;              // ERROR: Parentheses, missing ()
    }
}
```

**Fixed version**:
```java
public class Test {
    public static void main(String[] args) {
        double[] r = new double[100];           // Fix: Proper array declaration
        
        for (int i = 0; i < r.length; i++) {   // Fix: Remove semicolon, length not length()
            r[i] = Math.random() * 100;        // Fix: Square brackets, add parentheses
        }
    }
}
```

**Question 7.11**: What is the output of the following code?
```java
public class Test {
    public static void main(String[] args) {
        int list[] = {1, 2, 3, 4, 5, 6};
        for (int i = 1; i < list.length; i++)
            list[i] = list[i - 1];
        
        for (int i = 0; i < list.length; i++)
            System.out.print(list[i] + " ");
    }
}
```

**Answer**: `1 1 1 1 1 1`

**Explanation**: The first loop copies each element to the next position, starting from index 1. This propagates the first element (1) throughout the array.

### Array Copying and Methods

**Question 7.13**: Use arraycopy method to copy the following array to target array t:
```java
int[] source = {3, 4, 5};
```

**Answer**:
```java
int[] source = {3, 4, 5};
int[] t = new int[source.length];
System.arraycopy(source, 0, t, 0, source.length);
```

**Question 7.14**: Does the following code resize the array?
```java
int[] myList;
myList = new int[10];
// Sometime later...
myList = new int[20];
```

**Answer**: No, this does not resize the array. It creates a **new** array of size 20 and makes `myList` reference it. The original array of size 10 becomes eligible for garbage collection.

### Method Parameters and Return Values

**Question 7.15**: Why is this array reversal code wrong?
```java
int[] list = {1, 2, 3, 5, 4};
for (int i = 0, j = list.length - 1; i < list.length; i++, j--) {
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
```

**Answer**: The condition `i < list.length` causes the loop to continue beyond the midpoint, reversing the array twice. 

**Fixed version**:
```java
int[] list = {1, 2, 3, 5, 4};
for (int i = 0, j = list.length - 1; i < j; i++, j--) {  // Change to i < j
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;
}
```

**Question 7.16**: True or false? When an array is passed to a method, a new array is created and passed to the method.

**Answer**: **FALSE**. Only the reference to the array is passed. The method works with the same array object in memory.

**Question 7.17**: Show the output of the following programs:

**Program (a)**:
```java
public class Test {
    public static void main(String[] args) {
        int number = 0;
        int[] numbers = new int[1];
        m(number, numbers);
        System.out.println("number is " + number + " and numbers[0] is " + numbers[0]);
    }
    
    public static void m(int x, int[] y) {
        x = 3;
        y[0] = 3;
    }
}
```

**Output**: `number is 0 and numbers[0] is 3`

**Explanation**: Primitive `number` is passed by value (unchanged), but array element is modified through reference.

**Program (b)**:
```java
public class Test {
    public static void main(String[] args) {
        int[] list = {1, 2, 3, 4, 5};
        reverse(list);
        for (int i = 0; i < list.length; i++)
            System.out.print(list[i] + " ");
    }
    
    public static void reverse(int[] list) {
        int[] newList = new int[list.length];
        for (int i = 0; i < list.length; i++)
            newList[i] = list[list.length - 1 - i];
        list = newList;  // This only changes local reference!
    }
}
```

**Output**: `1 2 3 4 5`

**Explanation**: The assignment `list = newList` only changes the local reference, not the original array.

### Variable-Length Arguments

**Question 7.19**: What is wrong with these method headers?

```java
// WRONG: Can't have multiple variable-length parameters
public static void print(String... strings, double... numbers)

// WRONG: Variable-length parameter must be last
public static void print(double... numbers, String name)

// WRONG: Can't return variable-length type
public static double... print(double d1, double d2)
```

**Question 7.20**: Can you invoke printMax with these statements?

```java
printMax(1, 2, 2, 1, 4);           // YES - variable arguments
printMax(new double[]{1, 2, 3});   // YES - array argument
printMax(new int[]{1, 2, 3});      // NO - wrong type (int vs double)
```

### Searching Algorithms

**Question 7.21**: How to fix integer overflow in binary search?

**Problem**: `(low + high) / 2` may overflow if values are very large.

**Solution**:
```java
int mid = low + (high - low) / 2;  // Prevents overflow
```

**Question 7.22**: Apply binary search to find key 10 and key 12:

**For key 10 in** `{2, 4, 7, 10, 11, 45, 50, 59, 60, 66, 69, 70, 79}`:
```
Step 1: low=0, high=12, mid=6, list[6]=50 > 10, search left
Step 2: low=0, high=5, mid=2, list[2]=7 < 10, search right  
Step 3: low=3, high=5, mid=4, list[4]=11 > 10, search left
Step 4: low=3, high=3, mid=3, list[3]=10 = 10, FOUND at index 3
```

**For key 12** (not in array):
```
Step 1: low=0, high=12, mid=6, list[6]=50 > 12, search left
Step 2: low=0, high=5, mid=2, list[2]=7 < 12, search right
Step 3: low=3, high=5, mid=4, list[4]=11 < 12, search right
Step 4: low=5, high=5, mid=5, list[5]=45 > 12, search left
Step 5: low=5, high=4, low > high, NOT FOUND, return -(5)-1 = -6
```

**Question 7.23**: If binary search returns -4, is the key in the list? Where should it be inserted?

**Answer**: 
- Key is **not** in the list (negative return indicates not found)
- Insertion point: `-(-4) - 1 = 3`, so key should be inserted at index 3

### Sorting Algorithms

**Question 7.24**: Apply selection sort to `{3.4, 5, 3, 3.5, 2.2, 1.9, 2}`:

```
Initial:  [3.4, 5, 3, 3.5, 2.2, 1.9, 2]
Step 1:   [1.9, 5, 3, 3.5, 2.2, 3.4, 2]  // 1.9 swapped with 3.4
Step 2:   [1.9, 2, 3, 3.5, 2.2, 3.4, 5]  // 2 swapped with 5
Step 3:   [1.9, 2, 2.2, 3.5, 3, 3.4, 5]  // 2.2 swapped with 3
Step 4:   [1.9, 2, 2.2, 3, 3.5, 3.4, 5]  // 3 swapped with 3.5
Step 5:   [1.9, 2, 2.2, 3, 3.4, 3.5, 5]  // 3.4 swapped with 3.5
Step 6:   [1.9, 2, 2.2, 3, 3.4, 3.5, 5]  // Already sorted
Final:    [1.9, 2, 2.2, 3, 3.4, 3.5, 5]
```

**Question 7.25**: How to modify selection sort for decreasing order?

**Answer**: Change the comparison in the inner loop:
```java
// Change this line:
if (currentMin > list[j]) {

// To this:
if (currentMin < list[j]) {  // Find maximum instead of minimum
```

### Arrays Class Methods

**Question 7.26**: What array types can be sorted? Does sort create new array?

**Answer**: 
- All primitive types and objects implementing Comparable
- No, `sort` modifies the original array in-place

**Question 7.27**: Should array be sorted in increasing/decreasing order for binarySearch?

**Answer**: **Increasing order**. The array must be sorted in ascending order for `binarySearch` to work correctly.

**Question 7.28**: Show output:
```java
int[] list1 = {2, 4, 7, 10};
java.util.Arrays.fill(list1, 7);
System.out.println(java.util.Arrays.toString(list1));

int[] list2 = {2, 4, 7, 10};
System.out.println(java.util.Arrays.toString(list2));
System.out.print(java.util.Arrays.equals(list1, list2));
```

**Output**:
```
[7, 7, 7, 7]
[2, 4, 7, 10]
false
```

### Command-Line Arguments

**Question 7.29**: Can main method header be replaced with these alternatives?

```java
public static void main(String args[])     // YES - valid alternative
public static void main(String[] x)       // YES - parameter name can vary
public static void main(String x[])       // YES - alternative syntax
static void main(String x[])              // NO - must be public
```

**Question 7.30**: Show output for different command-line invocations:

**1. `java Test I have a dream`**:
```
Number of strings is 4
I
have
a
dream
```

**2. `java Test "1 2 3"`**:
```
Number of strings is 1
1 2 3
```

**3. `java Test`**:
```
Number of strings is 0
```

---

## Summary

### Key Takeaways

1. **Arrays are objects** that store fixed-size collections of same-type elements
2. **Index-based access** using zero-based indexing (`array[0]` to `array[length-1]`)
3. **Reference semantics** when passing arrays to methods
4. **Enhanced for loops** provide clean syntax for sequential access
5. **Built-in Arrays class** offers sorting, searching, and utility methods
6. **Linear search** is O(n), **binary search** is O(log n) but requires sorted array
7. **Selection sort** is O(n²) but simple to understand and implement

### Best Practices

1. **Prefer** `type[] arrayName` over `type arrayName[]`
2. **Use enhanced for loops** when you don't need indices
3. **Check array bounds** to avoid `ArrayIndexOutOfBoundsException`
4. **Use Arrays class methods** instead of writing your own
5. **Consider performance** - binary search for large sorted arrays
6. **Handle edge cases** like empty arrays and null references

### Common Pitfalls

1. **Off-by-one errors** with array indices
2. **Assignment vs copying** - `array1 = array2` copies reference, not contents
3. **Modifying arrays in methods** affects original array
4. **Overflow in binary search** with large indices
5. **Unsorted arrays** with binary search produce incorrect results

This comprehensive guide covers all concepts, examples, and exercises from Chapter 7, providing detailed explanations and practical examples for mastering single-dimensional arrays in Java.
            
