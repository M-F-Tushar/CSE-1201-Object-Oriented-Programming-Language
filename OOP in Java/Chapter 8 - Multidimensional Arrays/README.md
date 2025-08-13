# Chapter 8: Multidimensional Arrays - Complete Study Guide

## 8.1 Introduction

### Key Concept
Data in a table or matrix can be represented using a two-dimensional array. While one-dimensional arrays store linear collections of elements, two-dimensional arrays can store matrices or tables.

### Real-World Example: Distance Table
Consider a table showing distances between cities:

| City | Chicago | Boston | New York | Atlanta | Miami | Dallas | Houston |
|------|---------|--------|----------|---------|--------|---------|---------|
| Chicago | 0 | 983 | 787 | 714 | 1375 | 967 | 1087 |
| Boston | 983 | 0 | 214 | 1102 | 1763 | 1723 | 1842 |
| New York | 787 | 214 | 0 | 888 | 1549 | 1548 | 1627 |
| Atlanta | 714 | 1102 | 888 | 0 | 661 | 781 | 810 |
| Miami | 1375 | 1763 | 1549 | 661 | 0 | 1426 | 1187 |
| Dallas | 967 | 1723 | 1548 | 781 | 1426 | 0 | 239 |
| Houston | 1087 | 1842 | 1627 | 810 | 1187 | 239 | 0 |

**Java Implementation:**
```java
double[][] distances = {
    {0, 983, 787, 714, 1375, 967, 1087},
    {983, 0, 214, 1102, 1763, 1723, 1842},
    {787, 214, 0, 888, 1549, 1548, 1627},
    {714, 1102, 888, 0, 661, 781, 810},
    {1375, 1763, 1549, 661, 0, 1426, 1187},
    {967, 1723, 1548, 781, 1426, 0, 239},
    {1087, 1842, 1627, 810, 1187, 239, 0}
};
```

---

## 8.2 Two-Dimensional Array Basics

### 8.2.1 Declaration and Creation

#### Declaration Syntax
```java
elementType[][] arrayRefVar;          // Preferred
elementType arrayRefVar[][];          // Allowed, but not preferred
```

#### Examples:
```java
int[][] matrix;                       // Declares a 2D array variable
int matrix[][];                       // Alternative syntax (not preferred)
```

#### Creation Syntax
```java
matrix = new int[5][5];               // Creates a 5×5 array
```

#### Array Indexing
- Two subscripts are used: one for row, one for column
- Both indices start from 0
- Access element: `arrayName[rowIndex][columnIndex]`

**Visual Representation:**
```
matrix = new int[5][5];
     [0] [1] [2] [3] [4]
[0]   0   0   0   0   0
[1]   0   0   0   0   0
[2]   0   0   7   0   0   ← matrix[2][1] = 7;
[3]   0   0   0   0   0
[4]   0   0   0   0   0
```

#### Array Initialization
**Method 1: Array Initializer**
```java
int[][] array = {
    {1, 2, 3},
    {4, 5, 6},
    {7, 8, 9},
    {10, 11, 12}
};
```

**Method 2: Explicit Assignment**
```java
int[][] array = new int[4][3];
array[0][0] = 1; array[0][1] = 2; array[0][2] = 3;
array[1][0] = 4; array[1][1] = 5; array[1][2] = 6;
array[2][0] = 7; array[2][1] = 8; array[2][2] = 9;
array[3][0] = 10; array[3][1] = 11; array[3][2] = 12;
```

**Important Note:** 
❌ `matrix[2, 1]` is WRONG
✅ `matrix[2][1]` is CORRECT

### 8.2.2 Obtaining Array Lengths

**Key Concept:** A 2D array is actually an array of 1D arrays.

```java
int[][] x = new int[3][4];
```

**Length Properties:**
- `x.length` = 3 (number of rows)
- `x[0].length` = 4 (columns in row 0)
- `x[1].length` = 4 (columns in row 1)
- `x[2].length` = 4 (columns in row 2)

