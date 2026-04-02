#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  STR(s);
  ll x = 1;
  for (char c : s) x = x << 1 | (c == 'R');
  print(x);
}
#include "YRS/aa/main.hpp"