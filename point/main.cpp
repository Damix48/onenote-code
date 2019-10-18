#include <iostream>
#include "Point.h"

int main() {
  Point A(1, 2, 3);
  std::cout << A << " " << A.norm() << std::endl;
  A.negate();
  std::cout << A << " " << A.norm() << std::endl;
  Point B(1, 2, 3);
  A.negate();
  B = B + A;
  std::cout << B << " " << B.norm() << std::endl;
  system("pause");
  return 0;
}