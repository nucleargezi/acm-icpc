#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
struct X {
  ll l, r, c;
};
bool cmp(const X &L, const X &R) {
  if (L.c < R.c or L.l > R.l or L.r < R.r) return 0;
  return L.c > R.c or L.l < R.l or L.r > R.r;
}
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  vc<X> dat{{0, inf<ll>, 0}}, f;
  Z eb = [&](vc<X> &f, ll l, ll r, ll c) -> void {
    if (l >= r or r <= 0) return;
    for (Z &x : f) if (x.l == l and x.r == r) {
      chmax(x.c, c);
      return;
    }
    f.ep(X{l, r, c});
  };
  vc<u8> vis(N << 1);
  FOR(i, N - 1) {
    ll d = a[i + 1] - a[i];
    f.clear();
    for (Z x : dat) {
      Z [l, r, c] = x;
      ll mx = min(r, d);
      if (l < mx) eb(f, d - mx, d - l, c + 1);
      if (l < d) eb(f, 0, d - l, c);
    }
    int sz = len(f);
    FOR(i, sz) vis[i] = 0;
    FOR(i, sz) if (not vis[i]) 
      FOR(k, sz) if (i != k and not vis[k]) 
        vis[i] |= cmp(f[k], f[i]);
    dat.clear();
    FOR(i, sz) if (not vis[i]) dat.ep(f[i]);
  }
  ll s = 0;
  for (Z &x : dat) chmax(s, x.c);
  print(s);
}
#include "YRS/aa/main.hpp"