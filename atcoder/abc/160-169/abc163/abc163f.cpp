#include "YRS/all.hpp"
#include "YRS/IO/fio.hpp"
#include "YRS/ds/rb/rb_dsu.hpp"

void Yorisou() {
  INT(N);
  VEC(int, c, N);
  vc<vc<int>> v(N);
  FOR(i, N) v[--c[i]].ep(i);
  VEC(PII, es, N - 1);
  for (Z &[f, t] : es) --f, --t;
  vc<vc<int>> cut(N - 1);
  vc<vc<PII>> g(N);
  FOR(i, N - 1) {
    var [a, b] = es[i];
    g[a].ep(b, i), g[b].ep(a, i);
  }

  FOR(i, N) for (int n : v[i]) {
    for (var [x, id] : g[n]) cut[id].ep(i);
  }
  vc<T3<int>> dat;
  FOR(i, N - 1) {
    unique(cut[i]);
    int l = 0;
    for (int t : cut[i]) {
      if (l < t) dat.ep(i, l, t);
      l = t + 1;
    }
    if (l < N) dat.ep(i, l, N);
  }
  
  vc<int> I(si(dat));
  iota(all(I), 0);
  rb_dsu ds(N);
  ll s = 0;
  Z f = [&](Z &f, int l, int r, const vc<int> &I) -> void {
    if (l >= r) return;
    ll cp = s, t = ds;
    int m = (l + r) >> 1;
    vc<int> ls, rs;
    for (int i : I) {
      var [ei, pl, pr] = dat[i];
      var [f, t] = es[ei];
      if (pl < l + 1 and pr > r - 1) {
        if (ds[f] != ds[t]) {
          ll sz = ds.size(f);
          s -= sz * (sz - 1) / 2;
          sz = ds.size(t);
          s -= sz * (sz - 1) / 2;
          ds.merge(f, t);
          sz = ds.size(t);
          s += sz * (sz - 1) / 2;
        }
      } else {
        if (pl < m) ls.ep(i);
        if (pr > m) rs.ep(i);
      }
    }
    if (l + 1 == r) print(ll(N - 1) * N / 2 - s + si(v[l]));
    else f(f, l, m, ls), f(f, m, r, rs);
    ds(t), s = cp;
  };
  f(f, 0, N, I);
}

int main() { Yorisou(); }