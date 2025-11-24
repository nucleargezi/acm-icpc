#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#define tests 0
#define fl 0
#define DB 10
using RE = long double;
bool f(int N, int w, int M) {
  vector<vector<PII>> r(M);
  int k = 0, y = 0;
  FOR(i, M) {
    for (int x = N; x; ) {
      if (y == 0) ++k, y = M;
      int d = min(x, y);
      r[i].ep(d, k);
      x -= d, y -= d;
      if (x == 0 and d + N < M) return false;
    }
  }
  YES();
  setp(6);
  FOR(i, M) {
    for (Z [x, y] : r[i]) put(y, RE(w) / M * x);
    print();
  }
  return true;
}
void Yorisou() {
  INT(N, w, M);
  if (not f(N, w, M)) NO();
}
#include "YRS/Z_H/main.hpp"