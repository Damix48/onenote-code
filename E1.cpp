#include <iostream>

class A {
 private:
  void h() { std::cout << " A::h "; }

 public:
  virtual void g() { std::cout << " A::g "; }
  virtual void f() {
    std::cout << " A::f ";
    g();
    h();
  }
  void m() {
    std::cout << " A::m ";
    g();
    h();
  }
  virtual void k() {
    std::cout << " A::k ";
    g();
    h();
    m();
  }
  A* n() {
    std::cout << " A::n ";
    return this;
  }
};

class B : public A {
 private:
  void h() { std::cout << " B::h "; }

 public:
  virtual void g() { std::cout << " B::g "; }
  void m() {
    std::cout << " B::m ";
    g();
    h();
  }
  void k() {
    std::cout << " B::k ";
    g();
    h();
    m();
  }
  B* n() {
    std::cout << " B::n ";
    return this;
  }
};

int main(int argc, char const* argv[]) {
  B* b = new B();
  A* a = new B();
  b->f();
  std::cout << std::endl;
  b->m();
  std::cout << std::endl;
  b->k();
  std::cout << std::endl;
  a->f();
  std::cout << std::endl;
  a->m();
  std::cout << std::endl;
  a->k();
  std::cout << std::endl;
  b->n()->g();
  std::cout << std::endl;
  b->n()->n()->g();
  std::cout << std::endl;
  a->n()->g();
  std::cout << std::endl;
  a->n()->m();

  return 0;
}
