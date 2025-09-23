/*

Q6 (c) Write lines of code to perform tasks (call superclass constructor, call toString(), etc.) [12 marks]

Short answers (snippets to place in subclass):

Specify that ClassRepresentative inherits from Student:

class ClassRepresentative extends Student { ... }


Call superclass toString() from subclass method:

super.toString();   // inside a method of subclass


Call superclass constructor from subclass constructor (three String args):

public ClassRepresentative(String first, String last, String id) {
    super(first, last, id);
}


Explanation: super(...) calls base class constructor. super.toString() calls superclass implementation of a method.

*/