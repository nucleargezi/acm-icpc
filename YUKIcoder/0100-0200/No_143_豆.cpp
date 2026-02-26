#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

void Yorisou() {
  LL(K, N, sz);
  VEC(ll, a, sz);
  ll s = K * N - SUM(a);
  print(max(s, -1ll));
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"