#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  S(s);
  ll n = len(s);
  ll p = -1;
  FOR(i, n - 1) {
    if (s[i] - '0' & 1) continue;
    p = i;
    if (s[i] < s[n - 1]) break;
  }
  if (p == -1) iroha UL(-1);
  std::swap(s[p], s[n - 1]);
  UL(s);
}
#include "MeIoN_Lib/Z_H/main.hpp"