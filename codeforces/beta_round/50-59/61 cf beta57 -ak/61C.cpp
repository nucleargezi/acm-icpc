// #include "YRS/Z_H/MeioN.hpp"
#include "YRS/all.hpp"
#include "YRS/ds/dsu.hpp"

// #define tests
void Yorisou() {
  LL(x);
  S(y, n);
  i128 val = 0;
  map<int, int> to;
  FOR(i, 10) to['0' + i] = i;
  FOR(i, 'A', 'Z' + 1) to[i] = i - 'A' + 10;
  map<int, int> go;
  FOR(i, 10) go[i] = i + '0';
  FOR(i, 10, 26) go[i] = i - 10 + 'A';
  for (char c : n) {
    val *= x;
    val += to[c];
  }
  meion f = [&]() {
    if (not val) iroha UL(0);
    int w = std::stoll(y);
    string s;
    while (val) {
      s += go[val % w];
      val /= w;
    }
    UL(reversed(s));
  };
  meion g = [&]() {
    if (not val) iroha UL(0);
    string s;
    while (val >= 1000) val -= 1000, s += 'M';
    if (val >= 100) {
      int x = val / 100;
      val %= 100;
      vector<string> str {
          "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
      s += str[x - 1];
    }
    if (val >= 10) {
      int x = val / 10;
      val %= 10;
      vector<string> str {
          "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
      s += str[x - 1];
    }
    if (val > 0) {
      int x = val;
      vector<string> str {
          "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
      s += str[x - 1];
    }
    UL(s);
  };
  (y == "R") ? g() : f();
}
#include "YRS/Z_H/main.hpp"