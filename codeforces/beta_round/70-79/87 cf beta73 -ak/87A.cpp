#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(a, b);
  ll l = std::lcm(a, b);
  a = l / a, b = l / b;
  if (a < b) ++a;
  else if (a > b) ++b;
  print(a < b ? "Masha" : a == b ? "Equal" : "Dasha");
}
#include "YRS/Z_H/main.hpp"