#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/mod/powertable.hpp"
#include "YRS/range_of/mo.hpp"
#include "YRS/tr/hld.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M99;
const vc<mint> pw = power_table_1(mint(2), 1'000'10);
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  for (int &x : a) --x;

  graph g(N);
  g.sc();
  hld v(g);
  const vc<int> &L = v.L, &R = v.R, &V = v.V;
  
  Mo mo;
  FOR(i, N) mo.add(L[i], R[i]);

  mint s, ss;
  vc<int> c(N);
  for (int x : a) ++c[x];
  vc<int> d(c);
  for (int &x : c) ss += pw[x] - 1, x = 0;

  Z ad = [&](int i) {
    int x = a[V[i]];
    s += pw[c[x]];
    ++c[x];
    --d[x];
    ss -= pw[d[x]];
  };
  Z rm = [&](int i) {
    int x = a[V[i]];
    --c[x];
    s -= pw[c[x]];
    ss += pw[d[x]];
    ++d[x];
  };
  vc<pair<mint, mint>> rs(N);
  Z ke = [&](int i) { rs[i] = {s, ss}; };
  mo(ad, ad, rm, rm, ke);

  mint ans;
  for (Z x : rs) ans += x.fi * x.se * 2;

  vc<mint> go;
  for (int n : V) {
    go.clear();
    mint s;
    for (Z &&e : g[n]) {
      if (e.to == v.fa[n]) go.ep(rs[n].se);
      else go.ep(rs[e.to].fi);
    }
    for (mint x : go) s += x;
    for (mint x : go) ans -= x * (s - x);
  }
  print(ans);
}
#include "YRS/aa/main.hpp"