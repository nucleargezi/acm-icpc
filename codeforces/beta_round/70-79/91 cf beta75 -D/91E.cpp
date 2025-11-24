#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ge/all.hpp"
#include "YRS/math/fibonacci_search.hpp"
#include "YRS/ds/basic/hashmap.hpp"

#define tests 0
#define fl 0
#define DB 100
using P = point<ll>;
using X = vector<P>;
PLL keis(const X &f, ll x) {
  return fibonacci_search<ll, 0>([&](int i) -> ll {
    return f[i].x + f[i].y * x;
  }, 0, len(f));
}
void Yorisou() {
  INT(N, Q);
  VEC(P, p, N);
  int sz = 1;
  while (sz < N) sz <<= 1;
  vector<X> a(sz << 1);
  FOR(i, N) a[sz + i].ep(p[i]);
  FOR_R(i, 1, sz) {
    a[i] = a[i << 1];
    a[i].insert(a[i].end(), all(a[i << 1 | 1]));
    a[i] = rearrange(a[i], hull(a[i], 2));
  }
  hash_map<vector<int>> mp;
  FOR(i, N) mp[p[i].x << 30 | p[i].y].ep(i + 1);
  FOR(Q) {
    INT(l, r, t);
    --l;
    int rl = l;
    ll ans = 0;
    P sp;
    l += sz, r += sz;
    while (l < r) {
      if (l & 1) {
        Z [f, i] = keis(a[l], t);
        if (chmax(ans, f)) sp = a[l][i];
        ++l;
      }
      if (r & 1) {
        --r;
        Z [f, i] = keis(a[r], t);
        if (chmax(ans, f)) sp = a[r][i];
      }
      l >>= 1, r >>= 1;
    }
    const Z &v = mp[sp.x << 30 | sp.y];
    print(v[upper_bound(v, rl)]);
  }
}
#include "YRS/Z_H/main.hpp"