**Visual Structure:**
```
x ──→ x[0] ──→ [0][0] [0][1] [0][2] [0][3]
      x[1] ──→ [1][0] [1][1] [1][2] [1][3]
      x[2] ──→ [2][0] [2][1] [2][2] [2][3]
```

### 8.2.3 Ragged Arrays

**Definition:** Arrays where rows can have different lengths.

**Example:**
```java
int[][] triangleArray = {
    {1, 2, 3, 4, 5},    // 5 elements
    {2, 3, 4, 5},       // 4 elements
    {3, 4, 5},          // 3 elements
    {4, 5},             // 2 elements
    {5}                 // 1 element
};
```

**Visual Representation:**
```
1 2 3 4 5
2 3 4 5
3 4 5
4 5
5
```

**Creating Ragged Arrays Dynamically:**
```java
int[][] triangleArray = new int[5][];
triangleArray[0] = new int[5];
triangleArray[1] = new int[4];
triangleArray[2] = new int[3];
triangleArray[3] = new int[2];
triangleArray[4] = new int[1];

// Now assign values
triangleArray[0][3] = 50;
triangleArray[4][0] = 45;
```

**Important Syntax Rule:**
✅ `new int[5][]` - First dimension required
❌ `new int[][]` - Invalid syntax

---

## 8.2 Check Point Exercises

### 8.1 Array Declaration and Creation
**Question:** Declare an array reference variable for a two-dimensional array of int values, create a 4-by-5 int matrix, and assign it to the variable.

**Answer:**
```java
int[][] matrix;              // Declaration
matrix = new int[4][5];      // Creation and assignment
// Or combined:
int[][] matrix = new int[4][5];
```

### 8.2 Ragged Arrays
**Question:** Can the rows in a two-dimensional array have different lengths?

**Answer:** Yes, rows can have different lengths. These are called ragged arrays. Each row is itself an array, so they can be of different sizes.

### 8.3 Code Output
**Question:** What is the output of the following code?
```java
int[][] array = new int[5][6];
int[] x = {1, 2};
array[0] = x;
System.out.println("array[0][1] is " + array[0][1]);
```

**Answer:** `array[0][1] is 2`

**Explanation:** 
- `array[0]` is assigned to reference the array `x`
- `x[1]` contains the value 2
- Therefore, `array[0][1]` returns 2

### 8.4 Valid Statements
**Question:** Which of the following statements are valid?
```java
int[][] r = new int[2];       // ❌ Missing second dimension
int[] x = new int[];          // ❌ Missing size
int[][] y = new int[3][];     // ✅ Valid ragged array
int[][] z = {{1, 2}};         // ✅ Valid initialization
int[][] m = {{1, 2}, {2, 3}}; // ✅ Valid initialization
int[][] n = {{1, 2}, {2, 3}, }; // ✅ Valid (trailing comma allowed)
```

---

## 8.3 Processing Two-Dimensional Arrays

### Key Concept
Nested for loops are commonly used to process two-dimensional arrays.

### Common Processing Patterns

#### 1. Initializing with User Input
```java
java.util.Scanner input = new Scanner(System.in);
System.out.println("Enter " + matrix.length + " rows and " + 
                   matrix[0].length + " columns: ");
for (int row = 0; row < matrix.length; row++) {
    for (int column = 0; column < matrix[row].length; column++) {
        matrix[row][column] = input.nextInt();
    }
}
```

#### 2. Initializing with Random Values
```java
for (int row = 0; row < matrix.length; row++) {
    for (int column = 0; column < matrix[row].length; column++) {
        matrix[row][column] = (int)(Math.random() * 100);
    }
}
```

#### 3. Printing Arrays
```java
for (int row = 0; row < matrix.length; row++) {
    for (int column = 0; column < matrix[row].length; column++) {
        System.out.print(matrix[row][column] + " ");
    }
    System.out.println(); // New line after each row
}
```

#### 4. Summing All Elements
```java
int total = 0;
for (int row = 0; row < matrix.length; row++) {
    for (int column = 0; column < matrix[row].length; column++) {
        total += matrix[row][column];
    }
}
```

