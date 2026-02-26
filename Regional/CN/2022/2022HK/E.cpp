#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/lazy_seg_base.hpp"
#include "YRS/ds/a_monoid/mincnt_add.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  int sz = QMAX(a);
  for (int &x : a) --x;
  vvc<int> v(sz);
  vc<int> p(N);
  FOR(i, N) v[a[i]].ep(i), p[i] = len(v[a[i]]) - 1;
  ll ans = 0;
  lazy_seg<a_monoid_mincnt_add<int>> seg(N, [&](int) { return PII(0, 1); });
  FOR(i, N) {
    int x = a[i], id = p[i];
    if (id >= K) {
      int l = id - K ? v[x][id - K - 1] + 1 : 0, r = v[x][id - K] + 1;
      seg.apply(l, r, -1);
    }
    if (id + 1 >= K) {
      int l = id - K > -1 ? v[x][id - K] + 1 : 0, r = v[x][id - K + 1] + 1;
      seg.apply(l, r, 1);
    }
    Z [mn, c] = seg.prod(0, i + 1);
    if (mn == 0) ans += c;
  }
  print(ans);
}
#include "YRS/aa/main.hpp"