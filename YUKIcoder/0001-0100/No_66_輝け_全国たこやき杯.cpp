#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
using re = ld;
void Yorisou() {
  INT(N);
  VEC(ll, a, 1 << N);
  retsu<re> f(N + 1, 1 << N);
  FOR(i, 1 << N) f[0][i] = 1;
  FOR(i, 1, N + 1) {
    FOR(s, 1 << N) {
      int bs = ((s >> (i - 1)) << (i - 1)) ^ (1 << (i - 1));
      FOR(k, 1 << (i - 1)) {
        int t = bs | k;
        f[i][s] += f[i - 1][t] * (a[s] * a[s] / re(a[s] * a[s] + a[t] * a[t]));
      }
      f[i][s] *= f[i - 1][s];
    }
  }
  setp(7);
  print(f[N][0]);
}
#include "YRS/aa/main.hpp"