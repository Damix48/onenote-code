class Nodo {
  friend class Tree;

 private:
  Nodo(char c = '*', Nodo* s = nullptr, Nodo* d = nullptr)
      : info(c), sx(s), dx(d){};
  char info;
  Nodo* sx;
  Nodo* dx;
};

class Tree {
 public:
  Tree(const Tree& t) : root(copia(t.root)){};
  Tree& operator=(const Tree& t) {
    if (this != &t) {
      distruggi(root);
      root = copia(t.root);
    }
    return *this;
  };
  ~Tree() { distruggi(root); };

 private:
  Nodo* root;
  static Nodo* copia(Nodo* n) {
    if (!n) {
      return nullptr;
    } else {
      return new Nodo(n->info, copia(n->sx), copia(n->sx));
    }
  }
  static void distruggi(Nodo* n) {
    if (n) {
      distruggi(n->sx);
      distruggi(n->dx);
      delete n;
    }
  }
};