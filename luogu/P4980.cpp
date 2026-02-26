#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/mod/mint.hpp"
#include "YRS/pr/euler_phi.hpp"
#include "YRS/pr/divisors.hpp"

#define tests 1
#define fl 0
#define DB 10
using mint = M17;
void Yorisou() {
  INT(N);
  Z f = [&](int d) { return mint(N).pow(d) * euler_phi(N / d); };
  mint s = 0;
  for (int x : divisor(N)) s += f(x);
  print(s / N);
}
#include "YRS/aa/main.hpp"