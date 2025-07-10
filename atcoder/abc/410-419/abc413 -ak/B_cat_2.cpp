#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
void Yorisou() {
  LL(n);
  set<string> se;
  VEC(string, s, n);
  FOR(i, n) FOR(k, n) if (i != k) se.emplace(s[i] + s[k]);
  UL(len(se));
}
#include "MeIoN_Lib/Z_H/main.hpp"