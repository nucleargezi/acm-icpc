#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, m, k);
  VEC(ll, a, k);
  ll ans = 0;
  FOR(n) {
    FOR(m) {
      LL(x);
      ll p = 0;
      FOR(i, len(a)) if (a[i] == x) p = i;
      ans += p + 1;
      a.erase(a.begin() + p);
      a.insert(a.begin(), x);
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"