#### 5. Summing Elements by Column
```java
for (int column = 0; column < matrix[0].length; column++) {
    int total = 0;
    for (int row = 0; row < matrix.length; row++) {
        total += matrix[row][column];
    }
    System.out.println("Sum for column " + column + " is " + total);
}
```

#### 6. Finding Row with Largest Sum
```java
int maxRow = 0;
int indexOfMaxRow = 0;

// Get sum of the first row
for (int column = 0; column < matrix[0].length; column++) {
    maxRow += matrix[0][column];
}

// Compare with other rows
for (int row = 1; row < matrix.length; row++) {
    int totalOfThisRow = 0;
    for (int column = 0; column < matrix[row].length; column++) {
        totalOfThisRow += matrix[row][column];
    }
    
    if (totalOfThisRow > maxRow) {
        maxRow = totalOfThisRow;
        indexOfMaxRow = row;
    }
}

System.out.println("Row " + indexOfMaxRow + 
                   " has the maximum sum of " + maxRow);
```

#### 7. Random Shuffling
```java
for (int i = 0; i < matrix.length; i++) {
    for (int j = 0; j < matrix[i].length; j++) {
        int i1 = (int)(Math.random() * matrix.length);
        int j1 = (int)(Math.random() * matrix[i].length);
        
        // Swap matrix[i][j] with matrix[i1][j1]
        int temp = matrix[i][j];
        matrix[i][j] = matrix[i1][j1];
        matrix[i1][j1] = temp;
    }
}
```

---

## 8.3 Check Point Exercises

### 8.5 Array Traversal Output
**Question:** Show the output of the following code:
```java
int[][] array = {{1, 2}, {3, 4}, {5, 6}};
for (int i = array.length - 1; i >= 0; i--) {
    for (int j = array[i].length - 1; j >= 0; j--) {
        System.out.print(array[i][j] + " ");
    }
    System.out.println();
}
```

**Answer:**
```
6 5 
4 3 
2 1 
```

**Explanation:** The loops traverse the array from last row to first row, and within each row from last column to first column.

### 8.6 Column Sum Output
**Question:** Show the output of the following code:
```java
int[][] array = {{1, 2}, {3, 4}, {5, 6}};
int sum = 0;
for (int i = 0; i < array.length; i++) {
    sum += array[i][0];
}
System.out.println(sum);
```

**Answer:** `9`

**Explanation:** This sums the first column: `array[0][0] + array[1][0] + array[2][0] = 1 + 3 + 5 = 9`

---

## 8.4 Passing Two-Dimensional Arrays to Methods

### Key Concept
When passing a 2D array to a method, the reference of the array is passed to the method.

### Complete Example: PassTwoDimensionalArray.java
```java
import java.util.Scanner;

public class PassTwoDimensionalArray {
    public static void main(String[] args) {
        int[][] m = getArray(); // Get an array
        
        // Display sum of elements
        System.out.println("\nSum of all elements is " + sum(m));
    }
    
    public static int[][] getArray() {
        // Create a Scanner
        Scanner input = new Scanner(System.in);
        
        // Enter array values
        int[][] m = new int[3][4];
        System.out.println("Enter " + m.length + " rows and " + 
                          m[0].length + " columns: ");
        for (int i = 0; i < m.length; i++) {
            for (int j = 0; j < m[i].length; j++) {
                m[i][j] = input.nextInt();
            }
        }
        
        return m;
    }
    
    public static int sum(int[][] m) {
        int total = 0;
        for (int row = 0; row < m.length; row++) {
            for (int column = 0; column < m[row].length; column++) {
                total += m[row][column];
            }
        }
        
        return total;
    }
}
```

**Sample Run:**
```
Enter 3 rows and 4 columns:
1 2 3 4
5 6 7 8
9 10 11 12

Sum of all elements is 78
```

**Key Points:**
- `getArray()` method returns a 2D array
- `sum()` method takes a 2D array parameter
- Use `m.length` for number of rows
- Use `m[row].length` for number of columns in a specific row

---

## 8.4 Check Point Exercise

