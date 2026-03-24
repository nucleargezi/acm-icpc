#include "YRS/all.hpp"

void Yorisou() {
  INT(N);
  VEC(int, a, N + 1);
  int f[11][11]{};
  FOR(i, 11) FOR(k, 11) f[i][k] = inf<int> / 2;
  f[0][0] = 1;
  FOR(i, N + 1) FOR(k, a[i] + 1) {
    if (i > 0) chmin(f[i][k], f[i - 1][k] + 1);
    FOR(j, k) chmin(f[i][k], f[i][j] + f[i][k - j - 1]);
  }
  print(vc<int>{f[N], f[N] + a[N] + 1});
}
constexpr int tests = 0, fl = 0, DB = 10;
#include "YRS/aa/main.hpp"