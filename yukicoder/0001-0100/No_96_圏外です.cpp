#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dsu.hpp"
#include "YRS/ge/pairs/furthest_pair.hpp"
#include "YRS/ds/basic/hashmap.hpp"

#define tests 0
#define fl 0
#define DB 10
using P = point<ll>;
void Yorisou() {
  INT(N);
  if (N == 0) return print(1);
  VEC(P, a, N);
  FOR(i, N) a[i].x += 10000, a[i].y += 10000;
  hash_map<int> mp;
  FOR(i, N) mp[a[i].x << 30 | a[i].y] = i;
  dsu g(N);
  FOR(i, N) {
    ll x = a[i].x, y = a[i].y;
    FOR(k, 11) FOR(j, 11) {
      if (k * k + j * j > 100) break;
      for (ll d : {-1, 1}) {
        ll xx = x + k, yy = y + j * d;
        if (mp.contains(xx << 30 | yy)) g.merge(i, mp[xx << 30 | yy]);
      }
    }
  }
  vc<vc<int>> s = g.get_group();
  ll mx = 0;
  for (vc<int> &s : s) if (len(s) > 1) {
    vc<P> p;
    for (int i : s) p.ep(a[i]);
    Z [a, b] = furthest_pair(p);
    chmax(mx, (p[a] - p[b]).square());
  }
  setp(9);
  print(sqrtl(mx) + 2);
}
#include "YRS/aa/main.hpp"