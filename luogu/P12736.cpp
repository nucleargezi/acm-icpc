#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/seg_t.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/al/m/hash.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M17;
using MX = monoid_hash<>;
void Yorisou() {
  INT(N, Q);
  vvc<int> se(N);
  FOR(i, N) se[i].ep(i);
  vc<int> fa(N);
  iota(all(fa), 0);
  
  seg_t<MX> seg(N, [&](int i) { return MX::sing(i); });

  FOR(Q) {
    INT(x, y, z);
    int a = x - 1, b = a + z, c = y - 1;
    while (a < b) {
      int sz = bina([&](int sz) -> bool {
        return seg.prod(a, a + sz) == seg.prod(c, c + sz);
      }, 0, b - a + 1);
      if (a + sz == b) break;
      a += sz, c += sz;
      int f, t;
      if (len(se[fa[a]]) > len(se[fa[c]])) f = fa[c], t = fa[a];
      else f = fa[a], t = fa[c];
      for (int x : se[f]) {
        fa[x] = t;
        se[t].ep(x);
        seg.set(x, MX::sing(t));
      }
      se[f].clear();
      se[f].shrink_to_fit();
      ++a, ++c;
    }
  }

  int c = 0;
  FOR(i, N) c += fa[i] == i;
  print(c);
}
#include "YRS/aa/main.hpp"