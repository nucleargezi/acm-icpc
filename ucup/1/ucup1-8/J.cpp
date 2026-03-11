#define YRSD
#include "YRS/all.hpp"
#include "YRS/IO/fast_io.hpp"

using P = pair<int, ll>;
bool cp(P a, P b) {
  if (a.fi == -inf<int>) return 1;
  return (i128)a.se * b.fi > (i128)a.fi * b.se;
}
struct X {
  vc<P> a;
  bool fail(P a, P b, P c) {
    b.fi -= a.fi, b.se -= a.se;
    c.fi -= a.fi, c.se -= a.se;
    return b.fi * c.se - b.se * c.fi <= 0;
  }
  void merge(const X &p) {
    for (const P &x : p.a) {
      while (len(a) > 1 and fail(ed(a)[-2], ed(a)[-1], x)) pop(a);
      a.ep(x);
    }
  }
  P sb(P a, P b) {
    a.fi -= b.fi, a.se -= b.se;
    return a;
  }
  P f(P X) {
    int l = 0, r = len(a) - 1, a = l - 1, x, b, s = 1, t = 2;
    while (t < r - l + 2) swap(s += t, t);
    x = a + t - s, b = a + t;
    P fx = sb(this->a[x], X), fy;
    while (a + b != 2 * x) {
      int y = a + b - x;
      if (r < y or (fy = sb(this->a[y], X), cp(fy, fx))) {
        b = a, a = y;
      } else {
        a = x, x = y, fx = fy;
      }
    }
    return this->a[x];
  }
};
void Yorisou() {
  INT(N, Q);
  ++N;
  vc<P> a(N);
  FOR(i, 1, N) IN(a[i].se), a[i].se += a[i - 1].se, a[i].fi = i;

  int sz = 1;
  while (sz < N) sz <<= 1;
  vc<X> dat(sz << 1);
  FOR(i, N) dat[i + sz].a.ep(a[i]);
  FOR_R(i, 1, sz) {
    dat[i] = dat[i << 1];
    dat[i].merge(dat[i << 1 | 1]);
  }
  
  FOR(Q) {
    INT(l, r);
    r += l;
    P res{-inf<int>, -inf<ll>}, x = a[l - 1];
    l += sz, r += sz;
    while (l < r) {
      if (l & 1) {
        P g = dat[l].f(x);
        g.fi -= x.fi, g.se -= x.se;
        if (cp(res, g)) res = g;
        ++l;
      }
      if (r & 1) {
        --r;
        P g = dat[r].f(x);
        g.fi -= x.fi, g.se -= x.se;
        if (cp(res, g)) res = g;
      }
      l >>= 1, r >>= 1;
    }
    ll s = floor<ll>(res.se, res.fi);
    if (s < 0) print("stay with parents");
    else print(s);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"