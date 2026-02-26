#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"
#include "YRS/mod/modint.hpp"

#define tests 0
#define fl 0
#define DB 10
using mint = M99;
void Yorisou() {
  INT(N, M);
  retsu<mint> a(N + 1, M + 1), b(a);
  FOR(i, N) FOR(k, M) IN(a[i][k]);
  FOR(i, N) FOR(k, M) IN(b[i][k]);
  FOR(i, N) FOR_R(k, M) a[i][k] += a[i][k + 1];
  FOR(k, M) FOR_R(i, N) b[i][k] += b[i + 1][k];
  mint s = 2;
  FOR(i, N) FOR(k, M) {
    s += a[i + 1][k] * b[i][k + 1] * (mint(1) - a[i][k]) * (mint(1) - b[i][k]);
  }
  print(s);
}
#include "YRS/aa/main.hpp"