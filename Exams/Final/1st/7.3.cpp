/*

Q7 (c) Given constraints: 5 methods exist (fn1..fn5), 2 interfaces (each at most 2 methods), 1 abstract class with 1 abstract method. MyClass must implement exactly those 5 methods, must implement 1 interface and extend abstract class, etc. Write code. [15 marks]

Interpretation & solution sketch: You design two interfaces I1, I2 (each with up to 2 methods), abstract class AbsClass with one abstract method. MyClass will extend AbsClass and implement one interface (say I1) and define the remaining concrete methods as required. This is mostly design; sample:

interface I1 {
    void a1();
    void a2();
}

interface I2 {
    void b1();
    void b2();
}

abstract class AbsClass {
    abstract void absMethod();
}

class MyClass extends AbsClass implements I1 {
    @Override
    public void a1() { System.out.println("a1"); }
    @Override
    public void a2() { System.out.println("a2"); }

    // implement abstract method
    @Override
    void absMethod() { System.out.println("absMethod"); }

    // two other methods to reach total of 5 methods
    public void extra1() { }
    public void extra2() { }
}


Explanation: This meets constraints: MyClass extends AbsClass (one abstract method implemented) and implements one interface (I1 with two methods). The class defines 5 methods total.

*/