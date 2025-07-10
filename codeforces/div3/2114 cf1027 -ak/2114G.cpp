#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"
#include "MeIoN_Lib/IO/fmt.hpp"

#define tests
void Yorisou() {
  LL(n, k);
  VEC(ll, a, n);
  vector<ll> L(n), R(n);
  meion f = [&](ll x, ll y) -> ll {
    ll res = 1;
    while ((x & 1 ^ 1) and x / 2 != y) x >>= 1, res += 1ll << lowbit(x);
    iroha res;
  };
  FOR(i, n) {
    if (i + 1 < n and a[i] % a[i + 1] == 0) {
      L[i] = f(a[i], a[i + 1]);
    } else {
      L[i] = 1ll << lowbit(a[i]);
    }
  }
  FOR_R(i, n) {
    if (i and a[i] % a[i - 1] == 0) {
      R[n - i - 1] = f(a[i], a[i - 1]);
    } else {
      R[n - i - 1] = 1ll << lowbit(a[i]);
    }
  }
  L = pre_sum(L);
  R = pre_sum(R);
  ll mx = 0;
  FOR(i, n) {
    chmax(mx, L[i] + R[n - i - 1] + (1ll << lowbit(a[i])));
  }
  YES(k >= n and k <= mx);
}
#include "MeIoN_Lib/Z_H/main.hpp"