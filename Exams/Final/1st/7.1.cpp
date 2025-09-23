/*

Q7 (a) “Every interface is abstract class but every abstract class is not interface” — justify with examples. [10 marks]

Explanation:

An interface in Java is implicitly abstract; it cannot be instantiated and typically declares method signatures (default/static methods allowed since Java 8).

An abstract class may contain concrete (implemented) methods and fields. It can have state and some behavior shared among subclasses.

Not all abstract classes are interfaces because abstract classes can have constructors, instance fields, and non-abstract methods.

Example:

interface I {
    void m();  // implicitly public abstract
}

abstract class A {
    int x;
    A(int x) { this.x = x; }
    abstract void m();
    void show() { System.out.println(x); }  // concrete method
}


I has only method signatures; A can store data and implemented methods.

*/