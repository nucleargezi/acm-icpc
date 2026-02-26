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
  int n = 0;
  while (1 << n < N) ++n;
  print(n);
}
#include "YRS/aa/main.hpp"