class orario {
 public:
  orario();
  orario(int = 0, int = 0, int = 0);
  int Ore();
  int Minuti();
  int Secondi();

 private:
  int sec;
};

orario::orario() {
  sec = 0;
}

orario::orario(int o, int m, int s) {
  sec = o * 3600 + m * 60 + s;
}

int orario::Ore() {
  return sec / 3600;
}

int orario::Minuti() {
  return (sec / 60) % 60;
}

int orario::Secondi() {
  return sec % 60;
}