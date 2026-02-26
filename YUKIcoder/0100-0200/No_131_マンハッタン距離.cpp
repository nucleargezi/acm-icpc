#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  LL(a, b, c);
  ll l = bina([&](ll x) { return c - x <= b; }, inf<int>, -1);
  ll r = bina([&](ll x) { return c - x >= 0; }, 0, inf<int>);
  chmin(r, a);
  print(l <= a ? r - l + 1 : 0);
}
#include "YRS/aa/main.hpp"