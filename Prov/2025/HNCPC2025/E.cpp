// #define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
#include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/math/PR/prims_test.hpp"

#define tests 0
#define fl 0
#define DB 10
using T = retsu<int>;
int N, M;
void Yorisou() {
  if (fl) N = rng(2, 10) ,M = rng(2, 10);
  else IN(N, M);
  T a(N, M);
  FOR(i, N) FOR(k, M) a[i][k] = i * M + k + 1;
  YES();
  FOR(i, N) FOR(k, M) cout << a[i][k] << " \n"[k + 1 == M];
}
#include "YRS/Z_H/main.hpp"