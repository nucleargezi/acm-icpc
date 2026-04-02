#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  int s = 0, f = 0;
  FOR(N) {
    INT(N);
    STR(str);
    int sz = len(str), d = min(12 * N / 1000, sz);
    s += d;
    f += sz - d;
  }
  print(s, f);
}
#include "YRS/aa/main.hpp"