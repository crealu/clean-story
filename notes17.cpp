/* HOUR 17 */
// polymorphism allows derived objects to be treated as base objects

// to do so, declare a pointer to Mammal and assign to it the address of a Dog
// object you create on the heap
// EXAMPLE
Mammal *pMammal = new Dog;

// use this pointer to invoke any member function on Mammal

// virtual member functions allow you to call the correct function that is
// overriden in Dog

// an example of a virtual member funciont declaration is below
// EXAMPLE
virtual void speak() const { std::cout << "Mammal speak!\n"; }

// quick note!!!!!!!!!!
Mammal* pMammal = new Dog;
// is the same as
Mammal *pMammal = new Dog;

// you can have an array of pointers to Mammal, each pointing do a different
// subclass of Mammal, that llow you to call the correct function
// this is shown in mammal9.cpp

// when a derived class object is created, first the constructor of the base class
// is called, then the constructor of the derived class

// when a virtual function is created in the object, the object must keep track
// of that function

// compilers build a virtual function table, a v-table

// each object for that type of v-table keeps a virtual table pointer (vptr)
// the vptr points to the virtual function table

// virtual function magic only operates on pointers and references
// in other words, passing an object by value will not invoke a virtual member function
// this is shown in mammal10.cpp

// it is common in C++ to pass a pointer to a derived object when a pointer to
// a base object in expected

// good rule of thumb
// if any functions in your class are virtual, the destructor should also be virtual

// sometimes a program needs to pass in a pointer to a base object and have a
// copy of the correct derived object that is created
// this is accomplished by cloning a member function in the base calss and
// making it virtual, this is shown in mammal11.cpp

// in mammal11.cpp, the clone() funciton must be explicitly called

// the copy function in a derived class can always be overriden
// but this reduces flexibility, hence why the approach in mammal11.cpp is
// favored over the approach in mammal10.cpp

// review this chapter!!!!!!!!!!!!!!
