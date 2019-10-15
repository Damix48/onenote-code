#include <math.h>
#include <iostream>

class point {
 private:
  int x, y, z;

 public:
  point();
  point(int, int, int);
  int X() const;
  int Y() const;
  int Z() const;
  void negate();
  double norm();
  point operator+(const point&) const;
};

point::point() {
  x = 0;
  y = 0;
  z = 0;
}

point::point(int _x, int _y, int _z) {
  x = _x;
  y = _y;
  z = _z;
}

int point::X() const {
  return x;
}

int point::Y() const {
  return y;
}

int point::Z() const {
  return z;
}

void point::negate() {
  x = -x;
  y = -y;
  z = -z;
}

double point::norm() {
  return sqrt(x * x + y * y + z * z);
}

point point::operator+(const point& p) const {
  return point(x + p.x, y + p.y, z + p.z);
}

std::ostream& operator<<(std::ostream& os, const point& p) {
  return os << "(" << p.X() << ", " << p.Y() << ", " << p.Z() << ")";
}

int main() {
  point A(1, 2, 3);
  std::cout << A << " " << A.norm() << std::endl;
  A.negate();
  std::cout << A << " " << A.norm() << std::endl;
  point B(1, 2, 3);
  A.negate();
  B = B + A;
  std::cout << B << " " << B.norm() << std::endl;
}