#include "YRS/all.hpp"
#include "YRS/ge/basic/angle_sort.hpp"

using P = point<ll>;
void no(P &p) {
  Z &[x, y] = p;
  ll g = gcd(x, y);
  x /= g, y /= g;
  if (x < 0 or (x == 0 and y < 0)) x = -x, y = -y;
}
void Yorisou() {
  INT(N);
  vc<pair<P, P>> a;
  FOR(N) {
    INT(x, xx, y);
    if (x > xx) swap(x, xx);
    a.ep(P(x, y), P(xx, y));
  }
  
  ll ans = 0;
  Z ke = [&](vc<P> v, const vc<ll> &w, P bs) -> ll {
    for (P &p : v) p -= bs;
    int N = si(w);
    FOR(i, N) if (v[i << 1].y < 0) {
      swap(v[i << 1], v[i << 1 | 1]);
      v[i << 1] = -v[i << 1], v[i << 1 | 1] = -v[i << 1 | 1];
    }
    vc<int> I = angle_sort(v);
    int sz = si(I);
    vc<int> rk(sz);
    FOR(k, sz) rk[I[k]] = k;
    FOR(k, 1, sz) {
      int l = I[k - 1], r = I[k];
      P x = v[l], y = v[r];
      no(x), no(y);
      if (x == y) rk[r] = rk[l];
    }
    vc<ll> c(sz + 1);
    FOR(i, N) {
      int l = rk[i << 1], r = rk[i << 1 | 1];
      ll e = w[i];
      if (l > r) swap(l, r);
      c[l] += e, c[r + 1] -= e;
    }
    FOR(i, sz) c[i + 1] += c[i];
    return QMAX(c);
  };

  FOR(i, N) {
    vc<P> v;
    vc<ll> w;
    FOR(k, N) if (k != i and a[i].fi.y != a[k].fi.y) {
      v.ep(a[k].fi);
      v.ep(a[k].se);
      w.ep(a[k].se.x - a[k].fi.x);
    }
    ll es = a[i].se.x - a[i].fi.x;
    chmax(ans, ke(v, w, a[i].fi) + es);
    chmax(ans, ke(v, w, a[i].se) + es);
  }
  print(ans);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"