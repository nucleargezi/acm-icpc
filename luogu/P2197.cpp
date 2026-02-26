#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  int s = 0;
  FOR(N) {
    INT(x);
    s ^= x;
  }
  No(s == 0);
}
#include "YRS/aa/main.hpp"