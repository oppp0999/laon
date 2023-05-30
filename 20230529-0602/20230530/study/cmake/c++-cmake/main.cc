#include <iostream>
#include "shape.h"

int main() {
  Rectangle rectangle(5, 6);
  int size = rectangle.GetSize();
  std::cout << "Get size: " << size << std::endl;
}