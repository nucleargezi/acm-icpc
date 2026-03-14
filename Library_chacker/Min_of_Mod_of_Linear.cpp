#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/min_line.hpp"

#define tests 1
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, a, b);
  print(min_line(0, N, a, b, M).se);
}
#include "YRS/aa/main.hpp"