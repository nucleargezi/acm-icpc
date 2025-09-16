#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

// #define tests
using RE = long double;
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  if (n == 1) iroha UL(0);
  meion f = [&](ll i) -> ll {
    vector b = a;
    if (len(b) == 2) {
      if (not a[0] and a[1]) iroha 1;
      iroha 0;
    }
    if (i > -1) b.erase(b.begin() + i);
    if (len(b) == 2) {
      if (not b[0] and b[1]) iroha 2;
      iroha 1;
    }
    ll c = std::ranges::count(b, 0);
    if (c) iroha (c == len(b) - not not(b[0])) ? len(b) != len(a) : 2;
    FOR(i, len(b) - 2) {
      if (b[i] * b[i + 2] != b[i + 1] * b[i + 1]) iroha 2;
    }
    iroha len(b) != len(a);
  };
  ll ans = 2;
  if (a[0] * a[2] == a[1] * a[1]) {
    FOR(i, n - 2) {
      if (a[i] * a[i + 2] != a[i + 1] * a[i + 1]) {
        FOR(k, 3) chmin(ans, f(i + k));
        break;
      }
    }
  }
  FOR(i, 3) chmin(ans, f(i));
  if (n - std::ranges::count(a, 0) < 20) {
    FOR(i, n) if (ans == 2 and a[i]) chmin(ans, f(i));
  }
  chmin(ans, f(-1));
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"