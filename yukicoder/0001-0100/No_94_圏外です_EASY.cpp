#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/unionfind/dsu.hpp"
#include "YRS/ge/pairs/furthest_pair.hpp"

#define tests 0
#define fl 0
#define DB 10
using P = point<ll>;
void Yorisou() {
  INT(N);
  if (N == 0) return print(1);
  VEC(P, a, N);
  dsu g(N);
  FOR(i, N) FOR(k, i + 1, N) {
    if ((a[i] - a[k]).square() <= 100) g.merge(i, k);
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