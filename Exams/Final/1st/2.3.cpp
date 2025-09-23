/*

Q2 (c) Explain output of given Point program (normal & copy constructors). [10 marks]

Program summary:

Point(int i=0, int j=0) prints "Normal constructor called"

Point(const Point &t) prints "Copy constructor called"

Main example (slightly paraphrased):

Point t1;               // default args -> Normal constructor
Point t2(10,20);        // Normal constructor
Point t3(t1);           // Copy constructor
Point t4 = t2;          // Copy constructor


Output sequence:

Normal constructor called
Normal constructor called
Copy constructor called
Copy constructor called


Explanation: Each variable is constructed in the order written. t1 and t2 use the normal constructor. t3(t1) explicitly invokes the copy constructor. Point t4 = t2; syntactic sugar — also invokes copy constructor.

*/