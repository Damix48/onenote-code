#include <iostream>

class orario {
 public:
  orario(int = 0, int = 0, int = 0);
  int Ore() const;
  int Minuti() const;
  int Secondi() const;
  orario operator+(const orario&) const;
  orario operator-(const orario&) const;
  bool operator==(const orario&) const;
  bool operator<(const orario&) const;
  bool operator>(const orario&) const;

 private:
  int sec;
};

orario::orario(int o, int m, int s) {
  if (o < 0 || o > 23 || m < 0 || m > 59 || s < 0 || s > 59) {
    sec = 0;
  } else {
    sec = o * 3600 + m * 60 + s;
  }
}

int orario::Ore() const {
  return sec / 3600;
}

int orario::Minuti() const {
  return (sec / 60) % 60;
}

int orario::Secondi() const {
  return sec % 60;
}

orario orario::operator+(const orario& o) const {
  orario temp;
  temp.sec = (sec + o.sec) % 86400;
  return temp;
}

orario orario::operator-(const orario& o) const {
  orario temp;
  temp.sec = (sec - o.sec) % 86400;
  return temp;
}

bool orario::operator==(const orario& o) const {
  return sec == o.sec;
}

bool orario::operator<(const orario& o) const {
  return sec < o.sec;
}

bool orario::operator>(const orario& o) const {
  return sec > o.sec;
}

int main() {
  orario adesso(14, 47);
  orario ora2(2);
  adesso = adesso + 2;
  std::cout << adesso.Ore();
  system("pause");
  return 0;
}