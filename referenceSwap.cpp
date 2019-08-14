// referenceSwap.cpp
// passing references as parameters to swap original values in swap()
#include <iostream>

// swap delcared to accept two int references
void swap(int &x, int &y);

int main() {
  int x = 5, y = 10;

  std::cout << "Main. Before swap, x: " << x
            << " y: " << y << std::endl;
  // call swap on the address of x and y
  swap(x, y);
  std::cout << "Main. After swap, x: " << x
            << " y: " << y << std::endl;
  return 0;
}

// pass in pointer x and pointer y
void swap(int &rx, int &ry) {

  // temp doesn't need to be a pointer b/c it temporarily holds the value for the life of the function
  int temp;

  std::cout << "Swap. Before swap, rx: " << rx
            << " ry: " << ry << std::endl;

  temp = rx;
  rx = ry;
  ry = temp;

  std::cout << "Swap. After swap, rx: " << rx
            << " ry: " << ry << std::endl;
}

// advantages
// references are like normal variables, easy to use with the power capability of pointers
