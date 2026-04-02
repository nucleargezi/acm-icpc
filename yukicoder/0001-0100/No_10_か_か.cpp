#define YRSD
#include "YRS/all.hpp"
#include "YRS/debug.hpp"
// #include "YRS/IO/fast_io.hpp"
// #include "YRS/random/rng.hpp"
#include "YRS/ds/basic/retsu.hpp"

#define tests 0
#define fl 0
#define DB 10
void Yorisou() {
  INT(N, S);
  VEC(int, a, N);
  retsu<string> f(N, S + 1, "-");
  f[0][a[0]] = "";
  FOR(i, 1, N) {
    int x = a[i];
    FOR(k, S + 1) if (f[i - 1][k] != "-" and k + x <= S) {
      f[i][k + x] = f[i - 1][k] + '+';
    }
    FOR(k, S + 1) if (f[i - 1][k] != "-" and 1ll * k * x <= S) {
      if (f[i][k * x] == "-") f[i][k * x] = f[i - 1][k] + '*';
      chmax(f[i][k * x], f[i - 1][k] + '*');
    }
  }
  print(f[N - 1][S]);
}
#include "YRS/aa/main.hpp"