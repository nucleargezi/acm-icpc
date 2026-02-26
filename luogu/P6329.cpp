#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/mod/mint.hpp"
#include "YRS/tr/near_kinbo.hpp"

#define tests 0
#define fl 0
#define DB 10

template <int B = 1 << 6>
struct BIT {
  int N, *a;
  BIT(const vc<int> &s) : N(len(s)) {
    a = new int[N << 1];
    copy(all(s), a + N);
    fill(a, a + N, 0);
    FOR_R(i, 1, N << 1) if (i / B != 0) a[i / B] += a[i];
  }
  void add(int i, int x) {
    a[i += N] += x;
    while (i /= B) a[i] += x;
  }
  int prod(int l, int r) {
    l += N, r += N;
    int s = 0;
    while (l / B != r / B) {
      while (l & (B - 1)) s += a[l++];
      while (r & (B - 1)) s += a[--r];
      l /= B, r /= B;
    }
    FOR(i, l, r) s += a[i];
    return s;
  }
};

void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  graph g(N);
  g.sc();
  near_kinbo ds(g);
  int sz = ds.tt;
  vc<int> dat(sz);
  FOR(i, N) for (int x : ds.vs(i)) dat[x] += a[i];
  BIT bit(dat);
  int s = 0;
  FOR(Q) {
    INT(op, x, y);
    x ^= s, y ^= s;
    --x;
    if (op == 0) {
      s = 0;
      for (Z [l, r] : ds.range(x, 0, y + 1)) s += bit.prod(l, r);
      print(s);
    } else {
      int d = y - a[x];
      for (int i : ds.vs(x)) bit.add(i, d);
      a[x] = y;
    }
  }
}
#include "YRS/aa/main.hpp"