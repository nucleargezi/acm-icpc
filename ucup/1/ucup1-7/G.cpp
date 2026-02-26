#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/string/run_length.hpp"
#include "YRS/mod/powertable.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = mint_t<1'000'000'000 + 9>;
Z pt = power_table_1<mint>(2, 5'000'00 + 10);
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  for (ll &x : a) x *= 2;
  sort(a);
  ll d = (N & 1 ? a[N >> 1] : (a[N / 2 - 1] + a[N / 2]) / 2);
  vc<ll> b, c;
  for (ll x : a) {
    if (x < d) b.ep(d - x);
    if (x > d) c.ep(x - d);
  }
  while (len(b) < N / 2) b.ep(0);
  while (len(c) < N / 2) c.ep(0);
  sort(b);
  sort(c);
  if (b != c) return print(0);
  mint ans = fac(N / 2);
  for (Z [x, y] : run_length(b)) {
    ans *= ifac(y);
    if (x) ans *= pt[y];
  }
  print(ans);
}
#include "YRS/aa/main.hpp"