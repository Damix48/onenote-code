#include <iostream>

class A {
 public:
  virtual ~A() = default;
};

class B : public A {
  virtual ~B() = 0;
};
B::~B() = default;

class C : public B {};

class D {
 protected:
  D() = default;
};

class E : public D {
  E& operator=(const E& e) {
    D::operator=(e);
    return *this;
  }
};
