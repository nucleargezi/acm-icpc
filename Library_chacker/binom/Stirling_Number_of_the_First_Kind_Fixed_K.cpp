#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/po/f/stiling_1.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, K);
  Z r = stiling_1_k<mint>(N, K, 1);
  reverse(all(r));
  while (not r.empty() and r.back() == mint(0)) r.pop_back();
  reverse(all(r));
  print(r);
}
#include "YRS/aa/main.hpp"