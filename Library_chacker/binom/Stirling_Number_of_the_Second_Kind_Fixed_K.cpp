#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/f/stiling_2.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, K);
  Z f = stiling_2_k<mint>(N, K);
  reverse(all(f));
  FOR(K) f.pop_back();
  reverse(all(f));
  print(f);
}
#include "YRS/aa/main.hpp"