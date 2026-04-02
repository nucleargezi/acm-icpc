#define YRSD
#include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
#include "YRS/tr/near_kinbo.hpp"

#ifdef VIEW
constexpr int sz = 10;
#else
constexpr int sz = 4'000'000;
#endif
int N;
ll a[sz];
constexpr int B = 1 << 5;

void build(const vc<ll> &s) {
  N = len(s);
  FOR(i, N) a[i + N] = s[i];
  for (uint i = (N << 1) - 1; i >= 1; --i) a[i / B] += a[i];
}

void add(uint i, ll x) {
  a[i += N] += x;
  while (i /= B) a[i] += x;
}

ll prod(uint l, uint r) {
  l += N, r += N;
  ll s = 0;
  while (l / B != r / B) {
    while (l & (B - 1)) s += a[l++];
    while (r & (B - 1)) s += a[--r];
    l /= B, r /= B;
  }
  for (uint i = l; i < r; ++i) s += a[i];
  return s;
}
void Yorisou() {
  INT(N, Q);
  VEC(int, a, N);
  graph g(N);
  g.sc<0, 0>();
  near_kinbo ds(g);
  vc<ll> dat(ds.tt);
  FOR(i, N) for (int x : ds.vs(i)) dat[x] += a[i];
  build(dat);
  FOR(Q) {
    INT(op);
    if (op == 0) {
      INT(x, y);
      for (int i : ds.vs(x)) add(i, y);
    } else {
      INT(x, l, r);
      ll s = 0;
      for (Z [l, r] : ds.range(x, l, r)) s += prod(l, r);
      print(s);
    }
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"