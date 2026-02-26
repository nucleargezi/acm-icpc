#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, M, s);
  if (N > M) swap(N, M);
  if (N == 1 and M > 2) return NO();
  if ((N * M) & 1) return NO();
  YES();
}
#include "YRS/aa/main.hpp"