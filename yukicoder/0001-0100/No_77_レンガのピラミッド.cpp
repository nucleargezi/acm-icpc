#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  a.resize(N + 200);
  N += 200;
  int sm = SUM(a), ans = inf<int>;
  FOR(sz, 1, N + 1, 2) {
    int x = 0, y = 0, s = 0;
    FOR(i, sz) {
      int d = min(i + 1, sz - i);
      s += d;
      if (a[i] > d) x += a[i] - d;
      else if (a[i] < d) y += d - a[i];
    }
    if (s > sm) break;
    FOR(i, sz, N) x += a[i];
    chmin(ans, max(x, y));
  }
  print(ans);
}
#include "YRS/aa/main.hpp"