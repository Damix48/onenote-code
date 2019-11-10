#include <iostream>

class Raz {
 private:
  int num, den;  // INV: den != 0

 public:
  Raz(int = 0, int = 1);
  Raz inverso() const;
  operator double() const;
  Raz operator+(const Raz&) const;
  Raz operator*(const Raz&)const;
  Raz operator++(int);  //++ post-fisso
  Raz& operator++();    //++ pre-fisso
  bool operator==(const Raz&) const;
  static Raz unTerzo();
};

std::ostream& operator<<(std::ostream, const Raz&);

/* n1/d1 + n2/d2 = (n1*d2 + n2*d1) / (d1*d2)
n1/d1 + n2/d2 = (n1*n2) / (d1*d2)
n1/d1 == n1/d2 -> n1*d2==n2*d1
*/