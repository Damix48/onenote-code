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