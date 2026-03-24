#include "YRS/all.hpp"
#include "YRS/pr/divisors.hpp"

void Yorisou() {
  ll s = 1 + 2 + 3 + 4;
  FOR(i, 5, 1000000) {
    s += i;
    if (si(divisor(s)) > 500) return print(s);
  }
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"