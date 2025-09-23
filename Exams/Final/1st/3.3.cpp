/*


Q3 (c) What is a virtual function? How to use it for runtime polymorphism? Example. [10 marks]

Definition: A virtual function is a member function declared with the virtual keyword in a base class and overridden in derived classes. Virtual functions enable dynamic (runtime) binding: which overridden function runs is decided by the actual object type at runtime, not by the pointer/reference type used to call it.

Why use it: Allows code to treat objects uniformly via base pointers/references while allowing derived classes to provide specialized behavior.

Example:

class Animal {
public:
  virtual void speak() { cout << "Animal sound\n"; }
  virtual ~Animal() {}
};

class Dog : public Animal {
public:
  void speak() override { cout << "Woof\n"; }
};

void makeSpeak(Animal &a) { a.speak(); }

int main() {
  Dog d;
  makeSpeak(d);  // prints "Woof" because speak is virtual
}


*/