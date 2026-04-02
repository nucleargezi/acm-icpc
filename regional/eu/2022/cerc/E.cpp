#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

using re = ld;
void Yorisou() {
  INT(N);
  VEC(re, a, N);
  re m = QMIN(a);
  for (re &x : a) x /= m;
  re mn = inf<re>;
  int ai = -1;
  FOR(i, 1, 10001) {
    re mx = 0;
    for (re x : a) {
      x *= i;
      chmax(mx, abs(x - round(x)));
    }
    if (chmin(mn, mx)) ai = i;
  }
  FOR(k, N) print(ll(round(a[k] * ai)));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"