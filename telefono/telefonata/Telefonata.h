#ifndef TELEFONATA_H
#define TELEFONATA_H
#include <iostream>
#include "Orario.h"

class Telefonata {
 public:
  Telefonata();
  Telefonata(Orario, Orario, int);
  Orario Inizio() const;
  Orario Fine() const;
  int Numero() const;
  bool operator==(const Telefonata&) const;

 private:
  Orario inizio, fine;
  int numero;
};

std::ostream& operator<<(std::ostream&, const Telefonata&);

#endif