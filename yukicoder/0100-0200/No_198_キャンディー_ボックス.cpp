#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
#include "YRS/nt/fib_search.hpp"

void Yorisou() {
  INT(B, N);
  VEC(ll, a, N);
  print(fib_search<ll, 1>([&](ll x) {
    ll s = 0;
    for (ll e : a) s += abs(e - x);
    return s;
  }, 0ll, (B + SUM(a)) / N + 1).fi);
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"