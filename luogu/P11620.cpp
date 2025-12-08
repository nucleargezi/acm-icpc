#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/seg/dual_seg.hpp"
#include "YRS/ds/seg/seg_base.hpp"
#include "YRS/ds/monoid/xor.hpp"
#include "YRS/ds/monoid/vector_space.hpp"

#define tests 0
#define fl 0
#define DB 10
using bs = vector_space<int>;
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  vc<int> b(N);
  FOR(i, 1, N) b[i] = a[i] ^ a[i - 1];
  dual_seg<monoid_xor<int>> s(N);
  Seg<monoid_vector_space<int>> seg(N, [&](int i) {
    bs x;
    x.add(b[i]);
    return x;
  });
  FOR(Q) {
    INT(op, l, r, x);
    --l;
    if (op == 1) {
      s.apply(l, r, x);
      bs nx;
      nx.add(b[l] ^= x);
      seg.set(l, nx);
      nx.a.clear();
      if (r != N) nx.add(b[r] ^= x), seg.set(r, nx);
    } else {
      bs e = l == r ? bs() : seg.prod(l + 1, r);
      e.add(s.get(l) ^ a[l]);
      print(e.get_max(x));
    }
  }
}
#include "YRS/Z_H/main.hpp"