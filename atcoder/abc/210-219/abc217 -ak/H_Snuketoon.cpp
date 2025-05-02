#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/alg/slope/slope_trick.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  slope_trick<ll> g;
  FOR(n << 1) g.add_abs(0);
  ll pr = 0;
  FOR(n) {
    LL(t, d, x);
    ll df = t - pr;
    if (df > 0) g.shift(-df, df);
    if (d == 0) {
      g.add_a_minus_x(x);
    } else {
      g.add_x_minus_a(x);
    }
    pr = t;
  }
  UL(g.get_min());
}
#include "MeIoN_Lib/Z_H/main.hpp"