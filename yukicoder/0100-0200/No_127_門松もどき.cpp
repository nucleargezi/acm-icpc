#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
// #include "YRS/mod/mint.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N);
  VEC(int, a, N);
  retsu<int> x(N, N), y(N, N); // lmin, rmin
  FOR(i, N) x[i][i] = 1;
  FOR(i, N) y[i][i] = 1;
  FOR_R(l, N) FOR(r, l + 1, N) {
    x[l][r] = x[l][r - 1];
    if (a[l] < a[r]) chmax(x[l][r], y[l + 1][r] + 1);
    y[l][r] = y[l + 1][r];
    if (a[r] < a[l]) chmax(y[l][r], x[l][r - 1] + 1);
  }
  print(max(x.max(), y.max()));
}
#include "YRS/aa/main.hpp"