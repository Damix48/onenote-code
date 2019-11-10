#include <iostream>

template <class T>
class albero;

template <class T>
std::ostream operator<<(std::ostream& os, const albero<T>& a);

template <class T>
class albero {
 private:
  // classe annidata associata ad albero
  class nodo {
   public:
    nodo(const T& t = T(),
         nodo* s = nullptr,
         nodo* c = nullptr,
         nodo* d = nullptr)
        : info(t), sx(s), cx(c), dx(d) {}
    T info;
    nodo* sx;
    nodo* cx;
    nodo* dx;
  };
  nodo* root;  // albero vuoto iff root==nullptr
  static nodo* copy(nodo* n) {
    if (!n) {
      return nullptr;
    }
    return new nodo(n->info, copy(n->sx), copy(n->cx), copy(n->dx));
  }
  static void destroy(nodo* n) {
    if (n != nullptr) {
      destroy(n->sx);
      destroy(n->cx);
      destroy(n->dx);
      delete n;  // chiamata al distruttore standard di nodo
    }
  }
  static bool r_search(nodo* n, const T& t) {
    if (!n) {
      return false;
    }
    if (n->info == t) {
      return true;
    }
    return r_search(n->sx, t) || r_search(n->cx, t) || r_search(n->dx, t);
  }
  static bool r_equality(nodo* n1, nodo* n2) {
    if (!n1 && !n2) {
      return true;
    }
    // n1 != n2
    if (!n1 || !n2) {
      return false;
    }
    return (n1->info == n2->info) && r_equality(n1->sx, n2->sx) &&
           r_equality(n1->cx, n2->cx) && r_equality(n1->dx, n2->dx);
  }

 public:
  albero() : root(nullptr) {}
  albero(const albero& a) : root(copy(a.root)) {}
  albero& operator=(const albero& a) {
    if (this != &a) {
      destroy(root);
      root = copy(a.root);
    }
    return *this;
  }
  ~albero() { destroy(root); }
  void insert(const T& t) { root = new nodo(t, root, copy(root), copy(root)); }
  bool search(const T& t) const { return r_search(root, t); }
  bool operator==(const albero& a) const { return r_equality(root, a.root); }
};

template <class T>
std::ostream operator<<(std::ostream& os, const albero<T>& a) {
  return os << a.root->info;
}

int main() {
  albero<int> ciao;
  ciao.insert(21);
  ciao.insert(1);

  std::cout << "ciao" << std::endl;
  std::cout << ciao << std::endl;
}