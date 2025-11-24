#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/math/mod/modint.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M99;
mint keis(ll x, ll y, ll xx, ll yy) {
  x = xx - x, y = yy - y;
  return C<mint>(x + y, x);
}
void Yorisou() {
  INT(N, M, a, b, c, d);
  if (M > N) swap(N, M), swap(a, b), swap(c, d);
  mint al = keis(0, 0, N, M), s = 0;
  mint pr = 0, t;
  FOR(i, b + 1) {
    t = keis(0, 0, c, i);
    s += (t - pr) * keis(c, i, N, M);
    pr = t;
  }
  pr = 0;
  FOR(i, d, M + 1) {
    t = keis(0, 0, a, i);
    s += (t - pr) * keis(a, i, N, M);
    pr = t;
  }
  print(s / al);
}
#include "YRS/Z_H/main.hpp"