#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"
#include "YRS/ds/rb/rb_dsu.hpp"
#include "YRS/ds/basic/hashmap.hpp"

void Yorisou() {
  INT(N, Q);
  VEC(ll, w, N);
  rb_arr<ll> a(w);

  vc<T4<int>> es;
  es.reserve(Q);
  hashmap<int> mp(Q >> 1);
  vc<int> q(Q, -1);
  FOR(i, Q) {
    INT(op);
    if (op == 0) {
      ULL(x, y);
      if (x > y) swap(x, y);
      mp[x << 32 | y] = i;
    } else if (op == 1) {
      ULL(x, y);
      if (x > y) swap(x, y);
      int &l = mp[x << 32 | y];
      es.ep(x, y, l, i);
      l = -1;
    } else if (op == 2) {
      INT(x, y);
      es.ep(x, y, i, -Q);
    } else {
      INT(x);
      q[i] = x;
    }
  }
  for (Z &[k, l] : mp.get_all()) {
    if (l != -1) es.ep(k >> 32, uint(k), l, Q);
  }
  int sz = len(es);
  vc<int> I(sz);
  iota(all(I), 0);

  rb_dsu g(N);
  Z f = [&](Z &f, int l, int r, const vc<int> &I) -> void {
    if (l >= r) return;
    int t = g.time(), tt = a.time();
    int m = (l + r) >> 1;
    vc<int> ls, rs;
    ls.reserve(len(I) >> 1);
    rs.reserve(len(I) >> 1);
    for (int i : I) {
      Z [x, y, pl, pr] = es[i];
      int op = pr < 0;
      pl = abs(pl), pr = abs(pr);
      if (pl <= l and pr >= r) {
        if (op == 0) {
          x = g[x], y = g[y];
          if (x != y) {
            ll w = a[x] + a[y];
            g.merge(x, y);
            a.set(g[x], w);
          }
        } else {
          x = g[x];
          a.set(x, a[x] + y);
        }
      } else {
        if (pl < m) ls.ep(i);
        if (pr > m) rs.ep(i);
      }
    }
    if (l == r - 1) {
      int x = q[l];
      if (x != -1) print(a[g[x]]);
    } else {
      f(f, l, m, ls);
      f(f, m, r, rs);
    }
    g.rb(t), a.rb(tt);
  };
  f(f, 0, Q, I);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"