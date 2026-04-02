#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"

void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  ll s = SUM(a);
  ll c = 0;
  for (ll x : a) c += 10 * x <= s;
  print(30 * c);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"