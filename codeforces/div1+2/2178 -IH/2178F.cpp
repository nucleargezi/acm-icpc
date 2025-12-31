#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/tr/Basic.hpp"
#include "YRS/mod/modint.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N);
  graph g(N);
  g.read_tree();
  tree v(g);
  vc<int> sz(N), a{0};
  Z f = [&](Z &f, int n, int fa, int p) -> void {
    ++sz[p];
    for (Z &&e : g[n]) if (e.to != fa) {
      if (v.subtree_size(e.to) & 1) f(f, e.to, n, p);
      else a.ep(e.to), f(f, e.to, n, e.to);
    }
  };
  f(f, 0, -1, 0);
  int M = len(a);
  if (M == 1) return print(1);
  mint s = 1;
  for (int x : a) if (x != 0) s *= sz[x];
  mint I = 0;
  for (int x : a) if (x != 0) I += inv<mint>(sz[x]);
  print(mint(sz[0]) * s * s * fact<mint>(M - 2) * I);
}
#include "YRS/aa/main.hpp"