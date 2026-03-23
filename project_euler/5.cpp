#include "YRS/all.hpp"

void Yorisou() {
  ll g = 1;
  for (ll x = 1; x <= 20; ++x) g = lcm(g, x);
  print(g);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"