#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/geo/1-base.hpp"

// #define tests
using P = point<ll>;
using RE = f128;
void Yorisou() {
  LL(n);
  VEC(P, ps, n);
  INT(q);
  FOR(q) {
    LL(x, y);
    vector<RE> a(n);
    FOR(i, n) {
      meion[X, Y] = ps[i] - P(x, y);
      a[i] = std::atan2(Y, X);
    }
    sort(a);
    FOR(i, n) a.emplace_back(a[i] + pi + pi);
    ll ans {n * (n - 1) * (n - 2) / 6};
    FOR(i, n) {
      ll x {lower(a, a[i] + pi) - a.begin() - i};
      ans -= (x - 1) * (x - 2) / 2;
    }
    UL(ans);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"