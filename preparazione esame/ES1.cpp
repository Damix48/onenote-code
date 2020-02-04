#include <iostream>

template <class T>
class SmartP;

template <class T>
class SmartP {
 private:
  T* ptr;

 public:
  SmartP() : ptr(nullptr){};                         // COSTRUTTORE STANDARD
  SmartP(const T* t) : ptr(new T(*t)){};             // COSTRUTTORE AD UN PARAMETRO
  SmartP(const SmartP& p) : ptr(new T(*(p.ptr))){};  // COSTRUTTORE DI COPIA PROFONDA
  SmartP& operator=(const SmartP& p) {               // ASSEGNAZIONE PROFONDA
    delete ptr;
    ptr = new T(*(p.ptr));
    return *this;
  }
  ~SmartP() { delete ptr; }

  T& operator*() { return *ptr; }

  bool operator==(const SmartP& p) const { return *ptr == *p.ptr; }
  bool operator!=(const SmartP& p) const { return !(*ptr == *p.ptr); }

  T* operator->() { return ptr; }
};

class C {
 public:
  int* p;
  C() : p(new int(5)) {}
};

int main() {
  const int a = 1;
  const int* p = &a;
  SmartP<int> r;
  SmartP<int> s(&a);
  SmartP<int> t(s);
  std::cout << *s << " " << *t << " " << *p << std::endl;  // 1 1 1
  *s = 2;
  *t = 3;
  std::cout << *s << " " << *t << " " << *p << std::endl;  // 2 3 1
  r = t;
  *r = 4;
  std::cout << *r << " " << *s << " " << *t << " " << *p << std::endl;  // 4 2 3 1
  std::cout << (s == t) << " " << (s != p) << std::endl;                // 0 1
  C c;
  SmartP<C> x(&c);
  std::cout << *(c.p) << " " << *(x->p) << std::endl;  // 5 5
  *(c.p) = 6;
  std::cout << *(c.p) << " " << *(x->p) << std::endl;  // 6 6
  SmartP<C>* q = new SmartP<C>(&c);
  delete q;
  std::cout << *(x->p) << std::endl;  // 6
}
