#include "YRS/all.hpp"
#include "YRS/pr/divisors.hpp"

void Yorisou() {
  LL(N);
  ll s = 0;
  for (ll x : divisor(N & 1 ? N : N / 2)) s += x;
  print(s);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"