#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  static bitset<2000> v[2000];
  FOR(i, n) FOR(k, n) {
    CH(c);
    v[i][k] = c == '1';
  }
  FOR(i, n) v[i][i] = 1;
  FOR(k, n) FOR(i, n) if (v[i][k]) {
    v[i] |= v[k];
  }
  ll ans = 0;
  FOR(i, n) ans += v[i].count();
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"