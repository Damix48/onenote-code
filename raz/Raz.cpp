#include "Raz.h"
#include <iostream>

Raz::Raz(int n, int d) : num(n), den(d != 0 ? d : 1) {}

Raz Raz::inverso() const {
  return num != 0 ? Raz(den, num) : Raz();
}

Raz::operator double() const {
  return static_cast<double>(num) / static_cast<double>(den);
}

Raz Raz::operator+(const Raz& r) const {
  return Raz(num * r.den + r.num * den, den * r.den);
}

Raz Raz::operator*(const Raz& r) const {
  return Raz(num * r.num, den * r.den);
}

Raz Raz::operator++(int) {
  Raz aux(*this);
  *this = this->operator+(1);
  return aux;
}

Raz& Raz::operator++() {
  *this = this->operator+(1);
  return *this;
}

bool Raz::operator==(const Raz& r) const {
  return num * r.den == r.num * den;
}

Raz Raz::unTerzo() {
  return (1, 3);
}

std::ostream& operator<<(std::ostream os, const Raz& r) {
  return os << "il razionale in virgola mobile è: " << r.operator double();
}
