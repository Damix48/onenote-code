#include <iostream>
#include <vector>

#ifndef WORKOUT_H
#define WORKOUT_H
class Workout {
 private:
  unsigned int durata;

 public:
  unsigned int getDurata() const { return durata; }
  virtual Workout* clone() const = 0;
  virtual int calorie() const = 0;
  virtual ~Workout() {}
};
#endif

#ifndef CORSA_H
#define CORSA_H
class Corsa : public Workout {
 private:
  float distanza;

 public:
  Corsa* clone() const { return new Corsa(*this); }
  int calorie() const { return 500 * (distanza * distanza) / getDurata(); }
};
#endif

#ifndef NUOTO_H
#define NUOTO_H
class Nuoto : public Workout {
 private:
  unsigned int vasche;

 public:
  unsigned int getVasche() const { return vasche; }
  virtual Nuoto* clone() const = 0;
};
Nuoto::~Nuoto() {
  delete this;
}
#endif

#ifndef STILELIBERO_H
#define STILELIBERO_H
class StileLibero : public Nuoto {
 public:
  StileLibero* clone() const { return new StileLibero(*this); }
  int calorie() const {
    if (getDurata() < 10) {
      return 35 * getVasche();
    } else {
      return 40 * getVasche();
    }
  }
};
#endif

#ifndef DORSO_H
#define DORSO_H
class Dorso : public Nuoto {
 public:
  Dorso* clone() const { return new Dorso(*this); }
  int calorie() const {
    if (getDurata() < 15) {
      return 30 * getVasche();
    } else {
      return 35 * getVasche();
    }
  }
};
#endif

#ifndef RANA_H
#define RANA_H
class Rana : public Nuoto {
 public:
  Rana* clone() const { return new Rana(*this); }
  int calorie() const { return 25 * getVasche(); }
};
#endif

#ifndef INFORMA_H
#define INFORMA_H
class InForma {
 private:
  std::vector<const Workout*> allenamenti;

 public:
  std::vector<Nuoto*> vasche(int v) {
    std::vector<Nuoto*> temp;
    const Nuoto* n;
    for (std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it < allenamenti.end(); ++it) {
      n = dynamic_cast<const Nuoto*>(*it);
      if (n != nullptr && n->getVasche() > v) {
        temp.push_back(n->clone());
      }
    }
    return temp;
  }
  std::vector<Workout*> calorie(int c) {
    std::vector<Workout*> temp;
    for (std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it < allenamenti.end(); ++it) {
      if (typeid(*it) != typeid(const Rana*) && (*it)->calorie() > c) {
        temp.push_back((*it)->clone());
      }
    }
    return temp;
  }
  void removeNuoto() {
    int cal = 0;
    const Nuoto* n;
    for (std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it < allenamenti.end(); ++it) {
      n = dynamic_cast<const Nuoto*>(*it);
      if (n != nullptr && n->calorie() > cal) {
        cal = n->calorie();
      }
    }
    for (std::vector<const Workout*>::const_iterator it = allenamenti.begin(); it < allenamenti.end(); ++it) {
      n = dynamic_cast<const Nuoto*>(*it);
      if (n != nullptr && n->calorie() == cal) {
        delete *it;
        allenamenti.erase(it);
      }
    }
  }
};
#endif
