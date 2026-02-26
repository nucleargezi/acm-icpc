#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
ll merge(vc<PLL> &rgs) {
  ll s = 0, p = -inf<ll>;
  for (Z [l, r] : rgs) {
    chmax(p, l);
    s += max(0ll, r - p);
    chmax(p, r);
  }
  return s;
}
void Yorisou() {
  INT(N, D, T);
  VEC(ll, x, N);
  for (ll &x : x) x += inf<int>;
  map<ll, vc<int>> mp;
  for (ll x : x) mp[x % D].ep(x / D);
  ll ans = 0;
  for (Z &[_, a] : mp) {
    sort(a);
    vc<PLL> rgs;
    for (int x : a) rgs.ep(x - T, x + T + 1);
    ans += merge(rgs);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"