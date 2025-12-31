#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  LL(l, r);
  if (l == r) return print(0);
  int top = topbit(l ^ r);
  ll msk = ~((1ll << (top + 1)) - 1), s = (l & msk) | (1ll << top);
  ll a = s - l, b = r - s + 1;
  print(min(a & -a, b & -b) - 1 + (a == b ? (a & -a) : 0));
}
#include "YRS/aa/main.hpp"