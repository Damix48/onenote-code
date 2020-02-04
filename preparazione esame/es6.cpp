#include <iostream>
#include <vector>

#ifndef CLIENTE_H
#define CLIENTE_H

class Cliente {
 private:
  unsigned int tempo;
  unsigned int n_telefonate;
  unsigned int n_sms;
  unsigned int traffico_mb;

 public:
  static double costo_mb;

  unsigned int getTempo() const { return tempo; }
  unsigned int getN_telefonate() const { return n_telefonate; }
  unsigned int getN_sms() const { return n_sms; }
  unsigned int getTraffico_mb() const { return traffico_mb; }
  virtual double costoMeseCorrente() const = 0;
  virtual Cliente* clone() const = 0;
};
double Cliente::costo_mb = 0.01;

#endif

#ifndef ALMINUTO_H
#define ALMINUTO_H

class AlMinuto : public Cliente {
  static double costo_scatto;
  static double costo_minuto;
  static double costo_sms;

 public:
  double costoMeseCorrente() const {
    return (getN_telefonate() * costo_scatto + getTempo() * costo_minuto + getN_sms() * costo_sms +
            getTraffico_mb() * costo_mb);
  }
  AlMinuto* clone() const { return new AlMinuto(*this); }
};
double AlMinuto::costo_scatto = 0.15;
double AlMinuto::costo_minuto = 0.2;
double AlMinuto::costo_sms = 0.1;

#endif

#ifndef ABBONAMENTO_H
#define ABBONAMENTO_H

class Abbonamento : public Cliente {
  static double costo_minuto;
  double costo_abbonamento;
  unsigned int minuti_abbonamento;

 public:
  unsigned int getMinuti_abbonamento(){return minuti_abbonamento};
  double costoMeseCorrente() const {
    return (costo_abbonamento + getTraffico_mb() * costo_mb +
            (getTempo() > minuti_abbonamento ? (getTempo() - minuti_abbonamento) * costo_minuto : 0));
  }
  Abbonamento* clone() const { return new Abbonamento(*this); }
};
double Abbonamento::costo_minuto = 0.3;

#endif

#ifndef SEDEMOON_H
#define SEDEMOON_H

class sedeMoon {
  std::vector<Cliente*> clienti;
  void aggiungiCliente(const Cliente& c) { clienti.push_back(c.clone()); }
  double incassoMensileCorrente() {
    double temp = 0;
    for (auto it = clienti.begin(); it < clienti.end(); ++it) {
      temp += (*it)->costoMeseCorrente();
    }
    return temp;
  }
  int numClientiAbbonatiOltreSoglia() {
    int temp = 0;
    Abbonamento* abb;
    for (auto it = clienti.begin(); it < clienti.end(); ++it) {
      abb = dynamic_cast<Abbonamento*>(*it);
      if (abb != nullptr && (abb->getTempo() > abb->getMinuti_abbonamento())) {
        temp++;
      }
    }
    return temp;
  }
  std::vector<AlMinuto> alMinutoSMS(int x) {
    std::vector<AlMinuto> temp;
    AlMinuto* ut;
    for (auto it = clienti.begin(); it < clienti.end(); ++it) {
      ut = dynamic_cast<AlMinuto*>(*it);
      if (ut != nullptr && ut->getN_sms() > x) {
        temp.push_back(*(ut->clone()));
      }
    }
    return temp;
  }
};

#endif

int main() {
  return 0;
}
