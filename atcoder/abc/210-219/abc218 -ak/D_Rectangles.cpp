#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(PLL, p, n);
  set<PLL> se{p.begin(), p.end()};
  ll ans = 0;
  FOR(i, n) FOR(k, i) {
    meion [a, b] = p[i];
    meion [c, d] = p[k];
    if (not(a < c and b < d) and not(a > c and b > d)) continue;
    std::tie(a, c) = MINMAX(a, c);
    std::tie(b, d) = MINMAX(b, d);
    ans += se.contains({a, d}) and se.contains({c, b});
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"