/* Point.cpp
implementazione di Point */

#include "Point.h"
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