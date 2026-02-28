#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"
// #include "YRS/aa/def.hpp"

void Yorisou() {
  INT(N);
  vc<ll> a;
  FOR(N) {
    LL(x, y);
    a.ep(x + 4 * y);
  }
  sort(a);
  FOR(i, N - 1) if ((a[i] ^ a[i + 1]) & 1) return print(-1);
  ll s = 0, mx = QMAX(a);
  for (ll x : a) s += mx - x;
  print(s / 2);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"