#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/modint.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, K);
  int g = std::gcd(N, K), sz = N / g;
  mint s = mint(2).pow(sz) - 1;
  s = s.pow(g - 1);
  s *= mint(2).pow(sz) + g - 1;
  print(s);
}
#include "YRS/aa/main.hpp"