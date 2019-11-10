#include "Telefonata.h"
#include <iostream>
#include "Orario.h"

Telefonata::Telefonata() {
  numero = 0;
}

Telefonata::Telefonata(Orario i, Orario f, int n)
    : inizio(i), fine(f), numero(n) {}

Orario Telefonata::Inizio() const {
  return inizio;
}

Orario Telefonata::Fine() const {
  return fine;
}

int Telefonata::Numero() const {
  return numero;
}

bool Telefonata::operator==(const Telefonata& t) const {
  return (inizio == t.inizio && fine == t.fine && numero == t.numero);
}

std::ostream& operator<<(std::ostream& os, const Telefonata& t) {
  return os << "INIZIO: " << t.Inizio() << " FINE: " << t.Fine()
            << " NUMERO CHIAMATO: " << t.Numero();
}