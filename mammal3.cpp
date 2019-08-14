// mammal3.cpp
// calling constructors and destructors for objects belonging to derived classes
#include <iostream>

enum BREED { YORKIE, CAIRN, DANDIE, SHETLAND, DEOBERMAN, LAB };

class Mammal {
public:
  // constructors
  Mammal();
  ~Mammal();

  // accessors
  int getAge() const { return age; }
  void setAge(int newAge) { age = newAge; }
  int getWeight() const { return weight; }
  void setWeight(int newWeight) { weight = newWeight; }

  // other member functions
  void speak() { std::cout << "Mammal sound!\n"; }
  void sleep() { std::cout << "Shhh. I'm sleeping.\n"; }

protected:
  int age;
  int weight;
};

class Dog : public Mammal {
public:
  // constructors
  Dog();
  ~Dog();

  // accessors
  BREED getBreed() const { return YORKIE; }
  void setBreed(BREED newBreed) { breed = newBreed; }

  // other member functions
  void wagTail() { std::cout << "Tail wagging...\n"; }
  void begForFood() { std::cout << "Begging for food...\n"; }

private:
  BREED breed;
};

Mammal::Mammal():
age(3),
weight(5) {
  std::cout << "Mammal constructor ...\n";
}

Mammal::~Mammal() {
  std::cout << "Mammal destructor ...\n";
}


Dog::Dog():
breed(YORKIE) {
  std::cout << "Dog constructor ...\n";
}

Dog::~Dog() {
  std::cout << "Dog destructor ...\n";
}

int main() {
  Dog fido;   // dog created, Mammal constructor called, then Dog constructor
  fido.speak();
  fido.wagTail();
  std::cout << "Fido is " << fido.getAge() << " years old\n";
  std::cout << "The breed of Fido is a " << fido.getBreed() << ".\n";
  return 0;
}

// whats going on here?
// fido is created and its member functions are called
// Mammal and Dog constructora and destructors output text when called
// fido.getBreed() give 0 which is YORKIE enumerated

// questions
// would lines 46-51 return the same thing if I were just to put (age = 3) and (weight = 5)
// inside the brackets?
