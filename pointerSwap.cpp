// pointerSwap.cpp
// passing pointers as parameters to swap() to manipulate the original value
#include <iostream>

// swap delcared to accept two int pointers
void swap(int *x, int *y);

int main() {
  int x = 5, y = 10;

  std::cout << "Main. Before swap, x: " << x
            << " y: " << y << std::endl;
  // call swap on the address of x and y
  swap(&x, &y);
  std::cout << "Main. After swap, x: " << x
            << " y: " << y << std::endl;
  return 0;
}

// pass in pointer x and pointer y
void swap(int *px, int *py) {

  int temp;

  std::cout << "Swap. Before swap, *px: " << *px
            << " *py: " << *py << std::endl;

  temp = *px;
  *px = *py;
  *py = temp;

  std::cout << "Swap. After swap, *px: " << *px
            << " *py: " << *py << std::endl;
}

// some limitations
// the calling function must know to pass in the address of the object it wants to swap
// hence the repeated need to dereference the pointers in the swap function
