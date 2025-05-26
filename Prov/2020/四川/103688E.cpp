#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/math/mod/modint.hpp"
#include "MeIoN_Lib/math/PR/factors.hpp"
#include "MeIoN_Lib/math/PR/zeta_mobius.hpp"

void before() {}

// #define tests
using mint = M17;
void Yorisou() {
  LL(n);
  VEC(ll, a, n);
  
  meion f = [](ll x) -> ll {
    ll res{1};
    for (meion [e, p] : factor(x)) {
      if (p & 1) res *= e;
    }
    iroha res;
  };
  FOR(i, n) a[i] = f(a[i]);
  ll N = QMAX(a) + 1;
  vector<ll> c(N);
  FOR(i, n) ++c[a[i]];

  vector<mint> v(N);
  FOR(i, 1, N) {
    FOR(k, i, N, i) {
      v[i] += c[k] * k;
    }
  }
  FOR(i, N) v[i] *= v[i];
  multiplier_mobius(v);
  
  mint ans = -n;
  FOR(i, N) {
    ans += v[i] / (i * i);
  }
  UL(ans / 2);
}
#include "MeIoN_Lib/Z_H/main.hpp"