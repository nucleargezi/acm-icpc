#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/f/stiling_2.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = modint<167772161>;
void Yorisou() {
  INT(N, K);
  print(stiling_2_k<mint>(N, K));
}
#include "YRS/aa/main.hpp"