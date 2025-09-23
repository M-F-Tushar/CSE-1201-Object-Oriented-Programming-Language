/*

Q8 (b) How is multiple inheritance achieved in Java? Explain with example. [10 marks]

Java does not support multiple class inheritance (cannot extend two classes).

Multiple inheritance is achieved via interfaces: a class can implement multiple interfaces.
Example:

interface A { void mA(); }
interface B { void mB(); }
class C implements A, B {
    public void mA() {}
    public void mB() {}
}

*/