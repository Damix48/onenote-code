template <class T>
class dList {
 private:
  class nodo {
   public:
    T info;
    nodo* prev;
    nodo* next;
    nodo(const T& t = T(), nodo* p = nullptr, nodo* n = nullptr)
        : info(t), prev(p), next(n) {}
    ~nodo() { delete next; }  // ometto if(next!=nullptr)
  };

  nodo* last;
  nodo* first;

  static nodo* copy(nodo* n, nodo*& l) {
    nodo* pre = new nodo(n->info);
    nodo* nex = pre;
    nodo* aux = pre;

    while (n->next != nullptr) {
      nex = new nodo(n->next->info, pre);
      pre->next = nex;
      pre = nex;
      n = n->next;
    }
    l = nex;
    return aux;
  }

  static bool isLess(nodo* n1, nodo* n2) {
    if (n2 == nullptr)
      return false;

    // n2!=nullptr

    if (n1 == nullptr)
      return true;

    // n1&&n2!=nullptr

    return n1->info < n2->info ||
           (n1->info == n2->info && isLess(n1->next, n2->next));
  }

 public:
  dList(unsigned int k = 0, const T& t = T()) : last(nullptr), first(nullptr) {
    for (unsigned int i = 0; i < k; ++i) {
      insertBack(t);
    }
  }
  ~dList() { delete first; }
  dList(const dList& dL) : first(copy(dL.first, last)) {}
  dList& operator=(const dList& dL) {
    if (this != &dL) {
      delete first;
      first = copy(dL.first, last);
    }
    return *this;
  }
  bool operator<(const dList& dL) const { return isLesss(first, dL.first); }
  void insertFront(const T& t) {
    if (first == nullptr) {
      first = new nodo(t);
      last = first;
    } else {
      first->pre = new nodo(t, nullptr, first);
      first = first->pre;
    }
  }
  void insertBack(const T& t) {
    if (first == nullptr) {
      first = new nodo(t);
      last = first;
    } else {
      last->next = new nodo(t, last);
      last = last->next;
    }
  }

  class constiterator {  // manca la gestione della memoria di constiterator
    friend class dList<T>;

   private:
    nodo* ptr;
    bool pastTheEnd;  // true iff constiterator è 'past-the-end'
    constiterator(nodo* p, bool pte = false)
        : ptr(p),
          pastTheEnd(pte) {
    }  // funziona cnhe come convertitore da nodo* a constiterator

   public:
    constiterator() : ptr(nullptr), pastTheEnd(false) {}
    const T& operator*() const { return ptr->info; }
    const T* operator->() const { return &(ptr->info); }
    constiterator& operator++() {
      if (ptr != nullptr) {
        if (!pastTheEnd) {
          if (ptr->next == nullptr) {
            ++ptr;
            pastTheEnd = true;
            ;
          } else {
            ptr = ptr->next;
          }
        }
      }
      return *this;
    }
    constiterator& operator--() {
      if (ptr != nullptr) {
        if (pastTheEnd) {
          --ptr;
          pastTheEnd = false;
        } else {
          ptr = ptr->prev;
        }
      }
      return *this;
    }
    bool operator==(const constiterator& x) { return ptr == x.ptr; }
    bool operator!=(const constiterator& x) { return ptr != x.ptr; }
  };
  constiterator& begin() const { return first; }
  constiterator& end() const {
    if (last == nullptr) {
      return nullptr;
    }
    return constiterator(last + 1, true);
  };
};

int main() {
  dList<int> ciao(12, 6);
  dList<int> ciao2(1, 2);
  ciao2 = ciao;
}