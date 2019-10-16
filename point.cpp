/* Point.h
interfaccia di Point */

#include <iostream>

class Point {
 private:
  double x, y, z;

 public:
  // Costruisco un punto di coordinate cartesiane (x, y, z)
  Point(double _x = 0, double _y = 0, double _z = 0);
  double getX() const;
  double getY() const;
  double getZ() const;
  void negate();
  double norm() const;
};
std::ostream& operator<<(std::ostream&, const Point&);
Point operator+(const Point&, const Point&);

/* Point.cpp
implementazione di Point */

// #include "Point.h"c
#include <math.h>

Point::Point(double _x, double _y, double _z) {
  x = _x;
  y = _y;
  z = _z;
}

double Point::getX() const {
  return x;
}

double Point::getY() const {
  return y;
}

double Point::getZ() const {
  return z;
}

void Point::negate() {
  x = -x;
  y = -y;
  z = -z;
}

double Point::norm() const {
  return sqrt(x * x + y * y + z * z);
}

Point operator+(const Point& p1, const Point& p2) {
  return Point(p1.getX() + p2.getX(), p1.getY() + p2.getY(),
               p1.getZ() + p2.getZ());
}

std::ostream& operator<<(std::ostream& os, const Point& p) {
  return os << "(" << p.getX() << ", " << p.getY() << ", " << p.getZ() << ")";
}

// main.cpp

// #include "Point.h"
#include <iostream>

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