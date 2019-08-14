// mammal9.cpp
// calling a virtual function on an array of pointers to respective subclasses
#include <iostream>

class Mammal {
public:
  Mammal():age(1) {}
  ~Mammal() {}
  virtual void speak() const { std::cout << "Mammal speak!\n"; }
protected:
  int age;
};

class Dog : public Mammal {
public:
  void speak() const { std::cout << "Woof!\n"; }
};

class Cat : public Mammal {
public:
  void speak() const { std::cout << "Meow!\n"; }
};

class Horse : public Mammal {
public:
  void speak() const { std::cout << "Nehhh!\n"; }
};

class Pig : public Mammal {
public:
  void speak() const { std::cout << "Oink!\n"; }
};

int main() {
  Mammal *array[5];
  Mammal *ptr;
  int choice, i;
  for (i = 0; i < 5; i++) {
    std::cout << "(1) dog  (2) cat  (3) horse  (4) pig: ";
    std::cin >> choice;
    switch (choice) {
      case 1:
        ptr = new Dog;
        break;
      case 2:
        ptr = new Cat;
        break;
      case 3:
        ptr = new Horse;
        break;
      case 4:
        ptr = new Pig;
        break;
      default:
        ptr = new Mammal;
        break;
    }
    array[i] = ptr;
  }
  for (i = 0; i < 5; i++) {
    array[i] -> speak();
  }
  return 0;
}

// whats going on here?
// on line 9 Mammal's speak() function is declared to be virtual
// the four derived classes of Mammal override the implementation of speak()
// on lines 16, 21, 26, and 31

// the user chooses which object to create

// questions
// try adding an array with each animal name and output it before line 61 like
// std::cout << "The " << animalArray[i] << " says" array[i] -> speak() "\n";
