#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

void Yorisou() {
  INT(N, B);
  VEC(T3<int>, a, N);
  vc<int> x, y;
  for (Z &[a, b, c] : a) x.ep(a), y.ep(b);
  unique(x);
  unique(y);
  for (Z &[a, b, c] : a) a = lb(x, a), b = lb(y, b);

  int sx = len(x), sy = len(y);
  retsu<int> cnt(sx + 1, sy + 1), sum(cnt);
  for (Z &[a, b, c] : a) {
    cnt[a + 1][b + 1] += 1;
    sum[a + 1][b + 1] += c;
  }
  cnt.pres();
  sum.pres();

  int s = 0;
  FOR(a, sx) FOR(b, a + 1, sx + 1) {
    int r = 0;
    FOR(l, sy) {
      chmax(r, l);
      while (r < sy and sum.prod(a, b, l, r + 1) <= B) ++r;
      chmax(s, cnt.prod(a, b, l, r));
    }
  }
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"