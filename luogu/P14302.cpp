#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dsu.hpp"
#include "YRS/al/m/max_subarray_sum.hpp"

#define tests 0
#define fl 0
#define DB 10
ull sd;
ull rng() {
  sd ^= sd << 13, sd ^= sd >> 7;
  return sd ^= sd << 17;
}
ull splitmix64(ull x) {
  x += 0x9e3779b97f4a7c15;
  x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
  x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
  return x ^ (x >> 31);
}

using MX = monoid_max_subarray_sum<ll>;
using X = MX::X;
struct skew {
  struct node {
    int fa, hd, d;
    X c, s;
  };
  int N;
  vc<vc<int>> g;
  vc<node> a;
  
  inline int &fa(int i) { return a[i].fa; }
  inline int &hd(int i) { return a[i].hd; }
  inline int &d(int i) { return a[i].d; }

  inline X &c(int i) { return a[i].c; }
  inline X &s(int i) { return a[i].s; }
  
  skew(int N) : N(N), g(N), a(N) { FOR(i, N) c(i) = MX::unit(), add(i, -1); }
  skew(const vc<X> &dat) : N(len(dat)), g(N), a(N) {
    FOR(i, N) c(i) = dat[i], add(i, -1);
  }

  inline void add(int n, int p) {
    a[n] = {p, n, p == -1 ? 0 : d(p) + 1, c(n), c(n)};
    if (p != -1 and fa(hd(p)) != -1) {
      int q = fa(hd(p));
      if (d(p) - d(hd(p)) == d(q) - d(hd(q))) {
        s(n) = MX::op(MX::op(s(q), s(p)), s(n));
        hd(n) = hd(q);
      }
    }
  }
  void dfs(int n, int p) {
    add(n, p);
    for (int t : g[n]) if (t != p) dfs(t, n);
  }
  void add_edge(int n, int p) {
    g[p].ep(n);
    g[n].ep(p);
    dfs(n, p);
  }
  X prod(int x, int y) {
    X sl = MX::unit(), sr = sl;
    while (d(x) > d(y)) {
      if (d(hd(x)) > d(y) + 1) {
        sl = MX::op(s(x), sl);
        x = fa(hd(x));
      } else {
        sl = MX::op(c(x), sl);
        x = fa(x);
      }
    }
    while (d(x) < d(y)) {
      if (d(hd(y)) > d(x) + 1) {
        sr = MX::op(s(y), sr);
        y = fa(hd(y));
      } else {
        sr = MX::op(c(y), sr);
        y = fa(y);
      }
    }
    while (x != y) {
      if (hd(x) != hd(y)) {
        sl = MX::op(s(x), sl);
        sr = MX::op(s(y), sr);
        x = fa(hd(x));
        y = fa(hd(y));
      } else {
        sl = MX::op(c(x), sl);
        sr = MX::op(c(y), sr);
        x = fa(x);
        y = fa(y);
      }
    }
    if (not MX::isid(sl)) swap(sl.l, sl.r);
    return MX::op(MX::op(sl, c(x)), sr);
  }
};
void Yorisou() {
  INT(N, Q);
  IN(sd);
  sd = splitmix64(sd);
  vc<X> dat(N);
  FOR(i, N) {
    uint x = rng();
    dat[i] = MX::sing(int(x));
  }
  
  skew ds(dat);
  dsu g(N);
  FOR(Q) {
    int x = rng() % N, y = rng() % N;
    if (g[x] == g[y]) {
      sd ^= ds.prod(x, y).mx;
    } else {
      if (g.size(x) < g.size(y)) swap(x, y);
      g.merge(x, y);
      ds.add_edge(y, x);
    }
  }
  print(sd);
}
#include "YRS/aa/main.hpp"