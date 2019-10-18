#include <iostream>
#include <string>
#include <vector>
using namespace std;

void print(string, vector<int>);
void fib(int x, int y, int n, vector<int>& v);

int main() {
  cout << "Quanti elementi della serie di Fibonacci vuoi?";
  int n;
  cin >> n;
  vector<int> vfib;
  cout << "scegli due numeri di partenza: ";
  int x, y;
  cout << "\nx:";
  cin >> x;
  cout << "y:";
  cin >> y;
  fib(x, y, n, vfib);
  string label = "Fibonacci: \n";
  print(label, vfib);
  return 0;
}

void fib(int x, int y, int n, vector<int>& v) {
  v.push_back(x);
  v.push_back(y);
  for (int i = 2; i < n; i++) {
    v.push_back(v[i - 2] + v[i - 1]);
  }
}

void print(string labeling, vector<int> vettore) {
  cout << labeling;
  for (int i = 0; i < vettore.size(); i++) {
    cout << vettore[i] << endl;
  }
}