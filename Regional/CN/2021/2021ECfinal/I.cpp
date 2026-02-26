#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(ll, a, N);
  ll x = 0, y = 0, on = 0;
  for (ll e : a) {
    if (e < 1) ++x;
    if (e > 1) ++y; 
    if (e == 1) ++on;
  }
  print(x * y + on * (N - on) + on * (on - 1) / 2);
}
#include "YRS/aa/main.hpp"