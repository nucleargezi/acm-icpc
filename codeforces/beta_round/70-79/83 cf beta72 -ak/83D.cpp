#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
bool test(int x) {
  for (int i = 2; i * i < x + 1; ++i) 
    if (x % i == 0) return false;
  return true;
}
ll f(ll x, ll k) {
  if (x < k or not test(k)) return 0;
  ll s = x / k;
  FOR(i, 2, min(k - 1, x / k) + 1) 
    s -= f(x / k, i);
  return s;
}
void Yorisou() {
  INT(a, b, k);
  if (not test(k)) return print(0);
  print(f(b, k) - f(a - 1, k));
}
#include "YRS/Z_H/main.hpp"