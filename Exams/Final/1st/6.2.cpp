/*


Q6 (b) Is the code going to compile? If so, what is the result? (Class inheritance snippet) [6 marks]

Interpreting the typical exam snippet: (common pattern)

class MyClass1 {
  int x = 50;
}

public class MyClass2 extends MyClass1 {
  int x = 40;
}

public class Main {
  public static void main(String[] args) {
    MyClass1 ob1 = new MyClass1();
    System.out.println(ob1.x); // prints 50

    MyClass1 ob2 = new MyClass2();
    System.out.println(ob2.x); // prints 50  (field access is compile-time by reference type)

    MyClass2 ob3 = new MyClass2();
    System.out.println(ob3.x); // prints 40 (ob3 is MyClass2 reference)
  }
}


Explanation: Fields are not polymorphic in Java — field access is resolved at compile time by reference type. Methods (overridden) are polymorphic.

Output:

50
50
40

*/