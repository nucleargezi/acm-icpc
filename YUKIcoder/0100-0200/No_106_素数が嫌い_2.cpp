#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/pr/lpf_table.hpp"
#include "YRS/pr/factors.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  vc<int> lpf = lpf_table(N);
  int s = 0;
  FOR(i, 2, N + 1) s += len(factor_by_lpf(i, lpf)) >= K;
  print(s);
}
#include "YRS/aa/main.hpp"