#ifndef ORARIO_H
#define ORARIO_H
#include <iostream>

class Orario {
 public:
  Orario(int = 0, int = 0, int = 0);
  int Ore() const;
  int Minuti() const;
  int Secondi() const;
  Orario operator+(const Orario&) const;
  Orario operator-(const Orario&) const;
  bool operator==(const Orario&) const;
  bool operator<(const Orario&) const;
  bool operator>(const Orario&) const;

 private:
  int sec;
};

std::ostream& operator<<(std::ostream&, const Orario&);

#endif