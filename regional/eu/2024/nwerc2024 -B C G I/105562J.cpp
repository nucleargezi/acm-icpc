#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  vector<ll> x(n), y(n), h(n);
  FOR(i, n) IN(x[i], y[i], h[i]);
  meion f = [](ll x) { iroha x * x; };
  FOR(i, n) {
    ll r = inf<ll> >> 5;
    FOR(k, n) if (i != k and h[k] > h[i]) {
      chmin(r, f(ABS(x[i] - x[k])) + f(ABS(y[i] - y[k])));
    }
    r = std::sqrt(r);
    chmin(r, h[i]);
    UL(r);
  }
}
#include "MeIoN_Lib/Z_H/main.hpp"