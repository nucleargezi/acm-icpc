#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  S(s, t);
  ll ans = 0;
  FOR(i, n) ans += s[i] != t[i];
  map<PLL, ll> m;
  FOR(i, n) if (s[i] != t[i]) {
    if (m.contains({t[i], s[i]})) {
      iroha UL(ans - 2), UL(m[{t[i], s[i]}] + 1, i + 1);
    }
    m[{s[i], t[i]}] = i;
  }
  map<ll, ll> mm;
  FOR(i, n) if (s[i] != t[i]) {
    if (mm.contains(s[i])) {
      iroha UL(ans - 1), UL(mm[s[i]] + 1, i + 1);
    }
    mm[t[i]] = i;
  }
  mm = {};
  FOR_R(i, n) if (s[i] != t[i]) {
    if (mm.contains(s[i])) {
      iroha UL(ans - 1), UL(mm[s[i]] + 1, i + 1);
    }
    mm[t[i]] = i;
  }
  UL(ans);
  UL(-1, -1);
}
#include "MeIoN_Lib/Z_H/main.hpp"