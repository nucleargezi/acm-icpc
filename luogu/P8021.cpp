#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/flow/mcf.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  int s = 5000 + N + 1, t = s + 1, tp = 5000, al = 0;
  int sz = t + 1;
  mcf g(sz * 5);
  FOR(i, sz) g.add(i, 4 * sz + i, sz, 0);
  FOR(i, sz) g.add(2 * sz + i, i, sz, 0);
  FOR(i, sz << 1) g.add(sz + i / 2, sz + i, sz, 0);
  FOR(i, sz << 1) g.add(3 * sz + i, 3 * sz + i / 2, sz, 0);

  Z to_range = [&](int i, int l, int r, int f, int c) -> void {
    l += sz, r += sz;
    while (l < r) {
      if (l & 1) g.add(i, sz + l, f, c), ++l;
      if (r & 1) --r, g.add(i, sz + r, f, c);
      l >>= 1, r >>= 1;
    }
  };
  Z range_to = [&](int l, int r, int i, int f, int c) -> void {
    l += sz, r += sz;
    while (l < r) {
      if (l & 1) g.add(3 * sz + l, i, f, c), ++l;
      if (r & 1) --r, g.add(3 * sz + r, i, f, c);
      l >>= 1, r >>= 1;
    }
  };
  FOR(i, N) g.add(i, t, 1, 0);
  FOR(N) {
    INT(a, b, c);
    --a, --b;
    al += c;
    g.add(s, tp, 1, 0);
    g.add(tp, t, 1, c);
    to_range(tp, a, b, 1, 0);
    ++tp;
  }
  Z [f, c] = g.flow(s, t);
  print(al - c);
}
#include "YRS/aa/main.hpp"