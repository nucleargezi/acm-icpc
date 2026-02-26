#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/segd.hpp"
#include "YRS/al/m/max_subarray_sum.hpp"

#define tests 0
#define fl 0
#define DB 10
using MX = monoid_max_subarray_sum<int>;
using DS = segd_t<MX, true, int, 1 << 18>;
using np = DS::np;
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  vc<int> f = a;
  unique(f);
  int sz = len(f);
  vvc<int> v(sz);
  FOR(i, N) {
    int x = a[i];
    v[lb(f, x)].ep(i);
  }

  DS seg(0, N);
  vc<np> t(sz);
  vc<MX::X> dat(N, MX::sing(-1));
  for (int x : v[sz - 1]) dat[x] = MX::sing(1);
  t[sz - 1] = seg.newnode(dat);
  FOR_R(i, sz - 1) {
    t[i] = t[i + 1];
    for (int x : v[i]) {
      t[i] = seg.set(t[i], x, MX::sing(1));
    }
  }

  INT(Q);
  int ans = 0, q[4];
  FOR(Q) {
    FOR(i, 4) IN(q[i]), q[i] += ans, q[i] %= N;
    std::sort(q, q + 4);
    int a = q[0], b = q[1], c = q[2], d = q[3];
    ++b, ++d;
    int id = bina([&](int x) -> bool {
      int s = seg.prod(t[x], b, c).s;
      s += seg.prod(t[x], a, b).r;
      s += seg.prod(t[x], c, d).l;
      return s >= 0;
    }, 0, sz);
    print(ans = f[id]);
  }
}
#include "YRS/aa/main.hpp"