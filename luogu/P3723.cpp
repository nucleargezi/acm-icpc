#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/convolution.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M);
  VEC(mint, a, N);
  VEC(mint, b, N);
  ll ans = 0, t = 0;
  FOR(i, N) {
    ans += 1ll * a[i].val() * a[i].val();
    ans += 1ll * b[i].val() * b[i].val();
    t += (ll)b[i].val() - a[i].val();
  }
  int X = std::floor(t * 1.0 / N), Y = std::ceil(t * 1.0 / N);
  ans += min(N * X * X - 2 * X * t, N * Y * Y - 2 * Y * t);
  reverse(all(a));
  b.insert(b.end(), all(b));
  a = convolution(a, b);
  t = 0;
  FOR(i, N + 1) chmax(t, a[N + i].val());
  print(ans - t - t);
}
#include "YRS/aa/main.hpp"