#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  VEC(int, a, 3);
  int s = 29;
  while (QMAX(a) > 0) FOR(i, 3) {
    a[i] -= 2, ++s;
    if (QMAX(a) < 1) break;
  }
  print(s);
}
#include "YRS/Z_H/main.hpp"