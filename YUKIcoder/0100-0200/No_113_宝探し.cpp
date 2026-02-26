#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  ll x = 0, y = 0;
  STR(s);
  for (char c : s) {
    if (c == 'N') ++x;
    if (c == 'S') --x;
    if (c == 'E') ++y;
    if (c == 'W') --y;
  }
  setp(10);
  print(sqrtl(x * x + y * y));
}
#include "YRS/aa/main.hpp"