#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
// #include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  unique(a);
  N = len(a);
  int s = inf<int>;
  FOR(i, N - 1) chmin(s, a[i + 1] - a[i]);
  print(s == inf<int> ? 0 : s);
}
#include "YRS/aa/main.hpp"