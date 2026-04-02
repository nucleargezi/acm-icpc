#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/pow_fast.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = modint<998244352>;
void Yorisou() {
  INT(x, N);
  pow_fast<mint> f(x);
  FOR(i, N) {
    INT(x);
    put(f(x));
  }
}
#include "YRS/aa/main.hpp"