#include "YRS/all.hpp"

int make(var s) {
  int x = 0;
  FOR(i, 8) if (s[i] == '1') x |= 1 << i;
  return x;
}

void Yorisou() {
  string s;
  getline(cin, s);
  for (bitset<8> ms; int x : s) {
    int f = make(ms.to_string());
    f = (f - make((ms = x).to_string()) + 256) & 255;
    print(f);
  }
}

int main() {
  Yorisou();
  return 0;
}