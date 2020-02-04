#include <iostream>

class Abs {
 public:
  virtual ~Abs() = 0;
};
Abs::~Abs() {}
class B : public Abs {};
class C {};
class D : public C {};

template <class T1, class T2>
bool Fun(T1* t1, T2& t2) {
  if (typeid(T1) == typeid(T2) && typeid(*t1) == typeid(t2) && dynamic_cast<Abs*>(t1) != nullptr) {
    return true;
  } else {
    return false;
  }
}

int main() {
  B* b = new B();
  C* c = new C();
  D* d = new D();
  std::cout << Fun(b, b) << std::endl;
  std::cout << Fun(c, d) << std::endl;
  // std::cout << Fun(d, c) << std::endl;

  // c = new D();
  // std::cout << Fun(b, d) << std::endl;
  // std::cout << Fun(d, c) << std::endl;
}