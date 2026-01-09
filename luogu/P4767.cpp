#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/dp/monoton.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, K);
  VEC(int, a, N);
  sort(a);
  a.insert(a.begin(), 0);
  retsu<int> c(N + 1, N + 1);
  FOR_R(i, 1, N + 1) FOR(k, i, N + 1) c[i][k] = c[i + 1][k - 1] + a[k] - a[i];
  Z w = [&](int i, int k) {
    return c[i + 1][k];
  };
  print(monoton_dp<int>(N + 1, K, w)[N]);
}
#include "YRS/aa/main.hpp"