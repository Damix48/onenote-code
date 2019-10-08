class C {
 private:
  int x;

 public:
  C(int n = 0) { x = n; }
  C F(C obj) {
    C r;
    r.x = obj.x + x;
    return r;
  }
  C G(C obj) const {
    C r;
    r.x = obj.x + x;
    return r;
  }
  C H(C& obj) {
    obj.x += x;
    return obj;
  }
  C I(const C& obj) {
    C r;
    r.x = obj.x + x;
    return r;
  }
  C J(const C& obj) const {
    C r;
    r.x = obj.x + x;
    return r;
  }
};

int main() {
  C x, y(1), z(2);
  const C v(2);
  z = x.F(y);
  v.F(y);  // non posso chiamare un metodo non costante su un oggetto costante
  v.G(y);
  (v.G(y)).F(x);
  (v.G(y)).G(x);
  x.H(v);       // non posso passare un oggetto costante a un non costante
  x.H(z.G(y));  // z.G(y) ritorna un valore non un indirizzo
  x.I(z.G(y));
  x.J(z.G(y));
  v.J(z.G(y));
}