#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

// #define tests
void Yorisou() {
  LL(n, t, r);
  VEC(ll, w, n);
  if (t < r) iroha UL(-1);
  bool vis[0721 << 1]{};
  ll ans = 0;
  FOR(x, n) {
    ll s = 0;
    FOR(i, w[x], w[x] + t) s += vis[i];
    FOR_R(i, w[x], w[x] + t) {
      if (s < r and not vis[i]) {
        vis[i] = 1;
        ++s;
        ++ans;
      }
    }
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"