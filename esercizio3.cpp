#include <iostream>

class Vettore {
 public:
  // vettore vuoto sse data=nullptr && _size=0

  Vettore(unsigned int s = 0, int x = 0)
      : data(s == 0 ? nullptr : new int[s]), _size(s) {
    for (int i = 0; i < _size; i++) {
      data[i] = x;
    }
  };
  unsigned int size() const { return _size; }
  Vettore(const Vettore& v)
      : data(v.size() == 0 ? nullptr : new int[v.size()]), _size(v.size()) {
    for (int i = 0; i < _size; i++) {
      data[i] = v.data[i];
    }
  }
  Vettore& operator=(const Vettore& v) {
    if (this != &v) {
      delete[] data;
      if (v.size() == 0) {
        _size = 0;
        data = nullptr;
      } else {
        _size = v.size();
        data = new int[_size];
        for (int i = 0; i < _size; i++) {
          data[i] = v.data[i];
        }
      }
    }
    return *this;
  }
  ~Vettore() { delete[] data; }

  int& operator[](unsigned int i) const { return data[i]; }
  void append(const Vettore& v) { *this = *this + v; }
  bool operator==(const Vettore& v) const {
    if (this == &v) {
      return true;
    }
    if (size() != v.size()) {
      return false;
    }
    for (int i = 0; i < size(); i++) {
      if (data[i] != v.data[i]) {
        return false;
      }
    }
    return true;
  }

 private:
  int* data;
  unsigned int _size;
};

Vettore& operator+(const Vettore& v1, const Vettore& v2) {
  Vettore temp(v1.size() + v2.size());
  for (int i = 0; i < v1.size(); i++) {
    temp[i] = v1[i];
  }
  for (int i = 0; i < v2.size(); i++) {
    temp[i + v1.size()] = v2[i];
  }
  return temp;
}

std::ostream& operator<<(std::ostream os, const Vettore& v) {}