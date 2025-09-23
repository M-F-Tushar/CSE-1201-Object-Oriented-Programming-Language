/*
Q6 (d) Explain the two general forms of super keyword and give a short program. [12 marks]

Two uses of super:

Call superclass constructor: super(args) must be first statement in subclass constructor.

Access superclass members hidden by subclass: super.field or super.method() to invoke the superclass version.

Short example:

class Person {
    String name;
    Person(String name) { this.name = name; }
    String getInfo() { return "Person: " + name; }
}

class Student extends Person {
    String name; // hides Person.name
    Student(String pName, String sName) {
        super(pName); // call parent constructor
        this.name = sName;
    }
    String getInfo() {
        return super.getInfo() + ", Student name (local): " + this.name;
    }
}

*/