### 8.7 Method Return Values
**Question:** Show the output of the following code:
```java
public class Test {
    public static void main(String[] args) {
        int[][] array = {{1, 2, 3, 4}, {5, 6, 7, 8}};
        System.out.println(m1(array)[0]);
        System.out.println(m1(array)[1]);
    }
    
    public static int[] m1(int[][] m) {
        int[] result = new int[2];
        result[0] = m.length;
        result[1] = m[0].length;
        return result;
    }
}
```

**Answer:**
```
2
4
```

**Explanation:**
- `m.length` = 2 (number of rows)
- `m[0].length` = 4 (number of columns in first row)
- Method returns an array `{2, 4}`

---

## 8.5 Case Study: Grading a Multiple-Choice Test

### Problem Description
Write a program to grade multiple-choice tests for 8 students with 10 questions each.

### Data Structure
**Students' Answers:**
```
         0 1 2 3 4 5 6 7 8 9
Student 0: A B A C C D E E A D
Student 1: D B A B C A E E A D
Student 2: E D D A C B E E A D
Student 3: C B A E D C E E A D
Student 4: A B D C C D E E A D
Student 5: B B E C C D E E A D
Student 6: B B A C C D E E A D
Student 7: E B E C C D E E A D
```

**Answer Key:**
```
Key: D B D C C D A E A D
```

### Complete Solution: GradeExam.java
```java
public class GradeExam {
    /** Main method */
    public static void main(String[] args) {
        // Students' answers to the questions
        char[][] answers = {
            {'A', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
            {'D', 'B', 'A', 'B', 'C', 'A', 'E', 'E', 'A', 'D'},
            {'E', 'D', 'D', 'A', 'C', 'B', 'E', 'E', 'A', 'D'},
            {'C', 'B', 'A', 'E', 'D', 'C', 'E', 'E', 'A', 'D'},
            {'A', 'B', 'D', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
            {'B', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
            {'B', 'B', 'A', 'C', 'C', 'D', 'E', 'E', 'A', 'D'},
            {'E', 'B', 'E', 'C', 'C', 'D', 'E', 'E', 'A', 'D'}
        };
        
        // Key to the questions
        char[] keys = {'D', 'B', 'D', 'C', 'C', 'D', 'A', 'E', 'A', 'D'};
        
        // Grade all answers
        for (int i = 0; i < answers.length; i++) {
            // Grade one student
            int correctCount = 0;
            for (int j = 0; j < answers[i].length; j++) {
                if (answers[i][j] == keys[j]) {
                    correctCount++;
                }
            }
            
            System.out.println("Student " + i + "'s correct count is " + 
                             correctCount);
        }
    }
}
```

**Output:**
```
Student 0's correct count is 7
Student 1's correct count is 6
Student 2's correct count is 5
Student 3's correct count is 4
Student 4's correct count is 8
Student 5's correct count is 7
Student 6's correct count is 7
Student 7's correct count is 7
```

**Algorithm Explanation:**
1. Store student answers in a 2D char array (8 rows × 10 columns)
2. Store correct answers in a 1D char array (10 elements)
3. For each student (outer loop):
   - Initialize correct count to 0
   - For each question (inner loop):
     - Compare student's answer with correct answer
     - If match, increment correct count
   - Display result for current student

---

## 8.6 Case Study: Finding the Closest Pair

### Problem Description
Given a set of points, find the two points that are nearest to each other.

### Algorithm
1. Compute distances between all pairs of points
2. Find the pair with minimum distance

### Mathematical Formula
Distance between points (x₁, y₁) and (x₂, y₂):
```
distance = √[(x₂ - x₁)² + (y₂ - y₁)²]
```

