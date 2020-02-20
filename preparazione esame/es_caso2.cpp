#include <iostream>

class C {
 public:
  int a[2];
  C(int x = 0, int y = 1) {
    a[0] = x;
    a[1] = y;
    std::cout << "C(" << a[0] << ", " << a[1] << ") ";
  }
  C(const C&) { std::cout << "Cc "; }
};

class D {
 private:
  C c1;
  C* c2;
  C& cr;

 public:
  D() : c2(&c1), cr(c1) { std::cout << "D() "; }
  D(const D& d) : cr(c1) { std::cout << "Dc "; }
  ~D() { std::cout << "~D "; }
};

class E {
 public:
  static C cs;
};

C E::cs = 1;

int main() {
  std::cout << std::endl;
  C c;
  std::cout << "UNO" << std::endl;
  // C(0, 1) UNO
  C x(c);
  std::cout << x.a[0] << " " << x.a[1] << " DUE" << std::endl;
  // Cc 0 0 DUE
  D d = D();
  std::cout << "TRE" << std::endl;
  // C(0, 1) C(0, 1) D() ~D TRE
  E e;
  std::cout << "QUATTRO" << std::endl;
  // QUATTRO
}