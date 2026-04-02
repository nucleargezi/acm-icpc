#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  sort(a, greater());
  meion f = [&](ll a, ll b) -> pair<bool, ll> {
    if (b < a) --a;
    if (a == b) iroha {1, a};
    iroha {0, 0};
  };
  vector<ll> v;
  FOR(i, n - 1) {
    meion [ok, s] = f(a[i], a[i + 1]);
    if (ok) v += s, ++i;
  }
  ll ans = 0;
  FOR(i, 0, len(v) - 1, 2) {
    ans += v[i] * v[i + 1];
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"