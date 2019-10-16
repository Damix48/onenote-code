#include <math.h>
#include <iostream>

// Point.h
// interfaccia di Point
class Point {
 private:
  double x, y, z;

 public:
  Point();
  Point(double, double, double);
  double X() const;
  double Y() const;
  double Z() const;
  void negate();
  double norm();
  Point operator+(const Point&) const;
};

// Point.cpp
// implementazione di Point
Point::Point() {
  x = 0;
  y = 0;
  z = 0;
}

Point::Point(double _x, double _y, double _z) {
  x = _x;
  y = _y;
  z = _z;
}

double Point::X() const {
  return x;
}

double Point::Y() const {
  return y;
}

double Point::Z() const {
  return z;
}

void Point::negate() {
  x = -x;
  y = -y;
  z = -z;
}

double Point::norm() {
  return sqrt(x * x + y * y + z * z);
}

Point Point::operator+(const Point& p) const {
  return Point(x + p.x, y + p.y, z + p.z);
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
  return os << "(" << p.X() << ", " << p.Y() << ", " << p.Z() << ")";
}

int main() {
  Point A(1, 2, 3);
  std::cout << A << " " << A.norm() << std::endl;
  A.negate();
  std::cout << A << " " << A.norm() << std::endl;
  Point B(1, 2, 3);
  A.negate();
  B = B + A;
  std::cout << B << " " << B.norm() << std::endl;
}