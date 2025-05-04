#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  set<int> se;
  FOR(i, 26) se += i;
  S(s);
  for (char c : s) {
    c -= 'a';
    if (se.contains(c)) se -= c;
  }
  UL(char(*se.begin() + 'a'));
}
#include "MeIoN_Lib/Z_H/main.hpp"