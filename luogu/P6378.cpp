#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/g/two_sat.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, K);
  TwoSat g(N + 2'000'000);
  FOR(i, M) {
    INT(x, y);
    --x, --y;
    g.ban(x, y, 0, 0);
  }
  int t = N;
  vc<int> L(N), R(N);
  FOR(K) {
    INT(sz);
    VEC(int, a, sz);
    FOR(i, sz) --a[i];
    FOR(i, sz) L[i] = t++, R[i] = t++;
    FOR(i, sz) {
      g.ban(L[i], a[i], 1, 1);
      g.ban(R[i], a[i], 1, 1);
      if (i > 0) {
        g.ban(L[i], L[i - 1], 1, 0);
        g.ban(a[i], L[i - 1], 1, 0);
      }
      if (i + 1 < sz) {
        g.ban(R[i], R[i + 1], 1, 0);
        g.ban(a[i], R[i + 1], 1, 0);
      }
    }
  }
  TAK(g.solve());
}
#include "YRS/aa/main.hpp"