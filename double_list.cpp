#include <iostream>

template <class T>
class dList;

template <class T>
class dList {
 private:
  class nodo {
   public:
    T info;
    nodo* pre;
    nodo* next;
    nodo(const T& t = T(), nodo* n = nullptr, nodo* p = nullptr)
        : info(t), next(n), pre(p) {}
  };

  nodo* begin;
  nodo* end;

  static nodo* copy(nodo* n) {
    if (!n) {
      return nullptr;
    }
    std::cout << "c " << n->info << std::endl;

    return new nodo(n->info, copy(n->next));
  }

  static nodo* reconnect(nodo* n) {
    if (n->next != nullptr) {
      n->next->pre = n;
      return reconnect(n->next);
    }
    return n;
  }

  static void destroy(nodo* n) {
    if (n != nullptr) {
      destroy(n->next);
      delete n;
    }
  }

 public:
  dList(int k = 0, const T& t = T()) : begin(nullptr), end(nullptr) {
    for (int i = 0; i < k; i++) {
      insertBack(t);
    }
  }
  dList(const dList& dL) : begin(copy(dL.begin)), end(reconnect(begin)) {}

  void insertFront(const T& t) {
    if (!begin) {
      begin = new nodo(t);
      end = begin;
    } else {
      begin->pre = new nodo(t, begin);
      begin = begin->pre;
    }
  }
  void insertBack(const T& t) {
    if (!begin) {
      begin = new nodo(t);
      end = begin;
    } else {
      end->next = new nodo(t, nullptr, end);
      end = end->next;
    }
  }

  dList& operator=(const dList& dL) {
    if (this != &dL) {
      destory(begin);
      begin = copy(dL.begin);
      end = reconnect(begin);
    }
    return *this;
  }
  void print() {
    std::cout << begin->info << std::endl;
    std::cout << begin->next->info << std::endl;
    std::cout << begin->next->next->info << std::endl;
    std::cout << begin->next->next->next->info << std::endl;
    std::cout << begin->next->next->next->next->info << std::endl;
    std::cout << begin->next->next->next->next->next->info << std::endl;
    std::cout << "contrario" << std::endl;

    std::cout << begin->next->pre->info << std::endl;

    std::cout << end->info << std::endl;
    std::cout << end->pre->info << std::endl;
    std::cout << end->pre->pre->info << std::endl;
    std::cout << end->pre->pre->pre->info << std::endl;
    std::cout << end->pre->pre->pre->pre->info << std::endl;
    std::cout << end->pre->pre->pre->pre->pre->info << std::endl;
    // std::cout << begin->next->next->next->next->next->next->info <<
    // std::endl;
  }
};

int main() {
  // dList<int> prova(6, 14);
  dList<int> prova;

  prova.insertFront(5);
  prova.insertBack(1);
  prova.insertBack(2);
  prova.insertFront(6);
  prova.insertBack(3);
  prova.insertBack(4);
  dList<int> prova2(prova);
  // prova2 = prova;
  prova.insertFront(5);

  prova.print();
  std::cout << std::endl;
  prova2.print();
}