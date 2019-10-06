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