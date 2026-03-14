#define YRSD
// #include "YRS/aa/fast.hpp"
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/binom.hpp"
#include "YRS/nt/bigint/big.hpp"

void Yorisou() {
  using ll = bigint;
  ll a, b;
  INT(N);
  FOR(N) {
    IN(a, b);
    a *= b;
    print(a);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"