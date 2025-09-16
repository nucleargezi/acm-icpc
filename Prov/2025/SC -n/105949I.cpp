#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/string/hash.hpp"

// #define tests
using H = HASH<string>;
void Yorisou() {
  LL(n);
  set<PLL> se;
  FOR(n) {
    S(s);
    H hs(s);
    int n = len(s);
    FOR(i, n) se.emplace(hs.get(i, n));
  }
  UL(len(se));
}
#include "MeIoN_Lib/Z_H/main.hpp"