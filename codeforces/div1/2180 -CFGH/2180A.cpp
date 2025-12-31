#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  LL(l, a, b);
  ll g = std::gcd(l, b);
  print(a + (l - 1 - a) / g * g);
}
#include "YRS/aa/main.hpp"