### Complete Solution: FindNearestPoints.java
```java
import java.util.Scanner;

public class FindNearestPoints {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        System.out.print("Enter the number of points: ");
        int numberOfPoints = input.nextInt();
        
        // Create an array to store points
        double[][] points = new double[numberOfPoints][2];
        System.out.print("Enter " + numberOfPoints + " points: ");
        for (int i = 0; i < points.length; i++) {
            points[i][0] = input.nextDouble(); // x coordinate
            points[i][1] = input.nextDouble(); // y coordinate
        }
        
        // p1 and p2 are the indices in the points' array
        int p1 = 0, p2 = 1; // Initial two points
        double shortestDistance = distance(points[p1][0], points[p1][1],
                                         points[p2][0], points[p2][1]);
        
        // Compute distance for every two points
        for (int i = 0; i < points.length; i++) {
            for (int j = i + 1; j < points.length; j++) {
                double distance = distance(points[i][0], points[i][1],
                                         points[j][0], points[j][1]);
                
                if (shortestDistance > distance) {
                    p1 = i; // Update p1
                    p2 = j; // Update p2
                    shortestDistance = distance; // Update shortestDistance
                }
            }
        }
        
        // Display result
        System.out.println("The closest two points are " +
            "(" + points[p1][0] + ", " + points[p1][1] + ") and (" +
            points[p2][0] + ", " + points[p2][1] + ")");
    }
    
    /** Compute the distance between two points (x1, y1) and (x2, y2) */
    public static double distance(double x1, double y1, double x2, double y2) {
        return Math.sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    }
}
```

**Sample Run:**
```
Enter the number of points: 8
Enter 8 points: -1 3 -1 -1 1 1 2 0.5 2 -1 3 3 4 2 4 -0.5
The closest two points are (1.0, 1.0) and (2.0, 0.5)
```

**Algorithm Analysis:**
- **Time Complexity:** O(n²) where n is the number of points
- **Space Complexity:** O(n) for storing points
- The nested loop ensures every pair is checked exactly once

**Visual Representation:**
```
Points: (-1,3), (-1,-1), (1,1), (2,0.5), (2,-1), (3,3), (4,2), (4,-0.5)

    4 |     •(3,3)
    3 | •(-1,3)      •(4,2)
    2 |
    1 |         •(1,1)
    0 |             •(2,0.5)
   -1 | •(-1,-1)   •(2,-1)    •(4,-0.5)
      +--+--+--+--+--+--+--
       -1  0  1  2  3  4
```

**Input File Usage:**
You can store input in a file and use input redirection:
```bash
java FindNearestPoints < FindNearestPoints.txt
```

---

## 8.7 Case Study: Sudoku

### Problem Description
Verify whether a given Sudoku solution is correct.

### Sudoku Rules
A valid 9×9 Sudoku solution must have:
1. Numbers 1-9 in every row
2. Numbers 1-9 in every column  
3. Numbers 1-9 in every 3×3 box

### Data Representation
- Use 2D integer array: `int[][] grid = new int[9][9]`
- Value 0 represents empty cell (for puzzles)
- Values 1-9 represent filled cells

### Grid Structure Visualization
```
Grid Layout with 3×3 boxes:
┌─────┬─────┬─────┐
│ 0 1 │ 2 3 │ 4 5 │
│ 6 7 │ 8 0 │ 1 2 │
├─────┼─────┼─────┤
│ 3 4 │ 5 6 │ 7 8 │
│ 9 0 │ 1 2 │ 3 4 │
├─────┼─────┼─────┤
│ 5 6 │ 7 8 │ 9 0 │
│ 1 2 │ 3 4 │ 5 6 │
└─────┴─────┴─────┘
```

### Box Starting Cell Formula
For any cell `grid[i][j]`, the starting cell of its 3×3 box is:
`grid[(i / 3) * 3][(j / 3) * 3]`

**Example:**
- For `grid[8][5]`: Starting cell = `grid[6][3]`
- For `grid[2][8]`: Starting cell = `grid[0][6]`

