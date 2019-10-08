class orario {
 public:
  orario();
  orario(int = 0, int = 0, int = 0);
  int Ore() const;
  int Minuti() const;
  int Secondi() const;

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