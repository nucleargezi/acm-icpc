#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/factors.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  int s = 0;
  FOR(N) {
    INT(x);
    for (Z [e, p] : factor(x)) s ^= p % 3;
  }
  Bob(s == 0);
}
#include "YRS/aa/main.hpp"