#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, k);
  vector<ll> mx(m, inf<ll>);
  FOR(n) {
    LL(r, c);
    chmin(mx[--r], c);
  }
  FOR(i, n) if (mx[i] == inf<ll>) mx[i] = 0;
  UL(MIN(SUM(mx), k));
}
#include "MeIoN_Lib/Z_H/main.hpp"