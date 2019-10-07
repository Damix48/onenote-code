#include <iostream>
using namespace std;
// Complex.h
struct Complex {
  // ...
} double module(Complex);

// altro file
#include "Complex.h"
struct Complex {
  // ...
}

// file Definizioni.h
namespace ProgOgg {
  struct Complex {
    // ...
  }
  // ...
}

#include "lib1.h"
#include "lib2.h"
void funzione() {
  SPAZIO_UNO::Complex complesso1;
  SPAZIO_UNO::funct(complesso1);
  SPAZIO_DUE::Complex complesso2;
  SPAZIO_DUE::funct(complesso2);
}

using namespace std;
cout << "hello";

std::cout << "hello";

using namespace SPAZIO_UNO::Complex;
using namespace SPAZIO_DUE::g;

char* st = "Ciao a tutti\0";

#include <string>
using namespace std;
int main() {
  char* st = "Ciao a tutti";
  string st2("Ciao a tutti");
  string st3 = "Ciao a tutti";
  cout << st2.size;
}

// Complessi.h
struct comp {
  double re, im;
};
comp inizializzaComp(double, double);
double reale(comp);
double immag(comp);
comp somma(comp, comp);

class orario {
 private:
  int sec;

 public:
  int Ore();
  int Minuti();
  int Secondi();
};

int orario::Ore() {
  return sec / 3600;
}
int orario::Minuti() {
  return (sec / 60) % 60;
}
int orario::Secondi() {
  return sec % 60;
}

int orario::Secondi() {
  return sec % 60;
}
int orario::Secondi(orario* this) {
  return this.sec % 60;
}

int orario::Secondi() {
  return (*this).sec % 60;
}

class A {
 private:
  int a;

 public:
  A f();
};
A A::f() {
  a = 5;
  return *this;
}

orario o;
cout << o.Ore() << endl;
cout << o.sec << endl;

// Complessi.cpp
class Complesso {
 private:
  double re, im;

 public:
  void inizializza(double, double);
  double reale();
  double immag();
};
void Complesso::inizializza(double r, double i) {
  re = r;
  im = i;
}
double Complesso::reale() {
  return re;
}
double Complesso::immag() {
  return im;
}

orario mezzanotte;
mezzanotte.sec = 0;

class orario() {
 public:
  orario();
};

orario::orario() {
  sec = 0;
}

class orario {
 public:
  orario();
  orario(int, int);
  orario(int, int, int);
};

orario adesso(14, 25);
orario adesso = orario(14, 25);

orario t;
t = orario(14, 35);

orario(12, 25, 47);

orario* o = new orario;
orario* o1 = new orario(14, 25);
cout << o->Ore();

class orario {
 public:
  // nessun costruttore
};
orario o;

orario adesso(11, 55);
orario copia;
copia = adesso;
orario copia1 = adesso;
orario copia2(adesso);

C(const C&);

C& operator=(const C&);

orario s;
s = 8;

void F(double x, int n = 3, string s);

orario::orario(int o = 0, int m = 0, int s = 0) {
  if (o < 0 || o > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
    sec = 0;
  } else {
    sec = o * 3600 + m * 60 + s;
  }
}

class orario {
 public:
  orario(int = 0, int = 0, int = 0);

 private:
  int sec;
};
orario::orario(int o, int m, int s) {
  // ...
}

class orario {
 public:
  operator int() { return sec; }

 private:
  int sec;
};
orario o(14, 25);
int x = o;

class orario {
 public:
  explicit orario(int);

 private:
  int sec;
};
orario o = 8;

class orario {
 public:
  // ...
  orario UnOraPiuTardi();
  void AvanzaUnOra();

 private:
  int sec;
};

orario orario::UnOraPiuTardi() {
  orario aux;
  aux = (sec + 3600) % 86400;
  return aux;
}
void orario::AvanzaUnOra() {
  sec = (sec + 3600) % 86400;
}

class orario {
 public:
  void StampaSecondi() const;
};
void orario::StampaSecondi() const {
  std::cout << sec << std::endl;
}