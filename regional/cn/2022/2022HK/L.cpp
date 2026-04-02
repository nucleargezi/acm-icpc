#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/seg_base.hpp"
#include "YRS/ds/monoid/add.hpp"
#include "YRS/ds/monoid/max.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, K);
  VEC(int, a, N);
  VEC(int, b, M);
  VEC(int, l, K);

  vc<int> I;
  int i = 0, k = 0;
  for (; i < N; ++i) {
    if (k < M and a[i] == b[k]) ++k;
    else I.ep(i);
  }
  if (k != M) return NO();
  sort(I, [&](int i, int k) { return a[i] > a[k]; });

  multiset<int> se{all(l)};
  Seg<monoid_add<int>> c(N, [&](int) { return 1; });
  Seg<monoid_max<int>> seg(a);
  for (int i : I) {
    int x = a[i];
    int l = seg.min_left([&](int s)  { return s <= x; }, i);
    int r = seg.max_right([&](int s)  { return s <= x; }, i);
    int ct = c.prod(l, r);
    Z it = se.upper_bound(ct);
    if (it == se.begin()) return NO();
    --it;
    se.extract(it);
    seg.set(i, -1);
    c.set(i, 0);
  }
  YES();
}
#include "YRS/aa/main.hpp"