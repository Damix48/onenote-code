#include "Orario.h"
#include <iostream>

Orario::Orario(int o, int m, int s) {
  if (o < 0 || o > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
    sec = 0;
  } else {
    sec = o * 3600 + m * 60 + s;
  }
}

int Orario::Ore() const {
  return sec / 3600;
}

int Orario::Minuti() const {
  return (sec / 60) % 60;
}

int Orario::Secondi() const {
  return sec % 60;
}

Orario Orario::operator+(const Orario& o) const {
  Orario temp;
  temp.sec = (sec + o.sec) % 86400;
  return temp;
}

Orario Orario::operator-(const Orario& o) const {
  Orario temp;
  temp.sec = (sec - o.sec) % 86400;
  return temp;
}

bool Orario::operator==(const Orario& o) const {
  return sec == o.sec;
}

bool Orario::operator<(const Orario& o) const {
  return sec < o.sec;
}

bool Orario::operator>(const Orario& o) const {
  return sec > o.sec;
}

std::ostream& operator<<(std::ostream& os, const Orario& o) {
  return os << o.Ore() << ":" << o.Minuti() << ":" << o.Secondi();
}