### Complete Solution: CheckSudokuSolution.java
```java
import java.util.Scanner;

public class CheckSudokuSolution {
    public static void main(String[] args) {
        // Read a Sudoku solution
        int[][] grid = readASolution();
        
        System.out.println(isValid(grid) ? "Valid solution" : 
                                          "Invalid solution");
    }
    
    /** Read a Sudoku solution from the console */
    public static int[][] readASolution() {
        // Create a Scanner
        Scanner input = new Scanner(System.in);
        
        System.out.println("Enter a Sudoku puzzle solution:");
        int[][] grid = new int[9][9];
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                grid[i][j] = input.nextInt();
            }
        }
        
        return grid;
    }
    
    /** Check whether a solution is valid */
    public static boolean isValid(int[][] grid) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (grid[i][j] < 1 || grid[i][j] > 9 || 
                    !isValid(i, j, grid)) {
                    return false;
                }
            }
        }
        return true; // The solution is valid
    }
    
    /** Check whether grid[i][j] is valid in the grid */
    public static boolean isValid(int i, int j, int[][] grid) {
        // Check whether grid[i][j] is unique in i's row
        for (int column = 0; column < 9; column++) {
            if (column != j && grid[i][column] == grid[i][j]) {
                return false;
            }
        }
        
        // Check whether grid[i][j] is unique in j's column
        for (int row = 0; row < 9; row++) {
            if (row != i && grid[row][j] == grid[i][j]) {
                return false;
            }
        }
        
        // Check whether grid[i][j] is unique in the 3-by-3 box
        for (int row = (i / 3) * 3; row < (i / 3) * 3 + 3; row++) {
            for (int col = (j / 3) * 3; col < (j / 3) * 3 + 3; col++) {
                if (row != i && col != j && grid[row][col] == grid[i][j]) {
                    return false;
                }
            }
        }
        
        return true; // The current value at grid[i][j] is valid
    }
}
```

**Sample Run:**
```
Enter a Sudoku puzzle solution:
9 6 3 1 7 4 2 5 8
1 7 8 3 2 5 6 4 9
2 5 4 6 8 9 7 3 1
8 2 1 4 3 7 5 9 6
4 9 6 8 5 2 3 1 7
7 3 5 9 6 1 8 2 4
5 8 9 7 1 3 4 6 2
3 1 7 2 4 6 9 8 5
6 4 2 5 9 8 1 7 3
Valid solution
```

### Validation Algorithm Explained

**Method 1: `isValid(int[][] grid)`**
- Checks if every cell contains a value 1-9
- Calls `isValid(i, j, grid)` for each cell

**Method 2: `isValid(int i, int j, int[][] grid)`**
1. **Row Check:** Ensure `grid[i][j]` is unique in row `i`
2. **Column Check:** Ensure `grid[i][j]` is unique in column `j`
3. **Box Check:** Ensure `grid[i][j]` is unique in its 3×3 box

### 3×3 Box Traversal Pattern
```java
// Get all cells in a 3-by-3 box starting at grid[r][c]
for (int row = r; row < r + 3; row++) {
    for (int col = c; col < c + 3; col++) {
        // grid[row][col] is in the box
    }
}
```

**Input File Usage:**
```bash
java CheckSudokuSolution < CheckSudokuSolution.txt
```

---

## 8.8 Multidimensional Arrays

### Key Concept
Java supports n-dimensional arrays for any integer n ≥ 3.

### Three-Dimensional Array Declaration and Creation
```java
// Declaration
double[][][] arrayRefVar;

// Creation
double[][][] scores = new double[6][5][2];
```

### Real-World Example: Student Exam Scores
Store exam scores for:
- 6 students
- 5 exams per student  
- 2 parts per exam (multiple-choice and essay)

```java
double[][][] scores = {
    {{7.5, 20.5}, {9.0, 22.5}, {15, 33.5}, {13, 21.5}, {15, 2.5}},
    {{4.5, 21.5}, {9.0, 22.5}, {15, 34.5}, {12, 20.5}, {14, 9.5}},
    {{6.5, 30.5}, {9.4, 10.5}, {11, 33.5}, {11, 23.5}, {10, 2.5}},
    {{6.5, 23.5}, {9.4, 32.5}, {13, 34.5}, {11, 20.5}, {16, 7.5}},
    {{8.5, 26.5}, {9.4, 52.5}, {13, 36.5}, {13, 24.5}, {16, 2.5}},
    {{9.5, 20.5}, {9.4, 42.5}, {13, 31.5}, {12, 20.5}, {16, 6.5}}
};
