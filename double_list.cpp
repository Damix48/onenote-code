#include <iostream>

template <class T>
class dList;

template <class T>
class dList {
 private:
  /* data */
 public:
  dList(int, const T&);
  ~dList();
};

template <class T>
dList<T>::dList(int k, const T& t) {}

template <class T>
dList<T>::~dList() {}

int main() {}