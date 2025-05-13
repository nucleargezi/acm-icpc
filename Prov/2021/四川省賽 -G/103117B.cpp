#include "MeIoN_Lib/Z_H/MeioN.hpp"
#include "MeIoN_Lib/MeIoN_all.hpp"

void before() {}

#define tests
void Yorisou() {
  LL(n, m, K);
  ll t = K / (n + n);
  K %= n + n;
  vector<u8> vis(m);
  vector<ll> ans(n);
  VEC(ll, a, n);
  FOR(i, n) --a[i];
  FOR(2) FOR(i, n) {
    ans[i] += vis[a[i]];
    vis[a[i]] ^= 1;
  }
  FOR(i, n) ans[i] *= t;
  FOR(i, K) {
    ll x = i % n;
    ans[x] += vis[a[x]];
    vis[a[x]] ^= 1;
  }
  UL(ans);
}
#include "MeIoN_Lib/Z_H/main.hpp"