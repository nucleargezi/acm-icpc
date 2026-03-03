#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/tr/near_kinbo.hpp"

template <uint B = 1 << 7>
struct pars {
  uint N, *a;

  pars(const vc<uint> &s) : N(len(s)) {
    a = new uint[N << 1];
    copy(all(s), a + N);
    fill(a, a + N, 0);
    for (uint i = (N << 1) - 1; i >= 1; --i) a[i / B] += a[i];
  }

  ~pars() { delete[] a; }

  void add(uint i, uint x) {
    a[i += N] += x;
    while (i /= B) a[i] += x;
  }

  uint prod(uint l, uint r) {
    l += N, r += N;
    uint s = 0;
    while (l / B != r / B) {
      while (l & (B - 1)) s += a[l++];
      while (r & (B - 1)) s += a[--r];
      l /= B, r /= B;
    }
    for (uint i = l; i < r; ++i) s += a[i];
    return s;
  }
};
void Yorisou() {
  INT(N, Q);
  VEC(uint, a, N);
  graph g(N);
  g.sc();
  near_kinbo ds(g);
  int sz = ds.tt;
  vc<uint> dat(sz);
  FOR(i, N) for (int x : ds.vs(i)) dat[x] += a[i];
  pars bit(dat);
  uint s = 0;
  FOR(Q) {
    INT(op, x, y);
    x ^= s, y ^= s;
    --x;
    if (op == 0) {
      s = 0;
      for (Z [l, r] : ds.range(x, 0, y + 1)) 
        s += bit.prod(l, r);
      print(s);
    } else {
      int d = y - a[x];
      for (int i : ds.vs(x)) bit.add(i, d);
      a[x] = y;
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"